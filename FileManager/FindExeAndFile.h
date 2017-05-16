#pragma once


// CFindExeAndFile dialog

class CFindExeAndFile : public CDialogEx
{
	DECLARE_DYNAMIC(CFindExeAndFile)

public:
	CFindExeAndFile(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFindExeAndFile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FILE };
#endif

private:
	CEdit m_EditExe;
	CEdit m_EditFile;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnFindExe();
	afx_msg void OnBnClickedBtnFindDoc();
	afx_msg void OnBnClickedBtnLau();
};
