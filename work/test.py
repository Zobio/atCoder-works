s = input()
move = 10 ** 100 % ((len(s) - 1) * 2)
print(move)
if move > len(s) - 1:
	reverse = True
else:
	reverse = False
ans = [0] * len(s)
for a in range(len(s)):
	if s[a] == 'R':
		if not reverse:
			direction = a + move
			print('a')
		else:
			direction = a - move
			print('b')
	else:
		if not reverse:
			direction = a - move
			print('c')
		else:
			direction = a + move
			print('d')
	if direction > len(s) - 1:
		direction = 2 * (len(s) - 1) - direction
	if direction < 0:
		direction = -direction
	print(direction)
	ans[direction] += 1

for a in ans:
	print(f'{a} ', end='')
print()