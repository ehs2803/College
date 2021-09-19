
// Test22019305059View.cpp: CTest22019305059View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Test22019305059.h"
#endif

#include "Test22019305059Doc.h"
#include "Test22019305059View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest22019305059View

IMPLEMENT_DYNCREATE(CTest22019305059View, CView)

BEGIN_MESSAGE_MAP(CTest22019305059View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CTest22019305059View 생성/소멸

CTest22019305059View::CTest22019305059View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTest22019305059View::~CTest22019305059View()
{
}

BOOL CTest22019305059View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTest22019305059View 그리기

void CTest22019305059View::OnDraw(CDC* /*pDC*/)
{   //2019305059 이현수
	CTest22019305059Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	dc.SetTextAlign(TA_CENTER);

	dc.SetTextColor(RGB(0, 0, 255));
	dc.TextOutW(rect.right / 2, 0, CString("2019305059 이현수"));

	CPen pen(PS_SOLID, 10, RGB(255, 255, 0));
	dc.SelectObject(&pen);
	dc.Rectangle(rect.right / 2 -100, rect.bottom / 4-100, rect.right / 2+100, rect.bottom / 4+100);

	CPen pen1(PS_SOLID, 1, RGB(150, 0, 150));
	dc.SelectObject(&pen1);
	dc.Ellipse(rect.right / 2+100, rect.bottom / 4 - 100, rect.right / 2 + 300, rect.bottom / 4 + 100);

}


// CTest22019305059View 인쇄

BOOL CTest22019305059View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTest22019305059View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTest22019305059View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTest22019305059View 진단

#ifdef _DEBUG
void CTest22019305059View::AssertValid() const
{
	CView::AssertValid();
}

void CTest22019305059View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest22019305059Doc* CTest22019305059View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest22019305059Doc)));
	return (CTest22019305059Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest22019305059View 메시지 처리기


void CTest22019305059View::OnLButtonDown(UINT nFlags, CPoint point)
{
	MessageBox(_T("열심히 노력한 나를 칭찬해!"),_T("2019305059이현수. 왼쪽마우스클릭!"));

	CView::OnLButtonDown(nFlags, point);
}
