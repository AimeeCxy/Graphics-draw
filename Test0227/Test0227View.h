// Test0227View.h : CTest0227View 类的接口
//


#pragma once
#include "atltypes.h"


class CTest0227View : public CView
{
protected: // 仅从序列化创建
	CTest0227View();
	DECLARE_DYNCREATE(CTest0227View)

// 属性
public:
	CTest0227Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CTest0227View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
	void Clean(void);
	CArray<CPoint,CPoint> pointList;
	CArray<CPoint,CPoint> pointList2;
	CPoint pStart;
	CPoint pEnd;
	CArray<CPoint,CPoint> pointList3;
	CArray<CPoint,CPoint> pointList4;
};

#ifndef _DEBUG  // Test0227View.cpp 中的调试版本
inline CTest0227Doc* CTest0227View::GetDocument() const
   { return reinterpret_cast<CTest0227Doc*>(m_pDocument); }
#endif

