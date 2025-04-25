#ifndef _IFP_WINDOWS_H
#define _IFP_WINDOWS_H

#pragma comment(lib, "Ws2_32.lib")

#ifdef __cplusplus
extern "C" {
#endif

//		--------------- Specific

#define	IF_PLF_OS			1	//windows

#if defined	CFSHARE_DLL
#define	CFS_EXPORT	__declspec(dllexport)
#elif defined	LIBCFS_EXPORTS
#define	CFS_EXPORT	__declspec(dllexport)
#else
#define	CFS_EXPORT	
#endif

#define	uint8_t		unsigned __int8
#define	uint16_t	unsigned __int16
#define	uint32_t	unsigned __int32
#define	uint64_t	unsigned __int64
#define	int8_t		__int8
#define	int16_t		__int16
#define	int32_t		__int32
#define	int64_t		__int64

#define socklen_t	INT

#define	INLINE		__inline

#define INVALID_TLS INVALID

#ifdef _M_IX86


typedef unsigned __int32	PTRUINT;
typedef __int32				PTRINT;
#define	INVALIDPTR	((void*)0xffffffff)
#define	INVPTRUINT	0xffffffff
#define IF_PTRSIZE	4
#define IF_PC_EXE_NAME		"if_portcore.exe"
#define	IF_PLF_CPU			1	//intel


#define	FMT_U64	"%I64u"
#define	FMT_I64	"%I64d"
#define	FMT_X64	"%I64X"
#define	FMT_x64	"%I64x"

#define	P_ASM_EAX	eax
#define R_ASM_ECX	ecx
#define	P_ASM_ESI	esi
#define R_ASM_EDI	edi

#elif defined  _M_X64


typedef unsigned __int64	PTRUINT;
typedef __int64				PTRINT;
#define	INVALIDPTR	((void*)0xffffffffffffffff)
#define	INVPTRUINT	0xffffffffffffffff
#define IF_PTRSIZE	8
#define IF_PC_EXE_NAME		"if_portcore64.exe"
#define	IF_PLF_CPU			1	//intel

#define	FMT_U64	"%I64u"
#define	FMT_I64	"%I64d"
#define	FMT_X64	"%I64X"
#define	FMT_x64	"%I64x"

#define	P_ASM_EAX	rax
#define R_ASM_ECX	rcx
#define	P_ASM_ESI	rsi
#define R_ASM_EDI	rdi

#else 
#error ifp_windows.h:	windows type not defined!
#endif

#define OS_EXE_EXT	".exe"
 
//		--------------- General

#define	_platform_name	"Windows"

#define thread_local __declspec(thread)

#define INVALID			0xffffffff
#define INVALID64		0xffffffffffffffff
#define	IF_WINDOWS	(IF_PTRSIZE*8)

#define IF_TRY			__try
#define IF_EXCEPT(x)	__except(x)	
#define IF_ETRY			;

#define _CDECL			__cdecl
#define _STDCALL		__stdcall
#define _THREADCALL		__stdcall

#define	IF_ENDIAN	0	//little
#define	IF_PATHDIV	'\\'
#define	IF_PATHDIV_ALT	'/'
#define	IF_PATHDIVS	"\\"

#define	FN_IGNORE_CASE

typedef __int64				i64;
typedef unsigned __int64	u64;


#include <windows.h>
#include <windowsx.h>
#include <malloc.h>



#if MAX_PATH!=260
#error		Wrong MAX_PATH length!
#endif

#define EEH		EXCEPTION_EXECUTE_HANDLER


#define	pR_CRITICAL_SECTION	CRITICAL_SECTION

#include	"pc_werr.h"

#define	pR_WAIT_OBJECT_0						WAIT_OBJECT_0
#define pR_WAIT_ABANDONED_0						WAIT_ABANDONED_0

#define	pR_WAIT_TIMEOUT							WAIT_TIMEOUT

#define	MAX_SVC_NAME		64


#ifndef CSIDL_PROFILE
#define CSIDL_LOCAL_APPDATA		0x001c
#define CSIDL_PROFILE			0x0028
#endif

//		---------------- Standard functions
#include <stdio.h>
#include <direct.h>
#include <io.h>
#include <conio.h>
#include <errno.h>
#include <malloc.h>
#include <process.h>

#define F_OK	0
#define R_OK	4
#define W_OK	2

#define	pR_access	_access
#define	pR_mkdir(path)	(CreateDirectory(path,cfsSAEO())?0:(-1))
#define pR_CreateDirectory(path) CreateDirectory(path,cfsSAEO()) 
#define pR_rmdir		_rmdir
#define setenv(name,val,ovw) SetEnvironmentVariable(name,val)
//		---------------- Cfshare functions
#include "ifp_cfs.h"

//		--------------- Windows Functions
#define	GPA														GetProcAddress
#ifndef _ICS
#define	 CFS_DEFAULT_CS_SPIN									8
#define _ICS_and_SC												InitializeCriticalSectionAndSpinCount
#define _ICS(pcs)												(void)InitializeCriticalSectionAndSpinCount(pcs,CFS_DEFAULT_CS_SPIN)
#define _DCS													DeleteCriticalSection
#define _ECS													EnterCriticalSection
#define try_ECS													TryEnterCriticalSection
#define _LCS													LeaveCriticalSection
#endif

#define	pR_GLE													GetLastError
#define	pR_GetLastError											GetLastError
#define	pR_SLE													SetLastError

#ifdef	IF_PORTCORE
#define	pR_GetTickCount											Win_GetTickCount
#define	pR_GetTickCount_										Win_GTCSimple
#else
#define	pR_GetTickCount											GetTickCount
#define	pR_GetTickCount_										GetTickCount
#endif

#define	pR_InterlockedExchange									InterlockedExchange
#define	pR_InterlockedExchangeAdd								InterlockedExchangeAdd

#define	pR_Sleep												Sleep
#define	pR_ResetEvent											ResetEvent
#define	pR_SetEvent												SetEvent
#define	pR_WaitForMultipleObjects								WaitForMultipleObjects
#define	pR_WaitForSingleObject									WaitForSingleObject
#define	pR_ZeroMemory											ZeroMemory
#define	pR_CopyMemory											pR_memcpy
#define	pR_FillMemory											FillMemory

#define	pR_CreateEvent											CreateEvent

#ifdef IF_PORTCORE
BOOL	pR_TerminateThread(HANDLE hThread,DWORD excode);
#else
#define	pR_TerminateThread										TerminateThread
#endif

#define	pR_CloseHandle											CloseHandle
#define pR_SetLocalTime											SetLocalTime
#define	pR_WideCharToMultiByte									WideCharToMultiByte
#define	pR_IsBadReadPtr											IsBadReadPtr
#define	pR_IsBadWritePtr										IsBadWritePtr
#define	pR_DeleteFile											DeleteFile
#define	pR_ProcessId											GetCurrentProcessId
#define	pR_ThreadId												GetCurrentThreadId
#define pR_GetCurrentThread										GetCurrentThread
#define	pR_GetLocalTime											GetLocalTime
#define	pR_GetSystemTime										GetSystemTime
#define	pR_SetSystemTime										SetSystemTime

BOOL cfsSetSystemTime(
	DWORD Year,
	DWORD Month,
	DWORD Day,
	DWORD Hour,
	DWORD Minute,
	DWORD Second,
	DWORD Msec
);

#ifdef	IFP_OLD
#define pR_CopyFile												CopyFile
#define pR_MoveFile(f1,f2,rep)									MoveFileEx(f1,f2,(rep?MOVEFILE_REPLACE_EXISTING:0)|MOVEFILE_COPY_ALLOWED|MOVEFILE_WRITE_THROUGH)
#else
#define pR_CopyFile												cfsCopyFile
#define pR_MoveFile												cfsMoveFile
#endif

#define pR_MoveFileWithProgress(f1,f2,rtn,rtndata,rep,through)		MoveFileWithProgress(f1,f2,rtn,rtndata,MOVEFILE_COPY_ALLOWED|(rep?MOVEFILE_REPLACE_EXISTING:0)|(through?MOVEFILE_WRITE_THROUGH:0))


#define pR_SuspendThread										SuspendThread										
#define pR_ResumeThread											ResumeThread
#define pR_GetThreadTiming                                      Win_GetThreadTiming
#define pR_GetACP												GetACP
#define pR_IsAdmin()											Win_IsAdmin(FALSE)
#define pR_QueryPerformanceFrequency							QueryPerformanceFrequency
#define pR_QueryPerformanceCounter								QueryPerformanceCounter
#define OsIsAdmin												Win_IsAdmin
#define	pR_GetHandleCount()										0
/////////////////

#ifdef	IFP_OLD
#define	SA_EO			cfsSAEO()
#define SA_MEMOBJ		SA_EO
#define SA_LOCALFILE	SA_EO
#define SA_SERVERFILE	SA_EO
#define SA_NONETOBJ		SA_EO
#define	SA_FILE			SA_EO
#else
#define	SA_EO			cfsSAEO()
#define SA_MEMOBJ		cfsSAAdm()
#define SA_LOCALFILE	NULL
#define SA_SERVERFILE	cfsSAAdm()
#define SA_NONETOBJ		cfsSALoc()
#define	SA_FILE			cfsSAFile()
#endif


#define pR_OpenFile(fname,wr,ex,ca)								pR_CreateFile(	\
			fname,\
			GENERIC_READ|((wr)?GENERIC_WRITE:0),\
			FILE_SHARE_READ|((wr)?0:FILE_SHARE_WRITE),\
			SA_FILE,\
			(ex)?OPEN_EXISTING:((ca)?CREATE_ALWAYS:OPEN_ALWAYS),\
			0,\
			NULL)

