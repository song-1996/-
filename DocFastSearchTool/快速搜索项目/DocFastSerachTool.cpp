#define _CRT_SECURE_NO_WARNINGS 1
#include"ScanManager.h"
//void Test_DirectoryList()
//{
//	string path = "F:\\cÓïÑÔ\\ÏîÄ¿ºÍ¸´Ï°\\¸´Ï°";
//	vector<string> dirfile, subfile;
//	DirectoryList(path,dirfile,subfile);
//	for (auto& e : dirfile)
//		cout << e << endl;
//	for (auto& e : subfile)
//		cout << e << endl;
//}

int main(int argc,char* argv[])
{
	//Test_DirectoryList();
	ScanManager& s=ScanManager::CreateInstance("F:\\cÓïÑÔ\\ÏîÄ¿ºÍ¸´Ï°\\¸´Ï°\\A");
	//s.ScanDirectory("F:\\cÓïÑÔ\\ÏîÄ¿ºÍ¸´Ï°\\¸´Ï°\\A");
	DataManager& db = DataManager::CreateInstance();
	while (1)
	{
		DrawMenu();
		string key;
		cin >> key;
		if (key == "exit")
			break;
		vector<pair<string, string>> ret;
		db.Seach(key,ret);
		int pos = 5;
		for (auto &it : ret)
		{
			SetCurPos(2, pos);
			string prefix, hightlight, suffix;
			db.SplitHightLight(it.first, key, prefix, hightlight, suffix);
			PrintfSearchstr(prefix, hightlight, suffix);
			SetCurPos(52, pos);
			printf("%-65s", (it.second).c_str());
			pos++;
			Next_line(pos);
		}
		ret.clear();
		SystemEnd();
		system("pause");
	}
	SystemEnd();
	return 0;
}


//test windows fun
/*
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
void SetPos(short x, short y)
{
	COORD point = { x,y };
	SetConsoleCursorPosition(handle, point);
}
void Hidehandle()
{
	CONSOLE_CURSOR_INFO cur_info = { 1,0 };
	SetConsoleCursorInfo(handle, &cur_info);
}
int main()
{
	char str[128] = { 0 };
	const char* title = "¿ìËÙÎÄµµËÑË÷¹¤¾ß";
	sprintf(str, "title %s", title);
	system(str);
	memset(str, 0, 128);
	int x = 120, y = 40;
	sprintf(str, "mode con cols=%d lines=%d",x,y);
	system(str);
	system("color 0F");
	SetPos((120 - (short)strlen("»¶Ó­Äã")) / 2, 0);
	printf("»¶Ó­Äã");
	Hidehandle();
	system("pause");
	return 0;
}
*/

