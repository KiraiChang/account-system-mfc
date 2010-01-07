#pragma once
#include<list>

#include"./core/data_structures.h"
#include"./core/account_system.h"
#include"DlgAccountInput.h"
// DlgJournal ��ܤ��

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
	DlgJournal(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~DlgJournal();
	void Release();
	void Create();
	void Update();

	void OnOK(void);
	void OnCancel(void);
private:
	void PostNcDestroy(void);


// ��ܤ�����
	enum { IDD = IDD_DIALOG_JOURNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonErase();
};
