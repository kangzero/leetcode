#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize){
    if (costSize < 2) return -1; // 2 <= costSize <= 1000
    
    int *ans = calloc(costSize, sizeof(int));
    
    ans[0] = cost[0];
    ans[1] = cost[1];
    
    for (int i = 2; i < costSize; i++) {
        ans[i] = cost[i] + MIN(ans[i-1], ans[i-2]);
    }

    return MIN(ans[costSize-1], ans[costSize-2]);
}

