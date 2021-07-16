#include <stdio.h>
#include <stdlib.h>

char pos[3][3];

//1.首先打印棋盘
//2.玩家落子
//3.判定胜负
//4.电脑落子
//5.判定胜负

// 1.打印棋盘
void init()
{

    for(int j=0; j<3; j++)
    {
        for(int k=0; k<3; k++)
        {
            pos[j][k]=' ';
        }
    }
}

// 2.玩家落子
void player()
{
    int x,y;
    printf("请输入你要落子的坐标：\n");
    scanf("%d-%d", &x, &y);

    pos[x-1][y-1]='*';

    for(int i=0; i<3; i++)
    {
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n", pos[i][0], pos[i][1], pos[i][2]);
    }
    printf("+---+---+---+\n");
}


// 判断
int judgeA()
{
    //横向
    for(int i=0; i<3; i++)
    {
        if(pos[i][0]==pos[i][1] && pos[i][0]==pos[0][2] && pos[i][0]!=' ' && pos[0][i]=='*' )
        {
            return 1;
        }
    }

    //纵向
    for(int i=0; i<3; i++)
    {
        if(pos[0][i]==pos[1][i] && pos[0][i]==pos[2][i] && pos[0][i]!=' ' && pos[0][i]=='*')
        {
            return 1;
        }
    }

    //右斜
    if(pos[0][0]==pos[1][1] && pos[0][0]==pos[2][2] && pos[0][0]!=' ' && pos[0][0]=='*')
    {
        return 1;
    }

    if(pos[2][0]==pos[1][1] && pos[2][0]==pos[0][2] && pos[2][0]!=' '  && pos[0][0]=='*')
    {
        return 1;
    }

    return 0;
}

int judgeB()
{
    //横向
    for(int i=0; i<3; i++)
    {
        if(pos[i][0]==pos[i][1] && pos[i][0]==pos[0][2] && pos[i][0]!=' ' && pos[0][i]=='&' )
        {
            return 2;
        }
    }

    //纵向
    for(int i=0; i<3; i++)
    {
        if(pos[0][i]==pos[1][i] && pos[0][i]==pos[2][i] && pos[0][i]!=' ' && pos[0][i]=='&')
        {
            return 2;
        }
    }

    //右斜
    if(pos[0][0]==pos[1][1] && pos[0][0]==pos[2][2] && pos[0][0]!=' ' && pos[0][0]=='&')
    {
        return 2;
    }

    if(pos[2][0]==pos[1][1] && pos[2][0]==pos[0][2] && pos[2][0]!=' '  && pos[0][0]=='&')
    {
        return 2;
    }

    return 0;
}


// 电脑落子
void comp()
{
    int i=rand()%3;
    int j=rand()%3;
    printf("%d-%d\n", i, j);
    if(pos[i][j]=='*')
    {
        i=rand()%3;
        j=rand()%3;
        pos[i][j]='&';
    }else
    {
        pos[i][j]='&';
    }
   

    for(int i=0; i<3; i++)
    {
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n", pos[i][0], pos[i][1], pos[i][2]);
    }
    printf("+---+---+---+\n");
}


int main()
{
    int count;
    init();

    while (1)
    {
        player();
        comp();
        int k = judgeA();
        if(k==1)
        {
            printf("恭喜你战胜了人工智障\n");
            return 0;
        }
        
        int p = judgeB();
        if(p==2)
        {
            printf("下次再玩\n");
            return 0;
        }
    }
    

}