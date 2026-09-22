# Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

int* findAnagrams(char* s, char* p, int* returnSize) {
    int freqP[26] = {0};
    int freqS[26] = {0};

    int n = strlen(s);
    int m = strlen(p);

    int* ans = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;

    if (m > n)
        return ans;


    for (int i = 0; i < m; i++) {
        freqP[p[i] - 'a']++;
    }


    for (int i = 0; i < n; i++) {


        freqS[s[i] - 'a']++;


        if (i >= m) {
            freqS[s[i - m] - 'a']--;
        }


        if (i >= m - 1) {
            int same = 1;

            for (int j = 0; j < 26; j++) {
                if (freqS[j] != freqP[j]) {
                    same = 0;
                    break;
                }
            }

            if (same) {
                ans[*returnSize] = i - m + 1;
                (*returnSize)++;
            }
        }
    }

    return ans;
}
