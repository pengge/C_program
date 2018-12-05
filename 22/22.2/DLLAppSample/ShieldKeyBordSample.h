
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SHIELDKEYBORDSAMPLE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SHIELDKEYBORDSAMPLE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef SHIELDKEYBORDSAMPLE_EXPORTS
#define SHIELDKEYBORDSAMPLE_API __declspec(dllexport)
#else
#define SHIELDKEYBORDSAMPLE_API __declspec(dllimport)
#endif

// This class is exported from the ShieldKeyBordSample.dll
class SHIELDKEYBORDSAMPLE_API CShieldKeyBordSample {
public:
	CShieldKeyBordSample(void);
	// TODO: add your methods here.
};

extern SHIELDKEYBORDSAMPLE_API int nShieldKeyBordSample;

SHIELDKEYBORDSAMPLE_API int fnShieldKeyBordSample(void);

SHIELDKEYBORDSAMPLE_API bool StartShieldKey(LPDWORD lpdwVirtualKey, LPDWORD lpdwContentKey, int nLength);
SHIELDKEYBORDSAMPLE_API bool StopShieldKey();


