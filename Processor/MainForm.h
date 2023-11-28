#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Elements\button.h"
#include "Blocks\PanelProc.h"
#include "Blocks\PanelQueue.h"
using namespace sf;
using namespace std;

class MainForm
{
	RenderWindow* window;

	void Update();
	void Draw();
	void Init();
public:
	MainForm(int Windht = 2000, int Height = 1300);
	~MainForm();
	void Start();

private:
//Объекты
	button* exit;
	RectangleShape PanelMenu;
	Text name;
	Font font;
	
	
	PanelProc* panelProc;
	PanelQueue* panelQueue;
	PanelQueue* panelTask;

	Controller* controller;

};
