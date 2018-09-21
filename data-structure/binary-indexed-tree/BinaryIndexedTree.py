import numpy as np

class BinaryIndexedTree:

    def _lowbit(self, x):
        return x & (-x)


    def _bulid(self, arr, length):
        for i in np.arange(1, length):
            j = i + self._lowbit(i)
            if j < length:
                arr[j] += arr[i]
        return arr

    def __init__(self, input_arr):
        self.biTree = np.append(np.array([0]), input_arr)
        self.length = self.biTree.size
        self.biTree = self._bulid(self.biTree, self.length)
    

    def update(self, idx, delta):
        idx += 1
        while idx < self.length:
            self.biTree[idx] += delta
            idx += self._lowbit(idx)

    def prefixSum(self, idx):
        idx += 1
        result = 0
        while idx > 0:
            result += self.biTree[idx]
            idx -= self._lowbit(idx)
        return result

    def rangeSum(self, begin, end):
        result = self.prefixSum(end) - self.prefixSum(begin-1)
        return result

    def totalSum(self):
        result = self.prefixSum(self.length - 2)
        return result


if __name__ == "__main__":

    testArr = np.array([2, 4, 1, 3, 8, 9, 4, 5, 3, 2, 9, 8])
    testBIT =  BinaryIndexedTree(testArr)
    print("Sum of the first 6 elements: ")
    print(testBIT.prefixSum(5))

    testBIT.update(3, 6)
    print("after update: ")
    print(testBIT.prefixSum(5))
