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
//系统功能函数模块
void DirectoryList(const string &path, vector<string> &subfile, vector<string> &subdir);

// 汉字转拼音全拼
/* CSDN：http://blog.csdn.net/csnd_ayo */
string ChineseConvertPinYinAllSpell(const string& dest_chinese);
// 汉字转拼音首字母
string ChineseConvertPinYinInitials(const string& name);

// 颜色高亮显示一段字符串
void ColourPrintf(const string  &str);

void PrintfSearchstr(string &prefix, string &hightlight, string &suffix);

void Next_line(int pos);
