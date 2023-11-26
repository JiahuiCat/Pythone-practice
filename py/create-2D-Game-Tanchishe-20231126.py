#coding=gbk
# ��PygameΪ��
import pygame
import sys
import random

# ��ʼ�� Pygame
pygame.init()

# ���峣��
WIDTH, HEIGHT = 600, 400
GRID_SIZE = 20
FPS = 10

# ������ɫ
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# ���巽��
UP = (0, -1)
DOWN = (0, 1)
LEFT = (-1, 0)
RIGHT = (1, 0)

# ��Ϸ��ʼ��
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

snake = [(100, 100), (90, 100), (80, 100)]
snake_direction = RIGHT

food = (random.randint(1, (WIDTH//GRID_SIZE)-1) * GRID_SIZE,
        random.randint(1, (HEIGHT//GRID_SIZE)-1) * GRID_SIZE)

# ��Ϸ��ѭ��
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

    # �ƶ���
    new_head = (snake[0][0] + snake_direction[0] * GRID_SIZE,
                snake[0][1] + snake_direction[1] * GRID_SIZE)

    # �ж��Ƿ�Ե�ʳ��
    if new_head == food:
        food = (random.randint(1, (WIDTH//GRID_SIZE)-1) * GRID_SIZE,
                random.randint(1, (HEIGHT//GRID_SIZE)-1) * GRID_SIZE)
    else:
        snake.pop()

    # �ж��Ƿ���Ϸ����
    if (new_head in snake or
            new_head[0] < 0 or new_head[0] >= WIDTH or
            new_head[1] < 0 or new_head[1] >= HEIGHT):
        pygame.quit()
        sys.exit()

    snake.insert(0, new_head)

    # ���Ʊ���
    screen.fill(WHITE)

    # ������
    for segment in snake:
        pygame.draw.rect(screen, GREEN, (segment[0], segment[1], GRID_SIZE, GRID_SIZE))

    # ����ʳ��
    pygame.draw.rect(screen, RED, (food[0], food[1], GRID_SIZE, GRID_SIZE))

    # ˢ����Ļ
    pygame.display.flip()

    # ������Ϸ֡��
    clock.tick(FPS)
