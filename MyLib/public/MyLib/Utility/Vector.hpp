#include <functional>
#include <iostream>
using namespace std;


template <class T>
class Vector
{

private:
    T** expand(int nr)
    {
        T** t = new T*[_count + nr];

        for (int i = 0; i < _count; ++i) 
        {
            t[i] = _t[i];
        }

        _t = t;
        _count += nr;
        return _t + _count - nr;
    }

    public:
    T** _t;
    int _count;



    void push_back(const T& elem)
    {
        *(expand(1)) = new T((const T&) elem);
    }






    void for_each(std::function<void(const T&)> f)
    {   
        for (T** i = _t; i < _t + _count; ++i)
        {
            f(**i);
        }
    }

    T& operator[](int i)
    {
        return **(_t + i);
    }

    int size() const 
    {
        return _count;
    }

    Vector() : _count(0), _t(nullptr)
    {

    }

    ~Vector()
    {

    }

    Vector& operator/=(const Vector& other)
    {
        return *this;
    }
    Vector& operator*=(const Vector& other)
    {
        return *this;
    }
    Vector& operator+=(const Vector& other)
    {
        return *this;
    }
    Vector& operator+=(const T& elem)
    {
        *(expand(1)) = new T((const T&) elem);
        return *this;
    }
    Vector& operator-=(const Vector& other)
    {
        for (T** i = _t; i < _t + _count; ++i)
        {
            
        }
        
    }
    Vector& operator-=(const T& elem)
    {
        return *this;
    }
    friend Vector operator/(Vector first, const Vector& second)
    {
        return first;
    }
    friend Vector operator*(Vector first, const Vector& second)
    {
        return first;
    }
    friend Vector operator+(Vector first, const Vector& second)
    {
        return first;
    }
    friend Vector operator-(Vector first, const Vector& second)
    {
        return first;
    }
    Vector& operator++(){
        return *this;
    }
    Vector& operator--(){
        return *this;
    }
    Vector operator++(int){
        Vector tmp(*this);
        operator++();
        return tmp;
    }
    Vector operator--(int){
        Vector tmp(*this);
        operator--();
        return tmp;
    }
    Vector& operator=(Vector other)
    {
        swap(*this, other);
        return *this;
    }
    bool operator==(const Vector& other)
    {
        return false;
    }
    bool operator!=(const Vector& other)
    {
        return false;
    }
};


