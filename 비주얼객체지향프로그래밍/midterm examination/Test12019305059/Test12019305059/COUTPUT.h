#pragma once


// COUTPUT 대화 상자

class COUTPUT : public CDialogEx
{
	DECLARE_DYNAMIC(COUTPUT)

public:
	COUTPUT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~COUTPUT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUTPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOUTEX;
	CString m_strOUTFA;
	CString m_strOUTFU;
	CString m_strOUTMU;
};
