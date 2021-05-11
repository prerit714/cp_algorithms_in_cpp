import math
import collections

x = 'acbcf'
y = 'abcdaf'
m = 0
n = 0
t = {}


def print_lcs():
    s = ''
    i = m
    j = n
    while i>0 and j>0:
        if x[i-1]==y[j-1]:
            s += x[i-1]
            i -= 1
            j -= 1
        elif t[(i, j-1)]>=t[(i-1, j)]:
            j -= 1
        else:
            i -= 1
    print(''.join(reversed(s)))

def lcs():
    global m, n
    m = len(x)
    n = len(y)
    for i in range(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                t[(i, j)] = 0
            else:
                t[(i, j)] = -math.inf
    for i in range(1, m+1):
        for j in range(1, n+1):
            if x[i-1]==y[j-1]:
                t[(i, j)] = 1+t[(i-1, j)]
            else:
                t[(i, j)] = max(t[(i-1, j)], t[(i, j-1)])
    print(t[(m, n)])


def main():
    lcs()
    print_lcs()


if __name__=='__main__':
    main()

