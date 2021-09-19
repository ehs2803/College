
// Test12019305059Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test12019305059.h"
#include "Test12019305059Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTest12019305059Dlg 대화 상자



CTest12019305059Dlg::CTest12019305059Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST12019305059_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest12019305059Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTest12019305059Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CTest12019305059Dlg::OnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CTest12019305059Dlg::OnClickedButtonOutput)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTest12019305059Dlg::OnClickedButtonExit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTest12019305059Dlg 메시지 처리기

BOOL CTest12019305059Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	htimer = SetTimer(1, 1000, NULL);
	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTest12019305059Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTest12019305059Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTest12019305059Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest12019305059Dlg::OnClickedButtonInput()
{
	m_input.DoModal();
}


void CTest12019305059Dlg::OnClickedButtonOutput()
{
	UpdateData(FALSE);
	m_output.m_strOUTEX = m_input.m_strINEX;
	m_output.m_strOUTFA = m_input.m_strINFA;
	m_output.m_strOUTFU = m_input.m_str;
	m_output.m_strOUTMU = m_input.m_strINMU;
	UpdateData(TRUE);
	m_output.DoModal();
}


void CTest12019305059Dlg::OnClickedButtonExit()
{   //2019305059 이현수
	KillTimer(htimer);
	PostQuitMessage(0);
}


void CTest12019305059Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime gct = CTime::GetCurrentTime();

	CString strDate, strtime;
	CString temp;

	strDate.Format(_T("%d 년 %d 월 %d 일 "), gct.GetYear(), gct.GetMonth(), gct.GetDay());
	GetDlgItem(IDC_STATIC_DATE)->SetWindowText((LPCTSTR)strDate);
	if (gct.GetHour() > 12) {
		strtime.Format(_T("오후%d 시 %d 분"), gct.GetHour() - 12, gct.GetMinute());
		GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strtime);
		
	}
	else {
		strtime.Format(_T("오전 %d 시 %d 분"), gct.GetHour(), gct.GetMinute());
		GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strtime);
		
	}
	CDialogEx::OnTimer(nIDEvent);
}
