#define RECURSIVE 0
#define ITERATIVE 0
#define DYNAMIC_P 1

class Solution {
public:
    int fib(int N) {
#if RECURSIVE //O(), Space: O(n)
        if (N < 2) return N;

        return fib(N-1) + fib(N-2);
#elif ITERATIVE //O(n), Space: O(1)
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
#elif DYNAMIC_P //O(n), Space: O(1)
        int f1 = 0;
        int f2 = 1;
        
        while (N != 0) {
            f2 += f1; //f3
            f1 = f2 - f1; //f2
            N--;
        }
        
        return f1;
#endif
    }
};
