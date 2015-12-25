/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#pragma once

#include "DlgVideo.h"
#include "SourceManager.h"
#include "afxwin.h"

// CDlgPanel �Ի���
class CEasyClientDlg;

class CDlgPanel : public CEasySkinDialog
{
	DECLARE_DYNAMIC(CDlgPanel)

public:
	CDlgPanel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPanel();

// �Ի�������
	enum { IDD = IDD_DIALOG_PANEL };

protected:
	CDlgVideo		*pDlgVideo;
	CEdit	*m_pEdtServerIP;		
	CEdit	*m_pEdtServerPort;		
	CEdit	*m_pEdtServerStream;		

	CComboBox* m_pCmbType;//ֱ��/������ѡ
	CComboBox* m_pCmbSourceType;//Դ����ѡ��
	CComboBox* m_pCmbCamera;
	CComboBox* m_pCmbMic;
	CComboBox* m_pCmbScreenMode;
	
	CEdit	*m_pEdtRtspStream;		
	CEasySkinButton m_btnStart;
	CEasyClientDlg* m_pMainDlg;
	//EASY_CHANNEL_INFO_T	easyChannelInfo;

protected:
	//UI �������
	virtual void DrawClientArea(CDC*pDC,int nWidth,int nHeight);
	void		UpdateComponents();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCbnSelchangeComboPannelType();
	afx_msg void OnCbnSelchangeComboPannelSource();
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL DestroyWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnInitDialog();
	CWnd* GetDlgVideo();
	void SetMainDlg(CEasyClientDlg* pMainDlg, int nId);
	void UpdataResource();
	//�����Ƹ�ʽ��
	void FormatStreamName(char* sStreamName);

private:
	CSourceManager* m_pManager;
	int m_nWndId;//�Լ��Ĵ���Id
	CFont	m_ftSaticDefault;

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCbnSelchangeComboCapscreenMode();
};
