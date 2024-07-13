#include <iostream>
#include <initializer_list>
class DynamicArray
{
  public:
    DynamicArray();
    DynamicArray(std::initializer_list<int> lst);
    DynamicArray(int cap,int val);
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other);
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& obj);
    int& operator[](int pos);
    const int& operator[](int pos) const;
    ~DynamicArray();

  public:
    void Reserve(int cap);
    int Capacity();
    int Size();
    bool Include(int elem);
    void Insert(int pos,int val);
    void Push_Back(int elem);
    void Pop_Back();
    void Remove(int pos);
    void Clear();
    bool IsEmpty();
    void ShrinkToFit();
    
  
  private:
    void Resize(int cap);
  private:
    int* m_arr;
    int  m_size;
    int  m_cap;
};