#include "./DynamicArray.h"


DynamicArray::DynamicArray()
:m_cap(5)
,m_size()
,m_arr(new int[m_cap])
{
  for (size_t i = 0; i < m_cap; i++)
  {
    m_arr[i] = 0;
  }
}

DynamicArray::DynamicArray(std::initializer_list<int> lst)
:m_cap(lst.size())
,m_size(lst.size())
,m_arr(new int[m_cap])
{
  int i = 0;
  for(int val:lst)
  {
    m_arr[i++] = val;
  }
}


DynamicArray::DynamicArray(int cap,int val = 0)
:m_cap(cap)
,m_size()
,m_arr(new int[m_cap])
{
  for (size_t i = 0; i < m_cap; i++)
  {
    m_arr[i] = val;
  }
}

DynamicArray::DynamicArray(const DynamicArray& other)
:m_cap(other.m_cap)
,m_size(other.m_size)
,m_arr(new int[m_cap])
{
  for (size_t i = 0; i < m_size; i++)
  {
    m_arr[i] = other.m_arr[i];
  }
  
}

DynamicArray::DynamicArray(DynamicArray&& other)
:m_cap(other.m_cap)
,m_size(other.m_size)
,m_arr(other.m_arr)
{
     other.m_arr = nullptr;
     other.m_cap = 0;
     other.m_size = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
  if(this != &other)
  {
    m_cap = other.m_cap;
    m_size = other.m_size;
    m_arr = new int[m_cap];

    for (size_t i = 0; i < m_size; i++)
    {
      m_arr[i] = other.m_arr[i];
    }
  }
  return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other)
{
  if(this != &other)
  {
    m_cap = other.m_cap;
    m_size = other.m_size;
    m_arr = other.m_arr;

    other.m_arr = nullptr;
    other.m_cap = 0;
    other.m_size = 0;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& obj) 
{
    os << "[";
    for (size_t i = 0; i < obj.m_size; ++i) {
        os << obj.m_arr[i];
        if (i < obj.m_size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int& DynamicArray::operator[](int pos)
{
    return m_arr[pos];
}

const int& DynamicArray::operator[](int pos) const
{
    return m_arr[pos];
}

 DynamicArray::~DynamicArray()
 {
    delete[] m_arr;
    m_cap = 0;
    m_size = 0;
 }


void DynamicArray::Reserve(int cap)
{
    Resize(cap);
}

int DynamicArray::Capacity()
{
    return m_cap;
}

int DynamicArray::Size()
{
    return m_size;
}

bool DynamicArray::Include(int elem)
{
    for (size_t i = 0; i < Size(); i++)
    {
        if(m_arr[i] == elem)
        {
            return true;
        }
    }
  
    return false;
}


void DynamicArray::Insert(int pos, int val)
{
    if(pos < 0 && pos > Size())
    {
        throw std::out_of_range("Wrong Possition");
    }
    if(m_size == m_cap)
    {
        m_cap *= 2;
        Resize(m_cap);
    }
    for (size_t i = m_size; i > pos; --i)
    {
        m_arr[i] = m_arr[i-1];
    }
    ++m_size;
    m_arr[pos] = val;
}

void DynamicArray::Push_Back(int elem)
{
    if(Size() == Capacity())
    {
        m_cap *= 2;
        Resize(m_cap);
    }
    m_arr[m_size++] = elem;
}

void DynamicArray::Pop_Back()
{
    if(m_size != 0)
    --m_size;
}

void DynamicArray::Remove(int pos)
{
    if(pos < 0 && pos > m_size)
    {
       throw std::out_of_range("Wrong position");
    }
    for (size_t i = pos; i < m_size; i++)
    {
        m_arr[i] = m_arr[i+1];
    }
    --m_size;
}

void DynamicArray::Clear()
{
    for (size_t i = 0; i < Size(); i++)
    {
        m_arr[i] = 0;
    }
    m_size = 0;
}

bool DynamicArray::IsEmpty()
{
    return m_size == 0 ? true:false;
}

void DynamicArray::ShrinkToFit()
{
    int* NewArr = new int[m_size];
    for (size_t i = 0; i < m_size; i++)
    {
        NewArr[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = NewArr;
    m_cap = m_size;
    
}

void DynamicArray::Resize(int cap) {
    if (cap < 0) {
        throw std::out_of_range("input new size");
    }

    int* NewArr = new int[cap];
    
    if (cap > m_size) {
        for (size_t i = 0; i < m_size; i++) {
            NewArr[i] = m_arr[i];
        }
        for (size_t i = m_size; i < cap; i++) {
            NewArr[i] = 0;
        }
    } else {
        for (size_t i = 0; i < cap; i++) {
            NewArr[i] = m_arr[i];
        }
        m_size = cap;
    }

    delete[] m_arr;

    m_arr = NewArr;
    m_cap = cap;
}

