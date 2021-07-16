#include <stdio.h>
// using namespace std;

// typedef struct
// {
//     int id;
//     char name[50];
//     float price;
// }dish;

// dish dish1={1, "拍黄瓜", 11.5};
// dish dish2={2, "地三鲜", 13};
// dish dish3={3, "酸菜鱼", 25};
// dish dish4={4, "炒生菜", 25.5};
// dish dish5={5, "佛跳墙", 9.9};

int main()
{
    int temp;
    int a[5]={0};
    int j,k=0;
    float sum=0;

    printf("今日菜品:\n");
    printf("编号-----菜名-----价格\n");
    printf(" 1      拍黄瓜    11.5\n");
    printf(" 2      地三鲜    13\n");
    printf(" 3      酸菜鱼    25\n");
    printf(" 4      炒生菜    25.5\n");
    printf(" 5      破跳墙    9.9\n");

    while(1)
    {
        printf("请输入您的操作编号：(1.点餐 2.退出系统)\n");       
        scanf("%d", &temp);

        if(temp==1)
        {
            printf("请输入菜品编号：\n");
            scanf("%d", &j);
            switch(j)
            {
                case 1: a[k]=1, k++; break;
                case 2: a[k]=2, k++; break;
                case 3: a[k]=3, k++; break;
                case 4: a[k]=4, k++; break;
                case 5: a[k]=5, k++; break;
            }

        }else
        {
            printf("-----------------\n");
            printf("您的菜单如下：\n");
            for(int i=0; i<5; i++)
            {
                switch(a[i])
                {
                    case 1: printf(" %d      拍黄瓜    11.5\n", i+1); sum+=11.5; break;
                    case 2: printf(" %d      地三鲜    13\n", i+1); sum+=13; break;
                    case 3: printf(" %d      酸菜鱼    25\n", i+1); sum+=25; break;
                    case 4: printf(" %d      炒生菜    25.5\n", i+1); sum+=25.5; break;
                    case 5: printf(" %d      破跳墙    9.9\n", i+1); sum+=9.9; break;

                }

            }

            printf("总计：%f\n", sum);
            return 0;
        }
    }
}
