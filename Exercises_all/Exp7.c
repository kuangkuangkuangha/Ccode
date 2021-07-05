#include <stdio.h>
#include <string.h>
#define NUM 80

// BF算法，串模式匹配算法,正文模式匹配
int BF(char S[], char T[])
{
    int i=0, j=0;
    int index = 0;

    while(S[i]!='\0' && T[j]!='\0')
    {
        if(S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = 0;
            index++;
            i = index;
        }
    }
    if(T[j]=='\0')
        return index+1;
    else
        return -1;
}

// 字符串的真前后缀
void MaxAffixLength(char T[], int next[]){
    int i, j, len;
    memset(next, 0, NUM*sizeof(int));
    for(i=0; T[i]!='\0'; i++){

        for(len=i; len>=1; len--){

            for(j=0; j<len; j++){

                if(T[j] != T[i - len*j +1])
                    break;
            }
            if(j==len){
                next[i] = len;
                break;
            }
        }
    }

}



int main(){
    int a;
    a = BF("ababca ababbabc cbab","ababbabc");
    printf("匹配到的字符是第%d个", a);

    // int i;
    // int next[]={};
    // MaxAffixLength("ababaaababaa",next);
    // for ( i = 0; i < 6; i++){
    //     printf("%d", next[i]);
    // }
    
    return 0;
}