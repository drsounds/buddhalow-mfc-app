
// Buddhalow.h : main header file for the Buddhalow application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols



// CBuddhalowApp:
// See Buddhalow.cpp for the implementation of this class
//

class CBuddhalowApp : public CWinApp
{
public:
	CBuddhalowApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBuddhalowApp theApp;
