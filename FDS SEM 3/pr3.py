def union(a, b):
    res = list(a)  # res = a   will update both lists and break code for later
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
    a = [1,2,3,4,5,6,14,15,16]
    b = [2,4,6,8,10,11,17,18,19]
    c = [6,7,8,9,10,12,13,14,15]

    # a = []
    # b = []
    # c = []

    # for _ in range(int(input("How many want to play cricket: "))):
    #     a.append(int(input("Roll numbers: ")))
    # for _ in range(int(input("How many want to play batminton: "))):
    #     b.append(int(input("Roll numbers: ")))
    # for _ in range(int(input("How many want to play football: "))):
    #     c.append(int(input("Roll numbers: ")))

    print(f"Both Cricket and Badminton: {union(a, b)}")
    print(f"Cricket or batminton but not both: {eiter_or(a, b)}")
    print(f"Neitner cricket not football: {minus(minus(b, a), c)}")
    print(f"Cricket and football but not batminton: {minus(intersect(a, c), b)}")

if __name__ == "__main__":
    main()

