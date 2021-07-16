
//
//  main.cpp
//  test
//
//  Created by 张旷 on 2021/7/9.
//

#include </usr/local/mysql/include/mysql.h>
#include <iostream>
using namespace std;

//把下面配置信息修改为自己数据库的
const char host[] = "localhost";
const char user[] = "root";
const char pwd[] = "zk2824895143";
const char database[] = "20Exercise";
unsigned int port = 3306;



int main()
{
    
    MYSQL myCont;
    mysql_init(&myCont);
    if (mysql_real_connect(&myCont, host, user, pwd, database, port, NULL, 0))
    {
        printf("Hello Mysql\n");
    }
    else
    {
        cout << "connect failed!" << endl;
    }
    
    
    char sql [200];
    
    sprintf(sql, "select * from user where uname like '%s%%' ", "l");
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
    
    if(row = mysql_fetch_row(res))
    {
        cout << row[0] << endl;
    }
    
    
    mysql_close(&myCont);
    return 0;
}


  int role;
//    role = CheckRole();
        char sql_check_role[100];
        sprintf(sql_check_role, "select role from user where uname = '%s'", uname);
    
    if(mysql_query(pconn, sql_check_role))
    {
        printf("查询失败");
    }
    else{
        printf("查询成功");
    }
        MYSQL_RES *res=mysql_store_result(pconn);
        MYSQL_ROW row = mysql_fetch_row(res);

    printf("hah%s", row[0]);
    role = atoi(row[0]);
    