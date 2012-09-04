// MFCDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "MFCDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern HINSTANCE hInstLib;

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CMFCDllApp

BEGIN_MESSAGE_MAP(CMFCDllApp, CWinApp)
	//{{AFX_MSG_MAP(CMFCDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDllApp construction

CMFCDllApp::CMFCDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// Called by DllMain
BOOL CMFCDllApp::InitInstance()
{
	CWinApp::InitInstance();

	// Store hInstance
	hInstLib = AfxGetInstanceHandle();

	return TRUE;
}

// Called by DllMain
int CMFCDllApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFCDllApp object

CMFCDllApp theApp;

