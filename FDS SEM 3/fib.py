def fib(n):
    a = 0
    b = 1
    for _ in range(n):
        print(a, end=" ")
        a, b = b, a+b


fib(int(input("print fibonachi series till: ")))

def fsearch(target, l):
    n = len(l)
    f1 = 0
    f2 = 1
    f = 1

    while n >= f:
        f2 = f1
        f1 = f
        f = f1 + f2

    offset = -1

    while (f > 1):
        i = min(offset + f2, n - 1)
        if (l[i] < target):
            f = f1
            f1 = f2
            f2 = f - f1
            offset = i

        elif (l[i] > target):
            f = f2
            f1 = f1 - f2
            f2 = f - f1

        else:
            return f"{target} found in the list at position {i}"
 
    if(f1 and l[n-1] == target):
        return f"{target} found in the list at position {n-1}"
    return f"{target} Not found in the list"