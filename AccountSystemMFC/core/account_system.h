#ifndef _ACCOUNT_SYSTEM_H_
#define _ACCOUNT_SYSTEM_H_


//################################################################################
//##################################Account########################################
//################################################################################

class Account
{
private:
	unsigned int m_accout_name;
	unsigned int m_nt_dollar;
	unsigned short m_side;
	unsigned short m_count;
public:
	Account(void):m_accout_name(1000),m_nt_dollar(0),m_side(0),m_count(0)															{}
	~Account(void)																																						{Release();}
	void Init();
	void Release(void)																																					{}
	//--------------------------------------Getter-----------------------------------------------------------------------
	const unsigned int GetAccount(void)const																													{return m_accout_name;}
	const unsigned int	GetDollar(void)	const																													{return m_nt_dollar;}
	const unsigned short GetSide(void)const																													{return m_side;}
	const unsigned short GetCount(void)	const																												{return m_count;}
	//---------------------------------------Setter-----------------------------------------------------------------------
	void SetAccount(const unsigned int account)																												{m_accout_name = account;}
	void SetDollar(const unsigned int dollar)																													{m_nt_dollar = dollar;}
	void SetSide(const unsigned short side)																														{m_side = side;}
	void SetCount(const unsigned short count)																												{m_count = count;}
	void SetData(const unsigned int account,const unsigned int dollar,const unsigned short side, const unsigned short count)
	{
		m_accout_name = account;
		m_nt_dollar = dollar;
		m_side = side;
		m_count = count;
	}
	enum AccountSide{CREDIT=0,DEBIT};
	enum AccountName{ASSET=1000, DEBT=2000,EQUIT=3000, REVENUE=4000, EXPENSE=5000 };
};

#endif //_ACCOUNT_SYSTEM_H_