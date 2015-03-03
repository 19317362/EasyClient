/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
// DlgVideo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgVideo.h"
#include "afxdialogex.h"


#include "../libEasyPlayer/libEasyPlayerAPI.h"

// CDlgVideo �Ի���

IMPLEMENT_DYNAMIC(CDlgVideo, CDialogEx)

CDlgVideo::CDlgVideo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgVideo::IDD, pParent)
{
	m_WindowId	=	-1;
	m_ChannelId	=	-1;
	bDrag		=	false;

	InitialComponents();
}

CDlgVideo::~CDlgVideo()
{
}

void CDlgVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgVideo, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_PREVIEW, &CDlgVideo::OnBnClickedButtonPreview)
	ON_BN_CLICKED(IDC_CHECK_OSD, &CDlgVideo::OnBnClickedCheckOsd)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDlgVideo ��Ϣ�������
LRESULT CDlgVideo::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (WM_PAINT == message || WM_SIZE==message)
	{
		UpdateComponents();
	}

	return CDialogEx::WindowProc(message, wParam, lParam);
}


BOOL CDlgVideo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CreateComponents();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CDlgVideo::DestroyWindow()
{
	DeleteComponents();

	return CDialogEx::DestroyWindow();
}


void CDlgVideo::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HWND hWnd = ::GetParent(GetSafeHwnd());
	::PostMessageW(hWnd, WM_WINDOW_MAXIMIZED, m_WindowId, 0);

	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CDlgVideo::OnLButtonDown(UINT nFlags, CPoint point)
{
	bDrag = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDlgVideo::OnLButtonUp(UINT nFlags, CPoint point)
{
	bDrag = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CDlgVideo::OnMouseMove(UINT nFlags, CPoint point)
{
	if (bDrag)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		if (! rcClient.IsRectEmpty())
		{
			int nX = (int)(((float)point.x / (float)rcClient.Width() * 100.0f));
			int nY = (int)(((float)point.y / (float)rcClient.Height() * 100.0f));

			TRACE("X: %d\tY: %d\n", nX, nY);
		}
	}


	CDialogEx::OnMouseMove(nFlags, point);
}

void	CDlgVideo::SetWindowId(int _windowId)	
{
	m_WindowId = _windowId;

	if (m_WindowId == 0)
	{
		if (NULL != pEdtURL)		pEdtURL->SetWindowText(TEXT("rtsp://218.204.223.237:554/live/1/0547424F573B085C/gsfp90ef4k0a6iap.sdp"));
	}

	if (m_WindowId == 1)
	{
		if (NULL != pEdtURL)		pEdtURL->SetWindowText(TEXT("rtsp://218.204.223.237:554/live/1/66251FC11353191F/e7ooqwcfbqjoo80j.sdp"));
	}
	
}

void	CDlgVideo::InitialComponents()
{
	pDlgRender	=	NULL;
	pEdtURL		=	NULL;
	pEdtUsername=	NULL;
	pEdtPassword=	NULL;
	pChkOSD		=	NULL;
	pSliderCache=	NULL;
	pBtnPreview	=	NULL;
}

void	CDlgVideo::CreateComponents()
{
	if (NULL == pDlgRender)
	{
		pDlgRender = new CDlgRender();
		pDlgRender->Create(IDD_DIALOG_RENDER, this);
		pDlgRender->ShowWindow(SW_SHOW);
	}

	__CREATE_WINDOW(pEdtURL,		CEdit,		IDC_EDIT_RTSP_URL);
	__CREATE_WINDOW(pEdtUsername,	CEdit,		IDC_EDIT_USERNAME);
	__CREATE_WINDOW(pEdtPassword,	CEdit,		IDC_EDIT_PASSWORD);
	__CREATE_WINDOW(pChkOSD,		CButton,	IDC_CHECK_OSD);
	__CREATE_WINDOW(pSliderCache,	CSliderCtrl,IDC_SLIDER_CACHE);
	__CREATE_WINDOW(pBtnPreview,	CButton,	IDC_BUTTON_PREVIEW);

	if (NULL != pEdtURL)		pEdtURL->SetWindowText(TEXT("rtsp://"));
	if (NULL != pEdtUsername)	pEdtUsername->SetWindowText(TEXT("admin"));
	if (NULL != pEdtPassword)	pEdtPassword->SetWindowText(TEXT("admin"));
	if (NULL != pSliderCache)	pSliderCache->SetRange(1, 10);
	if (NULL != pSliderCache)	pSliderCache->SetPos(3);

	if (NULL != pBtnPreview)		pBtnPreview->SetWindowText(TEXT("Play"));
}
void	CDlgVideo::UpdateComponents()
{
	CRect	rcClient;
	GetClientRect(&rcClient);
	if (rcClient.IsRectEmpty())		return;

	CRect	rcRender;
	rcRender.SetRect(rcClient.left, rcClient.top, rcClient.right, rcClient.bottom-20);
	__MOVE_WINDOW(pDlgRender, rcRender);
	if (NULL != pDlgRender)		pDlgRender->Invalidate();

	CRect	rcURL;
	rcURL.SetRect(rcClient.left, rcRender.bottom+2, rcClient.right-280, rcClient.bottom);
	__MOVE_WINDOW(pEdtURL, rcURL);
	if (NULL != pEdtURL)		pEdtURL->Invalidate();

	CRect	rcUsername;
	rcUsername.SetRect(rcURL.right+2, rcURL.top, rcURL.right+2+50, rcURL.bottom);
	__MOVE_WINDOW(pEdtUsername, rcUsername);
	if (NULL != pEdtUsername)		pEdtUsername->Invalidate();

	CRect	rcPassword;
	rcPassword.SetRect(rcUsername.right+2, rcUsername.top, rcUsername.right+2+rcUsername.Width(), rcUsername.bottom);
	__MOVE_WINDOW(pEdtPassword, rcPassword);
	if (NULL != pEdtPassword)		pEdtPassword->Invalidate();

	CRect	rcOSD;
	rcOSD.SetRect(rcPassword.right+2, rcPassword.top, rcPassword.right+2+38, rcPassword.bottom);
	__MOVE_WINDOW(pChkOSD, rcOSD);
	if (NULL != pChkOSD)		pChkOSD->Invalidate();
	CRect	rcCache;
	rcCache.SetRect(rcOSD.right+2, rcOSD.top, rcOSD.right+2+60, rcOSD.bottom);
	__MOVE_WINDOW(pSliderCache, rcCache);
	if (NULL != pSliderCache)		pSliderCache->Invalidate();

	CRect	rcPreview;
	rcPreview.SetRect(rcCache.right+2, rcURL.top, rcClient.right, rcURL.bottom);
	__MOVE_WINDOW(pBtnPreview, rcPreview);
	if (NULL != pBtnPreview)		pBtnPreview->Invalidate();
}
void	CDlgVideo::DeleteComponents()
{
	if (m_ChannelId > 0)
	{
		EasyPlayer_CloseStream(m_ChannelId);
		m_ChannelId = -1;
	}
	__DELETE_WINDOW(pDlgRender);
}

bool __WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,NULL,0,NULL,FALSE);
	if(dwSize < dwMinSize)
	{
		return false;
	}
	WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,lpszStr,dwSize,NULL,FALSE);
	return true;
}

