// Test0227.h : Test0227 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CTest0227App:
// 有关此类的实现，请参阅 Test0227.cpp
//

class CTest0227App : public CWinApp
{
public:
	CTest0227App();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest0227App theApp;