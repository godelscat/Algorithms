#include <iostream>
#include <vector>
#include "BinaryIndexedTree.h"
using namespace std;

int main ()
{
    vector<int> ivec = {2, 4, 1, 3, 8, 9, 4, 5, 3, 2, 9, 8};
    BinaryIndexedTree<int> bitree(ivec);
    cout << "Sum of the first 6 elements : " 
        << bitree.prefixSum(5) << "\n";
    
    bitree.update(3, 6);
    cout << "after update: " << bitree.prefixSum(5) << "\n";

    return 0;
}
