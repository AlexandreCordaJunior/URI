cont = 0

class Graph:
	def __init__(self, v):
		self.v = v
		self.matrix = []
		for i in range(v):
			lista = []
			for j in range(v):
				lista.append(0)
			self.matrix.append(lista)

	def dfs(self, start):
		visited = [False] * self.v
		visited[start] = True
		for i in range(self.v):
			global cont
			if(visited[i] == False and self.matrix[start][i] == 1):
				#print('1' + str(i))
				self.aux(i, visited)
				cont += 1

	def aux(self, start, visited):		
		visited[start] = True
		for i in range(self.v):
			global cont
			if(visited[i] == False and self.matrix[start][i] == 1):
				#print('2' + str(i))
				self.aux(i, visited)
				cont += 1


cases = int(input())
for i in range(cases):
	start = int(input())
	v, e = map(int, input().split())
	g = Graph(v)
	for j in range(e):
		u, v = map(int, input().split())
		g.matrix[u][v] = g.matrix[v][u] = 1
	g.dfs(start)
	print(2 * cont)
	cont = 0
