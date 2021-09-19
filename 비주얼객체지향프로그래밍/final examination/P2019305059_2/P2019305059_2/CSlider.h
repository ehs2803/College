#pragma once


// CSlider 대화 상자

class CSlider : public CDialogEx
{
	DECLARE_DYNAMIC(CSlider)

public:
	CSlider(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSlider();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CSliderCtrl m_sldR;
	CSliderCtrl m_sldB;
	CSliderCtrl m_sldG;
	CSliderCtrl m_sldR;
	int m_nB;
	int m_nG;
	int m_nR;
	COLORREF m_cRGB;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();
};
