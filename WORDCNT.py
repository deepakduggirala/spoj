numTests = int(raw_input())
for i in range(numTests):
	prev = 0
	maximum = count = 1
	data = str(raw_input())
	strings = data.split(' ')
	for s in strings:
		if len(s)>0:
			if prev == len(s):
				count+=1;
				if count > maximum:
					maximum = count
			else:
				count = 1;
				prev = len(s)
	print maximum				
