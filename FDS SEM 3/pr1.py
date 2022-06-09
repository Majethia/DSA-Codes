def sum_of_list(l):
    sum = 0
    for i in l:
        if i == -999:
            continue
        sum = sum + i
    return sum
    

def len_of_list(l):
    for i in l:
        pass
    return i


def find_highest(l):
    highest = -999
    for i in l:
        if i > highest:
            highest = i
    return highest


def find_lowest(l):
    lowest = l[0]
    for i in l:
        if i < lowest:
            lowest = i
    return lowest


def count_frequency(l, mark):
    count = 0
    for i in l:
        if i == mark:
            count = count + 1
    return count


def find_highest_frequency(marks):
    frequency = 0
    highest_frequency = 0
    for i in marks:
        count = count_frequency(marks, i)
        if count > frequency:
            highest_frequency = i
            frequency = count
    return highest_frequency
    

if __name__ == "__main__":
    marks = []
    for i in range(int(input("Total number of students: "))):
        mark = int(input(f"Score of student no {i+1} in FDS: "))
        marks.append(mark)

    print(f"Highest marks: {find_highest(marks)}")
    print(f"Lowest marks: {find_lowest(marks)}")
    print(f"Average marks: {sum_of_list(marks)/(len(marks) - count_frequency(marks, -999))}")
    print(f"No of students absent: {count_frequency(marks, -999)}")
    print(f"Most frequent marks are {find_highest_frequency(marks)}")

    print("Frequency of each of the marks")
    for i in marks:
        print(f"Frequency of {i} is {count_frequency(i)}")

