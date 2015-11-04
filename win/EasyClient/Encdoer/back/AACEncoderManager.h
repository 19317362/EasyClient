// AACEncoderManager.h: interface for the CAACEncoderManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AACENCODERMANAGER_H__CB1D102B_73A8_4C16_9DBA_4F3874CF446D__INCLUDED_)
#define AFX_AACENCODERMANAGER_H__CB1D102B_73A8_4C16_9DBA_4F3874CF446D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAACEncoderManager  
{
private:
	ULONG m_nSampleRate;  // ������
    UINT m_nChannels;         // ������
    UINT m_nPCMBitSize;      // ������λ��
    ULONG m_nInputSamples;	//�������������
    ULONG m_nMaxOutputBytes;	//�������ֽ�
//	ULONG nInputBytes;		//�����ֽ�
	faacEncHandle m_hAACEncoder;
    faacEncConfigurationPtr m_pAACConfiguration; 
//	bool m_bIsworking;
	byte* m_paacbuffer;
	CRITICAL_SECTION m_hcritical_section;	
public:
	int Clean();
	int Init();
	byte* Encoder(byte *indata,int inlen,int &outlen);
	CAACEncoderManager();
	virtual ~CAACEncoderManager();

	bool IsWorking(void);
};

#endif // !defined(AFX_AACENCODERMANAGER_H__CB1D102B_73A8_4C16_9DBA_4F3874CF446D__INCLUDED_)
