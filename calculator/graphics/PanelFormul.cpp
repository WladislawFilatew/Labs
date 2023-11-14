#include "PanelFormul.h"

PanelFormul::PanelFormul(int Windht, int Height)
{

	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht - 8, Height));
	rectagle.setPosition(Vector2f(4, 80));
	rectagle.setFillColor(Color(17, 24, 38));
	/*rectagle.setOutlineThickness(1);
	rectagle.setOutlineColor(Color::White);*/


	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");

	text.setFont(font);
	text.setCharacterSize(70);
	text.setOrigin(text.getLocalBounds().width, 0);
	text.setString("0");
	text.setPosition(rectagle.getSize().x - text.getLocalBounds().width - 10,rectagle.getPosition().y + rectagle.getSize().y / 2 - 50);
	text.setFillColor(Color::White);
}

void PanelFormul::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(text);
}

void PanelFormul::SetText(wstring s)
{
	text.setString(s);
	text.setPosition(rectagle.getSize().x - text.getLocalBounds().width - 10, rectagle.getPosition().y + rectagle.getSize().y / 2 - 50);
}
