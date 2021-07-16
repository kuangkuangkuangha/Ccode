//
//  main.cpp
//  test
//
//  Created by 张旷 on 2021/7/9.
//

#include </usr/local/mysql/include/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MYSQL *pconn = mysql_init(0);
char uname[30];
int upwd;


void registe()
{

}




void login()
{
    
    printf("欢迎来到球赛管理系统\n");
    printf("现在是用户登陆页面\n");
    
    printf("请输入用户名：\n");
    scanf("%s", uname);
    
    printf("请输入密码：\n");
    scanf("%d", &upwd);
    
    char sql[100];
    
    sprintf(sql, "select * from user where uname = '%s' and upwd = %d", uname, upwd);
    
    if(mysql_query(pconn, sql))
    {
        printf("登陆失败, 错误为%u\n", mysql_errno(pconn));
        printf("%s\n", sql);
    }
    
    MYSQL_RES *res = mysql_store_result(pconn);
    unsigned long long colume = mysql_num_rows(res);
    if(colume>0)
    {
        printf("登陆成功\n");
    }else
    {
        printf("登陆失败\n");
    }
    
}




void AddGame()
{
    char teamA[50];
    char teamB[50];
    char sql_select_tname[100];
//    char sql_insert_game[100];
    
    
    printf("现在是添加球赛界面:\n");
    
    printf("请输入主队的队名：\n");
    scanf("%s", teamA);
    printf("请输入客队的队名：\n");
    printf("%s", teamB);
    
    sprintf(sql_select_tname, "select tid from team where tname = '%s' or tname = '%s'", teamA, teamB);
    
    if(mysql_query(pconn, sql_select_tname))
    {
        printf("添加球赛失败，错误为%u", mysql_errno(pconn));
    }

//    MYSQL_RES *res=mysql_store_result(pconn);
//    MYSQL_ROW row;
//
//    while (row = mysql_fetch_row(res))
//    {
//
//    }
//
}

void mysql()
{
    if(!mysql_real_connect(pconn, "localhost", "root", "zk2824895143", "20Exercise", 3306, NULL, 0))
    {
        printf("连接失败,错误为：%u\n", mysql_errno(pconn));
        mysql_close(pconn);
    }else
    {
        printf("连接成功\n");
    }
    
    if(mysql_query(pconn, "set names gbk"))
    {
        printf("编码有误,错误为%u", mysql_errno(pconn));
    }

}



//查看用户权限
//int CheckRole()
//{
//    char sql_check_role[100];
//    sprintf(sql_check_role, "select role from user where uname = '%s'", uname);
//
//    MYSQL_RES *res=mysql_store_result(pconn);
//    MYSQL_ROW row;
//
//    if(row = mysql_fetch_row(res))
//    {
//        printf("haha%s", row[0]);
//    }
//
//    return 0;
//}
//


// 用户
//获取球赛列表
void GetGames()
{
    
}

void SearchGame()
{
    
}

//注册
void Registe()
{
    
}

//登陆
void Login()
{
    
}




//前台管理员
//创建球赛
void CreatGame()
{
    
}

//预约球赛
void AppointGame()
{
    
}

//查看单个用户预约的所有球赛
void GetAppoint()
{
    
}


//球员&球队服务
//登记球员
void RecordPlayer()
{
    
}

//登记团队
void RecordTeam()
{
    
}

//




int main()
{
    
    mysql();
    login();
    
    int role;
//    role = CheckRole();
        char sql_check_role[100];
        sprintf(sql_check_role, "select role from user where uname = '%s'", uname);
    
        MYSQL_RES *res=mysql_store_result(pconn);
        MYSQL_ROW row = mysql_fetch_row(res);

    printf("hah%s", row[0]);
    role = atoi(row[0]);
    
    

    if(role==0)
    {
        while(1){

            int choose;
            printf("请输入你要执行的操作：\n");
            printf("1.获取球赛列表 2.搜索球赛 3.退出\n");
            scanf("%d", &choose);

            switch(choose)
            {
                case 1: GetGames();break;
                case 2: SearchGame();break;
                case 3: return 0;
            }

        }
    }

    if(role==1)
    {
        while(1){

            int choose;
            printf("请输入你要执行的操作：\n");
            printf("1.预约球赛 2.添加球赛 3.查看用户预约的球赛 4.退出\n");
            scanf("%d", &choose);


            switch(choose)
            {
                case 1: AppointGame();break;
                case 2: CreatGame();break;
                case 3: GetAppoint();break;
                case 4: return 0;
            }

        }


    }

    if(role==2)
    {
        while(1){

            int choose;
            printf("请输入你要执行的操作：\n");
            printf("1.预约球赛 2.创建游戏 3.获取预约的球赛 4.登记球员 5.登记球队 6.退出\n");
            scanf("%d", &choose);

            switch(choose)
            {
                case 1: AppointGame();break;
                case 2: CreatGame();break;
                case 3: GetAppoint();break;
                case 4: RecordPlayer();break;
                case 5: RecordTeam();break;
                case 10: return 0;
            }
        }
    }
    
    
    mysql_close(pconn);
}
