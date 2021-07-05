#include <stdio.h>
#include <math.h>

// 解一元二次方程
// ax@2 + bx +c = 0
void solve()
{
    printf("请输入三个数：\n");
    float a, b, c;
    scanf("%f,%f,%f", &a, &b, &c);
    float x1, x2;
    float delta;
    delta = b*b - 4*a*c;

    if(delta > 0)
    {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("方程的两个解是x1=%f,x2=%f\n", x1, x2);
    }

    if(delta == 0)
    {
        x1 = (-b + sqrt(delta))/(2*a);
        printf("方程的解是x1=x2=%f", x1);
    }

    if(delta < 0)
    {
        printf("方程无解\n");
    } 
}

void divide()
{
    int a;
    int temp;
    printf("请输入一个三位数：");
    scanf("%d",  &a);
    while (a > 0)
    {
        temp = a%10;
        a = a/10;
        printf("%d\n", temp);
    }
}

void changebit(){
    long temp;
    long res = 0;
    printf("请输入一个整数：");
    printf("%d", sizeof(short));
    scanf("%d", temp);
    long a, b, c, d;
    a = temp >> 24;
    b = temp << 24;

    c = temp >> 16;
    c = c & 0x00f0;

    d = temp << 16;
    d = d & 0x0f00;

    res = a+b+c+d;
    printf("移位后的数是%ld\n", res);

}




int main()
{
    // solve();
    divide();
    // changebit();
    return 0;
}