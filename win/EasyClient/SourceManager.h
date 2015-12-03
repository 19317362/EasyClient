/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
// EasyDarwin���ͺͽ���Դ�˵Ĺ����� [11/8/2015 Dingshuai]
// Add by SwordTwelve
#pragma once

#define EasyClent_VersionInfo _T("Version:1.1.1.4 Powered By SwordTwelve/Gavin/Arno")

//������Ƶ����
#include "AudioSource\DirectSound.h"
//������Ƶ����
#include "VideoSource\USBCamera\CameraDS.h"
//��������Ƶ���ɼ�
#include "EasyPlayerManager.h"
//DShow����Ƶ�ɼ���ͷ�ļ���ӣ���Ӹÿ���Ҫ��Ϊ�˽������ƵԴͷ�ϲ�ͬ�������⣩
#include "./DShowCapture/DShowCaptureAudioAndVideo_Interface.h"

#include "./FFEncoder/FFEncoderAPI.h"
#pragma comment(lib, "./FFEncoder/FFEncoder.lib")


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
	//DShowʵʱ���ݻص�����
	static int CALLBACK RealDataCallbackFunc(int nDevId, unsigned char *pBuffer, int nBufSize, 
																	   RealDataStreamType realDataType, /*RealDataStreamInfo*/void* realDataInfo, void* pMaster);
	void DSRealDataManager(int nDevId, unsigned char *pBuffer, int nBufSize, 
		RealDataStreamType realDataType, /*RealDataStreamInfo*/void* realDataInfo);

	static int CALLBACK __MediaSourceCallBack( int _channelId, int *_channelPtr, int _frameType, char *pBuf, RTSP_FRAME_INFO* _frameInfo);
	int SourceManager(int _channelId, int *_channelPtr, int _frameType, char *pBuf, RTSP_FRAME_INFO* _frameInfo);

	int StartDSCapture(int nCamId, int nAudioId,HWND hShowWnd, int nVideoWidth, int nVideoHeight, int nFps, int nBitRate);
	//��ʼ����(�ɼ�)
	int StartCapture(SOURCE_TYPE eSourceType, int nCamId, int nAudioId,  HWND hCapWnd, 
		char* szURL = NULL, int nVideoWidth=640, int nVideoHeight=480, int nFps=25, int nBitRate=2048);
	//ֹͣ�ɼ�
	void StopCapture();

	//��ʼ����
	int StartPush(char* ServerIp, int nPushPort, char* sPushName, int nPushBufSize = 1024);
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
		//int nVideoCap = m_videoCamera.InRunning();
		if (m_bDSCapture ||nStreamCap>0 )
			bCap = TRUE;
		else
			bCap = FALSE;
		return bCap ;
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
	void ResizeVideoWnd();

protected:
		void	UpdateLocalVideo(unsigned char *pbuf, int size, int width, int height);

	//Member Var
private:
	CEasyClientDlg* m_pMainDlg;
	CDirectSound	m_audioCapture;
	CCameraDS		m_videoCamera;

	//////////////////////////////////////////////////////////////////////////
	// ���ز���
	////////////////////////////////////////////////////////////////////////// 
	//��Ƶ�豸����ʵ��
	LPVideoCapturer m_pVideoManager;
	//��Ƶ�豸����ʵ��
	LPAudioCapturer m_pAudioManager;

	//��������RTSP����������
	EasyPlayerManager m_netStreamCapture;
	//����EasyDarwin�Ƴ���RTSP�����в���
	EasyPlayerManager m_netStreamPlayer;

	//����Dshow�����������
	DEVICE_CONFIG_INFO m_sDevConfigInfo;
	EASY_MEDIA_INFO_T   m_mediainfo;
	EASY_LOCAL_SOURCE_T m_sSourceInfo;
	EASY_LOCAL_SOURCE_T m_sPushInfo;
	EASY_LOCAL_SOURCE_T m_sPlayInfo;

	BOOL m_bDSCapture;
	D3D_HANDLE		m_d3dHandle;
	HWND m_hCaptureWnd;
	HWND m_hPlayWnd;
	BOOL m_bPushing;

	//FF---���������
	FFE_HANDLE m_hFfeVideoHandle;
	FFE_HANDLE m_hFfeAudioHandle;
	int m_nFrameNum;
	char * m_EncoderBuffer;// = new char[1920*1080];	//���������ڴ�ռ�

};

