
#include "BinarySearchTree.h"

int main(){

    BinarySearchTree *bst = new BinarySearchTree();
    bst->insert(45);
    bst->insert(36);
    bst->insert(14);
    bst->insert(52);
    bst->insert(42);
    bst->insert(6);
    bst->insert(21);
    bst->insert(73);
    bst->insert(47);
    bst->insert(26);
    bst->insert(37);
    bst->insert(33);
    bst->insert(8);

    bst->inOrderPrint();
    cout << endl;
    
    // bst->erase(bst, 14);
    
    bst->breadthFirstPrint();

    return 0;
}