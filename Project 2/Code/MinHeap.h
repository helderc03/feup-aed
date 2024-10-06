//
// Created by Jaime on 30/12/2022.
//

#ifndef UNTITLED_MINHEAP_H
#define UNTITLED_MINHEAP_H
#define LEFT(i) (2*(i) + 1)
#define RIGHT(i) (2*(i)+ 2)
#define PARENT(i) ((i - 1)/2)
#include <vector>
#include <unordered_map>
#include <iostream>

class MinHeap {

    struct heapElement{
        int key; // index of the node in the graph
        int value; // distance to source node
    };

    std::vector<heapElement> heapElements;
    int currentSize = 0;
    int maxSize;
    void swap(int pos1, int pos2);

    public:
        /**
         * Default constructor for the MinHeap class.
         * Complexity: O(1)
         */
        MinHeap();

        /**
         * Constructor for the MinHeap class.
         * Complexity: O(1)
         * @param maxSize Max size
         */
        MinHeap(int maxSize);

        /**
         * Gets the size.
         * Complexity: O(1)
         * @return Size
         */
        int getSize();

        /**
         * Remove the first element and adjust the size.
         * Complexity: O(1)
         * @return Removed element
         */
        int removeMin();

        /**
         * Inserts a new value.
         * Complexity: O(1)
         * @param key Key
         * @param value Value
         */
        void insert(const int &key, const int &value);

        /**
         * Decreases a key's value.
         * Complexity: O(n)
         * @param key Key to modify
         * @param value New value.
         */
        void decreaseKey(const int &key, const int &value);

        /**
         * Swaps the order of elements.
         * Complexity: O(n)
         * @param pos Position to be swapped
         */
        void upHeap(int pos);

        /**
         * Swaps the order of elements.
         * Complexity: O(n)
         * @param pos Position to be swapped
         */
        void downHeap(int pos);

        /**
         * Checks if a certain key exists.
         * Complexity: O(1)
         * @param key Key to be found
         * @return True or false
         */
        bool hasKey(const int &key);
        std::unordered_map<int, int> pos;

};


#endif //UNTITLED_MINHEAP_H
