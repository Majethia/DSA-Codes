def union(a, b):
    res = list(a)
    for i in b:
        if i not in a:
            res.append(i)
    return res

def intersect(a,b):
    res = []
    for i in a:
        if i in b:
            res.append(i) 
    return res

def eiter_or(a, b):
    u = union(a, b)
    i = intersect(a, b)
    for value in i:
        u.remove(value)
    return u

def minus(a, b):
    res = list(a)
    for i in b:
        if i in res:
            res.remove(i)
    return res

def main():
    drama = [int(input("Roll number of student: ")) for _ in range(int(input("How many students participated in drama? ")))]
    dance = [int(input("Roll number of student: ")) for _ in range(int(input("How many students participated in dance? ")))]
    singing = [int(input("Roll number of student: ")) for _ in range(int(input("How many students participated in singing? ")))]

    drama_and_dance = union(drama, dance)
    drama_and_dance_but_not_singing = minus(drama_and_dance , singing)
    print(f"The number of students who participated in dance and drama but not singing is {len(drama_and_dance_but_not_singing)}")

    drama_or_singing = eiter_or(drama, singing)
    print(f"List of students who participated in drama or singing but not both: {drama_or_singing}")

    all_students = union(drama_and_dance, singing)
    neither_drama_nor_singing = minus(minus(all_students, drama), singing)
    print(f"List of students who participated netiher in drama nor in singing: {neither_drama_nor_singing}")

if __name__ == "__main__":
    main()

