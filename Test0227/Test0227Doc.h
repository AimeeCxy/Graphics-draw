// Test0227Doc.h : CTest0227Doc ��Ľӿ�
//


#pragma once


class CTest0227Doc : public CDocument
{
protected: // �������л�����
	CTest0227Doc();
	DECLARE_DYNCREATE(CTest0227Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CTest0227Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