#define pR_OpenFileShared(fname,wr,ex,ca)								pR_CreateFile(	\
			fname,\
			GENERIC_READ|((wr)?GENERIC_WRITE:0),\
			FILE_SHARE_READ|FILE_SHARE_WRITE,\
			SA_FILE,\
			(ex)?OPEN_EXISTING:((ca)?CREATE_ALWAYS:OPEN_ALWAYS),\
			0,\
			NULL)

#define	pR_OpenFileNoBuf(fname,wr,ex,ca)						pR_CreateFile(	\
			fname,\
			GENERIC_READ|((wr)?GENERIC_WRITE:0),\
			FILE_SHARE_READ|((wr)?0:FILE_SHARE_WRITE),\
			SA_FILE,\
			(ex)?OPEN_EXISTING:((ca)?CREATE_ALWAYS:OPEN_ALWAYS),\
			FILE_FLAG_NO_BUFFERING,\
			NULL)

#define	pR_OpenFileSharedNoBuf(fname,wr,ex,ca)						pR_CreateFile(	\
			fname,\
			GENERIC_READ|((wr)?GENERIC_WRITE:0),\
			FILE_SHARE_READ|FILE_SHARE_WRITE,\
			SA_FILE,\
			(ex)?OPEN_EXISTING:((ca)?CREATE_ALWAYS:OPEN_ALWAYS),\
			FILE_FLAG_NO_BUFFERING,\
			NULL)

