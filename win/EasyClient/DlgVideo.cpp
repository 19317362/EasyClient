/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
// DlgVideo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EasyClient.h"
#include "DlgVideo.h"
#include "afxdialogex.h"


// CDlgVideo �Ի���

IMPLEMENT_DYNAMIC(CDlgVideo, CDialogEx)

CDlgVideo::CDlgVideo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgVideo::IDD, pParent)
{
	m_pEasyLogo = NULL;
}

CDlgVideo::~CDlgVideo()
{
	UIRenderEngine->RemoveImage(m_pEasyLogo);

}

void CDlgVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgVideo, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgVideo ��Ϣ�������
BOOL CDlgVideo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_pEasyLogo = UIRenderEngine->GetImage(TEXT("SkinUI\\ͼ��\\Easylogo.png"));

	return TRUE;
}

void CDlgVideo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	CBrush brushBkgnd; 
	CRect rcClient;
	brushBkgnd.CreateSolidBrush(RGB(0, 0, 0));
	GetClientRect(&rcClient);
	dc.FillRect(&rcClient, &brushBkgnd);
	brushBkgnd.DeleteObject(); //�ͷŻ�ˢ 

	if ( m_pEasyLogo != NULL && !m_pEasyLogo->IsNull() )
	{
		int nStartX = (rcClient.Width()-184)/2;
		int nStartY =  (rcClient.Height()-184)/2;
		m_pEasyLogo->DrawImage(CDC::FromHandle(dc.m_hDC),nStartX,nStartY);
	}
}
