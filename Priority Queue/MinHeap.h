#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <math.h>

using namespace std;

class CompleteTree{
private:
    const int HEAPSIZE = 100;
    int* arr = new int[HEAPSIZE];
    int size = 0;

    void swap(int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
public:
    CompleteTree(){
        for(int i = 0; i < HEAPSIZE; i++){
            arr[i] = 0;
        }
    }

    int height() const{
        //nodes = 2^(h+1) - 1
        // h = log(nodes + 1) - 1
        /* 
            calculate height by dividing last element by 2 (to find parent)
            until reaching the root (s = 1)
        */
        int h = 0;
        int s = size;
        while(s > 1){
            h++;
            s = s/2;
        }
        return h;
    }

    void push(int _data){
        // size++;
        arr[++size] = _data;
        int child = size;
        int tmp, parent;
        while(child > 1){
            parent = child/2;
            if(arr[child] < arr[parent]){  //if smaller than parent
                swap(child, parent);
            }else{  //child is bigger than parent -> heap is maintained
                break;
            }
            child/=2;
        }
    }

    int pop(){
        int parent = 1;
        int child1, child2;
        int ret = arr[1];

        arr[1] = arr[size--]; //copy last element to top
        

        while(parent*2 <= size){
            child1 = parent*2;
            child2 = child1 + 1;
            

            if(arr[child1] < arr[child2]){     //left < right
                if(arr[child1] < arr[parent]){  //when left is smallest -> swap
                    swap(child1, parent);
                    parent = child1;
                }else{      //parent is smallest -> do nth
                    break;
                }
            }else{                              // right < left
                if(arr[child2] < arr[parent]){  //when right is smallest -> swap
                    swap(child2, parent);
                    parent = child2;
                }else{      //parent is smallest -> do nth
                    break;
                }
            }
        }

        return ret;
    }

    int top() const{
        return arr[1];
    }

    void print() const{
        for(int i = 1; i <= size; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    // void printTree() const{
    //     int h = height();
    //     for(int i = h; i > 0; i--){
    //         for(int j = 0; j < pow(2, i); j++){
    //             cout << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
};

#endif