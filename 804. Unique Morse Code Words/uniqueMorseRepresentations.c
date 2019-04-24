//#define STR_OPR
#define BIT_TRANSFORM

#ifdef STR_OPR
//The length of words will be at most 100.
//Each words[i] will have length in range [1, 12] - max length of morse is 12*4 = 48

#define MAX_LENGTH_MORSE 50U
    
const char *morse[26] = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-",
                         "..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(char** words, int wordsSize) {
    if (wordsSize < 1) return 0;
    if (wordsSize == 1) return 1;
    
    int ret = wordsSize;
    char **str = (char**)calloc(wordsSize, sizeof(char*));  
    
    for (int i = 0; i < wordsSize; i++) {
        str[i] = (char*)calloc(MAX_LENGTH_MORSE, sizeof(char));
        int index = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
            int k=0;
            while (morse[words[i][j] - 'a'][k] != '\0') {
                str[i][index] =  morse[words[i][j] - 'a'][k];
                k++;
                index++;
            }
            str[i][index] = '\0';
        }
    }
     
    for (int i = 0; i < (wordsSize-1); i++) {
        for (int j = (i+1); j < wordsSize; j++){
            if (strcmp(str[i], str[j]) == 0 ) {
                ret--;
                break;
            }
        } 
    }

    free(str);
    return ret;    
}

#elif defined BIT_TRANSFORM

// morse code: 0 == '.' ; 1 =='-'
//a: 2, 01
//b: 4, 1000
//c: 4, 1010
//d: 3, 100
//e: 1，0
//f: 4，0010
//g: 3，110
//h: 4，0000
//i: 2，00
//j: 4，0111
//k: 3，101
//l: 4，0100
//m: 2，11
//n: 2, 10
//0: 3, 111
//p: 4, 0110
//q: 4, 1101
//r: 3, 010
//s: 3, 000
//t: 1, 1
//u: 3, 001
//v: 4, 0001
//w: 3, 011
//x: 4, 1001
//y: 4, 1011
//z: 4, 1100
const int morse[26][2] = {{2, 0x1}, {4, 0x8}, {4, 0xa}, {3, 0x4}, {1, 0x0}, {4, 0x2}, {3, 0x6},
                          {4, 0}, {2, 0}, {4, 0x7}, {3, 0x5}, {4, 0x4}, {2, 0x3}, {2, 0x2},
                          {3, 0x7}, {4, 0x6}, {4, 0xd}, {3, 0x2}, {3, 0x0}, {1, 0x1}, 
                          {3, 0x1}, {4, 0x1}, {3, 0x3}, {4, 0x9}, {4, 0xb}, {4, 0xc}};

int uniqueMorseRepresentations(char** words, int wordsSize) {
    if (wordsSize < 1) return 0;
    if (wordsSize == 1) return 1;
    
    int ret = wordsSize;
    
    //up to 100 words
    //every word length in morse is not more than 12*4 = 48 bits (< sizeof(long))
    long check[100][2] = {0}; 
    
    for (int i = 0; i < wordsSize; i++){
        //printf("%s\n", words[i]);
        for (int j = 0; j < strlen(words[i]); j++){
            check[i][0] += morse[words[i][j] - 'a'][0];
            if (j != 0) {
                check[i][1] <<= morse[words[i][j] - 'a'][0];
            }
            check[i][1] += morse[words[i][j] - 'a'][1];
        }
        //printf("check[%d][0] = %d, check[%d][1] = %x\n", i, check[i][0], i, check[i][1]);
    }
    
    for (int i = 0; i < 99; i++) {
        for (int j = (i+1); j < 100; j++) {
            if ((check[i][0] == check[j][0]) && (check[i][0] != 0)) {
                if(check[i][1] == check[j][1]){
                    ret--;
                    //printf("i = %d, j = %d, ret = %d\n", i, j, ret);
                    break;
                }
            }
        }
    }
    
    return ret;
}
#endif
