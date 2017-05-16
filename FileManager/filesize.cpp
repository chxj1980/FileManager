#include "stdafx.h"
#include "filesize.h"
#include <iostream>
#include <windows.h>
#include <string>  
using namespace std;

void getFoldersize(const char* path, unsigned __int64 *size)
{
	char* p = const_cast<char*>(path);
	CString strFilePath;
	strFilePath = p;
	if (FILE_ATTRIBUTE_DIRECTORY == GetFileAttributes(strFilePath))
	{
		WIN32_FIND_DATAA fad;
		HANDLE hfile = FindFirstFileA((string(path) + '\\' + "*.*").c_str(), &fad);

		BOOL result = true;
		while (result)
		{
			if (string(fad.cFileName) != string(".") && string(fad.cFileName) != string(".."))
			{
				getFoldersize((string(path) + '\\' + fad.cFileName).c_str(), size);
			}

			result = FindNextFileA(hfile, &fad);
		}

		FindClose(hfile);
	}
	else {
		WIN32_FILE_ATTRIBUTE_DATA fad;
		if (GetFileAttributesExA(path, GetFileExInfoStandard, &fad))
			*size += ((ULONG64)fad.nFileSizeHigh & 0xffffffff) << 32 | (ULONG64)fad.nFileSizeLow;
	}
}