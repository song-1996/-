#pragma once
#include"Common.h"
#include"Sysutil.h"
#include"DataMananger.h"


class ScanManager
{
public:
	static ScanManager& CreateInstance(const string& path);
	void ScanDirectory(const string& path);
	void StartScan(const string &path);
	void StartWatch(const string &path);
private:
	ScanManager();
	mutex m_mutex;
	condition_variable m_cond;
	//DataManager m_db;
};