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
    TreeNode* current = root;

    while (true)
    {
        if(current->data < val)
        {
            if(current->right == nullptr)
            {
                current->right = new TreeNode(val);
                return;
            } 
            current = current->right;
        }
        else if(current->data > val)
        {
            if(current->left == nullptr)
            {
                current->left = new TreeNode(val);
                return;
            } 
            current = current->left;
        }
        else
        {
            return;
        }
    }
    
}

void BST::iterative_clear() 
{
    if (root == nullptr) 
    {
        return;
    }

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* node = s.top();
        s.pop();
        if(node->left)
        {
            s.push(node->left);
        }
        if(node->right)
        {
            s.push(node->right);
        }
        delete node;
    }
    root = nullptr;  
}

void BST::iterative_preorderTraverse()
{
    if(root == nullptr)
    {
        return;
    }
    TreeNode* node = root;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        node = s.top();
        s.pop();
        
        if(node->right)
        {
          s.push(node->right);
        }
        if(node->left)
        {
          s.push(node->left);
        }
        std::cout<<node->data<<" ";
    }
}

void BST::iterative_inorderTraverse() 
{
        if (root == nullptr) 
        {
            return;
        }

        std::stack<TreeNode*> s;
        TreeNode* node = root;

        while (node != nullptr || !s.empty()) 
        {
            while (node != nullptr) 
            {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            std::cout << node->data << " ";

            node = node->right;
        }
}

void BST::iterative_postorderTraverse() 
{
        if (root == nullptr) 
        {
            return;
        }

        std::stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) 
        {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left) 
            {
                s1.push(node->left);
            }
            if (node->right) 
            {
                s1.push(node->right);
            }
        }

        while (!s2.empty()) 
        {
            TreeNode* node = s2.top();
            s2.pop();
            std::cout << node->data << " ";
        }
    }

int BST::iterative_getHeight()
{
    int height = 0;

    if(root == nullptr)
    {
        return height;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int level = q.size();
        ++height;
        for (size_t i = 0; i < level; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left )
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
    return height;
}

int BST::iterative_getNumberOfNodes()
{
    if(root == nullptr)
    {
        return 0;
    }
    int count = 0;
    std::stack<TreeNode*> s;
    TreeNode* node = root;
    s.push(root);
    while(!s.empty())
    {
        ++count;
        node = s.top();
        s.pop();
        if(node->left)
        {
            s.push(node->left);
        }
        if(node->right)
        {
            s.push(node->right);
        }
    }
    return count;
}

bool BST::iterative_contains(int data)
{
    if(root == nullptr)
    {
        return false;
    }
    TreeNode* node = root;
    while(node != nullptr)
    {
        if(node->data == data)
        {
            return true;
        }
        if(node->data > data)
        {
            node = node->left;
        }
        else if(node->data < data)
        {
            node = node->right;
        }
    }
    return false;
}

//public recursive functions
void BST::recursive_add(int val)
{
    _add(root,val);
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

void BST::_setRootData( int newData)
{
    if (root != nullptr)
    {
        root->data = newData;
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


