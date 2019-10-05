#pragma once


#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;


class Node {

public:
	int data;
	Node* next;

	Node(int _data) {
		this->data = _data;
		this->next = NULL;
	}
};


class CLinkedList{
    protected:
        bool empty(){
            return (this->head == NULL);
        }

        Node* head;
        Node* tail;
    public:

        CLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

 
    //need to change tail code
    void addBack(int x) {
        Node* temp = new Node(x);
        if(!empty()){
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }else{
            head = temp;
            tail = temp;
        }
	} //end of addBack()

        void Delete(int n){
            //temp points to the one Node before the deleting Node
            //nodeToDelete will hold Node that will be deleted
            Node* temp = this->head;
            Node* nodeToDelete = NULL;

            for(int i = 0; i < n-1; i++){
                temp = temp->next;
            }

            if(n<=0){
                nodeToDelete = temp;
            }else{
                nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
            }

            if(nodeToDelete == this->head){   //if Node to delete is head
                this->head = this->head->next;
            }
            
            if(nodeToDelete == this->tail){   //if Node to delete is tail
                this->tail = temp;
                this->tail->next = this->head;
            }

            delete nodeToDelete;
        }

        void showList() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {	//list is not empty
			Node* temp = this->head;
            do{
				cout << temp->data << ' ';
				temp = temp->next;
            }while(temp != this->tail->next);
			cout << endl;
		}
	}

};


#endif