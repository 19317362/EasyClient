#pragma once

// ����ƵDShow���񣬻ص���ȡYUV���ݱ�������EasyDarwin������������ [11/3/2015-12:29:46 Dingshuai]
// Create By ��������(Dingshuai)

#include "TypeDefine.h"

#include "Encdoer/RGBtoYUV.h"
#include "./Encdoer/FAACEncoder.h"
#include "./Encdoer/H264Encoder.h"
#include "./Encdoer/H264EncoderManager.h"
#include "./EasyPusher/EasyPusherAPI.h"
#pragma comment(lib, "./EasyPusher/libEasyPusher.lib")

//����DShow��������Ƶģ��DLL��
#include "./DShowCapture/DShowCaptureAudioAndVideo_Interface.h"
#pragma comment(lib, "./DShowCapture/DShowCaptureAudioAndVideoDll.lib")

class CEasyClientDlg;

class CMaster
{
	//Common Function
public:
	CMaster(CEasyClientDlg* pMainDlg);
	~CMaster(void);
	//��ʼ��Ψһ�Ĺ���ʵ��
	static CMaster* Instance(CEasyClientDlg* pMainDlg);
	//����Ψһ�Ĺ���ʵ��
	static void UnInstance();
	//�ͷ�Master��ռ�����Դ
	void RealseMaster();

	//Member Function
public:
	void InitDSCapture();
	void UnInitDSCapture();
	void InitEncoderAndPusher(int nFileIndex = 0);
	void UnInitEncoderAndPusher();
	int StartDSCapture(HWND hShowWnd[], int nWndNum);
	//ʵʱ���ݻص�����
	static int CALLBACK RealDataCallbackFunc(int nDevId, unsigned char *pBuffer, int nBufSize, 
		RealDataStreamType realDataType, /*RealDataStreamInfo*/void* realDataInfo, void* pMaster);
	//�ص�ȡ��ʵʱ���ݽ��д���
	int RealDataManager(int nDevId, unsigned char *pBuffer, int nBufSize, 
		RealDataStreamType realDataType, /*RealDataStreamInfo*/void* realDataInfo);

	//Member Var
private:
	//Ψһ��ʵ��������ָ�� 
	static CMaster* s_pMaster;
	// �����������ڵ�������
	CEasyClientDlg* m_pMainDlg;
	INT m_nDevCount;//�����豸��

	//��Ƶ�豸����ʵ��
	LPVideoCapturer m_pVideoManager[MAX_DEV];
	//��Ƶ�豸����ʵ��
	LPAudioCapturer m_pAudioManager;
	//AAC������
	FAACEncoder m_AACEncoderManager;
	//H264������
	CH264EncoderManager m_H264EncoderManager;
	//������Ϣ����
	Encoder_Config_Info*	m_pEncConfigInfo;
	byte m_sps[100];
	byte  m_pps[100];
	long m_spslen;
	long m_ppslen;
	//Pusher���
	void* m_pusherId;
	byte* m_pFrameBuf; 
	BOOL m_bStartPusher;

};
