#ifndef _FILENAME_OS_H_
#define _FILENAME_OS_H_

#include <iostream>
#include <vector>
#include <atlbase.h>
#include <stdlib.h>


//��ȡ�ļ�Ŀ¼
CString GetFileDirectory(CString strFilePath);

//��ȡ�ļ�����
CString GetFileName(CString strFilePath);


//��ȡ�ļ�Title
CString GetFileTitle(CString strFilePath);


//��ȡ�ļ���׺��
CString GetFileExt(CString strFilePath);

//��ȡ�ļ�Ŀ¼
std::string GetFileDirectory(std::string strFilePath);

//��ȡ�ļ�����
std::string GetFileName(std::string strFilePath);


//��ȡ�ļ�Title
std::string GetFileTitle(std::string strFilePath);


//��ȡ�ļ���׺��
std::string GetFileExt(std::string strFilePath);

//�����ļ����µ������ļ�
bool ReverseDirectory(CString strPath, std::vector<CString>& arrFilepath);

void ReverseDirectory(std::string strPath, std::vector<std::string>& arrFilepath);

//ɾ��ָ���ļ����������ļ�


//����һ���ļ������һ���ļ�������


//�����ļ���MD5ֵ


//�����ļ��Ĵ�С







#endif // !_FILENAME_OS_H_

