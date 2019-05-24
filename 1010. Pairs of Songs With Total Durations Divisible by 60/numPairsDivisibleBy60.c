#define BRUTE_FORCE 0 //TLE
#define COUNT 1

int numPairsDivisibleBy60(int* time, int timeSize) {
#if COUNT
    int ret = 0;
    int count[60] = {0};
    
    for (int i = 0; i < timeSize; i++) {
        count[time[i] % 60]++;
    }
    
    int l = 1, r = 59;
    while (l < r) {
        ret += count[l] * count[r];
        l++;
        r--;
    }
    
    ret += (count[0] * (count[0]-1) / 2) + (count[30] * (count[30]-1) / 2);
        
    return ret;
#elif BRUTE_FORCE
    int ret = 0;
    
    for (int i = 0; i < timeSize; i++) {
        for (int j = i+1; j < timeSize; j++) {
            if (((time[i] + time[j]) % 60) == 0 ) ret++;  
        }
    }
    
    return ret;
#endif
}

