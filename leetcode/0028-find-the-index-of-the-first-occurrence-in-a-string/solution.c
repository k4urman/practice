int strStr(char *haystack, char *needle) {
    if (*needle == '\0') {
        return 0;
    }

    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j = 0;
        for (; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i;
        }
    }
    return -1;
}
