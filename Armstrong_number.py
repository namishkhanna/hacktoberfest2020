#Program to check whether the number is an armstrong number or not
#Ask user to enter the number
number=int(input("Enter the number you want to check armstrong:  "))

order=len(str(number))

#Initialise sum to 0
sum=0

temp=number
while temp>0:
    num=temp%10
    sum+=num**order
    temp//=10

if (number==sum):
    print("The number you have entered is an Armstrong number.")
else:
    print("The number you have entered is not an Armstrong number.")



