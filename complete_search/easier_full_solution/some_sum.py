n = int(input())

even = False
odd = False
for i in range(1, 100 + 1):
    if i + n - 1 <= 100:
        sum = (n / 2) * (i + i + n - 1) # could have used a for loop instead
        if sum % 2 == 0:
            even = True
        else:
            odd = True

print("Either" if even and odd else "Even" if even else "Odd")
