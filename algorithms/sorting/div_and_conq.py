#r is the index of the last element in list
def MERGE(arr, p, q, r):
    s1 = q - p + 2
    s2 = r - q + 1
    L = arr[p:q+1]
    R = arr[q+1:r+1]
    L_MAX = R_MAX = 1000
    L.append(L_MAX)
    R.append(R_MAX)
    i = j = 0
    for k in range(p, r+1):
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
        else :
            arr[k] = R[j]
            j += 1

def MERGE_SORT(arr, p, r):
    if p < r:
        q = (p + r) // 2
        MERGE_SORT(arr, p ,q)
        MERGE_SORT(arr, q+1, r)
        MERGE(arr, p, q, r)

testList = [3,2,5,1,4]
MERGE_SORT(testList, 0, len(testList)-1)
print(testList)
