#ifndef	IF_PORTABLE_H
#define IF_PORTABLE_H	1

#define	_calltype_ _STDCALL


#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

//-----------------
#define	IF_PC_VER_MAJ	3
#define IF_PC_VER_MIN	0
#define IF_PC_VER	((IF_PC_VER_MAJ<<16)|IF_PC_VER_MIN)

#ifdef	IF_PORTCORE


#ifndef IF_PORTABLE
#define IF_PORTABLE
#endif

extern char*	_product_name;
extern char*	_prod_name_short;
extern char*	_base_subdir_name;
extern unsigned int _trademark;

#endif	//IF_PORTCORE

//--------------------------------------

#ifdef	IF_PORTABLE	//should be definded for particular os support



////////////////	WIN32
#ifdef	_WIN32
#ifndef _WIN64
#include "portable/ifp_windows.h"
#define IF_ARCH		1
#endif
#endif

//--------------------------------------

////////////////	WIN64
#ifdef _WIN64
#include "portable/ifp_windows.h"
#define IF_ARCH		1
#endif		//		WIN64

//--------------------------------------

////////////////	LINUX
#ifdef __gnu_linux__
#include "portable/ifp_linux.h"
#define IF_ARCH		1
#endif		//		LINUX
//--------------------------------------

////////////////	MAC OS
#ifdef __APPLE__
#ifdef __MACH__
#include "portable/ifp_darwin.h"
#define IF_ARCH		1
#endif
#endif

#define IF_PLATF		((IF_PLF_OS*100)+(IF_PLF_CPU*10)+(IF_PTRSIZE/4))

//---------------------------
#endif	//IF_PORTABLE
//-----------------

#ifndef	IF_ARCH
////////////////	DEFAULT ARCH
#include "portable/ifp_default.h"
#endif	// IF_ARCH



///////////////////			ENDIAN

WORD pR_swap2(WORD x);

DWORD pR_swap3( DWORD dw);

DWORD pR_swap4(DWORD x);

u64 pR_swap8(u64 x);

#if	IF_ENDIAN==0	//little

#define pR_b_endian2(x) pR_swap2(x)
#define pR_b_endian4(x) pR_swap4(x)
#define pR_b_endian8(x) pR_swap8(x)

#define pR_l_endian2(x) ((WORD)(x))
#define pR_l_endian4(x) ((DWORD)(x))
#define pR_l_endian8(x) ((u64)(x))




#else				//big

#define pR_l_endian2(x) pR_swap2(x)
#define pR_l_endian4(x) pR_swap4(x)
#define pR_l_endian8(x) pR_swap8(x)

#define pR_b_endian2(x) ((WORD)(x))
#define pR_b_endian4(x) ((DWORD)(x))
#define pR_b_endian8(x) ((u64)(x))


#endif

#define pR_b_endian2p(x) pR_b_endian2(*(unsigned short*)(x))
#define pR_b_endian4p(x) pR_b_endian4(*(unsigned long*)(x))
#define pR_b_endian8p(x) pR_b_endian8(*(u64*)(x))

#define pR_l_endian2p(x) pR_l_endian2(*(unsigned short*)(x))
#define pR_l_endian4p(x) pR_l_endian4(*(unsigned long*)(x))
#define pR_l_endian8p(x) pR_l_endian8(*(u64*)(x))

// -------------------------------
#ifndef OS_ENDIAN_SWAP

//in place

#define pR_swap2ip(p)	{	\
	register	BYTE *__tmp_p,__tmp_b;			\
	__tmp_p=(PBYTE)(PVOID)(p);					\
	__tmp_b=__tmp_p[0];__tmp_p[0]=__tmp_p[1];__tmp_p[1]=__tmp_b;	}

#define pR_swap4ip(p)	{	\
	register	BYTE *__tmp_p,__tmp_b;			\
	__tmp_p=(PBYTE)(PVOID)(p);					\
	__tmp_b=__tmp_p[0];__tmp_p[0]=__tmp_p[3];__tmp_p[3]=__tmp_b;		\
	__tmp_b=__tmp_p[1];__tmp_p[1]=__tmp_p[2];__tmp_p[2]=__tmp_b;	}

