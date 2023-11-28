#include <iostream>
using namespace std;

template<class T>
class MyQueue {

public:
	MyQueue() noexcept;
	MyQueue(MyQueue<T>& other);
	size_t size() noexcept { return sz; }
	void clear();
	void push(T value);
	T& top();
	bool empty() noexcept;
	void pop();
	~MyQueue();

	

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
public:
	class iterator {
		Note<T>* t;
	public:
		iterator() { t = nullptr; }
		void operator=(Note<T>* note) {
			t = note;
		}
		T operator*() {
			return t->value;
		}
		void operator++(int k) {
			t = t->prev;
		}
		bool operator!=(const Note<T>* note) {
			return t != note;
		}
	};

	Note<T>* begin() { return head; }
	Note<T>* end() { return (tail==nullptr)?tail:tail->prev; }


};

template<class T>
MyQueue<T>::MyQueue() noexcept {
	sz = 0;
	head = tail = nullptr;
}
template<class T>
MyQueue<T>::MyQueue(MyQueue<T>& other) {
	this->sz = 0;
	this->head = this->tail = nullptr;
	auto it = MyQueue<T>::iterator();
	it = other.begin();
	while (it != other.end()) {
		this->push((*it));
		it++;
	}
}
template<class T>
void MyQueue<T>::clear() {
	while (!this->empty())
		this->pop();
}
template<class T>
void MyQueue<T>::push(T value) {
	if (sz == 0) {
		head = new Note<T>(value);
		tail = head;
	}
	else {
		Note<T>* temp = new Note<T>(value, tail);
		tail->prev = temp;
		tail = temp;
	}
	sz++;
}
template<class T>
T& MyQueue<T>::top() {
	if (sz == 0)
		throw exception("Очередь пуста");
	return head->value;
}
template<class T>
bool MyQueue<T>::empty() noexcept {
	if (sz == 0)
		return true;
	return false;
}
template<class T>
void MyQueue<T>::pop() {
	if (sz == 0)
		throw exception("Очередь пуста");
	if (head->prev != nullptr) {
		Note<T>* temp = head->prev;
		temp->next = nullptr;
		delete head;
		head = temp;
	}
	else {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	sz--;
}
template<class T>
MyQueue<T>::~MyQueue() {
	this->clear();
}