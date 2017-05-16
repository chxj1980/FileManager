// CMPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileManager.h"
#include "CMPDlg.h"
#include "afxdialogex.h"
#include "filenameos.h"


// CCMPDlg dialog

IMPLEMENT_DYNAMIC(CCMPDlg, CDialogEx)

CCMPDlg::CCMPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_CMP, pParent)
{

}

CCMPDlg::~CCMPDlg()
{
}

void CCMPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SRC, m_ListSrc);
	DDX_Control(pDX, IDC_LIST_DIS, m_ListDis);
	DDX_Control(pDX, IDC_EDIT_SRC, m_editSrcPath);
	DDX_Control(pDX, IDC_EDIT_DIS, m_editDisPath);
}


BOOL CCMPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//1、源文件列表
	CRect rect;
	// 获取编程语言列表视图控件的位置和大小   
	m_ListSrc.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_ListSrc.SetExtendedStyle(m_ListSrc.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_ListSrc.InsertColumn(0, _T("语言"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_ListSrc.InsertColumn(1, _T("2012.02排名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_ListSrc.InsertColumn(2, _T("2011.02排名"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// 在列表视图控件中插入列表项，并设置列表子项文本   
	m_ListSrc.InsertItem(0, _T("Java"));
	m_ListSrc.SetItemText(0, 1, _T("1"));
	
	m_ListSrc.SetItemText(0, 2, _T("1"));
	m_ListSrc.InsertItem(1, _T("C"));
	
	m_ListSrc.SetItemText(1, 1, _T("2"));
	m_ListSrc.SetItemText(1, 2, _T("2"));
	
	m_ListSrc.InsertItem(2, _T("C#"));
	m_ListSrc.SetItemText(2, 1, _T("3"));
	
	m_ListSrc.SetItemText(2, 2, _T("6"));
	m_ListSrc.InsertItem(3, _T("C++"));
	
	m_ListSrc.SetItemText(3, 1, _T("4"));
	m_ListSrc.SetItemText(3, 2, _T("3"));

	//2、对比文件列表
	//CRect rect;
	// 获取编程语言列表视图控件的位置和大小   
	m_ListDis.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_ListDis.SetExtendedStyle(m_ListDis.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_ListDis.InsertColumn(0, _T("语言"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_ListDis.InsertColumn(1, _T("2012.02排名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_ListDis.InsertColumn(2, _T("2011.02排名"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// 在列表视图控件中插入列表项，并设置列表子项文本   
	m_ListDis.InsertItem(0, _T("Java"));
	m_ListDis.SetItemText(0, 1, _T("1"));

	m_ListDis.SetItemText(0, 2, _T("1"));
	m_ListDis.InsertItem(1, _T("C"));

	m_ListDis.SetItemText(1, 1, _T("2"));
	m_ListDis.SetItemText(1, 2, _T("2"));

	m_ListDis.InsertItem(2, _T("C#"));
	m_ListDis.SetItemText(2, 1, _T("3"));

	m_ListDis.SetItemText(2, 2, _T("6"));
	m_ListDis.InsertItem(3, _T("C++"));

	m_ListDis.SetItemText(3, 1, _T("4"));
	m_ListDis.SetItemText(3, 2, _T("3"));

	return TRUE;
}

BEGIN_MESSAGE_MAP(CCMPDlg, CDialogEx)
	//NM_CLICK(IDC_LIST_DIS, &CCMPDlg::OnSelectedChange)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DIS, &CCMPDlg::OnLvnItemchangedListDis)
	ON_BN_CLICKED(IDC_BTN_FIND_SRC, &CCMPDlg::OnBnClickedBtnFindSrc)
	ON_BN_CLICKED(IDC_BTN_FIND_DIS, &CCMPDlg::OnBnClickedBtnFindDis)
	ON_BN_CLICKED(IDOK, &CCMPDlg::OnBnClickedOk)
END_MESSAGE_MAP()

//void CCMPDlg::OnSelectedChange(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: Add your control notification handler code here   
//	*pResult = 0;
//
//	CString strLangName;    // 选择语言的名称字符串   
//	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
//
//	if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
//	{
//		// 获取被选择列表项第一个子项的文本   
//		strLangName = m_ListDis.GetItemText(pNMListView->iItem, 0);
//		// 将选择的语言显示与编辑框中   
//		SetDlgItemText(IDC_EDITSELECT, strLangName);
//	}
//}


// CCMPDlg message handlers
//ListCtrol控件响应事件
void CCMPDlg::OnLvnItemchangedListDis(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//// TODO: Add your control notification handler code here   
	//*pResult = 0;

	CString strLangName;    // 选择语言的名称字符串   
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
	{
		// 获取被选择列表项第一个子项的文本   
		strLangName = m_ListSrc.GetItemText(pNMListView->iItem, 0);
		// 将选择的语言显示与编辑框中   
		SetDlgItemText(IDC_EDITSELECT, strLangName);
	}
	*pResult = 0;
}


void CCMPDlg::OnBnClickedBtnFindSrc()
{
#define MAX_CFILEDIALOG_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFILEDIALOG_FILE_COUNT * (MAX_PATH + 1)) + 1)
	//获取主目录的路径
	CFileDialog dlgFile(TRUE);
	CString strFilePath;
	wchar_t* p = strFilePath.GetBuffer(FILE_LIST_BUFFER_SIZE);
	OPENFILENAME& ofn = dlgFile.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	ofn.lpstrFile = p;
	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;
	dlgFile.DoModal();

	m_editSrcPath.SetWindowText(strFilePath);
	strFilePath.ReleaseBuffer();

#undef MAX_CFILEDIALOG_FILE_COUNT
#undef FILE_LIST_BUFFER_SIZE ((MAX_CFILEDIALOG_FILE_COUNT * (MAX_PATH + 1)) + 1)
}


void CCMPDlg::OnBnClickedBtnFindDis()
{
#define MAX_CFILEDIALOG_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFILEDIALOG_FILE_COUNT * (MAX_PATH + 1)) + 1)
	//获取主目录的路径
	CFileDialog dlgFile(TRUE);
	CString strFilePath;
	wchar_t* p = strFilePath.GetBuffer(FILE_LIST_BUFFER_SIZE);
	OPENFILENAME& ofn = dlgFile.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	ofn.lpstrFile = p;
	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;
	dlgFile.DoModal();

	m_editDisPath.SetWindowText(strFilePath);
	strFilePath.ReleaseBuffer();
#undef MAX_CFILEDIALOG_FILE_COUNT
#undef FILE_LIST_BUFFER_SIZE ((MAX_CFILEDIALOG_FILE_COUNT * (MAX_PATH + 1)) + 1)
}


void CCMPDlg::OnBnClickedOk()
{
	//并遍历目录中的文件，存入相应的对话框
	//MessageBox(_T("chian"), _T("henebi"), MB_OKCANCEL);
	CString strSrcPath;
	m_editSrcPath.GetWindowText(strSrcPath);
	CString strDisPath;
	m_editDisPath.GetWindowText(strDisPath);

	//分别遍历文件夹中的内容，存储到不同的内存数组中
	USES_CONVERSION;
	std::string strSrcPaths = W2A(strSrcPath);
	ReverseDirectory(strSrcPaths, m_arrSrcPath);
	std::string china = "";
	MessageBox(_T("chian"), _T("henebi"), MB_OKCANCEL);
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
