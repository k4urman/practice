import sys


def main():
    input = sys.stdin.read().split()

    if not input:
        return

    n = int(input[0])
    m = int(input[1])

    ans = 0

    for a in range(int(n**0.5) + 1):
        for b in range(int(m**0.5) + 1):
            if a * a + b == n and a + b * b == m:
                ans += 1

    print(ans)


if __name__ == "__main__":
    main()

