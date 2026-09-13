# Given two strings s and t, return true if t is an anagram of s, and false otherwise.

bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int i;

    if (strlen(s) != strlen(t)) {
        return false;
    }

    for (i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}
