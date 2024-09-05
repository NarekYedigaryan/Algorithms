#ifndef DEQUE_H
#define DEQUE_h
#include <iostream>
namespace Nar
{
template<typename T>
class deque
{
public:
    deque();
    ~deque();
public:
    void push_front(const T& val);
    void push_front(T& val);
    void push_back(T& val);
    void push_back(const T& val);
    void pop_front();
    void pop_back();
    T front();
    bool empty();
    std::size_t size();
    void clear();
    T& operator[](std::size_t i);
    void insert(std::size_t i,int val);
    void erase(std::size_t i);
private:
    T* left;
    std::size_t leftSize;
    std::size_t leftCap;
    T* right;
    std::size_t rightSize;
    std::size_t rightCap;
private:
    void resizeLeft();
    void resizeRight();
};

}
#include "deque.hpp"


#endif