// Test0227.h : Test0227 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTest0227App:
// �йش����ʵ�֣������ Test0227.cpp
//

class CTest0227App : public CWinApp
{
public:
	CTest0227App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest0227App theApp;