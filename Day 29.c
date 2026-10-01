# Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {

    int freq[128] = {0};


    for (int i = 0; t[i] != '\0'; i++) {
        freq[(unsigned char)t[i]]++;
    }

    int count = strlen(t);

    int left = 0;
    int minLen = INT_MAX;
    int start = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        
        if (freq[(unsigned char)s[right]] > 0) {
            count--;
        }

        freq[(unsigned char)s[right]]--;

        
        while (count == 0) {

            int windowLen = right - left + 1;

           
            if (windowLen < minLen) {
                minLen = windowLen;
                start = left;
            }

            
            freq[(unsigned char)s[left]]++;

            
            if (freq[(unsigned char)s[left]] > 0) {
                count++;
            }

            left++;
        }
    }

    // No valid window
    if (minLen == INT_MAX) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }


    char* result = (char*)malloc(minLen + 1);

    strncpy(result, s + start, minLen);
    result[minLen] = '\0';

    return result;
}
