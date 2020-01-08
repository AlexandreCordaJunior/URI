while(True):
	try:
		str = input()
		lista = str.split(' ')
		qtd = 0
		last = lista[0][0].lower()
		conseq = False
		for i in range(1, len(lista)):
			if(lista[i][0].lower() == last):
				if(not conseq):
					qtd += 1
					conseq = True
			else:
				conseq = False
			last = lista[i][0].lower()
		print(qtd)
	except:
		break
