
#define INCR_POINTER 0
#define GREEDY 1


bool isOneBitCharacter(int* bits, int bitsSize) {
#if INCR_POINTER
    int idx = 0;
    while (idx < bitsSize) {
        if ((bits[idx] & 0x1) == 1) {
            idx += 2;
        } else {
            if ((idx == (bitsSize - 1)) && (bits[idx] == 0)) {
                return true;
            }
            idx += 1;
        }
    }
    return false;
#elif GREEDY
    if (bits[bitsSize-1] == 1) return false;
    
    int n = bitsSize - 2;
    while ((n >= 0) && (bits[n] > 0)) n--;
    return (bitsSize - n) % 2 == 0;
#endif
}
