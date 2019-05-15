/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define NATIVE  0
#define HASH    1
#define QSORT_BSEARCH 0

#define MAX_SIZE 100001

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
#ifdef NATIVE
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < ASize; i++) sum_a += A[i];
    for (int i = 0; i < BSize; i++) sum_b += B[i];
    
    int *ret = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int delta = (sum_b - sum_a) / 2;
    
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            if (B[j] == (A[i] + delta)) {
                ret[0] = A[i];
                ret[1] = B[j];
                return ret;
            }
        }
    }
  
    return ret;
#elif HASH
    int *hash_a = calloc(MAX_SIZE, sizeof(int));
    int *hash_b = calloc(MAX_SIZE, sizeof(int));
    
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < ASize; i++) {
        sum_a += A[i];
        hash_a[A[i]]++;
    }
    for (int i = 0; i < BSize; i++) {
        sum_b += B[i];
        hash_a[A[i]]++;
    }
    
    int *ret = calloc(2, sizeof(int));
    *returnSize = 2;
    int delta = (sum_b > sum_a) ? (sum_b - sum_a) / 2) : (sum_a - sum_b) / 2);
    for (int i = 0; i < MAX_SIZE; i++) {
        if (sum_b > sum_a) {
            if ((hash_a[i] > 0) && (hash_b[i+delta] > 0)) {
                ret[0] = i;
                ret[1] = i + delta;
                free(hash_a);
                free(hash_b);
                hash_a = NULL;
                hash_b = NULL;
                return ret;
          }  
        } else {
            if ((hash_b[i] > 0) && (hash_a[i+delta] > 0)) {
                ret[0] = i;
                ret[1] = i +delta;
                free(hash_a);
                free(hash_b);
                hash_a = NULL;
                hash_b = NULL;
                return ret;
            }
        }
    }

    free(hash_a);
    free(hash_b);
    hash_a = NULL;
    hash_b = NULL;
    return ret;
#elif QSORT_BSEARCH
    //step 1. qsort
    //step2. bsearch
#endif
}
