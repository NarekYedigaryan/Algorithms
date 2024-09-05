#include "AVL.h"

int main()
{
    AVL ob;
    ob.insert(50);
    ob.insert(40);
    ob.insert(60);
    ob.insert(100);
    ob.insert(10);
    ob.insert(120);
    ob.insert(4);
    ob.insert(6);

    ob.Delete(1);
   
    // ob.inOrderTraversal();
}
