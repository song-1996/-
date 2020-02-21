#define _CRT_SECURE_NO_WARNINGS 1
#include"DataMananger.h"
SqliteManager::SqliteManager()
	:m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	if (m_db)
	{
		SqliteManager::Close();
		m_db = nullptr;
	}
}
void SqliteManager::Open(const string& path)
{
	int rc = sqlite3_open(path.c_str(), &m_db);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("DB open fail");
		exit(0);
	}
	TRACE_LOG("DB open successed");
}
void SqliteManager::Close()
{
	int rc = sqlite3_close(m_db);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("DB close error");
		exit(0);
	}
	TRACE_LOG("DB close successed!");
}

void SqliteManager::ExecuteSql(const string& sql)
{
	char* errmsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &errmsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("DB execute error");
		exit(0);
	}
	TRACE_LOG("DB execute successed!");
}

void SqliteManager::GetTable(const string& sql, int& row, int& col, char**& ppRet)
{
	char* errmsg = nullptr;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &errmsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("DB GetTable error");
		exit(0);
	}
	TRACE_LOG("DB GetTable successed!");
	/*
	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4s", ppRet[i*col + j]);
		}
		printf("\n");
	}
	*/
}
////////////////////////////////////////////////////////////////
DataManager::DataManager()
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, ".\\db\\%s", DOC_DB);
	m_dbmgr.Open(sql);
	InitSqlite();
}

DataManager& DataManager::CreateInstance()
{
	static DataManager inst;
	return inst;
}
void DataManager::InitSqlite()
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "create table if not exists %s(id integer primary key autoincrement,name text,pinyin text ,pinyininit text ,adress text);", DOC_TABLE);
	m_dbmgr.ExecuteSql(sql);
}
DataManager::~DataManager()
{}

//向数据库中获取数据
void DataManager::GetDocs(const string &path, set<string>& docs)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "select name from %s;", DOC_TABLE);
	int row = 0, col = 0;
	char** pRet = nullptr;
	//m_dbmgr.GetTable(sql, row, col, pRet);
	AutoGetResTable at(&m_dbmgr, sql, row, col, pRet);
	for (int i = 1; i <= row; i++)
		docs.insert(pRet[i]);
	//sqlite3_free_table(pRet);
}
//向数据库中增加数据
void DataManager::InsertDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	string pinyin = ChineseConvertPinYinAllSpell(doc);
	string pinyininit = ChineseConvertPinYinInitials(doc);
	sprintf(sql, "insert into %s values(null,'%s','%s','%s','%s');", 
		DOC_TABLE, doc.c_str(), pinyin.c_str(),pinyininit.c_str(),path.c_str());
	m_dbmgr.ExecuteSql(sql);
}
//向数据库中删除数据
void DataManager::DeleteDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "delete from %s where name = '%s' and adress='%s';", DOC_TABLE, doc.c_str(), path.c_str());
	m_dbmgr.ExecuteSql(sql);
	//F:\c语言\项目和复习\复习\A
	string tmp_path = path;
	tmp_path += '\\';
	tmp_path += doc;
	memset(sql, 0, MAX_SQL_SIZE);
	sprintf(sql, "delete from %s where adress like '%s%%';", DOC_TABLE, tmp_path.c_str());
	m_dbmgr.ExecuteSql(sql);
}

void  DataManager::Seach(const string& key, vector<pair<string, string>>& doc_path)
{
	string pinyin = ChineseConvertPinYinAllSpell(key);
	string pininit = ChineseConvertPinYinInitials(key);
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "select name, adress from %s where pinyin like '%%%s%%'or pinyininit like '%%%s%%';", DOC_TABLE, pinyin.c_str(), pininit.c_str());
	int row = 0, col = 0;
	char** pRet = nullptr;
	//m_dbmgr.GetTable(sql, row, col, pRet);
	AutoGetResTable at(&m_dbmgr, sql, row, col, pRet);
	for (int i = 1; i <= row; i++)
		doc_path.push_back(make_pair(pRet[i*col + 0], pRet[i*col + 1]));
	//sqlite3_free_table(pRet);
}

////////////////////////////////////////////////////////////////////////

AutoGetResTable::AutoGetResTable(SqliteManager* db, const string&sql, int& row, int& col, char**& ppRet)
	:m_db(db), m_ppRet(nullptr)
{
	m_db->GetTable(sql, row, col, ppRet);
	m_ppRet = ppRet;
}
AutoGetResTable::~AutoGetResTable()
{
	if (m_ppRet)
	{
		sqlite3_free_table(m_ppRet);
		m_ppRet = nullptr;
	}
}


//////////////////////////////////////////////////////////////////////
void DataManager::SplitHightLight(const string &str, const string &key,
	string &prefix, string &hightlight, string &suffix)
{
	string strlower = str;
	string keylower = key;
	transform(str.begin(), str.end(), strlower.begin(), towlower);
	transform(key.begin(), key.end(), keylower.begin(), towlower);

	//key =  1.汉字搜索
	int pos = str.find(key);
	if (pos != string::npos)
	{
		prefix = str.substr(0, pos);
		hightlight = str.substr(pos, key.size());
		suffix = str.substr(pos + key.size());
		return;
	}

	//单个字母可以在全拼中搜到，要现在首字母中搜

	//2 拼音首字母搜索，如果能匹配，则需要匹配分离的汉字和首字母
	//str = "22比特科技,abc,让就业更简单666"; 
	//str_pinyin = "2btkj,abc,rjygjd666"
	//key_pinyin = "jy"

	string str_pinyininit = ChineseConvertPinYinInitials(str);
	string key_pinyininit = key;
	pos = str_pinyininit.find(key_pinyininit);
	if (pos != string::npos)
	{
		int i = 0, j = 0;
		int pre_index = 0, suf_index = 0;
		while (1)
		{
			if (pos == j)
			{
				pre_index = i;
				suf_index = i + key.size() * 2;
				break;
			}
			if (str[i] >= 0 && str[i] <= 127)
				i++;
			else
				i += 2;
			j++;
		}
		prefix = str.substr(0, pre_index);
		hightlight = str.substr(pre_index, suf_index - pre_index);
		suffix = str.substr(suf_index);
		return;
	}
	//3 拼音全拼搜索，如果能匹配，则需要匹配分离的汉字和拼音
	//str = "123比特科技,abc,让就业更简单666"; 
	//str_pinyin = "123bitekeji,abc,rangjiuyegengjiandan666"
	//key_pinyin = "jiuye"
	string str_pinyin = ChineseConvertPinYinAllSpell(str);
	string key_pinyin = key;
	pos = str_pinyin.find(key_pinyin);
	if (pos != string::npos)
	{
		int i = 0, j = 0;
		int pre_index = 0, suf_index = 0;
		int end_pos = -1;
		while (1)
		{
			if (j == end_pos)
			{
				suf_index = i;
				break;
			}
			if (j == pos)
			{
				pre_index = i;
				end_pos = pos + key.size();
			}
			if (str[i] >= 0 && str[i] <= 127)
			{
				i++; 
				j++;
			}
			else
			{
				string ch = str.substr(i, 2);
				string ch_pinyin = ChineseConvertPinYinAllSpell(ch);
				i+=2;
				j += ch_pinyin.size();
			}
		}
		prefix = str.substr(0, pre_index);
		hightlight = str.substr(pre_index, suf_index - pre_index);
		suffix = str.substr(suf_index);
		return;
	}


	prefix = str;
}