#pragma once
#include"Common.h"
#include<io.h>
#include<stdarg.h>

#define Height 30
#define Width 120
////////////////////////////////////////////////////////////////////////////////////////////////
void SetCurPos(short x, short y);
void Hidehandle();
void Draw_H_W(int x, int y);
void DrawFrame();
void DrawMenu();
void SystemEnd();

////////////////////////////////////////////////////////////////////////////////////////////////

size_t GetFileCount(const string &path);
/////////////////////////////////////////////////////////////////////////////////////////////////
//ϵͳ���ܺ���ģ��
void DirectoryList(const string &path, vector<string> &subfile, vector<string> &subdir);

// ����תƴ��ȫƴ
/* CSDN��http://blog.csdn.net/csnd_ayo */
string ChineseConvertPinYinAllSpell(const string& dest_chinese);
// ����תƴ������ĸ
string ChineseConvertPinYinInitials(const string& name);

// ��ɫ������ʾһ���ַ���
void ColourPrintf(const string  &str);

void PrintfSearchstr(string &prefix, string &hightlight, string &suffix);

void Next_line(int pos);
