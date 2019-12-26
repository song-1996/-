#include"Stack.h"
int main()
{
	BTNode* root=NULL;
	BTNode* Newroot = NULL;
	BTNode* aim = NULL;
	BTDataType str[] = {1,2,2,3,3,'#','#',4,4,'#','#','#','#','#','#' };
	root = CreatBTree(str, sizeof(str)/sizeof(str[0]));
	int arr1[] = { 1,2,4,7,3,5,6,8 };
	int arr2[] = { 4,7,2,1,5,3,8,6 };
	//Newroot = CopyBinTree(root);
	//LevelOrder(root);
	//printf("\n");
	//PreOrder(root);
	//printf("\n");
	//PreOrderNor(root);
	//printf("\n");
	//InOrder(root);
	//printf("\n");
	//InOrderNor(root);
	//printf("\n");
	//PostOrder(root);
	//printf("\n");
	//PostOrderNor(root);
	//printf("\n");
	//printf("Leafcount=%d,Nodecount=%d,height=%d,\n", GetLeafCount(root),
	//		GetNodeCount(root), Height(root));
	//printf("root=%c\n", FindRoot(root));
	//printf("%d\n", FindNode(root, 'Q'));
	//printf("第%d层节点的个数=%d\n", 3, GetKlevelNodeCount(root, 3));
	//printf("第%d层节点的个数=%d\n", 7, GetKlevelNodeCount(root, 7));
	//aim=GetNodeParent(root, GetNode(root, 'C'));
	//int k=isBalanced(root);
	BTNode* root1=reConstructBinaryTree(arr1, arr2, 8);
	DestroyBTree(&root);
	system("pause");
	return 0;

}
