#pragma once

#include <iostream>
#include "counter.h"

namespace kli
{
    
template <typename T>
class SharedPtr
{
  public:
    SharedPtr();
        
    SharedPtr(T *p);
        
    SharedPtr(const SharedPtr<T>& src);
        // copy constructor
    
    SharedPtr& operator=(const SharedPtr& src);
        // assignment
        
    ~SharedPtr();
    
    T& operator*();
        // overload operator *         
        
    T* operator->();
        // overload operator ->
    
  private:
    T *d_ptr;
        
    Counter *d_refCounter;
};



//========================================================
// class implements
//========================================================

template <typename T>
SharedPtr<T>::SharedPtr()
    : d_ptr{nullptr}
    , d_refCounter{new Counter{}}
{}
    
template <typename T>
SharedPtr<T>::SharedPtr(T *p)
    : d_ptr{p}
    , d_refCounter{new Counter{}}
{
    d_refCounter->increase();
}
    
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& src)
    : d_ptr{src.d_ptr}
    , d_refCounter{src.d_refCounter}
{
    d_refCounter->increase();
}
    
template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& src)
{
    // prevent self assignment
    if (this == &src)
        return *this;
        
    if (d_refCounter->decrease() == 0)
    {
        std::cout << "delete ptr @" << d_ptr << std::endl;
        delete d_ptr;
        delete d_refCounter;
    }
    
    d_ptr = src.d_ptr;
    d_refCounter = src.d_refCounter;
    d_refCounter->increase();
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (d_refCounter->decrease() == 0)
    {
        std::cout << "delete ptr @"<< d_ptr << std::endl;
        delete d_ptr;
        delete d_refCounter;
    }
}
    
template <typename T>
T& SharedPtr<T>::operator*()
{
    return *d_ptr;
}
    
template <typename T>
T* SharedPtr<T>::operator->()
{
    return d_ptr;
}

}
