#define _CRT_SECURE_NO_WARNINGS 1
#include"ScanManager.h"

void ScanManager::ScanDirectory(const string& path)
{
	//1.ɨ�豾���ļ��������д洢
	vector<string> local_files, local_dirs;
	DirectoryList(path, local_files, local_dirs);
	set<string> local_set;//set�ײ��Ǻ������Ԫ������
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());
	//2.ɨ�����ݿ��ļ��������д洢
	set<string> db_set;
	DataManager& m_db = DataManager::CreateInstance();
	m_db.GetDocs(path, db_set);
	//3.�Ա��ļ�
	auto loc_it = local_set.begin();
	auto db_it = db_set.begin();
	while (loc_it!=local_set.end() && db_it!=db_set.end())
	{
		if (*loc_it < *db_it)
		{
			//�����ļ����ڣ������ݿ��в�����,�����ݿ������
			m_db.InsertDoc(path, *loc_it);
			loc_it++;
		}
		else if (*loc_it > *db_it)
		{
			//�����ļ������ڣ������ݿ��д��ڣ���ôɾ�����ݿ��ж�Ӧ�ļ�
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//���غ����ݿ��о������ļ�
			loc_it++;
			db_it++;
		}
	}
	//�����ļ����ڣ������ݿ��в�����,�����ݿ������
	while (loc_it != local_set.end())
	{
		//����ļ�
		m_db.InsertDoc(path, *loc_it);
		loc_it++;
	}

	//�����ļ������ڣ������ݿ��д��ڣ���ôɾ�����ݿ��ж�Ӧ�ļ�
	while (db_it != db_set.end())
	{
		//ɾ���ļ�
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}
	//�ݹ������Ŀ¼
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
		//���pathĿ¼���ļ��ĸ����Ƿ��б仯
		g_ScanCount = 0;
		g_ScanCount = GetFileCount(path);
		if (g_ScanCount!= g_FileCount)
		{
			//����ɨ���ź�
			m_cond.notify_one();
			g_FileCount = g_ScanCount;
		}
	}
}
