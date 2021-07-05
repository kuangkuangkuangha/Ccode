#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isPrime(int n)// 判断n是否为素数
{
	int i,k;
	k = (int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int canPlace(int *p,int i,int j,int n)// 判断j是否可以放在p[i]上
{
	int k,flag;
	for(k=0;k<i;k++)// 判断j在之前已定的数中是否已经出现过
	{
		if(p[k]==j)
			return 0;
	}

	// j和前面一个的数的和是不是为素数
	flag = isPrime(j+p[i-1]);

	// 到了最后一个元素，n是素数环元素个数
	// 最后一个元素要和第一个元素的和为素数，也要和前一个元素的和为素数
	if(flag==1 && i==n-1)
	{
		flag = isPrime(j+p[0]);
		// j+p[0]是素数则可，不是则不可以
	}
	return flag;
}

void showResult(int *p,int n)
{
	int i;
	static int count = 0;
	printf("****第%d个解****\n",++count);
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

void primeCycle(int n)
{
	int i=1,j,k;
	int *p = (int *)malloc(sizeof(int)*n);
	memset(p,0,n*sizeof(int));
	p[0] = 1;

	
	while(i>=1)// 回溯核心代码
	{
		// 判断环中第i个元素放啥
		/*  j = p[i]+1 是为了p[i--]时回溯，n=4,比如p[0]=1,p[1]=2,p[2]=3,p[3]=4 
			此时i=3, p[i--]=0就可以将p[3]置为0，i置为2，j=p[2]+1=4,  就可以讨论1，2，4，3这种情况（回溯）
		*/
		for(j=p[i]+1;j<=n;j++)			
		{
			if(canPlace(p,i,j,n)==1)	
			{
				p[i] = j;
				break;  // break之后就进行下面的if判断
			}
		}

		// 这里判断结果，要么是环放完了打印结果，要么是判断下一个位置放啥
		// 执行到这里就说明1～n中没有可以放的数，此时j=n+1，
		if(j>n)
		{
			p[i--] = 0;    // 找到的数已经>n了，所以要把这个数置0，回到上一个数
		}

		else if(i==n-1)
		{
			showResult(p,n);
			p[i--] = 0;
		}
		else
			i++;
	}
	free(p);
	printf("finished\n");
}

int main()
{
	int n;
	printf("Input an integer\n");
	scanf("%d",&n);
	primeCycle(n);

	return 0;
}
