// VCPrjDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VCPrj.h"
#include "VCPrjDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCPrjDlg dialog

CVCPrjDlg::CVCPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVCPrjDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVCPrjDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVCPrjDlg)
	DDX_Control(pDX, IDC_STC_DRAW, m_stcDraw);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVCPrjDlg, CDialog)
	//{{AFX_MSG_MAP(CVCPrjDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_READ, OnBtnRead)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCPrjDlg message handlers

BOOL CVCPrjDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_nDevIndex = 0;
	m_nCH1VoltDIV = 5;//1V/DIV
	m_nCH2VoltDIV = 5;//1V/DIV
	m_nTimeDIV = 14;//1MSa/s

	if(dsoOpenDevice(0))
	{
		dsoGetCalLevel(m_nDevIndex,m_nCalData,32);
		dsoSetVoltDIV(m_nDevIndex,0,m_nCH1VoltDIV);
		dsoSetVoltDIV(m_nDevIndex,1,m_nCH2VoltDIV);
		dsoSetTimeDIV(m_nDevIndex,m_nTimeDIV);
	}
	else
	{
		AfxMessageBox("No device was found!");
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVCPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVCPrjDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVCPrjDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVCPrjDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CVCPrjDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CVCPrjDlg::OnBtnRead() 
{
	// TODO: Add your control notification handler code here
	short* pCH1Data;
	short* pCH2Data;
	ULONG nReadLen = 10240;//10k
	ULONG nDrawLen = 10000;
	short nTrigLevel = 64;
	short nSlope = 0;// 0:Rise; 1: Fall
	short nHTrigPos = 50;// 0 ~ 100
	ULONG nTrigPoint = 0;
	CRect rc;
	m_stcDraw.GetClientRect(&rc);
	pCH1Data = new short[nReadLen];
	pCH2Data = new short[nReadLen];		

	short nRe = dsoReadHardData(m_nDevIndex,
								pCH1Data, 
								pCH2Data,
								nReadLen,
								m_nCalData,
								m_nCH1VoltDIV,
								m_nCH2VoltDIV,
								0,//0:AUOT; 1:Normal; 2: Signal
								0,//CH1
								nTrigLevel,
								nSlope,
								m_nTimeDIV,
								nHTrigPos,
								nDrawLen,
								&nTrigPoint,
								0);
	if(nRe > 0)
	{
		m_stcDraw.GetDC()->FillSolidRect(&rc,RGB(0,0,0));
	//Draw CH1
		HTDrawWaveInYT(m_stcDraw.GetDC()->GetSafeHdc(),rc,RGB(255,255,0),0,pCH1Data,nReadLen,nDrawLen,nReadLen / 2,64,1.0,1.0,0,0);

	//Draw CH2
		HTDrawWaveInYT(m_stcDraw.GetDC()->GetSafeHdc(),rc,RGB(0,255,0),0,pCH1Data,nReadLen,nDrawLen,nReadLen / 2,192,1.0,1.0,0,0);
	}

	delete pCH1Data;
	delete pCH2Data;
}
