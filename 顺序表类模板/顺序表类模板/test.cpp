#include"Seqlist.h"
int main()
{
	Seqlist<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.PushBack(5);
	s.Print();
	s.PopBack();
	s.PopBack();
	s.Print();
	s.PushFront(0);
	s.Print();
	s.PopFront();
	s.Print();
	s.SeqlistInsert(s.SeqlistFind(3), 4);
	s.Print();
	s.SeqlistErase(s.SeqlistFind(3));
	s.Print();
	s.Remove(2);
	s.PushFront(2);
	s.PushFront(2);
	s.PushFront(2);
	s.Print();
	s.RemoveAll(2);
	s.Print();
	system("pause");
	return 0;

}