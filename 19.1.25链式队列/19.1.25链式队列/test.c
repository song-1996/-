#include"Queue.h"

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
	returnSize = (int*)malloc(sizeof(int) * 1000);
	int i = 0,  k = 0;
	while (i < findNumsSize)
	{
		int j = 0;
		while (j < numsSize)
		{
			if (findNums[i] == nums[j])
			{
				if (findNumsSize < numsSize&&nums[j] < nums[j + 1])
				{
					returnSize[k] = nums[j + 1];
					k++;
					break;
				}
				else
				{
					returnSize[k] = -1;
					k++;
					break;
				}
			}
			j++;
		}
		i++;
	}
	return returnSize;
}
int main()
{
	/*test();*/
	int a[] = { 4,1,2 };
	int b[] = { 1,3,4,2 };
	int* obj=NULL;
	nextGreaterElement(a, 3, b, 4, obj);
	system("pause");
	return 0;

}