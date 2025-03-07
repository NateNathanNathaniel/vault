#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char sentence[105];
    fgets(sentence, 105, stdin);
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i]<='z'&& sentence[i]>='a'){
            sentence[i]=sentence[i]-('a'-'A');    
        }
        else if(sentence[i]<='Z'&& sentence[i]>='A'){
            sentence[i]=sentence[i]+('a'-'A');    
        }
    }
    printf("%s",sentence);
    return 0;
}