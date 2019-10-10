#ifndef BSN_H
#define BSN_H

#include <iostream>
#include <algorithm>
#include "../Queue.h"

using namespace std;

template <typename Type> 
class BinarySearchNode {
    private:
        Type element;
        BinarySearchNode<Type> *left_tree;
        BinarySearchNode<Type> *right_tree;
        bool hasOnlyOneChild() const;
    public:
        BinarySearchNode( const Type& );
        Type retrieve() const;  
        BinarySearchNode<Type> *left() const;  
        BinarySearchNode<Type> *right() const;  
        bool empty() const;  
        bool is_leaf() const;  
        Type front() const;  
        Type back() const;  
        int size() const;  
        int height() const;  
        bool find(const Type&) const;
        void insert(BinarySearchNode*&, const Type&);
        void erase(BinarySearchNode*& , const Type&);
        void clear();
            //PRINT TREE//
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();
        void breadthFirstPrint();
};

template<typename Type>
bool BinarySearchNode<Type>::hasOnlyOneChild() const{
    return ((left()==0 && right() != 0) || (left()!=0 && right()==0));
}

template<typename Type>
BinarySearchNode<Type>::BinarySearchNode(const Type& data){
    element = data;
    left_tree = NULL;
    right_tree = NULL;
}

template<typename Type>
Type BinarySearchNode<Type>::retrieve() const{
    return element;
}

template<typename Type>
BinarySearchNode<Type>* BinarySearchNode<Type>::left() const{
    return left_tree;
}

template<typename Type>
BinarySearchNode<Type>* BinarySearchNode<Type>::right() const{
    return right_tree;
}

template<typename Type>
bool BinarySearchNode<Type>::empty() const{
    return this == 0;
}

template<typename Type>
bool BinarySearchNode<Type>::is_leaf() const{
    return ((left() == NULL) && (right() == NULL));
}

template<typename Type>
Type BinarySearchNode<Type>::front() const{
        if(left() == 0){
            return retrieve();
        }else{
            return left()->front();
        }
}

template<typename Type>
Type BinarySearchNode<Type>::back() const{
    if(right() == 0){
        return retrieve();
    }else{
        return right()->back();
    }
}

template<typename Type>
int BinarySearchNode<Type>::size() const{
    if(!empty()){
        return 1 + left()->size() + right()->size();
    }
    return 0;
}

template<typename Type>
int BinarySearchNode<Type>::height() const{
    if(!empty()){
        return 1 + std::max(left()->height(), right()->height());
    }
    return -1;
}

template<typename Type>
bool BinarySearchNode<Type>::find(const Type& data) const{
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

template<typename Type>
void BinarySearchNode<Type>::insert(BinarySearchNode *&ptr, const Type& data){
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
            left_tree = new BinarySearchNode<Type>(data);
        }else if (data > retrieve()){
            right_tree = new BinarySearchNode<Type>(data);
        }
    }else{
        (data < retrieve())? left()->insert(data): right()->insert(data);
    }
*/
}

template<typename Type>
void BinarySearchNode<Type>::erase(BinarySearchNode*& ptr, const Type& data){
    if(ptr == NULL){
        return;     //data is not in the tree
    }
    if(data < retrieve()){
        left()->erase(left_tree, data);
    }else if(data > retrieve()){
        right()->erase(right_tree, data);
    }else{     //data found
        if(is_leaf()){  //data is at leaf assign NULL to parent
            BinarySearchNode<Type>* tmp = ptr;
            ptr = NULL;
            delete tmp;
        }else if(hasOnlyOneChild()){  //
            BinarySearchNode<Type>* tmp = ptr;
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

template<typename Type>
void BinarySearchNode<Type>::clear(){
    if(!empty()){
        left()->clear();
        right()->clear();
        delete this;
    }
}

//PRINT TREE//
template<typename Type>
void BinarySearchNode<Type>::preOrderPrint(){
    if(!empty()){
        cout << retrieve() << ' ';
        left()->preOrderPrint();
        right()->preOrderPrint();
    }
}
template<typename Type>
void BinarySearchNode<Type>::inOrderPrint(){
    if(!empty()){
        left()->inOrderPrint();
        cout << retrieve() << ' ';
        right()->inOrderPrint();
    }
}
template<typename Type>
void BinarySearchNode<Type>::postOrderPrint(){
    if(!empty()){
        left()->postOrderPrint();
        right()->postOrderPrint();
        cout << retrieve() << ' ';
    }
}
template<typename Type>
void BinarySearchNode<Type>::breadthFirstPrint(){
    if(!empty()){
        Queue<BinarySearchNode<Type> *> Q;
        Q.enqueue(this);
        while(!Q.empty()){
            BinarySearchNode<Type>* tmp = Q.dequeue();
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