
// ControlsDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Controls.h"
#include "ControlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CAboutDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Диалоговое окно CControlsDlg



CControlsDlg::CControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTROLS_DIALOG, pParent)
	, m_strMessage(_T(""))
	, m_strRun(_T(""))
	, m_bEnableMsg(FALSE)
	, m_bEnableProgram(FALSE)
	, m_bShowsMsg(FALSE)
	, m_bShowsProgram(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlsDlg::DoDataExchange(CDataExchange* pDX)
{   
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_MSG, m_strMessage);
	//DDX_CBString(pDX, IDC_COMBO_RUN, m_strRun);
	//DDX_Check(pDX, IDC_ENABLE_MSG, m_bEnableMsg);
	//DDX_Check(pDX, IDC_ENABLE_PROGRAM, m_bEnableProgram);
	//DDX_Check(pDX, IDC_SHOWS_MSG, m_bShowsMsg);
	//DDX_Check(pDX, IDC_SHOWS_PROGRAM, m_bShowsProgram);

}

BEGIN_MESSAGE_MAP(CControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CControlsDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CControlsDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CControlsDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK2, &CControlsDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CControlsDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CControlsDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_BUTTON6, &CControlsDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Обработчики сообщений CControlsDlg

BOOL CControlsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CControlsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlsDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CControlsDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CControlsDlg::OnCbnSelchangeCombo1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CControlsDlg::OnBnClickedCheck2()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CControlsDlg::OnBnClickedCheck3()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CControlsDlg::OnBnClickedCheck4()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CControlsDlg::OnBnClickedButton6()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CAboutDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
