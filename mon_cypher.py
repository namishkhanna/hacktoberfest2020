W = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
 '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
UW = ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
 '5', '9', '6', '7','8', '1', '2', '3','0', '4']
def en(va):
 c = []
 for i in range(len(va)):
 for j in range(len(W)):
 if va[i].lower() == W[j]:
 c.append(UW[j])
 break
 return ''.join(c)
def dc(va):
 p1 = []
 for i in range(len(va)):
 for j in range(len(UW)):
 if UW[j] == va[i]:
 p1.append(W[j])
 return ''.join(p1)
mg = input("Please enter a message: ")
option = input("Would you like to encrypt or decrypt")
while not (option == "e" or option == "d" or option == "E" or option == "D"):
 option = input("Invalid option, enter again: ")
if option == "e" or option == "E":
 print(en(mg))
else:
 print(dc(mg))
