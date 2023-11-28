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
    int setsize(int setparent, int min, int max) {
        int _size = 0;
        for (int i = min; i <= max; i++) {
            if (find(graph_array[i]) == setparent) {
                _size++;
            }
        }
        return _size;   
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
    void clearset() {
        for (int i = 1; i <= size; i++) {
            graph_array[i] = i;
        }
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

class unionmaze {
    int height;
    int weight;
    DSU rooms;
    bool* rightwall;
    bool* bottomwall;
    friend class DSU;
public:
    unionmaze(int _h, int _w) : height(_h), weight(_w), rooms(height*weight) {
        rightwall = new bool[height * weight + 1];
        bottomwall = new bool[height * weight + 1];
        for (int i = 0; i <= height * weight; i++) {
            rightwall[i] = 0;
            bottomwall[i] = 0;
            if (i % weight == 0) {
                rightwall[i] = 1;
            }
            if (i > weight * (height - 1)) {
                bottomwall[i] = 1;
            }
        }
    }
    bool randomBool() {
        return (rand() % 2) == 1;
    }
    void generaterightwalls(int h) {
        int pos = 1 + weight * h;
        //rightwall[weight + weight * h] = 1;
        for (int i = 0; i < weight - 1; i++) {
            bool randb = randomBool();
            if (rooms.find(pos + i) == rooms.find(pos + i + 1)) {
                rightwall[pos + i] = 1;
                continue;
            }
            if (randb) {
                rightwall[pos + i] = 1;
            }
            else {
                rooms.union_(pos + i, pos + i + 1);
            }
        }
    }
    void generatebottomwalls(int h) {
        int pos = 1 + weight * h;
        for (int i = 0; i < weight - 1; i++) {
            bool randb = randomBool();
            if (checkbott(rooms.find(pos),1 + weight * h, weight + weight * h)) {
                bottomwall[pos] = randb;
            }
            pos++;
        }
    }
    bool checkbott(int parentset,int min,int max) {
        int counter = 0;
        for (int i = min; i <= max; i++) {
            if (rooms.find(i) == parentset && bottomwall[i] == 1)
                counter++;
        }
        return counter < rooms.setsize(parentset, min, max) - 1;
    }
    void unionnextline(int h) {
        int pos = 1 + weight * h;
        int parent = rooms.find(pos);
        int unionelem = pos + weight;
        for (int i = 0; i < weight; i++) {
            bool flag = true;
            pos = 1 + weight * h + i;
            int newparent = rooms.find(pos);
            if (parent != newparent) {
                parent = newparent;
                unionelem = pos + 1 + weight;
                bool flag = false;
            }
            if (bottomwall[pos])
                unionelem = pos + 1 + weight;
            if (!bottomwall[pos] && flag) {
                rooms.union_(unionelem, pos + weight);
            }

        }
    }
    void unioncheck(int h) {
        int pos = 1 + weight * h;
        for (int i = 0; i < weight - 1; i++) {
            if (!rightwall[pos+i]) {
                rooms.union_(pos+i, pos+i + 1);
            }
        }
    }
    void maze_generator() {
        for (int i = 0; i < height; i++) {
            generaterightwalls(i);
            generatebottomwalls(i);
            if (i != height - 1) {
                unionnextline(i);
            }
        }
    }
    void printmaze(bool db = false) {
        if (!db) {
            for (int i = 0; i < height; i++) {
                for (int j = 1; j <= weight; j++) {
                    std::cout << ((rightwall[j + weight * i] == 1) ? "    #" : "     ");
                }
                std::cout << std::endl;
                for (int j = 1; j <= weight; j++) {
                    std::cout << ((rightwall[j + weight * i] == 1) ? "    #" : "     ");
                }
                std::cout << std::endl;
                for (int j = 1; j <= weight; j++) {
                    std::cout << ((bottomwall[j + weight * i] == 1) ? "# # #" : "    #");
                }
                std::cout << std::endl;
            }
        }
        else {
            for (int i = 0; i < height; i++) {
                for (int j = 1; j <= weight; j++) {
                    std::cout << rooms.find(j + weight * i) << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif DSU_DSU_H_
