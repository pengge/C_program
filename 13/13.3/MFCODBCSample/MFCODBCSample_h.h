

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat May 04 18:20:56 2013
 */
/* Compiler settings for MFCODBCSample.odl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MFCODBCSample_h_h__
#define __MFCODBCSample_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMFCODBCSample_FWD_DEFINED__
#define __IMFCODBCSample_FWD_DEFINED__
typedef interface IMFCODBCSample IMFCODBCSample;
#endif 	/* __IMFCODBCSample_FWD_DEFINED__ */


#ifndef __Document_FWD_DEFINED__
#define __Document_FWD_DEFINED__

#ifdef __cplusplus
typedef class Document Document;
#else
typedef struct Document Document;
#endif /* __cplusplus */

#endif 	/* __Document_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MFCODBCSample_LIBRARY_DEFINED__
#define __MFCODBCSample_LIBRARY_DEFINED__

/* library MFCODBCSample */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_MFCODBCSample,0x91D6CBB4,0x1B63,0x4240,0xB7,0x26,0x1B,0x44,0x7B,0x2D,0xD6,0x1F);

#ifndef __IMFCODBCSample_DISPINTERFACE_DEFINED__
#define __IMFCODBCSample_DISPINTERFACE_DEFINED__

/* dispinterface IMFCODBCSample */
/* [uuid] */ 


DEFINE_GUID(DIID_IMFCODBCSample,0x6E0CFE89,0x9B0F,0x4015,0x92,0x41,0x64,0xE0,0xAD,0x96,0xF2,0x15);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6E0CFE89-9B0F-4015-9241-64E0AD96F215")
    IMFCODBCSample : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMFCODBCSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFCODBCSample * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFCODBCSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFCODBCSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMFCODBCSample * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMFCODBCSample * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMFCODBCSample * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMFCODBCSample * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMFCODBCSampleVtbl;

    interface IMFCODBCSample
    {
        CONST_VTBL struct IMFCODBCSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFCODBCSample_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFCODBCSample_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFCODBCSample_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFCODBCSample_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMFCODBCSample_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMFCODBCSample_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMFCODBCSample_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMFCODBCSample_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_Document,0x3EA49C1F,0x4228,0x4711,0x83,0x11,0x00,0xAC,0x9C,0xF0,0x3F,0x1F);

#ifdef __cplusplus

class DECLSPEC_UUID("3EA49C1F-4228-4711-8311-00AC9CF03F1F")
Document;
#endif
#endif /* __MFCODBCSample_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


