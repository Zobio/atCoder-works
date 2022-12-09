n = int(input())
a = list(map(int,input().split()))
a.reverse()
ans = 0
for k in range(n):
	ans = ans + a[k] * (10 ** k)
print(ans % 1000000007)
