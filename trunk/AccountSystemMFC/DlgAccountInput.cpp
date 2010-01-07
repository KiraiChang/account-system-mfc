// DlgAccountInput.cpp : 實作檔
//

#include "stdafx.h"
#include "AccountSystemMFC.h"
#include "DlgAccountInput.h"


// DlgAccountInput 對話方塊

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
}

void DlgAccountInput::Update(void)
{
	m_account.Release();
}


void DlgAccountInput::OnOK(void)
{
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


// DlgAccountInput 訊息處理常式

void DlgAccountInput::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	OnOK();
}

void DlgAccountInput::OnBnClickedCancel()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	OnCancel();
}
