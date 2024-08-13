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

    template<typename T>
    void forward_list<T>::swap(forward_list& other) noexcept
    {
      Node* tmp = head;
      head = other.head;
      other.head = tmp;
    }

   template<typename T>
   void forward_list<T>::merge(forward_list& other)
   {
    if (!head) 
    {
        head = other.head; 
        other.head = nullptr;
        return;
    }

    Node* tmp = head;
    Node* other_tmp = other.head;

    if (tmp->data > other_tmp->data) 
    {
        std::swap(tmp, other_tmp);
        std::swap(head, other.head);
    }

    while (tmp->next && other_tmp) 
    {
        if (tmp->next->data > other_tmp->data) 
        {
            Node* next_other = other_tmp->next;
            other_tmp->next = tmp->next;
            tmp->next = other_tmp;
            other_tmp = next_other;
        }
        tmp = tmp->next;
    }

    if (other_tmp) {
        tmp->next = other_tmp; 
    }

    other.head = nullptr; 
   }
    
    template<typename T>
    void forward_list<T>::merge(forward_list&& other)
    {
        this->merge(other);
    }

    template<typename T>
    void forward_list<T>::reverse() noexcept
    {
      Node* prev = nullptr;
      Node* current = head;
      Node* next = nullptr;

      while (current != nullptr) 
      {
        next = current->next;  
        current->next = prev;   
        prev = current;         
        current = next;         
      }
    
      head = prev; 
    }

    template<typename T>
    typename forward_list<T>::size_type forward_list<T>::unique()
    {
    if (!head) return 0; 

    Node* current = head;
    size_type removed_count = 0;

    while (current->next != nullptr) 
    {
        if (current->data == current->next->data) 
        {
            Node* duplicate = current->next;
            current->next = current->next->next; 
            delete duplicate; 
            ++removed_count;
        } else 
        {
            current = current->next; 
        }
    }

    return removed_count; 
  }

    template<typename T>
    void forward_list<T>::sort() 
    {
    if (!head || !head->next) return;

    Node* sorted = nullptr;

    while (head) {
        Node* node = head;
        head = head->next;

        if (!sorted || sorted->data >= node->data) 
        {
            node->next = sorted;
            sorted = node;
        } else 
        {
            Node* current = sorted;
            while (current->next && current->next->data < node->data) 
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    head = sorted;
}

}
