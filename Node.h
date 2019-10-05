#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>

using namespace std;

template<typename Type>class SLinkedList;

template<typename Type>
    class Node{
        private:
            Node<Type>* next;
            Type data;

        public:
            friend class SLinkedList<Type>;
            Node(Type);
            Type getData() const;
            Node<Type>* getNext();
            void setNext(Node<Type>*);
            
    };  //end of Interface//


//*****************************************************************//
template<typename Type>
        Node<Type>::Node(Type _data):  data(_data), next(NULL){}

template<typename Type>
    Type Node<Type>::getData() const {
        return data;
    }

template<typename Type>
    Node<Type>* Node<Type>::getNext(){
    return next;
}

template<typename Type>
    void Node<Type>::setNext(Node<Type>* n){
    next = n;
}


#endif