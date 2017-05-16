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

	//1��Դ�ļ��б�
	CRect rect;
	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_ListSrc.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_ListSrc.SetExtendedStyle(m_ListSrc.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������   
	m_ListSrc.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_ListSrc.InsertColumn(1, _T("2012.02����"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_ListSrc.InsertColumn(2, _T("2011.02����"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// ���б���ͼ�ؼ��в����б���������б������ı�   
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

	//2���Ա��ļ��б�
	//CRect rect;
	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_ListDis.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_ListDis.SetExtendedStyle(m_ListDis.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������   
	m_ListDis.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_ListDis.InsertColumn(1, _T("2012.02����"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_ListDis.InsertColumn(2, _T("2011.02����"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// ���б���ͼ�ؼ��в����б���������б������ı�   
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
//	CString strLangName;    // ѡ�����Ե������ַ���   
//	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
//
//	if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
//	{
//		// ��ȡ��ѡ���б����һ��������ı�   
//		strLangName = m_ListDis.GetItemText(pNMListView->iItem, 0);
//		// ��ѡ���������ʾ��༭����   
//		SetDlgItemText(IDC_EDITSELECT, strLangName);
//	}
//}


// CCMPDlg message handlers
//ListCtrol�ؼ���Ӧ�¼�
void CCMPDlg::OnLvnItemchangedListDis(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//// TODO: Add your control notification handler code here   
	//*pResult = 0;

	CString strLangName;    // ѡ�����Ե������ַ���   
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
	{
		// ��ȡ��ѡ���б����һ��������ı�   
		strLangName = m_ListSrc.GetItemText(pNMListView->iItem, 0);
		// ��ѡ���������ʾ��༭����   
		SetDlgItemText(IDC_EDITSELECT, strLangName);
	}
	*pResult = 0;
}


void CCMPDlg::OnBnClickedBtnFindSrc()
{
#define MAX_CFILEDIALOG_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFILEDIALOG_FILE_COUNT * (MAX_PATH + 1)) + 1)
	//��ȡ��Ŀ¼��·��
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
	//��ȡ��Ŀ¼��·��
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
	//������Ŀ¼�е��ļ���������Ӧ�ĶԻ���
	//MessageBox(_T("chian"), _T("henebi"), MB_OKCANCEL);
	CString strSrcPath;
	m_editSrcPath.GetWindowText(strSrcPath);
	CString strDisPath;
	m_editDisPath.GetWindowText(strDisPath);

	//�ֱ�����ļ����е����ݣ��洢����ͬ���ڴ�������
	USES_CONVERSION;
	std::string strSrcPaths = W2A(strSrcPath);
	ReverseDirectory(strSrcPaths, m_arrSrcPath);
	std::string china = "";
	MessageBox(_T("chian"), _T("henebi"), MB_OKCANCEL);
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
