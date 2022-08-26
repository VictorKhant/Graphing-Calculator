#ifndef queue1
#define queue1
#include <iostream>
#include <iomanip>
#include "../node/node.h"
#include "../linked_list_functions/linked_list_funtions.h"
using namespace std;
template <typename T>
class Queue
{
public:
    class Iterator
    {
    public:
        friend class Queue;                // give access to list to access _ptr
        Iterator() { _ptr = nullptr; }     // default ctor
        Iterator(node<T> *p) { _ptr = p; } // Point Iterator to where
                                           //...                        //  p is pointing to
        T &operator*();                    // dereference operator
        T *operator->();                   // member access operator

        bool is_null()
        {
            if (_ptr == nullptr)
            {
                return true;
            }
            return false;
        }
        friend bool operator!=(const Iterator &left,
                               const Iterator &right)
        {
            if (left._ptr != right._ptr)
            {
                return true;
            }
            return false;
        } // true if left != right

        friend bool operator==(const Iterator &left,
                               const Iterator &right)
        {
            if (left._ptr == right._ptr)
            {
                return true;
            }
            return false;
        }
        Iterator &operator++()
        {
            _ptr++;
            return *this;
        } // member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator &it,
                                   int unused)
        {

            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T> *_ptr; // pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T> &copyMe);
    ~Queue();
    Queue &operator=(const Queue<T> &RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const; // Iterator to the head node
    Iterator end() const;   // Iterator to NULL
    void print_pointers();
    int size() const { return _size; }
    template <typename TT>
    friend ostream &operator<<(ostream &outs, const Queue<TT> &printMe);

private:
    node<T> *_front;
    node<T> *_rear;
    int _size;
};

template <typename T>
T &Queue<T>::Iterator::operator*()
{
    assert(_ptr != nullptr);
    return _ptr->_item;
}

template <typename T>
T *Queue<T>::Iterator::operator->()
{
    return &(operator*());
}
template <typename T>
Queue<T>::Queue()
{
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &copyMe)
{
    _rear = _copy_list(_front, copyMe._front);
    // _front = copyMe._front;
    _size = copyMe._size;
    // cout << _front << endl;
    // cout << _rear << endl;
}

template <typename T>
Queue<T>::~Queue()
{
    // /cout << "destructor fired";
    _clear_list(_front);
    _front = nullptr;
    _rear = nullptr;
}
template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &RHS)
{
    if (this == &RHS)
    {
        return *this;
    }
    _clear_list(_front);
    _rear = _copy_list(_front, RHS._front);
    //_front = RHS._front;
    _size = RHS._size;
    // cout << _front << endl;
    // cout << _rear << endl;
    return *this;
}

template <typename T>
bool Queue<T>::empty()
{
    return (_front == nullptr);
}

template <typename T>
T Queue<T>::front()
{
    return _front->_item;
}

template <typename T>
T Queue<T>::back()
{
    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item)
{
    _rear = _insert_after(_front, _rear, item);
    _size++;
}

template <typename T>
T Queue<T>::pop()
{
    T item = _delete_node(_front, _front);
    if (item != T())
    {
        _size--;
    }
    if (_front == nullptr)
    {
        _rear = _front;
    }
    return item;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(_front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(nullptr);
}

template <typename T>
void Queue<T>::print_pointers()
{
    node<T> *walker = _front;
    cout << "H->";
    while (walker != nullptr)
    {
        cout << *walker->_item << "->";
        walker = walker->_next;
    }
    cout << "|||" << endl;
}
template <typename TT>
ostream &operator<<(ostream &outs, const Queue<TT> &printMe)
{
    node<TT> *walker = printMe._front;
    while (walker != nullptr)
    {
        outs << *walker;
        walker = walker->_next;
    }
    outs << "|||" << endl;
    return outs;
}
#endif