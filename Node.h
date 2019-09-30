#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>

using namespace std;

template<typename NODETYPE> class List;

template<typename NODETYPE>
    class Node{
        private:
            Node<NODETYPE>* next;
            NODETYPE data;

        public:
            friend class List<NODETYPE>;
            
            Node(NODETYPE _data):  data(_data), next(NULL){}

            NODETYPE getData() const {
                return data;
            }

            Node<NODETYPE>* getNext(){
                return next;
            }

            void setNext(Node<NODETYPE>* n){
                next = n;
            }
    };


#endif