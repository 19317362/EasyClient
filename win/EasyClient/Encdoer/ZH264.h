// ZH264.h: interface for the ZH264 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZH264_H__73683E64_93AB_48F8_BC47_1EEE761D8CA8__INCLUDED_)
#define AFX_ZH264_H__73683E64_93AB_48F8_BC47_1EEE761D8CA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdint.h"
#include "ZCOMMON.h"
#include "ZFLV.h"
#include "ZMP4.h"
extern "C"
{
#include "x264_config.h"
#include "x264.h"
}

#define ZH264_DEFAULT 0
#define ZH264_ULTRAFAST 1
#define ZH264_SUPERFAST 2
#define ZH264_VERYFAST 3
#define ZH264_FASTER 4
#define ZH264_FAST 5

void X264_CONFIG_SET(x264_param_t*param,int mode);

class ZH264  
{

	ZFLV*m_flv;
	ZMP4*m_mp4;

	x264_t*h;
	x264_param_t param;
	x264_picture_t m_pic;
	x264_picture_t m_picout;
	x264_nal_t*	nal;
	int yw;
	int yh;

public:
//	void ZSet(	x264_param_t*param);
	/*
	����yuv����
	BYTE*indata,YUV420����
	int inlen,���ݳ���
	*/
	void H264Encode(BYTE*indata,int inlen);
//	void GetFrame(BYTE*indata,int inlen,BYTE *outdata, int &outlen,bool &key);
//	void GetFirstFrame(BYTE*indata,int inlen,BYTE*spsdata,int &spslen,BYTE*ppsdata,int &ppslen,BYTE*data,int&datalen);
	/*
	����
	*/
	void Clean();
	/*
	��ʼ��ZH264
	ZFLV*flv,ZFLVָ��
	ZMP4*mp4,ZMP4ָ��
	int w,��Ƶ��
	int h,��Ƶ��
	int fps,��Ƶfps
	int cpu=0,��Ч
	int leave=0,ѹ������1~7��0ΪĬ��7
	int mode=0,������ʽ��0���Σ�1������
	*/
	void Init(ZFLV*flv,ZMP4*mp4,int w,int h,int fps,int bitrate=0,int leave=0,int mode=0);
	ZH264();
	virtual ~ZH264();

};

#endif // !defined(AFX_ZH264_H__73683E64_93AB_48F8_BC47_1EEE761D8CA8__INCLUDED_)
