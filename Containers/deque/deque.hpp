namespace Nar
{
//public functions
template<typename T>
deque<T>::deque():left(nullptr),leftSize(),leftCap(),right(nullptr),rightSize(),rightCap()
{}

template<typename T>
deque<T>::~deque()
{
    clear();
}

template<typename T>
void deque<T>::push_front(T& val)
{
    if(leftSize == leftCap)
    {
        resizeLeft();
    }
    left[leftSize++] = val;
}
 
template<typename T>
void deque<T>::push_front(const T& val)
{
    push_front(const_cast<T&>(val));
}

template<typename T>
void deque<T>::push_back(T& val)
{
    if(leftSize == leftCap)
    {
        resizeRight();
    }
    right[rightSize++] = val;
}

template<typename T>
void deque<T>::push_back(const T& val)
{
    push_back(const_cast<T&>(val));
}

template<typename T>
void deque<T>::pop_front()
{
    if(leftSize != 0)
    {
        leftSize--;
    }
    else if(rightSize != 0)
    {
        for (size_t i = 0; i < rightSize-1; ++i)
        {
            right[i] = right[i+1];
        }
        --rightSize;
    }
    else
    {
        return;
    }
}

template<typename T>
void deque<T>::pop_back()
{
    if(rightSize != 0)
    {
        --rightSize;
    }
    else if(leftSize != 0)
    {
        for (size_t i = 0; i < leftSize-1; ++i)
        {
            left[i] = left[i+1];
        }
        --leftSize;
    }
    else
    {
        return;
    }
}

template<typename T>
T deque<T>::front()
{
    if(leftSize != 0)
    {
        return left[leftSize-1];
    }
    if(rightSize != 0)
    {
        return right[rightSize-1];
    }
    throw std::out_of_range("Deque is empty");
}

template<typename T>
bool deque<T>::empty()
{
    if(leftSize or rightSize)
    {
        return true;
    }
    return false;
}


template<typename T>
std::size_t deque<T>::size()
{
    return leftSize+rightSize;
}

template<typename T>
void deque<T>::clear()
{
    delete[] left;
    delete[] right;
    leftSize = 0;
    rightSize = 0;
}

template<typename T>
T& deque<T>::operator[](std::size_t i)
{
    if(i < leftSize)
    {
        return left[leftSize - i - 1];
    }
    else if(i < size())
    {
        return right[i - leftSize];
    }
    else
    {
        throw std::out_of_range("there is no such index");
    }
}

template<typename T>
void deque<T>::insert(std::size_t i,int val)
{
    if(i < leftSize)
    {
        if(leftSize == leftCap)
        {
            resizeLeft();
        }
        for (size_t j = leftSize + 1; j > leftSize - 1 -i; --j)
        {
            left[j] = left[j-1];
        }
        ++leftSize;
        left[leftSize - 1 - i] = val; 
    }
    else if(i <= size())
    {
        if(rightSize == rightCap)
        {
            resizeRight();
        }
        for (size_t j = rightSize ; j > i - rightSize - 1 ; --j)
        {
            right[j] = right[j-1];
        }
        ++rightSize;
        right[i - rightSize] = val;
    }
    else
    {
        throw std::out_of_range("wrong index");
    }
}

template<typename T>
void deque<T>::erase(std::size_t i)
{
    if(i < 0 or i > size())
    {
        return;
    }
    else if(i < leftSize)
    {
        for (size_t j = leftSize - 1 - i; j < leftSize - 1; j++)
        {
            left[j] = left[j+1];
        }
        --leftSize;
    }
    else if(i <= size())
    {
        for (size_t j =i - rightSize - 1; j < rightSize; j++)
        {
            right[j] = right[j+1];
        }
        --rightSize;
    }
}


//private functions
template<typename T>
void deque<T>::resizeLeft()
{
    leftCap += 5;
    T* newArr = new T[leftCap];
    for (size_t i = 0; i < leftSize; i++)
    {
        newArr[i] = left[i];
    }
    delete[] left;
    left = newArr;
}

template<typename T>
void deque<T>::resizeRight()
{
    rightCap += 5;
    T* newArr = new T[rightCap];
    for (size_t i = 0; i < rightSize; i++)
    {
        newArr[i] = right[i];
    }
    delete[] right;
    right = newArr;
}

}


