// VCPrj.h : main header file for the VCPRJ application
//

#if !defined(AFX_VCPRJ_H__6286B8BF_712D_4144_AD69_F65A58108453__INCLUDED_)
#define AFX_VCPRJ_H__6286B8BF_712D_4144_AD69_F65A58108453__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVCPrjApp:
// See VCPrj.cpp for the implementation of this class
//

class CVCPrjApp : public CWinApp
{
public:
	CVCPrjApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCPrjApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVCPrjApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCPRJ_H__6286B8BF_712D_4144_AD69_F65A58108453__INCLUDED_)
