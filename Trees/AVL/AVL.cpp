#include "AVL.h"

void AVL::insert(int value)
{
   root = p_insert(root, value); 
}



void AVL::Delete(int value)
{
}

bool AVL::search(int value)
{
return true;
}

int AVL::getBalance(TreeNode* node)
{
    return node?getHeight(node->left) - getHeight(node->right):0;
}

AVL::TreeNode* AVL::rotateLeft(TreeNode* node)
{
    TreeNode* y = node->right;
    TreeNode* tmp = y->left;

    y->left = node;
    node->right = tmp;

    node->m_height = std::max(getHeight(node->left),getHeight(node->right))+1;
    y->m_height = std::max(getHeight(y->left),getHeight(y->right))+1;

    return y;
}   

AVL::TreeNode* AVL::rotateRight(TreeNode* node)
{
    TreeNode* x = node->left;
    TreeNode* tmp = x->right;

    x->right = node;
    node->left = tmp;
    
    node->m_height = std::max(getHeight(node->left),getHeight(node->right))+1;
    x->m_height = std::max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}

int AVL::getHeight(TreeNode* node)
{
    return node==nullptr?0:node->m_height;
}

void AVL::inOrderTraversal()
{
   inOrderTraversal(root);
}

//private

AVL::TreeNode* AVL::p_insert(TreeNode* node, int value)
{
    if (!node)  
    {
        return new TreeNode(value);
    }

    if (value > node->m_val)
    {
        node->right = p_insert(node->right, value);
    }
    else if (value < node->m_val)
    {
        node->left = p_insert(node->left, value);
    }
    else
    {
        return node; 
    }

    node->m_height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->m_val)
    {
        return rotateRight(node);
    }

    if (balance < -1 && value > node->right->m_val)
    {
        return rotateLeft(node);
    }

    if (balance > 1 && value > node->left->m_val)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && value < node->right->m_val) 
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}


void AVL::inOrderTraversal(TreeNode* node)
{
    if (!node)
    {
        return;
    }
    inOrderTraversal(node->left);
    std::cout << node->m_val << " ";  
    inOrderTraversal(node->right);
}

