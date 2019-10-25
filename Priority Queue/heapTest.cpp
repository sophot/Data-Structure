#include "MinHeap.h"


int main(){
    CompleteTree pq;

    int d;
    while(cin >> d){
        pq.push(d);
    }
    cout << endl;

    cout << "height: " << pq.height() << endl;
    pq.print();
    cout << "pop: " << pq.pop() << endl;
    pq.print();
    cout << "pop: " << pq.pop() << endl;
    pq.print();  

    return 0;
}
/*  --> EOF in mac = control + D <--
18 7 22 33 50 19 28 25 30 17 20 15 10
10 34 67 38 40 68 70 39 41 45 50 88 90 98 99 17
12 23 34 43 32 2 5 9 8 4 7 100 111 3 321 6 50 300
9999 45000 4321 3456 9847 2484 393 123 5430 12 43 9 4 1 -100
*/