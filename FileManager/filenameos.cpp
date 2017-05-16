#include "stdafx.h"
#include "filenameos.h"


/*finder.FindNextFile();*/

//TRACE(_T("Root of %s is %s\n"), szFileToFind,
//	(LPCTSTR)finder.GetRoot());

//TRACE(_T("Title of %s is %s\n"), szFileToFind,
//	(LPCTSTR)finder.GetFileTitle());

//TRACE(_T("Path of %s is %s\n"), szFileToFind,
//	(LPCTSTR)finder.GetFilePath());

//TRACE(_T("URL of %s is %s\n"), szFileToFind,
//	(LPCTSTR)finder.GetFileURL());

//TRACE(_T("Name of %s is %s\n"), szFileToFind,
//	(LPCTSTR)finder.GetFileName());

//finder.Close();


//����������ļ��н������ļ�·�����
void ReverseDirectory(std::string strPath, std::vector<std::string>& arrFilepath)
{
	//������ļ���
	CFileFind finder;
	//const char*ת����LPCTSTR�ļ�
	//���ﱾ����ȡ����һ���ļ�·��
	//�����ļ�·���ҵ�����Ŀ¼
	std::string strFilePathG = GetFileDirectory(strPath);
	strFilePathG += "*.*";

	// = (LPCTSTR)strFilePathG.c_str();
	CString strFilePathW;
	char* p = const_cast<char*>(strFilePathG.c_str());
	//strFilePathW.Format("%s", p);//error C2664: 'void ATL::CStringT<wchar_t,StrTraitMFC_DLL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(UINT,...)': cannot convert argument 1 from 'const char [3]' to 'const wchar_t *'
	strFilePathW = p;
	BOOL bResult = finder.FindFile(strFilePathW);

	while (bResult)
	{
		bResult = finder.FindNextFile();
		if(finder.IsDots())
			continue;
		USES_CONVERSION;
		if (finder.IsDirectory())
		{
			CString str = finder.GetFilePath();
			std::string strs = W2A(str);
			strs += "\\";
			ReverseDirectory(strs, arrFilepath);
		}
		CString strFilePath = finder.GetFilePath();
		std::string strFilePaths = W2A(strFilePath);
		arrFilepath.push_back(strFilePaths);
	}
	return;
}

bool ReverseDirectory(CString strPath, std::vector<CString>& arrFilepath)
{

	return false;
}

//------------------------------------------------ - ����·��----------------------------------------------------
//_makepath(
//	path_buffer,
//	drive,       //���̣�����c��d�̣�
//	dir,         //Ŀ¼
//	fname,      //�ļ�����������׺��
//	ext        //�ļ�����׺
//)
//------------------------------------------------ - �ֽ�·��----------------------------------------------------
//_splitpath(drive,       //���̣�����c��d�̣�
//	dir,         //Ŀ¼
//	fname,      //�ļ�����������׺��
//	ext        //�ļ�����׺
//)



CString GetFileDirectory(CString strFilePath)
{

	return NULL;
}
CString GetFileName(CString strFilePath)
{
	return NULL;
}
CString GetFileTitle(CString strFilePath)
{
	return NULL;
}

CString GetFileExt(CString strFilePath)
{
	return NULL;
}

std::string GetFileDirectory(std::string strFilePath)
{
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(strFilePath.c_str(), drive, dir, fname, ext);

	//�ϳ�·������ȥ
	std::string strFileDir = drive;
	strFileDir += dir;
	return strFileDir;
}

std::string GetFileName(std::string strFilePath)
{
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(strFilePath.c_str(), drive, dir, fname, ext);

	//�ϳ�·������ȥ
	std::string strFileDir = fname;
	strFileDir += ".";
	strFileDir += ext;
	return strFileDir;
}

std::string GetFileTitle(std::string strFilePath)
{
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(strFilePath.c_str(), drive, dir, fname, ext);

	//�ϳ�·������ȥ
	std::string strFileDir = fname;
	return strFileDir;
}

std::string GetFileExt(std::string strFilePath)
{
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(strFilePath.c_str(), drive, dir, fname, ext);

	//�ϳ�·������ȥ
	std::string strFileDir = ext;
	return strFileDir;
}
