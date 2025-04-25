#ifndef _IFP_CFS_H
#define _IFP_CFS_H

#ifdef __cplusplus
extern "C" {
#endif


VOID cfsTestFn();
//--------------------------------------

#ifndef	USE_CFSHARE_DLL

#define CFT_HANDLE	PVOID
#define CFT_ZERO	NULL

#define	IF_LDOUBLE	double

/////////////////		for non-windows environment
#ifndef	REG_NONE

#define REG_NONE                    ( 0 )   // No value type
#define REG_SZ                      ( 1 )   // Unicode nul terminated string
#define REG_EXPAND_SZ               ( 2 )   // Unicode nul terminated string
                                            // (with environment variable references)
#define REG_BINARY                  ( 3 )   // Free form binary
#define REG_DWORD                   ( 4 )   // 32-bit number
#define REG_LINK                    ( 6 )   // Symbolic Link (unicode)
#define REG_MULTI_SZ                ( 7 )   // Multiple Unicode strings

#endif // REG_NONE

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
#define	CFS_MAX_SCRATCHPAD	128

typedef DWORD TRACE_ITEM_STORAGE;


typedef struct _CFS_PTHS{
	struct _CFS_PTHS* next;
	struct _CFS_PTHS** prev_where;
//
	unsigned ( _THREADCALL *start_address )( void * );
	void*	arglist;
	LPSTR	name;
//
	DWORD	suid_proc;
	DWORD	suid_thrd;

	CHAR	Idstr[32];
	PTRUINT	thid;

#ifdef IF_PORTCORE

	PVOID	pinst;		// program instance memory
	PVOID	cinst;		// cman instance struct
	PVOID	puser;		// instance user pointer
	PVOID	lluser;		// low level user (for tms)
	PVOID	cfsuser;	// cfs user ptr
	PVOID	cmu;		// CMAN_U*
	PVOID	srvtls;		// server tls
	DWORD	cb_packet;	// datagram length (for tmconn)
	// delta
	PVOID	dpc_port;
	// ext_pc
	BYTE	b_supp_ex_checks;	//this thread shouldn't check execution dir

#endif

	PVOID	tmconn_thd;	//TMCONN THREAD DATA

	DWORD	dwGeneralAccess;
	DWORD	dwServerAccess;
	DWORD   dwStartTime;

	LPSTR	cfs_up_storage;	//crd

#if IF_POSIX
	DWORD		dwLastError;
	PVOID		pstev;
	PVOID		pevt;
	PVOID		tthread;
	DWORD		lock_cnt;
	jmp_buf*	sehbuf;
	HANDLE		hThreadHandle;
	BYTE		b_finished;
	pR_CRITICAL_SECTION
				term_cs;
#endif		//IF_POSIX

	PVOID	thread_locks;

	CHAR	scratchpad[CFS_MAX_SCRATCHPAD];
}CFS_PTHS;

#define CFS_PTHS_DEFINED 1

typedef struct {
	LARGE_INTEGER last_update;
	LARGE_INTEGER shift;
}CFS_PFCMMF;


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
#pragma pack(1)

#define IFCFG_TYPE_DEFAULT		0
#define IFCFG_TYPE_ARIS			1
#define IFCFG_TYPE_ATI			2
#define IFCFG_TYPE_DRTS			3

typedef struct {
	FILETIME CreationTime;
	FILETIME ModificationTime;
	DWORD Attributes;
	DWORD Checksum;
	DWORD Reserved[12];
}CFS_FILE_PROPERTIES;

#define STR_SRV_SIG 0x3fd5a759
#define STR_USR_SIG 0x83a3b266

#define MAX_TI_TEXT 64

#define 	TRS_SRV_STARTING 	0
#define 	TRS_SRV_RUNNING		1
#define 	TRS_SRV_STOPPING	2


typedef struct {
	DWORD	signature;
	DWORD	unique;
	DWORD	pid;
	DWORD	ppid;
	DWORD	flags;
	DWORD	dbg_cnt;
	DWORD	loud_cnt;
	CHAR	name[MAX_TI_TEXT];
	CHAR	comment[MAX_TI_TEXT];
	u64		bytes_in;
	u64		bytes_out;
	DWORD	state;
	DWORD	creation_time;
	DWORD	res_state;
}IfaceServer;

typedef struct {
	IfaceServer s;
	CHAR		cmdl[256];
}IfaceServerEx;

typedef struct {
	DWORD signature;
	DWORD unique;
	DWORD thid;
	DWORD pid;
	DWORD flags;
	DWORD dbg_cnt;
	DWORD loud_cnt;
	CHAR name[MAX_TI_TEXT];
	CHAR comment[MAX_TI_TEXT];
	u64 bytes_in;
	u64 bytes_out;
	DWORD handle;
	DWORD creation_time;
}IfaceUser;

typedef struct {
	LPSTR	pAlias;
	LPSTR	pProtocol;
	LPSTR	pAddress;
}WS_ALIAS_INFO;

#define CFS_LOGINTP_TASK_PROP	1
#define CFS_LOGINTP_SRV_STATE	2

#pragma pack()
///////////////

#define CFSID_SIG	0xCF0C0FCF
typedef struct {
	DWORD signature;
	DWORD version;
	PVOID reserved[32];
}CFS_INIT_DATA;

typedef struct {
	DWORD			size;
	DWORD			FastCheck;
	DWORD			Embedded;
	DWORD			spFlags;
	DWORD			dwCprt;
	PDWORD			pWkstaUnique;
	PDWORD			(_CDECL *FeatGetPs)();
	DWORD			(_CDECL *UiniGetBin)(LPSTR uname,LPSTR oname,LPSTR dname,PBYTE p_buf,DWORD cb_buf);
	BOOL			(_calltype_ *CreateIFLLToken)(LPSTR	uname,LPSTR	tok_uname,LPSTR	tok_ch);
	BOOL			(_calltype_ *CheckIFLLToken)(LPSTR	uname,LPSTR	tok_uname,LPSTR	tok_ch);

}CFS_SECURE_POINTERS;

#define CFSSP_F_DEVELOPER	1
//#define CFSSP_F_CFXML		2
//#define CFSSP_F_NOBOVFBRK	4
//#define CFSSP_F_MAX			0x10000

#define DIS_NAME_LEN    100
#pragma pack(1)
typedef struct {
	DWORD PrimaryDomainError;
	WORD PrimaryDomainName[DIS_NAME_LEN];
	BYTE  PrimaryDomainSid[100];
	DWORD AccountDomainError;
	WORD AccountDomainName[DIS_NAME_LEN];
	BYTE  AccountDomainSid[100];
}DOMAIN_INFO_S;
#pragma pack()

#define NTPT_NOTDEF				0
#define NTPT_WORKSTATION		1
#define NTPT_DOMAIN_CONTROLLER	2
#define NTPT_SERVER				3

#define	PT_PC_WIN				0x80
#define PT_PC_LINUX				0x81
#define PT_PC_DARWIN			0x82

#define CFS_DEBUG(a,b)

#ifdef IF_WINDOWS
#if	IF_PTRSIZE==4
#undef CFS_DEBUG
#define CFS_DEBUG(a,b) cfsDebugInt(a,b)
#endif
#endif


#pragma pack(1)
typedef struct {
	DWORD				Len;
	CHAR				ComputerName[64];
	DWORD				NtVerMaj;
	DWORD				NtVerMin;
	DWORD				NtBuild;
	DWORD				Acp;
	u64					Uptime;
	BYTE				UptimeAbs;
	BYTE				NtProductType;
	BYTE				Win64;
	BYTE				_bres1;
	BYTE				LOctet[8];
	DWORD				CurrentGMT;
	WORD				CurrentMs;
	BYTE				SecType;
	BYTE				Cprt;
	BYTE				Endian;
	BYTE				_reserved[3];
	DWORD				CfsVerMaj;
	DWORD				CfsVerMin;
	DOMAIN_INFO_S		DomInfo;
	CHAR				UserName[64];
	CHAR				_res2[64];
	CHAR				UserAddr[64];
	DWORD				UserIfIp;
	CHAR				_res3[28];
	DWORD				IpAddrs[8];
	DWORD				AccessMask;
}COMPUTER_INFO_S;
#pragma pack()



CFS_INIT_DATA*	cfsInitApp();
DWORD	cfsCaps();

BOOL		cfsInitLibrary(LPSTR base_dir,LPSTR ext_arg);
VOID		cfsDeinitLibrary();


PVOID*		cfsGetThreadLocks();
LPSTR		cfsDoThreadListEnum(PVOID pinst);
VOID		cfsGetThreadTiming(CFS_PTHS* pths,LPSTR times, DWORD cb_times);


PVOID	_calltype_	cfsAllocMemory(DWORD dw);
VOID	_calltype_	cfsFreeMemory(PVOID p);

CFS_PTHS*	cfsPerThreadData();
VOID		cfsThreadCleanup(CFS_PTHS* pths);
VOID		cfsAddThreadName(LPSTR addit);


#ifdef IF_PORTCORE
VOID		cfsClonePths(CFS_PTHS* pths,DWORD suid);
#endif

//HANDLE		cfsGetCancelEvt();
//VOID		cfsSetCancelEvt(DWORD thid);
VOID		cfsStopProcess();
BOOL		cfsSleep(DWORD msec);
BOOL		cfsInitSockets();

BOOL cfsInterlockedBitTest(PVOID p, DWORD idx);
BOOL cfsInterlockedBitSet(PVOID p, DWORD idx);
BOOL cfsInterlockedBitReset(PVOID p, DWORD idx);

#include "ifp_logmsg.h"
#include "ifp_cftree.h"

#if (defined IF_PORTCORE) || (defined TMCONN_NEW) || (defined CFSHARE_DLL)
#include "../portable/pc_cfscommon.h"
#endif

PVOID		_calltype_ cfsSAEO(); //PSECURITY_ATTRIBUTES
PVOID		_calltype_ cfsSDEO(); //PSECURITY_DESCRIPTOR
PVOID		_calltype_ cfsSALoc();
PVOID		_calltype_ cfsSDLoc();
PVOID		_calltype_ cfsSAAdmWr();
PVOID		_calltype_ cfsSAAdm();
PVOID		_calltype_ cfsSDAdmWr();
PVOID		_calltype_ cfsSDAdm();
PVOID		_calltype_ cfsSAFile();


BOOL		cfsMakeCfPath(LPSTR path,LPSTR fullpath,DWORD cb);


DWORD		cfsGetLocalDomainInfo(DOMAIN_INFO_S* dis);
VOID		cfsGetSystemVersion(PDWORD pdwVerMaj,PDWORD pdwVerMin,PDWORD pdwVerRelease,PDWORD pdwProductType);


INT			_calltype_ cfs_stricmp(LPSTR s1,LPSTR s2);
INT			_calltype_ cfs_strnicmp(LPSTR s1,LPSTR s2,INT count);



#ifdef	FN_IGNORE_CASE
#define	cfs_fncmp	cfs_stricmp
#define	cfs_fnncmp	cfs_strnicmp
#else
#define	cfs_fncmp	strcmp
#define	cfs_fnncmp	strncmp
#endif

BOOL	cfs_wildcmp(const char *wild, const char *string,BOOL case_sens);
VOID	cfs_strupr(LPSTR s);
VOID	cfs_strlwr(LPSTR s);
LPSTR	cfs_stristr(LPSTR s,LPSTR ss);
BOOL	cfsIsCharAlpha(CHAR c);
BOOL	cfsIsCharAlphaNumeric(CHAR c);
BOOL	cfs_ishex(CHAR c);
BOOL	cfs_isalpha(CHAR c);
CHAR	cfs_toupper(CHAR c);
CHAR	cfs_tolower(CHAR c);
extern	CHAR	cfsHexBytes[256][2];
extern	LPSTR	litCfsSystem;
extern	LPSTR	litMain;


BOOL xmlMBToUTF8(LPSTR text,LPSTR buf,DWORD cb_buf);
BOOL xmlUTF8ToMB(LPSTR utext,LPSTR buf,DWORD cb_buf);

BOOL cfsConvertBufIfUTF8To1251(LPSTR xtext);

#define MAX_PWD_LEN 64

VOID ndEnc1(PCHAR B,PCHAR Key);
VOID ndDec1(PCHAR B,PCHAR Key);
VOID ndE(PCHAR  B, DWORD count, PCHAR Key);
VOID ndD(PCHAR  B, DWORD count, PCHAR Key);


VOID scfsSrvCliProcessAttach();
VOID scfsDecBuf(LPSTR buf,LPSTR key,BOOL fPlusNd,PBYTE ndKey);
VOID scfsEncBuf(LPSTR buf,LPSTR key,BOOL fPlusNd,BOOL fNopwm,PBYTE ndKey);


extern	int		IF_CODE_PAGE;
//extern	int		IF_PWMS;
extern	int		IF_COMPRESS_XACT;

#ifndef	CFSHARE_DLL
extern	BYTE	Cfs_Unique[16];
extern	DWORD	Cfs_UniqueCrc;
extern	BOOLEAN	Cfs_UniqueChanged;
extern	BYTE	Cfs_UniqueGenSec;
extern BOOL		Cfs_System_Stateless;
#define	OsGetWkstaUniquePtr()	Cfs_Unique
#define	OsGetFileChangeTime		cfsGetFileChangeTime
#else
PBYTE OsGetWkstaUniquePtr();
#endif 	//CFSHARE_DLL

#define L_S(e,r)		((LPSTR)((IF_CODE_PAGE==1251)?(IF_RU_CONV(r)):(e)))
#define LS_(cp,e,r)		((LPSTR)((cp==1251)?(IF_RU_CONV(r)):(e)))
#define L_S_I(e,r)		((IF_CODE_PAGE==1251)?(r):(e))
#define _IFL_	L_S


BOOL cfsInitDirectory(LPSTR path);
BOOL cfsInitDirectoryL(LPSTR path,LPSTR relink);


BOOL cfsGetVolatilePath(LPSTR path,DWORD cbPath);

#define LIT_TEMP	"@Temp@"

DWORD cfsIfLang();

LPSTR cfsBasePath();
LPSTR cfsVolatilePath();
LPSTR cfsVolatilePathNoDef();
LPSTR cfsGetCfsharePath();
LPSTR cfsGetDataPath();
LPSTR cfsGetMainPath();
LPSTR cfsGetProtectedPath();
LPSTR cfsGetWkstaPath();
LPSTR cfsGetLogsPath();
LPSTR cfsGetTempPath();
LPSTR cfsGetRemotePath();
LPSTR cfsGetCfshareINI();
LPSTR cfsDispservIni();
LPSTR cfsExeDirectory();
LPSTR cfsGetShortExeName();
VOID cfsGetHomePath(LPSTR path,DWORD cb_path);


LPSTR	cfsGetTempShortPath();
BOOL	cfsSetVolatilePath(LPSTR path);

BOOL	cfsConfGetIniName(LPSTR buf, DWORD cb_buf);
DWORD	cfsGetConfDwordEx(LPSTR fns,LPSTR sec,LPSTR key,DWORD def);

BOOL	cfsGetComputerInfoLocal(COMPUTER_INFO_S* cis);
VOID	cfsComputerInfoLE(COMPUTER_INFO_S* cis);
BOOL	cfsGetOsUptime(PVOID connid,u64* p_uptime,PBOOL p_absolute);

BOOL cfsIsPathAbsolute(LPSTR path);
BOOL cfsMakeCfPath(LPSTR path,LPSTR fullpath,DWORD cb);
BOOL cfsCreateDirs(LPSTR fname,BOOL b_last);
BOOL cfsGetFileChangeTime(LPSTR path,FILETIME *pft);
VOID cfsConvertDividers(LPSTR buf,BOOL bwin);
BOOL cfsCleanupDir(LPSTR dirname,BOOL fRecursive,BOOL fSelf);
BOOL cfsCopyDir(LPSTR src,LPSTR dst, BOOL b_move);

VOID	cfsExpandPassword(LPSTR buf,DWORD cb_buf);




VOID	cfsLockInit();
PVOID	cfsLockFile(LPSTR fname,DWORD to);
PVOID	cfsUnlockFile(LPSTR fname,BOOL fTotal);
VOID	cfsUnlockFileByH(PVOID h);
PVOID	cfsLockFileRel(LPSTR fname,DWORD to);
PVOID	cfsUnlockFileRel(LPSTR fname,BOOL fTotal);
VOID	cfsLockFileWritten(LPSTR fname);




CFS_EXPORT
HANDLE _calltype_ cfsBeginThreadEx(
	PVOID	security,
	DWORD	stack_size,
	unsigned ( _THREADCALL *start_address )( void * ),
	PVOID	arglist,
	DWORD	initflag,
	PDWORD	thrdaddr,
	LPSTR	name,
	DWORD	suid
);

HANDLE _calltype_ cfsBeginThread(
	PVOID	security,
	DWORD	stack_size,
	unsigned ( _THREADCALL *start_address )( void * ),
	PVOID	arglist,
	DWORD	initflag,
	PDWORD	thrdaddr,
	LPSTR	name
);

VOID	_calltype_ cfsChangeThreadName(LPSTR name);

///////////////// log functions

typedef VOID (*CFS_LOGHOOK)(PVOID parm, DWORD pos, LPSTR str);
BOOL	cfslog_Init(DWORD suid);
VOID	cfslog_DeInit();
BOOL	cfslog_IsRunning();
PVOID	cfslog_Open(LPSTR name,DWORD dwForceSize);
VOID	cfslog_Close(PVOID plf,BOOL fDelete);
VOID	cfslog_FixString(LPSTR s);
VOID	cfslog_AddTextLog(LPSTR s);
VOID	cfslog_ClearMasterLog();
PVOID	cfslogCopyCreate();
VOID	cfslogCopyReset(PVOID pvlf);
BOOL	cfslogCopyGetString(PVOID pvlf,LPSTR buf,PDWORD pcb);
BOOL	cfslogCopyGetStringPos(PVOID pvlf,LPSTR buf,PDWORD pcb,PDWORD p_pos);
DWORD	cfslogCopy(LPSTR name,LPSTR fullname,DWORD cb_fullname);
BOOL	cfslogSetHook(CFS_LOGHOOK hook, PVOID parm, BOOL b_set);



///////////////// strac functions

VOID	cfsSrvSetDebug(BOOL fDebug);

#define		TRS_RST_NONRES		0

#define		TRS_SRC_INDEF		1
#define		TRS_SRC_CONN		2
#define		TRS_SRC_SYNC		3
#define		TRS_SRC_WORK		4
#define		TRS_SRC_UNCONN		5


#define		TRS_DST_RES			0x1001
#define		TRS_DST_FREE		0x1002
#define		TRS_DST_INDEF		0x1003

#define CFSUMSG_MESSAGE			'M'
#define CFSUMSG_ERROR			'E'
#define CFSUMSG_DEBUG			'D'

BOOL	strac_Init();
VOID	strac_Deinit();
VOID	strac_SetConsoleDebug(BOOL fDebug);
BOOL	strac_AllocServer(TRACE_ITEM_STORAGE* tis,DWORD pid,DWORD ppid,LPSTR name,LPSTR comment);
BOOL	strac_AllocUser(TRACE_ITEM_STORAGE* tis,DWORD pid,LPSTR name,LPSTR comment,PVOID pu);	//should be called in the context of user thread
VOID	strac_FreeUser(TRACE_ITEM_STORAGE* tis);
VOID	strac_FreeServer(TRACE_ITEM_STORAGE* tis);
VOID	strac_SetUserComment(TRACE_ITEM_STORAGE* tis,LPSTR comment);
BOOL	strac_ServerNameBySuid(DWORD suid_proc,LPSTR sn,DWORD cb);
DWORD	strac_FindServer(LPSTR name);
BOOL	strac_SetProcidBySuid(DWORD suid_proc,DWORD procid);
DWORD	strac_GetProcidBySuid(DWORD suid_proc);
DWORD	strac_FindServerByExProcid(DWORD procid);


BOOL	strac_GetNameByIdx(DWORD i,BOOL fServer,	LPSTR sn, DWORD cb);
DWORD	strac_TreeWaitChange(DWORD chc);
DWORD	strac_TreeCheckChange();
VOID	strac_TreeChange();
BOOL	strac_GetServerData(LPSTR name, IfaceServer* buf);
BOOL	strac_GetUserData(LPSTR name, IfaceUser* buf);
VOID	strac_SetServerState(TRACE_ITEM_STORAGE* tis,DWORD state);
VOID 	strac_SetResState(TRACE_ITEM_STORAGE* tis,DWORD rs);
VOID	strac_SetNameAndComment(DWORD pid,LPSTR name,LPSTR comment);


DWORD	strac_RegisterTracer(
	PVOID*	ppslot,
	DWORD	pid,
	DWORD	thid,
	BOOL	debug,
	DWORD	pause,
	DWORD	dw_max_cfs_data
);	//!=0 on error

VOID	strac_UnRegisterTracer(PVOID* ppslot);
DWORD	strac_ReadMessage(PVOID* ppslot,LPSTR p,PDWORD plen);	//!=0 on error
VOID	strac_SendMessage(LPSTR buffer,DWORD suid_proc,DWORD suid_thrd,BOOL fDbgMsg);
BOOL	strac_IsTraced(DWORD suid_proc,DWORD suid_thrd,BOOL fDbgMsg);
BOOL	strac_MsgDebug();


///////////////// lz functions

BYTE	_calltype_ cfsCompressionLevelSupported();
BOOL	_calltype_ cfslzInit();
INT		_calltype_ cfslzCompressM(PVOID InBuf,DWORD InLen,PVOID OutBuf,PDWORD pOutLen,PVOID wrkmem);
INT		_calltype_  cfslzCompress(PVOID InBuf,DWORD InLen,PVOID OutBuf,PDWORD pOutLen);
INT		_calltype_ cfslzDecompress(PVOID InBuf,DWORD InLen,PVOID OutBuf,PDWORD pOutLen);
DWORD	_calltype_ cfslzWrkmemSize();

#define cfslzCMem(x) ((x)+((x)/4)+512)


////////////////// wide char functions

WCHAR	cfsChar2WC(CHAR x);
CHAR	cfsWC2Char(WCHAR wc);
BOOL	cfsMB2WC(LPSTR s, PWSTR ws,DWORD len);
BOOL	cfsWC2MB(PWSTR ws,LPSTR s,DWORD len);

BOOL	cfsNonAnsi(LPSTR s);
BOOL	cfsDivWindows(LPSTR s);
BOOL	cfsDivUnix(LPSTR s);



////////////////// file watch functions

typedef VOID (*CFSFNOTIFY)(LPSTR fname);

HANDLE	cfsStartWatchFile(
	LPSTR cname,LPSTR fname,PFILETIME p_ft,CFSFNOTIFY func,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);	//Returns handle of auto-reset event or null

VOID	cfsStopWatchFile(HANDLE hEvt);
VOID	cfsWatcherInit(DWORD master_suid);
VOID	cfsWatcherDone();


////////////////// uxtime functions
VOID	uxt_attach();
VOID	uxt_detach();

DWORD uxgmtime();
DWORD uxgmtime_h(PBYTE pHund);
DWORD uxgmtime_ms(PWORD pMS);

DWORD uxtime();
DWORD uxtime_h(PBYTE pHund);
DWORD uxtime_ms(PWORD pMS);

DWORD uxgmtime2uxtime(	DWORD t);
DWORD uxgmt2tzuxt(	DWORD t,TIME_ZONE_INFORMATION* ptzi);
DWORD uxgmt_tz_dls_bias(	DWORD t,TIME_ZONE_INFORMATION* ptzi);
DWORD uxtime2uxgmtime(	DWORD t);
DWORD tzuxtime2uxgmt(	DWORD t,TIME_ZONE_INFORMATION* ptzi);

VOID	cfs_ut_2_ft(DWORD ut, DWORD ms, FILETIME* pft);
DWORD	cfs_ft_2_ut(FILETIME* pft, PWORD p_ms);


DWORD  mk_uxtime(DWORD Year,DWORD Month,DWORD Day, DWORD Hour,DWORD Minute,DWORD Second);

BOOL parse_uxtime(DWORD t,
    PDWORD Year,
    PDWORD Month,
    PDWORD Day,
    PDWORD Hour,
    PDWORD Minute,
    PDWORD Second);

INT		sprint_uxtime(DWORD ut,LPSTR buf);
DWORD	scans_uxtime(LPSTR s);

DWORD	dow_uxtime(DWORD t);

VOID	ux_tzi(TIME_ZONE_INFORMATION* tzi);
DWORD	ux_tz_change();
BOOL	ux_tz_by_name(LPSTR tzname,TIME_ZONE_INFORMATION* tzip,PBOOL pGw);

BOOL	cfsGetExactSystemTime(SYSTEMTIME* pst);

BOOL	_calltype_	cfsCopyFile( LPSTR lpExistingFileName, LPSTR lpNewFileName, BOOL bFailIfExists);
BOOL	_calltype_	cfsMoveFile( LPSTR lpExistingFileName, LPSTR lpNewFileName, BOOL bReplaceExisting);

///////////////////// ztl functions

DWORD	ztl_len(LPSTR ztl);
DWORD	ztl_count(LPSTR ztl);
BOOL	ztl_expand(LPSTR* p_ztl,LPSTR str);
LPSTR	ztl_find(LPSTR ztl,LPSTR s);
BOOL	ztl_remove_first(LPSTR ztl);
BOOL	ztl_remove(LPSTR ztl,LPSTR s);
BOOL	ztl_insert_front(LPSTR* p_ztl,LPSTR str);


#define ZTLLen ztl_len
#define ZTLCount ztl_count
#define	ZTLExpand ztl_expand
#define ZTLFind ztl_find
#define ZTLRemove ztl_remove
#define ZTLInsertFront ztl_insert_front

///////////////////// file find

PVOID	cfs_FFindFirst( LPSTR path,LPSTR mask);
BOOL	cfs_FFindNext( LPSTR mask, PVOID Handle);
BOOL	cfs_FFindClose( PVOID Handle);
LPSTR	cfs_FFindFileData(PVOID Handle, PDWORD p_attr);
LPSTR	cfs_FFindFileDataEx(PVOID Handle, PDWORD p_attr,u64* p_fs, FILETIME* p_ft);
BOOL	cfsGetFileSizeByName(LPSTR name,u64* pfs); //accompanying


///////////////////// thread list
#ifdef IF_PORTCORE
VOID	cfsThreadListInsert(CFS_PTHS* pths);
VOID	cfsThreadListRemove(CFS_PTHS* pths);
LPSTR	cfsThreadListEnum(PVOID pinst);

VOID	_calltype_ cfsChangeThreadName(LPSTR name);
#endif

///////////////////// pkf files
typedef BOOL (* pfkProgressFn)(LPSTR pkf_name,LPSTR file_name, DWORD fidx, u64 total_size, u64 total_pos, u64 file_size, u64 file_pos, PVOID prog_parm);

BOOL	_calltype_  pkfPack(LPSTR pkfname,LPSTR fnames,LPSTR errs,DWORD errlen);
BOOL	_calltype_	pkfPackProgress(LPSTR pkfname,LPSTR fnames,LPSTR errs,DWORD errlen, pfkProgressFn prog, PVOID prog_parm);
BOOL	_calltype_  pkfPackAdd(LPSTR pkfname,LPSTR fnames,LPSTR errs,DWORD errlen);
LPSTR	_calltype_  pkfUnPack(LPSTR pkfname,LPSTR dirname,LPSTR errs,DWORD errlen);
LPSTR	_calltype_  pkfEnumPackedFiles(LPSTR pkfname,LPSTR errs,DWORD errlen);
BOOL	_calltype_  pkfExtractFile(LPSTR pkfname,LPSTR fname, LPSTR dirname,LPSTR errs,DWORD errlen);

BOOL	_calltype_  pkfPack_Pwd(LPSTR pkfname,LPSTR fnames,LPSTR errs,DWORD errlen,LPSTR pwd);
BOOL	_calltype_  pkfPackAdd_Pwd(LPSTR pkfname,LPSTR fnames,LPSTR errs,DWORD errlen,LPSTR pwd);
LPSTR	_calltype_  pkfUnPack_Pwd(LPSTR pkfname,LPSTR dirname,LPSTR errs,DWORD errlen,LPSTR pwd);
BOOL	_calltype_  pkfExtractFile_Pwd(LPSTR pkfname,LPSTR fname, LPSTR dirname,LPSTR errs,DWORD errlen,LPSTR pwd);

VOID	_calltype_	pkfFreeMemory(PVOID p);

INT					cfsZipPack(LPSTR zipname,LPSTR fnames);
LPSTR				cfsZipUnpack(LPSTR zipname,LPSTR dir,INT* p_error);


///////////////////// base64
int		b64E(char *src, size_t srclength, char *target, size_t targsize);
int		b64D(char *src, char *target, size_t targsize);

///////////////////// access

VOID		cfsSrvHLInit();

BOOL		cfsSrvEnumOSUsers(LPSTR buf,DWORD cb_buf,BOOL b_comment);

///////////////////// aliases etc


BOOL	cfsSrvGetPreferedAliasPwd(BOOL fAdmin,LPSTR alias,LPSTR user,DWORD cb_user,LPSTR pwd,DWORD cb_pwd);
BOOL	cfsSrvSavePreferedAliasPwd(BOOL fAdmin,LPSTR alias,LPSTR user,LPSTR pwd);

///////////////////// user type
#define	CFS_UT_OPSYS	(0)
#define	CFS_UT_CERT		((BYTE)'.')
#define	CFS_UT_SPEC		((BYTE)'@')
#define	CFS_UT_OWN		((BYTE)'*')

#define	CFS_UT_IFLL		((BYTE)'`')

#define	CFS_PWT_MD5					0x01
#define	CFS_PWT_SHA256				0x02
#define	CFS_PWT_GOST34_11_12		0x04
#define	CFS_PWT_SHA512				0x08


///////////////////// general access

#define CFSHARE_ACCESS_READ			0x00000001
#define CFSHARE_ACCESS_WRITE		0x00000002
#define CFSHARE_ACCESS_GLOBAL		0x00000004
#define CFSHARE_ACCESS_OP_PIPE		0x00000008
#define CFSHARE_ACCESS_TRACE		0x00000010
#define CFSHARE_ACCESS_AL_SEC		0x00000020
#define CFSHARE_ACCESS_AL_ADM		0x00000040
#define CFSHARE_ACCESS_SECCHG		0x00008000

#define CFSHARE_ACCESS_OR			0x80000000

#define CFSHARE_GENERIC_READ		CFSHARE_ACCESS_READ
#define CFSHARE_GENERIC_WRITE		(CFSHARE_ACCESS_READ|CFSHARE_ACCESS_WRITE)
#define CFSHARE_GENERIC_ALL			(CFSHARE_ACCESS_READ|CFSHARE_ACCESS_WRITE|CFSHARE_ACCESS_GLOBAL|CFSHARE_ACCESS_OP_PIPE|CFSHARE_ACCESS_TRACE|CFSHARE_ACCESS_SECCHG|CFSHARE_ACCESS_AL_SEC|CFSHARE_ACCESS_AL_ADM)

#define	IF_RIGHT_INTERACTIVE		(0x04000000)

DWORD	cfsGetGeneralAccess();

#define	CFSCP_R		1	/*data diode?*/
#define	CFSCP_S		2	/*data diode?*/
#define CFSCP_LG	4



#define CFS_SECURITY_LEVEL_DEFAULT	0
#define CFS_SECURITY_LEVEL_ACCESS	1
#define CFS_SECURITY_LEVEL_SSL		2
#define CFS_SECURITY_LEVEL_MAX		2


#define	CFS_NUS_FL_AVAIL		0x00000001	//subsystem available
#define	CFS_NUS_FL_CERT			0x00000002	//certificate support
#define	CFS_NUS_FL_EXUS			0x00000004	//special user support
#define	CFS_NUS_FL_OSUS			0x00000008	//own user support
#define	CFS_NUS_FL_CHGP			0x00000100	//change password
#define	CFS_NUS_FL_SLOG			0x00000200	//security log
#define	CFS_NUS_FL_UTMPL		0x00000400	//user templates
#define CFS_NUS_FL_ADMCHGP		0x00000800	

DWORD	cfsSessionId();
VOID	cfsDebugInt(LPSTR a,LPSTR b);

#ifdef CFSHARE_SECURED
#include "ifp_cfssec.h"
#endif

/////////////////////	secure functions
#define PR_FLF_FUNCTIONS	1
LPSTR	pR_strcpy(LPSTR dest, const LPSTR src);
LPSTR	pR_strncpy(LPSTR dest, const LPSTR src, DWORD count);
DWORD	pR_strlen(const LPSTR str);
LPSTR	pR_strcat(LPSTR	dest, const LPSTR src);
PVOID   pR_memcpy(PVOID dest, const PVOID src, DWORD cnt);
INT		pR_sprintf(LPSTR buf, const LPSTR pformat, ...);
INT		pR_snprintf(LPSTR buf, DWORD count, const LPSTR pformat, ...);
INT		pR_atoi(const LPSTR s);

LPWSTR	pR_strcpyW(LPWSTR dest, const LPWSTR src);
LPWSTR	pR_strncpyW(LPWSTR dest, const LPWSTR src, DWORD count);
DWORD	pR_strlenW(const LPWSTR str);
LPWSTR	pR_strcatW(LPWSTR	dest, const LPWSTR src);

BOOL	pR_CheckForFileExistance(const LPSTR fn);
INT		pR_getchar();

#define pR_sscanf	sscanf


/////////////////////  tsc

BOOL			tscUse();
CFS_PFCMMF*		tscMmf();
VOID			tscGetPF(u64 *ppf);
VOID			tscGetPC(u64 *ppc);
DWORD			tscGetExactUT(PWORD pms);

#define cfsGetTickCount pR_GetTickCount
#define	pR_GetThreadTiming cfsGetThreadTiming

/////////////////////// sid
#ifdef IF_PORTCORE
#define pR_IsValidSid ifpcIsValidSid
#define pR_GetLengthSid ifpcGetLengthSid
#define pR_EqualSid ifpcEqualSid
#else
#define pR_IsValidSid IsValidSid
#define pR_GetLengthSid GetLengthSid
#define pR_EqualSid EqualSid
#endif


/////////////////////// ptrid

#if IF_PTRSIZE==8
DWORD	cfs_allocptrid(PVOID ptr);
BOOL	cfs_freeptrid(DWORD ptrid);
PVOID	cfs_ptrid(DWORD ptrid);
#endif

/////////////////////// misc
BOOL	cfsCheckDaemonRunning(LPSTR s);
DWORD	_calltype_ cfsRandom();
BOOL	cfsAlAlloc(DWORD size,DWORD align,PVOID* ppvm, PVOID *ppmal);
VOID	cfsAlFree(PVOID* ppvm, PVOID *ppmal);
VOID 	cfsGetCliSessionKey(LPSTR sk/*17 bytes*/);
BOOL	cfsSetCliSessionKey(LPSTR sk);


DWORD cfsSectorSize(LPSTR fname);


////////////////////	al reserve

#define CFS_RESERVE_NONE	0
#define CFS_RESERVE_SRC		1
#define CFS_RESERVE_TARGET	2
#define CFS_RESERVE_NOTACT	3

typedef struct {
	DWORD	StructSize;
	DWORD	ReserveType;
	DWORD	InetAddr;
	WORD	Port;
	DWORD	AbortTimeout;
	DWORD	RetakeTimeout;
	DWORD	BindAddr;
	BOOL	CopyConfig;
	WORD	BroadcastPort;
	BOOL	StopInactive;
}CFS_RESERVE_PARAMETERS;

////////////////////
#pragma pack(1)
#define CFS_EUD_RCNT	250
typedef struct {
    DWORD	RecNum;		//not used
    DWORD	UserID;	//1-255
    BYTE	Group;
    CHAR	KeyID[16];
    CHAR	Nick[16];
    CHAR	NickPwd[8];	//not used?
    CHAR	Rights[CFS_EUD_RCNT];
}CFS_EXT_USER_DATA;
#pragma pack()

typedef struct {
	DWORD	error_code;
	DWORD	bflags;
	CHAR	fname_or_error[1024];
}TCfsServerBackupData;

DWORD cfsGetVersion();

////////////////////	connection oriented

#ifndef FAIL_IF_NO_CONNECT
#define FAIL_IF_NO_CONNECT 0x80000000
#endif

#define CID_HANDLE	PVOID

VOID	cfsSetUser(LPSTR name,LPSTR pwd);

BOOL	cfsSetUserForThread(LPSTR name,LPSTR pwd);

VOID	cfsGetUser(LPSTR name,DWORD namelen,LPSTR pwd,DWORD pwdlen);

PVOID	cfsConnect(LPSTR serverName,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

PVOID	cfsConnectCrd(LPSTR serverName,LPSTR user, LPSTR pwd, LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsCheckUserCred(PVOID connid,LPSTR name,LPSTR pwd);

VOID	cfsDisconnect(PVOID connid);

VOID	cfsBreakConnection(PVOID connid);

DWORD	cfsGetConnectionType(PVOID connid);

DWORD	cfsGetConnectionParms(PVOID connid,PBYTE p_sst,PBYTE p_usertype,LPSTR p_user, DWORD cb_user,LPSTR p_addr,DWORD cb_addr);

BOOL	cfsIsConnected(PVOID connid);

DWORD	cfsGetSoftwareType(PVOID connid);

BOOL	cfsGetBasePath(PVOID connid,LPSTR path,DWORD cbPath,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);	//returns FALSE if error

DWORD	cfsPipeOpen(PVOID connid,LPSTR pipe,DWORD flags,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsPipeClose(PVOID connid,DWORD hPipe,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsPipeWait(PVOID connid,LPSTR pipe,DWORD dwTime,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsPipeSetMode(PVOID connid,DWORD hPipe,DWORD mode,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsPipeTransact(	PVOID connid,DWORD hPipe,	LPVOID outbuf,DWORD cb_outbuf,LPVOID inbuf,DWORD cb_inbuf,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsPipeRead(	PVOID connid,DWORD hPipe,LPVOID inbuf,DWORD cb_inbuf,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsPipeWrite(	PVOID connid,DWORD hPipe,LPVOID outbuf,DWORD cb_outbuf,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIsReadOnly(PVOID connid,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsTest(PVOID connid,PBYTE pData,DWORD cbData,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileLock(PVOID connid,LPSTR fname,DWORD to,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileUnlock(PVOID connid,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsFileGetSize(PVOID connid,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

u64		cfsFileGetSizeEx(PVOID connid,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileCopy(PVOID connid,LPSTR existing_fname,LPSTR new_fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileMove(PVOID connid,LPSTR existing_fname,LPSTR new_fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileDelete(PVOID connid,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileGetTime(PVOID connid,LPSTR fname,
			PFILETIME pft,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileGetPropreties(PVOID connid,LPSTR fname,
			CFS_FILE_PROPERTIES* pprops,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsDirEnum(PVOID connid,LPSTR dirname,
			LPSTR buf,DWORD len,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFilePut(PVOID connid,LPSTR remote_fname,LPSTR local_fname,DWORD timeout,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

typedef VOID (* cfsProgressFn)(DWORD count,DWORD total,LPVOID param);

typedef VOID (* cfsBackupProgressFn)(DWORD per_cent,LPVOID str,LPVOID param);

BOOL	cfsFilePutEx(PVOID connid,LPSTR remote_fname,LPSTR local_fname,DWORD timeout,
			cfsProgressFn pfn,LPVOID pfn_parm,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileGet(	PVOID connid,	LPSTR remote_fname,		LPSTR local_fname,	DWORD timeout,PFILETIME pft,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsFileGetEx(PVOID connid,LPSTR remote_fname,LPSTR local_fname,
			DWORD timeout,PFILETIME pft/* optional if not null*/,
			cfsProgressFn pfn,LPVOID pfn_parm,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);	//returns FALSE if error

CFT_HANDLE
		cfsConfFileOpen(LPSTR serverName,LPSTR fname,DWORD timeout,PFILETIME p_ft,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

CFT_HANDLE
		cfsConfFileOpenCid(	PVOID	connid, LPSTR serverName,LPSTR fname,DWORD timeout,PFILETIME p_ft,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsConfFileSaveAsUser(CFT_HANDLE tree_id,LPSTR serverName,
		LPSTR remote_fname,DWORD timeout,PFILETIME pft,
		LPSTR username,
		LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsConfFileSaveAs(CFT_HANDLE tree_id,LPSTR serverName,
			LPSTR remote_fname,DWORD timeout,PFILETIME pft,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsNodeFileSave(CFT_HANDLE  tree_id,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

CFT_HANDLE
		cfsNodeFileLoad(LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

CFT_HANDLE
		cfsConfFileLoadLocal(LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsConfFileSaveLocal(CFT_HANDLE tree_id,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsGetSysdataFile(PVOID connid, 	LPSTR name,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsLogOpen(PVOID connid,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsLogClose(PVOID connid, 	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsLogCopy(PVOID connid, 	LPSTR name,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsLogGetRecord(PVOID connid,BOOL fFirst,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsLogClear(PVOID connid,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

u64		cfsSlogOpen(PVOID connid,DWORD log_type,DWORD file_start_idx,DWORD dir,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsSlogReadRecords(	PVOID connid,	u64 sl_handle,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsSlogClose(PVOID connid,u64 sl_handle,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

u64		cfsLocalSlogOpen(LPSTR fname,LPSTR pwd);

LPSTR	cfsLocalSlogReadRecords(u64 sl_handle);

VOID	cfsLocalSlogEndScan(u64 sl_handle);

BOOL	cfsGetComputerInfo(PVOID connid,COMPUTER_INFO_S* cis,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsExternalBackupServer(PVOID connid,LPSTR dllname,LPSTR servname,DWORD bflags,
			TCfsServerBackupData* pbd,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsExternalRestoreServer(PVOID connid,LPSTR dllname,LPSTR servname,LPSTR filename,PDWORD pbflags,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsGetIniString(PVOID connid,LPSTR path,LPSTR section,LPSTR key,LPSTR def,LPSTR value,PDWORD pcb_value,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsSetIniString(PVOID connid,LPSTR path,LPSTR section,LPSTR key,LPSTR value,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIpgGetPort(CID_HANDLE connid,LPSTR oname,DWORD portidx,PDWORD p_port,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIpgSetPort(CID_HANDLE connid,LPSTR oname,DWORD portidx,DWORD port,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsEditGrabCid(PVOID connid,BOOL bGrab,LPSTR fname,LPSTR username,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsEditGrab(LPSTR MachineName,BOOL bGrab,LPSTR fname,LPSTR username,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

PVOID	cfsPmonGetProcByCmdline(LPSTR cmdl);

DWORD	cfsPmonFindPossibleParent(LPSTR	cmdl);

PVOID	cfsPmonLocalDispatchProcessCmdline(
			LPSTR	cmdl,
			DWORD	dwParId,
			PDWORD	pPid
);

PVOID	cfsPmonLocalDispatchProcess(
			int argc,
			char** argv,
			DWORD dwParId,	//ingored
			PDWORD pPid);

VOID	cfsPmonLocalUndispatchProcess(PVOID pd);

BOOL	cfsPmonLocalCheckProcess(PVOID pd);

BOOL	cfsPmonLocalStopProcessBySuid(DWORD suid);

BOOL	cfsPmonGetCmdlineBySuid(DWORD suid,LPSTR cmdl,DWORD cb_cmdl);

VOID	cfsPmonLocalRegisterProcess(int argc,char** argv,PHANDLE phStartEvt,PHANDLE phStopEvt);

LPSTR	cfsPmonCreateObjectName(int argc,char** argv,LPSTR prefix);

CHAR** cfsPmonLocalTokenizeString(LPSTR s,PINT pargc);

LPSTR	cfsEnumTimezones(PVOID connid,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

//////////////////////////////////////////////////////////////////////////////
BOOL cfsPmonEnumProcesses(PVOID connid,LPSTR prefix,LPSTR* pResult,BOOL fRunning,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsPmonRestartProcess(PVOID connid,LPSTR process_name_args,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD cfsPmonCheckProcess(PVOID connid,LPSTR process_name_args,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsPmonStopProcess(PVOID connid,LPSTR process_name_args,PDWORD pnumfound,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsPmonStopProcessEx(PVOID connid,LPSTR process_name_args,DWORD fKill,PDWORD pnumfound,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR cfsEnumThreads(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);
//////////////////////////////////////////////////////////////////////////////

LPSTR   cfsExecChildProcess(LPSTR cmdline, HANDLE hStop, DWORD to, PCHAR p_bdata,DWORD max_data, PDWORD pdw_exit_code);

VOID	cfsSlaveServerLogAudit(LPSTR s);

DWORD	cfsGetExtendedUserData(CID_HANDLE connid,LPSTR srvtype,LPSTR srvname,PVOID p_buf, DWORD cb_buf);

//////////////////////////////////////////////////////////////////////////////

BOOL	cfsIfpcNewUserSystemAvaliable(PVOID connid, PDWORD p_fl,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsIfpcMaster(PVOID connid,BYTE command /*0,1,2*/);

LPSTR	cfsIfpcEnumUsers(PVOID connid, LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsIfpcEnumOSUsers(PVOID connid,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsIfpcEnumUsersEx(PVOID connid,	DWORD	level,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcSetUserPwd(PVOID connid,LPSTR name,LPSTR pwd,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcDeleteUser(PVOID connid,LPSTR name,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD	cfsIfpcGetAccess(PVOID connid,LPSTR uname,LPSTR oname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcSetAccess(PVOID connid,LPSTR uname,LPSTR oname,DWORD dw_access,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsIfpcGetUserCertProps(PVOID connid,LPSTR uname,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR	cfsIfpcGetSecStats(PVOID connid,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

PVOID	cfsIfpcGetBin(PVOID connid,LPSTR uname,LPSTR oname,LPSTR binname,PDWORD p_cb_bin, LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcSetBin(PVOID connid,LPSTR uname,LPSTR oname,LPSTR binname,PVOID p_bin,DWORD cb_bin,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcBackupSecurity(CID_HANDLE connid,LPSTR snp,LPSTR pwd,LPSTR filename,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcRestoreSecurity(CID_HANDLE connid,LPSTR snp,LPSTR pwd,LPSTR filename,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcUDBFileTime(PVOID connid,FILETIME* ft,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcGetLogonToken(PVOID connid,LPSTR tok_uname /*MAX_PWD_LEN*/,LPSTR tok_token /*MAX_PWD_LEN*/,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsIfpcReactivateKey(PVOID connid,BOOL f_check,
			LPDWORD perr,LPSTR err_string,DWORD maxerrs);

#define TMCALC_TESTWAY_PRESENT	0
#define TMCALC_TESTWAY_CHECK	1
#define TMCALC_TESTWAY_TEST		2
#define TMCALC_TESTWAY_DRY		3

BOOL cfsIfpcTestTmcalc(PVOID connid,LPSTR tmsname,LPSTR clcname,DWORD test_way,DWORD test_flags,
	u64* p_handle,	PDWORD		p_pid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsIfpcStopTestTmcalc(PVOID connid, u64 handle, DWORD pid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsSwapFnSrvRole(LPSTR serverName, BOOL b_pre, LPSTR fns_name,LPDWORD perr,LPSTR err_string,DWORD maxerrs );

BYTE	cfsGetHostSecurityType(PVOID connid);

BOOL	cfsGetSecurityLevel(PVOID connid,PDWORD p_level,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsSetSecurityLevel(PVOID connid,DWORD level,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsUploadCert(PVOID connid,LPSTR fname,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsUploadMasterCert(PVOID connid,LPSTR fname,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsRemoteCheckCert(PVOID connid,LPSTR fname,LPSTR subj, DWORD cb_subj,LPDWORD perr,LPSTR err_string,DWORD maxerrs);

#ifndef CFSIITGK_AVAIL
#define CFSIITGK_AVAIL		0	
#define CFSIITGK_EXE		1	
#define CFSIITGK_ALL		2
#endif

BOOL	cfsCheckInstallationIntegrity(PVOID connid,DWORD kind,LPSTR* p_sig, LPSTR* p_errs,	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

CFS_EXPORT DWORD	_calltype_ cfs_s_s_GetSecurityLevel(PDWORD p_level);

VOID	_calltype_ cfsAuditMessage(
	DWORD flags,
	DWORD sesid,
	LPSTR uname,
	LPSTR text
);

LPSTR cfsTraceEnumServers(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR cfsTraceEnumUsers(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsTraceRestartProcess(PVOID connid,DWORD pid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL	cfsTraceStopProcess(PVOID connid,DWORD pid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceGetServerData(PVOID connid,LPSTR suid,IfaceServer* is,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceGetUserData(PVOID connid,LPSTR suid,IfaceUser* iu,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceGetServerDataEx(PVOID connid,LPSTR suid,IfaceServer* is,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceGetUserDataEx(PVOID connid,LPSTR suid,IfaceUser* iu,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD cfsTraceTreeWaitForChange(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

DWORD cfsTraceTreeCheckForChange(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceBeginTrace(PVOID connid,DWORD pid,DWORD thid,BOOL fDebug,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceBeginTraceEx(PVOID connid,DWORD pid,DWORD thid,BOOL fDebug,DWORD pause,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

BOOL cfsTraceEndTrace(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR cfsTraceGetMessage(PVOID connid,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

LPSTR lf_ParseMessage(LPSTR s,LPSTR sTime,LPSTR sDate,LPSTR sName,LPSTR sType,LPSTR sMsgType,LPSTR sThid);

BOOL cfsSaveMachineConfig(BOOL fFull,LPSTR RemoteMasterMachine,LPSTR FileName,LPSTR errs,DWORD cb_errs);

BOOL cfsPrepNewConfig(PVOID connid,LPSTR remote_fname,
	LPDWORD perr,LPSTR err_string,DWORD maxerrs);

#define	CFS_SMC_DEV			0
#define	CFS_SMC_MEDIUM		1
#define	CFS_SMC_COMPLETE	2

BOOL cfsSaveMachineConfigEx(
	LPSTR			RemoteMasterMachine,
	LPSTR			FileName,
	DWORD			dwScope,
	cfsBackupProgressFn	cfs_pfn,
	PVOID			cfs_pfn_parm,
	LPSTR			errs,
	DWORD			cb_errs
);

LPSTR cfsGetIfllKey();

typedef BOOL ( *i850CfProgress)(PVOID parm,LPSTR txt,BOOL err);
BOOL cfsI850GetConfig(CFT_HANDLE tid, LPSTR proto_parms, LPSTR addrs, LPSTR filename, i850CfProgress prog, PVOID prog_parm);

#ifdef IF_PORTCORE

VOID cfsSaveBDir(LPSTR base_dir);
BOOL cfsGetBDir(LPSTR base_dir, DWORD cb_bdir);

BOOL	cfsInitBlobsCheck(LPSTR exfn);
LPSTR	cfsInitBlobsEnum(LPSTR mask);	//free with cfsFreeMemory()
BOOL	cfsInitBlobExtractFile(LPSTR exfn,LPSTR dirname);
DWORD	_calltype_ cfs_s_s_SetSecurityLevel(DWORD level);
DWORD	_calltype_ cfs_s_s_SecLevel();

LPSTR		cfsUiniGetCert(LPSTR uname);
LPSTR		cfsUiniGetCertData(LPSTR uname);
BOOL		cfsUiniSaveCert(LPSTR uname,PBYTE cert, DWORD cb_cert);

BOOL		cfsValidateCert(LPSTR file_path,LPSTR uname,DWORD cb_uname,PBOOL has_priv_key);
BOOL		cfsCheckServerCert(LPSTR* pcertdata);
BOOL		cfsDeleteUiniSection(LPSTR uname);


DWORD	cfsGetExtendedUserDataByName(LPSTR username,LPSTR srvtype,LPSTR srvname,PVOID p_buf, DWORD cb_buf);
LPSTR	cfsGetExtendedUserParmByName(LPSTR username,LPSTR srvtype,LPSTR srvname,LPSTR parmname);

BOOL	cfsOSCheckPwd(DWORD sesid,LPSTR uname,LPSTR pwd,PBOOL pAdmin);
VOID	cfsCorrectAccessMask(PDWORD pdwAccessMask,LPSTR rbuf,LPSTR oname);

INT		cfsGetVirt(void);
VOID	cfsGetOsVersionString(LPSTR vers,DWORD cb_vers);

BOOL cfsCprtText(DWORD id,LPSTR tmpbuf,DWORD cb_tmpbuf);

LPSTR cfsGetDataPathAlt();
LPSTR cfsGetMainPathAlt();

VOID  cfsCreateIfllKey();

PTRUINT TmcalcRunTest(
	PDWORD	pChildPid,
	LPSTR	tmsname, 
	LPSTR	clcname, 
	DWORD	test_way, 
	DWORD	test_flags
);

BOOL TmcalcStopTest(
	PTRUINT handle,
	DWORD	pid
);
#endif	// IF_PORTCORE

#endif //	USE_CFSHARE_DLL

#ifdef __cplusplus
}
#endif

//--------------------------------------
#endif //_IFP_CFS_H
