#include"tree.h"

int main()
{
	int ino[] = {4,2,1,5,3,6};
	int pos[] = { 4,2,5,6,3,1 };
	Node* root=buildTree(ino, 6, pos, 6);
	system("pause");
	return 0;

}