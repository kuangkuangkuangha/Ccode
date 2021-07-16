#include <stdio.h>
#include </usr/local/mysql/include/mysql.h>

void registe(MYSQL *mycout)
{
    char name[50];
    int pwd;

    printf("现在是注册用户阶段：\n");
    printf("请输入用户名：\n");
    scanf("%s", name);

    printf("请输入密码：\n");
    scanf("%d", &pwd);

    if(mysql_query(mycout, "insert into empinfo(null, name, pwd)"))
    {
        printf("注册失败");
    }
    else{
        printf("注册成功");
    }

}

void login(MYSQL *mycout)
{
    char name[50];
    int pwd;

    printf("现在是登陆阶段：\n");
    printf("请输入用户名：\n");
    scanf("%s", name);

    printf("请输入密码：\n");
    scanf("%d", &pwd);

    if(mysql_query(mycout, "select * from empinfo where eName=name and pwd=pwd"))
    {
        printf("登陆失败");
    }
    else
    {
        printf("登陆成功");
    }


}


int main()
{

    printf("注册用户名：\n")
}