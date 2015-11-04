// ZMP4.h: interface for the ZMP4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZMP4_H__CD8C3DF9_A2A4_494D_948E_5672ADBE739D__INCLUDED_)
#define AFX_ZMP4_H__CD8C3DF9_A2A4_494D_948E_5672ADBE739D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GnElecPackageMP4.h"
#define MP4_NUL_NUM 3
class ZMP4  
{
	bool IsWrite;
public:
	ZMP4();
	virtual ~ZMP4();

	CRITICAL_SECTION g_cs;	
	CGnElecPackageMP4 m_mp4;
	int m_wight;
	int m_hight;
	int m_videtrackid;
	int m_audiotrackid;
//	unsigned char*tempbuff;
	long lasttime;
//	long lasttimeA;
	bool firsttime;
//	bool firsttimeA;
	
	
public:
	//��ʼ
	void Start();
	/*
	�Ƿ��һ�λ�ȡ����
	*/

	/*
	��ʼ��AAC��Ϣ
	BYTE*data,��������
	int len,���ݳ���
	long timestemp,ʱ���
	*/
	void InitAAC(BYTE*data,int len,long timestemp);
	/*
	��ȡAAC����
	BYTE*data,��������
	int len,���ݳ���
	long timestemp,ʱ���
	*/
	void GetAACData(BYTE*data,int len,long timestemp);
	/*
	��ȡH264����
	BYTE*data,��������
	int len,���ݳ���
	bool key,�Ƿ�ؼ�֡
	long timestemp,ʱ���
	*/
	void GetH264Data(BYTE*data,int len,bool key,long timestemp);
	/*
	��ʼ��H264��Ϣ
	BYTE*sps,sps����
	int spslen,sps����
	BYTE* pps,pps����
	int ppslen,pps����
	long timestemp,ʱ���
	*/	
	void InitH264(BYTE*sps,int spslen,BYTE* pps,int ppslen,long timestemp);
	/*
	��ʼ����
	bool video,�Ƿ�����Ƶ
	bool audio,�Ƿ�����Ƶ
	long width,��Ƶ��
	long hight,��Ƶ��
	long Samples,��Ƶ������
	*/
	void Init(bool video,bool audio,long width,long hight,long Samples);
	//����
	void Save();


};

#endif // !defined(AFX_ZMP4_H__CD8C3DF9_A2A4_494D_948E_5672ADBE739D__INCLUDED_)
