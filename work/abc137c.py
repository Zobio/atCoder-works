n = int(input())
ls = list()
for a in range(n):
	word = sorted(input())
	if not word in ls:
		ls.append(word)
	