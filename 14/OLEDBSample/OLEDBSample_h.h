

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat May 04 19:50:29 2013
 */
/* Compiler settings for OLEDBSample.odl:
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


#ifndef __OLEDBSample_h_h__
#define __OLEDBSample_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOLEDBSample_FWD_DEFINED__
#define __IOLEDBSample_FWD_DEFINED__
typedef interface IOLEDBSample IOLEDBSample;
#endif 	/* __IOLEDBSample_FWD_DEFINED__ */


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



#ifndef __OLEDBSample_LIBRARY_DEFINED__
#define __OLEDBSample_LIBRARY_DEFINED__

/* library OLEDBSample */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_OLEDBSample,0x9F9EE617,0x13F9,0x4769,0xAC,0x9D,0xD0,0xE6,0x10,0x90,0x38,0x09);

#ifndef __IOLEDBSample_DISPINTERFACE_DEFINED__
#define __IOLEDBSample_DISPINTERFACE_DEFINED__

/* dispinterface IOLEDBSample */
/* [uuid] */ 


DEFINE_GUID(DIID_IOLEDBSample,0xDB73D1EA,0x0D88,0x4E33,0xBD,0xDB,0xC3,0x98,0xFF,0xBD,0xA0,0x85);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DB73D1EA-0D88-4E33-BDDB-C398FFBDA085")
    IOLEDBSample : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IOLEDBSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOLEDBSample * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOLEDBSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOLEDBSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOLEDBSample * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOLEDBSample * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOLEDBSample * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOLEDBSample * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IOLEDBSampleVtbl;

    interface IOLEDBSample
    {
        CONST_VTBL struct IOLEDBSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOLEDBSample_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOLEDBSample_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOLEDBSample_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOLEDBSample_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOLEDBSample_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOLEDBSample_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOLEDBSample_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IOLEDBSample_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_Document,0xFB526224,0x2A91,0x42BC,0xBC,0xCD,0xF5,0x74,0xDD,0x92,0x6D,0x4C);

#ifdef __cplusplus

class DECLSPEC_UUID("FB526224-2A91-42BC-BCCD-F574DD926D4C")
Document;
#endif
#endif /* __OLEDBSample_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


