#include <iostream>

template<typename T>
class Doubly_List
{
  private:
  struct Node
  {
    Node* next;
    Node* prev;
    T data;
  };
};