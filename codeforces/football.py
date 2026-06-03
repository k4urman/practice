import sys

def main():
    input = sys.stdin.read().split()

    if not input:
        return

    n = int(input[0])
    x = input[1]
    y = ""

    team1 = 1
    team2 = 0

    for i in range(2, n+1):
        curr = input[i]
        if curr == x:
            team1 += 1
        else:
            y = curr
            team2 += 1

    if team1 > team2:
        print(x)
    else:
        print(y)

    
    if __name__ == '__main__':
        main()


