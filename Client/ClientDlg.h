// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_)
#define AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
#include "ClientSock.h"

//�������ݰ����ͣ��ı���ͼ��
enum PackageType  {ptText, ptImage};



BYTE _clip255( LONG v );
void YUY2_RGB( BYTE *YUY2buff, BYTE *RGBbuff, DWORD dwSize );
//����Ӧ�ò����ݰ��ṹ
class  CPackage
{
public:
	PackageType m_Type;
	DWORD		m_dwSize;	//���ݱ���С
	DWORD		m_dwContent;//���ݰ�Ӧ�������ݴ�С
	DWORD		m_dwData;	//m_Data�Ĵ�С
	BYTE		m_Data[];	//���ݻ�����
};



class CClientDlg : public CDialog
{
// Construction
public:
	void HandleRecData(CPackage* pPackage);
	BOOL InitSocket();
	void ReceiveData();
	CClientDlg(CWnd* pParent = NULL);	//standard constructor
	
	CClientSock m_ClientSock;
	HGLOBAL		m_hGlobal;				//ȫ�ֶѾ��
	CPackage*	m_pPackage;
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CStatic	m_Image;
	CRichEditCtrl	m_InfoList;
	CEdit	m_SendContent;
	CEdit	m_ServerIP;
	CEdit	m_Port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_)
