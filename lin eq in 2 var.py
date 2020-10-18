print(" \nax+by=c")
print("dx+ey=f \n ")
A=int(input("enter the value of a"))
B=int(input("enter the value of b"))
C=int(input("enter the value of c"))
D=int(input("enter the value of d"))
E=int(input("enter the value of e"))
F=int(input("enter the value of f"))
G=A*E-B*D
H=C*E-B*F
I=A*F-C*D
print(" \n  the required equations are ",A,"x +",B,"y =",C)
print("                             ",D,"x +",E,"y =",F)
print(" \n  x is equal to ",H/G)
print("  y is equal to ",I/G)