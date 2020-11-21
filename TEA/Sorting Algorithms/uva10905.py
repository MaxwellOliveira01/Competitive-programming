def comp(a,b):
    if a+b > b+a: return 1
    return 0


def s(arr):
    troca = 5
    for f in range(len(arr)-1,-1,-1):
        for c in range(0,f,1):
            if comp(arr[f],arr[c]): continue;
            else:
                arr[f],arr[c] = arr[c],arr[f]
                troca = 1
    return arr[::-1]
        

while int(input()):
    print("".join(map(str,s(input().split()))))
