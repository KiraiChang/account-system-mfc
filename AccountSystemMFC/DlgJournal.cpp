// DlgJournal.cpp : 實作檔
//

#include "stdafx.h"
#include "AccountSystemMFC.h"
#include "DlgJournal.h"


// DlgJournal 對話方塊

IMPLEMENT_DYNAMIC(DlgJournal, CDialog)

DlgJournal::DlgJournal(CWnd* pParent /*=NULL*/)
	: CDialog(DlgJournal::IDD, pParent),d_account(NULL)
{
	mp_parent = pParent;
	this->m_id = DlgJournal::IDD;
}

DlgJournal::~DlgJournal()
{
	Release();
}

void DlgJournal::Release()
{
	if(mp_parent)
	{
		mp_parent =NULL;
	}
	m_journal.clear();
}

void DlgJournal::Create()
{
	CDialog::Create(m_id,NULL);
	//m_journal.set_id(2010,01,01,0001);
	m_journal.push_back(Account());
	m_journal.back().SetData(Account::ASSET, 1000, Account::CREDIT, 0);
	m_journal.push_back(Account());
	m_journal.back().SetData(Account::DEBT, 100, Account::CREDIT, 1);
	m_journal.push_back(Account());
	m_journal.back().SetData(Account::EQUIT, 100, Account::CREDIT, 2);
	m_journal.push_back(Account());
	m_journal.back().SetData(Account::REVENUE, 100, Account::CREDIT, 3);
	m_journal.push_back(Account());
	m_journal.back().SetData(Account::EXPENSE, 100, Account::CREDIT, 3);
	Update();
}

void DlgJournal::Update()
{
	CString str;
	//顯示分錄編號
	//str.Format(_T("%d%02d%02d%04d"), m_journal.get_year(), m_journal.get_month(), m_journal.get_day(), m_journal.get_id());
	//SetDlgItemText(IDC_EDIT_JOURNAL_ID,str);
	CListBox* pDlgJournal=(CListBox*)GetDlgItem(IDC_LIST_JOURNAL);
	pDlgJournal->ResetContent();
	int ori_journal_select = pDlgJournal->GetCurSel();
	int size = m_journal.size();
	JOURNAL::iterator pi = m_journal.begin();
	for(int i = 0; i < size; i++)
	{
		str.Format(_T("%d,%d,%d,%d"),(*pi).GetAccount(), (*pi).GetDollar(), (*pi).GetSide(), (*pi).GetCount());
		pDlgJournal->AddString(str);
		++pi;
	}
}

void DlgJournal::OnOK(void)
{
	DestroyWindow();
}
void DlgJournal::OnCancel(void)
{
	DestroyWindow();
}

void DlgJournal::PostNcDestroy(void)
{
	delete this;
}


void DlgJournal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgJournal, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &DlgJournal::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &DlgJournal::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_ERASE, &DlgJournal::OnBnClickedButtonErase)
END_MESSAGE_MAP()


// DlgJournal 訊息處理常式

void DlgJournal::OnBnClickedButtonAdd()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	m_journal.push_back(Account());
	Update();
}

void DlgJournal::OnBnClickedButtonModify()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pDlgJournal=(CListBox*)GetDlgItem(IDC_LIST_JOURNAL);
	int ori_journal_select = pDlgJournal->GetCurSel();
	if(ori_journal_select < 0 || ori_journal_select > (int)m_journal.size())
		return ;
	JOURNAL::iterator pi = m_journal.begin();
	for(int i = 0; i < ori_journal_select; i++)
	{
		pi++;
	}
	m_journal.set_current(pi);
	d_account = new DlgAccountInput(this);
	d_account->Create(m_journal.const_back());
	d_account->ShowWindow(SW_NORMAL);
}

void DlgJournal::OnBnClickedButtonErase()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pDlgJournal=(CListBox*)GetDlgItem(IDC_LIST_JOURNAL);
	int ori_journal_select = pDlgJournal->GetCurSel();
	if(ori_journal_select < 0 || ori_journal_select > (int)m_journal.size())
		return ;
	JOURNAL::iterator pi = m_journal.begin();
	for(int i = 0; i < ori_journal_select; i++)
	{
		pi++;
	}
	m_journal.erase(pi);
	Update();
	if(ori_journal_select == (int)m_journal.size())
		pDlgJournal->SetCurSel(ori_journal_select-1);
	else
		pDlgJournal->SetCurSel(ori_journal_select);
}
