import heapq

class Graph:
	def __init__(self, v):
		self.v = v
		self.matrix = []

		for i in range(v):
			lista = []
			for j in range(v):
				lista.append(0)
			self.matrix.append(lista)

	def addEdge(self, u, v):
		self.matrix[u][v] = self.matrix[v][u] = 1


	def dijkstra(self, de, para):
		distance = [4004] * self.v
		distance[de] = 0
		queue = []
		heapq.heappush(queue, (0, de))
		while(queue):
			weight, u = heapq.heappop(queue)
			#print(str(weight) + " " + str(u))
			for i in range(self.v):
				if(self.matrix[u][i] == 1 and distance[i] > weight + 1):
					distance[i] = weight + 1
					heapq.heappush(queue, (distance[i], i))
		return distance[para]


v, e = map(int, input().split())
g = Graph(v)
dictionary = {}
index = 0
for i in range(e):
	u, v = input().split()
	if(dictionary.get(u, -1) == -1):
		dictionary[u] = index
		index += 1
	if(dictionary.get(v, -1) == -1):
		dictionary[v] = index
		index += 1
	g.matrix[dictionary[u]][dictionary[v]] = g.matrix[dictionary[v]][dictionary[u]] = 1

print(g.dijkstra(dictionary['Entrada'], dictionary['*']) + g.dijkstra(dictionary['*'], dictionary['Saida']))