#include <stdio.h>
#include <stdlib.h>



// 矩阵乘法实验
int* matProduct(int *a, int *b, int rowa, int cola ,int rowb, int colb)
{
	int *p, *arow, *bcol;//p��ʾ����˷������һά�ṹ��arow��ʾ����a��һ�У�bcol��ʾ����b��һ��
	int i,j;
	if(cola!=rowb)
	{
		printf("Error!\n");
		return 0;
	}
	realloc( *p, 8*sizeof(int)+1);
	realloc( *arow, 6*sizeof(int));
	realloc( *bcol, 12*sizeof(int));
	for(i=0;i<rowa;i++)
	{
		arow=a++;
		for(j=0;j<colb;j++)
		{
			bcol=b[0];
			bcol+=j;
			*(p++)=(**arow)*(**bcol)+(*((*arow)+1))*(*(bcol+4))+(*((*arow)+2))*(*(*bcol+8));
		}
	}
	free(arow,bcol);
	p=p-8;
	return p;
}

void main()//���Դ���
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int b[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (*p)[4]=(int(*)[4])matProduct((int*)a, (int*)b, 2,3,3,4);
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",p[i][j]);
			printf("\n");
		}
	}
	free(p);
}
	