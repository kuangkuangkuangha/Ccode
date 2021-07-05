#include <stdio.h>

// 合并有序数列
void ex1()
{
    int i, j, k;
    int temp;
    i=j=k=0;
    int a[5] = {0,4,5,8,20};
    int b[5] = {2,3,6,7,9};
    int c[10];



    while(i<=5 || j<=5)
    {
        if(a[i]<b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else{
            c[k] = b[j];
            j++;
            k++;
        }
    }
   
    if(a[4]>b[4])
        c[9] = a[4];
    else
        c[9] = b[4];

    // 打印出合并后的数组
    for(temp=0; temp<10; temp++)
    {
        printf("%d\n", c[temp]);
    }

}

// 01背包问题
void ex2()
{
    
}


int main()
{
    ex1();
}