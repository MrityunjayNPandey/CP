def util(val):
    high, endd = 0, 32
    for i in range(endd):
        if not ((1 << i) - val):
            high=i
            break
        if not ((1 << i) & val) - (1 << i):
            high = i+1
            if val == i:
                high -= 1
    return high + 1
tcs = int(input())
while tcs:
    x, y = map(int, input().split())
    if util(x) > y:
        print(str(0))
    else:
        print(str(y - util(x) + 1))
    tcs -= 1