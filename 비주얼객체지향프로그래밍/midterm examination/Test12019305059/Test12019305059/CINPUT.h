#pragma once


// CINPUT 대화 상자

class CINPUT : public CDialogEx
{
	DECLARE_DYNAMIC(CINPUT)

public:
	CINPUT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CINPUT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strINEX;
	CString m_strINFA;
	CString m_str;
	CString m_strINMU;
};
