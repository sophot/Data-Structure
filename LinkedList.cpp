#include <string>
#include <vector>
#include "SLinkedList.h"

using namespace std;

void instructions(){
    cout << "Enter one of the following\n"
        << " 1 to insert at beginning of list\n"
        << " 2 to insert at the end of list\n"
        << " 3 to delete from beginning of list\n"
        << " 4 to delete from the end of list\n"
        << " 5 to end list processing\n";
}

template<typename T>
    void testList(SLinkedList<T>& ListObject, const string& typeName){
        cout << "Testing a List of " << typeName << " values\n";
        instructions();

        int choice;
        T value;

        do{
            cout << "? ";
            cin >> choice;

            switch(choice){
                case 1:
                    cout << "Enter " << typeName << ": ";
                    cin >> value;
                    ListObject.insertAtFront(value);
                    ListObject.print();
                    break;
                case 2:
                    cout << "Enter " << typeName << ": ";
                    cin >> value;
                    ListObject.insertAtBack(value);
                    ListObject.print();
                    break;
                case 3:
                    if(ListObject.removeFromFront(value)){
                        cout << value << " removed from list";
                    }
                    ListObject.print();
                    break;
                // case 4:
                //     if(ListObject.removeFromBack(value)){
                //         cout << value << " removed from list";
                //     }
                //     ListObject.print();
                //     break;
            }
        }while(choice < 5);
        cout << "End of list test\n";
    }

int main(){
    // List<int> integerList;
    // testList(integerList, "integer");
    // int a = 9;
    // Node<int *> i(&a);
    
    vector<int> a {1, 2, 4};

    cout << a.at(1) << endl;

    
    return 0; 
}