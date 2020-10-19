def QuadS(a,b,c):
	d=pow(b,2)-(4*a*c)
	if d>=0:
		print("Real solution exist-")
		print(((-b)+pow(d,0.5))/(2*a),((-b)-pow(d,0.5))/(2*a))
	else:print("No real solution exist.")
x,y,z=map(int,input('Enter the coeficients of x\u00b2 ,x and constant term-\n').split())
QuadS(x,y,z)