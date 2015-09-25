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

// ChildView.h : CChildView クラスのインターフェイス
//


#pragma once
#include "atlimage.h"


// CChildView ウィンドウ

class CChildView : public CWnd
{
// コンストラクション
public:
	CChildView();

// 属性
public:

// 操作
public:

// オーバーライド
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 実装
public:
	virtual ~CChildView();

	// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileClose();
protected:
	bool modified_flag;
	CBitmap scrn;
	unsigned int width;
	unsigned int height;
	CImage image;
	COLORREF color;
public:
	afx_msg void OnColorDialog();
};

