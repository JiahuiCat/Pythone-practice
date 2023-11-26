# -*- coding: utf-8 -*-
import pygame
import sys
import random
import time

# 初始化 Pygame
pygame.init()

# 定义常量
WIDTH, HEIGHT = 800, 600
FPS = 60

# 定义颜色
WHITE = (255, 255, 255)
RED = (255, 0, 0)
YELLOW = (255, 255, 0)

# 定义飞机属性
airplane_width = 50
airplane_height = 50

# 定义敌机属性
enemy_width = 50
enemy_height = 50

# 定义 Boss 属性
boss_width = 100
boss_height = 100

# 定义小 Boss 属性
mini_boss_width = 80
mini_boss_height = 80

# 定义子弹属性
bullet_width = 5
bullet_height = 10

# 定义生命图标属性
life_width = 30
life_height = 30

# 定义无敌时间
invincible_time = 10

# 定义子弹发射间隔
bullet_interval = 0.5  # 每0.5秒发射一颗子弹

# 定义小 Boss 的特殊奖励持续时间
special_reward_duration = 3  # 持续3秒

# 定义小 Boss 的特殊奖励状态
special_reward_active = False
special_reward_start_time = 0

# 定义子弹速度
bullet_speed = 10

# 游戏初始化
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Aircraft Battle")

airplane_image = pygame.Surface((airplane_width, airplane_height), pygame.SRCALPHA)
pygame.draw.polygon(airplane_image, RED, [(0, 0), (airplane_width / 2, airplane_height), (airplane_width, 0)])

enemy_image = pygame.Surface((enemy_width, enemy_height), pygame.SRCALPHA)
pygame.draw.rect(enemy_image, RED, (0, 0, enemy_width, enemy_height))

boss_image = pygame.Surface((boss_width, boss_height), pygame.SRCALPHA)
pygame.draw.rect(boss_image, RED, (0, 0, boss_width, boss_height))

mini_boss_image = pygame.Surface((mini_boss_width, mini_boss_height), pygame.SRCALPHA)
pygame.draw.rect(mini_boss_image, YELLOW, (0, 0, mini_boss_width, mini_boss_height))

bullet_image = pygame.Surface((bullet_width, bullet_height), pygame.SRCALPHA)
pygame.draw.rect(bullet_image, RED, (0, 0, bullet_width, bullet_height))

life_image = pygame.Surface((life_width, life_height), pygame.SRCALPHA)
pygame.draw.polygon(life_image, RED, [(0, life_height), (life_width / 2, 0), (life_width, life_height)])

airplane_rect = airplane_image.get_rect(center=(WIDTH / 2, HEIGHT - airplane_height / 2))
airplane_speed = 8

enemies = []
enemy_speed = 5
enemy_spawn_rate = 30

boss = None
boss_speed = 3
boss_health = 3

mini_boss = None
mini_boss_speed = 4
mini_boss_health = 5

bullets = []

lives = 3
life_rects = [life_image.get_rect(topleft=(10 + i * (life_width + 5), 10)) for i in range(lives)]

score = 0
font = pygame.font.SysFont(None, 30)

