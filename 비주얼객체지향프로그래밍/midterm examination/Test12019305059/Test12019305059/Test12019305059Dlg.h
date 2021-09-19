
// Test12019305059Dlg.h: 헤더 파일
//

#pragma once
#include "CINPUT.h"
#include "COUTPUT.h"

// CTest12019305059Dlg 대화 상자
class CTest12019305059Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTest12019305059Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CINPUT m_input;
	COUTPUT m_output;
	UINT htimer;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST12019305059_DIALOG };
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
	afx_msg void OnClickedButtonInput();
	afx_msg void OnClickedButtonOutput();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
