
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
	afx_msg void OnEnChangeEdit1();//*******
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CAboutDlg::OnEnChangeEdit1) // ******
END_MESSAGE_MAP()


// Диалоговое окно CControlsDlg



CControlsDlg::CControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTROLS_DIALOG, pParent)
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
	
	ON_EN_CHANGE(IDC_EDIT3, &CControlsDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CControlsDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT1, &CControlsDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CControlsDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT5, &CControlsDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON2, &CControlsDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CControlsDlg::OnBnClickedButton1)
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


void CAboutDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnEnChangeEdit3() //
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnEnChangeEdit4() //
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnEnChangeEdit1() //
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnEnChangeEdit2()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnEnChangeEdit5()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CControlsDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	float P, L, U, a;
	float Z = 0;

	CString text, newText;

	// введенняданихкористувача
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->GetWindowText(text);
	P = _tstof(text);

	pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit->GetWindowText(text);
	L = _tstof(text);

	pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
	pEdit->GetWindowText(text);
	U = _tstof(text);

	pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
	pEdit->GetWindowText(text);
	a = _tstof(text);



	// формування результату обчислення
	Z = P * (1 - L) * U * a * 365;


	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT6);
	// Перевірити, чи вдалось отримати доступ до текстового поля
	if (pEdit)
	{
		// Отримати текст, якийвивести

		newText.Format(_T("%f"), Z);
		//CStringnewText = _T("Текст, якийвихочетевивести");

		// Встановитиновий текст для текстового поля
		pEdit2->SetWindowText(newText);
	}
}


void CControlsDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
