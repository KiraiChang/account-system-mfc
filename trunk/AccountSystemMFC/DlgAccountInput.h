#pragma once

#include "./core/account_system.h"
// DlgAccountInput 對話方塊

class DlgAccountInput : public CDialog
{
	DECLARE_DYNAMIC(DlgAccountInput)
	Account m_account;
	AccountNameMgr * mp_account_name;
	CWnd *mp_parent;
	int m_id;
public:
	DlgAccountInput(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~DlgAccountInput();
	void Release(void);
	void Create(Account account);
	void Update(void);

	void OnOK(void);
	void OnCancel(void);
protected:
	void PostNcDestroy(void);

// 對話方塊資料
	enum { IDD = IDD_DIALOG_ACCOUNT_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
