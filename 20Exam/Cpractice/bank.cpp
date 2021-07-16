#include<stdio.h>
int accout1 = 123, accout2 = 456;
int pwd1 = 111, pwd2 = 333;
float money1 = 9.9, money2 = 8.8;

int P_accout, P_pwd;
float P_money;
// struct user
// {
//     int account;
//     int pwd;
//     float money;
// };


void login()
{
    int accout, pwd;
    printf("请输入账户：\n");
    scanf("%d", &accout);
    printf("请输入密码：\n");
    scanf("%d", &pwd);

    if(accout==accout1 && pwd==pwd1 || (accout==accout2 && pwd==pwd2))
    {
        printf("登入成功\n");
        P_accout=accout;
        P_pwd=pwd;
        if(accout==accout1)
        {
            P_money = money1;
        }else
        {
            P_money = money2;
        }
        
    }else
    {
        printf("用户名或密码错误\n");
    }
}

void save()
{
    float save;
    printf("请输入您要存入的金额：\n");
    scanf("%f", &save);

    P_money = P_money + save;
    printf("账户余额是%f\n", P_money);
} 

void zhuan()
{
    float money;
    printf("请输入你要转出的钱:\n");
    scanf("%f", &money);

    P_money = P_money - money;
    money2 = money2 + money;
    printf("账户余额为%f", P_money);
}

void get()
{
    float money;
    printf("请输入你要取出的钱:\n");
    scanf("%f", &money);

    P_money = P_money - money;
    // money2 = money2 + money;
    printf("账户余额为%f", P_money);

}

int main()
{
    int choose;
    // login();
    // save();

    while(1)
    {
        printf("请输入你想执行的操作：\n");
        printf("1.存款 2.取款 3.转帐 4.退出\n");
        scanf("%d", &choose);
        switch (choose)
        {
            case 1: save(); break;
            case 2: get();  break;
            case 3: zhuan();  break;
            default: return 0;   
        }

    }

    return 0;
}