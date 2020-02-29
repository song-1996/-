#pragma once
#include"Common.h"
#include"Sysutil.h"
class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	//�����ݿ�
	void Open(const string& path);
	//�ر����ݿ�
	void Close();
	//ִ��sql���
	void ExecuteSql(const string& sql);
	//��ȡ����
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
	//�����ݿ��л�ȡ����
	void GetDocs(const string &path, set<string>& docs);
	//�����ݿ�����������
	void InsertDoc(const string &path, string doc);
	//�����ݿ���ɾ������
	void DeleteDoc(const string &path, string doc);
	//������������
	void Seach(const string& key, vector<pair<string, string>>& doc_path);
	//�ָ�ؼ���
	void SplitHightLight(const string &str, const string &key,
		string &prefix, string &hightlight, string &suffix);
	//������ݿ�
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