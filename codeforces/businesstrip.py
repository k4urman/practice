import sys

def main():
    input_data = sys.stdin.read().split()

    if not input_data:
        return

    k = int(input_data[0])
    a = [int(x) for x in input_data[1:]]

    a.sort(reverse=True)

    total = 0
    count = 0

    if k == 0:
        print(0)
        return

    for i in a:
        total += i
        count += 1
        if total >= k:
            print(count)
            return

    print(-1)

if __name__ == '__main__':
    main()


