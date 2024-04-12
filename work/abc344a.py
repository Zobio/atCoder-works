s = input()
flag = True
answer = ""
for i in range(len(s)):
	if s[i] == '|':
		flag = not flag
		continue
	if flag:
		answer = answer + s[i]
print(answer)