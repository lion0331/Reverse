#pragma once


// FunctionDialog 对话框

class FunctionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FunctionDialog)

public:
	FunctionDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FunctionDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_One };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
};
