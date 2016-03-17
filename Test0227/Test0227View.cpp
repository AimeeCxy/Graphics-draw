// Test0227View.cpp : CTest0227View 类的实现
//

#include "stdafx.h"
#include "Test0227.h"

#include "Test0227Doc.h"
#include "Test0227View.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest0227View

IMPLEMENT_DYNCREATE(CTest0227View, CView)

BEGIN_MESSAGE_MAP(CTest0227View, CView)
	ON_COMMAND(ID_One, &CTest0227View::OnOne)
	ON_COMMAND(ID_Two, &CTest0227View::OnTwo)
	ON_COMMAND(ID_Three, &CTest0227View::OnThree)
END_MESSAGE_MAP()

// CTest0227View 构造/析构

CTest0227View::CTest0227View()
: pStart(0)
, pEnd(0)
{
	// TODO: 在此处添加构造代码

}

CTest0227View::~CTest0227View()
{
}

BOOL CTest0227View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTest0227View 绘制

void CTest0227View::OnDraw(CDC* /*pDC*/)
{
	CTest0227Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	CPoint p;
	p.x = 460;p.y = 320;
	pointList.Add(p);
	p.x = 300;p.y = 300;
	pointList.Add(p);
	p.x = 200;p.y = 100;
	pointList.Add(p);
	p.x = 200;p.y = 10;
	pointList.Add(p);
	p.x = 350;p.y = 80;
	pointList.Add(p);
	p.x = 260;p.y = 100;
	pointList.Add(p);

	// TODO: 在此处为本机数据添加绘制代码
}


// CTest0227View 诊断

#ifdef _DEBUG
void CTest0227View::AssertValid() const
{
	CView::AssertValid();
}

