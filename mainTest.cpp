#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

int main(){
	// int x = 1;

	// cout << (1+7*x++ < 3-1/5) << endl;
	// cout << x << endl;

	Queue<int> que;

	que.push(1);
	que.push(2);
	que.push(3);
	que.showList();
	cout << que.front() << endl;
	cout << que.pop() << endl;
	que.showList();

	return 0;
}