#define DYNAMIC_P 1
#define ITERATIVE 0
#define RECURSIVE 0

int fib(int N) {
#if DYNAMIC_P
    int f1 = 0;
    int f2 = 1;
    
    while (N-- > 0) {
        f2 += f1;
        f1 = f2 - f1;
    }
    
    return f1;
#elif ITERATIVE
    if (N < 2) return N;
    
    int f1 = 0;
    int f2 = 1;
    int f3 = 0;
    for (int i = 2; i <= N; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    
    return f3;
#elif RECURSIVE
    if ((N == 0) || (N == 1)) return N;
    
    return fib(N-1)+fib(N-2);
#endif
}
