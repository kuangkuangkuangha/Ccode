//
//  main.c
//  login
//
//  Created by 张旷 on 2021/7/10.
//

#include <stdio.h>
#include </usr/local/mysql/include/mysql.h>

int main()

{
    char name[10];
    int age = 0;
    char sex[20];
    char sql[200];
    
    // 拼接字符串
    sprintf(sql, "insert into userinfo value (null, '%s', %d, '%s')", name, age, sex);
    sprintf(sql, "update userinfo set ugender ='%s' ,name ='%d' where id = %d," , name, age , age );
    
    
    printf("hello world\n");
    return 0;
}
