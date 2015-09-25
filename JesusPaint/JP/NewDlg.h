#pragma once

#include "afxwin.h"
#include "jp.h"

class CNewDlg : public CDialog
{
	// コンストラクション
public:
	CNewDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

	// ダイアログ データ
	//{{AFX_DATA(CNewDlg)
	enum { IDD = IDD_NEW };
	UINT	m_width;
	UINT	m_height;
	//}}AFX_DATA


	// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CNewDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

	// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CNewDlg)
	// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

