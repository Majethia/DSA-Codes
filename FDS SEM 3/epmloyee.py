while True:
    name = input("Name of employee: ")
    while True:
        post = input("Designation: ")
        if post in ["Manager", "Leader", "Member"]:
            break
        print("Thats not a valid job Designation at this workplace, please try again")

    while True:
        try:
            days = int(input("Days worked: "))
            if 0 < days <= 31:
                break
            else:
                print("Days worked cant exceed 31 days")

        except ValueError:
            print("Please enter a valid number.")

    while True:
        try:
            overtime = int(input("Overtime worked: "))
            if days <= 10:
                break
            else:
                print("Overtime cant exceed 10 days")
        except ValueError:
            print("Please enter a valid number.")
    
    overtime = overtime/2
    salary_dict = {"Manager": 2000, "Leader": 1800, "Member": 1000}
    
    statement = f"\n\n-----------------------\nStatement of salary\nEmployee: {name}\nDesignation: {post}\nSalary due: {(days + overtime) * salary_dict[post]}\n-----------------------\n"
    print(statement)
    if input("\nY to continue or anything else to exit: ") != "y":
        break
