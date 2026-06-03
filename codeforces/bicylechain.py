import sys

def main():
    input = sys.stdin.read().split()

    if not input:
        return
    
    n = int(input[0])
    a = [int(x) for x in input[1:n+1]]
    m = int(input[n+1])
    b = [int(x) for x in input[n+2:n+2+m]]

    max = 0
    count = 0

    for x in a:
        for y in b:
            if y % x == 0:
                ratio = y // x

                if ratio > max:
                    max = ratio
                    count = 1
                elif ratio == max:
                    count += 1

    print(count)

if __name__ == '__main__':
    main()
