#include <stdio.h>

// 输出等腰三角形
void delta()
{
    int a;
	int j, k, m, i , p;
	printf("请输入腰长：\n");
	scanf("%d", &a);
	
	//输出第一行
	for(p = 0 ; p < a-1;p++){
		printf(" ");	
	} 
		printf("*\n");
	
	//输入第二至倒数第二行 
	for (j = 2; j <= a-1; j ++){
		for(k = 0 ;k < a-j; k ++){
		printf(" ");
		}
		
		printf("*");
		
	 	for(m = 0; m < 2*j - 3; m++){
		printf(" ");
		}
		
		printf("*\n"); 
		
	}

	//输出最后一行
	for(i = 0; i < 2*a-1 ; i++)

		printf("*"); 
}

// 凸包问题
void tubao()
{
    int i, k, j;
    int a, b, c;
    int flag1, flag2;

    int x[7]={1,3,5,1,2,2,2};
    int y[7]={1,1,4,3,2,2,6};
    // 确定第一个点
    for(i=0; i<6; i++)
    {
        // 循环第二个点
        for(k=i+1; k<7; k++)
        {
            // 遍历所有的点
            flag1 = flag2 = 0;

            for(j=0; j<7; j++)
            {
                a= y[k] - y[i];
                b= x[i] - x[k];
                c= x[i]*y[k] - y[i]*x[k];

                if(a*x[j] + b*y[j] > c)
                flag1 = 1;

                if(a*x[j] + b*y[j] < c)
                flag2 = 1;

                if(flag1 == 1 && flag2== 1)
                break;
            }
            if(j == 7)
            printf("一条边是%d-%d\n", i+1, k+1);

        }
    }

}

int main()
{
    // delta();
    tubao();
}