#define pR_swap8ip(p)	{	\
	register	BYTE *__tmp_p,__tmp_b;			\
	__tmp_p=(PBYTE)(PVOID)(p);					\
	__tmp_b=__tmp_p[0];__tmp_p[0]=__tmp_p[7];__tmp_p[7]=__tmp_b;		\
	__tmp_b=__tmp_p[1];__tmp_p[1]=__tmp_p[6];__tmp_p[6]=__tmp_b;		\
	__tmp_b=__tmp_p[2];__tmp_p[2]=__tmp_p[5];__tmp_p[5]=__tmp_b;		\
	__tmp_b=__tmp_p[3];__tmp_p[3]=__tmp_p[4];__tmp_p[4]=__tmp_b;	}


#endif //OS_ENDIAN_SWAP

// conditional
#define pR_swap2m(endi_mis,p)	if(endi_mis)pR_swap2ip(p)
#define pR_swap4m(endi_mis,p)	if(endi_mis)pR_swap4ip(p)
#define pR_swap8m(endi_mis,p)	if(endi_mis)pR_swap8ip(p)

#define pR_b_endian2ip(p) pR_swap2m(!IF_ENDIAN,p)
#define pR_b_endian4ip(p) pR_swap4m(!IF_ENDIAN,p)
#define pR_b_endian8ip(p) pR_swap8m(!IF_ENDIAN,p)

#define pR_l_endian2ip(p) pR_swap2m(IF_ENDIAN,p)
#define pR_l_endian4ip(p) pR_swap4m(IF_ENDIAN,p)
#define pR_l_endian8ip(p) pR_swap8m(IF_ENDIAN,p)

// -------------------------------

float	pR_TakeFloat(BOOL end_mis,PVOID p);
double	pR_TakeDouble(BOOL end_mis,PVOID p);
void	pR_PutFloat(BOOL end_mis,PVOID p, float f);
void	pR_PutDouble(BOOL end_mis,PVOID p,double dbl);


///////////////////			POINTERSIZE


//float	pR_TakeFloatFun(PVOID p);
//double	pR_TakeDoubleFun(PVOID p);

#if IF_PTRSIZE==4

#define pR_allocptrid(ptr)	((DWORD)(ptr))
#define pR_freeptrid(ptrid)
#define pR_ptrid(id)		((PVOID)(id))

#define	pR_InterlockedExchangePtruint								pR_InterlockedExchange
#define	pR_InterlockedExchangeAddPtruint							pR_InterlockedExchangeAdd
#define	pR_InterlockedExchangePtr(where,what)						((PVOID)pR_InterlockedExchange((PDWORD)(where),(DWORD)(what)))
#define	pR_InterlockedGetPtr(where)									((PVOID)pR_InterlockedExchangeAdd((PDWORD)(where),0))

#elif IF_PTRSIZE==8

#define pR_allocptrid(ptr)	cfs_allocptrid(ptr)
#define pR_freeptrid(ptrid)	cfs_freeptrid(ptrid)
#define pR_ptrid(ptrid)		cfs_ptrid(ptrid)

#define	pR_InterlockedExchangePtruint								cfsInterlockedExchange64
#define	pR_InterlockedExchangeAddPtruint							cfsInterlockedExchangeAdd64
#define pR_InterlockedExchangePtr(where,what)						((PVOID)cfsInterlockedExchange64((i64*)(where),(i64)(what)))
#define	pR_InterlockedGetPtr(where)									((PVOID)cfsInterlockedExchangeAdd64((i64*)(where),0))

#else

#error	PTRID - not implemented!

#endif		//IF_PTRSIZE



#ifdef IF_PORTCORE
void *pR_malloc( size_t size );
void *pR_calloc( size_t num, size_t size );
void *pR_realloc( void *memblock, size_t size );
void pR_free( void *memblock);
DWORD pR_msize( void *memblock);
#else
#define pR_malloc	malloc
#define pR_calloc	calloc
#define pR_realloc	realloc
#define pR_free		free
#define pR_msize	_msize
#endif

#define pR_alloca	alloca

#ifdef IF_WINDOWS
#if IF_PTRSIZE>=8
#undef pR_alloca
#define pR_alloca _malloca
#endif
#endif

//-------------------------------
#ifdef __cplusplus
}
#endif

#endif	//IF_PORTABLE_H

