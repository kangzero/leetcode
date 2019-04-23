char* toLowerCase(char* str) {
    int len = strlen(str);
    
    for(int i = 0; i < len; i++){
        //if((str[i] >= 65) && (str[i] <= 90)){
        if((*(str+i) >= 'A') && (*(str+i) <= 'Z')){
            //str[i] += 32;
            *(str+i) += ('a' - 'A');
        }
    }
    
    return str;
}
