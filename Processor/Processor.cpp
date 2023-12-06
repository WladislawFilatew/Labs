
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "MainForm.h"
#include "TestMain.h"
using namespace std;
using namespace sf;



int WinMain() {
	MainForm a;
	a.Start();
}




int main() {

	Controller a( 9, 50, 1, 9, 1, 10);
	int i = 0;
	for (; i < 1000; i++) {
		a.Tact();
		system("cls");
		cout << "Tact:" << i + 1 << endl;
		
		vector<vector<Controller::CoreInfo>> temp = a.GetTablCores();
		for (int j = 0; j < temp.size(); j++) {
			for (int k = 0; k < temp[j].size(); k++) {
				cout << "Proc:" << (j * temp.size() + k + 1) << " ID:" << temp[j][k].Id << " Tact:" << temp[j][k].KolTact << " | ";
			}
			cout << endl;
		}

		MyQueue<Task> tasks(a.GetTask());
		auto it = MyQueue<Task>::iterator();
		it = tasks.begin();
		while (it != tasks.end()) {
			cout << (*it).ID() << " " << (*it).GetAllTact() << " " << (*it).GetKolProc() << endl;
			it++;
		}

		chrono::milliseconds timespan(50);
		this_thread::sleep_for(timespan);
	}

	cout << endl << "________________________" << endl <<  (double)a.GetKol() / i;

}
