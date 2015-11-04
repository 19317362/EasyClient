// ZMP4ByGPAC.h: interface for the ZMP4AVC1class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ZMP4GPAC_H)
#define ZMP4GPAC_H

#include <time.h>

#include <gpac/isomedia.h>
#pragma comment(lib,"libgpac.lib")

#ifndef ZOUTFILE_FLAG_FULL
#define ZOUTFILE_FLAG_VIDEO 0x01
#define ZOUTFILE_FLAG_AUDIO 0x02
#define ZOUTFILE_FLAG_FULL (ZOUTFILE_FLAG_AUDIO|ZOUTFILE_FLAG_VIDEO)
#endif

class ZMP4ByGPAC 
{
	//���÷��
	int		m_flag;//������Ƶ��Ƶ

	long	m_audiostartimestamp;
	long	m_videostartimestamp;

	GF_ISOFile *p_file;//MP4�ļ�
    GF_AVCConfig *p_config;//MP4����
    GF_ISOSample *p_videosample;//MP4֡
	GF_ISOSample *p_audiosample;//MP4֡

	
	int m_wight;
	int m_hight;
	int m_videtrackid;
	int m_audiotrackid;

	unsigned int i_videodescidx;
	unsigned int i_audiodescidx;
	

public:
	ZMP4ByGPAC();
	virtual ~ZMP4ByGPAC();
public:

	bool CreateFile(char*filename,int flag);
	//sps,pps��һ���ֽ�Ϊ0x67��68,
	bool WriteH264SPSandPPS(unsigned char*sps,int spslen,unsigned char*pps,int ppslen,int width,int height);
	//д��AAC��Ϣ
	bool WriteAACInfo(unsigned char*info,int len);
	//д��һ֡��ǰ���ֽ�Ϊ��֡NAL����
	bool WriteH264Frame(unsigned char*data,int len,bool keyframe,long timestamp);
	//д��aac���ݣ�ֻ��raw����
	bool WriteAACFrame(unsigned char*data,int len,long timestamp);
	//�����ļ�
	bool SaveFile();
	
	bool CanWrite();
};

#endif // !defined(AFX_ZMP4_H__CD8C3DF9_A2A4_494D_948E_5672ADBE739D__INCLUDED_)
