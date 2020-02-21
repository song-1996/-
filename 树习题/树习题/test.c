#include"tree.h"

int main()
{
	int arr[] = { 10,5,'#','#',15,6,'#','#',20,'#','#' };
	Node* root = CreatBTree(arr, 11);
	int ret = isValidBST(root);
	system("pause");
	return 0;

}