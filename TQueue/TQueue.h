// Copyright 2023 Anikin Maksim

#ifndef TQUEUE_TQUEUE_H_
#define TQUEUE_TQUEUE_H_

#include <iostream>
#include "../TList/TList.h"

template <class T>
class TQueue {
    size_t size;
    size_t actsize;
    TNode<T>* beg;
    TNode<T>* end;

 public:
    explicit TQueue(size_t size_) : 
        size(size_), actsize(0), beg(nullptr), end(nullptr) { }
    bool isEmpty() {
        return beg == nullptr;
    }
    bool isFull() {
        return actsize == size;
    }
    void push(T val) {
        if (!isFull()) {
            TNode<T>* p = new TNode<T>(val);
            if (beg == nullptr) {
                beg = p;
                end = p;
            }
            else {
                end->next = p;
                end = p;
            }
            actsize++;
        }
    }
    T pop() {
        if (!isEmpty()) {
            T ret = beg->data;
            TNode<T>* p = beg;
            beg = beg->next;
            delete p;
            actsize--;
            return ret;
        }
    }
    void clear() {
        while (!isEmpty())
            pop();
    }
    size_t getsize() {
        return actsize;
    }
    void print() {
        TNode<T>* p = beg;
        while (p) {
            std::cout << p->data << " " << std::endl;
            p = p->next;
        }
    }
};

template <class T>
class PQueue {
    TList<Priority<T>> queue;
    size_t size;
    size_t actsize;
 
 public:
    explicit PQueue(size_t size_) : 
        size(size_), actsize(0), queue() { }
    bool isFull() {
        return size == actsize;
    }
    bool isEmpty() {
        return queue.isEmpty();
    }
    void push(T val, int pr = 0) {
        if (isFull()) return;
        Priority<T> p(val, pr);
        queue.pushback(p);
        actsize++;
    }
    void popmin() {
        if (isEmpty()) return;
        int locprmin = queue[0]->data.priority;
        for (int i = 1; i < actsize; i++) {
            if (locprmin > queue[i]->data.priority) {
                locprmin = queue[i]->data.priority;
            }
        }
        for (int i = 0; i < actsize; i++) {
            if (queue[i]->data.priority == locprmin) {
                queue.remove(i);
                actsize--;
                return;
            }
        }
    }
    void print() {
        for (int i = 0; i < actsize; i++) {
            std::cout << queue[i]->data.data << " ";
        }
    }
};

#endif // TQUEUE_TQUEUE_H_
