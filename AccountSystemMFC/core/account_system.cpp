#include"stdafx.h"
#include"account_system.h"

//################################################################################
//##################################Account########################################
//################################################################################

void AccountName::Init(void)
{
	strcpy_s(m_account_name, sizeof(m_account_name), "\0");
}

void AccountName::Release(void)
{

}

void AccountName::SetData(const char* name, const unsigned int id)
{
	m_account_id = id;
	strcpy_s(m_account_name, sizeof(m_account_name), name);
}

const char *AccountName::GetAccountName(const unsigned int id)
{
	if(id == m_account_id)
	{
		return m_account_name;
	}
	else
	{
		return "\0";
	}
}

//################################################################################
//#########################Account Name Mgr########################################
//################################################################################

AccountNameMgr *AccountNameMgr::gp_singleton = NULL;
void AccountNameMgr::Release(void)
{
	lAccountName.clear();
	if(gp_singleton)
	{
		delete gp_singleton;
		gp_singleton = NULL;
	}
}

void AccountNameMgr::Init(void)
{
	AddAccountName("資產", 1000);
	AddAccountName("負債", 2000);
	AddAccountName("權益", 3000);
	AddAccountName("收入", 4000);
	AddAccountName("支出", 5000);
}

AccountNameMgr *AccountNameMgr::GetInstance(void)
{
	if(gp_singleton == NULL)
	{
		gp_singleton = new AccountNameMgr;
		return gp_singleton;
	}
	else
	{
		return gp_singleton;
	}
}

void AccountNameMgr::AddAccountName(const char *name, unsigned int id)
{
	lAccountName.push_back(AccountName());
	lAccountName.back().SetData(name, id);
}

void AccountNameMgr::EraseAccountName(int select)
{

	lAccountName.erase(select);
}

const char *AccountNameMgr::GetAccountName(unsigned int id)
{
	LIST_ACCOUNT_NAME::iterator pi = lAccountName.begin();
	int size = lAccountName.size();
	for(int i = 0; i <size; i++)
	{
		AccountName account_name = *pi;
		if(strcmp(account_name.GetAccountName(id), "\0") != 0)
		{
			return account_name.GetAccountName(id);
		}
		++pi;
	}
	return "無此會計科目";
}


//################################################################################
//##################################Account########################################
//################################################################################

void Account::SetData(const unsigned int account,const unsigned int dollar,const unsigned short side, const unsigned short count)
{
	m_account_name = account;
	m_nt_dollar = dollar;
	m_side = side;
	m_count = count;
}

//################################################################################
//###################################Journal########################################
//################################################################################

void Journal::Init()
{
	vAccount.clear();
}

void Journal::Release()
{
	vAccount.clear();
}

void Journal::SetAccount(Account account)
{
	vAccount.back() = account;
}

void Journal::SetID(unsigned short year, unsigned short month, unsigned short day, unsigned short id)
{
	m_year = year;
	m_month = month;
	m_day = day ;
	m_id = id;
}

void Journal::AddAccount(void)
{
	vAccount.push_back(Account());
}

void Journal::AddAccount(const unsigned int account, const unsigned int dollar,const unsigned short side, const unsigned short id)
{
	vAccount.push_back(Account());
	vAccount.back().SetData(account, dollar, side, id);
}
