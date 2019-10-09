#ifndef BST_H
#define BST_H

#include <iostream>
#include <algorithm>
#include "../Queue.h"

using namespace std;

template <typename Type> 
class BinarySearchTree {
    private:
        Type element;
        BinarySearchTree<Type> *left_tree;
        BinarySearchTree<Type> *right_tree;
        bool hasOnlyOneChild() const;
    public:
        BinarySearchTree( Type const & );
        Type retrieve() const;  
        BinarySearchTree<Type> *left() const;  
        BinarySearchTree<Type> *right() const;  
        bool empty() const;  
        bool is_leaf() const;  
        Type front() const;  
        Type back() const;  
        int size() const;  
        int height() const;  
        bool find(const Type&) const;
        void insert(BinarySearchTree*&, Type const&);
        void erase(BinarySearchTree*& , Type const&);
        void clear();
        //PRINT TREE//
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();
        void breadthFirstPrint();
};

template<typename Type>
bool BinarySearchTree<Type>::hasOnlyOneChild() const{
    return ((left()==0 && right() != 0) || (left()!=0 && right()==0));
}

template<typename Type>
BinarySearchTree<Type>::BinarySearchTree(Type const& data){
    element = data;
    left_tree = NULL;
    right_tree = NULL;
}

template<typename Type>
Type BinarySearchTree<Type>::retrieve() const{
    return element;
}

template<typename Type>
BinarySearchTree<Type>* BinarySearchTree<Type>::left() const{
    return left_tree;
}

template<typename Type>
BinarySearchTree<Type>* BinarySearchTree<Type>::right() const{
    return right_tree;
}

template<typename Type>
bool BinarySearchTree<Type>::empty() const{
    return this == 0;
}

template<typename Type>
bool BinarySearchTree<Type>::is_leaf() const{
    return ((left() == NULL) && (right() == NULL));
}

template<typename Type>
Type BinarySearchTree<Type>::front() const{
        if(left() == 0){
            return retrieve();
        }else{
            return left()->front();
        }
}

template<typename Type>
Type BinarySearchTree<Type>::back() const{
    if(right() == 0){
        return retrieve();
    }else{
        return right()->back();
    }
}

template<typename Type>
int BinarySearchTree<Type>::size() const{
    if(!empty()){
        return 1 + left()->size() + right()->size();
    }
    return 0;
}

template<typename Type>
int BinarySearchTree<Type>::height() const{
    if(!empty()){
        return 1 + std::max(left()->height(), right()->height());
    }
    return -1;
}

template<typename Type>
bool BinarySearchTree<Type>::find(const Type& data) const{
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
void BinarySearchTree<Type>::insert(BinarySearchTree *&ptr, Type const& data){
    if(ptr == NULL){
        ptr = new BinarySearchTree(data);
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
            left_tree = new BinarySearchTree<Type>(data);
        }else if (data > retrieve()){
            right_tree = new BinarySearchTree<Type>(data);
        }
    }else{
        (data < retrieve())? left()->insert(data): right()->insert(data);
    }
*/
}

template<typename Type>
void BinarySearchTree<Type>::erase(BinarySearchTree*& ptr, Type const& data){
    if(ptr == NULL){
        return;     //data is not in the tree
    }
    if(data < retrieve()){
        left()->erase(left_tree, data);
    }else if(data > retrieve()){
        right()->erase(right_tree, data);
    }else{     //data found
        if(is_leaf()){  //data is at leaf assign NULL to parent
            BinarySearchTree<Type>* tmp = ptr;
            ptr = NULL;
            delete tmp;
        }else if(hasOnlyOneChild()){  //
            BinarySearchTree<Type>* tmp = ptr;
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
void BinarySearchTree<Type>::clear(){
    if(!empty()){
        left()->clear();
        right()->clear();
        delete this;
    }
}
//PRINT TREE//
template<typename Type>
void BinarySearchTree<Type>::preOrderPrint(){
    if(!empty()){
        cout << retrieve() << ' ';
        left()->preOrderPrint();
        right()->preOrderPrint();
    }
}
template<typename Type>
void BinarySearchTree<Type>::inOrderPrint(){
    if(!empty()){
        left()->inOrderPrint();
        cout << retrieve() << ' ';
        right()->inOrderPrint();
    }
}
template<typename Type>
void BinarySearchTree<Type>::postOrderPrint(){
    if(!empty()){
        left()->postOrderPrint();
        right()->postOrderPrint();
        cout << retrieve() << ' ';
    }
}
template<typename Type>
void BinarySearchTree<Type>::breadthFirstPrint(){
    if(!empty()){
        Queue<BinarySearchTree<Type> *> Q;
        Q.enqueue(this);
        while(!Q.empty()){
            BinarySearchTree<Type>* tmp = Q.dequeue();
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