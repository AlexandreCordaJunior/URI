while(True):
	try:
		string = input()
		error = False

		temp = ""
		if(string == ""):
			error = True
		else:
			temp = ""
			for i in range(len(string)):
				if(string[i] == 'o' or string[i] == 'O'):
					temp += '0'
				else:
					if(string[i] == '0' or string[i] == '1' or string[i] == '2' or
						string[i] == '3' or string[i] == '4' or string[i] == '5' or
						string[i] == '6' or string[i] == '7' or string[i] == '8' or
						string[i] == '9'):
						temp += string[i]
					else:
						if(string[i] == 'l'):
							temp += '1'
						else:
							if(string[i] != ',' and string[i] != ' '):
								error = True
								break
		if(len(temp) > 10):
			error = True
		else:
			if(not error):
				num = int(temp)
				if(num > 2147483647):
					error = True
		if(error):
			print("error")
		else:
			print(int(temp))
	except:
		break