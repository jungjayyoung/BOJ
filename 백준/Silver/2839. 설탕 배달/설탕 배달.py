n = int(input())

five_bag = n // 5
three_bag = n // 3
is_true=False
for i in range(five_bag,-1,-1):

    for j in range(0,three_bag +1):
        if (5 * i)+(3 * j) == n:
            print(i+j)
            is_true =True
            break
        elif (5 * i)+(3 * j) > n:
            break
    if is_true:
        break
if(not is_true):
    print(-1)