lower_num = int(input())

upper_num = int(input())

print("Prime numbers between", lower_num, "and", upper_num, "are:")

for num in range(lower_num, upper_num + 1):
   if num > 1:
       for i in range(2, num):
           if (num % i) == 0:
               break
       else:
           print(num)
