# You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

int characterReplacement(char* s, int k) {
    int freq[26] = {0};

    int left = 0;
    int maxFreq = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {


        freq[s[right] - 'A']++;


        if (freq[s[right] - 'A'] > maxFreq) {
            maxFreq = freq[s[right] - 'A'];
        }

       
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        
        int windowSize = right - left + 1;

        if (windowSize > maxLen) {
            maxLen = windowSize;
        }
    }

    return maxLen;
}
