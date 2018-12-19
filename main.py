# 计算理论期望和方差

n=100000
e=[0 for _ in range(n+1)]
e2=e[:]
for i in range(n+1):
    for len in range(2,i+1):
        e[i]+=(i-len+1)*(2/len)
print(e[n])
for i in range(n+1):
    for j in range(0,i):
        e2[i]+=(e2[j]+e2[i-1-j]+(i-1)**2+2*(i-1)*(e[j]+e[i-1-j])+2*e[j]*e[i-1-j])/i
print(e2[n]-e[n]**2)

