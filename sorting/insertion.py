def incre_sorting(arr):
    for j in range(1, len(arr)):
        key = arr[j]
        i = j -1
        while i >= 0 and arr[i] > key:
            arr[i+1] = arr[i]
            i = i-1
        arr[i+1] = key

def decre_sorting(arr):
    for j in range(1, len(arr)):
        key = arr[j]
        i = j - 1
        while i >= 0 and arr[i] < key:
            arr[i+1] = arr[i]
            i = i - 1
        arr[i+1] = key

testArr1 = [5, 2, 3, 7, 1]
testArr2 = [5, 2, 3, 7, 1]

incre_sorting(testArr1)
decre_sorting(testArr2)
print(testArr1)
print(testArr2)
