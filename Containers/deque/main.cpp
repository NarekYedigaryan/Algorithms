#include "deque.h"

int main()
{
    Nar::deque<int> dq;
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    dq.push_front(3);
    dq.push_front(2);
    dq.push_front(1);
    dq.push_front(0);
    dq.push_front(-1);

    // dq.pop_front();
    // dq.pop_back();
    // dq.clear();
    // dq.insert(6,7);
    dq.erase(1);
    dq.erase(6);
    for (size_t i = 0; i < dq.size(); i++)
    {
        std::cout<<dq[i]<<" ";
    }
    // std::cout<<dq.front();
    // std::cout<<dq.empty();

    
    

}