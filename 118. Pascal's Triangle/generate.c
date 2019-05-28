//#define _DEBUG

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **pascal = malloc(numRows * sizeof(int*));
    
    for (int i = 0; i < numRows; i++) {
#ifdef _DEBUG
        printf("i = %d \n", i);
#endif
        pascal[i] = malloc((i+1) * sizeof(int));
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
     
#ifdef _DEBUG
    for (int i = 0; i < numRows; i++) {
        printf("%d ", pascal[numRows-1][i]);
    }
    printf("\n");
#endif
    
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int*));
    for (int k = 0; k < numRows; k++) {
        (*returnColumnSizes)[k] = k + 1;
    }
    
    return pascal;
}

