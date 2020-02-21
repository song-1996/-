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

ScanManager::ScanManager()
{};
ScanManager& ScanManager::CreateInstance(const string& path)
{
	static ScanManager sm;
	thread Scan_thread(&StartScan,&sm ,path);
	Scan_thread.detach();
	return sm;
}

void ScanManager::StartScan(const string &path)
{
	while (1)
	{
		ScanDirectory(path);
		this_thread::sleep_for(chrono::seconds(2));
	}
}