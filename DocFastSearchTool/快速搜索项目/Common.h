#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<thread>
#include<mutex>
#include <condition_variable>
#include<algorithm>
#include".\sqlite\sqlite3.h"
#pragma comment(lib,".\\sqlite\\sqlite3.lib")
using namespace std;

#define MAX_SQL_SIZE 256
#define DOC_DB "my_db"
#define DOC_TABLE "my_table"
#define MAX_BUF_SIZE 256
#define title  "DocFastSerachTool"


#ifndef __TRACE__
//#define __TRACE__
#endif

#ifndef __DEBUG__
//#define __DEBUG__
#endif

///////////////////////////////////////////////////////////////////////
static std::string GetFileName(const std::string& path)
{
	char ch = '/';  //Linux   

#ifdef _WIN32      
	ch = '\\';
#endif 
	size_t pos = path.rfind(ch);
	if (pos == std::string::npos)
		return path;
	else
		return path.substr(pos + 1);
}

//���ڵ���׷�ݵ�trace log
inline static void __TraceDebug(const char* filename, int line, const char* function, const char* format, ...)
{
#ifdef __TRACE__
	//������ú�������Ϣ
	fprintf(stdout, "[TRACE][%s:%d:%s]:", GetFileName(filename).c_str(), line, function);

	//�ɱ����
	//����û����trace��Ϣ
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);

	fprintf(stdout, "\n");
#endif
}

inline static void __ErrorDebug(const char* filename, int line, const char* function, const char* format, ...)
{
#ifdef __DEBUG__
	//������ú�������Ϣ
	fprintf(stdout, "[ERROR][%s:%d:%s]:", GetFileName(filename).c_str(), line, function);

	//����û����trace��Ϣ
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);

	fprintf(stdout, " errmsg:%s, errno:%d\n", strerror(errno), errno);
#endif
}

#define TRACE_LOG(...) \
	__TraceDebug(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);

#define ERROR_LOG(...) \
	__ErrorDebug(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);