void CDlgVideo::OnBnClickedButtonPreview()
{
	if (m_ChannelId > 0)
	{
		EasyPlayer_CloseStream(m_ChannelId);
		m_ChannelId = -1;

		if (NULL != pDlgRender)			pDlgRender->Invalidate();
		if (NULL != pBtnPreview)		pBtnPreview->SetWindowText(TEXT("Play"));
	}
	else
	{
		wchar_t wszURL[128] = {0,};
		if (NULL != pEdtURL)	pEdtURL->GetWindowTextW(wszURL, sizeof(wszURL));
		if (wcslen(wszURL) < 1)		return;

		wchar_t wszUsername[32] = {0,};
		wchar_t wszPassword[32] = {0,};
		if (NULL != pEdtUsername)	pEdtUsername->GetWindowText(wszUsername, sizeof(wszUsername));
		if (NULL != pEdtPassword)	pEdtPassword->GetWindowText(wszPassword, sizeof(wszPassword));

		char szURL[128] = {0,};
		__WCharToMByte(wszURL, szURL, sizeof(szURL)/sizeof(szURL[0]));
		char szUsername[32] = {0,};
		char szPassword[32] = {0,};
		__WCharToMByte(wszUsername, szUsername, sizeof(szUsername)/sizeof(szUsername[0]));
		__WCharToMByte(wszPassword, szPassword, sizeof(szPassword)/sizeof(szPassword[0]));

		HWND hWnd = NULL;
		if (NULL != pDlgRender)	hWnd = pDlgRender->GetSafeHwnd();
		m_ChannelId = EasyPlayer_OpenStream(szURL, hWnd, (RENDER_FORMAT)RenderFormat, szUsername, szPassword);

		if (m_ChannelId > 0)
		{
			int iPos = pSliderCache->GetPos();
			EasyPlayer_SetFrameCache(m_ChannelId, iPos);		//���û���

			if (NULL != pBtnPreview)		pBtnPreview->SetWindowText(TEXT("Stop"));
		}
	}
}



void CDlgVideo::OnBnClickedCheckOsd()
{
	int nShow = 0x00;

	if (NULL != pChkOSD)		nShow = pChkOSD->GetCheck();

	if (m_ChannelId > 0)
	{
		EasyPlayer_ShowStatisticalInfo(m_ChannelId, nShow);
	}
}



void CDlgVideo::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if( NULL != pScrollBar && NULL != pSliderCache &&
		pSliderCache->GetDlgCtrlID() == pScrollBar->GetDlgCtrlID())
	{
		int iPos = pSliderCache->GetPos();
		
		if (m_ChannelId > 0)
		{
			EasyPlayer_SetFrameCache(m_ChannelId, iPos);
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
