seq = input().split()
par_anterior = False
resultado = "ok";

for i in seq:
	e = int(i)
	if par_anterior == True and e % 2 == 1:
		resultado = "erro"
	else:
		if e % 2 == 0:
			par_anterior = True;
		else:
			par_anterior = False;
print (resultado)
