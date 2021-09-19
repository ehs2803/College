// COUTPUT.cpp: 구현 파일
//

#include "pch.h"
#include "Test12019305059.h"
#include "COUTPUT.h"
#include "afxdialogex.h"


// COUTPUT 대화 상자

IMPLEMENT_DYNAMIC(COUTPUT, CDialogEx)

COUTPUT::COUTPUT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OUTPUT, pParent)
	, m_strOUTEX(_T(""))
	, m_strOUTFA(_T(""))
	, m_strOUTFU(_T(""))
	, m_strOUTMU(_T(""))
{

}

COUTPUT::~COUTPUT()
{
}

void COUTPUT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OUT_EX, m_strOUTEX);
	DDX_Text(pDX, IDC_EDIT_OUT_FA, m_strOUTFA);
	DDX_Text(pDX, IDC_EDIT_OUT_FU, m_strOUTFU);
	DDX_Text(pDX, IDC_EDIT_OUT_MUSIC, m_strOUTMU);
}


BEGIN_MESSAGE_MAP(COUTPUT, CDialogEx)
END_MESSAGE_MAP()


// COUTPUT 메시지 처리기
