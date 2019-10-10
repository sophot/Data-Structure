#ifndef BST_H
#define BST_H

#include "BinarySearchNode.h"

template<typename Type>
class BinarySearchTree{
private:
    BinarySearchNode<Type>* root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool empty() const;  
    Type front() const;  
    Type back() const;  
    int size() const;  
    int height() const;  
    bool find(const Type&) const;
    void insert(const Type&);
    void erase(const Type&);

        //PRINT TREE//
    void preOrderPrint();
    void inOrderPrint();
    void postOrderPrint();
    void breadthFirstPrint();
};

template<typename Type>
BinarySearchTree<Type>::BinarySearchTree(){
    root = NULL;
}

template<typename Type>
BinarySearchTree<Type>::~BinarySearchTree(){
    root->clear();
    cout << "CLEARED!!!" << endl;
}

template<typename Type>
bool BinarySearchTree<Type>::empty() const{
    return root->empty();
}

template<typename Type>
Type BinarySearchTree<Type>::front() const{
    return root->front();
}

template<typename Type>
Type BinarySearchTree<Type>::back() const{
    return root->back();
}

template<typename Type>
int BinarySearchTree<Type>::size() const{
    return root->size();
}

template<typename Type>
int BinarySearchTree<Type>::height() const{
    return root->height();
}

template<typename Type>
bool BinarySearchTree<Type>::find(const Type& data) const{
    return root->find(data);
}

template<typename Type>
void BinarySearchTree<Type>::insert(const Type& data){
    root->insert(root, data);
}

template<typename Type>
void BinarySearchTree<Type>::erase(const Type& data){
    root->erase(root, data);
}

//PRINT TREE//
template<typename Type>
void BinarySearchTree<Type>::preOrderPrint(){
    root->preOrderPrint();
}
template<typename Type>
void BinarySearchTree<Type>::inOrderPrint(){
    root->inOrderPrint();
}
template<typename Type>
void BinarySearchTree<Type>::postOrderPrint(){
    root->postOrderPrint();
}
template<typename Type>
void BinarySearchTree<Type>::breadthFirstPrint(){
    root->breadthFirstPrint();
}


#endif