// この MFC サンプル ソース コードでは、MFC Microsoft Office Fluent ユーザー インターフェイス 
// ("Fluent UI") の使用方法を示します。このコードは、MFC C++ ライブラリ ソフトウェアに 
// 同梱されている Microsoft Foundation Class リファレンスおよび関連電子ドキュメントを
// 補完するための参考資料として提供されます。
// Fluent UI を複製、使用、または配布するためのライセンス条項は個別に用意されています。
// Fluent UI ライセンス プログラムの詳細については、Web サイト
// http://go.microsoft.com/fwlink/?LinkId=238214 を参照してください。
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// ChildView.cpp : CChildView クラスの実装
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



// CChildView メッセージ ハンドラー

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
	CPaintDC dc(this); // 描画のデバイス コンテキスト
	
	// TODO: ここにメッセージ ハンドラー コードを追加します。
	image.Draw(dc.m_hDC, 0, 0);
	// メッセージの描画のために CWnd::OnPaint() を呼び出さないでください。
}



void CChildView::OnFileSaveAs()
{
//	CClientDC dc(this);
//	CDC memDC, imageDC;

	// TODO: ここにコマンド ハンドラー コードを追加します。
	CString csFilter = _T("JPEG(*.jpg)|*.jpg|GIF(*.gif)|*.gif|PNG(*.png)|*.png|ビットマップ(*.bmp)|*.bmp||");
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
	// TODO: ここにコマンド ハンドラー コードを追加します。
	image.Destroy();
}


void CChildView::OnColorDialog()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	CColorDialog cd;

	if (cd.DoModal() == IDOK)
		color = cd.GetColor();
}
