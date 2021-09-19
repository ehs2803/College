
// P2019305059_1View.cpp: CP20193050591View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "P2019305059_1.h"
#endif

#include "P2019305059_1Doc.h"
#include "P2019305059_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CP20193050591View

IMPLEMENT_DYNCREATE(CP20193050591View, CView)

BEGIN_MESSAGE_MAP(CP20193050591View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FIG_CIR, &CP20193050591View::OnFigCir)
	ON_COMMAND(ID_FIG_RECT, &CP20193050591View::OnFigRect)
//	ON_COMMAND(ID_COLOR_BLUE, &CP20193050591View::OnColorBlue)
//	ON_COMMAND(ID_COLOR_RED, &CP20193050591View::OnColorRed)
//	ON_COMMAND(ID_COLOR_YELLOW, &CP20193050591View::OnColorYellow)
//ON_WM_PAINT()
ON_COMMAND(ID_COLOR_PINK, &CP20193050591View::OnColorPink)
ON_COMMAND(ID_COLOR_PU, &CP20193050591View::OnColorPu)
ON_COMMAND(ID_COLOR_GREEN, &CP20193050591View::OnColorGreen)
END_MESSAGE_MAP()

// CP20193050591View 생성/소멸

CP20193050591View::CP20193050591View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CP20193050591View::~CP20193050591View()
{
}

BOOL CP20193050591View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CP20193050591View 그리기

void CP20193050591View::OnDraw(CDC* pDC)
{
	CP20193050591Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);

	CFont font, * pOldFoint;
	font.CreatePointFont(200, _T("Times New Roman"));
	pOldFoint = (CFont*)pDC->SelectObject(&font);

	pDC->SetTextAlign(TA_CENTER);
	pDC->SetTextColor(RGB(0, 255, 0));
	pDC->SetBkColor(RGB(255, 255,255));
	pDC->TextOutW(rect.right / 2, 0, CString("2019305059 이현수"));

	if (temp==TRUE) {
		if (m_fig == 1) {
			CPen pen1(PS_SOLID, 20, pDoc->ColorGet());
			pDC->SelectObject(&pen1);
			pDC->Ellipse(100, 100, 200, 200); 
			if (m_inColor == 0) {
				CBrush brush(RGB(255, 255, 255));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(100, 100, 200, 200);
			}
			else if (m_inColor == 1) {
				CBrush brush(RGB(255, 0, 127));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(100, 100, 200, 200);
			}
			else if (m_inColor == 2) {
				CBrush brush(RGB(95,0, 255));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(100, 100, 200, 200);
			}
			else if (m_inColor == 3) {
				CBrush brush(RGB(0, 255, 0));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(100, 100, 200, 200);
			}
			
		}
		else {
			CPen blackpen(PS_SOLID, 20, pDoc->ColorGet());
			pDC->SelectObject(&blackpen);
			pDC->Rectangle(100, 100, 200, 200);
			if (m_inColor == 0) {
				CBrush brush(RGB(255, 255, 255));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(100, 100, 200, 200);
			}
			else if (m_inColor == 1) {
				CBrush brush(RGB(255, 0, 127));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(100, 100, 200, 200);
			}
			else if (m_inColor == 2) {
				CBrush brush(RGB(95, 0, 255));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(100, 100, 200, 200);
			}
			else if (m_inColor == 3) {
				CBrush brush(RGB(0, 255, 0));
				CBrush* pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(100, 100, 200, 200);
			}
		}
		temp = FALSE;
	}

}


// CP20193050591View 인쇄

BOOL CP20193050591View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CP20193050591View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CP20193050591View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CP20193050591View 진단

#ifdef _DEBUG
void CP20193050591View::AssertValid() const
{
	CView::AssertValid();
}

void CP20193050591View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CP20193050591Doc* CP20193050591View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CP20193050591Doc)));
	return (CP20193050591Doc*)m_pDocument;
}
#endif //_DEBUG


// CP20193050591View 메시지 처리기


void CP20193050591View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	temp = TRUE;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CP20193050591View::OnFigCir()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_fig = 1;
	Invalidate();
}


void CP20193050591View::OnFigRect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_fig = 2;
	Invalidate();
}



//void CP20193050591View::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
//					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
//
//}


void CP20193050591View::OnColorPink()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_inColor = 1;
	Invalidate();
}


void CP20193050591View::OnColorPu()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_inColor = 2;
	Invalidate();
}


void CP20193050591View::OnColorGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_inColor = 3;
	Invalidate();
}
