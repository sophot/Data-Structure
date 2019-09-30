#ifndef QUEUE_H
#define QUEUE_H

#include "SLinkedList.h"

template<typename Type>
class Queue{
    private:
        SLinkedList<Type> list;
    public: 
        Queue();
        bool empty() const;
        Type front() const;
        void push(const Type&);
        Type pop();
        void showList() const;
};

template<typename Type>
Queue<Type>::Queue(){}

template<typename Type>
    bool Queue<Type>::empty() const{
        return list.isEmpty();
    }

template<typename Type>
    Type Queue<Type>::front() const{
        return list.front();
    }

template<typename Type>
    void Queue<Type>::push(const Type& newData){
        list.addBack(newData);
    }

template<typename Type>
    Type Queue<Type>::pop(){
        return list.removeFront();
    }

template<typename Type>
    void Queue<Type>::showList() const{
        list.showList();
    }

#endif