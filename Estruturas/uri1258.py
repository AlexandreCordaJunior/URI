class pedido:
	def __init__(self, nome, cor, tamanho):
		self.nome = nome
		self.cor = cor
		self.tamanho = tamanho

first = True
while(True):

	casos = int(input())
	if(casos == 0):
		break
	if(not first):
		print()
	first = False
	vet = []
	for i in range(casos):
		nome = input()
		cor, tamanho = input().split()
		p = pedido(nome, cor, tamanho)
		vet.append(p)

	newVet = sorted(sorted(sorted(vet, key = lambda x : x.nome), key = lambda x: x.tamanho, reverse = True), key = lambda x: x.cor)
	for i in newVet:
		print(i.cor, end=" ")
		print(i.tamanho, end=" ")
		print(i.nome)