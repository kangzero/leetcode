/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TWO_PASS 0
#define WR_HEAD 1

#if TWO_PASS
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int *t = (int*)malloc(ASize * sizeof(int));
    
    int index = 0;
    for (int i = 0; i < ASize; i++) {
        if ((A[i]%2) == 0) {
            t[index] = A[i];
            index += 2;
        }
    }
    
    index = 1;
    for (int i = 0; i < ASize; i++) {
        if ((A[i]%2) == 1) {
            t[index] = A[i];
            index += 2;
        }
    }
    
    *returnSize = ASize;
    return t;
}
#elif defined WR_HEAD
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int j = 1;
    for (int i = 0; i < ASize; i += 2) {
        if ((A[i] % 2) != 0) {
            while ((A[j] % 2) == 1) {
                j += 2;
            }
            //swap i & j
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    *returnSize = ASize;
    return A;
}
#endif

