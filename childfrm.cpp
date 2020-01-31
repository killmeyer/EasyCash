// ChildFrm.cpp : implementation of the CChildFrame class
//
// Diese Datei ist Bestandteil von EasyCash&Tax, der freien E�R-Fibu
//
// Copyleft (GPLv3) 2020  Thomas Mielke
// 
// Dies ist freie Software; Sie d�rfen sie unter den Bedingungen der 
// GNU General Public License, wie von der Free Software Foundation 
// ver�ffentlicht, weiterverteilen und/oder modifizieren; entweder gem�� 
// Version 3 der Lizenz oder (nach Ihrer Option) jeder sp�teren Version.
//
// Diese Software wird in der Hoffnung weiterverbreitet, dass sie n�tzlich 
// sein wird, jedoch OHNE IRGENDEINE GARANTIE, auch ohne die implizierte 
// Garantie der MARKTREIFE oder der VERWENDBARKEIT F�R EINEN BESTIMMTEN ZWECK.
// Mehr Details finden Sie in der GNU Lesser General Public License.
//
// Sie sollten eine Kopie der GNU General Public License Version 3 zusammen mit 
// dieser Software erhalten haben; falls nicht, schreiben Sie an die Free 
// Software Foundation, Inc., 51 Franklin St, 5th Floor, Boston, MA 02110, USA. 

#include "stdafx.h"
#include "EasyCash.h"
#include "ECTIFace\EasyCashDoc.h"

#include "ChildFrm.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_WM_MDIACTIVATE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    if(CMDIChildWndEx::PreCreateWindow(cs)==0) return FALSE;
	cs.style &= ~(LONG)FWS_ADDTOTITLE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

void CChildFrame::ActivateFrame(int nCmdShow) 
{

	// die plug-ins
	//if (AfxGetMainWnd()->GetMenu()->InsertMenu(4, MF_BYPOSITION|MF_STRING, 0, "Erweiterungen"))
	{
//VS9		CMenu *pm = AfxGetMainWnd()->GetMenu()->GetSubMenu(3);	
//VS9
/*		ExtensionDLLsClass *pExtensionDLLs = ExtensionDLLs;
		if (pExtensionDLLs)
		{
			int i = pm->GetMenuItemCount();
			while (i > 15 && pm->GetMenuItemID(--i) != MF_SEPARATOR)
				pm->RemoveMenu(i, MF_BYPOSITION);

			pm->AppendMenu(MF_STRING|MF_SEPARATOR, 0);	
			while (pExtensionDLLs)
			{
				pm->AppendMenu(MF_STRING, pExtensionDLLs->menu_item_id, pExtensionDLLs->menu_item_string);
				//pm->EnableMenuItem(pExtensionDLLs->menu_item_id, MF_BYCOMMAND|MF_ENABLED);
				pExtensionDLLs = pExtensionDLLs->next;
//VS9			}
//VS9		}
*/	}
	
	
	CMDIChildWndEx::ActivateFrame(nCmdShow);
}

void CChildFrame::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd)
{
	CMDIChildWndEx::OnMDIActivate(bActivate, pActivateWnd, pDeactivateWnd);

	// // Saldo im status bar aktualisieren, z.B. bei Strg-Tab
	if (bActivate)
		((CMainFrame*)m_pMDIFrame)->UpdateSaldo();
}