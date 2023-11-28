#include "MainForm.h"

void MainForm::Update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == Event::MouseButtonReleased) {
			if (event.mouseButton.button == Mouse::Left) {
				if (exit->MousHover(window)) {
					window->close();
				}
			}
		}
	}

	exit->MousHover(window);

	
}

void MainForm::Draw()
{
	window->clear(Color(28,32,42));

	window->draw(PanelMenu);

	exit->draw(window);
	
	panelProc->draw(window);
	panelQueue->draw(window);
	panelTask->draw(window);


	window->draw(name);
	
	window->display();
}

void MainForm::Init()
{
	exit = new button(40, 50);
	exit->SetColor(Color(28, 32, 42));
	exit->Text().setString("X");
	exit->SetPosition(Vector2f(Vector2f(window->getSize().x - exit->GetSize().x, 0)));
	exit->SetHoverColor(Color::Red);

	if (!font.loadFromFile("Times.ttf"))
		throw exception("NON font");

	name.setFont(font);
	name.setCharacterSize(30);
	name.setPosition(Vector2f(30, 10));
	name.setFillColor(Color::White);
	name.setString(L"Процессор");


	PanelMenu.setSize(Vector2f(window->getSize().x, 60));
	PanelMenu.setFillColor(Color(17, 24, 38));



	int kolProc = 16;
	controller = new Controller(kolProc, 50, 1, kolProc, 1, 10);

	
	panelProc = new PanelProc(1000, 1000, controller);
	panelProc->SetPosition(Vector2f(500, 0));

	panelQueue = new PanelQueue(200, 1000,L"Очередь:");
	panelQueue->SetPosition(Vector2f(1755, 0));


	panelTask = new PanelQueue(200, 1000,L"Задачи:");
	panelTask->SetPosition(Vector2f(1545, 0));

}

MainForm::MainForm(int Windht, int Height)
{
	window = new RenderWindow(VideoMode(Windht, Height), L"Процессор", Style::None);
	window->setPosition(Vector2i(100, 100));
	this->Init();
}

MainForm::~MainForm()
{
	delete window;
	delete exit;

	delete panelProc;
	delete panelQueue;
	delete panelTask;
}

void MainForm::Start()
{
	//window->setFramerateLimit(60);
	while (window->isOpen()) {
		Update();

		controller->Tact();
		panelProc->SetProc(controller);
		panelQueue->getTasks(controller->GetTask());
		panelTask->getTasks(controller->GetTaskProc());

		Draw();

		chrono::milliseconds timespan(400);
		this_thread::sleep_for(timespan);
	}

}


