n = int(input())
a = map(int, input().split())
sum = 0
ave = 0.0
for i in range(n):
	sum += a[i]
	ave += a[i] / n
print(sum, ave)