

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ret = malloc((digitsSize+1) * sizeof(int));
    int len = digitsSize;

    int val = digits[len-1] + 1;
    int carry = 0;
    if (val > 9) {
        ret[len] = 0;
        carry = 1;
    } else {
        ret[len] = val;
        carry = 0;
    }
    len--;

    while (len > 0) {
        val = digits[len-1] + carry;
        if (val > 9) {
            ret[len] = 0;
            carry = 1;
        } else {
            ret[len] = val;
            carry = 0;
        }
        len--;
    }
    
    if (carry == 1) {
        ret[0] = 1;
        *returnSize = digitsSize + 1;
    }
    
    if (carry == 0) {
        for (int i = 0; i < digitsSize; i++) {
            ret[i] = ret[i+1];
            *returnSize = digitsSize;
        }
    }
    
    return ret;
}

