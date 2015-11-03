#pragma once


#include "DlgVideo.h"
#include "../libEasyPlayer/libEasyPlayerAPI.h"
#ifdef _DEBUG
#pragma comment(lib, "../Debug/libEasyPlayer.lib")
#else
#pragma comment(lib, "../Release/libEasyPlayer.lib")
#endif


typedef struct __EASY_CHANNEL_INFO_T
{
	int		channelId;


}EASY_CHANNEL_INFO_T;

// CDlgRemotePanel �Ի���

class CDlgRemotePanel : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRemotePanel)

public:
	CDlgRemotePanel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRemotePanel();

// �Ի�������
	enum { IDD = IDD_DIALOG_REMOTE_PANEL };


protected:
	CStatic			*pStaticServerAddr;	//IDC_STATIC_SERVER_ADDR
	CEdit			*pEdtServerAddr;	//IDC_EDIT_SERVER_ADDR
	CButton			*pBtnStart;			//IDC_BUTTON_START
	CDlgVideo		*pDlgVideo;
	void		UpdateComponents();

	EASY_CHANNEL_INFO_T	easyChannelInfo;

	void		CloseRtspChannel();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButtonStart();
};
