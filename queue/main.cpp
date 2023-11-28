#include <iostream>
#include "lib/queue_lib.h"
#include <list>
using namespace std;


void func(MyQueue<int> &a) {
	auto it = MyQueue<int>::iterator();
	it = a.begin();
	while (it != a.end()) {
		cout << (*it) << endl;
		it++;
	}
}


int main() {
	MyQueue<int> a;



	a.push(1);
	a.pop();
	a.push(2);
	a.pop();
	func(a);
	a.push(3);

	//while (!a.empty()) {
	//	cout << a.top() << endl;
	//	a.pop();
	//}

	/*auto it = MyQueue<int>::iterator();
	it = a.begin();
	while (it != a.end()) {
		cout << (*it) << endl;
		it++;
	}*/


	//list<int> b;
	//b.push_back(1);
	//b.push_back(2);
	//b.push_back(3);
	//auto it = list<int>::iterator();
	//it = b.begin();
	//while (it != b.end()) {
	//	cout << (*it);
	//	it++;
	//}


}