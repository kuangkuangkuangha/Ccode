#include <stdio.h>
#define N 10

int main()
{
	int i,j;
	int a[N]={5,9,6,4,8,2,3,1,7,0};
	int tag=N-1;//最后一次交换位置的下标 
	int t;//交换操作中间变量 
	int n=0;//while循环终止条件 
	while(n!=tag)
	{
		n=tag;
		for(i=0;i<n;i++)
		{
			if(a[i]%2==0 && a[i+1]%2)
			{
				t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
				tag=i;
				continue;
			}
			if(a[i]%2 && a[i+1]%2==0)
			{
				continue;
			}
			if(a[i]>a[i+1])
			{
				t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
				tag=i;
			}
		}
	 } 
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}