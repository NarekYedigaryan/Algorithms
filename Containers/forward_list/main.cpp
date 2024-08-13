#include "./forward_list.h"


  int main()
  {
    Nar::forward_list<int> lst={1,3,5,7,9};
    Nar::forward_list<int> lst1={2,4,6,8,10,11,12};

    // lst.print();
    // std::cout<<lst.front();
    // std::cout<<lst.empty();
    // lst.push_front(7);
    // lst.pop_front();
    // lst.push_back(10);
    // lst.swap(lst1);
    lst.merge(lst1);
    lst.print();

  }

