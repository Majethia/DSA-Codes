def length_str(s):
    count = 0
    for _ in s:
        count = count+1
    return count

def longest_len(s):
    l = s.split()
    count = len(l[0])
    res = l[0]
    for i in l:
        if len(i) > count:
            count = len(i)
            res = i
    return(res, count)

def find_freq(s, char):
    count = 0
    for i in s:
        if i == char:
            count += 1
    return count

def check_palindrome(s):
    if s == s[::-1]:
        return True
    return False

def find_appearance(s, subs):
    if subs in s:
        s = s.split(subs)
        return len(s[0])
    
def frequency_word(s, word):
    l = s.split()
    count = 0
    res = l[0]
    for i in l:
        if word == i:
            count += 1
            res = i
    return(res, count)

def main():
    s = input("Your string: ")
    word = input("Word: ")
    print(f"Frequency of {word} in given string is {frequency_word(s, word)[1]}")
    print(f"It appears first at index {find_appearance(s, word)}")
    print(f"Given string is a palindrome: {check_palindrome(s)}")

if __name__ == "__main__":
    main()
