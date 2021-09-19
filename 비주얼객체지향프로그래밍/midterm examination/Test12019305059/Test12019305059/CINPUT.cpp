// CINPUT.cpp: 구현 파일
//

#include "pch.h"
#include "Test12019305059.h"
#include "CINPUT.h"
#include "afxdialogex.h"


// CINPUT 대화 상자

IMPLEMENT_DYNAMIC(CINPUT, CDialogEx)

CINPUT::CINPUT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INPUT, pParent)
	, m_strINEX(_T(""))
	, m_strINFA(_T(""))
	, m_str(_T(""))
	, m_strINMU(_T(""))
{

}

CINPUT::~CINPUT()
{
}

void CINPUT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_EX, m_strINEX);
	DDX_Text(pDX, IDC_EDIT_IN_FA, m_strINFA);
	DDX_Text(pDX, IDC_EDIT_IN_FU, m_str);
	DDX_Text(pDX, IDC_EDIT_IN_MUSIC, m_strINMU);
}


BEGIN_MESSAGE_MAP(CINPUT, CDialogEx)
END_MESSAGE_MAP()


// CINPUT 메시지 처리기
