#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>

class Array
{
public:
    Array<T>() : _size(0)
    {
        _array = new T();
    };

    Array<T>(int n) : _size(n)
    {
        _array = new T[n];
    }

    Array<T>(const Array<T> &to_cpy)
    {
        _size = to_cpy._size;
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = to_cpy._array[i];
    }

    Array<T> &operator=(const Array<T> &to_cpy)
    {
        if (this != &to_cpy)
        {
            delete[] _array;

            _size = to_cpy._size;
            _array = new T[_size];
            for (int i = 0; i < _size; i++)
                _array[i] = to_cpy._array[i];
        }
        return (*this);
    }

    ~Array()
    {
        delete[] _array; 
    }

    T &operator[](int i)
    {
        if (i < 0 || i > (_size - 1))
            throw(std::out_of_range("Index out of range"));
        return _array[i];
    }
    int size() const
    {
        return _size;
    }

private:
    T *_array;
    int _size;
};

#endif