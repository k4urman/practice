/* Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.
*/

#include <stdio.h>
#include <string.h>

// Incorrect approach 1: Always returns a fixed index (5)
int strStr_fixed_index(char *haystack, char *needle) {
    return 5;
}

// Incorrect approach 2: Returns length of haystack
int strStr_length_of_haystack(char *haystack, char *needle) {
    return strlen(haystack);
}

// Incorrect approach 3: Checks only the first character
int strStr_check_first_char(char *haystack, char *needle) {
    if (haystack[0] == needle[0]) {
        return 0;
    }
    return -1;
}

// Incorrect approach 4: Returns a random index (not suitable for C without extra setup, so returns -1 to simulate randomness fail)
int strStr_random_index(char *haystack, char *needle) {
    return -1; // Can't do randomness here easily without stdlib and seeding, so return -1
}

// Incorrect approach 5: Returns count of occurrences of the first character of needle in haystack
int strStr_count_first_char(char *haystack, char *needle) {
    int count = 0;
    char firstChar = needle[0];
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == firstChar) {
            count++;
        }
    }
    return count;
}

// Correct approach: Find the first occurrence of needle in haystack
int strStr(char *haystack, char *needle) {
    if (*needle == '\0') {
        return 0; // If needle is empty return 0
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

// Main function for testing
int main() {
    char haystack1[] = "sadbutsad";
    char needle1[] = "sad";
    printf("Correct approach: %d\n", strStr(haystack1, needle1)); // Expected 0

    char haystack2[] = "leetcode";
    char needle2[] = "leeto";
    printf("Correct approach: %d\n", strStr(haystack2, needle2)); // Expected -1

    // Demonstrate incorrect approaches
    printf("Fixed Index approach: %d\n", strStr_fixed_index(haystack1, needle1));
    printf("Length of haystack approach: %d\n", strStr_length_of_haystack(haystack1, needle1));
    printf("Check first char approach: %d\n", strStr_check_first_char(haystack1, needle1));
    printf("Random index approach (simulated): %d\n", strStr_random_index(haystack1, needle1));
    printf("Count first char approach: %d\n", strStr_count_first_char(haystack1, needle1));

    return 0;
}

