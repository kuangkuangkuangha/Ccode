#include <stdio.h>
#include <stdlib.h>
#define N 8

// 斐波那契数列
int feibo(int n)
{
    if(n <= 2)
        return 0;
    else 
        return feibo(n-1)+feibo(n-2);
}


// 八皇后问题
int a[N];
// int m=0;

void showresult()
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d" ,a[i]);
    }
    printf("\n");
}

// i表示放置第i个皇后，判断第i个皇后是否与前i-1个皇后 同行列 或 同斜线
// 判断第i行第n列可不可以放
int canplace(int i, int n)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(a[j]==n || abs(a[j]-n)==abs(j-i))    // 判断列 和 对角线，因为数组下标就表示行，不用判断
        {
            return 0;
        }
    }
    return 1;
}

int try(int i)//表示尝试放置第i行的皇后
{
    int j;
    if(i==N)
    {
        showresult();
        return 0;
    }

    for(j=0;j<N;j++)
    {
        if(canplace(i,j))
        {
            a[i]=j;
            try(i+1);
        }
    }
    return 0;
}

int main()
{
    // feibo(5);
    int m;
    try(0);
    printf("%d\n",m);
    return 0;
}

