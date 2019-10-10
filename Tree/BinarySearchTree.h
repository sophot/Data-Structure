#ifndef BST_H
#define BST_H

#include "BinarySearchNode.h"

class BinarySearchTree{
private:
    BinarySearchNode* root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool empty() const;  
    int front() const;  
    int back() const;  
    int size() const;  
    int height() const;  
    bool find(const int&) const;
    void insert(const int&);
    void erase(const int&);

        //PRINT TREE//
    void preOrderPrint();
    void inOrderPrint();
    void postOrderPrint();
    void breadthFirstPrint();
};


BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    root->clear();
}


bool BinarySearchTree::empty() const{
    return root->empty();
}


int BinarySearchTree::front() const{
    return root->front();
}


int BinarySearchTree::back() const{
    return root->back();
}


int BinarySearchTree::size() const{
    return root->size();
}


int BinarySearchTree::height() const{
    return root->height();
}


bool BinarySearchTree::find(const int& data) const{
    return root->find(data);
}


void BinarySearchTree::insert(const int& data){
    root->insert(root, data);
}


void BinarySearchTree::erase(const int& data){
    root->erase(root, data);
}

//PRINT TREE//
void BinarySearchTree::preOrderPrint(){
    root->preOrderPrint();
}

void BinarySearchTree::inOrderPrint(){
    root->inOrderPrint();
}

void BinarySearchTree::postOrderPrint(){
    root->postOrderPrint();
}

void BinarySearchTree::breadthFirstPrint(){
    root->breadthFirstPrint();
}


#endif