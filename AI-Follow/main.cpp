#include<raylib.h>
#include<iostream>
#include "button.h"
#include "game.h"

int main()
{
	InitWindow(800, 600, "Raylib Buttons Tutorial");

	SetTargetFPS(60);

	Texture2D background = LoadTexture("Graphics/background.png");
	Button startButton{ "Graphics/start_button.png",{300,150},0.25 };
	Button exitButton{ "Graphics/exit_button.png",{300,300},0.25 };
	bool exit = false;

	while (WindowShouldClose() == false && exit == false)
	{
		Vector2 mousePosition = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		if (startButton.isPressed(mousePosition, mousePressed))
		{
			std::cout << "Start Button Pressed" << std::endl;

			CloseWindow();   // close menu window
			RunGame();    // 🔥 launch tetris
			return 0;
		}

		if (exitButton.isPressed(mousePosition, mousePressed))
		{
			exit = true;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		startButton.Draw();
		exitButton.Draw();
		EndDrawing();
	}
	CloseWindow();
}