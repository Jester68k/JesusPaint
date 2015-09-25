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

// ChildView.cpp : CChildView �N���X�̎���
//

#include "stdafx.h"
#include "JP.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	HDC imageHDC;

	width = g_image.GetWidth();
	height = g_image.GetHeight();
	image.Create(width, height, 24);
	imageHDC = image.GetDC();
	g_image.Draw(imageHDC, 0, 0);
	image.ReleaseDC();
	modified_flag = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_SAVE_AS, &CChildView::OnFileSaveAs)
	ON_COMMAND(ID_FILE_CLOSE, &CChildView::OnFileClose)
	ON_COMMAND(ID_COLOR_DIALOG, &CChildView::OnColorDialog)
END_MESSAGE_MAP()



// CChildView ���b�Z�[�W �n���h���[

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.cx = width;
	cs.cy = height;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
//	cs.style |= WS_HSCROLL | WS_VSCROLL;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g
	
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����܂��B
	image.Draw(dc.m_hDC, 0, 0);
	// ���b�Z�[�W�̕`��̂��߂� CWnd::OnPaint() ���Ăяo���Ȃ��ł��������B
}



void CChildView::OnFileSaveAs()
{
//	CClientDC dc(this);
//	CDC memDC, imageDC;

	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	CString csFilter = _T("JPEG(*.jpg)|*.jpg|GIF(*.gif)|*.gif|PNG(*.png)|*.png|�r�b�g�}�b�v(*.bmp)|*.bmp||");
	CFileDialog save_dialog(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, csFilter);
	if (save_dialog.DoModal() == IDOK) {
//		memDC.CreateCompatibleDC(&dc);
//		memDC.SelectObject(&scrn);
//		imageDC.FromHandle(image.GetDC());
//		imageDC.BitBlt(0, 0, width, height, &memDC, 0, 0, SRCCOPY);
		image.Save(save_dialog.GetPathName());
	}
}


void CChildView::OnFileClose()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	image.Destroy();
}


void CChildView::OnColorDialog()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	CColorDialog cd;

	if (cd.DoModal() == IDOK)
		color = cd.GetColor();
}
