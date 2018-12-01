
COMSampleps.dll: dlldata.obj COMSample_p.obj COMSample_i.obj
	link /dll /out:COMSampleps.dll /def:COMSampleps.def /entry:DllMain dlldata.obj COMSample_p.obj COMSample_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del COMSampleps.dll
	@del COMSampleps.lib
	@del COMSampleps.exp
	@del dlldata.obj
	@del COMSample_p.obj
	@del COMSample_i.obj
