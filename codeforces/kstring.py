from collections import Counter
import sys

def solve():
    lines = sys.stdin.read().splitlines()
    if not lines:
        return
    
    k = int(lines[0])
    s = lines[1]
    
    if len(s) % k != 0:
        print("-1")
        return

    counts = Counter(s)

    for char, count in counts.items():
        if count % k != 0:
            print("-1")
            return

    result = "".join(char * (count // k) for char, count in counts.items()) * k
    print(result)

if __name__ == "__main__":
    solve()

