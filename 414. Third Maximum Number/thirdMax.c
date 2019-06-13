//#define _DEBUG

int cmpInt(const void *a, const void *b);

int thirdMax(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), &cmpInt);

#ifdef _DEBUG
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
#endif

    int cnt = 1;
    if (numsSize >= 3) {
        for (int i = (numsSize-2); i >= 0; i--) {      
            if (nums[i+1] != nums[i]) {
                cnt++;
            } 
            if (cnt == 3) return nums[i];
        }
    }
    
    return nums[numsSize-1];
}

int cmpInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
        
