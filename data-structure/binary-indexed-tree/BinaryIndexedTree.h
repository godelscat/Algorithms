//ref: https://blog.csdn.net/Yaokai_AssultMaster/article/details/79492190
//time cost O(lgn)
#ifndef BINARY_INDEXED_TREE_H
#define BINARY_INDEXED_TREE_H
#include <iostream>
#include <vector>

template <class T>
class BinaryIndexedTree {
    private:
        std::vector<T> biTree = {0};
        int len;
        inline int lowbit (int x) {
            return x & (-x);
        }
    
    public:
        BinaryIndexedTree (std::vector<T> input_list);
        //idx is the index of the input_list
        void update (int idx, T delta);
        //including idx
        T prefixSum (int idx);
        //including from_idx and to_idx
        T rangeSum (int from_idx, int to_idx);
};

template <class T>
BinaryIndexedTree<T>::BinaryIndexedTree (std::vector<T> input_list){
    for (auto &c : input_list) {
        biTree.push_back(c);
    }
    len = biTree.size();
    for (int i = 1; i < len; ++i) {
        int j = i + lowbit(i);
        if ( j < len ) {
            biTree[j] += biTree[i];
        }
    }
}

template <class T>
void BinaryIndexedTree<T>::update (int idx, T delta) {
    idx += 1;
    while (idx < len) {
        biTree[idx] += delta;
        idx += lowbit(idx);
    }
}

template <class T>
T BinaryIndexedTree<T>::prefixSum (int idx) {
    idx += 1;
    T result;
    while (idx > 0) {
        result += biTree[idx];
        idx -= lowbit(idx);
    }
    return result;
}

template <class T>
T BinaryIndexedTree<T>::rangeSum(int from_idx, int to_idx) {
    T result = prefixSum(to_idx) - prefixSum(from_idx - 1);
    return result;
}

#endif
