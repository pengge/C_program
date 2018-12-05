// ShieldKeyBordSample.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <malloc.h>
#include "ShieldKeyBordSample.h"

// 全局变量
HINSTANCE     m_hInstance = NULL;				// 模块实例句柄
HHOOK         m_hHook = NULL;					// 钩子句柄
LPDWORD       m_lpdwVirtualKey = NULL;			// Keycode 数组的指针
LPDWORD       m_lpdwContentKey = NULL;			// 组合键 数组的指针
int           m_nLength = 0;					// Keycode 数组的长度

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{	
    m_hInstance = (HINSTANCE)hModule;	// 保存模块实例句柄
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			delete m_lpdwVirtualKey;
			delete m_lpdwContentKey;
			if (m_hHook != NULL) UnhookWindowsHookEx(m_hHook);
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


// This is an example of an exported variable
SHIELDKEYBORDSAMPLE_API int nShieldKeyBordSample=0;

// This is an example of an exported function.
SHIELDKEYBORDSAMPLE_API int fnShieldKeyBordSample(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see ShieldKeyBordSample.h for the class definition
CShieldKeyBordSample::CShieldKeyBordSample()
{ 
	return; 
}

// 底层键盘钩子回调函数
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{    
     if (nCode == HC_ACTION)	// 禁用键盘的某个按键
     {
         KBDLLHOOKSTRUCT* pHookStruct = (KBDLLHOOKSTRUCT*)lParam;	// 取出钩子结构
		 LPDWORD tmpVirKey = m_lpdwVirtualKey;		// 取出要屏蔽的键的列表指针
         for (int i = 0; i < m_nLength; i++)
         {			 
			 if (*m_lpdwContentKey++ == 1)
			 {
				 DWORD dwAltKey = 32;
				 if ((pHookStruct->vkCode == *tmpVirKey++)
					 && (pHookStruct->flags == dwAltKey)) return TRUE;
			 }
			 if (pHookStruct->vkCode == *tmpVirKey++) return TRUE;
         }
     }
     return CallNextHookEx(m_hHook, nCode, wParam, lParam);	// 如果不是要屏蔽的按键则传给系统中的下一个钩子
}

// 启动屏蔽
SHIELDKEYBORDSAMPLE_API bool StartShieldKey(LPDWORD lpdwVirtualKey, LPDWORD lpdwContentKey, int nLength)
{
     if (m_hHook != NULL) return StopShieldKey();
     m_lpdwVirtualKey = (LPDWORD)malloc(sizeof(DWORD) * nLength);
	 m_lpdwContentKey = (LPDWORD)malloc(sizeof(DWORD) * nLength);
     LPDWORD tmpVirKey = m_lpdwVirtualKey;// 要屏蔽的底层键盘;
	 LPDWORD tmpConKey = m_lpdwContentKey;// 要屏蔽的底层键盘组合键;
     for (int i = 0; i < nLength; i++)
     {
         *tmpVirKey++ = *lpdwVirtualKey++;
		 *tmpConKey++ = *lpdwContentKey++;
     }

	 m_nLength = nLength;     
     // 安装底层键盘钩子
     m_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, m_hInstance, NULL);
     if (m_hHook == NULL) return FALSE;
     return TRUE;
}

// 停止屏蔽
SHIELDKEYBORDSAMPLE_API bool StopShieldKey()
{
     if (UnhookWindowsHookEx(m_hHook) == 0) return FALSE;
     m_hHook = NULL;
     return TRUE;
}


