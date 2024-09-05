#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
#include <stack>
class TreeNode
{
public:
  TreeNode* left;
  TreeNode* right;
  int data;
  TreeNode()
  :data()
  ,left(nullptr)
  ,right(nullptr)
  {}
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
   void _setRootData(int newData);


public:
   void iterative_add(int val);
   void iterative_clear();
   void iterative_preorderTraverse();
   void iterative_inorderTraverse();
   void iterative_postorderTraverse();
   int iterative_getHeight();
   int iterative_getNumberOfNodes();
   bool iterative_contains(int data);
public:
   void recursive_add(int val);
   void recursive_clear();
   void recursive_preorderTraverse();
   void recursive_inorderTraverse();
   void recursive_postorderTraverse();
   int recursive_getHeight();
   int recursive_getNumberOfNodes();
   bool recursive_contains(int data);
private:
   void _add(TreeNode*& node,int val);
   void _clear(TreeNode* node);
   void _preorderTraverse(TreeNode* node);
   void _inorderTraverse(TreeNode* node);
   void _postorderTraverse(TreeNode* node);
   int _getHeight(TreeNode* node);
   int _getNumberOfNodes(TreeNode* node);
   bool _contains(TreeNode* node,int val);
private:
   TreeNode* root; 

};


#endif