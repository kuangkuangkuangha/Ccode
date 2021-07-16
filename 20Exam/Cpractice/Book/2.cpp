#include <iostream>
#include <typeinfo>
#include </usr/local/mysql/include/mysql.h>
using namespace std;

int main()
{
    MYSQL ceshi;
    mysql_init(&ceshi);   //初始化MYSQL变量
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num;        //用来存放结果集列数
    int i;
    
    if (mysql_real_connect(&ceshi, "127.0.0.1", "root", "root", "testgbk", 0, 0, 0))  //连接到mysql 账号 密码 数据库名 端口
    {
        cout << "\n\t-----MySQL已连接----" << endl;
    }

    if (!mysql_query(&ceshi, "SELECT * FROM runoob_tbl"))   //若查询成功返回0，失败返回随机数
    {
        cout << "\n\t  ----查询成功----" << endl;
    }

    result = mysql_store_result(&ceshi);    //将查询到的结果集储存到result中
    num = mysql_num_fields(result);        //将结果集列数存放到num中

    while ((row = mysql_fetch_row(result)))  //遇到最后一行中止
    {
        for (i = 0; i < num; i++)         //输出该行的每一列
        {
            cout << row[i]<< "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
            cout << endl;
        }
        cout << endl;
    }
    mysql_free_result(result);     //释放结果集所占用的内存
    mysql_close(&ceshi);          //关闭与mysql的连接

}
