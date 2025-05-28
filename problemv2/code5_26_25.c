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
