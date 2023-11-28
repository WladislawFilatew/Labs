#include "PanelProc.h"

PanelProc::PanelProc(int Windht, int Height,Controller* controller)
{

	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht - 8, Height));
	rectagle.setPosition(Vector2f(4, 80));
	rectagle.setFillColor(Color(17, 24, 38));
	rectagle.setOutlineThickness(3);
	rectagle.setOutlineColor(Color(77,77,77));


	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");

	text.setFont(font);
	text.setCharacterSize(25);
	text.setString(L"ѕроцессор:");
	text.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - text.getLocalBounds().width) / 2,-10));
	text.setFillColor(Color(117,117,120));


	float x = (Windht - 2) / controller->width();
	float y = (Height - 20) / controller->height();
	int h = controller->width();
	proc.resize(controller->GetKolProc());
	for (int i = 0; i < controller->GetKolProc();i++) {
		proc[i] = new ProcV(x * 0.9, y * 0.9, i + 1);
		Vector2f temp = Vector2f((i % h) * x + x * 0.05 + 0.5, (i / h) * y + y * 0.05 + 20);
		proc[i]->SetPosition(rectagle.getPosition() + temp);
	}
}

void PanelProc::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(text);

	for (auto& a : proc) {
		a->draw(window);
	}
}


void PanelProc::SetText(wstring s)
{
	text.setString(s);
	text.setPosition(rectagle.getSize().x - text.getLocalBounds().width - 10, rectagle.getPosition().y + rectagle.getSize().y / 2 - 50);
}

void PanelProc::SetPosition(Vector2f vector)
{
	rectagle.setPosition(rectagle.getPosition() + vector);
	text.setPosition(text.getPosition() + vector);

	for (auto& a : proc) {
		a->SetPosition(vector);
	}
}

void PanelProc::SetProc(Controller* controller)
{
	vector<vector<Controller::CoreInfo>> temp = controller->GetTablCores();
	int h = controller->height();
	for (int i = 0; i < controller->GetKolProc(); i++) {
		string s = to_string(temp[i % h][i / h].Id) + ":" + to_string(temp[i % h][i / h].KolTact);
		wstring ws;
		for (auto a : s) {
			ws += a;
		}
		proc[i]->SetInfo(ws);
		proc[i]->setColor(Color(temp[i % h][i / h].color[0], temp[i % h][i / h].color[1], temp[i % h][i / h].color[2]));
		
	}
}

ProcV::ProcV(int Windht, int Height, int Nomer)
{
	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht, Height));
	rectagle.setFillColor(Color(180,180,180));
	rectagle.setOutlineThickness(3);
	rectagle.setOutlineColor(Color(77, 77, 77));


	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");

	int mini = min(Height, Windht);

	idProc.setFont(font);
	idProc.setCharacterSize(mini* 0.2);
	idProc.setString(L"ядро: " + to_string(Nomer));
	idProc.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - idProc.getLocalBounds().width) / 2,10));
	idProc.setFillColor(Color(117, 117, 120));


	info.setFont(font);
	info.setCharacterSize(mini * 0.2);
	info.setString(L"0:0");
	info.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - info.getLocalBounds().width) / 2, (rectagle.getSize().y - info.getLocalBounds().height) / 2));
	info.setFillColor(Color(117, 117, 120));
}

void ProcV::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(idProc);
	window->draw(info);
}

void ProcV::SetIdProc(wstring s)
{
	idProc.setString(s);
	idProc.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - idProc.getLocalBounds().width) / 2, 10));
}

void ProcV::SetInfo(wstring s)
{
	info.setString(s);
	info.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - info.getLocalBounds().width) / 2, (rectagle.getSize().y - info.getLocalBounds().height) / 2));
}

void ProcV::SetPosition(Vector2f vector)
{
	rectagle.setPosition(rectagle.getPosition() + vector);
	idProc.setPosition(idProc.getPosition() + vector);
	info.setPosition(info.getPosition() + vector);
}
