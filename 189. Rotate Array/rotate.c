#define SIMPLE 0
#define DUAL_DIRECTION 0
#define EXTRA_ARRAY 0
#define REVERSE 1
#define CYCLIC 0

#if SIMPLE
void rotate(int* nums, int numsSize, int k) {
    //printf("SIMPLE \n");
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < k; i++) {
        temp = *(nums + numsSize - 1);
        for (j = numsSize - 1; j > 0; j--) {
            *(nums + j) = *(nums + j - 1);
        }
        *nums = temp;
    } 
}

#elif DUAL_DIRECTION
// move the elements in a given array by two position
void rotate(int* nums, int numsSize, int k) {
    int direction = 1;  //input: 1 = forward, 0 - backward
    //k = 2; //fixed to 2 positions for test case
    //printf("DUALDIRECTION \n");
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < k; i++) {
        if (direction) {
            temp = *(nums + numsSize - 1);
            for (j = numsSize - 1; j > 0; j--) {
                *(nums + j) = *(nums + j - 1);
            }
            *nums = temp;
        } else {
            temp = *(nums);
            for (j = 0; j < numsSize - 1; j++) {
                *(nums + j) = *(nums + j + 1);
            }
            *(nums + j) = temp;
        }    
    } 
}

#elif EXTRA_ARRAY
//use an extra arry in which place elements at correct position and the copy to orignal one
void rotate(int* nums, int numsSize, int k) {
    //printf("EXTRAARRY \n");
    int* temp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i]; 
    }
    for (int i = 0; i< numsSize; i++) {
        nums[i] = temp[i];
    }
    free(temp);
}

#elif REVERSE
void rotate(int* nums, int numsSize, int k) {
    //printf("REVERSE \n");
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

void reverse(int* nums, int start, int end){
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

#elif CYCLIC
void rotate(int* nums, int numsSize, int k) {
    printf("CYCLIC \n");
}
#endif
