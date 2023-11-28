#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class button {
	RectangleShape rectagle;
	Font font;
	Text text;

	Color Hover;
	Color Fill;


public:
	button(int Windht = 100, int Height = 100);
	Color GetColor() { return rectagle.getFillColor(); }
	Vector2f GetSize() { return rectagle.getSize(); }
	Vector2f GetPosition() { return rectagle.getPosition(); }
	void SetColor(Color color);
	void SetHoverColor(Color color) { Hover = color; }
	Text& Text() { return text; }
	void SetPosition(Vector2f vec);
	void draw(RenderWindow* window);
	bool MousHover(RenderWindow* window);

};
