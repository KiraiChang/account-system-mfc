#include"stdafx.h"
#include"account_system.h"

void Account::SetData(const unsigned int account,const unsigned int dollar,const unsigned short side, const unsigned short count)
{
	m_account_name = account;
	m_nt_dollar = dollar;
	m_side = side;
	m_count = count;
}

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
