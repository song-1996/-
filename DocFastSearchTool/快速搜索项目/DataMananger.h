#pragma once
#include"Common.h"
#include"Sysutil.h"
class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	//打开数据库
	void Open(const string& path);
	//关闭数据库
	void Close();
	//执行sql语句
	void ExecuteSql(const string& sql);
	//获取表结果
	void GetTable(const string& sql, int& row, int& col, char**& ppRet);
public:
	SqliteManager(const SqliteManager&) = delete;
	SqliteManager& operator=(const SqliteManager&) = delete;
private:
	sqlite3* m_db;
};

class DataManager
{
public:
	static DataManager& CreateInstance();
	~DataManager();
private:
	DataManager();
public:
	void InitSqlite();
public:
	//向数据库中获取数据
	void GetDocs(const string &path, set<string>& docs);
	//向数据库中增加数据
	void InsertDoc(const string &path, string doc);
	//向数据库中删除数据
	void DeleteDoc(const string &path, string doc);
	//简易搜索函数
	void Seach(const string& key, vector<pair<string, string>>& doc_path);
	//分割关键字
	void SplitHightLight(const string &str, const string &key,
		string &prefix, string &hightlight, string &suffix);
	//清除数据库
	void Clear();
private:
	SqliteManager m_dbmgr;
};

class AutoGetResTable
{
public:
	//GetTable(const string& sql, int& row, int& col, char**& ppRet)
	AutoGetResTable(SqliteManager* db, const string&sql, int& row, int& col, char**& ppRet);
	~AutoGetResTable();
public:
	AutoGetResTable(const AutoGetResTable &) = delete;
	AutoGetResTable& operator=(const AutoGetResTable &) = delete;
private:
	SqliteManager* m_db;
	char** m_ppRet;
};