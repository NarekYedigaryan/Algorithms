#ifndef AVL_H
#define AVL_H
#include <iostream>

class AVL
{
private:
    struct TreeNode
    {
        int m_val;
        int m_height;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val):m_val(val),m_height(1),left(),right(){}
    };
private:
    TreeNode* root;
public:
    AVL():root(nullptr){}//why
    void insert(int value) ;//Insert a value into the AVL tree, ensuring the tree remains balanced.
    void Delete(int value) ;// Delete a value from the AVL tree, ensuring the tree remains balanced.
    bool search(int value) ;// Search for a value in the AVL tree and return the node if found.
    int getBalance(TreeNode* node) ;//Calculate and return the balance factor of a node. The balance factor is the difference in height between the left and right subtrees.
    TreeNode* rotateLeft(TreeNode* node) ;// Perform a left rotation on the subtree rooted at the given node to maintain balance.
    TreeNode* rotateRight(TreeNode* node) ;// Perform a right rotation on the subtree rooted at the given node to maintain balance.
    int getHeight(TreeNode* node) ;//Return the height of the given node.
    void inOrderTraversal() ;// Perform an in-order traversal of the tree, printing the values in ascending order.
private:
    TreeNode* p_insert(TreeNode* node,int value) ;//Insert a value into the AVL tree, ensuring the tree remains balanced.
    void inOrderTraversal(TreeNode* node);
};
#endif