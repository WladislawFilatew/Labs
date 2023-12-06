#pragma once
#include <SFML\Graphics.hpp>
#include "..\Elements\button.h"
#include "..\Elements\CP.h"
using namespace sf;
using namespace std;

class ProcV {
	RectangleShape rectagle;
	Font font;
	Text idProc;
	Text info;
public:
	ProcV(int Windht = 100, int Height = 100, int nomer = 0);
	void draw(RenderWindow* window);
	void SetIdProc(wstring s);
	void SetInfo(wstring s);
	Text& IdProc() { return idProc; }
	Text& Info() { return info; }
	void SetPosition(Vector2f vector);
	Vector2f getPosition() { return rectagle.getPosition(); }
	void setColor(Color color) { 
		rectagle.setFillColor(color);
		info.setFillColor(Color(255 - color.r, 255 - color.g, 255 - color.b));
		idProc.setFillColor(Color(255 - color.r, 255 - color.g, 255 - color.b));
	}
};


class PanelProc {
	Font font;
	Text text;
	RectangleShape rectagle;
public:
	PanelProc(int Windht, int Height, Controller* controller);
	void draw(RenderWindow* window);
	void SetText(wstring s);
	Text& Text() { return text; }
	void SetPosition(Vector2f vector);
	Vector2f getSize() { return rectagle.getSize(); }
	Vector2f getPosition() { return rectagle.getPosition(); }
	

	vector<ProcV*> proc;
	void SetProc(Controller* controller);
};