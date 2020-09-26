#include "Utility/Vector.hpp"


// template <class T>
// void Vector<T>::push_back(const T& element)
// {
//     T** t = new T*[_count + 1];


//     for (T** i = _t; i < _t + _count; ++i)
//     {
//         t[_t + _count - i] = *i;
//     }
//     t[_count] = new T(element);
//     delete _t;
//     _t = t;
//     ++_count;
// }

// template <class T>
// void Vector<T>::for_each(std::function<void(T&)> f)
// {   
//     for (T** i = _t; i < _t + _count; ++i)
//     {
//         f((T&)**i);
//     }
    
// }

// template <class T>
// Vector<T>::Vector() : _count(0), _t(nullptr)
// {

// }

// template <class T>
// Vector<T>::~Vector()
// {

// }