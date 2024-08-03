#include "./forward_list.h"

namespace Nar
{
    template<typename T>
    forward_list<T>::forward_list()
    :head(nullptr)
    {}

    template<typename T>
    forward_list<T>::forward_list(size_type count, const T& value)
    :head(nullptr)
    {
       if(count > 0)
       {
         head = new Node(value);
         Node* current = head;
         --count;
         while(count)
         {
           Node* NewNode = new Node(value);
           current->next = NewNode;
           current = NewNode;
           --count;
         }
       }
       
    }

    template<typename T>
    forward_list<T>::forward_list(const forward_list& other)
    :head(nullptr)
    {
      if(other.head)
      {
        head = new Node(other.head->data);
        Node* current = head;
        Node * other_current = other.head->next;
        while (other_current)
        {
            current->next = new Node(other_current->data);
            current = current->next;
            other_current = other_current->next;
        }
        
      }
    }

    template<typename T>
    forward_list<T>::forward_list(forward_list&& other)
    :head(other.head)
    {
        other.head = nullptr;
    }

    template<typename T>
    forward_list<T>::forward_list(std::initializer_list<T> init)
    :head(nullptr)
    {
        for (T i : init)
        {
            push_back(i);
        }
        
    }

    template<typename T>
    forward_list<T>& forward_list<T>::operator=(const forward_list& other)
    {
      if(this != other)
      {
        if(other.head)
        {
          head = new Node(other.head->data);
          Node* current = head;
          Node * other_current = other.head->next;
          while (other_current)
          {
            current->next = new Node(other_current->data);
            current = current->next;
            other_current = other_current->next;
          }
        
        }
        return *this;
      }
    }


    template<typename T>
    forward_list<T>& forward_list<T>::operator=(forward_list&& other)
    {
      if(this != other)
      {
        if(other.head)
        {
          head = other.head;
          other.head = nullptr;
        }
        return *this;
      }
    }


    template<typename T>
    forward_list<T>::~forward_list()
    {
        clear();
    }

    template<typename T>
    void forward_list<T>::print()
    {
      Node* tmp = head;
      while(tmp)
      {
        std::cout<<tmp->data<<" ";
        tmp = tmp->next;
      }
    }

    template<typename T>
    typename forward_list<T>::reference forward_list<T>::front()
    {
        if(head)
        {
            return head->data;
        }
        throw std::out_of_range("No data in container");
    }
     
    template<typename T>
    typename forward_list<T>::const_reference forward_list<T>::front() const 
    {
        if(head)
        {
            return head->data;
        }
        throw std::out_of_range("No data in container");
    }

    template<typename T>
    bool forward_list<T>::empty() const noexcept
    {
        if(!head)
        {
            return true;
        }
        return false;
    }
    
    template<typename T>
    void forward_list<T>::clear() noexcept
    {
       
        while (head)
        {
           Node* tmp = head->next;
           delete head;
           head = tmp;
        }
        
    }

    template<typename T>
    void forward_list<T>::insert_after(Node* prev_node, value_type data)
    {
      if (prev_node == nullptr) 
      {
        throw std::invalid_argument("prev_node cannot be nullptr");
      }
        Node* NewNode = new Node(data);
        NewNode->next = prev_node->next;
        prev_node->next = NewNode;
    }
    
   template<typename T>
    void forward_list<T>::erase_after(Node* prev_node) 
    {
    if (prev_node == nullptr) 
    {
        throw std::invalid_argument("prev_node cannot be nullptr");
    }
    Node* node_to_delete = prev_node->next;
    if (node_to_delete == nullptr) 
    {
        throw std::invalid_argument("There is no node to erase after prev_node");
    }
    prev_node->next = node_to_delete->next;
    delete node_to_delete;
}


    template<typename T>
    void forward_list<T>::push_front(const value_type& value)
    {
        Node* NewNode = new Node(value);
        NewNode->next = head;
        head = NewNode;
    }

    template<typename T>
    void forward_list<T>::push_front(value_type&& value)
    {
        Node* NewNode = new Node(value);
        NewNode->next = head;
        head = NewNode;
    }

   template<typename T>
   void forward_list<T>::push_back(const value_type& value)
   {
     Node* new_node = new Node(value);
     if (!head) 
     {
        head = new_node;
     } 
     else 
     {
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
      }
   }


    template<typename T>
    void forward_list<T>::push_back(value_type&& value)
    {
      Node* new_node = new Node(std::move(value));
      if (!head) 
      {
        head = new_node;
      } 
      else 
      {
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
      }
    }

    template<typename T>
    void forward_list<T>::pop_front()
    {
        if(head)
        {
          Node* tmp = head->next;
          delete head;
          head = head->next;
        }
        
    }




}
