#ifndef _ACCOUNT_SYSTEM_H_
#define _ACCOUNT_SYSTEM_H_
#include"data_structures.h"

//################################################################################
//##################################Account########################################
//################################################################################

class Account
{
private:
	unsigned int m_account_name;
	unsigned int m_nt_dollar;
	unsigned short m_side;
	unsigned short m_count;
public:
	Account(void):m_account_name(1000),m_nt_dollar(0),m_side(0),m_count(0)															{}
	~Account(void)																																						{Release();}
	void Init();
	void Release(void)																																					{}
	//--------------------------------------Getter-----------------------------------------------------------------------
	const unsigned int GetAccount(void)const																													{return m_account_name;}
	const unsigned int	GetDollar(void)	const																													{return m_nt_dollar;}
	const unsigned short GetSide(void)const																													{return m_side;}
	const unsigned short GetCount(void)	const																												{return m_count;}
	//---------------------------------------Setter-----------------------------------------------------------------------
	void SetAccount(const unsigned int account)																												{m_account_name = account;}
	void SetDollar(const unsigned int dollar)																													{m_nt_dollar = dollar;}
	void SetSide(const unsigned short side)																														{m_side = side;}
	void SetCount(const unsigned short count)																												{m_count = count;}
	void SetData(const unsigned int account,const unsigned int dollar
						,const unsigned short side, const unsigned short count);

	enum AccountSide{CREDIT=0,DEBIT};
	enum AccountName{ASSET=1000, DEBT=2000,EQUIT=3000, REVENUE=4000, EXPENSE=5000 };
};

typedef list<Account> LIST_ACCOUNT;

//################################################################################
//###################################Journal########################################
//################################################################################

class Journal
{
private:
	LIST_ACCOUNT vAccount;
	unsigned short m_year;
	unsigned short m_month;
	unsigned short m_day;
	unsigned short m_id;
public:
	Journal(void):m_year(0),m_month(0),m_day(0),m_id(0)																			{Init();}
	~Journal(void)																																			{Release();}
	void Init(void);
	void Release(void);
	LIST_ACCOUNT &GetAccountTable(void)																							{return vAccount;}
	Account GetAccount(void)																														{return vAccount.back();}
	unsigned short GetYear(void)																													{return m_year;}
	unsigned short GetMonth(void)																													{return m_month;}
	unsigned short GetDay(void)																														{return m_day;}
	unsigned short GetID(void)																														{return m_id;}
	void SetAccount(Account account);
	void SetID(const unsigned short year, const unsigned short month,
					  const unsigned short day, const unsigned short id);
	void AddAccount(void);
	void AddAccount(const unsigned int account, const unsigned int dollar,
								const unsigned short side, const unsigned short id);
};

#endif //_ACCOUNT_SYSTEM_H_