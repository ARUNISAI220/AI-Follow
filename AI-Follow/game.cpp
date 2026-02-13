#include "raylib.h"
#include <math.h>
#include "game.h"

void RunGame(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Raylib AI Follow EXample");
	SetTargetFPS(60);

	Vector2 playerPos = { 400,255 };
	Vector2 enemyPos = { 100,100 };

	float playerSpeed = 200.0f;
	float enemySpeed = 120.0f;

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		if (IsKeyDown(KEY_W)) playerPos.y -= playerSpeed * dt;
		if (IsKeyDown(KEY_S)) playerPos.y += playerSpeed * dt;
		if (IsKeyDown(KEY_A)) playerPos.x -= playerSpeed * dt;
		if (IsKeyDown(KEY_D)) playerPos.x += playerSpeed * dt;

		Vector2 direction = {
			playerPos.x - enemyPos.x,
			playerPos.y - enemyPos.y
		};

		float length = sqrtf(direction.x * direction.x + direction.y * direction.y);

		if (length > 1.0f)
		{
			direction.x /= length;
			direction.y /= length;

			enemyPos.x += direction.x * enemySpeed * dt;
			enemyPos.y += direction.y * enemySpeed * dt;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircleV(playerPos, 15, BLUE);
		DrawCircleV(enemyPos, 15, RED);

		DrawText("WASD to move player", 10,10,20,DARKGRAY);
		DrawText("Red circle follows Blue Circle", 10,40,20,DARKGRAY);
		EndDrawing();
	}
	CloseWindow();
	//return 0;
}
