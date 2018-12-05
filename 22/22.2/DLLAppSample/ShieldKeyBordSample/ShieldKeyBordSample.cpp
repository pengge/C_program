// ShieldKeyBordSample.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <malloc.h>
#include "ShieldKeyBordSample.h"

// ȫ�ֱ���
HINSTANCE     m_hInstance = NULL;				// ģ��ʵ�����
HHOOK         m_hHook = NULL;					// ���Ӿ��
LPDWORD       m_lpdwVirtualKey = NULL;			// Keycode �����ָ��
LPDWORD       m_lpdwContentKey = NULL;			// ��ϼ� �����ָ��
int           m_nLength = 0;					// Keycode ����ĳ���

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{	
    m_hInstance = (HINSTANCE)hModule;	// ����ģ��ʵ�����
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

// �ײ���̹��ӻص�����
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{    
     if (nCode == HC_ACTION)	// ���ü��̵�ĳ������
     {
         KBDLLHOOKSTRUCT* pHookStruct = (KBDLLHOOKSTRUCT*)lParam;	// ȡ�����ӽṹ
		 LPDWORD tmpVirKey = m_lpdwVirtualKey;		// ȡ��Ҫ���εļ����б�ָ��
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
     return CallNextHookEx(m_hHook, nCode, wParam, lParam);	// �������Ҫ���εİ����򴫸�ϵͳ�е���һ������
}

// ��������
SHIELDKEYBORDSAMPLE_API bool StartShieldKey(LPDWORD lpdwVirtualKey, LPDWORD lpdwContentKey, int nLength)
{
     if (m_hHook != NULL) return StopShieldKey();
     m_lpdwVirtualKey = (LPDWORD)malloc(sizeof(DWORD) * nLength);
	 m_lpdwContentKey = (LPDWORD)malloc(sizeof(DWORD) * nLength);
     LPDWORD tmpVirKey = m_lpdwVirtualKey;// Ҫ���εĵײ����;
	 LPDWORD tmpConKey = m_lpdwContentKey;// Ҫ���εĵײ������ϼ�;
     for (int i = 0; i < nLength; i++)
     {
         *tmpVirKey++ = *lpdwVirtualKey++;
		 *tmpConKey++ = *lpdwContentKey++;
     }

	 m_nLength = nLength;     
     // ��װ�ײ���̹���
     m_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, m_hInstance, NULL);
     if (m_hHook == NULL) return FALSE;
     return TRUE;
}

// ֹͣ����
SHIELDKEYBORDSAMPLE_API bool StopShieldKey()
{
     if (UnhookWindowsHookEx(m_hHook) == 0) return FALSE;
     m_hHook = NULL;
     return TRUE;
}


