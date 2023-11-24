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

class maze {
    int size;
    bool*  rooms;
    bool* rightwall;
    bool* bottomwall;
    friend class DSU;
 public:
    explicit maze(int _size) : size(_size) {
        rightwall = new bool[size * size + 1];
        bottomwall = new bool[size * size + 1];
        rooms = new bool[size * size + 1];
        clearmaze();
    }
    void clearmaze() {
        for (int i = 1; i <= size*size; i++) {
            rightwall[i] = 1;
            bottomwall[i] = 1;
            rooms[i] = 0;
        }
    }
    int generate_step(bool u, bool d, bool l, bool r) {
        int max = u + d + l + r;
        bool choose[4] = {u,d,l,r};
        int step = rand() % max; // 0 u, 1 d, 2 l, 3r;
        for (int i = 0; i < 4; i++) {
            if (choose[i] != 0) {
                if (step == 0) {
                    return i;
                }
                step--;
            }
        }
    }
    void generate_way_to_finish(bool dbprint = 0) {
        int pos = 1;
        while (pos != size * size) {
            if (dbprint) system("cls");
            rooms[1] = 1;
            bool upflag = 0;
            bool downflag = 0;
            bool rightflag = 0;
            bool leftflag = 0;
            if (pos - size > 0)
                upflag = (rooms[pos - size] == 0) ? 1 : 0;
            if (pos + size < size * size)
                downflag = (rooms[pos + size] == 0) ? 1 : 0;
            if (pos % size != 1)
                leftflag = (rooms[pos - 1] == 0) ? 1 : 0;
            if (pos % size != 0)
                rightflag = (rooms[pos + 1] == 0) ? 1 : 0;
            if (!upflag && !downflag && !rightflag && !leftflag == 1) {
                pos = 1;
                clearmaze();
                continue;
            }
            int dbgen = generate_step(upflag, downflag, leftflag,rightflag);
            switch (dbgen) {
            case 0: {
                rooms[pos - size] = 1;
                pos = pos - size;
                bottomwall[pos] = 0;
                break;
            }
            case 1: {
                rooms[pos + size] = 1;
                bottomwall[pos] = 0;
                pos = pos + size;
                break;
            }
            case 2: {
                rooms[pos - 1] = 1;
                pos = pos - 1;
                rightwall[pos] = 0;
                break;
            }
            case 3: {
                rooms[pos + 1] = 1;
                rightwall[pos] = 0;
                pos = pos + 1;
                break;
            }
            }
            if (dbprint) {
                dbprintmaze();
            }
        }
    }
    void dbprintmaze() {
        for (int i = 1; i <= size*size; i++) {
            if (i % size == 1)
                std::cout << std::endl;
            std::cout << rooms[i] << " ";
        }
    }
    void printmaze() {
        ;
    }
};

#endif DSU_DSU_H_
