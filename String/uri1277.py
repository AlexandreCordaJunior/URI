casos = int(input())

for i in range(casos):
	num = int(input())

	pessoas = input().split()
	presencas = input().split()
	prim = True
	for j in range(0, len(presencas)):
		total = 0
		p = 0
		a = 0
		for k in range(0, len(presencas[j])):
			if(presencas[j][k] != 'M'):
				total += 1
				if(presencas[j][k] == 'P'):
					p += 1
				else:
					a += 1
		if(total != 0):
			if(p / total < .75):
				if(not prim):
					print(" ", end = "")
				print(pessoas[j], end = "")
				prim = False
	print()