#define pR_OpenPipe(PipeName)									CreateFile(\
			PipeName,\
			GENERIC_READ|GENERIC_WRITE,\
			FILE_SHARE_READ|FILE_SHARE_WRITE,\
			NULL,OPEN_EXISTING,\
			0,\
			NULL);
#define	pR_SetThreadPriority									Win_SetThreadPriority
#define pR_SetFileEveryones(FileName)							SetFileSecurity(FileName,DACL_SECURITY_INFORMATION,cfsSDEO())
#define pR_SetFileEvrRd(FileName)								SetFileSecurity(FileName,DACL_SECURITY_INFORMATION,cfsSDAdmWr());
#define pR_ClrFileReadonly(fname)								SetFileAttributes(fname,GetFileAttributes(fname)&(~FILE_ATTRIBUTE_READONLY))
#define	pR_WriteFileSync(h,b,cb,pcbw)							WriteFile(h,b,cb,pcbw,NULL)
#define	pR_ReadFileSync(h,b,cb,pcbw)							ReadFile(h,b,cb,pcbw,NULL)
#define	pR_CloseFile											pR_CloseHandle
#define	pR_ClosePipe											pR_CloseHandle
#define	pR_GetFileSizeShort(hFile)								GetFileSize(hFile,NULL)
#define	pR_GetFileSizeLong										Win_GetFileSizeLong
#define pR_SetFilePointerLong									Win_SetFilePointerLong
#define	pR_GetFilePointerLong(hFile)							Win_SetFilePointerLong(hFile,0, FILE_CURRENT)
#define	pR_SetFilePointerShort(hFile,dist,method)				SetFilePointer(hFile,dist,NULL,method)
#define	pR_GetFilePointerShort(hFile)							SetFilePointer(hFile,0,NULL,FILE_CURRENT)
#define	pR_SetEOF												SetEndOfFile
#define	pR_FlushFileByHandle									FlushFileBuffers
#define	pR_FlushFileByName(fn)										
#define pR_RoughFileTime										Win_RoughFileTime
#define pR_EnableFpuExceptions									Win_EnableFpuExceptions
#define	pR_PreInitOSSpecific									WindowsPreInit
#define	pR_InitOSSpecific										WindowsInit
#define	pR_ReinitOSSpecific										WindowsReinit
#define pR_SetTerminationHandlerEvent							Win_SetTerminationHandlerEvent
#define	pR_GetFileChangeTime									Win_GetFileChangeTime
#define	pR_SetFileTime											SetFileTime
#define	pR_CompareFileTime										CompareFileTime
#define	pR_SystemTimeToFileTime									SystemTimeToFileTime
#define	pR_FileTimeToSystemTime									FileTimeToSystemTime
#define pR_CreateMapping(wr,size,name,hnd,offs)					Win_CreateMapping(wr,size,name,hnd,offs)
#define pR_FlushMapping(p)										Win_FlushMapping(p)
#define pR_DeleteMapping(p,size)								Win_DeleteMapping(p,size)
#define	pR_GetComputerName										Win_GetComputerName
#define pR_GetFreeSpace											Win_GetFreeSpace
#define	pR_osu_enum_users										Win_osu_enum_users
#define	pR_osu_logon_user										Win_osu_logon_user
#define	pR_NormalizeUserName									Win_NormalizeUserName
#define pR_MapGenericMask										MapGenericMask
#define	pR_GetFullUserName										Win_GetFullUserName
#define	OsGetMACAddresses										Win_GetMACAddresses

