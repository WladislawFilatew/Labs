#pragma once
#include <iostream>
#include "..\lib\calculator_lib.h"
#include <SFML\Graphics.hpp>
#include "button.h"
#include "PanelFormul.h"
using namespace sf;
using namespace std;

class MainForm
{
	RenderWindow* window;

	void Update();
	void Draw();
	void Init();
public:
	MainForm(int Windht = 1000, int Height = 1300);
	~MainForm();
	void Start();

private:
//Объекты
	button* exit;
	Text name;
	Font font;
	PanelFormul* panel;

	button*** knopki;
	void zap_knopki();
	void MousKlic(wstring s);
};
