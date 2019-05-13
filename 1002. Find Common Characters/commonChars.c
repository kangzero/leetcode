/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//assumption 1: 1 <= A.length <= 100
//assumption 2: 1 <= A[i].length <= 100
//assumption 3: lowercase letter only
char** commonChars(char** A, int ASize, int* returnSize) {
    char **list = (char **)calloc(100, sizeof(char*));
    int **checklist = (int**)calloc(ASize, sizeof(int*));
    
    for (int i = 0; i < ASize; i++) {
        checklist[i] = (int*)calloc(26, sizeof(int));
        for (int j = 0; j < strlen(A[i]); j++) {
            checklist[i][A[i][j] - 'a']++;
        }
    }
    
    int cnt = 0;
    for (int n = 0; n < 26; n++) {
        int min = INT_MAX;
        for (int m = 0; m < ASize; m++) {
            min = (min < checklist[m][n]) ? min : checklist[m][n];
            if (min == 0) break;
        }
        while (min > 0) {
            list[cnt] = (char*)calloc(2, sizeof(char));
            list[cnt][0] = n + 'a';
            list[cnt][1] = '\0';
            cnt++;
            min--;
        }
    }
    
    *returnSize = cnt;
    free(checklist);
    checklist = NULL;
    
    return list;
}
