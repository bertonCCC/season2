from sys import stdin

line = stdin.readline().strip()
N, M = line.split()

N = int(N)
M = int(M)

line = stdin.readline().strip()
words = line.split()

hs = set()
ans = set()

for word in words:
    hs.add(word)

line = stdin.readline().strip()
words2 = line.split()

for word in words2:
    if word in hs:
        ans.add(word)

print(len(ans))
