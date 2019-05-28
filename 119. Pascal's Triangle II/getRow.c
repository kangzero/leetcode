#define PASCAL_GENERATE 0
#define ONE_PASS 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
#if PASCAL_GENERATE  
    int **pascal = malloc((rowIndex+1) * sizeof(int*));
    
    for (int i = 0; i < (rowIndex+1); i++) {
        pascal[i] = malloc((i+1) * sizeof(int));
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i;j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    
    *returnSize = rowIndex + 1;
    return pascal[rowIndex];
#elif ONE_PASS
    int *ret = calloc((rowIndex+1), sizeof(int));
    *returnSize = rowIndex + 1;
    
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            ret[j] += ret[j-1];
        }
    }
    
    return ret;
    
#endif
}

