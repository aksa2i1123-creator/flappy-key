#include "system.h"

void loseF() {
    DrawText("GAME OVER", 250, 200, 40, RED);
}
void pauseF() {
    DrawText("PAUSED", 300, 200, 40, RED);
}

int main() {
    InitWindow(width, height, "flappy key");

    bird_up = LoadTexture("up_bird.png");
    bird_down = LoadTexture("down_bird.png");
    bird_right = LoadTexture("right_bird.png");
    bird_left = LoadTexture("left_bird.png");
    cable = LoadTexture("cable.png");

    Vector2 playerPos = {400.0f, 200.0f};
    float obstacleX = 650.0f;
    float obstacleGapY = 200.0f;
    const float obstacleWidth = 52.0f;
    const float obstacleGapHeight = 150.0f;
    const float obstacleSpeed = 200.0f;

    if (number == 0) {
        bird = bird_up;
    } else if (number == 1) {
        bird = bird_down;
    } else if (number == 2) {
        bird = bird_right;
    } else {
        bird = bird_left;
    }

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_P) && !lose) {
            paused = !paused;
        }

        if (!lose && !paused) {
            if (IsKeyPressed(KEY_UP) && number == 0) {
                jump();
            }
            if (IsKeyPressed(KEY_DOWN) && number == 1) {
                jump();
            }
            if (IsKeyPressed(KEY_LEFT) && number == 3) {
                jump();
            }
            if (IsKeyPressed(KEY_RIGHT) && number == 2) {
                jump();
            }


            velocityY += gravity * GetFrameTime();
            playerPos.y += velocityY * GetFrameTime();
            obstacleX -= obstacleSpeed * GetFrameTime();

            if (obstacleX + obstacleWidth < 0.0f) {
                obstacleX = (float)width + 40.0f;
                obstacleGapY = GetRandomValue(120, 320);
            }
        }

        if (lose) {
            if (IsKeyPressed(KEY_R))
            {
                lose = false;
                playerPos = {400.0f, 200.0f};
                obstacleX = 650.0f;
                obstacleGapY = 200.0f;
                velocityY = 0.0f;
            }
        }

        if (playerPos.y >= groundY || playerPos.y <= ceilingY) {
            lose = true;
        }

        const float playerHitboxWidth = 10.0f;
        const float playerHitboxHeight = 10.0f;
        Rectangle playerRect = {
            playerPos.x + 14.0f,
            playerPos.y + 14.0f,
            playerHitboxWidth,
            playerHitboxHeight
        };

        const float topHeight = obstacleGapY - obstacleGapHeight * 0.5f;
        const float bottomY = obstacleGapY + obstacleGapHeight * 0.5f;
        const float bottomHeight = (float)height - bottomY;

        Rectangle topRect = {
            obstacleX,
            0.0f,
            obstacleWidth,
            topHeight
        };

        Rectangle bottomRect = {
            obstacleX,
            bottomY,
            obstacleWidth,
            bottomHeight
        };

        if (CheckCollisionRecs(playerRect, topRect) || CheckCollisionRecs(playerRect, bottomRect)) {
            lose = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureEx(bird, playerPos, 0.0f, 4.0f, WHITE);

        DrawTexturePro(
            cable,
            {0.0f, 0.0f, (float)cable.width, (float)cable.height},
            {obstacleX, 0.0f, obstacleWidth, topHeight},
            {0.0f, 0.0f},
            0.0f,
            WHITE
        );

        DrawTexturePro(
            cable,
            {0.0f, 0.0f, (float)cable.width, (float)cable.height},
            {obstacleX, bottomY, obstacleWidth, bottomHeight},
            {0.0f, 0.0f},
            0.0f,
            WHITE
        );

        if (lose) {
            loseF();
        }
        if (paused) {
            pauseF();
        }

        EndDrawing();
    }

    UnloadTexture(bird_up);
    UnloadTexture(bird_down);
    UnloadTexture(bird_right);
    UnloadTexture(bird_left);
    UnloadTexture(cable);
    CloseWindow();

    return 0;
}