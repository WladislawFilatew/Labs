#include "button.h"

button::button(int Windht, int Height)
{
	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht, Height));
	Fill = Hover = Color::Green;
	rectagle.setFillColor(Fill);

	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");
	text.setFont(font);
	text.setCharacterSize(Height - 12);
	text.setFillColor(Color::White);

}






void button::SetColor(Color color)
{
	rectagle.setFillColor(color);
	Fill = color;
	if (Hover != Color::Green)
		Hover = color;

}

void button::SetPosition(Vector2f vec)
{
	rectagle.setPosition(vec);
	text.setPosition(Vector2f(vec.x + rectagle.getSize().x / 2 - 15, vec.y + rectagle.getSize().y / 2 - 30));
}

void button::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(text);
}

bool button::MousHover(RenderWindow* window)
{
	int x = Mouse::getPosition(*window).x;
	int y = Mouse::getPosition(*window).y;
	bool flag = true;
	if (x < rectagle.getPosition().x || x > rectagle.getPosition().x + rectagle.getSize().x)
		flag = false;
	if (y < rectagle.getPosition().y || y > rectagle.getPosition().y + rectagle.getSize().y)
		flag = false;
	flag ? rectagle.setFillColor(Hover) : rectagle.setFillColor(Fill);
	return flag;
}
