#ifndef STACK_H
#define STACK_H

#include "SLinkedList.h"

template<typename Type>
class Stack{

private:
    SLinkedList<Type>* list;
public:
    Stack();
    ~Stack();
    int size() const;
    bool isEmpty() const;
    void push(const Type&);
    Type pop();
    Type top() const;
    void showStack() const;
};  //End of Interface//

//*****************************************************************//
template<typename Type>
Stack<Type>::Stack():
    list(new SLinkedList<Type>()) {}

template<typename Type>
Stack<Type>::~Stack(){
    list->~SLinkedList();
}

template<typename Type>
int Stack<Type>::size() const{
    return list->size();
}

template<typename Type>
bool Stack<Type>::isEmpty() const{
    return list->isEmpty();
}

template<typename Type>
void Stack<Type>::push(const Type& n){
    list->addFront(n);
}

template<typename Type>
Type Stack<Type>::pop(){
    return list->removeFront();
}

template<typename Type>
Type Stack<Type>::top() const{
    return list->front();
}

template<typename Type>
void Stack<Type>::showStack() const{
    list->showList();
}

#endif