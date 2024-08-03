#include "BST.h"
#include <exception>
//public
BST::BST():root(nullptr){}

BST::~BST()
{
  recursive_clear();
}

//public
bool BST::isEmpty()
{
    return root == nullptr;
}

int BST::_getRootData()
{
    if(!root)
    {
        throw std::exception();
    }
    return root->data;
}

//public iterative functions

void BST::iterative_add(int val)
{
    if(root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode* tmp = root;
    while(tmp->left && tmp->right)
    {
       if(tmp->data > val)
       {
         tmp = tmp->left;
       }
       else if(tmp->data < val)
       {
         tmp = tmp->right;
       }
       else
       {
          return;
       }
    }
    tmp = new TreeNode(val);

}



//public recursive functions
void BST::recursive_add(int val)
{
    _add(root,val);
}

void BST::recursive_setRootData(int newData)
{
    _setRootData(root,newData);
}

void BST::recursive_clear()
{
    _clear(root);
    root = nullptr; 
}

void BST::recursive_preorderTraverse()
{
    _preorderTraverse(root);
}

void BST::recursive_inorderTraverse()
{
    _inorderTraverse(root);
}

void BST::recursive_postorderTraverse()
{
     _postorderTraverse(root);
}

int BST::recursive_getHeight()
{
   return _getHeight(root);
}

int BST::recursive_getNumberOfNodes()
{
    return _getNumberOfNodes(root);
}

bool BST::recursive_contains(int data)
{
    return _contains(root,data);
}

//private recursive functions
void BST::_add(TreeNode*& node, int val) 
{
    if (node == nullptr) 
    {
        node = new TreeNode(val); 
    } 
    else if (val < node->data) 
    {
        _add(node->left, val); 
    } 
        else if (val > node->data) 
    {
        _add(node->right, val);  
    }
}

void BST::_setRootData(TreeNode* node, int newData)
{
    if (node != nullptr)
    {
        node->data = newData;
    }
}



void BST::_clear(TreeNode* node)
{
   if(node == nullptr)
   {
     return;
   }
     _clear(node->left);
     _clear(node->right);
     delete node;

}


void BST::_preorderTraverse(TreeNode* node)
{
     if (node == nullptr) 
    {
        return;
    }
    std::cout << node->data << " ";
    _inorderTraverse(node->left);
    _inorderTraverse(node->right);
}

void BST::_inorderTraverse(TreeNode* node)
{
    if (node == nullptr) 
    {
        return;
    }
    _inorderTraverse(node->left);
    std::cout << node->data << " ";
    _inorderTraverse(node->right);
}

void BST::_postorderTraverse(TreeNode* node)
{
    if (node == nullptr) 
    {
        return;
    }
    _postorderTraverse(node->left);
    _postorderTraverse(node->right);
    std::cout << node->data << " ";
}

int BST::_getHeight(TreeNode* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    else 
    {
        int leftHeight = _getHeight(node->left);
        int rightHeight = _getHeight(node->right);
        return 1+std::max(leftHeight,rightHeight);
    }
}

int BST::_getNumberOfNodes(TreeNode* node)
{
    if(node == nullptr)
    {
        return 0 ;
    }
    return _getNumberOfNodes(node->left) + _getNumberOfNodes(node->right) + 1;

}

bool BST::_contains(TreeNode* node,int val)
{
    if(!node)
    {
        return false;
    }
    if(val == node->data)
    {
        return true;
    }
    return _contains(node->left,val) || _contains(node->right,val);

}


