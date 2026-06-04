import sys

def main():
    input = sys.stdin.read().split()

    if not input:
        return

    n = int(input[0])
    m = int(input[1])
    a = [int(x) for x in input[2:]]
    
    total = 0

    a.sort()
    
    for in in range(m):
        if a[i] < 0:
            total += abs(a[i])
        else:
            break

    print(total)


if __name__ == '__main__':
    main()
