#ifndef SIMPLETREE_H
#define SIMPLETREE_H

#include "SLinkedList.h"

template <typename Type>
class Simple_tree {
private:
    Type element;
    Simple_tree *parent_node;
    SLinkedList<Simple_tree *> children;
public:
    Simple_tree( Type const &, Simple_tree * = 0 ); //constructor
    Type retrieve() const;
    Simple_tree *parent() const;
    int degree() const;
    bool is_root() const;
    bool is_leaf() const;

    Simple_tree *child( int n ) const;
    int height() const;
    void insert( Type const & );
    void insert( Simple_tree * );
    void detach();
};

template <typename Type>
Simple_tree<Type>::Simple_tree( Type const &obj, Simple_tree *p ):
    element( obj ), parent_node( p ) {  /* Empty constructor */ }

template <typename Type>
Type Simple_tree<Type>::retrieve() const {
    return element;
}

template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::parent() const{
    return parent_node;
}

template <typename Type>
int Simple_tree<Type>::degree() const{
    
}

template <typename Type>
bool Simple_tree<Type>::is_root() const{

}

template <typename Type>
bool Simple_tree<Type>::is_leaf() const{

}

template <typename Type>
Simple_tree<Type>* Simple_tree<Type>::child(int n) const{

}

template <typename Type>
int Simple_tree<Type>::height() const{

}

template <typename Type>
void Simple_tree<Type>::insert(Type const& num){

}

template <typename Type>
void Simple_tree<Type>::insert(Simple_tree<Type>* st){

}

template <typename Type>
void Simple_tree<Type>::detach(){

}

#endif