// AccountSystemMFC.h : AccountSystemMFC ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CAccountSystemMFCApp:
// �аѾ\��@�����O�� AccountSystemMFC.cpp
//


class CAccountSystemMFCApp : public CWinApp
{
public:
	CAccountSystemMFCApp();



// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAccountSystemMFCApp theApp;