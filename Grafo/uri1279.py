caso = False

while(True):
	try:
		
		bi = False
		bu = False
		hu = False

		ano = int(input())
		if(caso):
			print()		
		caso = True
		if(ano % 400 == 0):
			bi = True
		else:
			if(ano % 4 == 0 and not (ano % 100 == 0)):
				bi = True
		if(ano % 15 == 0):
			hu = True
		if(ano % 55 == 0 and bi):
			bu = True

		if(bi):
			print('This is leap year.')
		if(hu):
			print('This is huluculu festival year.')
		if(bu):
			print('This is bulukulu festival year.')
		if(not(bi) and not(bu) and not(hu)):
			print('This is an ordinary year.')
	except:
		break
