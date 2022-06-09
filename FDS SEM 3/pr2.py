def calcualte_balance(transaction_log):
    transaction_log = transaction_log.split(",")
    balance = 0
    for i in transaction_log:
        i = i.split()
        amount = int(i[-1])
        if i[0] == "D":
            balance = balance + amount

        elif i[0] == "W":
            if balance - amount > 0:
                balance = balance - amount
            else:
                return f"Transaction failed, {balance} left and you tried to withdraw {amount}"
    return balance


print(calcualte_balance("D 300,D 300,W 200,D 100"))
print(calcualte_balance("D 300,D 300,W 900,D 100"))