INT		pR_MultiByteToWideChar(
					UINT CodePage,         // code page
					DWORD dwFlags,         // character-type options
					LPCSTR lpMultiByteStr, // string to map
					INT cbMultiByte,       // number of bytes in string
					LPWSTR lpWideCharStr,  // wide-character buffer
					INT cchWideChar        // size of buffer
);
FILE *pR_fopen( const char *filename, const char *mode );

#define pR_FOPEN_AB	"ab"
#define pR_FOPEN_WB	"wb"

#define	pR_FILE_LF	"\n"

#define pR_LIB_ANYDIR		((LPSTR)(PTRUINT)0)
#define pR_LIB_SYSTEM		((LPSTR)(PTRUINT)1)
#define pR_LIB_LOCAL		((LPSTR)(PTRUINT)2)

PVOID	pR_LoadLibSecure(LPSTR lib_dir,LPSTR lib_name);


#define pR_CreateDirNotificationEvent(name,b_sub,b_full)			\
		FindFirstChangeNotification(name,b_sub,	\
FILE_NOTIFY_CHANGE_LAST_WRITE|(b_full?(FILE_NOTIFY_CHANGE_FILE_NAME|FILE_NOTIFY_CHANGE_SIZE):0))
#define	pR_CloseDirNotificationEvent							FindCloseChangeNotification
#define	pR_DirNotificationNext									FindNextChangeNotification


