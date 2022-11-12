#pragma once
#include "RoleDialog.h"
#include "FunctionDialog.h"
#include "SkillDialog.h"

#define MAX_PAGE_MAIN 3
// Torchlight2Dialog 对话框

class Torchlight2Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Torchlight2Dialog)

public:
	Torchlight2Dialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Torchlight2Dialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Main };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	RoleDialog   PageZero;
	FunctionDialog   PageOne;
	SkillDialog   PageTwo;
	CDialogEx* Pages[MAX_PAGE_MAIN];
	short      CurPage = 0;
	bool InstallPage(CDialogEx* wnd, int IDD_WND, CString&& _Name, BOOL IsShow = false);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	virtual BOOL OnInitDialog();
	void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CTabCtrl mTab;
};
