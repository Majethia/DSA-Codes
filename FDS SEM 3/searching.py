def lsearch(target, l):
    for n, i in enumerate(l):
        if i == target:
            return f"{target} found in the lsit at position {n}"
    return f"{target} Not found in the lsit"


def ssearch(target, l):
    l1 = list(l)
    l1.append(target)
    i = 0
    while l1[i] != target:
        i+= 1
    if i == len(l):
        return f"{target} Not found in the list"
    return f"{target} found in the list at position {i}"


def bsearch(target, l):
    l1 = list(l)
    while len(l1) > 2:
        if l1[int(len(l1)/2)] == target:
            return f"{target} found in the list at position {int(len(l1)/2)}"
        elif l1[int(len(l1)/2)] > target:
            l1 = l1[int(len(l1)/2):]
        else:
            l1 = l1[:int(len(l1)/2)]
    return f"{target} Not found in the list"


def fib_search(target, l):
    fib = [0,1,1,2,3,5,8,13,21,34,55,89]
    for x in range(len(fib)):
        if len(l) < fib[x]:
            break
    offset = -1
    f = fib[x-2]
    while f > 1:
        f = fib[x-2]
        i = min(fib[x-3] + offset, len(l) - 1)
        if l[i] > target:
            x = x-1
        elif l[i] < target:
            x = x-2
        else:
            return f"{target} found in the list at position {i}"


def main():
    students = []
    for _ in range(int(input("Number of sudents: "))):
        students.append(int(input("Rollno of students: ")))
    print(ssearch(35, students))
    print(lsearch(35, students))
    print(fib_search(35, students))


# main()

