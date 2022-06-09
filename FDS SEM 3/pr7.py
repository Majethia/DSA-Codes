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

def matrix_to_sparse(matrix):
    res = []
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] != 0:
                res.append([i,j,matrix[i][j]])
    return res

def sparse_addition(sparse1, sparse2):
    if len(sparse1) > len(sparse2):
        longer = sparse1
        shorter = sparse2
    else:
        longer = sparse2
        shorter = sparse1

    res = list(longer)
    for i in range(len(shorter)):
        if sparse1[i][0:2] == sparse2[i][0:2]:
            res[i][-1] = sparse1[i][-1] + sparse2[i][-1]
        else: 
            res.append(shorter[i])
    res.sort()
    return res

def sparse_transpose(s):
    res = []
    for i in s:
        res.append([i[1], i[0], i[2]])
    return res

[(1, 1, 6), (0, 2 , 4)]  [(1,3,5), (1, 1, 3)]
[(1,1,9) (0, 2 , 4) (1,3,5)]
