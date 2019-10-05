#ifndef SIMPLETREE_H
#define SIMPLETREE_H

#include "SLinkedList.h"

template <typename Type>
class Simple_tree {
private:
    Type element;
    Simple_tree<Type> *parent_node;
    SLinkedList<Simple_tree *> children;
public:
    Simple_tree( Type const &, Simple_tree<Type> * = 0 ); //constructor
    ~Simple_tree(); //not yet
    Type getData() const;
    Simple_tree<Type> *parent() const;
    int degree() const; //tested
    bool is_root() const;
    bool is_leaf() const;

    Simple_tree<Type> *child( int n ) const;//tested
    int height() const; //not yet
    void insert( const Type& ); //tested
    void insert( Simple_tree<Type> * ); //tested
    void detach(); //not yet
}; //End of Interface//


//*****************************************************************//
template <typename Type>
Simple_tree<Type>::Simple_tree( Type const &obj, Simple_tree<Type> *p ):
    element( obj ), parent_node( p ) {}

template<typename Type>
Simple_tree<Type>::~Simple_tree(){
    
}

template <typename Type>
Type Simple_tree<Type>::getData() const {
    return element;
}

template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::parent() const{
    return parent_node;
}

template <typename Type>
int Simple_tree<Type>::degree() const{
    // int count = 0;
    // for(Node<Simple_tree<Type>* >* tmp = children.getHead(); tmp != NULL; tmp = tmp->getNext()){
    //     count++;
    // }
    // return count;
    return children.size();
}

template <typename Type>
bool Simple_tree<Type>::is_root() const{
    return (parent_node == NULL);
}

template <typename Type>
bool Simple_tree<Type>::is_leaf() const{
    return children.isEmpty();
}

template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::child(int n) const{
    if(n < 0 || n >= children.size()){
        return NULL;
    }

    Node<Simple_tree<Type> *> *tmp = children.getHead();
    for(int i = 0; i < n; i++){
        tmp = tmp->getNext();
    }

    return tmp->getData();
}

template <typename Type>
int Simple_tree<Type>::height() const{
    int h = 0;

    for(Node<Simple_tree *> *tmp = children.getHead(); tmp != 0; tmp = tmp->getNext()){
        h = max(h, 1 + tmp->getData()->height());
    }

    return h;
}

template <typename Type>
void Simple_tree<Type>::insert(const Type& num){
    this->children.addBack(new Simple_tree(num, this));
}

template <typename Type>
void Simple_tree<Type>::insert(Simple_tree<Type>* st){
    this->children.addBack(st);
    st->parent_node = this;
}

template <typename Type>
void Simple_tree<Type>::detach(){
    parent()->children.remove(this);
    this->parent_node = NULL;
}

#endif