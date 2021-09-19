
// P2019305059_2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "P2019305059_2.h"
#include "P2019305059_2Dlg.h"
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


// CP20193050592Dlg 대화 상자



CP20193050592Dlg::CP20193050592Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P2019305059_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP20193050592Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CP20193050592Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CP20193050592Dlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_NOTE, &CP20193050592Dlg::OnClickedButtonNote)
	ON_BN_CLICKED(IDC_BUTTON_SLD, &CP20193050592Dlg::OnClickedButtonSld)
END_MESSAGE_MAP()


// CP20193050592Dlg 메시지 처리기

BOOL CP20193050592Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	htimer = SetTimer(1, 1000, NULL);
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
	nR = 255;
	nG = 228;
	nB = 0;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CP20193050592Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CP20193050592Dlg::OnPaint()
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
		CPaintDC dc(this);
		CPen pen(PS_SOLID, 10, RGB(nR,nG,nB));
		dc.SelectObject(&pen);
		dc.Rectangle(0, 0, m_nWidth / 2, 3 * m_nHeight / 4);

		HBITMAP hbitmap = ::LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

		HDC hMemDC = ::CreateCompatibleDC(NULL);
		SelectObject(hMemDC, hbitmap);
		::StretchBlt(dc.m_hDC, 0+10, 0+10, m_nWidth/2-10, 3*m_nHeight/4-10, hMemDC, 0, 0,48,48, SRCCOPY);

	
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CP20193050592Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CP20193050592Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime gct = CTime::GetCurrentTime();
	CString strTime;

	strTime.Format(_T("%d 시 %d 분 %d 초"), gct.GetHour(), gct.GetMinute(), gct.GetSecond());
	GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void CP20193050592Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_nWidth = cx;
	m_nHeight=cy;
	Invalidate();
}


void CP20193050592Dlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CP20193050592Dlg::OnClickedButtonNote()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	system("notepad.exe");
}


void CP20193050592Dlg::OnClickedButtonSld()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_slide.DoModal();
	nR = m_slide.m_nR;
	nG = m_slide.m_nG;
	nB = m_slide.m_nB;
	Invalidate();
}
