#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

bool duplicates(std::vector<int> vec)
{

  std::map<int,int> mp;

  for (int &num : vec)
  {
    if(++mp[num] >= 2)
    {
      return true;
    }
  }
  
  return false;
}

void bubbleSort(std::vector<int>& vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    for (size_t j = 0; j < vec.size()-1-i; ++j)
    {
      if(vec[j] > vec[j+1])
      {
        std::swap(vec[j],vec[j+1]);
      }
    }
  }
}

void insertionSort(std::vector<int>& vec)
{
  int j = 0;
  for (size_t i = 1; i < vec.size(); ++i)
  {
    j = i;
    while(j > 0 && vec[j-1] > vec[j])
    {
      std::swap(vec[j-1],vec[j]);
      j -= 1;
    }
  }
}

void selectionSort(std::vector<int>& vec)
{
  int min_ind = 0;
   for (size_t i = 0; i < vec.size(); ++i)
   {
     min_ind = i; 
     for (size_t j = i; j < vec.size(); ++j)
     {
       if(vec[j] < vec[min_ind])
       {
         min_ind = j;
       }
     }
     std::swap(vec[min_ind],vec[i]);
   }
   
}
int main()
{
  std::vector<int> vec = {1,5,-8,5,6,3};
  // std::cout<<duplicates(vec);
  // bubbleSort(vec);
  // insertionSort(vec);
  selectionSort(vec);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout<<vec[i]<<" ";
  }
  
}