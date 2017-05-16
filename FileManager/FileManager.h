
// FileManager.h : main header file for the FileManager application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFileManagerApp:
// See FileManager.cpp for the implementation of this class
//

class CFileManagerApp : public CWinApp
{
public:
	CFileManagerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnHelpLaunch();
};

extern CFileManagerApp theApp;
