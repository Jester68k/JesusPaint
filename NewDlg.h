#pragma once

#include "afxwin.h"
#include "jp.h"

class CNewDlg : public CDialog
{
	// �R���X�g���N�V����
public:
	CNewDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	// �_�C�A���O �f�[�^
	//{{AFX_DATA(CNewDlg)
	enum { IDD = IDD_NEW };
	UINT	m_width;
	UINT	m_height;
	//}}AFX_DATA


	// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CNewDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

	// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CNewDlg)
	// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

