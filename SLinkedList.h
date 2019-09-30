#ifndef LIST_H
#define LIST_H
#include "Node.h"

template<typename Type>
    class SLinkedList{
        private:
            Node<Type>* head;
            Node<Type>* tail;

            Node<Type>* getNewNode(const Type& value){
                return new Node<Type>(value);
            }

        public:
            ~SLinkedList();
            SLinkedList();
            int size() const;
            bool isEmpty() const;
            Type front() const;
            Type back() const;
            Node<Type>* getHead() const;
            Node<Type>* getTail() const;
            // int count(const Type&) const;

            void addFront(const Type&);
            void addBack(const Type&);
            Type removeFront();
            void showList() const;
    };

template<typename Type>
    SLinkedList<Type>::~SLinkedList(){
        if(!isEmpty()){
            cout << "Destructor is deleting nodes ...\n";
            Node<Type>* currentPtr = head;
            Node<Type>* tempPtr = NULL;

            while(currentPtr != NULL){
                tempPtr = currentPtr;
                cout << tempPtr->getData() << endl;
                currentPtr = currentPtr->getNext();
                delete tempPtr;
            }
        }
    }

template<typename Type>
    SLinkedList<Type>::SLinkedList(): head(NULL), tail(NULL){}

template<typename Type>
    int SLinkedList<Type>::size() const{
        int c = 0;
        Node<Type>* temp = head;
        while(temp != tail){
            c++;
            temp = temp->getNext();
        }
        return c;
    }

template<typename Type>
    bool SLinkedList<Type>::isEmpty() const{
        return (head==NULL);
    }

template<typename Type>
Type SLinkedList<Type>::front() const{
    if (isEmpty()) {	//if list is empty
        return -1;
    }
    else {
        return head->getData();
    }
}

template<typename Type>
Type SLinkedList<Type>::back() const{
    if (isEmpty()) {	//if list is empty
        return -1;
    }
    else {
        return tail->getData();
    }
}

template<typename Type>
Node<Type>* SLinkedList<Type>::getHead() const{
    return this->head;
}

template<typename Type>
Node<Type>* SLinkedList<Type>::getTail() const{
    return this->tail;
}

template<typename Type>
    void SLinkedList<Type>::addFront(const Type& value){
        Node<Type>* newNode(getNewNode(value));
        if(isEmpty()){
            head = tail = newNode;
        }else{
            newNode->setNext(head);
            head = newNode;
        }
    }

template<typename Type>
    void SLinkedList<Type>::addBack(const Type& value){
        Node<Type>* newNode(getNewNode(value));
        if(isEmpty()){
            head = tail = newNode;
        }else{
            tail->setNext(newNode);
            tail = newNode;
        }
    }

template<typename Type>
    Type SLinkedList<Type>::removeFront(){
        if(!isEmpty()){
            Node<Type>* tempPtr = head;
            int value = head->getData();
            head = head->getNext();
            delete tempPtr;
            return value;
        }else{
            return -1;
        }
    }

template<typename Type>
        void SLinkedList<Type>::showList() const{
            while(isEmpty()){
                cout << "The list is empty\n";                    
                return;
            }
            cout << "The list is: ";
            Node<Type>* currentPtr = head;
            while(currentPtr != NULL){
                cout << currentPtr->getData() << ' ';
                currentPtr = currentPtr->getNext();
            }
            cout << endl;
        }

#endif