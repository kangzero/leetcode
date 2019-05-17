/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int r = 0;
    int l = numbersSize - 1;
    while (r < l) {
        if ((numbers[r] + numbers[l]) > target) {
            l--;
        } else if ((numbers[r] + numbers[l]) < target) {
            r++;
        } else {
            //return index are not zero-based
            ret[0] = r + 1;
            ret[1] = l + 1;
            return ret;
        }
    }
    return NULL;
}
