// Skip List

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
typename CP::list<T>::iterator CP::list<T>::insert(typename CP::list<T>::iterator it, const T& element) {
    node* tmp = new node(element, it.ptr->get_prev(), it.ptr, nullptr);
    if (it.ptr->get_next() != mHeader && it.ptr != mHeader) {
        tmp->set_nextnext(it.ptr->get_next());
    }
    it.ptr->get_prev()->set_next(tmp);
    if (it.ptr != mHeader) {
        it.ptr->get_prev()->set_nextnext(it.ptr);
    }
    if (it.ptr->get_prev() != mHeader) {
        it.ptr->get_prev()->get_prev()->set_nextnext(tmp);
    }
    it.ptr->set_prev(tmp);
    mSize++;
    return iterator(tmp);
}

template<typename T>
T CP::list<T>::at(size_t k) {
    // Ensure k is in range
    if (k >= mSize) throw std::out_of_range("index of out range");
    size_t index = 0;
    node* current = mHeader->get_next();
    while (index < k) {
        if (index + 2 <= k) {
            index += 2;
            current = current->get_nextnext();
        } else {
            index ++;
            current = current->get_next();
        }
    }
    return current->data;
}

template<typename T>
typename CP::list<T>::iterator CP::list<T>::erase(typename CP::list<T>::iterator it) {
    iterator tmp(it.ptr->get_next());
    if (it.ptr->get_prev() != mHeader) {
        if (it.ptr->get_next() != mHeader) {
            it.ptr->get_prev()->get_prev()->set_nextnext(it.ptr->get_next());
        } else {
            it.ptr->get_prev()->get_prev()->set_nextnext(nullptr);
        }
    }
    it.ptr->get_prev()->set_next(it.ptr->get_next());
    if (it.ptr->get_next() != mHeader && it.ptr->get_next()->get_next() != mHeader) {
        it.ptr->get_prev()->set_nextnext(it.ptr->get_next()->get_next());
    } else {
        it.ptr->get_prev()->set_nextnext(nullptr);
    }
    it.ptr->get_next()->set_prev(it.ptr->get_prev());
    delete it.ptr;
    mSize--;
    return tmp;
}

#endif
