s = input()
flag = True
for i in range(len(s)):
	if(i == 0):
		flag &= s[i] == '<'
	elif(0 < i < len(s) - 1):
		flag &= s[i] == '='
	else:
		flag &= s[i] == '>'
print("Yes" if flag else "No")
