/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int *ret = calloc(ASize, sizeof(int));
    int l = 0; 
    int r = ASize - 1; 
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            ret[l++] = A[i]; 
        } else {
            ret[r--] = A[i];
        }
    }
    return ret;
}
