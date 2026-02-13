#include "button.h"

Button::Button(const char* imagePath, Vector2 imagePosition, float scale)
{
	Image image = LoadImage(imagePath);

	int newWidth = static_cast<int>(image.width * scale);
	int newHeight = static_cast<int>(image.height * scale);

	ImageResize(&image, newWidth, newHeight);
	texture = LoadTextureFromImage(image);

	UnloadImage(image);
	position = imagePosition;

}

Button::~Button()
{
	UnloadTexture(texture);
}

void Button::Draw()
{
	DrawTextureV(texture, position, WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed)
{
	Rectangle rect{
		position.x,
		position.y,
		(float)texture.width,
		(float)texture.height
	};
	return CheckCollisionPointRec(mousePos, rect) && mousePressed;
}

