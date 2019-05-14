/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int *queriesColSizes, int* returnSize) {
    *returnSize = ASize;
    int *ret = malloc(ASize * sizeof(int));
    int index = 0;
    
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 0x1) == 0) {
            sum += A[i];
        }
    }
    
    for (int i = 0; i < queriesRowSize; i++) {
        if ((A[queries[i][1]] & 0x1) == 0) {
            sum -= A[queries[i][1]];
        }
        A[queries[i][1]] +=  queries[i][0];
        if ((A[queries[i][1]] & 0x1) == 0) {
            sum += A[queries[i][1]];
        }
        ret[index++] = sum;
    }

    return ret;
}
