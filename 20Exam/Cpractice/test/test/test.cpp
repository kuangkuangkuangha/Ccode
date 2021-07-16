//
//  main.cpp
//  test
//
//  Created by 张旷 on 2021/7/9.
//

#include </usr/local/mysql/include/mysql.h>
//#include<mysql.h>
//#include <stdio.h">
#include <iostream>
using namespace std;

//把下面配置信息修改为自己数据库的
const char host[] = "localhost";
const char user[] = "root";
const char pwd[] = "zk2824895143";
const char database[] = "20Exercise";
unsigned int port = 3306;

//int registe(MYSQL *p)
//{
//    char name[50];
//    int pwd[10];
//    char sex[2];
//
//    printf("注册用户名：/n");
//    scanf("%s", name);
//
//    return 0;
//}

int main()
{
    
    MYSQL myCont;
    mysql_init(&myCont);
    if (mysql_real_connect(&myCont, host, user, pwd, database, port, NULL, 0)){
//        cout << "Hello MySQL！" << endl;
        printf("Hello Mysql");
        
    }
    else
    {
        cout << "connect failed!" << endl;
        
    }
    
    
    
    
    
    
    char sql [200];
    
    sprintf(sql, "select * from empinfo where eName like '%s%%' ", "l");
    cout <<sql << endl;
    
    if(mysql_query(&myCont, sql))
    {
        cout << "查询失败" << endl;
    }
    else
    {
        cout << "查询成功" << endl;
    }
    
    MYSQL_RES *res = mysql_store_result(&myCont);
    MYSQL_ROW row;
    
    while(row = mysql_fetch_row(res))
    {
        cout << row[0] << row[1] << row [2] << row[3] << endl;
    }
    
    

    
    
    
//   添加操作
    /*
     if(mysql_query(&myCont, "insert into empinfo value(null,'张', 20, '男')"))
    {
        cout << "插入失败" << endl;
    }
    else
    {
        cout << "插入成功" << endl;
    }
    */
    
//   修改操作
    /*
     if(mysql_query(&myCont, "update empinfo set eGender='女' where eName = '张'"))
    {
        cout << "修改失败" << endl;
    }
    else
    {
        cout << "修改成功" << endl;
    }
    */
    
//   查询操作
    /*
     if(mysql_query(&myCont, "select * from empinfo"))
    {
        cout << "查询成功" <<endl;
    }
    else
    {
        cout << "查询失败" <<endl;
    }
    
    MYSQL_RES *res = mysql_store_result(&myCont);
    MYSQL_ROW row;
    
    while (row = mysql_fetch_row(res)) {
        cout << row[0] << row[1] << row[2] << row[3] <<endl;
        //printf("haha");
    }
    */
    
// 删除操作
    /*
     if(mysql_query(&myCont, "delete from empinfo where eid = 3"))
    {
        cout << "删除失败" << endl;
    }else
    {
        cout << "删除成功" << endl;
    }
     */
    
    mysql_close(&myCont);
    return 0;
}


