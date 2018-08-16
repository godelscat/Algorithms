def fib_normal (n) :
    if n <= 2 :
        return 1
    result = fib_normal(n-1) + fib_normal(n-2)
    return result

def fib_memoize (n, lt):
    if n <= 2 :
        return 1
    if lt[n-1] != None :
        result = lt[n-1]
    else :
        result = fib_memoize(n-1, lt) + fib_memoize(n-2, lt)
    lt[n-1] = result
    return result

def fib_bottom_up (n):
    if n <= 2 :
        return 1
    lt = [None] * n
    lt[0] = 1
    lt[1] = 1
    for i in range(2,n) :
        lt[i] = lt[i-1] + lt[i-2]
    return lt[n-1]


if __name__ == "__main__" : 
    print(fib_normal(20))
    lt = [None] * 20;
    print(fib_memoize(20, lt))
    print(fib_bottom_up(20))
