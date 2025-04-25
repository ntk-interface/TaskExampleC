#ifndef _POS_HANDLE_H
#define _POS_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////////
BOOL 	Ipos_PreInit();
BOOL	Ipos_Init(LPSTR ext_arg);
VOID	Ipos_CloseHandle(PVOID Handle);
///////////////////////////////////////////////////////////////////////////////////////
BOOL	Ipos_AllowBindLow();
INT		Ipos_ForkDaemon();//	=-1 - error, =0 - dameon, >0 - parent
BOOL	Ipos_KillDaemon(LPSTR name);
INT		Ipos_fork();
///////////////////////////////////////////////////////////////////////////////////////
LPSTR	Ipos_SkipVolPrefix(LPSTR path);

int		Ipos_GetFD(PVOID Handle);
PVOID	Ipos_OpenFile(LPSTR fname,BOOL wr,BOOL exst,BOOL cnew,BOOL shared,BOOL nobuf);
BOOL	Ipos_WriteFile(PVOID Handle,PVOID p,DWORD cb, PDWORD pcbw);
BOOL	Ipos_ReadFile(PVOID Handle,PVOID p,DWORD cb, PDWORD pcbr);
BOOL	Ipos_CopyFile(LPSTR to, LPSTR from,BOOL replace);
BOOL	Ipos_MoveFile(LPSTR to, LPSTR from,BOOL replace);
BOOL	Ipos_MoveFileWithProgress(
		LPSTR from,
		LPSTR to,
		LPPROGRESS_ROUTINE rtn,
		PVOID   rtndata,
		BOOL	rep,
		BOOL	through
		);
BOOL	Ipos_CreateDirectory(LPSTR dirname);
BOOL	Ipos_SetFileEveryones(LPSTR name);
BOOL	Ipos_SetFileEvrRd(LPSTR name);
BOOL	Ipos_ClrFileReadonly(LPSTR name);
INT		Ipos_Access(LPSTR fname,INT ac);
INT		Ipos_Rmdir(LPSTR fname);
DWORD	Ipos_GetFileAttributes(LPSTR path);

INT		Ipos_SeekShort(PVOID	Handle,INT dist,DWORD method);
i64		Ipos_SeekLong(PVOID	Handle,i64 dist,DWORD method);

INT		Ipos_GetFilePointerShort(PVOID	Handle);
i64		Ipos_GetFilePointerLong(HANDLE Handle);

DWORD	Ipos_GetFileSizeShort(HANDLE Handle);
BOOL	Ipos_GetFileSizeLong(PVOID	Handle, u64* ps);

BOOL	Ipos_SetEOF(HANDLE Handle);
BOOL	Ipos_GetFileChangeTime(LPSTR fn,FILETIME* pft);
BOOL	Ipos_SetFileTimes(HANDLE Handle, FILETIME* cr_time, FILETIME* mod_time);
BOOL	Ipos_DeleteFile(LPSTR fn);
BOOL	Ipos_FlushFileByName(LPSTR fn);
BOOL	Ipos_FlushFileByHandle(PVOID Handle);

BOOL	Ipos_InitTSC();
u64		Ipos_GetTSC();
u64		Ipos_TSCF();

VOID	Ipos_SetThreadPriority(int pri);
BOOL	Ipos_PerformanceFrequency(LARGE_INTEGER* pf);
BOOL	Ipos_PerformanceCounter(LARGE_INTEGER* pc);

DWORD	Ipos_SectorSize(LPSTR path);
VOID	Ipos_GetUserPath(LPSTR path,DWORD cb_path);

DWORD	Ipos_GetHandleCount();
HMODULE		Ipos_LoadLibrary(const char* path);
BOOL		Ipos_FreeLibrary(HMODULE module);
PVOID	Ipos_GetProcAddress(HMODULE module, const char* proc_name);
BOOL	Ipos_CheckProcParent(DWORD pid,DWORD check_pid);

