// ZAAC.h: interface for the ZAAC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZAAC_H__CCDDE86E_DF80_4C62_8551_46F9DA67D81D__INCLUDED_)
#define AFX_ZAAC_H__CCDDE86E_DF80_4C62_8551_46F9DA67D81D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//4096�����ֽ�
//1024����������

class ZAAC  
{
	bool IsPlay;	
	ZFLV*m_flv;
	ZMP4*m_mp4;
	//ZRTMP*m_rtmp;

	ULONG nSampleRate;  // ������
    UINT nChannels;         // ������
    UINT nPCMBitSize;      // ������λ��
    ULONG nInputSamples;	//�������������
    ULONG nMaxOutputBytes;	//���
	ULONG nInputBytes;

	faacEncHandle hEncoder;
    faacEncConfigurationPtr pConfiguration; 
	BYTE* pbAACBuffer;

public:
	void Init(ZFLV*flv,ZMP4*mp4);//,ZRTMP*rtmp);
	void Clean();
	void AACEncode(BYTE*indata,int inlen);
	ZAAC();
	virtual ~ZAAC();

};

#endif // !defined(AFX_ZAAC_H__CCDDE86E_DF80_4C62_8551_46F9DA67D81D__INCLUDED_)
