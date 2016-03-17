// Test0227Doc.cpp : CTest0227Doc 类的实现
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


// CTest0227Doc 构造/析构

CTest0227Doc::CTest0227Doc()
{
	// TODO: 在此添加一次性构造代码

}

CTest0227Doc::~CTest0227Doc()
{
}

BOOL CTest0227Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTest0227Doc 序列化

void CTest0227Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CTest0227Doc 诊断

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


// CTest0227Doc 命令
