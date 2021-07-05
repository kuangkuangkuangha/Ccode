#include <stdio.h>

// 数一个数的位数
void ex1()
{
    int temp;
    int count = 0;
    printf("请输入一个正整数:\n");
    scanf("%d", &temp);
    while (temp > 0)
    {
        temp = temp/10;
        count ++;
    }

    printf("这是一个%d位数", count);
}

// 验证一个数的立方可以分成若干个奇数的和
void ex2()
{
    int a, temp;
    int i, j, k;
    int count;
    int sum;
    printf("请输入一个整数：\n");
    scanf("%d", &a);
    temp = a*a*a;

    for(i=1; i<temp; i+=2)
    {
        sum = 0;
        count = 0;

        for(j=i; j<temp; j+=2)
        {
            sum += j;
            count ++;
            if(temp == sum)
            {
                
                for(k=0; k<count; k++)
                {
                    printf("%d\n", i + k*2);
                }

                break;
            }
            printf("haha");
        }
        
    }



}


// 百元买百鸡问题
void ex3()
{
    int x,y,z;
    for(x=0; x<100; x++)
    {
        for(y=0; y<100; y++)
        {
            for(z=0; z<100; z++)
            {
                if(x+y+z==100 && 5*x + 3*y + 1/3*z == 100)
                {
                    printf("可以买%d只母鸡，%d只公鸡，%d只小鸡\n", x, y, z);
                    break;
                }
            }
        }
    }
}

int main()
{
    ex2();
}