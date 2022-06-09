def eliminate_dupes(l):
    res = []
    for i in l:
        if i not in res:
            res.append(i)
    return res

def display_assending(l):
    l.sort()
    for i in l:
        print(f"Name of book: {i[1]}, its cost is {i[0]}")
    
def add_book():
    name = input("Name of the book: ")
    cost = int(input(f"Cost of {name}: "))
    return (cost, name)

def count_500(l):
    count = 0
    for i in l:
        if i[0] >= 500:
            count += 1
    return count

def new_l(l):
    res = []
    for i in l:
        if i[0] < 500:
            res.append(i)
    return res

def main():
    list_of_books = []
    list_of_books.append(add_book())
    list_of_books.append(add_book())
    list_of_books.append(add_book())
    display_assending(list_of_books)
    print(f"No of books with cost more than or equal to 500: {count_500(list_of_books)}")

if __name__ == "__main__":
    main()