void CTest0227View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest0227Doc* CTest0227View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest0227Doc)));
	return (CTest0227Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest0227View 消息处理程序

void CTest0227View::OnOne()
{
	// TODO: 在此添加命令处理程序代码
	Clean();
	CClientDC dc(this);
	for(int i=0;i<pointList.GetSize()-3;i++){
		int a1 = -pointList.GetAt(i).x + 3*pointList.GetAt(i+1).x - 3*pointList.GetAt(i+2).x + pointList.GetAt(i+3).x ;
		int a2 = -pointList.GetAt(i).y + 3*pointList.GetAt(i+1).y - 3*pointList.GetAt(i+2).y + pointList.GetAt(i+3).y ;
		int b1 = 3*pointList.GetAt(i).x - 6*pointList.GetAt(i+1).x + 3*pointList.GetAt(i+2).x ;
		int b2 = 3*pointList.GetAt(i).y - 6*pointList.GetAt(i+1).y + 3*pointList.GetAt(i+2).y ;
		int c1 = -3*pointList.GetAt(i).x + 3*pointList.GetAt(i+2).x ;
		int c2 = -3*pointList.GetAt(i).y + 3*pointList.GetAt(i+2).y ;
		int d1 = pointList.GetAt(i).x + 4*pointList.GetAt(i+1).x + pointList.GetAt(i+2).x ;
		int d2 = pointList.GetAt(i).y + 4*pointList.GetAt(i+1).y + pointList.GetAt(i+2).y ;

		if(i%3==0){
			CPen pen(PS_SOLID,1,RGB(255,0,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pStart.x=d1/6;pStart.y=d2/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==1){
			CPen pen(PS_SOLID,1,RGB(0,255,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==2){
			CPen pen(PS_SOLID,1,RGB(0,0,255));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pEnd.x=(a1+b1+c1+d1)/6;
			pEnd.y=(a2+b2+c2+d2)/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}	
	}
}

void CTest0227View::OnTwo()
{
	// TODO: 在此添加命令处理程序代码
	//Clean();
	OnOne();
	pointList2.SetSize(pointList.GetSize());
	if(pEnd.x!=pStart.x){
		double k = (pEnd.y-pStart.y)/(pEnd.x-pStart.x);
		double b = pEnd.y - k*pEnd.x;
		for(int i=0;i<pointList.GetSize();i++){
			double kk = -1/k;
			double bb = pointList.GetAt(i).y - kk*pointList.GetAt(i).x;
			double xx = (bb-b)/(k-kk);
			double yy = k*xx+b;
			CPoint pp;
			pp.x = xx;pp.y = yy;
			pointList2.SetAt(i,pp);
		}
	}else{
		for(int i=0;i<pointList.GetSize();i++){
			double xx = 2*pEnd.x - pointList.GetAt(i).x;
			double yy = pointList.GetAt(i).y;
			CPoint pp;
			pp.x = xx;pp.y = yy;
			pointList2.SetAt(i,pp);
		}
	}
	CClientDC dc(this);
	for(int i=0;i<pointList2.GetSize()-3;i++){
		int a1 = -pointList2.GetAt(i).x + 3*pointList2.GetAt(i+1).x - 3*pointList2.GetAt(i+2).x + pointList2.GetAt(i+3).x ;
		int a2 = -pointList2.GetAt(i).y + 3*pointList2.GetAt(i+1).y - 3*pointList2.GetAt(i+2).y + pointList2.GetAt(i+3).y ;
		int b1 = 3*pointList2.GetAt(i).x - 6*pointList2.GetAt(i+1).x + 3*pointList2.GetAt(i+2).x ;
		int b2 = 3*pointList2.GetAt(i).y - 6*pointList2.GetAt(i+1).y + 3*pointList2.GetAt(i+2).y ;
		int c1 = -3*pointList2.GetAt(i).x + 3*pointList2.GetAt(i+2).x ;
		int c2 = -3*pointList2.GetAt(i).y + 3*pointList2.GetAt(i+2).y ;
		int d1 = pointList2.GetAt(i).x + 4*pointList2.GetAt(i+1).x + pointList2.GetAt(i+2).x ;
		int d2 = pointList2.GetAt(i).y + 4*pointList2.GetAt(i+1).y + pointList2.GetAt(i+2).y ;
		if(i%3==0){
			CPen pen(PS_SOLID,1,RGB(255,0,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==1){
			CPen pen(PS_SOLID,1,RGB(0,255,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==2){
			CPen pen(PS_SOLID,1,RGB(0,0,255));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}	
	}
}

void CTest0227View::OnThree()
{
	// TODO: 在此添加命令处理程序代码
	Clean();
	//OnTwo();
	double theta = 0;
	double pi = 3.1415926 ;
	double xxx = pStart.x;
	double yyy = pStart.y;
	pointList3.SetSize(pointList.GetSize());
	for(int i=0;i<8;i++){
		for(int j=0;j<pointList.GetSize();j++){
			CPoint p;
			p.x = (pointList.GetAt(j).x-xxx) * cos(theta*pi/180) - (pointList.GetAt(j).y-yyy) *sin(theta*pi/180) +xxx;
			p.y = (pointList.GetAt(j).x-xxx) * sin(theta*pi/180) + (pointList.GetAt(j).y-yyy) *cos(theta*pi/180) +yyy;
			pointList3.SetAt(j,p);
		}
		theta = theta + 45;
	CClientDC dc(this);
	for(int i=0;i<pointList3.GetSize()-3;i++){
		int a1 = -pointList3.GetAt(i).x + 3*pointList3.GetAt(i+1).x - 3*pointList3.GetAt(i+2).x + pointList3.GetAt(i+3).x ;
		int a2 = -pointList3.GetAt(i).y + 3*pointList3.GetAt(i+1).y - 3*pointList3.GetAt(i+2).y + pointList3.GetAt(i+3).y ;
		int b1 = 3*pointList3.GetAt(i).x - 6*pointList3.GetAt(i+1).x + 3*pointList3.GetAt(i+2).x ;
		int b2 = 3*pointList3.GetAt(i).y - 6*pointList3.GetAt(i+1).y + 3*pointList3.GetAt(i+2).y ;
		int c1 = -3*pointList3.GetAt(i).x + 3*pointList3.GetAt(i+2).x ;
		int c2 = -3*pointList3.GetAt(i).y + 3*pointList3.GetAt(i+2).y ;
		int d1 = pointList3.GetAt(i).x + 4*pointList3.GetAt(i+1).x + pointList3.GetAt(i+2).x ;
		int d2 = pointList3.GetAt(i).y + 4*pointList3.GetAt(i+1).y + pointList3.GetAt(i+2).y ;
		if(i%3==0){
			CPen pen(PS_SOLID,1,RGB(255,0,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pStart.x = d1/6;
			pStart.y = d2/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==1){
			CPen pen(PS_SOLID,1,RGB(0,255,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==2){
			CPen pen(PS_SOLID,1,RGB(0,0,255));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pEnd.x = (a1+b1+c1+d1)/6;
			pEnd.y = (a2+b2+c2+d2)/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}	
	}
	}

	pointList4.SetSize(pointList2.GetSize());
	for(int i=0;i<8;i++){
		for(int j=0;j<pointList2.GetSize();j++){
			CPoint p;
			p.x = (pointList2.GetAt(j).x-xxx) * cos(theta*pi/180) - (pointList2.GetAt(j).y-yyy) *sin(theta*pi/180) +xxx;
			p.y = (pointList2.GetAt(j).x-xxx) * sin(theta*pi/180) + (pointList2.GetAt(j).y-yyy) *cos(theta*pi/180) +yyy;
			pointList4.SetAt(j,p);
		}
		theta = theta + 45;
	CClientDC dc(this);
	for(int i=0;i<pointList4.GetSize()-3;i++){
		int a1 = -pointList4.GetAt(i).x + 3*pointList4.GetAt(i+1).x - 3*pointList4.GetAt(i+2).x + pointList4.GetAt(i+3).x ;
		int a2 = -pointList4.GetAt(i).y + 3*pointList4.GetAt(i+1).y - 3*pointList4.GetAt(i+2).y + pointList4.GetAt(i+3).y ;
		int b1 = 3*pointList4.GetAt(i).x - 6*pointList4.GetAt(i+1).x + 3*pointList4.GetAt(i+2).x ;
		int b2 = 3*pointList4.GetAt(i).y - 6*pointList4.GetAt(i+1).y + 3*pointList4.GetAt(i+2).y ;
		int c1 = -3*pointList4.GetAt(i).x + 3*pointList4.GetAt(i+2).x ;
		int c2 = -3*pointList4.GetAt(i).y + 3*pointList4.GetAt(i+2).y ;
		int d1 = pointList4.GetAt(i).x + 4*pointList4.GetAt(i+1).x + pointList4.GetAt(i+2).x ;
		int d2 = pointList4.GetAt(i).y + 4*pointList4.GetAt(i+1).y + pointList4.GetAt(i+2).y ;
		if(i%3==0){
			CPen pen(PS_SOLID,1,RGB(255,0,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pStart.x = d1/6;
			pStart.y = d2/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==1){
			CPen pen(PS_SOLID,1,RGB(0,255,0));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}
		if(i%3==2){
			CPen pen(PS_SOLID,1,RGB(0,0,255));
			dc.SelectObject(pen);
			dc.MoveTo(d1/6,d2/6);
			pEnd.x = (a1+b1+c1+d1)/6;
			pEnd.y = (a2+b2+c2+d2)/6;
			for(double x=0;x<=1;x=x+0.01){
				dc.LineTo( (a1*x*x*x+b1*x*x+c1*x+d1)/6,(a2*x*x*x+b2*x*x+c2*x+d2)/6 );
			}
		}	
	}
	}
}

void CTest0227View::Clean(void)
{
	CDC *pDC = GetDC();
    CRect rc;
    GetClientRect(&rc);
    pDC->FillSolidRect(&rc, RGB(255, 255, 255));
    ReleaseDC(pDC);
}
