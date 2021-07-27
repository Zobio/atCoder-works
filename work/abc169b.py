n = int(input())
li = []
li = list(map(int, input().split()))
li.sort()
ans = 1
ma = 1000000000000000000
for b in range(n):
	ans = ans * li[b]
	if ans > ma:
		print(-1)
		exit()
print(ans)