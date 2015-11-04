
//////////////////////////////////////////////////////////////////////////
//
// DShow��ȡ�������Ƶ��������Ƶԭʼ����Dll�����ඨ��
// DShowCaptureAudioAndVideo_Interface.h
// 
//////////////////////////////////////////////////////////////////////////

#ifndef DSHOWCAPTUREAUDIOANDVIDEO_H
#define DSHOWCAPTUREAUDIOANDVIDEO_H

#ifdef __cplusplus

//Ϊ��ʵ�ֶ����Ĵ��麯��
//��ΪC����������Ļ�����ҪԴ���룬Ȼ��������ȥ���Ļ�����ֻҪ�ļ�ͷ���ô����ˡ�

//ʵʱ������������
typedef enum _REALDATA_TYPE
{
	REALDATA_RAW = 0,				//������ֱ���յ�������,������Ƶ����Ƶ�ȵ�
	REALDATA_VIDEO,					//ԭʼ��Ƶ����,������YUY2 UYVY�ȵ�
	REALDATA_AUDIO,					//ԭʼ��Ƶ����,������PCM�ȵ�
	REALDATA_H264,					//��Ƶ������H264��Ƶ����
	REALDATA_AAC,					//��Ƶ������AAC��Ƶ����
}RealDataStreamType;


//�ص�ȡ��ʵʱ���ݽ��д���
// int RealDataManager(int nDevId, unsigned char *pBuffer, int nBufSize, 
// 					RealDataStreamType realDataType, void* realDataInfo);

typedef int (WINAPI *RealDataCallback)(int nDevId, unsigned char *pBuffer, int nBufSize, 
								RealDataStreamType realDataType, void* realDataInfo, void* pMaster);


typedef struct tagThreadCalInfo
{
	RealDataCallback realDataCalFunc;
	void* pMaster;
}ThreadCalInfo;

//��ȡ��Ƶ���ݵ�����ӿ�
class DShowCaptureVideo_Interface
{
public:
	virtual void WINAPI SetVideoCaptureData(int nIndex,int iDeviceId,HWND hWnd,int nFrameRate,
		int iWidth,int iHeight,char* strRGBByte,int nRenderType,int nPinType, 
		int nDataType, BOOL bIsThread) = 0;
	virtual int WINAPI CreateCaptureGraph() = 0;
	virtual int WINAPI BulidPrivewGraph() = 0;
	virtual void WINAPI SetCaptureVideoErr(int nError) = 0;
	virtual void WINAPI BegineCaptureThread() = 0;
	virtual HRESULT WINAPI SetupVideoWindow(HWND hWnd=0) = 0;
	virtual void WINAPI ResizeVideoWindow() = 0;
	virtual void WINAPI SetDShowCaptureCallback(RealDataCallback realDataCalBack, void* pMaster) = 0;

};

//��ȡ��Ƶ���ݵ�����ӿ�
class DShowCaptureAudio_Interface
{
public:
	virtual void WINAPI SetAudioCaptureData(int iDeviceId,int nChannels,
		int nBytesPerSample,int nSampleRate,int nAudioBufferType,int nPinType, 
		int nDataType, BOOL bIsThread) = 0;
	virtual int  WINAPI CreateCaptureGraph()  = 0;
	virtual int  WINAPI BulidCaptureGraph()   = 0;
	virtual void WINAPI BegineCaptureThread() = 0;
	virtual void WINAPI SetDShowCaptureCallback(RealDataCallback realDataCalBack, void* pMaster) = 0;

};

//��Ƶ��ȡ����ӿ�ָ������
typedef	DShowCaptureVideo_Interface*	LPVideoCapturer;	

LPVideoCapturer	APIENTRY Create_VideoCapturer();//�������ƽӿ�ָ��
void APIENTRY Release_VideoCapturer(LPVideoCapturer lpVideoCapturer);//���ٿ��ƽӿ�ָ��


//��Ƶ��ȡ����ӿ�ָ������
typedef	DShowCaptureAudio_Interface*	LPAudioCapturer;	

LPAudioCapturer	APIENTRY Create_AudioCapturer();//�������ƽӿ�ָ��
void APIENTRY Release_AudioCapturer(LPAudioCapturer lpAudioCapturer);//���ٿ��ƽӿ�ָ��

//void APIENTRY SetDShowCaptureCallback(RealDataCallback realDataCalBack, void* pMaster);


#endif//__cplusplus

#endif//DSHOWCAPTUREAUDIOANDVIDEO_H