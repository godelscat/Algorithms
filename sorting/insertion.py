def insert_sorting(arr):
    for j in range(1, len(arr)):
        key = arr[j]
        i = j -1
        while i >= 0 and arr[i] > key:
            arr[i+1] = arr[i]
            i = i-1
        arr[i+1] = key

testArr = [5, 2, 3, 7, 1]

insert_sorting(testArr)
print(testArr)
