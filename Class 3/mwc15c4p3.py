from sys import stdin

def get():
    return stdin.readline().strip().split()

def geti():
    return list(map(int, stdin.readline().strip().split()))

N, Q = geti()
hs = set()
xmap = {}
ymap = {}

for i in range(N):
    x, y = geti()

    hs.add((x, y))

    if x in xmap:
        xmap[x] += 1
    else:
        xmap[x] = 1

    if y in ymap:
        ymap[y] += 1
    else:
        ymap[y] = 1

for i in range(Q):
    line = get()

    if int(line[0]) == 1:
        x = int(line[1])
        y = int(line[2])

        if (x, y) in hs:
            print('salty')
        else:
            print('bland')
    else:
        subtype = line[1]
        if subtype == 'X':
            x = int(line[2])
            if x in xmap:
                print(xmap[x])
            else:
                print(0)
        else:
            y = int(line[2])
            if y in ymap:
                print(ymap[y])
            else:
                print(0)
