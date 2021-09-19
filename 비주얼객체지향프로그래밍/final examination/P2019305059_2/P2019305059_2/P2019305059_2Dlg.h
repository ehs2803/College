
// P2019305059_2Dlg.h: 헤더 파일
//

#pragma once
#include "CSlider.h"

// CP20193050592Dlg 대화 상자
class CP20193050592Dlg : public CDialogEx
{
// 생성입니다.
public:
	CP20193050592Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	UINT htimer;
	HINSTANCE m_hInstance;
	int m_nWidth;
	int m_nHeight;
	int nR;
	int nG;
	int nB;
	CSlider m_slide;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P2019305059_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClickedButtonExit();
	afx_msg void OnClickedButtonNote();
	afx_msg void OnClickedButtonSld();
};
