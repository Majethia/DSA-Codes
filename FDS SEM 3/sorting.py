def bubble(lst):
    l = list(lst)
    changes = True
    while changes:
        changes = False
        for i in range(len(l)-1):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
                changes = True
    return l


def insertion(lst):
    for i in range(1, len(lst)):
        x = lst[i]
        j = i-1
        while j >= 0 and x < lst[j]:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = x
    return lst


def selection(lst):
    for i in range(len(lst)):
        min = i
        for j in range(i+1, len(lst)):
            if lst[min] > lst[j]:
                min = j

        lst[i], lst[min] = lst[min], lst[i]
    return lst


def shell_sort(lst):
    n = len(lst)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = lst[i]
            j = i
            while (j >= gap) and (lst[j - gap] > temp):
                lst[j] = lst[j - gap]
                j = j - gap
            lst[j] = temp
        gap = gap // 2
    return lst


def quick_sort(lst):
    def divide(lst, low, high):
        pivot = lst[low]
        i = low + 1
        j = high
        while True:
            while(i <= j and lst[i] <= pivot):
                i = i+1
            while(i <= j and lst[j] >= pivot):
                j -= 1
            if(j < i):
                break
            else:
                lst[i], lst[j] = lst[j], lst[i]

        lst[low], lst[j] = lst[j], lst[low]
        return j

    low = 0
    high = len(lst) - 1

    def qsort(lst, low, high):
        if(low < high):
            d = divide(lst, low, high)
            qsort(lst, low, d - 1)
            qsort(lst, d + 1, high)
        return lst
    return qsort(lst, low, high)