paused = False
invincible_timer = None
last_bullet_time = time.time()

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                paused = not paused

    if not paused:
        mouse_x, mouse_y = pygame.mouse.get_pos()
        airplane_rect.centerx += (mouse_x - airplane_rect.centerx) / 10

        if random.randint(1, enemy_spawn_rate) == 1:
            enemy_rect = enemy_image.get_rect(center=(random.randint(0, WIDTH-enemy_width), 0))
            enemies.append(enemy_rect)

        if boss is None and score >= 10:
            boss = boss_image.get_rect(center=(WIDTH / 2, 50))
            boss_health = 3
            invincible_timer = time.time()

        if mini_boss is None and score >= 20:
            mini_boss = mini_boss_image.get_rect(center=(WIDTH / 2, 50))
            mini_boss_health = 5
            invincible_timer = time.time()

        for enemy_rect in enemies:
            enemy_rect.y += enemy_speed

        if boss is not None:
            if boss.x < airplane_rect.centerx:
                boss.x += boss_speed
            elif boss.x > airplane_rect.centerx:
                boss.x -= boss_speed

            boss.y += boss_speed

        if mini_boss is not None:
            if mini_boss.x < airplane_rect.centerx:
                mini_boss.x += mini_boss_speed
            elif mini_boss.x > airplane_rect.centerx:
                mini_boss.x -= mini_boss_speed

            mini_boss.y += mini_boss_speed

        for bullet_rect, speed_x, speed_y in bullets:
            bullet_rect.x += speed_x
            bullet_rect.y += speed_y
            screen.blit(bullet_image, bullet_rect)

        for life_rect in life_rects[:lives]:
            screen.blit(life_image, life_rect)

        score_text = font.render(f"Score: {score}", True, RED)
        screen.blit(score_text, (10, 10))

        # 处理子弹和敌机碰撞
        for bullet_rect, speed_x, speed_y in bullets:
            for enemy_rect in enemies:
                if bullet_rect.colliderect(enemy_rect):
                    bullets.remove((bullet_rect, speed_x, speed_y))
                    enemies.remove(enemy_rect)
                    score += 1

        # 处理飞机和敌机碰撞
        for enemy_rect in enemies:
            if invincible_timer is None and airplane_rect.colliderect(enemy_rect):
                enemies.remove(enemy_rect)
                lives -= 1
                if lives == 0:
                    pygame.quit()
                    sys.exit()

        # 处理 Boss 和子弹碰撞
        if boss is not None:
            for bullet_rect, speed_x, speed_y in bullets:
                if invincible_timer is None and bullet_rect.colliderect(boss):
                    bullets.remove((bullet_rect, speed_x, speed_y))
                    boss_health -= 1
                    if boss_health == 0:
                        boss = None
                        score += 5
                        boss_health = 3
                        invincible_timer = time.time()

        # 处理 Mini Boss 和子弹碰撞
        if mini_boss is not None:
            for bullet_rect, speed_x, speed_y in bullets:
                if invincible_timer is None and bullet_rect.colliderect(mini_boss):
                    bullets.remove((bullet_rect, speed_x, speed_y))
                    mini_boss_health -= 1
                    if mini_boss_health == 0:
                        mini_boss = None
                        score += 10
                        mini_boss_health = 5
                        special_reward_active = True
                        special_reward_start_time = time.time()

        # ... （其余游戏逻辑代码）

        if time.time() - last_bullet_time > bullet_interval:
            bullet_rect = bullet_image.get_rect(center=(airplane_rect.centerx, airplane_rect.centery - airplane_height / 2))
            bullets.append((bullet_rect, 0, -bullet_speed))
            last_bullet_time = time.time()

        if score >= 200:
            pygame.quit()
            sys.exit()

        # ... （其余游戏逻辑代码）

    # 在非暂停时清除暂停文本
    screen.fill(WHITE)

    screen.blit(airplane_image, airplane_rect)

    for enemy_rect in enemies:
        screen.blit(enemy_image, enemy_rect)

    if boss is not None and (invincible_timer is None or time.time() - invincible_timer % 0.5 < 0.25):
        screen.blit(boss_image, boss)

    if mini_boss is not None and (invincible_timer is None or time.time() - invincible_timer % 0.5 < 0.25):
        screen.blit(mini_boss_image, mini_boss)

    for bullet_rect, speed_x, speed_y in bullets:
        bullet_rect.x += speed_x
        bullet_rect.y += speed_y
        screen.blit(bullet_image, bullet_rect)

    for life_rect in life_rects[:lives]:
        screen.blit(life_image, life_rect)

    score_text = font.render(f"Score: {score}", True, RED)
    screen.blit(score_text, (10, 10))

    pygame.display.flip()

    clock.tick(FPS)
