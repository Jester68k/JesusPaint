// ���� MFC �T���v�� �\�[�X �R�[�h�ł́AMFC Microsoft Office Fluent ���[�U�[ �C���^�[�t�F�C�X 
// ("Fluent UI") �̎g�p���@�������܂��B���̃R�[�h�́AMFC C++ ���C�u���� �\�t�g�E�F�A�� 
// ��������Ă��� Microsoft Foundation Class ���t�@�����X����ъ֘A�d�q�h�L�������g��
// �⊮���邽�߂̎Q�l�����Ƃ��Ē񋟂���܂��B
// Fluent UI �𕡐��A�g�p�A�܂��͔z�z���邽�߂̃��C�Z���X�����͌ʂɗp�ӂ���Ă��܂��B
// Fluent UI ���C�Z���X �v���O�����̏ڍׂɂ��ẮAWeb �T�C�g
// http://go.microsoft.com/fwlink/?LinkId=238214 ���Q�Ƃ��Ă��������B
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// JP.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "JP.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "NewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CImage g_image;

// CJPApp

BEGIN_MESSAGE_MAP(CJPApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CJPApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CJPApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CJPApp::OnFileOpen)
//	ON_COMMAND(ID_FILE_CLOSE, &CJPApp::OnFileClose)
END_MESSAGE_MAP()


// CJPApp �R���X�g���N�V����

CJPApp::CJPApp()
{
	m_bHiColorIcons = TRUE;

	// �ċN���}�l�[�W���[���T�|�[�g���܂�
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// �A�v���P�[�V���������ʌ��ꃉ���^�C�� �T�|�[�g (/clr) ���g�p���č쐬����Ă���ꍇ:
	//     1) ���̒ǉ��ݒ�́A�ċN���}�l�[�W���[ �T�|�[�g������ɋ@�\���邽�߂ɕK�v�ł��B
	//     2) �쐬����ɂ́A�v���W�F�N�g�� System.Windows.Forms �ւ̎Q�Ƃ�ǉ�����K�v������܂��B
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ���̃A�v���P�[�V���� ID ���������ӂ� ID ������Œu�����܂��B���������
	// ������̌`���� CompanyName.ProductName.SubProduct.VersionInformation �ł�
	SetAppID(_T("JP.AppID.NoVersion"));

	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

// �B��� CJPApp �I�u�W�F�N�g�ł��B

CJPApp theApp;


// CJPApp ������

BOOL CJPApp::InitInstance()
{
	// �A�v���P�[�V���� �}�j�t�F�X�g�� visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll Version 6 �ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �� InitCommonControlsEx() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �A�v���P�[�V�����Ŏg�p���邷�ׂẴR���� �R���g���[�� �N���X���܂߂�ɂ́A
	// �����ݒ肵�܂��B
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE ���C�u���������������܂��B
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit �R���g���[�����g�p����ɂ� AfxInitRichEdit2() ���K�v�ł�	
	// AfxInitRichEdit2();

	// �W��������
	// �����̋@�\���g�킸�ɍŏI�I�Ȏ��s�\�t�@�C����
	// �T�C�Y���k���������ꍇ�́A�ȉ�����s�v�ȏ�����
	// ���[�`�����폜���Ă��������B
	// �ݒ肪�i�[����Ă��郌�W�X�g�� �L�[��ύX���܂��B
	// TODO: ��Ж��܂��͑g�D���Ȃǂ̓K�؂ȕ������
	// ���̕������ύX���Ă��������B
	SetRegistryKey(_T("�A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ���[�J�� �A�v���P�[�V����"));


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ���C�� �E�B���h�E���쐬����Ƃ��A���̃R�[�h�͐V�����t���[�� �E�B���h�E �I�u�W�F�N�g���쐬���A
	// ������A�v���P�[�V�����̃��C�� �E�B���h�E�ɃZ�b�g���܂�
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ���C�� MDI �t���[�� �E�B���h�E���쐬���܂��B
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// ���ʂ� MDI ���j���[�ƃA�N�Z�����[�^ �e�[�u����ǂݍ��݂܂��B
	//TODO: �ǉ��̃����o�[�ϐ��������āA�A�v���P�[�V�������K�v�Ƃ���
	//	�ǉ��̃��j���[�^�C�v�̂��߂ɌĂяo����ǂݍ���ł��������B
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_JPTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_JPTYPE));




	// ���C�� �E�B���h�E�����������ꂽ�̂ŁA�\���ƍX�V���s���܂��B
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}

int CJPApp::ExitInstance()
{
	//TODO: �ǉ��������\�[�X������ꍇ�ɂ͂������������Ă�������
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CJPApp ���b�Z�[�W �n���h���[

void CJPApp::OnFileNew()
{
	CNewDlg newdlg;
	int width, height;

	width = 640;
	height = 480;
	newdlg.m_width = width;
	newdlg.m_height = height;
	if (newdlg.DoModal() == IDOK) {
		width = newdlg.m_width;
		height = newdlg.m_height;
	}
	g_image.Destroy();
	g_image.Create(width, height, 24);

	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// �V���� MDI �q�E�B���h�E���쐬���܂�
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_JPTYPE, m_hMDIMenu, m_hMDIAccel);
}

// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �_�C�A���O�����s���邽�߂̃A�v���P�[�V���� �R�}���h
void CJPApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CJPApp �̃J�X�^�}�C�Y���ꂽ�ǂݍ��݃��\�b�h�ƕۑ����\�b�h

void CJPApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CJPApp::LoadCustomState()
{
}

void CJPApp::SaveCustomState()
{
}

// CJPApp ���b�Z�[�W �n���h���[
void CJPApp::OnFileOpen()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	CString csFilter = _T("JPEG(*.jpg)|*.jpg|GIF(*.gif)|*.gif|PNG(*.png)|*.png|�r�b�g�}�b�v(*.bmp)|*.bmp||");
	CFileDialog load_dialog(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT, csFilter);
	if (load_dialog.DoModal() == IDOK) {
		g_image.Destroy();
		g_image.Load(load_dialog.GetPathName());
	}
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// �V���� MDI �q�E�B���h�E���쐬���܂�
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_JPTYPE, m_hMDIMenu, m_hMDIAccel);
}
