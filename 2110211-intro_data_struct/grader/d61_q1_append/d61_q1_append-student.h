// Stack Queue Append

#include "stack.h"
#include "queue.h"

namespace CP {
template<typename T>
void stack<T>::appendStack(stack<T> s) {
    stack<T> aux;
    while (!empty()) {
        aux.push(top());
        pop();
    }
    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }
    while (!aux.empty()) {
        push(aux.top());
        aux.pop();
    }
}

template<typename T>
void stack<T>::appendQueue(queue<T> q) {
    stack<T> aux;
    while (!empty()) {
        aux.push(top());
        pop();
    }
    while (!q.empty()) {
        aux.push(q.front());
        q.pop();
    }
    while (!aux.empty()) {
        push(aux.top());
        aux.pop();
    }
}

template<typename T>
void queue<T>::appendStack(stack<T> s) {
    while (!s.empty()) {
        push(s.top());
        s.pop();
    }
}

template<typename T>
void queue<T>::appendQueue(queue<T> q) {
    while (!q.empty()) {
        push(q.front());
        q.pop();
    }
}
}
