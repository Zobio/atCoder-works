k, x = map(int, input().split())
if x - k + 1 < -1000000:
	start = -1000000
else:
	start = x - k + 1
if x + k - 1 > 1000000:
    end = 1000000
else:
	end = x + k - 1
for a in range(start, end + 1):
	print(f'{a} ', end = '')
print()