#include "stdafx.h"
#include "NewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewDlg �_�C�A���O


CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewDlg)
	m_width = 0;
	m_height = 0;
	//}}AFX_DATA_INIT
}


void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDlg)
	DDX_Text(pDX, IDC_WIDTH, m_width);
	DDV_MinMaxUInt(pDX, m_width, 1, 65535);
	DDX_Text(pDX, IDC_HEIGHT, m_height);
	DDV_MinMaxUInt(pDX, m_height, 1, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialog)
	//{{AFX_MSG_MAP(CNewDlg)
	// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDlg ���b�Z�[�W �n���h��
