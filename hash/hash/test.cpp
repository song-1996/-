#include"HashBucket.hpp"
int main()
{
	HashBucket<int> h;
	h.Insert(3);
	h.Insert(13);
	h.Insert(23);
	h.Insert(12);
	h.Insert(2);
	h.Insert(22);
	h.Insert(5);
	h.Insert(55);
	h.Insert(15);
	h.clear();
	system("pause");
	return 0;
}