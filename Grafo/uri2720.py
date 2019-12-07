class present:
    def __init__(self, id, x, y, z):
        self.id = id
        self.x = x
        self.y = y
        self.z = z


casos = int(input())
for i in range(casos):
    noel, bru = list(map(int, input().split()))
    lista = []
    for j in range(noel):
        id, x, y, z = list(map(int, input().split()))
        pre = present(id, x, y, z)
        lista.append(pre)
    lista.sort(key = lambda x: x.id)
    lista.sort(key = lambda x: x.x * x.y * x.z, reverse = True)
    
    listaBru = []
    for i in range(bru):
        listaBru.append(lista[i])
    listaBru.sort(key = lambda x: x.id)
    for i in listaBru:
        print(i.id, end=" ")
    print()
