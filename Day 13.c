# Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    int j;

    while (strs[0][i] != '\0') {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
        i++;
    }

    return strs[0];
}
