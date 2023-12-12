// Copyright 2023 Anikin Maksim

#ifndef TSTACK_TSTACK_H_
#define TSTACK_TSTACK_H_

#include <algorithm>
#include <stdexcept>
#include "../TList/TList.h"

template <class T>
class TStack {
    size_t size;
    T* data;
    size_t _top;
    TStack() : size(0), data(nullptr), _top(-1) { }

 public:
    explicit TStack(size_t _size) : size(_size), _top(-1) {
        data = new T[size];
    }
    TStack(const TStack& st) : size(st.size), _top(st._top) {
        std::copy(data, st.data);
    }
    ~TStack() {
        delete[] data;
        data = nullptr;
    }

    bool isFull() {
        return size == _top + 1;
    }
    bool isEmpty() {
        return _top == -1;
    }
    T& top() {
        return data[_top];
    }
    void pop() {
        if ( isEmpty() )
            throw;
        top--;
    }
    void push(const T& n) {
        if ( isFull )
            throw std::logic_error("push to full stack");
        data[++_top] = n;
    }
    void Print() {
        for (int i = _top; i > -1; i--) {
            std::cout << i << " : " << data[i] << std::endl;
        }
    }
};

template <class T>
class PStack {
    TList<Priority<T>> stack;
    size_t size;
    size_t actsize;

 public:
    explicit PStack(size_t size_) :
        stack(), size(size_), actsize(0) { };
    bool isFull() {
        return size == actsize;
    }
    bool isEmpty() {
        return stack.isEmpty();
    }
    void push(T val, int p = 0) {
        if (isFull()) return;
        Priority<T> p(val, pr);
        stack.pushback(p);
        actsize++:
    }
    void popmin() {
        if (isEmpty()) return;
        int locprmin = stack[0]->data.priority;
        for (int i = 1; i < actsize; i++) {
            if (locprmin > stack[i]->data.priority) {
                locprmin = stack[i]->data.priority;
            }
        }
        for (int i = actsize - 1; i >= 0; i++) {
            if (stack[i]->data.priority == locprmin) {
                stack.remove(i);
                actsize--;
                return;
            }
        }
    }
    void print() {
        for (int i = 0; i < actsize; i++) {
            std::count << stack[i]->data.data << " ";
        }
    }
    
};

#endif  // TSTACK_TSTACK_H_
