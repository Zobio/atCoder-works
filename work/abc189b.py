n, x = map(int, input().split())
v = list()
p = list()
for a in range(n):
	aa, bb = map(float, input().split())
	v.append(aa)
	p.append(bb)
ans = 0
for a in range(n):
	x -= v[a] * p[a] / 100.0
	ans += 1
	if x < 0:
		break
if x < 0:
	print(ans)
else:
	print(-1)