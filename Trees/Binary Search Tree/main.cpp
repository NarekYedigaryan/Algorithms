#include "BST.h"

int main()
{
    BST obj;
    obj.recursive_add(10);
    obj.recursive_add(7);
    obj.recursive_add(20);
    obj.recursive_add(5);
    obj.recursive_add(9);
    obj.recursive_add(14);
    obj.recursive_add(25);
    
    // obj.recursive_inorderTraverse();
    // obj.recursive_preorderTraverse();
    // obj.recursive_postorderTraverse();
    // std::cout<<obj.recursive_getHeight();
    // std::cout<<obj.recursive_getNumberOfNodes();
    // std::cout<<obj._getRootData();
    // std::cout<<obj.recursive_contains(111);
    // obj.recursive_setRootData(4);
    // obj.recursive_inorderTraverse();
    // std::cout<<obj.isEmpty();
    
    BST obj2;
    obj2.iterative_add(10);
    obj2.iterative_add(6);
    obj2.iterative_add(12);
    obj2.iterative_add(4);
    obj2.iterative_add(9);
    obj2.iterative_add(11);
    obj2.iterative_add(15);
    // obj2.iterative_clear();

    // std::cout<<obj2.iterative_getHeight();
    // obj2.recursive_inorderTraverse();
    // obj2.iterative_preorderTraverse();
    // obj2.iterative_inorderTraverse();
    // std::cout<<obj2.iterative_getNumberOfNodes();
    std::cout<<obj2.iterative_contains(77);
}