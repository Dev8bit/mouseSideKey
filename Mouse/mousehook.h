#pragma once
#include "afx.h"

class AFX_EXT_CLASS CMouseHook :
	public CObject
{
public:
	CMouseHook(void);
public:
	~CMouseHook(void);
public:
	BOOL startHook();
	BOOL stopHook();
	static LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam);
};
