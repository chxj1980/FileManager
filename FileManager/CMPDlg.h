#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>
#include <iostream>


// CCMPDlg dialog

class CCMPDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCMPDlg)

public:
	CCMPDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCMPDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	//afx_msg void OnSelectedChange(NMHDR *pNMHDR, LRESULT *pResult);

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListSrc;
	CListCtrl m_ListDis;
	afx_msg void OnLvnItemchangedListDis(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnFindSrc();
	afx_msg void OnBnClickedBtnFindDis();
	afx_msg void OnBnClickedOk();
	CEdit m_editSrcPath;
	CEdit m_editDisPath;

	//内存结构
	//存储主目录中的所有文件的路径
	std::vector<std::string> m_arrSrcPath;

	//存储比对目录中的所有文件的路径
	std::vector<std::string> m_arrDisPath;
};
