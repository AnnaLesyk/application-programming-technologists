
// ControlsDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CControlsDlg
class CControlsDlg : public CDialogEx
{
// Создание
public:
	CControlsDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	



public:
	CString m_strMessage;
	CString m_strRun;
	BOOL m_bEnableMsg;
	BOOL m_bEnableProgram;
	BOOL m_bShowsMsg;
	BOOL m_bShowsProgram;

	
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
