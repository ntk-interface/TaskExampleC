//		--------------- General
#ifndef IFP_DARWIN_H
#define IFP_DARWIN_H


#include <inttypes.h>
#include <wchar.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <setjmp.h>
#include <signal.h>
#include <fenv.h>
#include <fcntl.h>
#include <time.h>
#include <malloc/malloc.h>

#define	INLINE		inline
////////////////////////////////////////////////////////////////////////////////////////

//#define IF_ABS_NEST_INC

#define	CFS_EXPORT

#define	_platform_name	"Darwin"

#define Darwin_exe_pfx	"ifpcore_mac_"


#if defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define thread_local __thread
# else
#  error "Cannot define thread_local"
# endif

/////////////  endian

#define	IF_ENDIAN	0	//little

#define	IF_PLF_OS	3		//darwin

#ifdef __x86_64__
#define Darwin_exe_arch "i"
#define	IF_PTRSIZE		8
#define IF_PLF_CPU		1
#endif


#ifndef Darwin_exe_arch
#error	ipf_darwin.h	-	architecture not defined!
#else
#define IF_PC_EXE_NAME		(Darwin_exe_pfx Darwin_exe_arch Darwin_exe_bits)
#endif

//////////////	end arch

#define IF_DARWIN	(IF_PTRSIZE*8)

#if IF_PTRSIZE==4
#define INVALIDPTR	((void*)0xffffffff)
typedef uint32_t		PTRUINT;
typedef int32_t			PTRINT;

#define	FMT_U64	"%llu"
#define	FMT_X64	"%llX"
#define	FMT_I64	"%lld"
#define Darwin_exe_bits	"32"

#elif IF_PTRSIZE==8
#define INVALIDPTR	((void*)0xffffffffffffffff)
typedef uint64_t		PTRUINT;
typedef int64_t			PTRINT;
/*#define	FMT_U64	"%lu"
#define	FMT_X64	"%lX"
#define	FMT_I64	"%ld"*/
#define	FMT_U64	"%llu"
#define	FMT_X64	"%llX"
#define	FMT_I64	"%lld"

#define Darwin_exe_bits	"64"

#else
#error Cannot define PTRUINT!
#endif



/*
#define IF_TRY
#define IF_EXCEPT(x)	if(0)
#define IF_ETRY
*/


#define IF_TRY do{									\
	jmp_buf ex_buf__,*pex_buf__;					\
	CFS_PTHS* ex_pths__=cfsPerThreadData();			\
	if(ex_pths__){									\
		pex_buf__=ex_pths__->sehbuf;				\
		ex_pths__->sehbuf=&ex_buf__;				\
	}												\
	if( !setjmp(ex_buf__) ){

#define IF_EXCEPT(x) } else { if((x)==EEH)

#define IF_ETRY }									\
	if(ex_pths__)ex_pths__->sehbuf=pex_buf__;		\
	}while(0);

#define IF_THROW {									\
	CFS_PTHS* ex_pths__=cfsPerThreadData();			\
	if(ex_pths__ && ex_pths__->sehbuf)longjmp(ex_pths__->sehbuf[0], 1) \
	}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#define _CDECL
#define _STDCALL
#define _THREADCALL


#define INVALID		0xffffffff

#define	IF_PATHDIV	'/'
#define	IF_PATHDIV_ALT	'\\'
#define	IF_PATHDIVS	"/"
#define	IF_POSIX	1

#ifndef	CP_ACP
#define CP_ACP                    0
#endif


#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

#define	UNICODE_NULL					0

#ifndef EXCEPTION_EXECUTE_HANDLER
#define EXCEPTION_EXECUTE_HANDLER       1
#define EXCEPTION_CONTINUE_SEARCH       0
#define EXCEPTION_CONTINUE_EXECUTION    -1
#endif

#define EEH		EXCEPTION_EXECUTE_HANDLER

#define GetExceptionInformation()		NULL

#define FAR
#define NEAR

#ifndef FILE_BEGIN
#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2
#endif



#define CALLBACK
#define WINAPI
#define WINAPIV
#define APIENTRY    WINAPI
#define APIPRIVATE
#define PASCAL

typedef int (FAR WINAPI *FARPROC)();
typedef int (NEAR WINAPI *NEARPROC)();
typedef int (WINAPI *PROC)();

#define CONST		const

typedef int			        SOCKET;