#define	pR_FPClassGood											Win_FPClassGood

#define pR_OemToCharBuff										cfsOemToCharBuff
#define pR_CharToOemBuff										cfsCharToOemBuff

#define pR_OemToChar(s,d)										cfsOemToCharBuff(s,d,pR_strlen(s)+1)
#define pR_CharToOem(s,d)										cfsCharToOemBuff(s,d,pR_strlen(s)+1)

#define	pR_IsCharAlpha											IsCharAlpha

#define pR_GetBuildDate											Win_BuildDate
#define pR_GetBuildUT											Win_BuildUT

#define pR_GetUptime											Win_GetUptime

#define	pR_SetSvcOpt(opt,val)									

#define	pR_GetMainResource										Win_GetMainResource
#define pR_GetUserPath											Win_GetUserPath


#define	pR_LoadLibrary											LoadLibrary
#define	pR_FreeLibrary											FreeLibrary
#define	pR_GetProcAddress										GetProcAddress

#define	pR_GetPid												GetCurrentProcessId
#define pR_CheckProcParent										Win_CheckProcParent

/////////////////
#define	os_uxt_attach											Win_uxt_attach
#define	os_uxt_detach											Win_uxt_detach
#define	os_uxt_tzi												Win_uxt_tzi
#define	os_uxt_system_ut										Win_uxt_system_ut
#define os_uxt_bias												Win_uxt_get_bias
#define os_uxt_dls_bias											Win_uxt_get_dls_bias
#define	os_ux_tz_change											Win_uxt_tz_change
#define	os_ux_tz_by_name										Win_uxt_tzi_byname
#define	os_enum_time_zones()									Win_EnumTimeZones(NULL)



#define pR_AllowBindLow()										TRUE
#define	pR_ForkDaemon()											(-1)
#define	pR_KillDaemon(s)										TRUE			
#define	pR_GetExeName											Win_GetExeName
#define pR_kbhit												_kbhit
#define pR_getch												getch
#define pR_getche												getche

#define	SHUT_RDWR	SD_BOTH 

#define IF_RU_CONV(x)											x
#define	pR_ConsoleOutConv(s,d,cb_d)								pR_CharToOemBuff(s,d,cb_d)

//		---------------- INI functions
#define INI_SYSTEM	1
#include "ifp_ini.h"

#define	pR_ODS(x)		OutputDebugString(x)

#ifdef	IF_PORTCORE
#ifndef IF_WINDOWS
#if		IF_PTRSIZE!=4
#undef pR_ODS
#define	pR_ODS(x)		d_printf("ODS: %s",x)
#endif
#endif
#endif

#define pR_MulDiv	MulDiv

//		---------------- Windows specific code
BOOL	WindowsPreInit();
BOOL	WindowsInit(LPSTR ext_arg);
VOID	WindowsReinit();
#ifdef	CFS_PTHS_DEFINED
VOID	Win_GetThreadTiming(CFS_PTHS* pths,LPSTR times, DWORD cb_times);
#endif
VOID	Win_EnableFpuExceptions();
VOID	Win_SetTerminationHandlerEvent(HANDLE hEvt);
BOOL	Win_GetFileChangeTime(LPSTR fn,FILETIME* pft);

