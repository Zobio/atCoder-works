n, l = map(int, input().split())
k = int(input())
a = list(map(int, input().split()))
a.append(l)

L = -1
R = 50000000000

while R - L > 1:
	mid = L + R >> 1

	cur = 0
	cnt = 0

	for i in range(n + 1):
		if a[i] - cur >= mid:
			cnt = cnt + 1
			cur = a[i]
	
	if cnt >= k + 1:
		L = mid
	else:
		R = mid

print(L)