/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* ret = (int *)malloc(sizeof(int) * (*returnSize));
    int* front = A, * rear = A + ASize - 1;
    int k = ASize - 1;
    
    while((front <= rear) && (k >= 0)){
        (*front) = ((*front) >0) ? (*front) : (*front)*(-1);
        (*rear) = ((*rear) >0) ? (*rear) : (*rear)*(-1);
        if((*front) >= (*rear)){
            *(ret + k) = (*front) * (*front);
            front++;
        }else{
            *(ret + k) = (*rear) * (*rear);
            rear--;
        }
        k--;
    }
    return ret;
} 
