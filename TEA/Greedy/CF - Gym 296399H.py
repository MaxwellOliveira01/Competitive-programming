pala = input()
ans,i,j = 0,0,1
control = False

#print(pala[:3],pala[3:5]) 

while i <= len(pala) and j <= len(pala):
    if pala[i:j+1] in pala[:i]:
        j += 1#resposta maior?
        control = True
        #print(i,j)
        continue
    
    elif control:
        control = False
        ans += 1
        i = j
        j += 1
        #print(i,j)
        continue

    ans+=1 #one letter
    i+=1
    j+=1

if control: ans+=1
print(ans)

