#include "StdAfx.h"
#include "MouseHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma data_seg("mydata")

HHOOK glhHook = NULL;
HINSTANCE glhInstance = NULL;

#pragma data_seg()


CMouseHook::CMouseHook()
{
}

CMouseHook::~CMouseHook()
{
	stopHook();
}

LRESULT CALLBACK CMouseHook::MouseProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	LPMSLLHOOKSTRUCT pMouseHook = (MSLLHOOKSTRUCT*)lParam;

	if (nCode >= 0)
	{
		if (wParam==WM_XBUTTONDOWN && HIWORD(pMouseHook->mouseData)==XBUTTON1)
		{
			INPUT keyEvent = {0};
			keyEvent.type = INPUT_KEYBOARD;
			keyEvent.ki.wVk = VK_E;
			keyEvent.ki.wScan = MapVirtualKey(VK_E, 0);

			SendInput(1, &keyEvent, sizeof(keyEvent));
			return TRUE;
		}

		if (wParam == WM_XBUTTONUP && HIWORD(pMouseHook->mouseData)==XBUTTON1)
		{
			INPUT keyEvent = {0};
			keyEvent.type = INPUT_KEYBOARD;
			keyEvent.ki.wVk = VK_E;
			keyEvent.ki.wScan = MapVirtualKey(VK_E, 0);

			keyEvent.ki.dwFlags = KEYEVENTF_KEYUP;//Ä¬ÈÏkeyEvent.ki.dwFlags  = 0 £¬¼´ KEYEVENTF_KEYDOWN
			SendInput(1, &keyEvent, sizeof(keyEvent));
			return TRUE;
		}

		if (wParam == WM_XBUTTONDOWN && HIWORD(pMouseHook->mouseData)==XBUTTON2)
		{
			INPUT keyEvent = {0};
			keyEvent.type = INPUT_KEYBOARD;
			keyEvent.ki.wVk = VK_Q;
			keyEvent.ki.wScan = MapVirtualKey(VK_Q, 0);

			SendInput(1, &keyEvent, sizeof(keyEvent));
			return TRUE;
		}

		if (wParam == WM_XBUTTONUP && HIWORD(pMouseHook->mouseData)==XBUTTON2)
		{
			INPUT keyEvent = {0};
			keyEvent.type = INPUT_KEYBOARD;
			keyEvent.ki.wVk = VK_Q;
			keyEvent.ki.wScan = MapVirtualKey(VK_Q, 0);

			keyEvent.ki.dwFlags = KEYEVENTF_KEYUP;//Ä¬ÈÏkeyEvent.ki.dwFlags  = 0 £¬¼´ KEYEVENTF_KEYDOWN
			SendInput(1, &keyEvent, sizeof(keyEvent));
			return TRUE;
		}
	}

	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}

BOOL CMouseHook::startHook()
{
	BOOL bResult = FALSE; 

	glhHook = SetWindowsHookEx(WH_MOUSE_LL, CMouseHook::MouseProc, glhInstance, 0); 

	if(glhHook != NULL) 
		bResult = TRUE; 

	return bResult; 
}

BOOL CMouseHook::stopHook()
{
	if (glhHook == NULL)
	{
		MessageBox(NULL, _T("NULL HOOK"), _T("glhHook"), MB_OK);
	}

	BOOL bResult = FALSE; 

	bResult = UnhookWindowsHookEx(glhHook); 

	if(bResult) 
	{ 
		MessageBox(NULL, _T("UnhookWindowsHookEx Success"), _T("glhHook"), MB_OK);
		glhHook = NULL;
	}

	return bResult;
}