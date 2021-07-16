#include <stdio.h>

int main()
{
    int a[30];
    int people[15];
    int temp=0;

    // int count=0;
    printf("haha");
    
    for(int i=0; i<30; i++)
    {
        a[i]=i+1;
    }

    while(temp<15)
    {
        for(int k=0; k<30; k++)
        {
            if(a[k]==0)
            {
                break;
            }

            if(a[k]%9==0)
            {
                a[k]=0;
                people[temp]=a[k];
                temp++;
            }
        }
    }

    for(int i=0; i<15; i++)
    {
        printf("%d", people[i]);
    }

    return 0;
}