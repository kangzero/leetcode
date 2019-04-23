/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    *returnSize = ARowSize;
    *columnSizes = calloc(ARowSize, sizeof(int*));
    int **ret = calloc(ARowSize, sizeof(int*));
    
    for (int i = 0; i < ARowSize; i++) {
        ret[i] = calloc((*AColSizes), sizeof(int));
        (*columnSizes)[i] = AColSizes[i];
        int k = 0;
        for (int j = AColSizes[i]-1; j >= 0; j--) {
            ret[i][k] = A[i][j] ^ 1;
            k++;
        } 
    }
    
    return ret;
}
