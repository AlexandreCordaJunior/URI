import heapq

def inv(i):
	string = str(i)
	inverso = string[::-1]
	return int(inverso)

vector = []
distance = [float(99999999)] * 10010

def inicio():
	global vector
	for i in range (10010):
		vector.append([])
	for i in range (10010):
		vector[i].append(i + 1)
		vector[i].append(inv(i))

def dijkstra(source):
	global vector
	global distance
	distance[source] = 0
	q = []
	heapq.heappush(q, (0, source))
	while q:
		distancia, v = heapq.heappop(q)
		if(v < 10010):
			for i in range(len(vector[v])):
				newDistance = vector[v][i]
				if(newDistance < 10010 and distance[newDistance] > distancia + 1):
					distance[newDistance] = distancia + 1
					heapq.heappush(q, (distance[newDistance], newDistance))

cases = int(input())
inicio()
for i in range(cases):
	de, para = map(int, input().split())
	dijkstra(de)
	print(distance[para])
	distance = [999 for i in range(10010)]
