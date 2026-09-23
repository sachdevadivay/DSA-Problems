# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    int longest = 0;

    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];
        int currentLength = 1;
        int isStart = 1;

        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == currentNum - 1) {
                isStart = 0;
                break;
            }
        }

        if (isStart) {
            int nextNum = currentNum + 1;

            while (1) {
                int found = 0;

                for (int j = 0; j < numsSize; j++) {
                    if (nums[j] == nextNum) {
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    break;

                currentLength++;
                nextNum++;
            }

            if (currentLength > longest)
                longest = currentLength;
        }
    }

    return longest;
}
