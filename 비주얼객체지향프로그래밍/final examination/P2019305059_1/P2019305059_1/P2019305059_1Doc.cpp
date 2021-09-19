
// P2019305059_1Doc.cpp: CP20193050591Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "P2019305059_1.h"
#endif

#include "P2019305059_1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BLACK RGB(0,0,0)
#define RED RGB(255,0,0)
#define BLUE RGB(52,52,255)
#define YELLOW RGB(255,204,51)
#define GREEN RGB(0,255,0)
#define PINK RGB(243,97,220)
#define PURE RGB(165,102,255)

// CP20193050591Doc

IMPLEMENT_DYNCREATE(CP20193050591Doc, CDocument)

BEGIN_MESSAGE_MAP(CP20193050591Doc, CDocument)
	ON_COMMAND(ID_COLOR_RED, &CP20193050591Doc::OnColorRed)
	ON_COMMAND(ID_COLOR_BLUE, &CP20193050591Doc::OnColorBlue)
	ON_COMMAND(ID_COLOR_YELLOW, &CP20193050591Doc::OnColorYellow)
//	ON_COMMAND(ID_COLOR_GREEN, &CP20193050591Doc::OnColorGreen)
//	ON_COMMAND(ID_COLOR_PINK, &CP20193050591Doc::OnColorPink)
//	ON_COMMAND(ID_COLOR_PU, &CP20193050591Doc::OnColorPu)
END_MESSAGE_MAP()


// CP20193050591Doc 생성/소멸

CP20193050591Doc::CP20193050591Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CP20193050591Doc::~CP20193050591Doc()
{
}

BOOL CP20193050591Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CP20193050591Doc serialization

void CP20193050591Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CP20193050591Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CP20193050591Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CP20193050591Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CP20193050591Doc 진단

#ifdef _DEBUG
void CP20193050591Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CP20193050591Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CP20193050591Doc 명령
void CP20193050591Doc::ColorSet(COLORREF color) {
	m_curColor = color;
	UpdateAllViews(NULL);
}

COLORREF CP20193050591Doc::ColorGet() {
	return m_curColor;
}

void CP20193050591Doc::OnColorRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ColorSet(RED);
}


void CP20193050591Doc::OnColorBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ColorSet(BLUE);
}


void CP20193050591Doc::OnColorYellow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ColorSet(YELLOW);
}


//void CP20193050591Doc::OnColorGreen()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}


//void CP20193050591Doc::OnColorPink()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}


//void CP20193050591Doc::OnColorPu()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}
