#pragma once
#include<list>

#include"./core/data_structures.h"
#include"./core/account_system.h"
#include"DlgAccountInput.h"
// DlgJournal 對話方塊

//typedef std::list<Account> JOURNAL;
typedef DoubleLinkList<Account> JOURNAL;


class DlgJournal : public CDialog
{
	DECLARE_DYNAMIC(DlgJournal)
	CWnd* mp_parent;
	DlgAccountInput * d_account;
	int m_id;
	JOURNAL m_journal;
public:
	DlgJournal(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~DlgJournal();
	void Release();
	void Create();
	void Update();

	void OnOK(void);
	void OnCancel(void);
private:
	void PostNcDestroy(void);


// 對話方塊資料
	enum { IDD = IDD_DIALOG_JOURNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonErase();
};
