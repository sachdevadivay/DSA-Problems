# Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

  void moveZeroes(int* nums, int numsSize) {
    int pos = 0;

   
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

   
    for (int i = pos; i < numsSize; i++) {
        nums[i] = 0;
    }
}
