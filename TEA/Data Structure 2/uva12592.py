q = int(input())
ans = []
dicio = {}
for _ in range(q):
    a,b = input(),input()
    dicio[a] = b
p = int(input())
for _ in range(p):
    ans.append(dicio[input()])

print("\n".join(map(str,ans)))
