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

// JP.cpp : アプリケーションのクラス動作を定義します。
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


// CJPApp コンストラクション

CJPApp::CJPApp()
{
	m_bHiColorIcons = TRUE;

	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// アプリケーションが共通言語ランタイム サポート (/clr) を使用して作成されている場合:
	//     1) この追加設定は、再起動マネージャー サポートが正常に機能するために必要です。
	//     2) 作成するには、プロジェクトに System.Windows.Forms への参照を追加する必要があります。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 下のアプリケーション ID 文字列を一意の ID 文字列で置換します。推奨される
	// 文字列の形式は CompanyName.ProductName.SubProduct.VersionInformation です
	SetAppID(_T("JP.AppID.NoVersion"));

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

// 唯一の CJPApp オブジェクトです。

CJPApp theApp;


// CJPApp 初期化

BOOL CJPApp::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE ライブラリを初期化します。
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit コントロールを使用するには AfxInitRichEdit2() が必要です	
	// AfxInitRichEdit2();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// メイン ウィンドウを作成するとき、このコードは新しいフレーム ウィンドウ オブジェクトを作成し、
	// それをアプリケーションのメイン ウィンドウにセットします
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// メイン MDI フレーム ウィンドウを作成します。
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// 共通の MDI メニューとアクセラレータ テーブルを読み込みます。
	//TODO: 追加のメンバー変数を加えて、アプリケーションが必要とする
	//	追加のメニュータイプのために呼び出しを読み込んでください。
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_JPTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_JPTYPE));




	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}

int CJPApp::ExitInstance()
{
	//TODO: 追加したリソースがある場合にはそれらも処理してください
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CJPApp メッセージ ハンドラー

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
	// 新しい MDI 子ウィンドウを作成します
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_JPTYPE, m_hMDIMenu, m_hMDIAccel);
}

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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

// ダイアログを実行するためのアプリケーション コマンド
void CJPApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CJPApp のカスタマイズされた読み込みメソッドと保存メソッド

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

// CJPApp メッセージ ハンドラー
void CJPApp::OnFileOpen()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	CString csFilter = _T("JPEG(*.jpg)|*.jpg|GIF(*.gif)|*.gif|PNG(*.png)|*.png|ビットマップ(*.bmp)|*.bmp||");
	CFileDialog load_dialog(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT, csFilter);
	if (load_dialog.DoModal() == IDOK) {
		g_image.Destroy();
		g_image.Load(load_dialog.GetPathName());
	}
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// 新しい MDI 子ウィンドウを作成します
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_JPTYPE, m_hMDIMenu, m_hMDIAccel);
}
