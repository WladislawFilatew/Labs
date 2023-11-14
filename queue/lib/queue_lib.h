#include <iostream>
using namespace std;

template<class T>
class MyQueue {

public:
	MyQueue() noexcept {
		sz = 0;
		head = tail = nullptr;
	}
	size_t size() noexcept { return sz; }
	void clear() {
		while (!this->empty())
			this->pop();
	}
	void push(T value) {
		if (sz == 0) {
			head  = new Note<T>(value);
			tail = head;
		}
		else {
			Note<T>* temp = new Note<T>(value, tail);
			tail->prev = temp;
			tail = temp;
		}
		sz++;
	}
	T& top() {
		if (sz == 0)
			throw exception("Очередь пуста");
		return head->value;
	}
	bool empty() noexcept {
		if (sz == 0)
			return true;
		return false;
	}
	void pop() {
		if (sz == 0)
			throw exception("Очередь пуста");
		if (head->prev != nullptr) {
			Note<T>* temp = head->prev;
			temp->next = nullptr;
			delete head;
			head = temp;
		}
		else
			delete head;
		sz--;
	}
	~MyQueue() {
		this->clear();
	}


private:
	template<class T>
	class Note {
	public:
		T value;
		Note* next;
		Note* prev;
		Note(T value = T(), Note* next = nullptr,Note* prev = nullptr) {
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
	};

	Note<T>* tail;
	Note<T>* head;
	size_t sz; 
};