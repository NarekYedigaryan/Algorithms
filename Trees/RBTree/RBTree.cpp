#include "RBTree.h"



//Private functions
void RBTree::leftRotate(TreeNode* x)
{
        TreeNode* y = x->right;
        x->right = y->left;
        if(y->left != nil)
        {
            y->left->parent = x;
        }
        if(x->parent == nil)
        {
            root = y;
        }
        else if(x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;

}

void RBTree::rightRotate(TreeNode* x)
{
    TreeNode* y = x->left;
    x->left = y->right;
    if(y->right != nil)
    {
        y->right->parent = x;
    }
    if(x->parent == nil)
    {
        root = y;
    }
    else if(x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->left = x;
    x->parent = y;
}


void RBTree::insertFixup(TreeNode* newNode) {
    while (newNode->parent->color == Red) {
        if (newNode->parent == newNode->parent->parent->left) {
            TreeNode* uncle = newNode->parent->parent->right; 

            if (uncle->color == Red) {
                newNode->parent->color = Black;           
                uncle->color = Black;                    
                newNode->parent->parent->color = Red;     
                newNode = newNode->parent->parent;        
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;            
                    leftRotate(newNode);                  
                }
                newNode->parent->color = Black;           
                newNode->parent->parent->color = Red;     
                rightRotate(newNode->parent->parent);     
            }
        } 
        else {
            TreeNode* uncle = newNode->parent->parent->left; 

            if (uncle->color == Red) {
                newNode->parent->color = Black;           
                uncle->color = Black;                     
                newNode->parent->parent->color = Red;     
                newNode = newNode->parent->parent;       
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;            
                    rightRotate(newNode);                 
                }
                newNode->parent->color = Black;          
                newNode->parent->parent->color = Red;     
                leftRotate(newNode->parent->parent);      
            }
        }
    }
    root->color = Black;  
}


void RBTree::clear(TreeNode* current)
{
    if(current != nil)
    {
        clear(current->left);
        clear(current->right);
        delete current;
    }
}

//Public functions
RBTree::RBTree():nil(new TreeNode(0)),root(nil)
{
    nil->color=Black;
}

RBTree::~RBTree()
{
    clear(root);
    delete nil;
}

void RBTree::insert(int val) {
    TreeNode* newNode = new TreeNode(val);
    newNode->color = Red;  
    newNode->left = newNode->right = newNode->parent = nil;  
    
    TreeNode* y = nil; 
    TreeNode* x = root; 
    
    while (x != nil) {
        y = x;
        if (newNode->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    newNode->parent = y;
    
    if (y == nil) {
        root = newNode;  
    } else if (newNode->key < y->key) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }

    insertFixup(newNode);
}
