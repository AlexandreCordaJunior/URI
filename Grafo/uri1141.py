def cultivando(lista, peso, i, num):
    if(peso[i] != 0):
        return peso[i]
    for j in range(i + 1, num):
        max = peso[i]
        if(lista[j].find(lista[i]) != -1):
            #print(lista[j] + " : " + lista[i])
            temp = 1 + cultivando(lista, peso, j, num)
            if(temp > max):
                max = temp
            peso[i] = max
        #print("for : i: " + str(i) + " j: " + str(j))
        #print(str(peso[i]) + " " + str(peso[j]))


    #max = 0
    #for j in range(i + 1, num):
    #    if(peso[j] > max and lista[j].find(lista[i]) != -1):
    #        max = peso[j]
    #print("rec : i: " + str(i))
    #print(str(peso[i]))
    return peso[i]

while(True):
    num = int(input())
    if(num == 0):
        break
    list = []
    peso = []
    for i in range(num):
        string = input()
        list.append(string)
        peso.append(0)
    list = sorted(list, key = lambda x: len(x))

    max = 0
    for i in range(num):
        temp = cultivando(list, peso, i, num)
        if(temp > max):
            max = temp
    #for i in range(len(peso)):
    #    print(peso[i])
    #    print(list[i])
    print(max + 1)
