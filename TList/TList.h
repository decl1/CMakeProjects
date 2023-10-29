// Copyright 2023 Anikin Maksim

#ifndef TLIST_TLIST_H_
#define TLIST_TLIST_H_

template <class T>
class TNode {
	T data;
	TNode* next;
 public:
	TNode(const TNode& node) : data(node.data), next(node.next) { };
    TNode(T _data, TNode* _next = nullptr) : data(_data), next(_next) { };
    ~TNode() { delete[] next; };
};

template <class T>
class TList {
	friend class TNode;
 public:
	 
};

#endif  // TLIST_TLIST_H_
