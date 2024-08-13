#ifndef F_L
#define F_L

#include <iostream>
#include <initializer_list>

namespace Nar
{
template<typename T>
class forward_list
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

public:
    forward_list();
    forward_list(size_type count, const T& value);
    forward_list(const forward_list& other);
    forward_list(forward_list&& other);
    forward_list(std::initializer_list<T> init);

    forward_list& operator=(const forward_list& other);
    forward_list& operator=(forward_list&& other);
    ~forward_list();

public:
    void print();
    reference front();
    const_reference front() const;
    bool empty() const noexcept;
    void clear() noexcept;
    void insert_after(Node* prev_node, value_type data);
    void erase_after(Node* prev_node);
    void push_front(const value_type& value);
    void push_front(value_type&& value);
    void push_back(const value_type& value);
    void push_back(value_type&& value);
    void pop_front();
    void swap(forward_list& other) noexcept;
    void merge(forward_list& other);
    void merge(forward_list&& other);
    void reverse() noexcept;
    size_type unique();
    void sort();

};

}
#include "./forward_list.hpp"
#endif