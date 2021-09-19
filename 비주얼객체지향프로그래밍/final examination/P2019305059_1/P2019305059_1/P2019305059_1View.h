
// P2019305059_1View.h: CP20193050591View 클래스의 인터페이스
//

#pragma once


class CP20193050591View : public CView
{
protected: // serialization에서만 만들어집니다.
	CP20193050591View() noexcept;
	DECLARE_DYNCREATE(CP20193050591View)

// 특성입니다.
public:
	CP20193050591Doc* GetDocument() const;

// 작업입니다.
public:
	BOOL temp;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CP20193050591View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFigCir();
	afx_msg void OnFigRect();
//	afx_msg void OnColorBlue();
//	afx_msg void OnColorRed();
//	afx_msg void OnColorYellow();
	int m_fig=1;
//	afx_msg void OnPaint();
	afx_msg void OnColorPink();
	afx_msg void OnColorPu();
	afx_msg void OnColorGreen();
	int m_inColor=0;
};

#ifndef _DEBUG  // P2019305059_1View.cpp의 디버그 버전
inline CP20193050591Doc* CP20193050591View::GetDocument() const
   { return reinterpret_cast<CP20193050591Doc*>(m_pDocument); }
#endif

