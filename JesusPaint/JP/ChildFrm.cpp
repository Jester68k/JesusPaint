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

// ChildFrm.cpp : CChildFrame �N���X�̎���
//

#include "stdafx.h"
#include "JP.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_CLOSE, &CChildFrame::OnFileClose)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CChildFrame �R���X�g���N�V����/�f�X�g���N�V����

CChildFrame::CChildFrame()
{
	// TODO: �����o�[�������R�[�h�������ɒǉ����Ă��������B
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs ��ύX���āAWindow �N���X�܂��̓X�^�C����ύX���܂��B
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	cs.cx = g_image.GetWidth() + ::GetSystemMetrics(SM_CXSIZEFRAME) * 2;
	cs.cy = g_image.GetHeight() + ::GetSystemMetrics(SM_CXSIZEFRAME) * 2 + ::GetSystemMetrics(SM_CYCAPTION);
	//	cs.style |= WS_HSCROLL | WS_VSCROLL;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CChildFrame �f�f

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

// CChildFrame ���b�Z�[�W �n���h���[
void CChildFrame::OnFileClose() 
{
	// ���̃t���[�������ɂ́AWM_CLOSE �𑗂�܂��B���̃��b�Z�[�W�́A
	// �V�X�e�� ���j���[�� [����] ��I�������ꍇ�Ɠ����ł��B
	SendMessage(WM_CLOSE);
}

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// �t���[���̃N���C�A���g�̈�S�̂��߂�r���[���쐬���܂��B
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�r���[ �E�B���h�E���쐬�ł��܂���ł����B\n");
		return -1;
	}

	return 0;
}

void CChildFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CMDIChildWndEx::OnSetFocus(pOldWnd);

	m_wndView.SetFocus();
}

BOOL CChildFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// �r���[�ɍŏ��ɃR�}���h����������@���^���܂��B
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;
	
	// ����ȊO�̏ꍇ�́A����̏������s���܂��B
	return CMDIChildWndEx::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
