// ZOutFile.h: interface for the ZOutFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZOUTFILE_H__96237C74_F7A8_482A_8876_A12ED200CC9F__INCLUDED_)
#define AFX_ZOUTFILE_H__96237C74_F7A8_482A_8876_A12ED200CC9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///����Ƶ������Ƶ���ؼ�֡����
#include <time.h>

#define ZOUTFILE_FLAG_VIDEO 0x01
#define ZOUTFILE_FLAG_AUDIO 0x02
#define ZOUTFILE_FLAG_FULL (ZOUTFILE_FLAG_AUDIO|ZOUTFILE_FLAG_VIDEO)
class ZOutFile  
{
public:
	//�ļ���������
	virtual	bool CreateFile(char*filename,int flag)=0;
	//sps,pps��һ���ֽ�Ϊ0x67��68,
	virtual bool WriteH264SPSandPPS(byte*sps,int spslen,byte*pps,int ppslen,int width,int height)=0;
	//д��AAC��Ϣ
	virtual bool WriteAACInfo(byte*info,int len)=0;
	//д��һ֡��ǰ���ֽ�Ϊ��֡NAL����
	virtual bool WriteH264Frame(byte*data,int len,long timestamp)=0;
	//д��aac���ݣ�ֻ��raw����
	virtual bool WriteAACFrame(byte*data,int len,long timestamp)=0;
	//�����ļ�
	virtual bool SaveFile()=0;
	//д״̬

//	void GetWidthAndHeightFromPPS(byte*pps,int ppslen,int&width,int &height);
	ZOutFile();
	virtual ~ZOutFile();

};

#endif // !defined(AFX_ZOUTFILE_H__96237C74_F7A8_482A_8876_A12ED200CC9F__INCLUDED_)
