#include <iostream>

using namespace std;

int accout1 = 123, accout2 = 456;
int pwd1 = 111, pwd2 = 333;
float money1 = 9.9, money2 = 8.8;

struct user
{
    int account;
    int pwd;
    char totto[50];
};

struct user zhangkaung;

void login()
{
    int username;
    int pwd;
    cout << "请输入用户名:" << endl;
    cin >> username ;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    if(username == accout1 && pwd == pwd1)
    {
        cout << "登入成功" <<endl;
    }else
    {
        cout << username << "de用户名或密码错误" << endl; 
    }


}


int main()
{
    login();
    return 0;
}