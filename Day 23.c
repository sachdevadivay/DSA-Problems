# Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int freq[20001] = {0};   
    int offset = 10000;     
    
  
    for(int i = 0; i < numsSize; i++)
        freq[nums[i] + offset]++;
    
    
    int unique[numsSize];
    int count = 0;
    
    for(int i = 0; i < numsSize; i++) {
        int found = 0;
        for(int j = 0; j < count; j++) {
            if(unique[j] == nums[i]) {
                found = 1;
                break;
            }
        }
        if(!found)
            unique[count++] = nums[i];
    }
    
   
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(freq[unique[i] + offset] < freq[unique[j] + offset]) {
                int temp = unique[i];
                unique[i] = unique[j];
                unique[j] = temp;
            }
        }
    }
    
   
    int* result = (int*)malloc(sizeof(int) * k);
    
    for(int i = 0; i < k; i++)
        result[i] = unique[i];
    
    *returnSize = k;
    
    return result;
}
