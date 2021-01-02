n = int(input())
w = list()
yet = dict()
for a in range(n):
	now = input()
	if now[0] == '!':
		yet[now] = True
	else:
		w.append(now)
for a in w:
	try:
		if yet['!' + a]:
	 		print(a)
	 		exit()
	except KeyError:
		pass
print('satisfiable')