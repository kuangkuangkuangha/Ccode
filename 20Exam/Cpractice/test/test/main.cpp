
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
int role;

void registe()
{
    
}









int login()
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
        return  0;

    }
    
    MYSQL_RES *res = mysql_store_result(pconn);
    unsigned long long colume = mysql_num_rows(res);
    if(colume>0)
    {
        printf("登陆成功\n");
        return 1;
    }else
    {
        printf("登陆失败\n");
        return 0;
    }
    
}




void AddGame()
{
    char teamA[50];
    char teamB[50];
    char place[50];
    int tidA, tidB;
    char sql_select_tnameA[100];
    char sql_select_tnameB[100];

    char sql_insert_game[100];
    
    
    printf("现在是添加球赛界面:\n");
    
    printf("请输入主队的队名：\n");
    scanf("%s", teamA);
    printf("请输入客队的队名：\n");
    scanf("%s", teamB);
    printf("请输入比赛地点：\n");
    scanf("%s", place);
    
    
    
    sprintf(sql_select_tnameA, "select tid from team where tname = '%s' ", teamA );
//    printf("%s\n", sql_select_tnameA);
    sprintf(sql_select_tnameB, "select tid from team where tname = '%s' ", teamB );
    
    if(mysql_query(pconn, sql_select_tnameA))
    {
        printf("A查询失败\n");
    }else
    {
        printf("A查询成功\n");
        MYSQL_RES *resA = mysql_store_result(pconn);
        MYSQL_ROW rowA=mysql_fetch_row(resA);
        
        tidA = atoi(rowA[0]);
        printf("hahah%d", tidA);
        
        printf("主队ID是：%d\n", atoi(rowA[0]));
            }
    
    
    if(mysql_query(pconn, sql_select_tnameB))
    {
        printf("B查询失败\n");
    }else
    {
        printf("B查询成功\n");
        MYSQL_RES *resB = mysql_store_result(pconn);
        MYSQL_ROW rowB=mysql_fetch_row(resB);
        printf("客队ID是：%d\n", atoi(rowB[0]));
        tidB = atoi(rowB[0]);
    }

    sprintf(sql_insert_game, "insert into game(tidA, tidB, gplace)value(%d, %d, '%s')", tidA, tidB, place);

    if(mysql_query(pconn, sql_insert_game))
    {
        printf("添加球赛失败，错误为：%s\n", mysql_error(pconn));
    }else
    {
        printf("添加球赛成功\n");
    }

}




void mysql()
{
    if(!mysql_real_connect(pconn, "localhost", "root", "zk2824895143", "20Exercise", 3306, NULL, 0))
    {
        printf("连接失败,错误为：%s\n", mysql_error(pconn));
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
int CheckRole()
{
    char sql_check_role[100];
    sprintf(sql_check_role, "select * from user where uname = '%s'", uname);
//    printf("%s\n", sql_check_role);
    
    if(mysql_query(pconn, sql_check_role))
    {
        printf("查询失败\n");
    }
    else
    {
        printf("查询成功\n");
    }

    MYSQL_RES *res=mysql_store_result(pconn);
    MYSQL_ROW row=mysql_fetch_row(res);

    printf("用户权限是%d\n", atoi(row[3]));
    return atoi(row[3]);
}



// 用户
//获取球赛列表
void GetGames()
{
    
}

void SearchGame()
{
    printf("请输入你要查询的队名:\n");
    
}

//注册
void Registe()
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
    char sql_select_id[100];
    char sql_getappoint[100];
    int uid;
//    char get_appoint[100];
    
    sprintf(sql_select_id, "select uid from user where uname = '%s'", uname);
    if(mysql_query(pconn, sql_select_id))
    {
        printf("查询失败，错误为%s", mysql_error(pconn));
    }
    MYSQL_RES *res = mysql_store_result(pconn);
    MYSQL_ROW row = mysql_fetch_row(res);
    
    uid = atoi(row[0]);
    printf("用户ID是%d\n",uid);
    
    
    sprintf(sql_getappoint, "select gid from user_game where uid = %d", uid);
    if(mysql_query(pconn, sql_getappoint))
    {
        printf("查询失败，错误为%s", mysql_error(pconn));
    }
    
    MYSQL_RES *resA = mysql_store_result(pconn);
    MYSQL_ROW rowA ;
    
    while ((rowA=mysql_fetch_row(resA)))
    {
        printf("预约的球赛编号是%d\n", atoi(rowA[0]));
    }

}


//球员&球队服务
//登记球员
void RecordPlayer()
{
    
}

//登记团队
void RecordTeam()
{
    char name[100];
    char city[100];
    printf("请输入团队名称：\n");
    scanf("%s", name);
    
    printf("%s\n", name);
    printf("请输入球队所在的城市\n");
    scanf("%s", city);
    
    char sql_insert_team[100];
    sprintf(sql_insert_team, "insert into team (tname, tcity)value('%s', '%s')", name, city);
    
    if(mysql_query(pconn, sql_insert_team))
    {
        printf("登记球队失败,错误为：%s\n", mysql_error(pconn));
    }else
    {
        printf("登记球队成功\n");
    }
    
}

//超级管理员
void ChangeRole()
{
    char name[100];
    char sql_update_role[100];
    
    int role2;
    
    printf("请输入你想修改的用户名:\n");
    scanf("%s", name);
    
    printf("请输入修改后的权限：\n");
    printf("1.普通用户 2.前台管理员 3.超级管理员\n");
    scanf("%d", &role2);
    
    sprintf(sql_update_role, "update user set role=%d where uname = '%s'", role2, name);
    if(mysql_query(pconn, sql_update_role))
    {
        printf("修改权限失败\n");
    }else
    {
        printf("修改权限成功\n");
    }
    
    
}



int main()
{
    
    mysql();
    int state=login();
    if(state==0)
        return 0;
    
    role=CheckRole();
    
    if(role==0)
    {
        printf("欢迎用户登陆\n");
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
        printf("欢迎管理员登陆\n");
        
        while(1)
        {
            int choose;
            printf("请输入你要执行的操作：\n");
            printf("1.预约球赛 2.添加球赛 3.查看用户预约的球赛 4.退出\n");
            scanf("%d", &choose);


            switch(choose)
            {
                case 1: AppointGame();break;
                case 2: AddGame();break;
                case 3: GetAppoint();break;
                case 4: return 0;
            }

        }


    }

    if(role==2)
    {
        printf("欢迎最高管理员登陆\n");
        while(1){

            int choose;
            printf("请输入你要执行的操作：\n");
            printf("1.预约球赛 2.创建游戏 3.获取预约的球赛 4.登记球员 5.登记球队 6.修改权限 7.退出\n");
            scanf("%d", &choose);

            switch(choose)
            {
                case 1: AppointGame();break;
                case 2: AddGame();break;
                case 3: GetAppoint();break;
                case 4: RecordPlayer();break;
                case 5: RecordTeam();break;
                case 6: ChangeRole();break;
                case 7: return 0;
            }
        }
    }
    
    
    mysql_close(pconn);
}
