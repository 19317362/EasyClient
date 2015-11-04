
// �ꡢ�ṹ�Լ�ȫ�ֱ����Ķ��� [11/3/2015-12:40:12 Dingshuai]
// Create By ��������(Dingshuai)
// #include "TypeDefine.h"

#define MAX_DEV 1
#define MAXNAMESIZE 64

// �豸���������Ϣ
typedef struct tagDEVICE_CONFIG_INFO
{
	int nVideoId;//��Ƶ	ID -1==���ã�0-n == id
	int nAudioId;//��Ƶid -1==���ã�0-n == id
	int  nDeviceId;//�豸��� 1,2,3,4,5....
	struct tagVideoInfo
	{
		int nWidth;
		int nHeight;
		int nVideoWndId;
		int nFrameRate;//��Ƶ֡��
		TCHAR strDataType[MAXNAMESIZE];//��ʶYUV�������ͣ���"YUY2" "YUYV" "UYVY��"
		int nRenderType;//���ַ�ʽ
		int nPinType;//�����
	}VideoInfo;

	struct tagAudioInfo
	{
		int nChannaels;//ͨ����
		int nBytesPerSample;//����λ��
		int nSampleRate;//������
		DWORD nAudioBufferType;//��Ƶ�������Ĵ�С
		int nPinType;//�����
	}AudioInfo;

}DEVICE_CONFIG_INFO;

//ʵʱ����������Ϣ �� REALDATA_TYPE ���ʹ��
typedef struct _realdata_callback_param
{	
	int		size;
	struct _video{
		int iEnable;	//�ýṹ���ڵ���Ϣ�Ƿ���Ч //REALDATA_VIDEO or REALDATA_YUV ��Ч
		unsigned int timestampe;	//ʱ�����Ϣ����λ����(ms)
		int width;		//��Ƶ���	//REALDATA_YUV ��Ч
		int height;		//��Ƶ����  //REALDATA_YUV ��Ч
		int encodeType;	//��Ƶ�������� 0:δ֪ H264 = 1 or mpeg4 = 2 //��ǰĬ��ΪH264 //REALDATA_VIDEO ��Ч
		int frameType;	//֡���� 0:δ֪ IDR֡=1 I֡=2 P֡=3 B֡=4 //REALDATA_VIDEO ��Ч
	}video;
	struct _audio{
		int iEnable;	//�ýṹ���ڵ���Ϣ�Ƿ���Ч //REALDATA_AUDIO or REALDATA_PCM ��Ч
		unsigned int timestampe;	//ʱ�����Ϣ����λ����(ms)
		int	bits;		//λ�� 16bits or 8bits	//REALDATA_PCM ��Ч
		int samplerate;	//������ 8000Hz 16000Hz 44100Hz�ȵ�	//REALDATA_PCM ��Ч
		int channels;	//������ ������=1 or ˫����=2	//REALDATA_PCM ��Ч
		int encodeType;	//��Ƶ�������� 0:δ֪ AAC=1 MP3=2 G729=10	//REALDATA_AUDIO ��Ч
	}audio;
}RealDataStreamInfo;

//����������Ϣ
//m_nResizeVideoWidth,m_nResizeVideoHeight,25,2000,3,m_nScrVideoWidth,m_nScrVideoHeight);
typedef struct tagEncoder_Config_Info
{
	int nScrVideoWidth;
	int nScrVideoHeight;
	int nResizeVideoWidth;
	int nResizeVideoHeight;
	int nFps;//֡��
	int nMainBitRate;//����Ƶ����
	int nSingleBitRate;//����Ƶ����
	int nMainEncLevel;//�����뼶��
	int nSingleEncLevel;//�ӱ��뼶��
	int nMainEncQuality;//��������Ƶ����
	int nSingleEncQuality;//�ӱ�����Ƶ����


	int nMainKeyFrame;//���ؼ�֡
	int nSingleKeyFrame;//�ӹؼ�֡

	int nMainUseQuality;
	int nSingleUseQuality;//�Ƿ�������������1--����,0--����
	int nRtmpUseQuality;//�Ƿ�������������1--����,0--����
	int nRtmpVideoWidth;//rtmp
	int nRtmpVideoHeight;
	int nRtmpEncLevel;
	int nRtmpEncQuality;
	int nRtmpBitRate;
	int nRtmpKeyFrame;
	CString nRtmpURL;

	int nMaxVideoFrames;//��Ӱģʽ�����Ƶ֡��
	int nSingleVideoFrames;//��Դģʽ�����Ƶ֡��

	DWORD nMaxPerFileSize;//���ÿ���ļ���С
	int nResizeType;

}Encoder_Config_Info;