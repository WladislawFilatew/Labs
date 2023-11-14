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
				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 5; j++) {
						if (knopki[i][j]->MousHover(window)) {
							MousKlic(knopki[i][j]->Text().getString());
						}
					}
				}
			}
		}
	}

	exit->MousHover(window);
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			knopki[i][j]->MousHover(window);
		}
	}
	
}

void MainForm::Draw()
{
	window->clear(Color(28,32,42));

	exit->draw(window);
	panel->draw(window);

	window->draw(name);
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			knopki[i][j]->draw(window);
		}
	}

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
	name.setString(L"Калькулятор");

	panel = new PanelFormul(window->getSize().x, 400);

	knopki = new button ** [7];
	for (int i = 0; i < 7; i++) {
		knopki[i] = new button*[5];
		for (int j = 0; j < 5; j++) {
			Vector2u r = window->getSize();
			int rx = r.x / 5 - 12;
			int ry = (r.y - 550) / 7 - 10;
			knopki[i][j] = new  button(rx, ry);
			knopki[i][j]->SetPosition(Vector2f(j * (rx + 10) + 10, i * (ry + 10) + 550 ));
			knopki[i][j]->Text().setString("X");
			knopki[i][j]->Text().setCharacterSize(50);
			knopki[i][j]->SetColor(Color(45, 50, 68));
			knopki[i][j]->SetHoverColor(Color(54, 59, 77));
		}
	}
	zap_knopki();
	
}

MainForm::MainForm(int Windht, int Height)
{
	window = new RenderWindow(VideoMode(Windht, Height), L"Калькулятор", Style::None);
	window->setPosition(Vector2i(100, 100));
	this->Init();
}

MainForm::~MainForm()
{
	delete window;
	delete exit;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			delete knopki[i][j];
		}
		delete[] knopki[i];
	}
	delete[]knopki;
}

void MainForm::Start()
{
	window->setFramerateLimit(60);
	while (window->isOpen()) {
		Update();


		Draw();
	}

}

void MainForm::zap_knopki()
{
	int k = 1;
	for (int i = 5; i >= 3; i--) {
		for (int j = 1; j <= 3; j++,k++) {
			knopki[i][j]->Text().setString(to_string(k));
		}
	}
	knopki[6][2]->Text().setString(L"0");
	knopki[6][3]->Text().setString(L".");
	knopki[6][1]->Text().setString(L",");

	knopki[0][1]->Text().setString(L"π");
	knopki[0][2]->Text().setString(L"e");
	knopki[0][3]->Text().setString(L"CE");
	knopki[0][4]->Text().setString(L"<");
	knopki[1][0]->Text().setString(L"sin");
	knopki[1][1]->Text().setString(L"xⁿ");
	knopki[1][2]->Text().setString(L"ⁿ√x");
	knopki[1][3]->Text().setString(L"logₓ");


	knopki[1][4]->Text().setString(L"%");
	knopki[2][1]->Text().setString(L"(");
	knopki[2][2]->Text().setString(L")");
	knopki[2][3]->Text().setString(L"n!");
	knopki[2][4]->Text().setString(L"÷");
	knopki[3][4]->Text().setString(L"×");
	knopki[4][4]->Text().setString(L"-");
	knopki[5][4]->Text().setString(L"+");
	knopki[6][4]->Text().setString(L"=");

	knopki[2][0]->Text().setString(L"cos");
	knopki[3][0]->Text().setString(L"tg");
	knopki[4][0]->Text().setString(L"ctg");

	knopki[0][0]->Text().setString(L"ln");

	knopki[5][0]->Text().setString(L"Aⁿₓ");
	knopki[6][0]->Text().setString(L"Cⁿₓ");
}

void MainForm::MousKlic(wstring s)
{
	wstring temp = panel->Text().getString();
	if (s == "CE")
		panel->SetText(L"0");
	if (s == "<") {
		if (temp.size() == 1)
			temp = L"0";
		else
			temp.pop_back();
		panel->SetText(temp);
	}
		
	if (s >= "0" && s <= "9" || s == L"π" || s == "e") {
		if (temp == "0")
			temp = s;
		else
			temp += s;
		panel->SetText(temp);
	}
	if (s == "+" || s == "-" || s == L"×" || s == L"÷" || s == "%" || s == "." || s == ",")
		panel->SetText(temp + s);
	if (s >= "(" && s <= ")") {
		if (temp == "0")
			temp = s;
		else
			temp += s;
		panel->SetText(temp);
	}
	if (s == "n!")
		panel->SetText(temp + "!");
	if (s == "ln" || s == "sin" || s == "cos" || s == "tg" || s == "ctg" ) {
		if (temp == "0")
			temp = s + "(";
		else
			temp += s + "(";
		panel->SetText(temp);
	}
	if (s == L"logₓ") {
		s.pop_back();
		if (temp == "0")
			temp = s + "(";
		else
			temp += s + "(";
		panel->SetText(temp);
	}
	if (s == L"Aⁿₓ" || s == L"Cⁿₓ") {
		s.pop_back();
		s.pop_back();
		if (temp == "0")
			temp = s + "(";
		else
			temp += s + "(";
		panel->SetText(temp);
	}
	if (s == L"xⁿ") {
		if (temp == "0")
			temp = L"pow(";
		else
			temp += L"pow(";
		panel->SetText(temp);
	}
	if (s == L"ⁿ√x") {
		if (temp == "0")
			temp = L"sqrt(";
		else
			temp += L"sqrt(";
		panel->SetText(temp);
	}
	if (s == "=") {
		try {
			string str;
			for (wchar_t a : temp) {
				if (a == *L"π")
					str += "pi";
				else if (a == *L"×")
					str += "*";
				else if (a == *L"÷")
					str += "/";
				else
					str += a;
			}
			calculator c(str);
			str = Remove0(to_string(c.Ansver()));
			temp = L"";
			for (auto a: str){
				temp += a;
			}
			panel->SetText(temp);
		}
		catch (exception& error) {
			temp = L"Неверная формула";
			panel->SetText(temp);
		}
	}
}