VOID	Ipos_MapGenericMask(PDWORD pMask,GENERIC_MAPPING* pMapping);
FILE*	Ipos_fopen(LPSTR fn, LPSTR mode);

///////////////////////////////////////////////////////////////////////////////////////
VOID	Ipos_EnableFpuExceptions();

///////////////////////////////////////////////////////////////////////////////////////
PVOID	Ipos_BeginThread(
	void *security,
	DWORD stack_size,
	DWORD ( _THREADCALL *start_address )( void * ),
	void *arglist,
	DWORD initflag,
	DWORD *thrdaddr,
	LPSTR name,
	DWORD suid
);
HANDLE	Ipos_GetCurrentThread();
VOID	Ipos_TerminateThread(PVOID Handle,DWORD code);
CFS_PTHS* Ipos_PerThreadData();
VOID	Ipos_GetThreadTiming(CFS_PTHS* pths,LPSTR times, DWORD cb_times);
DWORD	Ipos_ThreadId();
VOID	Ipos_ResumeThread(PVOID Handle);
VOID	Ipos_CancelBlockingCall(PVOID Handle);
VOID	Ipos_CBCByTThread(PVOID tthread);
///////////////////////////////////////////////////////////////////////////////////////
PVOID	Ipos_CreateEvent(BOOL man,BOOL init,LPSTR name);
VOID	Ipos_SetEvent( PVOID Handle);
VOID	Ipos_ResetEvent( PVOID Handle);
DWORD	Ipos_WaitForSingleObject(PVOID Handle,DWORD to);
DWORD	Ipos_WaitForMultipleObjects( DWORD nCount,HANDLE *pHandles,  BOOL bWaitAll,  DWORD to);

VOID    Ipos_SetTerminationHandlerEvent(PVOID Handle);

///////////////////////////////////////////////////////////////////////////////////////
#ifdef __linux__
typedef struct {
	int			flock;	//this will be aligned
	pthread_t	thid;
	unsigned	entry_count;
}LINUX_CS;
#endif //__linux__

typedef struct {
#ifdef __linux__
	unsigned char csdata[sizeof(LINUX_CS)+8];
#else
	pthread_mutex_t Mutex;
#endif

}pR_CRITICAL_SECTION;

BOOL	Ipos_InitCS(pR_CRITICAL_SECTION* pcs);
BOOL	Ipos_EnterCS(pR_CRITICAL_SECTION* pcs);
BOOL	Ipos_LeaveCS(pR_CRITICAL_SECTION* pcs);
BOOL	Ipos_DeleteCS(pR_CRITICAL_SECTION* pcs);

///////////////////////////////////////////////////////////////////////////////////////
DWORD	Ipos_SEN();
DWORD	Ipos_SLE(DWORD err);
DWORD	Ipos_GLE();
///////////////////////////////////////////////////////////////////////////////////////
DWORD	Ipos_GetTickCount() ;
DWORD	Ipos_GTCSimple();
VOID	Ipos_Sleep(DWORD ms);
BOOL	Ipos_GetLocalTime(SYSTEMTIME* pst);
BOOL	Ipos_GetSystemTime(SYSTEMTIME* pst);
BOOL	Ipos_SetLocalTime(SYSTEMTIME* pst);
BOOL	Ipos_SetSystemTime(SYSTEMTIME* pst);
BOOL	Ipos_SystemTimeToFileTime(SYSTEMTIME* st,FILETIME* pft);
BOOL	Ipos_FileTimeToSystemTime(FILETIME* pft,SYSTEMTIME* st);
BOOL	Ipos_GetTimeZoneString(LPSTR buf,DWORD cb_buf);
LPSTR	Ipos_EnumTimeZones(LPSTR list);
BOOL	Ipos_LoadTimeZone(LPSTR fname,TIME_ZONE_INFORMATION *tzi,PBOOL pGw);
VOID	Ipos_RoughFileTime(FILETIME* pft);



