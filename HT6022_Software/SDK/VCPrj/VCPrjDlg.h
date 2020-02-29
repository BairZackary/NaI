// VCPrjDlg.h : header file
//

#if !defined(AFX_VCPRJDLG_H__D0B43B51_1604_4E49_8BE0_86F77F4FEFB1__INCLUDED_)
#define AFX_VCPRJDLG_H__D0B43B51_1604_4E49_8BE0_86F77F4FEFB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVCPrjDlg dialog

class CVCPrjDlg : public CDialog
{
// Construction
public:
	CVCPrjDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVCPrjDlg)
	enum { IDD = IDD_VCPRJ_DIALOG };
	CStatic	m_stcDraw;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCPrjDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	public:
		short m_nDevIndex;
		short m_nCalData[32];
		int m_nCH1VoltDIV;
		int m_nCH2VoltDIV;
		int m_nTimeDIV;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVCPrjDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCPRJDLG_H__D0B43B51_1604_4E49_8BE0_86F77F4FEFB1__INCLUDED_)
