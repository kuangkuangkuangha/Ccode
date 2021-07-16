#include<stdio.h>

#include<winsock.h>
#include<mysql.h>


int main() 
{
	int n = 100;
	//初始化mysql
	MYSQL *pconn= mysql_init(0);

	//连接数据库 (1.初始化数据信息 2.连接地址 3.账号 4.密码 5.数据库名称)
	if (!mysql_real_connect(pconn, "localhost", "root", "root", "empdb", 0, 0, 0))
	{
		printf("连接失败,错误为:%s\n",mysql_error(pconn));
	}
	printf("连接成功！\n");
	
	//初始化编码问题
	if (mysql_query(pconn,"set names gbk")) 
	{
		printf("编码有错误为:%s\n", mysql_error(pconn));
	}

	//添加
	/*if (mysql_query(pconn, "INSERT into userInfo VALUE (null,'llii',21,'女')"))
	{
		printf("添加失败,错误为:%s\n", mysql_error(pconn));
	}
	else {
		printf("添加成功\n");
	}


	//修改
	if (mysql_query(pconn, "UPDATE userinfo set ugender='女' where uid in (4,5,7)"))
	{
		printf("修改失败,错误为:%s\n", mysql_error(pconn));
	}
	else {
		printf("修改成功\n");
	}

	//删除
	if (mysql_query(pconn, "delete from userinfo where uid =7"))
	{
		printf("删除失败,错误为:%s\n", mysql_error(pconn));
	}
	else {
		printf("删除成功\n");
	}*/

	//查询
	if (mysql_query(pconn, "select * from userInfo"))
	{
		printf("查询失败,错误为:%s\n", mysql_error(pconn));
	}
	 //用一个容器来接受查询的结果
	MYSQL_RES *res = mysql_store_result(pconn);
	//利用游标去读取数据,读取的是每一行数据
	MYSQL_ROW row;

	while (row = mysql_fetch_row(res))
	{
		printf("%s\t%s\t%s\t%s\n",row[0],row[1], row[2], row[3]);
	}

	exit:m
	system("pause");
	return 0;
}
