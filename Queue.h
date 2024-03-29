#ifndef QUEUE_H
#define QUEUE_H

#include "SLinkedList.h"

template<typename Type>
class Queue{
    private:
        SLinkedList<Type>* list;
    public: 
        Queue();
        ~Queue();
        bool empty() const;
        Type front() const;
        void enqueue(const Type&);
        Type dequeue();
        void showList() const;
}; //End of Interface//


//*****************************************************************//
template<typename Type>
Queue<Type>::Queue():
    list(new SLinkedList<Type>()){}

template<typename Type>
Queue<Type>::~Queue(){
    list->~SLinkedList();
}

template<typename Type>
    bool Queue<Type>::empty() const{
        return list->isEmpty();
    }

template<typename Type>
    Type Queue<Type>::front() const{
        return list->front();
    }

template<typename Type>
    void Queue<Type>::enqueue(const Type& newData){
        list->addBack(newData);
    }

template<typename Type>
    Type Queue<Type>::dequeue(){
        return list->removeFront();
    }

template<typename Type>
    void Queue<Type>::showList() const{
        list->showList();
    }

#endif