#ifndef _FILENAME_OS_H_
#define _FILENAME_OS_H_

#include <iostream>
#include <vector>
#include <atlbase.h>
#include <stdlib.h>


//获取文件目录
CString GetFileDirectory(CString strFilePath);

//获取文件名称
CString GetFileName(CString strFilePath);


//获取文件Title
CString GetFileTitle(CString strFilePath);


//获取文件后缀名
CString GetFileExt(CString strFilePath);

//获取文件目录
std::string GetFileDirectory(std::string strFilePath);

//获取文件名称
std::string GetFileName(std::string strFilePath);


//获取文件Title
std::string GetFileTitle(std::string strFilePath);


//获取文件后缀名
std::string GetFileExt(std::string strFilePath);

//便利文件夹下的所有文件
bool ReverseDirectory(CString strPath, std::vector<CString>& arrFilepath);

void ReverseDirectory(std::string strPath, std::vector<std::string>& arrFilepath);

//删除指定文件夹下所有文件


//传入一个文件夹输出一个文件夹数组


//计算文件的MD5值


//计算文件的大小







#endif // !_FILENAME_OS_H_

