def printa(a,b,n):
    if len(b) == 4: b = "0"+b
    print(a+" / "+b+" = "+n)
    
def val(a,b):
    n = a//b
    if b < 10000: b = "0"+str(b)
    confere,conta = "0123456789", 0
    for j in confere:
        if j in str(a) or j in str(b): conta+=1;
    if conta == 10: return 1
    return 0
        
def solve(n):
    sol,a = 0,0
    for b in range(1234,100000//n+1):
        a = b*n
        if val(a,b):
            printa(str(a),str(b),str(n))
            sol+=1
    if sol == 0: print("There are no solutions for "+str(n)+".")
linha = 0
while 1:
    n = int(input())
    if n == 0: break
    if linha == 1: print()
    solve(n)
    linha = 1
