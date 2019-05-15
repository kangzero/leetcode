//#define _DEBUG

bool canThreePartsEqualSum(int* A, int ASize){
#ifdef _DEBUG
    printf("ASize = %d\n", ASize);
#endif
    int sum = 0;
    for (int i = 0; i < ASize; i++) sum += A[i];
    if ((sum % 3) != 0) return false;
    
    int avg = sum / 3;

    int cnt = 0;
    int idx = 0;
    while ((cnt < 3) && (idx < ASize)) {
        cnt++;
        int tmp = 0;
        while (idx < ASize) {
            tmp += A[idx++];
            if (tmp == avg) break;
        }
#ifdef _DEBUG
        printf("%d\n", idx);
#endif
        if (idx > ASize) return false;
    }

#ifdef _DEBUG
    printf("cnt = %d", cnt);
#endif
    if (cnt == 3) return true;
    return false;
}

