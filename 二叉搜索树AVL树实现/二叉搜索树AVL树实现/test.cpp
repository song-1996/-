#include"AVLTree.hpp"
#include"RBTree.hpp"
#include"BSTree.hpp"


int main()
{
	/*
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4,2,6,1,3,5,15,7,16,14 };
	AVLTree<int> l;
	//16, 3, 7, 11, 9, 26, 18, 14, 15
	for (auto e : arr)
		l.Insert(e);
	l.InOrder();
	if (l.IsBalanceTree())
		cout << "Banlance Tree" << endl;
	else
		cout << "not Banlance Tree" << endl;
		*/
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };
	RBTree<int> r;
	for (auto e : arr)
		r.Insert(e);

	return 0;
}