#pragma once


// SkillDialog 对话框

class SkillDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SkillDialog)

public:
	SkillDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SkillDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Two };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
