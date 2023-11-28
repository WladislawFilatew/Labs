#pragma once
#include "..\Elements\button.h"
#include "..\Elements\CP.h"
using namespace sf;
using namespace std;


class TaskV {
	RectangleShape rectagle;
	Font font;
	Text info;
public:
	TaskV(int Windht = 100, int Height = 100);
	void draw(RenderWindow* window);
	void SetInfo(wstring s);
	Text& Info() { return info; }
	void SetPosition(Vector2f vector);
	Vector2f getPosition() { return rectagle.getPosition(); }
	void setColor(Color color) {
		rectagle.setFillColor(color);
		info.setFillColor(Color(255 - color.r, 255 - color.g, 255 - color.b));
	}
};


class PanelQueue {
	Font font;
	Text text;
	RectangleShape rectagle;
public:
	PanelQueue(int Windht, int Height, wstring s);
	void draw(RenderWindow* window);
	void SetText(wstring s);
	Text& Text() { return text; }
	void SetPosition(Vector2f vector);
	Vector2f getSize() { return rectagle.getSize(); }
	Vector2f getPosition() { return rectagle.getPosition(); }
	void getTasks(MyQueue<Task> tasks);
	

	vector<TaskV*> task;
};