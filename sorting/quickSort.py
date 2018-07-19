import random 

def Partition (lst, p, r):
    x = random.randint(p, r)
    lst[r], lst[x] = lst[x], lst[r]
    pivot = lst[r]
    i = p 
    for j in range(p, r):
        if lst[j] <= pivot:
            lst[i], lst[j] = lst[j], lst[i]
            i += 1
    lst[i], lst[r] = lst[r], lst[i]
    return i

def QuickSort (lst, p, r):
    if p < r:
        q = Partition (lst, p, r)
        QuickSort (lst, p, q-1)
        QuickSort (lst, q+1, r)

testLst = [2,3,1,4,7,5]
QuickSort (testLst, 0, len(testLst)-1)
print (testLst)
