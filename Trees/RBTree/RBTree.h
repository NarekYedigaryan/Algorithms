#ifndef RBTREE_H
#define RBTREE_H

enum Color{Red,Black};
struct TreeNode
{
    Color color;
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key):key(key),parent(),left(),right(){}
};

class RBTree
{
private:
    TreeNode* root;
    TreeNode* nil;
    void leftRotate(TreeNode* x);
    void rightRotate(TreeNode* current);
    void insertFixup(TreeNode* newNode);
    void deleteFixup(TreeNode* current);
    void transplant(TreeNode* newNode);
    void clear(TreeNode* current);
public:
    RBTree();
    ~RBTree();
    void insert(int val);
    void Delete(int key);//??
};

#endif