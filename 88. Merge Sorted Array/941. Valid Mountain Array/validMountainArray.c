bool validMountainArray(int* A, int ASize) {
    if (ASize < 3) return false;
    
    int r = 0;
    int l = ASize - 1;
    
    while (((r+1) < l) && (A[r] < A[r+1])) {
        r++;
    }
    while (((l-1) > 0) && (A[l] < A[l-1])) {
        l--;
    }
    
    return (r == l);   
}
