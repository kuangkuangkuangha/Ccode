#include <iostream>
using namespace std;

int main()
{
    struct user
    {
        char name[50];
        int age;
        float weight;
    };

    struct book
    {
        int bookid;
        int bookname;    
    }one;

    one.bookid = 10086;

    struct user A;

    // A.name = "张旷";
     
    strcpy(A.name, "张旷");
    A.age = 19;
    A.weight = 60.2;

    

}