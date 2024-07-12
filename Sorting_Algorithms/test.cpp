#include <iostream>
#include <functional>
#include <unordered_map>

// int main()
// {
// //  std::function<int(int)> foo = [&foo](int n) -> int
// //  {
// //    if(n == 0)
// //    {
// //     return 1;
// //    }
// //    return n * foo(n-1); 
// //  };
// //  std::cout<<foo(5);
// std::unordered_map<int,int> mp{};
// for (size_t i = 0; i < 6; i++)
// {
//   mp.insert(i+2,i+5);
// }
// for (size_t i = 0; i < mp.size(); i++)
// {
//   std::cout<<mp[i];
// }

// }


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     int& operator<<()
     {
      return next->val;
     } 
  };
 

    void mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode(2);
        std::cout<<ListNode->val;
    }
int main()
{

}