VOID	Win_uxt_attach();
VOID	Win_uxt_detach();
VOID	Win_uxt_tzi(TIME_ZONE_INFORMATION* tzi);
DWORD	Win_uxt_system_ut(PWORD pms);
INT		Win_uxt_get_bias(TIME_ZONE_INFORMATION* ptzi,BOOL gw,DWORD ut);
INT		Win_uxt_get_dls_bias(TIME_ZONE_INFORMATION* ptzi,BOOL gw,DWORD ut);
DWORD	Win_uxt_tz_change();
BOOL	Win_uxt_tzi_byname(LPSTR tzname,TIME_ZONE_INFORMATION* tzip,PBOOL pGw);
BOOL	Win_IsAdmin(BOOL fThread);
LPSTR	Win_EnumTimeZones(LPSTR list);
BOOL	Win_GetFreeSpace(LPSTR path,u64* pfsp,u64* ptot);

//		-----------------
BOOL	Win_FPClassGood(float* f);

BOOL	Win_InitTSC();
u64		Win_GetTSC();
u64		Win_TSCF();
DWORD	Win_GetTickCount();
DWORD	Win_GTCSimple();
LPSTR	Win_GetExeName();


PVOID	Win_CreateMapping(BOOL	wr,	DWORD	size,LPSTR	name,HANDLE	hnd,DWORD offs);
VOID	Win_FlushMapping(PVOID	p);
VOID	Win_DeleteMapping(PVOID	p,DWORD size);

#ifdef	IF_PORTCORE
i64		Win_InterlockedRead64(volatile i64 *target);
i64		Win_InterlockedExchange64(volatile i64 *target, i64 value);
i64		Win_InterlockedExchangeAdd64(i64 *target,i64 addend);
#else
#define pR_IsValidSid IsValidSid
#define pR_EqualSid EqualSid
#endif

#define	cfsIsForked()	FALSE

u64		Win_SetFilePointerLong(HANDLE hFile,i64 pos, DWORD method);
BOOL	Win_GetFileSizeLong(HANDLE hFile,u64* ps);
VOID	Win_RoughFileTime(FILETIME* pft);

BOOL	Win_CheckDaemonRunning(LPSTR s);
BOOL	Win_InstallService(LPSTR svc_name, LPSTR svc_descr,LPSTR path,LPSTR base_path);
BOOL	Win_RemoveService(LPSTR svc_name,LPSTR path);
BOOL	Win_CommandService(LPSTR svc_name,INT	cmd);


LPSTR	Win_BuildDate();
DWORD	Win_BuildUT();
BOOL	Win_GetComputerName(LPSTR szComputerName,DWORD dwComputerName);
BOOL	Win_GetUptime(u64* p_uptime);

LPSTR	Win_osu_enum_users(BOOL b_comment);
BOOL	Win_osu_logon_user(LPSTR user, LPSTR pw, PBOOL pAdmin);
VOID	Win_NormalizeUserName(LPSTR uname,LPSTR osun,DWORD cb_osun);
VOID	Win_GetUserPath(LPSTR path,DWORD cb_path);

typedef VOID (*pR_SERVICE_FUNCTION)();
BOOL	Win_ServiceRun(pR_SERVICE_FUNCTION svc_fn,HANDLE hStop);
BOOL	Win_IsService();

PBYTE	Win_GetMainResource(PDWORD pdw);
BOOL	Win_GetDwordResource(HINSTANCE hI,LPSTR lpName,LPSTR lpType,PDWORD pDwRes);


VOID	Win_SetThreadPriority(int pri);

BOOL	Win_GetFullUserName(LPSTR UserName,LPSTR FullName,DWORD cbFullName);
DWORD	Win_GetMACAddresses(PBYTE p_macs,DWORD c_macs);
BOOL	Win_CheckProcParent(DWORD pid,DWORD check_ppid);

char * strtok_r (char *s, const char *delim, char **save_ptr);

