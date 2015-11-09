#pragma once


#include "DlgVideo.h"
#include "../libEasyPlayer/libEasyPlayerAPI.h"
#ifdef _DEBUG
#pragma comment(lib, "../Debug/libEasyPlayer.lib")
#else
#pragma comment(lib, "../Release/libEasyPlayer.lib")
#endif


/*
typedef struct __EASY_CHANNEL_INFO_T
{
	int		channelId;


}EASY_CHANNEL_INFO_T;
*/

// CDlgPanel �Ի���

class CDlgPanel : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPanel)

public:
	CDlgPanel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPanel();

// �Ի�������
	enum { IDD = IDD_DIALOG_PANEL };

protected:
	CDlgVideo		*pDlgVideo;
	void		UpdateComponents();

	//EASY_CHANNEL_INFO_T	easyChannelInfo;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL DestroyWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonStart();
};
