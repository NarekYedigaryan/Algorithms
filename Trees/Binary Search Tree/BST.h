#ifndef BST_H
#define BST_H
#include <iostream>

class TreeNode
{
public:
  TreeNode* left;
  TreeNode* right;
  int data;
  TreeNode(int val)
  :data(val)
  ,left(nullptr)
  ,right(nullptr)
  {}
};

class BST
{
public:
   BST();
   ~BST();
public:
   bool isEmpty();
   int _getRootData();

public:
   void iterative_add(int val);
//    void iterative_setRootData(int newData);
//    void iterative_clear();
//    void iterative_preorderTraverse();
//    void iterative_inorderTraverse();
//    void recursive_postorderTraverse();
//    int iterative_getEntry(int anEntry);
//    int iterative_getHeight();
//    int iterative_getNumberOfNodes();
//    bool iterative_contains(int data);
public:
   void recursive_add(int val);
   void recursive_setRootData(int newData);
   void recursive_clear();
   void recursive_preorderTraverse();
   void recursive_inorderTraverse();
   void recursive_postorderTraverse();
//    int recursive_getEntry(int anEntry);
   int recursive_getHeight();
   int recursive_getNumberOfNodes();
   bool recursive_contains(int data);
private:
   void _add(TreeNode*& node,int val);
   void _setRootData(TreeNode* node,int newData);
   void _clear(TreeNode* node);
   void _preorderTraverse(TreeNode* node);
   void _inorderTraverse(TreeNode* node);
   void _postorderTraverse(TreeNode* node);
//    int _getEntry(TreeNode* node,int anEntry);
   int _getHeight(TreeNode* node);
   int _getNumberOfNodes(TreeNode* node);
   bool _contains(TreeNode* node,int val);
private:
   TreeNode* root; 

};


#endif