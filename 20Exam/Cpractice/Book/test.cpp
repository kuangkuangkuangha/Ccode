#include <stdio.h>

// #include <winsock.h>

#include </usr/local/mysql/include/mysql.h>

int main()
{
    //初始化mysql
    MYSQL *pconn= mysql_init(0);
    //连接数据库(1.初始化数据信息 2.连接地址 3.账号 4.密码 5.数据库名称)
    if(!mysql_real_connect(pconn), "localhost", "root", "root", "empdb", 0, 0, 0)
    {
        printf("连接失败，错误为%s\n", mysql_error(pconn));
        // goto exit;
        return 0;
    }

    mys

    //初始化编码问题
    printf("连接成功！\n");

    if(mysql_query(pconn, "set names utf8"))
    {
        printf("编码失败，错误为%s\n", mysql_errno(pconn));
        // goto exit;
        return 0;
    }

    printf("连接成功！\n");

    if(mysql_query(pconn, "insert into userinfo value(null, 'lili', 21, '女')"))
    {
        printf("添加失败，错误为%s\n", mysql_errno(pconn));
        // goto exit;
        return 0;
    }

    // exit;
    return 0;

    // 查询
    if((mysql_query(pconn),'select * from userinfo'))
    {
        printf("查询失败,错误为%s", mysql_error(pconn));
    }
    // 用一个容器来接收查询的结果
    MYSQL_RES *res = mysql_store_result(pconn);
    // 利用游标去读取数据
   

    // 循环读出每条数据
    MYSQL_ROW row;

    while (row = mysql_fetch_row(res))
    {
        printf("%s\n", row[0])
    }
    


}