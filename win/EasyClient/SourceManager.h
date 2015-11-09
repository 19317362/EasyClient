/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
// EasyDarwin���ͺͽ���Դ�˵Ĺ����� [11/8/2015 Dingshuai]
// Add by SwordTwelve

#pragma once

//������Ƶ����
#include "AudioSource\DirectSound.h"
//������Ƶ����
#include "VideoSource\USBCamera\CameraDS.h"
//��������Ƶ���ɼ�
#include "EasyPlayerManager.h"

typedef enum tagSOURCE_TYPE
{
	SOURCE_LOCAL_CAMERA = 0,//��������Ƶ
	SOURCE_RTSP_STREAM=1,//RTSP��
	SOURCE_ONVIF_STREAM=2//Onvif��

}SOURCE_TYPE;

class CEasyClientDlg ;

class CSourceManager
{
public:
	CSourceManager(void);
	~CSourceManager(void);

public:
	static CSourceManager* s_pSourceManager; 
	//��ʼ��Ψһ�Ĺ���ʵ��
	static CSourceManager* Instance();
	//����Ψһ�Ĺ���ʵ��
	static void UnInstance();
	//�ͷ�Master��ռ�����Դ
	void RealseManager();
	// Member Function Interface
public:
	//ִ����ƵԴ��ʼ������
	void InitSource();
	//����ʼ��
	void UnInitSource();
	static int CALLBACK __MediaSourceCallBack( int _channelId, int *_channelPtr, int _frameType, char *pBuf, RTSP_FRAME_INFO* _frameInfo);
	int SourceManager(int _channelId, int *_channelPtr, int _frameType, char *pBuf, RTSP_FRAME_INFO* _frameInfo);

	//��ʼ����(�ɼ�)
	int StartCapture(SOURCE_TYPE eSourceType, int nCamId,  HWND hCapWnd, char* szURL = NULL);
	//ֹͣ�ɼ�
	void StopCapture();

	//��ʼ����
	int StartPush(char* ServerIp, int nPushPort, char* sPushName);
	//ֹͣ����
	void StopPush();
	
	//��ʼ����
	int StartPlay(char* szURL, HWND hShowWnd);
	//ֹͣ����
	void StopPlay();
	void SetMainDlg(	CEasyClientDlg* pMainDlg);
	void LogErr(CString strLog);
	void EnumLocalAVDevInfo(CWnd* pComboxMediaSource, CWnd* pComboxAudioSource);

	//״̬
	BOOL IsInCapture()
	{
		BOOL bCap = FALSE;
		int nStreamCap = m_netStreamCapture.InRunning();
		int nVideoCap = m_videoCamera.InRunning();
		if (nVideoCap>0 ||nStreamCap>0 )
			bCap = TRUE;
		else
			bCap = FALSE;
		return bCap;
	}
	BOOL IsInPushing()
	{
		//return (int)m_sPushInfo.pusherHandle>0?TRUE:FALSE;
		return m_bPushing;
	}
	BOOL IsInPlaying()
	{
		return m_netStreamPlayer.InRunning()>0?TRUE:FALSE;
	}
protected:
		void	UpdateLocalVideo(unsigned char *pbuf, int size, int width, int height);

	//Member Var
private:
	CEasyClientDlg* m_pMainDlg;
	CDirectSound	m_audioCapture;
	CCameraDS		m_videoCamera;
	//��������RTSP����������
	EasyPlayerManager m_netStreamCapture;
	//����EasyDarwin�Ƴ���RTSP�����в���
	EasyPlayerManager m_netStreamPlayer;

	EASY_MEDIA_INFO_T   m_mediainfo;
	CAMERA_LIST_T		*m_pCameraList;
	EASY_LOCAL_SOURCE_T m_sSourceInfo;
	EASY_LOCAL_SOURCE_T m_sPushInfo;
	EASY_LOCAL_SOURCE_T m_sPlayInfo;
	int			m_nLocalVideoWidth;
	int			m_nLocalVideoHeight;
	unsigned char	*rgbData;
	int				rgbDataSize;
	D3D_HANDLE		m_d3dHandle;
	HWND m_hCaptureWnd;
	HWND m_hPlayWnd;
	BOOL m_bPushing;
};

