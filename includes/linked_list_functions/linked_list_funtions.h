#ifndef Linked_list
#define Linked_list
#include <cassert>
#include "../node/node.h"
using namespace std;
//-------------------------------------------------------------------------------------------------
// Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE> *head);

// recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head);

// return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_search_list(node<ITEM_TYPE> *head,
                              ITEM_TYPE key);

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_head(node<ITEM_TYPE> *&head,
                              ITEM_TYPE insert_this);

// insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_after(node<ITEM_TYPE> *&head,
                               node<ITEM_TYPE> *after_this,
                               ITEM_TYPE insert_this);

// insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_before(node<ITEM_TYPE> *&head,
                                node<ITEM_TYPE> *before_this,
                                ITEM_TYPE insert_this);

// ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_previous_node(node<ITEM_TYPE> *head,
                                node<ITEM_TYPE> *prev_to_this);

// delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE> *&head,
                       node<ITEM_TYPE> *delete_this);

// duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE> *head);

// duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src);

// delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE> *&head);

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE &_at(node<ITEM_TYPE> *head, int pos);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted(node<ITEM_TYPE> *&head, // insert
                                ITEM_TYPE item,
                                bool ascending = true);

// insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted_and_add(node<ITEM_TYPE> *&head,
                                        ITEM_TYPE item,
                                        bool ascending = true);
// node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_where_this_goes(node<ITEM_TYPE> *head,
                                  ITEM_TYPE item,
                                  bool ascending = true);
// Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_last_node(node<ITEM_TYPE> *head); //

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template <typename ITEM_TYPE, typename DUP>
// node<ITEM_TYPE> *_insert_sorted_unique(node<ITEM_TYPE> *&head,
//                                        const ITEM_TYPE item,
//                                        DUP Dup = Dup_Nothing<ITEM_TYPE>());

//---------------------------------------------------------------
// Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE> *head)
{
    node<ITEM_TYPE> *walker = head;
    cout << "H->";
    while (walker != nullptr)
    {
        cout << *walker;
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

// recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head)
{
    // empty
}

// return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_search_list(node<ITEM_TYPE> *head,
                              ITEM_TYPE key)
{
    node<ITEM_TYPE> *walker = head;
    while (walker != nullptr)
    {
        if (walker->_item == key)
        {
            return walker;
        }
        walker = walker->_next;
    }
    return walker;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_head(node<ITEM_TYPE> *&head,
                              ITEM_TYPE insert_this)
{
    node<ITEM_TYPE> *nodeptr = new node<ITEM_TYPE>(insert_this);
    nodeptr->_next = head;
    head = nodeptr;
    return head;
}

// insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_after(node<ITEM_TYPE> *&head,
                               node<ITEM_TYPE> *after_this,
                               ITEM_TYPE insert_this)
{
    // assert(after_this != nullptr);
    if (head == nullptr)
    {
        head = _insert_head(head, insert_this);
        return head;
    }
    node<ITEM_TYPE> *nodeptr = new node<ITEM_TYPE>(insert_this);
    nodeptr->_next = after_this->_next;
    after_this->_next = nodeptr;
    return nodeptr;
}

// insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_before(node<ITEM_TYPE> *&head,
                                node<ITEM_TYPE> *before_this,
                                ITEM_TYPE insert_this)
{
    node<ITEM_TYPE> *prev = _previous_node(head, before_this);
    if (prev == nullptr)
    {
        return _insert_head(head, insert_this);
    }

    return _insert_after(head, prev, insert_this);
}

// ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_previous_node(node<ITEM_TYPE> *head,
                                node<ITEM_TYPE> *prev_to_this)
{
    if (head == prev_to_this)
    {
        return nullptr;
    }
    node<ITEM_TYPE> *walker = head;
    while (walker != nullptr)
    {
        if (walker->_next == prev_to_this)
        {
            return walker;
        }
        walker = walker->_next;
    }
    assert(walker != nullptr);
    return walker;
}

// delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE> *&head,
                       node<ITEM_TYPE> *delete_this)
{
    ITEM_TYPE x;
    if (head == nullptr)
    {
        return ITEM_TYPE();
    }
    if (head == delete_this)
    {
        x = delete_this->_item;
        head = delete_this->_next;
        delete delete_this;
        return x;
    }
    x = delete_this->_item;
    node<ITEM_TYPE> *prev = _previous_node(head, delete_this);
    if (prev == nullptr)
    {
        return ITEM_TYPE();
    }
    prev->_next = delete_this->_next;
    delete delete_this;
    return x;
}

// duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE> *head)
{
    node<ITEM_TYPE> *newhead = nullptr;
    _copy_list(newhead, head);
    return newhead;
}

// duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src)
{
    if (dest != nullptr)
    {
        _clear_list(dest);
    }
    if (src == nullptr)
    {

        return dest;
    }
    node<T> *w1 = src;
    node<T> *w2 = dest;
    w2 = _insert_head(dest, w1->_item);
    w1 = w1->_next;
    while (w1 != nullptr)
    {
        _insert_after(dest, w2, w1->_item);
        w1 = w1->_next;
        w2 = w2->_next;
    }
    return _last_node(dest);
}

// delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE> *&head)
{
    node<ITEM_TYPE> *walker = head;
    node<ITEM_TYPE> *walker2 = walker;
    while (walker2 != nullptr)
    {
        walker2 = walker->_next;
        delete walker;
        walker = walker2;
    }
    head = nullptr;
}

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE &_at(node<ITEM_TYPE> *head, int pos)
{
    assert(pos >= 0);
    node<ITEM_TYPE> *walker = head;
    for (int i = 0; i < pos; i++)
    {
        walker = walker->_next;
    }
    assert(walker != nullptr);
    ITEM_TYPE *ptr = &(walker->_item);
    return *ptr;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted(node<ITEM_TYPE> *&head, ITEM_TYPE item, bool ascending)
{
    node<ITEM_TYPE> *ptr = _where_this_goes(head, item, ascending);
    if (ptr == nullptr)
    {
        return _insert_head(head, item);
    }
    return _insert_after(head, ptr, item);
}
// Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_last_node(node<ITEM_TYPE> *head)
{
    node<ITEM_TYPE> *walker = head;

    while (walker->_next != nullptr)
        walker = walker->_next;

    return walker;
} //
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_where_this_goes(node<ITEM_TYPE> *head, ITEM_TYPE item, bool ascending)
{

    if (head == nullptr)
    {
        return nullptr;
    }
    node<ITEM_TYPE> *w1 = head;
    node<ITEM_TYPE> *w2 = head->_next;
    if (ascending)
    {
        if (w1->_item < item)
        {
            while ((w2 != nullptr) && (w2->_item < item))
            {
                w1 = w1->_next;
                w2 = w2->_next;
            }
            return w1;
        }
        return nullptr;
    }
    if (!ascending)
    {
        if (w1->_item > item)
        {
            while ((w2 != nullptr) && (w2->_item >> item))
            {
                w1 = w1->_next;
                w2 = w2->_next;
            }
            return w1;
        }
        return nullptr;
    }
    return nullptr;
}
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted_and_add(node<ITEM_TYPE> *&head,
                                        ITEM_TYPE item,
                                        bool ascending)
{
    node<ITEM_TYPE> *result = _search_list(head, item);
    if (result != nullptr)
    {
        result->_item *= 2;
        return result;
    }
    return _insert_sorted(head, item, ascending);
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template <typename ITEM_TYPE, typename DUP>
// node<ITEM_TYPE> *_insert_sorted_unique(node<ITEM_TYPE> *&head,
//                                        const ITEM_TYPE item,
//                                        DUP Dup = Dup_Nothing<ITEM_TYPE>());
// node after which this item goes order: 0 ascending

#endif