import math

class antena:
	def __init__(self, x, y, r, index):
		self.x = x
		self.y = y
		self.r = r
		self.index = index


class Graph:
	def __init__(self, v):
		self.v = v
		self.matrix = []
		self.peso = []
		for i in range(v):
			lista = []
			listaP = []
			for j in range(v):
				lista.append(0)
				listaP.append(99999999)
			self.matrix.append(lista)
			self.peso.append(listaP)
		for i in range(v):
			self.peso[i][i] = 0

	def addEdge(self, x, y, distance):
		self.matrix[x.index][y.index] = 1
		self.peso[x.index][y.index] = distance

	def floyd(self):
		for k in range(self.v):
			for i in range(self.v):
				for j in range(self.v):
					if(self.peso[i][j] > self.peso[i][k] + self.peso[k][j]):
						self.peso[i][j] = self.peso[i][k] + self.peso[k][j]


while(True):
	v = int(input())
	if (v == 0):
		break
	g = Graph(v)
	antenas = []
	for i in range(v):
		x, y, r = map(int, input().split())
		antenas.append(antena(x, y, r, i))
	for i in range(v):
		for j in range(v):
			if(i != j):
				distance = math.sqrt(math.pow(antenas[i].x - antenas[j].x, 2) + math.pow(antenas[i].y - antenas[j].y, 2))
				if(antenas[i].r > distance):
					g.addEdge(antenas[i], antenas[j], distance);

	g.floyd()
	"""
	for i in range(v):
		for j in range(v):
			print(g.peso[i][j], end=' ')
		print()"""
	q = int(input())
	for i in range(q):
		u, v = map(int, input().split())
		distance = g.peso[u - 1][v - 1]
		if(distance == 99999999):
			print(-1)
		else:
			print(int(distance))