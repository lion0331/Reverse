#pragma once


// RoleDialog 对话框

class RoleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RoleDialog)

public:
	RoleDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RoleDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Zero };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	float HP;
	float MP;
	int Strength;
	int Dexterity;
	int Focus;
	int Vitality;
	int Level;
	int Fame;
	CString Name;
	int StatPoints;
	int SkillPoints;
	int EXP;
	int Gold;
};
