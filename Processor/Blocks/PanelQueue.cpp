#include "PanelQueue.h"




PanelQueue::PanelQueue(int Windht, int Height, wstring s)
{

	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht - 8, Height));
	rectagle.setPosition(Vector2f(4, 80));
	rectagle.setFillColor(Color(17, 24, 38));
	rectagle.setOutlineThickness(3);
	rectagle.setOutlineColor(Color(77, 77, 77));


	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");

	text.setFont(font);
	text.setCharacterSize(25);
	text.setString(s);
	text.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - text.getLocalBounds().width) / 2, -10));
	text.setFillColor(Color(117, 117, 120));


}

void PanelQueue::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(text);

	for (auto& a : task) {
		a->draw(window);
	}
}


void PanelQueue::SetText(wstring s)
{
	text.setString(s);
	text.setPosition(rectagle.getSize().x - text.getLocalBounds().width - 10, rectagle.getPosition().y + rectagle.getSize().y / 2 - 50);
}

void PanelQueue::SetPosition(Vector2f vector)
{
	rectagle.setPosition(rectagle.getPosition() + vector);
	text.setPosition(text.getPosition() + vector);
}

void PanelQueue::getTasks(MyQueue<Task> tasks)
{
	for (auto& a : task) {
		delete a;
	}
	task.clear();
	auto it = MyQueue<Task>::iterator();
	it = tasks.begin();
	int i = 0;
	while (it != tasks.end()) {
		task.push_back( new TaskV(rectagle.getSize().x - 10,40 ));
		string s = to_string((*it).ID())+ ":" + to_string((*it).GetAllTact()) + ":" + to_string((*it).GetKolProc());
		wstring ws;
		for (auto a : s) {
			ws += a;
		}
		task.back()->SetInfo(ws);
		task.back()->setColor(Color((*it).color[0], (*it).color[1], (*it).color[2]));
		task.back()->SetPosition(rectagle.getPosition() + Vector2f(5,25 + i * 45));
		it++;
		i++;
		if (45 * (i + 1) + 25 > rectagle.getSize().y)
			break;
	}
}

	












TaskV::TaskV(int Windht, int Height)
{
	rectagle.setPosition(0, 0);
	rectagle.setSize(Vector2f(Windht, Height));
	rectagle.setFillColor(Color(180, 180, 180));
	rectagle.setOutlineThickness(3);
	rectagle.setOutlineColor(Color(77, 77, 77));


	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");


	info.setFont(font);
	info.setCharacterSize(Height * 0.5);
	info.setString(L"0:0");
	Vector2f temp = rectagle.getPosition();
	info.setPosition(Vector2f((rectagle.getSize().x - info.getLocalBounds().width) / 2, (rectagle.getSize().y - info.getLocalBounds().height) / 2 ) + temp);
	info.setFillColor(Color(117, 117, 120));
}

void TaskV::draw(RenderWindow* window)
{
	window->draw(rectagle);
	window->draw(info);
}

void TaskV::SetInfo(wstring s)
{
	info.setString(s);
	info.setPosition(rectagle.getPosition() + Vector2f((rectagle.getSize().x - info.getLocalBounds().width) / 2, (rectagle.getSize().y - info.getLocalBounds().height) / 2));
}

void TaskV::SetPosition(Vector2f vector)
{
	rectagle.setPosition(rectagle.getPosition() + vector);
	info.setPosition(info.getPosition() + vector);
}