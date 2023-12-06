#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <thread>
#include "../queue/lib/queue_lib.h"
using namespace std;

class Task {
private:
	static int kolTask;
	int id;
	int kolProc;
	int kolTact;
	int allTact;
public:
	int color[3];
	Task();
	Task(int kolProc, int kolTact);
	bool Tact();

	int ID() { return id; }
	int GetKolProc() { return kolProc; }
	int GetKolTract() { return kolTact; }
	int GetAllTact() { return allTact; }
};


class Proc {
public:
	Proc(int kol = 0);
	void setKolProc(int kol);
	bool SetTask(Task task);
	void Tact();

	int kol = 0;

protected:
	class Core {
	private:
		Task* task;
		bool flag;
	public:
		Core();
		Core(const Core& other);
		Core& operator=(const Core& other) {
			this->flag = other.flag;
			this->task = other.task;
			return *this;
		}
		bool SetTask(Task* task);
		bool free() { return flag; }
		void StopTask();
		int IdTask() { return (task == nullptr) ? 0 : task->ID();}
		int GetTact() { return (task == nullptr) ? 0 : task->GetKolTract();}
		int* GetColor() { return (task == nullptr) ? nullptr : task->color; }
		Task& GetTask() { return *task; }

	};

public:
	vector<Core>& GetCore() { return Cores; }
	vector<Core> Cores;

	list<Task> Tasks;
private:
	int kolProz, kolFree;
	vector<int> id;
};


class Controller : public Proc {
public:
	struct CoreInfo {
		int Id;
		int KolTact;
		int color[3]{};
		CoreInfo(int id = 0, int tact = 0, int* color = nullptr) {
			this->Id = id;
			this->KolTact = tact;
			if (color != nullptr) {
				for (int i = 0; i < 3; i++)
					this->color[i] = color[i];
			}
		}
	};

	Controller(int kolProc, int Shans = 50, int minKolProc = 1, int maxKolProc = 16, int minKolTact = 1, int  maxKolTact = 20);
	void Tact();
	Proc& GetProc() { return proc; }
	MyQueue<Task> GetTask() { return tasks; }
	MyQueue<Task> GetTaskProc() {
		MyQueue<Task> temp;
		for (auto a : proc.Tasks) {
			temp.push(a);
		}
		return temp;
	}
	

	int height() { return Height; }
	int width() { return Width; }
	int GetKolProc() { return kolProc; }

private:
	Proc proc;
	MyQueue<Task> tasks;


	int Width, Height;
	vector<vector<CoreInfo>> TablCores;



	int kolProc;
	int Shans;
	int minKolProc, maxKolProc;
	int minKolTact, maxKolTact;


public:
	vector<vector<CoreInfo>> GetTablCores() {
		for (int i = 0; i < kolProc; i++) {
			int x = (int)(i / Height);
			int y = (int)(i % Height);
			TablCores.at(y).at(x) = CoreInfo(proc.Cores[i].IdTask(), proc.Cores[i].GetTact(),proc.Cores[i].GetColor());
		}
		return TablCores;
	}
	int GetKol() { return proc.kol; }
};