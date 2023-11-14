#include <iostream>
#include "lib/queue_lib.h"
using namespace std;


int main() {
	MyQueue<int> a;
	a.push(1);
	a.push(2);
	a.push(3);

	cout << a.size() << endl;

	while (!a.empty()) {
		cout << a.top() << endl;
		a.pop();
	}

}