HANDLE _CDECL pR_CreateFile(
    LPCSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
);
void	pR_DeinitOSSpecific();

PBYTE	OsGetResourcePtr(HINSTANCE hI,LPSTR lpName,LPSTR lpType,PDWORD p_cb);
BOOL	OsSetFileDefaultSecurity(LPSTR fname);
BOOL	OsSetFileAdmSysSecurity(LPSTR fname);

BOOL	OsGetTokenUser(HANDLE hToken,LPSTR userbuf,DWORD userbuflen);
//		-----------------

VOID _CDECL cfsOemToCharBuff( LPSTR lpszSrc,  LPSTR lpszDst,   DWORD cchDstLength );

VOID _CDECL cfsCharToOemBuff( LPSTR lpszSrc,  LPSTR lpszDst,   DWORD cchDstLength );

#define	cfsInitTSC				Win_InitTSC
#define cfsGetTSC				Win_GetTSC
#define cfsTSCF					Win_TSCF
#define cfsIsAdmin				Win_IsAdmin
#define cfsIsRoot(x)				FALSE

#ifndef USE_CFSHARE_DLL
#define cfsIsService			Win_IsService 
#endif

#ifdef	IF_PORTCORE
#define cfsInterlockedRead64		Win_InterlockedRead64
#define cfsInterlockedExchange64	Win_InterlockedExchange64
#define cfsInterlockedExchangeAdd64 Win_InterlockedExchangeAdd64
#endif

#define cfsCheckDaemonRunning	Win_CheckDaemonRunning	
#define	cfsSrvInstallService	Win_InstallService
#define	cfsSrvCommandService	Win_CommandService
#define	cfsSrvRemoveService		Win_RemoveService
#define	cfsSrvSvcScript(svcn,descr,exep,bpath)		FALSE

#define	cfsGetSysLimitsStr()	NULL

#define	pR_AltBaseRoot		NULL
///		-----------------

#ifndef _WIN64
#define OS_ENDIAN_SWAP
#define pR_swap2ip(p)	{	\
	register PVOID __tmp_p;								\
	__tmp_p=(PVOID)(p);							\
	__asm 	mov P_ASM_EAX,__tmp_p				\
	__asm 	mov cx,[P_ASM_EAX]					\
	__asm 	xchg	ch,cl						\
	__asm 	mov [P_ASM_EAX],cx					\
}

#define pR_swap4ip(p)	{	\
	register PVOID __tmp_p;								\
	__tmp_p=(PVOID)(p);							\
	__asm 	mov P_ASM_EAX,__tmp_p				\
	__asm 	mov ecx,[P_ASM_EAX]					\
	__asm 	bswap ecx							\
	__asm 	mov [P_ASM_EAX],ecx					\
}


#define pR_swap8ip(p)	{	\
	register PVOID __tmp_p;								\
	__tmp_p=(PVOID)(p);							\
	__asm 	mov P_ASM_EAX,__tmp_p				\
	__asm 	mov cl,[P_ASM_EAX+0]				\
	__asm 	xchg cl,[P_ASM_EAX+7]				\
	__asm 	mov [P_ASM_EAX+0],cl				\
\
	__asm 	mov cl,[P_ASM_EAX+1]				\
	__asm 	xchg cl,[P_ASM_EAX+6]				\
	__asm 	mov [P_ASM_EAX+1],cl				\
\
	__asm 	mov cl,[P_ASM_EAX+2]				\
	__asm 	xchg cl,[P_ASM_EAX+5]				\
	__asm 	mov [P_ASM_EAX+2],cl				\
\
	__asm 	mov cl,[P_ASM_EAX+3]				\
	__asm 	xchg cl,[P_ASM_EAX+4]				\
	__asm 	mov [P_ASM_EAX+3],cl				\
}
#endif

#ifdef __cplusplus
}
#endif
#endif //_IFP_WINDOWS_H
