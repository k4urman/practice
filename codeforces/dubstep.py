import sys

def main():
    text = sys.stdin.read().strip()
    if text:
        print(" ".join(text.replace("WUB", " ").split()))

if __name__ == "__main__":
    main()

    
