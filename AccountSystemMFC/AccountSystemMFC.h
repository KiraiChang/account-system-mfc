// AccountSystemMFC.h : AccountSystemMFC 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CAccountSystemMFCApp:
// 請參閱實作此類別的 AccountSystemMFC.cpp
//


class CAccountSystemMFCApp : public CWinApp
{
public:
	CAccountSystemMFCApp();



// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAccountSystemMFCApp theApp;