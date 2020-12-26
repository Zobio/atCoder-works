a, b = map(int, input().split())
if a + b > a - b:
	ans = a + b
else:
	ans = a - b
if a * b > ans:
	ans = a * b
print(ans)