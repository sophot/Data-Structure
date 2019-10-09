
#include "BinarySearchTree.h"

int main(){
    
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(31);
    bst->insert(bst, 45);
    bst->insert(bst, 36);
    bst->insert(bst, 14);
    bst->insert(bst, 52);
    bst->insert(bst, 42);
    bst->insert(bst, 6);
    bst->insert(bst, 21);
    bst->insert(bst, 73);
    bst->insert(bst, 47);
    bst->insert(bst, 26);
    bst->insert(bst, 37);
    bst->insert(bst, 33);
    bst->insert(bst, 8);

    bst->inOrderPrint();
    cout << endl;
    
    // bst->erase(bst, 14);
    
    bst->breadthFirstPrint();
    cout << endl;

    return 0;
}