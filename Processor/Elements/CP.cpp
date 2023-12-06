#include"CP.h"

//Task
Task::Task() {
	id = -1;
	kolProc = kolTact = allTact = 0;
}

Task::Task(int kolProc, int kolTact) {
	id = (++kolTask);
	this->kolProc = kolProc;
	this->kolTact = this->allTact = kolTact;
	for (auto& col : color) {
		col = rand() % 256;
	}
}
bool Task::Tact() {
	kolTact--;
	return kolTact == 0;
}

int Task::kolTask = 0;

//Proc
Proc::Proc(int kol) {
	setKolProc(kol);
}
void Proc::setKolProc(int kol) {
	Cores.clear();
	Tasks.clear();
	this->kolFree = this->kolProz = kol;
	for (int i = 0; i < kol; i++) {
		Cores.push_back(Core());
	}
}
bool Proc::SetTask(Task task) {
	if (kolFree < task.GetKolProc())
		return false;
	Tasks.push_back(task);
	int KolNProc = task.GetKolProc();
	for (auto& a : Cores) {
		if (a.SetTask(&Tasks.back()))
			KolNProc--;
		if (KolNProc == 0)
			break;
	}
	kolFree -= task.GetKolProc();
	return true;
}
void Proc::Tact() {
	if (!id.empty()) {
		for (auto& a : Cores) {
			if (!a.free())
				kol++;
			if (!a.free() && find(id.begin(), id.end(), a.IdTask()) != id.end()) {
				a.StopTask();
				kolFree++;
			}
		}
		auto it = Tasks.begin();
		while (it != Tasks.end()) {
			if (find(id.begin(), id.end(), (*it).ID()) != id.end())
				it = Tasks.erase(it);
			else
				it++;
		}
	}
	id.clear();
	for (auto& a : Tasks) {
		if (a.Tact())
			id.push_back(a.ID());
	}
}

//Proc::Core
class Core;
Proc::Core::Core()
{
	task = nullptr;
	flag = true;
}

Proc::Core::Core(const Core& other)
{
	this->flag = other.flag;
	this->task = other.task;
}


bool Proc::Core::SetTask(Task* task)
{
	if (!flag)
		return false;
	this->task = task;
	flag = false;
	return true;
}

void Proc::Core::StopTask()
{
	task = nullptr;
	flag = true;
}

//Controller
Controller::Controller(int kolProc, int Shans, int minKolProc, int maxKolProc, int minKolTact, int maxKolTact)
{
	srand((int)std::time(NULL));
	this->kolProc = kolProc;
	this->Shans = Shans;
	this->minKolProc = minKolProc;
	this->maxKolProc = maxKolProc;
	this->minKolTact = minKolTact;
	this->maxKolTact = maxKolTact;


	Height = sqrt(kolProc);
	Width = (kolProc % Height) ? kolProc / Height + 1 : kolProc / Height;


	proc = Proc(this->kolProc);

	TablCores.resize(Height);
	for (int i = 0; i < Height; i++) {
		TablCores[i].resize(Width);
	}
}

void Controller::Tact()
{
	if (rand() % 101 < Shans) {
		int KP = rand() % (maxKolProc - minKolProc + 1) + minKolProc;
		int KT = rand() % (maxKolTact - minKolTact + 1) + minKolTact;
		tasks.push(Task(KP, KT));
	}
	proc.Tact();
	if (!tasks.empty() && proc.SetTask(tasks.top())) {
		tasks.pop();
	}
}



