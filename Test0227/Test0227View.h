// Test0227View.h : CTest0227View ��Ľӿ�
//


#pragma once
#include "atltypes.h"


class CTest0227View : public CView
{
protected: // �������л�����
	CTest0227View();
	DECLARE_DYNCREATE(CTest0227View)

// ����
public:
	CTest0227Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CTest0227View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Test0227View.cpp �еĵ��԰汾
inline CTest0227Doc* CTest0227View::GetDocument() const
   { return reinterpret_cast<CTest0227Doc*>(m_pDocument); }
#endif

