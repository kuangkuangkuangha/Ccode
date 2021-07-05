#include <stdio.h>
#define NUM 5

int value[NUM] = {6,3,5,4,6}; 
int weight[NUM] = {2,2,6,5,4};
 
// w表示背包中的位置剩余,i表示第i个物品
int try(int w, int i)
{

	if(w==0 || i==NUM)     // 当背包中没位置了,(这就是递归结束的条件！)
	return 0;               // 程序正常退出，并不是返回一个零
	
	if(weight[i] > w)
		return try(w, i+1);
	
	else 
    {
		int value1 = try(w , i+1) ;
		int value2 = try(w - weight[i], i+1) + value[i];
		
		if (value1 < value2)
        {
			return value2;
		}
		else
        {
			return value1;
		}
	}
}

int main()
{
    int max;
    max = try(10, 0);
    printf("%d", max);
    return 0;
}