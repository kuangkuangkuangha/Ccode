#include <stdio.h>

void ex1()
{
    int hh, mm, ss;
    int temp;
    printf("请输入一个整数：\n");
    scanf("%d", &ss);
    hh = ss/3600;
    temp = hh%3600;
    mm = temp / 60;
    ss = temp % 60;

    printf("%d-%d-%d", hh, mm, ss);
}

void ex2()
{
    double a,b,c;
    double temp;
    printf("请输入三个浮点数：\n");
    scanf("%lf,%lf,%lf", &a, &b, &c);
    temp = (a+b+c)/3;

    temp = (int)(temp * 100);
    printf("保留后的小数是%.2f", temp/100);
}

void ex3(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void ex3_2(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    ex2();
}