VOID	Ipos_uxt_attach();
VOID	Ipos_uxt_detach();
VOID	Ipos_uxt_tzi(TIME_ZONE_INFORMATION* tzi);
DWORD	Ipos_uxt_system_ut(PWORD pms);
INT		Ipos_uxt_get_bias(TIME_ZONE_INFORMATION* ptzi,BOOL std,DWORD ut);
INT		Ipos_uxt_get_dls_bias(TIME_ZONE_INFORMATION* ptzi,BOOL gw,DWORD ut);

INT		Ipos_CompareFileTime(FILETIME* ft1,FILETIME* ft2);

BOOL	Ipos_FPClassGood(float* f);
DWORD	Ipos_FPClass(double d);

BOOL	Ipos_GetFreeSpace(LPSTR path,u64* pfsp,u64* ptot);
///////////////////////////////////////////////////////////////////////////////////////
DWORD	Ipos_InterlockedExchange(PDWORD where,DWORD what);
DWORD	Ipos_InterlockedExchangeAdd(PDWORD where,DWORD what);
DWORD	Ipos_InterlockedExchangeAnd(PDWORD where,DWORD what);
DWORD	Ipos_InterlockedExchangeOr(PDWORD where,DWORD what);

i64		Ipos_InterlockedRead64(i64 *target);
i64		Ipos_InterlockedExchange64(i64 *target, i64 value);
i64		Ipos_InterlockedExchangeAdd64(i64 *target,i64 addend);

DWORD	Ipos_lrotl(DWORD value, int shift);
CHAR	Ipos_getche();
///////////////////////////////////////////////////////////////////////////////////////

int Ipos_WideCharToMultiByte(
  UINT CodePage,            // code page	//IGNORED
  DWORD dwFlags,            // performance and mapping flags	//IGNORED
  LPWSTR lpWideCharStr,    // wide-character string
  int cchWideChar,          // number of chars in string
  LPSTR lpMultiByteStr,     // buffer for new string
  int cbMultiByte,          // size of buffer
  LPSTR lpDefaultChar,     // default for unmappable chars		//NOT USED
  LPBOOL lpUsedDefaultChar  // set when default char used
);

LPSTR Ipos_strupr(LPSTR s);
LPSTR Ipos_strlwr(LPSTR s);

///////////////////////////////////////////////////////////////////////////////////////
BOOL	Ipos_CheckDaemonRunning(LPSTR s);

///////////////////////////////////////////////////////////////////////////////////////
PVOID	Ipos_Do_CreateEvent(BOOL bManualReset,BOOL bInitialState);
VOID	Ipos_Do_DeleteEvent(PVOID pevt);
VOID	Ipos_Do_SetEvent(PVOID pevt);
VOID	Ipos_Do_ResetEvent(PVOID pevt);
int		Ipos_Do_WaitEvent(PVOID pevt,unsigned int timeout);
int		Ipos_DoWaitMultipleEvents(PVOID* ppevt, int nCount, int bWaitAll, unsigned int timeout, unsigned int *pindex);


#ifdef __cplusplus
}
#endif

///////////////////////////////////////////////////////////////////////////////////////
extern DWORD _pos_umask;

#ifndef	_FPCLASS_PN

#define _FPCLASS_SNAN   0x0001  /* signaling NaN */
#define _FPCLASS_QNAN   0x0002  /* quiet NaN */
#define _FPCLASS_NINF   0x0004  /* negative infinity */
#define _FPCLASS_NN     0x0008  /* negative normal */
#define _FPCLASS_ND     0x0010  /* negative denormal */
#define _FPCLASS_NZ     0x0020  /* -0 */
#define _FPCLASS_PZ     0x0040  /* +0 */
#define _FPCLASS_PD     0x0080  /* positive denormal */
#define _FPCLASS_PN     0x0100  /* positive normal */
#define _FPCLASS_PINF   0x0200  /* positive infinity */

#endif

//--------------------------------------
#endif //_POS_HANDLE_H
