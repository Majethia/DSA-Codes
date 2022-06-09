ops = {"+": lambda x,y: x+y, "-": lambda x,y: x-y}


def make_matrix():
    matrix = []
    while True:
        try:
            rows = int(input("Number of Rows: "))
            if rows != 0:
                break
            print("Number of rows or cols cant be 0")
        except ValueError:
            print("Please type a valid int.")

    while True:
        try:
            cols = int(input("Number of Cols: "))
            if cols != 0:
                break
            print("Number of rows or cols cant be 0")
        except ValueError:
            print("Please type a valid int.")

    # rows = int(input("Number of Rows: "))     # Above part is error handling for invalid input
    # cols = int(input("Number of Cols: "))     # Same result as this if input is correct

    for i in range(rows):
        matrix.append([])
        for j in range(cols):
            while True:
                try:
                    value = int(input(f"Value at position ({i+1}, {j+1}): "))
                    break
                except ValueError:
                    print("Please type a valid int.")

            # value = int(input(f"Value at position ({i+1}, {j+1}): "))     # Again, error handling for invalid inputs
            matrix[i].append(value)
    return matrix

def check_upper_triangular(matrix):
    if len(matrix) == 1:
        return False
    for i in range(len(matrix[0])):
        for j in range(len(matrix)):
            if i > j:
                if matrix[i][j] != 0:
                    return False
    return True

def sum_of_diagnol(matrix):
    res = 0
    for i in range(min(len(matrix[0]), len(matrix))):
        res = res + matrix[i][i]
    return res

def transpose_of_matrix(matrix):
    res = []
    for i in range(len(matrix[0])):
        temp = []
        for j in range(len(matrix)):
            temp.append(matrix[j][i])
        res.append(temp)
    return res

def add_matrix(m1, m2, operation):
    if len(m1) != len(m2) or len(m1[0]) != len(m2[0]):
        return f"Cant solve {operation} matrix of diffrent sizes"

    res = []
    for i in range(len(m1)):
        temp = []
        for j in range(len(m1[0])):
            s = ops[operation](m1[i][j], m2[i][j])
            temp.append(s)
        res.append(temp)
    return res

def multiply_matrix(m1, m2):
    if len(m1[0]) != len(m2):
        return "Cant multiply matrix of these sizes"
    
    res = []
    for i in range(len(m1)):
        temp = []
        for j in range(len(m2[0])):
            s = 0
            for k in range(len(m1[0])):
                s += m1[i][k]*m2[k][j]
            temp.append(s)
        res.append(temp)
    return res

def main():
    print("First Matrix")
    m1 = make_matrix()
    print("")
    for i in m1:
        print(i)
    print("\n")

    print("Second Matrix")
    m2 = make_matrix()
    print("")
    for i in m2:
        print(i)
    print("\n")

    print(f"First matrix is upper triangular: {check_upper_triangular(m1)}")
    print(f"Second matrix is upper triangular: {check_upper_triangular(m2)}\n")

    print(f"Sum of diagnol of first matrix: {sum_of_diagnol(m1)}")
    print(f"Sum of diagnol of second matrix: {sum_of_diagnol(m2)}\n")

    add = add_matrix(m1, m2, "+")
    if type(add) == str:
        print(f"{add}\n")

    else:
        print(f"Addition of the two matrix:")
        for i in add:
            print(i)
        print("\n\n")

    sub = add_matrix(m1, m2, "-")
    if type(sub) == str:
        print(f"{sub}\n")

    else:
        print(f"Subtraction of the two matrix:")
        for i in sub:
            print(i)
        print("\n\n")

    mul = multiply_matrix(m1, m2)
    if type(mul) == str:
        print(f"{mul}\n")

    else:
        print(f"Multiplication of the two matrix:")
        for i in mul:
            print(i)

if __name__ == "__main__":
    main()

