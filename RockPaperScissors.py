# Rock Paper Scissors Game in Python

from random import *
l=['R','P','S']
def game(n):
	x = randint(1,3)    
	if (x==1):
		k='Rock'
	if (x==2):
		k='Paper'
	if (x==3):
		k='Scissors'
	if(n==l[0] and (x==3)):
		print("You Win")
		print("Computer: "+ k)
		return ()
	if(n==l[1] and x==1):
		print("You Win")
		print("Computer: "+ k)
		return ()
	if(n==l[2] and x==2):
		print("You Win")
		print("Computer: "+ k)
		return ()
	if(n==l[0] and x==1) or (n==l[1] and x==2) or (n==l[2] and x==3):
		print('Draw')
		print("Computer: "+ k)
		return ()
	else:
		print('You Lose')
		print("Computer: "+ k)
		return ()
print("WELCOME LETS PLAY:")
print("R:Rock")
print("P:Paper")
print("S:Scissors")
name = input("What's your choice?\n ")
if(name in l):
	game(name)
else:
	print("Invalid Choice")

    
