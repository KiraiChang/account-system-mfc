// DlgAccountInput.cpp : ��@��
//

#include "stdafx.h"
#include "AccountSystemMFC.h"
#include "DlgAccountInput.h"
#include "DlgJournal.h"


// DlgAccountInput ��ܤ��

IMPLEMENT_DYNAMIC(DlgAccountInput, CDialog)

DlgAccountInput::DlgAccountInput(CWnd* pParent /*=NULL*/)
	: CDialog(DlgAccountInput::IDD, pParent)
{
	mp_parent = pParent;
	this->m_id = DlgAccountInput::IDD;
}

DlgAccountInput::~DlgAccountInput()
{
	Release();
}

void DlgAccountInput::Release(void)
{
	if(mp_parent)
		mp_parent = NULL;
}

void DlgAccountInput::Create(Account account)
{
	m_account = account;
	CDialog::Create(m_id,NULL);
	Update();
}

void DlgAccountInput::Update(void)
{
	CButton* pRadioCredit=(CButton*)GetDlgItem(IDC_RADIO_CREDIT);
	CButton* pRadioDebit=(CButton*)GetDlgItem(IDC_RADIO_DEBIT);
	CString str;
	str.Format(_T("%04d"),m_account.GetAccount());
	SetDlgItemText(IDC_EDIT_ACCOUNT_ID,str);
	str.Format(_T("NT$%d"),m_account.GetDollar());
	SetDlgItemText(IDC_EDIT_DOLLAR,str);
	if(m_account.GetSide() == 0)
		pRadioCredit->SetCheck(BST_CHECKED);
	else
		pRadioDebit->SetCheck(BST_CHECKED);
}


void DlgAccountInput::OnOK(void)
{
	CButton* pRadioCredit=(CButton*)GetDlgItem(IDC_RADIO_CREDIT);
	unsigned int account_name;
	unsigned int nt_dollar;
	unsigned short side;
	account_name = GetDlgItemInt(IDC_EDIT_ACCOUNT_ID);
	nt_dollar = GetDlgItemInt(IDC_EDIT_DOLLAR);
	int state = pRadioCredit->GetCheck();
	if(state == BST_CHECKED)
		side = 0;
	else
		side = 1;
	m_account.SetAccount(account_name);
	m_account.SetDollar(nt_dollar);
	m_account.SetSide(side);
	((DlgJournal *)mp_parent)->AccountInputOKReturn(m_account);
	DestroyWindow();
}

void DlgAccountInput::OnCancel(void)
{
	DestroyWindow();
}

void DlgAccountInput::PostNcDestroy(void)
{
	delete this;
}

void DlgAccountInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgAccountInput, CDialog)
	ON_BN_CLICKED(IDOK, &DlgAccountInput::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DlgAccountInput::OnBnClickedCancel)
END_MESSAGE_MAP()


// DlgAccountInput �T���B�z�`��

void DlgAccountInput::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	OnOK();
}

void DlgAccountInput::OnBnClickedCancel()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	OnCancel();
}
