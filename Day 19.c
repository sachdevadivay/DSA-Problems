# Given an integer n represented as a string, return the smallest good base of n.

We call k >= 2 a good base of n, if all digits of n base k are 1's.

char* smallestGoodBase(char* n) {
    unsigned long long num = strtoull(n, NULL, 10);

    for (int m = 59; m >= 1; m--) {
        unsigned long long low = 2;
        unsigned long long high = pow(num, 1.0 / m) + 1;

        while (low <= high) {
            unsigned long long k = low + (high - low) / 2;

            __int128 sum = 1;
            __int128 term = 1;

            for (int i = 1; i <= m; i++) {
                term *= k;
                sum += term;

                if (sum > num)
                    break;
            }

            if (sum == num) {
                char* ans = (char*)malloc(30);
                sprintf(ans, "%llu", k);
                return ans;
            }

            if (sum < num)
                low = k + 1;
            else
                high = k - 1;
        }
    }

    char* ans = (char*)malloc(30);
    sprintf(ans, "%llu", num - 1);
    return ans;
}
