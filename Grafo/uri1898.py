def isNum(character):
	if(character == '0' or character == '1' or character == '2' or character == '3' or character == '4' or character == '5' or character == '6' or character == '7' or character == '8' or character == '9'):
		return True
	else:
		return False

line1 = input()
cpf = ""
value1 = ""
index = 0
ponto = False
for i in range(len(line1)):
	if(isNum(line1[i])):
		if(index < 11):
			cpf += line1[i]
			index += 1
		else:
			value1 += line1[i]
	elif(line1[i] == '.' and not ponto):
		value1 += line1[i]
		ponto = True
	elif(line1[i] == '.' and ponto):
		break

line2 = input()
value2 = ""
ponto = False
for i in range(len(line2)):
	if(isNum(line2[i])):
		value2 += line2[i]
	elif(line2[i] == '.' and not ponto):
		value2 += line2[i]
		ponto = True
	elif(line2[i] == '.' and ponto):
		break

print("cpf " + cpf)
value = 0.0
if(value1 != ""):
	value += float(value1)
if(value2 != ""):
	value += float(value2)
print("%.2f"%(value))