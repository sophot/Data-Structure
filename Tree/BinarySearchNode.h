#ifndef BSN_H
#define BSN_H

#include <iostream>
#include <algorithm>
#include "../Queue.h"

using namespace std;

class BinarySearchNode {
    private:
        int element;
        BinarySearchNode *left_tree;
        BinarySearchNode *right_tree;
        bool hasOnlyOneChild() const;
    public:
        BinarySearchNode( const  int& );
        int retrieve() const;  
        BinarySearchNode *left() const;  
        BinarySearchNode *right() const;  
        bool empty() const;  
        bool is_leaf() const;  
        int front() const;  
        int back() const;  
        int size() const;  
        int height() const;  
        bool find(const  int&) const;
        void insert(BinarySearchNode*&, const int&);
        void erase(BinarySearchNode*& , const int&);
        void clear();
            //PRINT TREE//
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();
        void breadthFirstPrint();
};


bool BinarySearchNode::hasOnlyOneChild() const{
    return ((left()==0 && right() != 0) || (left()!=0 && right()==0));
}


BinarySearchNode::BinarySearchNode(const  int& data){
    element = data;
    left_tree = NULL;
    right_tree = NULL;
}


 int BinarySearchNode::retrieve() const{
    return element;
}


BinarySearchNode* BinarySearchNode::left() const{
    return left_tree;
}


BinarySearchNode* BinarySearchNode::right() const{
    return right_tree;
}


bool BinarySearchNode::empty() const{
    return this == 0;
}


bool BinarySearchNode::is_leaf() const{
    return ((left() == NULL) && (right() == NULL));
}


 int BinarySearchNode::front() const{
        if(left() == 0){
            return retrieve();
        }else{
            return left()->front();
        }
}


 int BinarySearchNode::back() const{
    if(right() == 0){
        return retrieve();
    }else{
        return right()->back();
    }
}


int BinarySearchNode::size() const{
    if(!empty()){
        return 1 + left()->size() + right()->size();
    }
    return 0;
}


int BinarySearchNode::height() const{
    if(!empty()){
        return 1 + std::max(left()->height(), right()->height());
    }
    return -1;
}


bool BinarySearchNode::find(const  int& data) const{
    if(empty()){
        return false;
    }
    if(data == retrieve()){
        return true;
    }else if(data < retrieve()){
        return left()->find(data);
    }else if(data > retrieve()){
        return right()->find(data);
    }
}


void BinarySearchNode::insert(BinarySearchNode *&ptr, const  int& data){
    if(ptr == NULL){
        ptr = new BinarySearchNode(data);
    }else{
        if(data < retrieve()){
            left()->insert(left_tree, data);
        }else if(data > retrieve()){
            right()->insert(right_tree, data);
        }
    }
/*  THIS WORKS FINE IF NODE IS LEAF NODE ONLY
    WHEN NOT LEAF -> WILL ACCESS NULLPTR AT LAST ELSE
    if(this->is_leaf()){
        if(data < retrieve()){
            left_tree = new BinarySearchNode(data);
        }else if (data > retrieve()){
            right_tree = new BinarySearchNode(data);
        }
    }else{
        (data < retrieve())? left()->insert(data): right()->insert(data);
    }
*/
}


void BinarySearchNode::erase(BinarySearchNode*& ptr, const  int& data){
    if(ptr == NULL){
        return;     //data is not in the tree
    }
    if(data < retrieve()){
        left()->erase(left_tree, data);
    }else if(data > retrieve()){
        right()->erase(right_tree, data);
    }else{     //data found
        if(is_leaf()){  //data is at leaf assign NULL to parent
            BinarySearchNode* tmp = ptr;
            ptr = NULL;
            delete tmp;
        }else if(hasOnlyOneChild()){  //
            BinarySearchNode* tmp = ptr;
            if(tmp->right() != 0){
                ptr = tmp->right();
            }else{
                ptr = tmp->left();
            }
            delete tmp;
        }else{ //data node has 2 child nodes
            ptr->element = right()->front();
            right()->erase(right_tree, ptr->element);
            // right()->erase(ptr, ptr->element);   //here reference to different address -> figure out why :D
            /*
                pass ptr is passing itself
            */
        }
    }
}


void BinarySearchNode::clear(){
    if(!empty()){
        left()->clear();
        right()->clear();
        delete this;
    }
}

//PRINT TREE//

void BinarySearchNode::preOrderPrint(){
    if(!empty()){
        cout << retrieve() << ' ';
        left()->preOrderPrint();
        right()->preOrderPrint();
    }
}

void BinarySearchNode::inOrderPrint(){
    if(!empty()){
        left()->inOrderPrint();
        cout << retrieve() << ' ';
        right()->inOrderPrint();
    }
}

void BinarySearchNode::postOrderPrint(){
    if(!empty()){
        left()->postOrderPrint();
        right()->postOrderPrint();
        cout << retrieve() << ' ';
    }
}

void BinarySearchNode::breadthFirstPrint(){
    if(!empty()){
        Queue<BinarySearchNode *> Q;
        Q.enqueue(this);
        while(!Q.empty()){
            BinarySearchNode* tmp = Q.dequeue();
            cout << tmp->retrieve() << ' ';
            if(tmp->left() != 0)
                Q.enqueue(tmp->left());
            if(tmp->right() != 0)
                Q.enqueue(tmp->right());
        }
    }
    cout << endl;
}

#endif