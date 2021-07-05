#include <stdio.h>
#include <string.h>



/* 编写程序，实现从输入的字符串中提取并保存连续数字子串的功能，
例如用户从键盘输入12abc345def67，输出12,345,67。*/

int main(){
    char a[]="12abc345def67";
    char res[20]={};
    int i;
    int flag=0;
    // char s[]={'a','d','\0','a','\0'};

    printf("请输入一段字符串：\n");
    

    for(i=0; i<strlen(a); i++){
        if('a'>a[i] || a[i]>'z'){
            res[flag] = a[i];
            flag ++;

            if('a'<=a[i+1] && a[i+1]<='z'){
                res[flag] = ',';
                flag ++;
            }
        }
    }
    
    printf("提取后的数字串是%s\n",res);
    // printf("haha%c\n",res[4] );
    // printf("%s",s);

    return 0;
}