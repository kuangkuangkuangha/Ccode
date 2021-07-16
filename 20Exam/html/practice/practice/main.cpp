//
//  main.cpp
//  practice
//
//  Created by 张旷 on 2021/7/9.
//

#include <stdio.h>
#include </usr/local/mysql/include/mysql.h>

int main()
{
    MYSQL *pconn = mysql_init(0);
    
    if(!mysql_real_connect(pconn, "locahost", "root", "zk2824895143", "20Exercise", 0, 0, 0))
    {
        printf("连接失败, 错误为%s\n", mysql_error(pconn));
    }
    printf("连接成功\n");
    
}
