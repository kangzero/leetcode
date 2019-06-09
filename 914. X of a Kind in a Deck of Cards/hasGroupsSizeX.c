int gcd (int num1, int num2);
bool hasGroupsSizeX(int* deck, int deckSize);

bool hasGroupsSizeX(int* deck, int deckSize) {
    if ((deckSize < 2) || ((deckSize == 2) && (deck[0] != deck[1]))) return false;
   
    int check[10001] = {0};
    for (int i = 0; i < deckSize; i++) check[deck[i]]++;
    
    int idx = 0;
    int g = -1;
    // while ((idx < 10001) && (check[idx]  == 0)) idx++;
    // int g = check[idx];
    // idx++;
    
    while (idx < 10001) {
        if (check[idx] > 0) {
            if (g == -1) {
               g = check[idx];
            } else {
                g = gcd(g, check[idx]);
            }
        }               
        idx++;
    }
    
    return (g >= 2);
}

int gcd (int num1, int num2) {
    int temp;
    while (num2 != 0) {
       temp = num2;
       num2 = num1 % num2;
       num1 = temp;
    }
    return num1;
    //return (num1 == 0) ? num2 : gcd(num2 % num1, num1);
}
 
