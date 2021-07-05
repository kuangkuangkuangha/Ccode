#include <stdio.h>

#define num 12
int KMP(char S[],char T[])
{
    int i=0,j=0,k;
    int index=0;
    int next[num]={0};
    int flag;
    memset(next,0,num*sizeof(int));
    next[0]=0;

    for(i=1;T[i]!='\0';i++)
    {
        k=next[i-1];
        flag=i-1;
        while(k>=1 && T[i]!=T[k])
        {
            flag --;
            k=next[flag];
        }
        if(T[i]==T[k])
        {
            next[i]=k+1;
        }
        else
        {
            next[i]=0;
        }
    }

	while(S[i]!='\0' && T[j]!='\0')
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			j=j-next[j+1];
			index++;
			i=index;
		}
	}
        if(T[j]=='\0')
			return index+1;
		else
			return -1;
}


void Merge(int temp[], int l, int m, int r)
{
    int left_size = m-l;
    int right_size = r-m+1;
    int left[left_size];
    int right[right_size];
    
    int j,k,n;
    for(j=l; j<m; j++)
    {
        left[j-l] = temp[j];
    }

    for(k=m; k<=r; k++)
    {
        right[k-m] = temp[k];
    }

    j=0; k=0; n=l;
    while(j<left_size && k<right_size)
    {
        if(left[j]<right[k])
        {
            temp[n]=left[j];
            j++;
            n++;
        }else
        {
            temp[n]=right[k];
            k++;
            n++;
        }
    }

    while(j<left_size)
    {
        temp[n]=left[j];
        n++;
        j++;
    }
    while(k<right_size)
    {
        temp[n]=right[k];
        n++;
        k++;
    }

}

void mergesort(int temp[], int L, int R)
{
    int M=(L+R)/2;
    if(L==R)
    {
        return;
    }else
    {
        mergesort(temp, L, M);
        mergesort(temp, M+1, L);
        Merge(temp, L, M-1, R);   // M-1  ??
    }
}


int main()
{
    // int a[]={2,8,9,43,6,29,65};
    // Merge(a,0,4,7);

    // for(int i=0; i<8; i++)
    // {
    //     printf("%d\n", a[i]);
    // }

    int i;
    char S[]="ababcaababbabccbab";
	char T[]="ababbab";
	i=KMP(S,T);
	printf("%d",i);
    return 0;

    return 0;
}
