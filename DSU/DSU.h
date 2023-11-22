// Copyright 2023 Anikin Maksim

#ifndef DSU_DSU_H_
#define DSU_DSU_H_

#include <iostream>

class DSU {
    int* graph_array;
    int size;
    int* ranks_array;
 public:
    explicit DSU(int _size) : size(_size) {
        graph_array = new int[size + 1];
        ranks_array = new int[size + 1];
        graph_array[0] = -1;
        ranks_array[0] = -1;
        for (int i = 1; i <= size; i++) {
            graph_array[i] = i;
            ranks_array[i] = 0;
        }
    }
    int find(int val) {
        if (val == graph_array[val])
            return val;
        return find(graph_array[val]);
    }
    int rank(int val) {
        return ranks_array[find(val)];
    }
    void union_(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x != parent_y)
            graph_array[parent_y] = parent_x;
    }
    void print() {
        for (int i = 0; i <= size; i++) {
            if (i == 0) {
                std::cout << "P:" << " ";
                continue;
            }
            std::cout << graph_array[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i <= size; i++) {
            if (i == 0) {
                std::cout << "I:" << " ";
                continue;
            }
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

#endif DSU_DSU_H_
