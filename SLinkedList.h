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

            void addFront(const Type&);
            void addBack(const Type&);
            Type removeFront();
            Type removeBack();  //haven't implemented yet
            void remove(Type);
            void showList() const;
    }; //End of Interface//


//*****************************************************************//
template<typename Type>
    SLinkedList<Type>::~SLinkedList(){
        if(!isEmpty()){
            cout << "\nDestructor is deleting nodes ...\n";
            Node<Type>* currentPtr = head;
            Node<Type>* tempPtr = NULL;

            while(currentPtr != NULL){
                tempPtr = currentPtr;
                // cout << tempPtr->getData() << endl;
                currentPtr = currentPtr->getNext();
                delete tempPtr;
            }
            cout << "Done!\n";
        }
    }

template<typename Type>
    SLinkedList<Type>::SLinkedList(): head(NULL), tail(NULL){}

template<typename Type>
    int SLinkedList<Type>::size() const{
        int c = 0;
        // Node<Type>* temp = head;
        // while(temp != tail){
        //     c++;
        //     temp = temp->getNext();
        // }
        for(Node<Type>* tmp = head; tmp != NULL; tmp = tmp->getNext()){
            c++;
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
            Type value = head->getData();
            head = head->getNext();
            delete tempPtr;
            return value;
        }else{
            return 0;
        }
    }

template<typename Type>
Type SLinkedList<Type>::removeBack(){
    if(isEmpty()){
        return 0;
    }

    Node<Type> * tmp = this->getHead();
    while(tmp->getNext() != getTail()){
        tmp = tmp->getNext();
    }
    this->tail = tmp;
    delete tmp->getNext();
}

template<typename Type>
    void SLinkedList<Type>::remove(Type e){
        Node<Type>* element = new Node<Type>(e);
        if(element == getHead()){
            this->removeFront();
        }

        Node<Type> *tmp = getHead();
        while(tmp->getNext() != element){
            tmp = tmp->getNext();
        }

        Node<Type> *toDel = tmp->getNext();

        tmp->setNext(toDel->getNext());
        
        delete toDel;
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
            cout << "\n\n";
        }

#endif