typedef	char				CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			BYTE;
typedef unsigned char			BOOLEAN;
typedef	int16_t				SHORT;
typedef	uint16_t		    	WORD;
typedef	int32_t				LONG;
typedef	uint32_t			ULONG;
typedef	int32_t				INT;
typedef	uint32_t		    	DWORD;
typedef	uint32_t		    	UINT;
typedef int64_t 			i64;
typedef uint64_t	        	u64;
typedef int32_t				BOOL;
typedef void				VOID;
typedef i64				LONGLONG;
typedef u64				ULONGLONG;


typedef	void*				PVOID;
typedef	BOOL*				PBOOL;
typedef	BOOL*				LPBOOL;
typedef BOOLEAN				*PBOOLEAN;
typedef CHAR*				PCHAR;
typedef UCHAR*				PUCHAR;
typedef BYTE*				PBYTE;
typedef INT*				PINT;
typedef WORD*				PWORD;
typedef SHORT*              		PSHORT;
typedef LONG*               		PLONG;
typedef ULONG*				PULONG;
typedef DWORD*				PDWORD;

typedef	void*				LPVOID;
typedef BYTE*				LPBYTE;
typedef WORD*				LPWORD;
typedef ULONG*				LPULONG;
typedef DWORD*				LPDWORD;

typedef CHAR*				PSTR;
typedef CHAR*				LPSTR;
typedef CONST CHAR			*LPCCH, *PCCH;
typedef CHAR				*NPSTR;
typedef CONST CHAR			*LPCSTR, *PCSTR;

typedef wchar_t				WCHAR;
typedef	WCHAR				*LPWSTR,*PWSTR;

typedef PVOID				HANDLE;
typedef HANDLE				HINSTANCE;
typedef HANDLE				SC_HANDLE;

typedef	HANDLE*				PHANDLE;
typedef	SC_HANDLE*			LPSC_HANDLE;
typedef HANDLE				HWND;

#ifndef FIELD_OFFSET
#define FIELD_OFFSET(type, field)    ((PTRUINT)&(((type *)0)->field))
#endif

//-----------------------
#define O_DIRECT			0
#define lseek64 lseek
#define open64 open
#define ftruncate64 ftruncate
#define lstat64 lstat
#define stat64 stat
//#define offsetof(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))   


#define MAX_PATH			260
#define	MAX_SVC_NAME		64

//--------------- WINDOWS things

typedef void* HMODULE;

#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    };
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef PVOID EXCEPTION_POINTERS;

typedef DWORD (WINAPI *LPPROGRESS_ROUTINE)(
    LARGE_INTEGER TotalFileSize,
    LARGE_INTEGER TotalBytesTransferred,
    LARGE_INTEGER StreamSize,
    LARGE_INTEGER StreamBytesTransferred,
    DWORD dwStreamNumber,
    DWORD dwCallbackReason,
    HANDLE hSourceFile,
    HANDLE hDestinationFile,
    LPVOID lpData
    );

#define _ICS(xcs)	Ipos_InitCS(xcs)
#define _ICS_and_SC(xcs,sc)	Ipos_InitCS(xcs)

#define _DCS(xcs)	Ipos_DeleteCS(xcs)
#define _ECS(xcs)	Ipos_EnterCS(xcs)
#define _LCS(xcs)	Ipos_LeaveCS(xcs)


typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _SERVICE_STATUS {
    DWORD   dwServiceType;
    DWORD   dwCurrentState;
    DWORD   dwControlsAccepted;
    DWORD   dwWin32ExitCode;
    DWORD   dwServiceSpecificExitCode;
    DWORD   dwCheckPoint;
    DWORD   dwWaitHint;
} SERVICE_STATUS, *LPSERVICE_STATUS;

typedef PVOID PSECURITY_DESCRIPTOR;
typedef PVOID PSID;


typedef DWORD ACCESS_MASK;
typedef ACCESS_MASK *PACCESS_MASK;

typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING;
typedef GENERIC_MAPPING *PGENERIC_MAPPING;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef struct _TIME_ZONE_INFORMATION {
	DWORD	index;
    WCHAR   StandardName[ 64 ];
    WCHAR   DaylightName[ 64 ];
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;



//		--------------- Windows Constants

#define	CREATE_SUSPENDED				(0x00000004L)
#ifndef GENERIC_READ
#define GENERIC_READ                     (0x80000000L)
#define GENERIC_WRITE                    (0x40000000L)
#define GENERIC_EXECUTE                  (0x20000000L)
#define GENERIC_ALL                      (0x10000000L)
#endif	//GENERIC_READ

#define	INVALID_HANDLE_VALUE			INVALIDPTR

#define INFINITE								0xffffffff
#define	MAXIMUM_WAIT_OBJECTS					32

#include "pc_werr.h"

#define	pR_WAIT_FAILED							((DWORD   )0xffffffffL)
#define	pR_WAIT_OBJECT_0						((DWORD   )0x00000000L)
#define pR_WAIT_ABANDONED_0						((DWORD   )0x00000080L)

#define	pR_WAIT_TIMEOUT							((DWORD   )0x00000102L)


#define FILE_ATTRIBUTE_READONLY             0x00000001
#define FILE_ATTRIBUTE_HIDDEN               0x00000002
#define FILE_ATTRIBUTE_SYSTEM               0x00000004
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010
#define FILE_ATTRIBUTE_NORMAL               0x00000080

#define FILE_ATTRIBUTE_ULNK                 0x00008000

#define FILE_FLAG_NO_BUFFERING				0x20000000

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

#define	SECURITY_SQOS_PRESENT	0	//insignificant
#define	SECURITY_IMPERSONATION	0	//insignificant

#define PIPE_READMODE_MESSAGE	0x00000002	//insignificant


//		serial port definitions

#define RTS_CONTROL_DISABLE    0x00
#define RTS_CONTROL_ENABLE     0x01
#define RTS_CONTROL_HANDSHAKE  0x02
#define RTS_CONTROL_TOGGLE     0x03

#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

#define PROGRESS_CONTINUE   0
#define PROGRESS_CANCEL     1
#define PROGRESS_STOP       2
#define PROGRESS_QUIET      3

//		--------------- Windows Functions



#define	pR_GLE													Ipos_GLE
#define	pR_SLE													Ipos_SLE
#define	pR_GetLastError											Ipos_GLE
#define	pR_GetTickCount											Ipos_GetTickCount
#define	pR_GetTickCount_										Ipos_GTCSimple
#define	pR_InterlockedExchange									Ipos_InterlockedExchange
#define	pR_InterlockedExchangeAdd								Ipos_InterlockedExchangeAdd
#define	pR_InterlockedExchangeAnd								Ipos_InterlockedExchangeAnd
#define	pR_InterlockedExchangeOr								Ipos_InterlockedExchangeOr
#define	cfsInterlockedRead64									Ipos_InterlockedRead64
#define	cfsInterlockedExchange64								Ipos_InterlockedExchange64
#define	cfsInterlockedExchangeAdd64								Ipos_InterlockedExchangeAdd64


#define	pR_Sleep												Ipos_Sleep
#define	pR_ResetEvent											Ipos_ResetEvent
#define	pR_SetEvent												Ipos_SetEvent
#define	pR_WaitForMultipleObjects								Ipos_WaitForMultipleObjects
#define	pR_WaitForSingleObject									Ipos_WaitForSingleObject
#define	pR_ZeroMemory(p,cnt)									memset(p,0,cnt)
#define	pR_CopyMemory(d,s,cnt)									memcpy(d,s,cnt)
#define	pR_FillMemory(d,cnt,fill)								memset(d,fill,cnt)
#define	pR_CreateEvent(sa,man,init,name)						Ipos_CreateEvent(man,init,name)

#define	pR_TerminateThread										Ipos_TerminateThread
#define	pR_CloseHandle											Ipos_CloseHandle
#define	pR_WideCharToMultiByte									Ipos_WideCharToMultiByte
#define	pR_IsBadReadPtr(p1,s)									((((PTRUINT)(p1))<0x100)?TRUE:FALSE)
#define	pR_IsBadWritePtr(p1,s)									((((PTRUINT)(p1))<0x100)?TRUE:FALSE)
#define	pR_ProcessId											getpid
#define pR_GetCurrentThread										Ipos_GetCurrentThread
#define	pR_ThreadId												Ipos_ThreadId
#define	pR_GetLocalTime											Ipos_GetLocalTime
#define	pR_GetSystemTime										Ipos_GetSystemTime
#define pR_SetLocalTime                                         Ipos_SetLocalTime
#define pR_SetSystemTime                                        Ipos_SetSystemTime

#define	pR_SetThreadPriority									Ipos_SetThreadPriority

#define pR_CompareFileTime										Ipos_CompareFileTime
#define pR_SystemTimeToFileTime									Ipos_SystemTimeToFileTime
#define pR_FileTimeToSystemTime									Ipos_FileTimeToSystemTime
#define pR_SetFileTime(hFile,lpCreationTime,lpLastAccessTime,lpLastWriteTime)	Ipos_SetFileTimes(hFile, lpCreationTime, lpLastWriteTime)
#define pR_RoughFileTime										Ipos_RoughFileTime

#define pR_CreateMapping(wr,size,name,hnd,offs)							Darwin_CreateMapping(wr,size,name,hnd,offs)
#define pR_FlushMapping(p)										Darwin_FlushMapping(p)
#define pR_DeleteMapping(p,size)								Darwin_DeleteMapping(p,size)

#define pR_MapGenericMask										Ipos_MapGenericMask

#define pR_CreateDirNotificationEvent(name,b_sub,b_full)					Darwin_LnotStart(name)
#define	pR_CloseDirNotificationEvent								Darwin_LnotStop
#define	pR_DirNotificationNext(hEvt)

#define	pR_GetComputerName										Darwin_GetComputerName

#define	pR_FPClassGood											Ipos_FPClassGood

#define	pR_IsAdmin()											((getuid()==0)?TRUE:FALSE)
#define	OsIsAdmin(bThread)										pR_IsAdmin()

#define pR_QueryPerformanceFrequency							Ipos_PerformanceFrequency
#define pR_QueryPerformanceCounter								Ipos_PerformanceCounter

/////////////////

// by name file/dir functions
#define pR_OpenFile(fname,wr,ex,cn)								(HANDLE)Ipos_OpenFile(fname,wr,ex,cn,FALSE,FALSE)
#define pR_OpenFileNoBuf(fname,wr,ex,cn)						(HANDLE)Ipos_OpenFile(fname,wr,ex,cn,FALSE,TRUE)
#define pR_OpenFileShared(fname,wr,ex,cn)						(HANDLE)Ipos_OpenFile(fname,wr,ex,cn,TRUE,FALSE)
#define pR_OpenFileSharedNoBuf(fname,wr,ex,cn)					(HANDLE)Ipos_OpenFile(fname,wr,ex,cn,TRUE,TRUE)
#define pR_SetFileEveryones(fname)								Ipos_SetFileEveryones(fname)
#define pR_ClrFileReadonly(fname)								Ipos_ClrFileReadonly(fname)
#define	pR_FlushFileByName										Ipos_FlushFileByName
#define	pR_GetExeName											Darwin_GetExeName
#define	pR_access												Ipos_Access
#define	pR_mkdir(d)												(Ipos_CreateDirectory(d)?0:(-1))
#define pR_CreateDirectory(d)									Ipos_CreateDirectory(d)
#define	pR_rmdir												Ipos_Rmdir
#define pR_CopyFile(f1,f2,fie)									Ipos_CopyFile(f2,f1,!(fie))
#define pR_MoveFile(f1,f2,rep)									Ipos_MoveFile(f2,f1,rep)
#define pR_MoveFileWithProgress(f1,f2,rtn,rtndata,rep,through)	Ipos_MoveFileWithProgress(f1,f2,rtn,rtndata,rep,through)
#define pR_GetFileAttributes									Ipos_GetFileAttributes
#define	pR_GetFileChangeTime									Ipos_GetFileChangeTime
#define	pR_DeleteFile											Ipos_DeleteFile
#define pR_GetFreeSpace											Ipos_GetFreeSpace
//

#define	pR_WriteFileSync(h,b,cb,pcbw)							Ipos_WriteFile(h,b,cb,pcbw)
#define	pR_ReadFileSync(h,b,cb,pcbr)							Ipos_ReadFile(h,b,cb,pcbr)
#define	pR_CloseFile											Ipos_CloseHandle

#define	pR_GetFileSizeShort										Ipos_GetFileSizeShort
#define	pR_GetFileSizeLong										Ipos_GetFileSizeLong

#define	pR_SetFilePointerShort				                    Ipos_SeekShort
#define	pR_SetFilePointerLong									Ipos_SeekLong

#define pR_GetFilePointerShort									Ipos_GetFilePointerShort
#define pR_GetFilePointerLong									Ipos_GetFilePointerLong
#define	pR_SetEOF												Ipos_SetEOF
#define	pR_FlushFileByHandle									Ipos_FlushFileByHandle

#define pR_EnableFpuExceptions									Ipos_EnableFpuExceptions
#define pR_ResumeThread											Ipos_ResumeThread
#define pR_SuspendThread(x)

#define pR_GetACP											Darwin_GetCodePage
#define	pR_InitOSSpecific										DarwinInit
#define	pR_ReinitOSSpecific										DarwinReinit
#define pR_SetTerminationHandlerEvent                           Ipos_SetTerminationHandlerEvent

#define pR_OemToCharBuff										Ipos_OemToCharBuff
#define pR_CharToOemBuff										Ipos_CharToOemBuff

#define	pR_CharToOem(s,d)										pR_CharToOemBuff(s,d,pR_strlen(s)+1)
#define	pR_OemToChar(s,d)										pR_OemToCharBuff(s,d,pR_strlen(s)+1)

#define	pR_IsCharAlpha											cfsIsCharAlpha

#define	pR_SetSvcOpt(opt,val)										Darwin_SetSvcOpt( opt,val)
#define	pR_GetMainResource										Darwin_GetMainResource

#define	pR_osu_enum_users										Darwin_osu_enum_users
#define	pR_osu_logon_user										Darwin_osu_logon_user
#define	pR_NormalizeUserName										Darwin_NormalizeUserName

#define	os_uxt_attach											Ipos_uxt_attach
#define	os_uxt_detach											Ipos_uxt_detach
#define	os_uxt_tzi												Ipos_uxt_tzi
#define	os_uxt_system_ut										Ipos_uxt_system_ut
#define os_uxt_bias												Ipos_uxt_get_bias
#define os_ux_tz_change()										0
#define	os_ux_tz_by_name(tzname,tzip,pGw)						Ipos_LoadTimeZone(tzname,tzip,pGw)
#define	os_enum_time_zones()									Ipos_EnumTimeZones(NULL)



#define pR_AllowBindLow()										Ipos_AllowBindLow()
#define	pR_ForkDaemon()											Ipos_ForkDaemon()
#define	pR_KillDaemon(s)										Ipos_KillDaemon(s)

#define pR_GetBuildUT											Darwin_BuildDateUT
#define pR_GetBuildDate											Darwin_BuildDate
#define pR_GetUptime											Darwin_GetUptime
#define pR_GetThreadTiming                                      					Ipos_GetThreadTiming

#define pR_GetUserPath											Ipos_GetUserPath

#define	pR_GetHandleCount()										Ipos_GetHandleCount()

#define	pR_LoadLibrary											Ipos_LoadLibrary
#define	pR_FreeLibrary											Ipos_FreeLibrary
#define	pR_GetProcAddress										Ipos_GetProcAddress

#define	pR_GetPid												getpid

#define	pR_GetFullUserName(UserName,FullName,cbFullName)		if(cbFullName && FullName!=UserName){ strncpy(FullName,UserName,cbFullName); FullName[cbFullName-1]=0;}

#define	pR_fopen												Ipos_fopen

#define pR_FOPEN_AB	"a"
#define pR_FOPEN_WB	"w"

#define	pR_FILE_LF	"\r\n"

#define pR_LIB_ANYDIR		((LPSTR)(PTRUINT)0)
#define pR_LIB_SYSTEM		((LPSTR)(PTRUINT)1)
#define pR_LIB_LOCAL		((LPSTR)(PTRUINT)2)

#define	pR_LoadLibSecure(lib_dir,lib_name)						pR_LoadLibrary(lib_name)

DWORD	OsGetMACAddresses(PBYTE p_macs,DWORD c_macs);
//

//		---------------- Statndard functions
#include <stdio.h>
#include <errno.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


#define stricmp			strcasecmp
#define _snprintf		snprintf
#define _strupr			Ipos_strupr
#define _strlwr			Ipos_strlwr
#define closesocket		close
#define	_vsnprintf		vsnprintf
#define _lrotl			Ipos_lrotl
#define	_msize			malloc_size
#define	_fpclass		Ipos_FPClass
#define _logb			logb
#define getche			Ipos_getche
#define _fileno			fileno

#define	pR_ODS(x)	printf("ODS: %s",x)

#define pR_MulDiv(m1,m2,d)		((DWORD)((((u64)(m1))*((u64)(m2)))/((u64)(d))))

//		---------------- Cfshare functions
#define CFT_HANDLE	PVOID

#include "ifp_cfs.h"

#define IF_RU_CONV(x)											x
#define	pR_ConsoleOutConv(s,d,cb_d)								xmlMBToUTF8(s,d,cb_d)


//		---------------- INI functions
#include "ifp_ini.h"

//		----------------
#include "posix/pos_handle.h"


//		----------------
#define INADDR_ANY		0
#define INADDR_NONE		0xffffffff

#define	SOCKET_ERROR	(-1)
#define INVALID_SOCKET	(-1)

#ifdef __cplusplus
extern "C" {
#endif

extern	int Darwin_Ver_Major;
extern	int Darwin_Ver_Minor;
extern	int Darwin_Ver_Release;

BOOL			DarwinInit();
VOID			DarwinReinit();
int				Darwin_GetCodePage();
LPSTR			Darwin_GetExeName();
LPSTR			Darwin_BuildDate();
DWORD			Darwin_BuildDateUT();
BOOL			Darwin_InstallService(LPSTR svc_name, LPSTR svc_descr,LPSTR path,LPSTR base_path);
BOOL			Darwin_RemoveService(LPSTR svc_name, LPSTR path);
BOOL			Darwin_CommandService(LPSTR svc_name,INT	cmd);
BOOL			Darwin_SvcScript(LPSTR svc_name, LPSTR svc_descr,LPSTR path,LPSTR base_path);

PVOID	Darwin_CreateMapping(BOOL	wr,	DWORD	size,LPSTR	name,HANDLE	hnd,DWORD offs);
VOID	Darwin_FlushMapping(PVOID	p);
VOID	Darwin_DeleteMapping(PVOID	p,DWORD size);
BOOL	Darwin_GetUptime(u64* p_uptime);
BOOL	Darwin_GetComputerName(LPSTR szComputerName,DWORD dwComputerName);

HANDLE 	Darwin_LnotStart(LPSTR dir);
BOOL 	Darwin_LnotStop(HANDLE hEvt);

VOID	Darwin_SetSvcOpt(LPSTR opt,LPSTR value);
VOID	Darwin_FnMB2UTF(LPSTR text, LPSTR buf, DWORD cb_buf);
VOID	Darwin_FnUTF2MB(LPSTR text,LPSTR buf, DWORD cb_buf);

void	pR_DeinitOSSpecific();

#define cfsPerThreadData		Ipos_PerThreadData
#define cfsBeginThreadEx		Ipos_BeginThread
#define	cfsInitTSC				Ipos_InitTSC
#define cfsGetTSC				Ipos_GetTSC
#define cfsTSCF					Ipos_TSCF
#define cfsIsAdmin(x)			pR_IsAdmin()
BOOL	cfsIsRoot(LPSTR name);

#define	cfsSectorSize			Ipos_SectorSize

#define cfsCheckDaemonRunning	Ipos_CheckDaemonRunning
#define	cfsSrvInstallService	Darwin_InstallService
#define	cfsSrvRemoveService	    Darwin_RemoveService
#define	cfsSrvCommandService	Darwin_CommandService
#define	cfsSrvSvcScript			Darwin_SvcScript

LPSTR	cfsGetSysLimitsStr();

#define FN_MB2UTF(x)	if(cfsNonAnsi(x) || cfsDivWindows(x)) { \
		LPSTR _mb2u; \
		DWORD _mb2u_len=(pR_strlen(x)+1)*3;\
		_mb2u=alloca(_mb2u_len);	\
		Darwin_FnMB2UTF(x,  _mb2u, _mb2u_len);\
		x=_mb2u; \
	}

#define FN_UTF2MB(x)	if(cfsNonAnsi(x))Darwin_FnUTF2MB(x, x , pR_strlen(x)+1);


LPSTR	Darwin_osu_enum_users(BOOL b_comment);
BOOL	Darwin_osu_logon_user(LPSTR user, LPSTR pw, PBOOL pAdmin);
VOID	Darwin_NormalizeUserName(LPSTR uname,LPSTR osun,DWORD cb_osun);

PBYTE	Darwin_GetMainResource(PDWORD pdw);

u64	Darwin_GetHeapUsage();

#define	pR_AltBaseRoot		"/var/lib"

typedef VOID (  *BPF_CALLBACK )( PVOID arg, PBYTE data, DWORD cb_data );

PVOID bpf_start_capture(LPSTR iface, unsigned short eth_type, BPF_CALLBACK cback, PVOID cb_arg);
VOID bpf_stop_capture(PVOID p);
BOOL bpf_send_packet(PVOID p, PVOID p_packet, DWORD cb_packet);

#ifdef __cplusplus
}
#endif

#endif //IFP_DARWIN_H
