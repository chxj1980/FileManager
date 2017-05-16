// FindExeAndFile.cpp : implementation file
//

#include "stdafx.h"
#include "FileManager.h"
#include "FindExeAndFile.h"
#include "afxdialogex.h"

#define _CRT_SECURE_NO_WARNINGS


/*创建一个比较两个文件夹的文件是不是有重名的，并且hashCode也是一样的的工具，
并把重复文件显示到list列表工具上
*/

// CFindExeAndFile dialog

IMPLEMENT_DYNAMIC(CFindExeAndFile, CDialogEx)

CFindExeAndFile::CFindExeAndFile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FILE, pParent)
{

}

CFindExeAndFile::~CFindExeAndFile()
{
}

void CFindExeAndFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FIND_EXE, m_EditExe);
	DDX_Control(pDX, IDC_EDIT_FIND_DOC, m_EditFile);
}


BEGIN_MESSAGE_MAP(CFindExeAndFile, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_FIND_EXE, &CFindExeAndFile::OnBnClickedBtnFindExe)
	ON_BN_CLICKED(IDC_BTN_FIND_DOC, &CFindExeAndFile::OnBnClickedBtnFindDoc)
	ON_BN_CLICKED(IDC_BTN_LAU, &CFindExeAndFile::OnBnClickedBtnLau)
END_MESSAGE_MAP()


// CFindExeAndFile message handlers


//发现程序
void CFindExeAndFile::OnBnClickedBtnFindExe()
{
	// TODO: Add your control notification handler code here
#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)

	CString fileName;
	wchar_t* p = fileName.GetBuffer(FILE_LIST_BUFFER_SIZE);
	CFileDialog dlgFile(TRUE, _T(".exe"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY, _T("exe文件(*.exe)|*.exe|所有文件(*.*)|*.*||"));
	OPENFILENAME& ofn = dlgFile.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	ofn.lpstrFile = p;
	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

	dlgFile.DoModal();
	m_EditExe.SetWindowText(fileName);
	fileName.ReleaseBuffer();
	return;
}

//发现程序
void CFindExeAndFile::OnBnClickedBtnFindDoc()
{
	// TODO: Add your control notification handler code here
#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)

	CString fileName;
	wchar_t* p = fileName.GetBuffer(FILE_LIST_BUFFER_SIZE);
	CFileDialog dlgFile(TRUE, _T(".exe"), NULL, OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_READONLY, _T("exe文件(*.exe)|*.exe|所有文件(*.*)|*.*||"));
	OPENFILENAME& ofn = dlgFile.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	ofn.lpstrFile = p;
	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

	dlgFile.DoModal();
	m_EditFile.SetWindowText(fileName);
	fileName.ReleaseBuffer();
#undef MAX_CFileDialog_FILE_COUNT
#undef FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)
	return;
}

//启动程序，调用关系
void CFindExeAndFile::OnBnClickedBtnLau()
{
	// TODO: Add your control notification handler code here
	CString strExePath;
	CString strDocPath;
	m_EditExe.GetWindowTextW(strExePath);
	m_EditFile.GetWindowTextW(strDocPath);

	CString strCmd = _T(" ");
	strCmd += strExePath;
	strCmd += _T(" ");
	strCmd += strDocPath;
	USES_CONVERSION;
	std::string lp = W2A(strCmd);
	char ch[2048];
	strcpy_s(ch, lp.c_str());
	WinExec(ch, SW_SHOW);
}
