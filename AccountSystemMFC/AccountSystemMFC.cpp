// AccountSystemMFC.cpp : 定義應用程式的類別行為。
//

#include "stdafx.h"
#include "AccountSystemMFC.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAccountSystemMFCApp

BEGIN_MESSAGE_MAP(CAccountSystemMFCApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CAccountSystemMFCApp::OnAppAbout)
END_MESSAGE_MAP()


// CAccountSystemMFCApp 建構

CAccountSystemMFCApp::CAccountSystemMFCApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CAccountSystemMFCApp 物件

CAccountSystemMFCApp theApp;


// CAccountSystemMFCApp 初始設定

BOOL CAccountSystemMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));
	// 若要建立主視窗，此程式碼建立新的框架視窗物件，且將其設定為
	// 應用程式的主視窗物件
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 使用其資源建立並載入框架
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// 僅初始化一個視窗，所以顯示並更新該視窗
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// 只有在 SDI 應用程式中有後置字元時，才呼叫 DragAcceptFiles
	// 這會發生於 ProcessShellCommand 之後



	return TRUE;
}


// CAccountSystemMFCApp 訊息處理常式




// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 執行對話方塊的應用程式命令
void CAccountSystemMFCApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CAccountSystemMFCApp 訊息處理常式

