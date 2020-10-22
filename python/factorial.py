integer = int(input('Enter an Integer : '))
factorial = 1

if integer < 0 :
	print('Enter a Positive Integer')
elif integer == 0 :
	print('Factorial = 1')
else :
	for i in range(1,integer+1):
		factorial = factorial * i
	print('Factorial = ',factorial)
