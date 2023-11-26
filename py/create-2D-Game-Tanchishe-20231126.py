#coding=gbk
# 以Pygame为例
import pygame
import sys
import random

# 初始化 Pygame
pygame.init()

# 定义常量
WIDTH, HEIGHT = 600, 400
GRID_SIZE = 20
FPS = 10

# 定义颜色
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# 定义方向
UP = (0, -1)
DOWN = (0, 1)
LEFT = (-1, 0)
RIGHT = (1, 0)

# 游戏初始化
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

snake = [(100, 100), (90, 100), (80, 100)]
snake_direction = RIGHT

food = (random.randint(1, (WIDTH//GRID_SIZE)-1) * GRID_SIZE,
        random.randint(1, (HEIGHT//GRID_SIZE)-1) * GRID_SIZE)

# 游戏主循环
clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP and snake_direction != DOWN:
                snake_direction = UP
            elif event.key == pygame.K_DOWN and snake_direction != UP:
                snake_direction = DOWN
            elif event.key == pygame.K_LEFT and snake_direction != RIGHT:
                snake_direction = LEFT
            elif event.key == pygame.K_RIGHT and snake_direction != LEFT:
                snake_direction = RIGHT

    # 移动蛇
    new_head = (snake[0][0] + snake_direction[0] * GRID_SIZE,
                snake[0][1] + snake_direction[1] * GRID_SIZE)

    # 判断是否吃到食物
    if new_head == food:
        food = (random.randint(1, (WIDTH//GRID_SIZE)-1) * GRID_SIZE,
                random.randint(1, (HEIGHT//GRID_SIZE)-1) * GRID_SIZE)
    else:
        snake.pop()

    # 判断是否游戏结束
    if (new_head in snake or
            new_head[0] < 0 or new_head[0] >= WIDTH or
            new_head[1] < 0 or new_head[1] >= HEIGHT):
        pygame.quit()
        sys.exit()

    snake.insert(0, new_head)

    # 绘制背景
    screen.fill(WHITE)

    # 绘制蛇
    for segment in snake:
        pygame.draw.rect(screen, GREEN, (segment[0], segment[1], GRID_SIZE, GRID_SIZE))

    # 绘制食物
    pygame.draw.rect(screen, RED, (food[0], food[1], GRID_SIZE, GRID_SIZE))

    # 刷新屏幕
    pygame.display.flip()

    # 控制游戏帧率
    clock.tick(FPS)
