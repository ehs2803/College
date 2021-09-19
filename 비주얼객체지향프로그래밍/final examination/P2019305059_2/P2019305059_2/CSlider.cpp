// CSlider.cpp: 구현 파일
//

#include "pch.h"
#include "P2019305059_2.h"
#include "CSlider.h"
#include "afxdialogex.h"


// CSlider 대화 상자

IMPLEMENT_DYNAMIC(CSlider, CDialogEx)

CSlider::CSlider(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_nB(0)
	, m_nG(0)
	, m_nR(0)
{

}

CSlider::~CSlider()
{
}

void CSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SLIDER_G, m_sldR);
	DDX_Control(pDX, IDC_SLIDER_B, m_sldB);
	DDX_Control(pDX, IDC_SLIDER_G, m_sldG);
	DDX_Control(pDX, IDC_SLIDER_R, m_sldR);
	DDX_Text(pDX, IDC_EDIT_B, m_nB);
	DDX_Text(pDX, IDC_EDIT_G, m_nG);
	DDX_Text(pDX, IDC_EDIT_R, m_nR);
}


BEGIN_MESSAGE_MAP(CSlider, CDialogEx)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &CSlider::OnBnClickedOk)
END_MESSAGE_MAP()


// CSlider 메시지 처리기


BOOL CSlider::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_sldB.SetRange(0, 255);
	m_sldG.SetRange(0, 255);
	m_sldR.SetRange(0, 255);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSlider::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CRect rect;
	CClientDC rgbdc(GetDlgItem(IDC_STATIC));
	CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC);
	pSRGB->GetClientRect(rect);
	rgbdc.FillSolidRect(rect, m_cRGB);
	pSRGB->ValidateRect(rect);
}


void CSlider::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	int nR = m_sldR.GetPos();
	int nG = m_sldG.GetPos();
	int nB = m_sldB.GetPos();

	if ((pScrollBar == (CScrollBar*)&m_sldR) || (pScrollBar == (CScrollBar*)&m_sldG) || (pScrollBar == (CScrollBar*)&m_sldB)) {
		int nPosR = m_sldR.GetPos();
		int nPosG = m_sldG.GetPos();
		int nPosB = m_sldB.GetPos();

		m_nR = nPosR;
		m_nG = nPosG;
		m_nB = nPosB;

		m_cRGB = RGB(m_nR, m_nG, m_nB);
		UpdateData(FALSE);
		InvalidateRect(&rect);
	}
	else {
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}


void CSlider::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Invalidate();
	CDialogEx::OnOK();
}
