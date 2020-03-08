casos = 0
while(True):
	num = int(input())
	if(num == 0):
		break
	if(casos != 0):
		print()
	vet = []
	for i in range(num):
		temp = input().split()
		str = ''
		first = True
		for j in temp:
			if(j != ' '):
				if(first):
					str = str + j
					first = False
				else:
					str = str + " " + j
		vet.append(str)


	maxLen = 0
	for i in range(num):
		if(len(vet[i]) > maxLen):
			maxLen = len(vet[i])

	for i in range(num):
		for j in range(maxLen - len(vet[i])):
			print(' ', end="")
		print(vet[i])
	casos += 1
