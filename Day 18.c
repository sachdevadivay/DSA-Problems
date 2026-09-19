# Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

bool checkInclusion(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    if (n1 > n2)
        return false;

    int freq1[26] = {0};
    int freq2[26] = {0};


    for (int i = 0; i < n1; i++) {
        freq1[s1[i] - 'a']++;
    }


    for (int i = 0; i < n1; i++) {
        freq2[s2[i] - 'a']++;
    }


    for (int i = n1; i < n2; i++) {


        int same = 1;

        for (int j = 0; j < 26; j++) {
            if (freq1[j] != freq2[j]) {
                same = 0;
                break;
            }
        }

        if (same)
            return true;


        freq2[s2[i] - 'a']++;

        freq2[s2[i - n1] - 'a']--;
    }

    for (int j = 0; j < 26; j++) {
        if (freq1[j] != freq2[j])
            return false;
    }

    return true;
}
