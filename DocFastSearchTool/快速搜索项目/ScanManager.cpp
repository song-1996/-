#define _CRT_SECURE_NO_WARNINGS 1
#include"ScanManager.h"

void ScanManager::ScanDirectory(const string& path)
{
	//1.扫描本地文件，并进行存储
	vector<string> local_files, local_dirs;
	DirectoryList(path, local_files, local_dirs);
	set<string> local_set;//set底层是红黑树，元素有序
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());
	//2.扫描数据库文件，并进行存储
	set<string> db_set;
	DataManager& m_db = DataManager::CreateInstance();
	m_db.GetDocs(path, db_set);
	//3.对比文件
	auto loc_it = local_set.begin();
	auto db_it = db_set.begin();
	while (loc_it!=local_set.end() && db_it!=db_set.end())
	{
		if (*loc_it < *db_it)
		{
			//本地文件存在，而数据库中不存在,往数据库中添加
			m_db.InsertDoc(path, *loc_it);
			loc_it++;
		}
		else if (*loc_it > *db_it)
		{
			//本地文件不存在，而数据库中存在，那么删除数据库中对应文件
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//本地和数据库中均存在文件
			loc_it++;
			db_it++;
		}
	}
	//本地文件存在，而数据库中不存在,往数据库中添加
	while (loc_it != local_set.end())
	{
		//添加文件
		m_db.InsertDoc(path, *loc_it);
		loc_it++;
	}

	//本地文件不存在，而数据库中存在，那么删除数据库中对应文件
	while (db_it != db_set.end())
	{
		//删除文件
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}
	//递归遍历子目录
	for (auto& dir : local_dirs)
		ScanDirectory(path + "\\" + dir);
}

///////////////////////////////////////////////////////////////////

size_t g_FileCount = 0;
size_t g_ScanCount = 0;

ScanManager::ScanManager()
{};
ScanManager& ScanManager::CreateInstance(const string& path)
{
	static ScanManager sm;
	thread Scan_thread(&StartScan,&sm ,path);
	Scan_thread.detach();
	thread Watch_thread(&StartWatch, &sm, path);
	Watch_thread.detach();
	return sm;
}

void ScanManager::StartScan(const string &path)
{
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(2));
		unique_lock<mutex> lock(m_mutex);
		m_cond.wait(lock);
		ScanDirectory(path);
	}
}

/*
bool DirectoryWatch(const string &path)
{
	size_t file_count= GetFileCount(path);
	return g_FileCount != file_count;
}
*/
void ScanManager::StartWatch(const string &path)
{
	while (1)
	{
		//监控path目录下文件的个数是否有变化
		g_ScanCount = 0;
		g_ScanCount = GetFileCount(path);
		if (g_ScanCount!= g_FileCount)
		{
			//发送扫描信号
			m_cond.notify_one();
			g_FileCount = g_ScanCount;
		}
	}
}
