// Test0227Doc.cpp : CTest0227Doc ���ʵ��
//

#include "stdafx.h"
#include "Test0227.h"

#include "Test0227Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest0227Doc

IMPLEMENT_DYNCREATE(CTest0227Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest0227Doc, CDocument)
END_MESSAGE_MAP()


// CTest0227Doc ����/����

CTest0227Doc::CTest0227Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CTest0227Doc::~CTest0227Doc()
{
}

BOOL CTest0227Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CTest0227Doc ���л�

void CTest0227Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CTest0227Doc ���

#ifdef _DEBUG
void CTest0227Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest0227Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTest0227Doc ����
