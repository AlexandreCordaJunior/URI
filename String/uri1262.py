while(True):
	try:
		string = input()
		num = int(input())

		temp = ""
		vet = []

		for i in range(num):
			temp += "R"
			vet.append(temp)

		vet.reverse()
		for i in range(0, len(vet)):
			string = string.replace(vet[i], "W")

		cont = 0
		for i in range(0, len(string)):
			if(string[i] == "W"):
				cont += 1
		print(cont)


	except:
		break
