/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
	Author: Gavin@easydarwin.org
*/
#ifndef MEMORY_DC_HEAD_FILE
#define MEMORY_DC_HEAD_FILE

#pragma once

#include "EasySkinUI.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//�ڴ�DC��
class  CMemoryDC : public CDC 
{
	//��������
private:
	CBitmap						m_bitmap;										// ��Ļ��λͼ
	CBitmap*					m_oldBitmap;									// ���λͼ����
	CDC*						m_pDC;											// ���澭������CDC
	CRect						m_rect;											// �����λ�������
	BOOL						m_bMemDC;										// �Ƿ�Ϊ�ڴ�DC

	//��������
public:
	//���캯������
	CMemoryDC(CDC* pDC, CRect rect = CRect(0,0,0,0), BOOL bCopyFirst = FALSE);

	//��������
	~CMemoryDC();

	// ����ʹ��ָ��
	CMemoryDC* operator->();

	// ����ʹ��ָ��
	operator CMemoryDC*();
};

#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
