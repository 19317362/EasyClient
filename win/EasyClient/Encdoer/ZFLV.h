// ZFLV.h: interface for the ZFLV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZFLV_H__8B156459_85F1_44E7_A594_0C6CFDA065A8__INCLUDED_)
#define AFX_ZFLV_H__8B156459_85F1_44E7_A594_0C6CFDA065A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>
#include <windows.h>
//#include "GnElecPackageMP4.h"
//class CGnElecPackageMP4;
#include "ZFile.h"
class ZFLV  
{
//	FILE*fp;
	long lasttime;
	CRITICAL_SECTION g_cs;

	ZFile m_fp;
	
//	CGnElecPackageMP4 m_mp4;
//	int m_wight;
//	int m_hight;
//	int m_videtrackid;
//	int m_audiotrackid;
//	unsigned char*tempbuff;


public:
	//��ʼ
	void Start();
	/*
	�Ƿ��һ�λ�ȡ����
	*/
	bool firsttime;
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
	*/
	void Init(bool video,bool audio);
	//����
	void Save();
	ZFLV();
	virtual ~ZFLV();

};

#endif // !defined(AFX_ZFLV_H__8B156459_85F1_44E7_A594_0C6CFDA065A8__INCLUDED_)
