#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;


class PanelFormul {
	Font font;
	Text text;
	RectangleShape rectagle;
public:
	PanelFormul(int Windht, int Height);
	void draw(RenderWindow* window);
	void SetText(wstring s);
	Text& Text() { return text; }
};
