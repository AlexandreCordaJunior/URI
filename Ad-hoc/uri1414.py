while(True):
	t, n = map(int, input().split(' '))
	if(t == 0 and n == 0):
		break

	total = 3 * n
	cont = 0

	for i in range(t):
		time, pontos = input().split(' ')
		pontos = int(pontos)
		cont += pontos
	print(total - cont)