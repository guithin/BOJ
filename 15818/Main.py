n=list(map(int, input().split()))

a=1
inp=list(map(int, input().split()))

for i in range(n[0]):
    a=a*inp[i]

print(a%n[1])