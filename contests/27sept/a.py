for Max in range(int(input())):
    MaxSize = int(input())
    MaxArr = list(map(int, input().split()))
    MaxRes = -1
    MaxCtr = 0
    for MaxI in range(MaxSize):
        if MaxI == 0 or MaxArr[MaxI] != MaxArr[MaxI - 1]:
            MaxCtr += 1
            MaxRes = max(MaxRes, MaxArr[MaxI])
    print(MaxRes + MaxCtr)