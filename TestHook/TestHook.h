// TestHook.h : TestHook DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestHookApp
// �йش���ʵ�ֵ���Ϣ������� TestHook.cpp
//

class CTestHookApp : public CWinApp
{
public:
	CTestHookApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
