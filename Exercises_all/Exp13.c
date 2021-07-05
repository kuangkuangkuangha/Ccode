#include <stdio.h>

void insert_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(a[i] < a[i-1])
        {
            int j=i-1;      // j用来搜索i前面元素的下标
            int x=a[i];

            while(j>-1 && x<a[j])
            {
                a[j+1]=a[j];
                j--;
            }

            a[j+1]=x;
        }
    }
}

int main()
{
    int temp[8]={3,7,66,45,3,37,4,5};
    insert_sort(temp, 8);

    for(int i=0; i<8; i++)
    {
        printf("%d\n", temp[i]);
    }
}