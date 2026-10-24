# Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int pivot = nums[left + (right - left) / 2];

        int low = left;
        int mid = left;
        int high = right;

       
        while (mid <= high) {
            if (nums[mid] < pivot) {
                swap(&nums[low], &nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] > pivot) {
                swap(&nums[mid], &nums[high]);
                high--;
            }
            else {
                mid++;
            }
        }

        

        if (target < low) {
            right = low - 1;
        }
        else if (target > high) {
            left = high + 1;
        }
        else {
            return pivot;
        }
    }

    return -1;
}
