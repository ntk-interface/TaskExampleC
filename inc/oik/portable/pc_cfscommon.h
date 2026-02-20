#ifndef _PC_CFSCOMMON_H
#define _PC_CFSCOMMON_H
/////////////////////////////////////////

#ifdef IF_PORTCORE
#define	CFS_OWNCOMMON
#endif

#ifdef CFSHARE_DLL
#define	CFS_OWNCOMMON
#endif

#ifdef IF_SCADASEC
#define	CFS_OWNCOMMON
#endif

#ifdef TMCONN_NEW
#define	CFS_OWNCOMMON
#endif

////////////////// misc
VOID	cfsInitCliSessionKey();
BOOL	strac_GetUserByIdx(DWORD idx,PVOID* ppu);
VOID	cfsSetStrictSessionControl(DWORD i);
VOID	cfsTestTSC();

#ifdef	CFS_PTHS_DEFINED
VOID	cfsThreadListInit();
VOID	cfsThreadListDeinit();
VOID	cfsThreadListInsert(CFS_PTHS* pths);
VOID	cfsThreadListRemove(CFS_PTHS* pths);
#endif


extern	BOOL cfs_StrictSessionControl;
extern	BOOL cfs_StrictSesAllowAdmin;


////////////////// rfcb
#define SMALLEST_SS	0x200

typedef struct {
	HANDLE  hFile;
	LPSTR	fname;
	PBYTE	pvm;
	PBYTE	mptr;
	DWORD	vmsize;
	DWORD	vsecsize;
	DWORD	vseccnt;
}RFCB;


#define RFCB_DISPOS_QUIET 0x80000000

BOOL _CDECL rfcbOpen(RFCB* f,LPSTR fname,DWORD dwFlagsAttr,DWORD dwDisposition);
VOID _CDECL rfcbClose(RFCB* f);
BOOL _CDECL rfcbGetSize(RFCB* f,u64* ppos);
BOOL _CDECL rfcbReadFile(RFCB* f,u64 pos,PVOID buf,DWORD count,PDWORD pdwread );
BOOL _CDECL rfcbWriteFile(RFCB* f,u64 pos,PVOID buf,DWORD count,PDWORD pdwwr );
BOOL _CDECL rfcbWriteBufs(RFCB* f,u64 pos,PVOID* bufs,DWORD* cnts,PDWORD pdwwr );
VOID _CDECL rfcbFlush(RFCB* f);
BOOL _CDECL rfcbSetEOF(RFCB* f,u64 pos);

////////////////// conffile

CFT_HANDLE	conffileLoadTree(HANDLE hFile,BOOL fNoFirstLev);
BOOL		conffileSaveTree(CFT_HANDLE tid,HANDLE hFile,BOOL fFirstLev);

BOOL		cfsXmlSaveTree(CFT_HANDLE tid,HANDLE hFile,BOOL fFirstLev);
CFT_HANDLE	cfsXmlLoadTree(HANDLE hFile);

CFT_HANDLE	cfsPlainLoadTree(HANDLE hFile);

////////////////// rwl functions

VOID	_calltype_ rwlProcessAttach();
VOID	_calltype_ rwlProcessDetach();
VOID	_calltype_ rwlThreadDetach();
PVOID	_calltype_ rwlAlloc();
VOID	_calltype_ rwlFree(PVOID p);
BOOL	_calltype_ rwlEnter(PVOID p,BOOL fExclusive,DWORD Timeout);
BOOL	_calltype_ rwlLeave(PVOID p,BOOL fExclusive);

////////////////// crc functions
DWORD	_calltype_		cfsCrc32(PBYTE p_buf,DWORD cb_buf);
VOID	_calltype_		cfsCrc32Start(PDWORD p_crc);
VOID	_calltype_		cfsCrc32End(PDWORD p_crc);
DWORD	_calltype_		cfsCrc32Append(DWORD crc,PBYTE p_buf,DWORD cb_buf);
#define	cfsCrc32Calc	cfsCrc32
WORD	_calltype_		cfsCrc16(WORD crc, PBYTE p_buf,DWORD cb_buf);

////////////////// random
/*DWORD	cfsPcgRandom(PVOID arena);
VOID	cfsPcgArenaNet(PVOID arena);*/

/////////// ifll
BOOL _calltype_ cfsCreateIFLLToken(
	LPSTR	uname,
	LPSTR	tok_uname,	//MAX_PWD_LEN
	LPSTR	tok_ch
);

BOOL _calltype_ cfsCreateIFLLTokenNC(
	LPSTR	uname,
	LPSTR	tok_uname,	//MAX_PWD_LEN
	LPSTR	tok_ch
);

BOOL _calltype_ cfsCheckIFLLToken(
	LPSTR	uname,
	LPSTR	tok_uname,	//MAX_PWD_LEN
	LPSTR	tok_ch
);
////////////////// string func
BOOL	cfsSrvStrPropActual(DWORD pr);
BOOL	cfsSrvStrTxtPropActual(LPSTR s);

////////////////// random
VOID cfsInitRandom();

////////////////// bits
DWORD cfsBSF32(DWORD dw);
DWORD cfsBSF64(u64 dw);

LPSTR cfsGetGetDirReplacementIni();
////////////////// ssec

#define	SLOG_TAG_TYPE			'\x1'
#define	SLOG_TAG_BODY			'\x2'
#define	SLOG_TAG_USER			'\x3'
#define	SLOG_TAG_TIME			'\x4'
#define	SLOG_TAG_INDEX			'\x5'
#define	SLOG_TAG_SOURCE			'\x6'
#define	SLOG_TAG_THID			'\x7'
#define	SLOG_TAG_SESID			'\x8'
#define	SLOG_TAG_FINDX			'\x9'
#define	SLOG_TAG_INFTYPE		'\xa'


#define	SLOG_MT_ERROR				'0'
#define	SLOG_MT_NORMAL				'1'
#define	SLOG_MT_UERR				'2'
#define	SLOG_MT_END					'3'

#define PFX_FIA_AFL		"/a=FIA_AFL/"
#define PFX_FIA_AFL_1	"/a=FIA_AFL.1/"
#define PFX_FIA_UAU_1	"/a=FIA_UAU.1/"
#define PFX_FIA_UAU_2	"/a=FIA_UAU.2/"
#define PFX_FIA_UID		"/a=FIA_UID/"
#define PFX_FAU_GEN_1	"/a=FAU_GEN.1/"
#define PFX_FAU_SAR_1	"/a=FAU_SAR.1/"
#define PFX_FAU_STG_3	"/a=FAU_STG.3/"
#define PFX_FDP_ITC_1	"/a=FDP_ITC.1/"
#define PFX_FDP_ROL		"/a=FDP_ROL/"
#define PFX_FMT_MTD_1	"/a=FMT_MTD.1/"
#define PFX_FMT_SMF_1	"/a=FMT_SMF.1/"
#define PFX_FMT_SMR_1	"/a=FMT_SMR.1/"
#define PFX_FPT_STM_1	"/a=FPT_STM.1/"
#define PFX_FPT_TST_1	"/a=FPT_TST.1/"
#define PFX_FTA_SSL_1	"/a=FTA_SSL.1/"

#define	SLOG_F_ADM					0x00000001
#define	SLOG_F_ERR					0x00000002
#define	SLOG_F_HARDERR				0x00000004
#define	SLOG_F_NO_MASTER_LOG		0x40000000
#define	SLOG_F_LOCALLY				0x80000000

#define	UINI_RESTORE_SKIP_GLOBALS	0x01
#define	UINI_RESTORE_PLAIN_INI		0x02

#ifdef CFS_OWNCOMMON



typedef	BOOL	(*	CFS_AMTLP)(
	DWORD	flags,
	LPSTR	text,
	DWORD	sesid,
	LPSTR	uname,
	LPSTR	source,
	LPSTR	thid
);

#define	CFS_SSBFC_LOG_ALLOWED	0
#define	CFS_SSBFC_GET_CLI_INST	1

typedef BOOL	(*CFS_SSBFUN)(
	DWORD	fncode,
	PVOID	p_in,
	PVOID	p_out
);

typedef	VOID (*CFS_SSLA)(LPSTR s);

typedef	struct	_SSEC_LOGSCAN{
	struct	_SSEC_LOGSCAN* next;
	BOOL	dir;
	PVOID	p_slf;
}SSEC_LOGSCAN;


typedef struct {

	DWORD	LogonCnt_OK;
	DWORD	LogonCnt_Failed;

	DWORD	UiniSave_Count;
	DWORD	UiniSave_Time;

	DWORD	UiniInteg_OK;
	DWORD	UiniInteg_Failed;

	DWORD	MainInteg_OK;
	DWORD	MainInteg_Failed;

	DWORD	SecInteg_OK;
	DWORD	SecInteg_Failed;

	DWORD	LastInteg_Time;

	DWORD	LastSecLogWrite_Time;
	DWORD	LastAdmLogWrite_Time;

	DWORD	Reserved[32];

}SCADASEC_STATS;

extern SCADASEC_STATS	ScadaSec_Stats;
extern BOOL				ScadaSec_FeatState;

typedef struct {
	DWORD	dwSize;

	VOID	(*ssec_Deinit)();
	VOID	(*ssec_FreeMemory)(LPSTR p);

	BOOL	(*ssec_StartLogs)(PVOID	Unique_in,	DWORD	Pincode_in);
	BOOL	(*ssec_StopLogs)();
	DWORD	(*ssec_GetSecurityType)();
	VOID	(*ssec_LogAuditMessage)(DWORD	flags,LPSTR	text,DWORD sesid,LPSTR	uname,LPSTR	source,LPSTR thid );
	VOID	(*ssec_UserAuditMessage)(DWORD	flags,DWORD sesid,LPSTR username,LPSTR text);

	u64		(*ssec_LogStartScan)(SSEC_LOGSCAN** root,BOOL dir,DWORD log_idx,DWORD index);
	BOOL	(*ssec_LogDoScan)(SSEC_LOGSCAN** root,u64 u_scan,LPSTR* p_msg);
	BOOL	(*ssec_LogEndScan)(SSEC_LOGSCAN** root,u64 u_scan);

	u64		(*ssec_LocalLogOpen)(LPSTR fname,LPSTR pwd);
	BOOL	(*ssec_LocalLogScan)(u64 u_scan,LPSTR* p_msg);
	VOID	(*ssec_LocalLogEndScan)(u64 u_scan);


	LPSTR	(*ssec_CheckInstallationIntegrityManually)(LPSTR ext_list,LPSTR rootsig);
	VOID	(*ssec_IntegrityCheckerStart)();
	VOID	(*ssec_IntegrityCheckerStop)();

	BOOL	(*ssec_UiniInitAccess)();
	BOOL	(*ssec_UiniCleanupReinit)();

	BOOL	(*ssec_UiniSetBin)(LPSTR uname,LPSTR oname,LPSTR dname,PBYTE p_data,DWORD dlen);
	DWORD	(*ssec_UiniGetBin)(LPSTR uname,LPSTR oname,LPSTR dname,PBYTE p_buf,DWORD cb_buf);
	DWORD	(*ssec_UiniGetDword)(LPSTR sec,LPSTR oname,LPSTR dname,DWORD def);
	VOID	(*ssec_UiniSetDword)(LPSTR sec,LPSTR oname,LPSTR dname,DWORD value);

	LPSTR	(*ssec_UiniReadString)(LPSTR uname,LPSTR keyname);
	BOOL	(*ssec_UiniWriteString)(LPSTR uname,LPSTR keyname, LPSTR value);
	BOOL	(*ssec_UiniWriteStringLen)(LPSTR uname,LPSTR keyname, LPSTR value, DWORD cb_data);

	BOOL	(*ssec_UiniDeleteUser)(LPSTR uname);
	BOOL	(*ssec_UiniEnumUsers)(LPSTR buf,DWORD cb_buf,BOOL b_comment);
	BYTE	(*ssec_UiniGetUserType)(LPSTR uname);
	BYTE	(*ssec_UiniGetPwdTypes)();
	DWORD	(*ssec_UiniGetSetAccessMask)(LPSTR uname,LPSTR oname,PDWORD pacc/*set it non-zero*/);
	DWORD	(*ssec_UiniGetAccess)(LPSTR uname,LPSTR oname,BOOL fExc,GENERIC_MAPPING* pGenMapping);


	VOID	(*ssec_ExpandPassword)(LPSTR buf,DWORD cb_buf);
	BOOL	(*ssec_UiniSetPassword)(LPSTR uname,LPSTR pwd);
	BOOL	(*ssec_UiniCheckPassword)(LPSTR uname,LPSTR digest);
	DWORD	(*ssec_UiniNeedChgPwd)(LPSTR uname);


	BOOL	(*ssec_UiniLogonResult)(DWORD sesid,LPSTR uname,PBYTE p_mac, DWORD c_mac,BOOL fOk,BOOL fCredLogon);
	VOID	(*ssec_UiniUserDisconnected)(DWORD sesid,LPSTR uname);
	BOOL	(*ssec_UiniCheckUserAllowed)(DWORD sesid,LPSTR uname,PBYTE p_mac, DWORD c_mac);

	LPSTR	(*ssec_UiniDoRestore)(DWORD sesid, LPSTR uname, LPSTR filename,LPSTR server_name_and_pfx,LPSTR pwd);
	LPSTR	(*ssec_UiniDoBackup)(DWORD sesid, LPSTR uname, LPSTR path,LPSTR tempdir,LPSTR server_name_and_pfx,LPSTR pwd);

	LPSTR	(*ssec_GetStats)();

	PVOID	obsolete;

	VOID	(*ssec_SetCommercialProtection)(DWORD code);

	VOID	(*ssec_GetUserSalt)(LPSTR uname, PBYTE salt/* 8 */);

	VOID	(*ssec_UiniGetFileTime)(FILETIME* ft);

	BYTE	(*ssec_UiniGetPwdTypesUser)(LPSTR name);

	BOOL	(*ssec_SetAutobackupPwd)(LPSTR pwd);


	PVOID	ssec_EndMarker;

}SCADASEC_FT;


SCADASEC_FT*	ssec_Init(
		PVOID	Unique_in,
		DWORD	Pincode_in,
		LPSTR	ProtectedPath_in,
		LPSTR	SourceName_in,
		__printf_func	eprh,
		__printf_func	mprh,
		__printf_func	dprh,
		CFS_AMTLP	Amptlp_In,
		CFS_SSLA	Ssla_In,
		LPSTR	ProductIni_In,
		LPSTR	CfsharePath_In,
		LPSTR	Cprt_In,
		PDWORD	pdwVer,
		CFS_SSBFUN		SSback_In,
		PVOID	Reserved15,
		PVOID	Reserved16
);

VOID	ssec_Deinit(void);

VOID	ssec_FreeMemory(LPSTR p);

//	security log functions

BOOL	ssec_StartLogs(
		PVOID	Unique_in,
		DWORD	Pincode_in
);
BOOL	ssec_StopLogs();
DWORD	ssec_GetSecurityType();
VOID	ssec_LogAuditMessage(DWORD	flags,LPSTR	text,DWORD sesid,LPSTR	uname,LPSTR	source,LPSTR thid );
VOID	ssec_UserAuditMessage(DWORD	flags,DWORD sesid,LPSTR username,LPSTR text);

u64		ssec_LogStartScan(SSEC_LOGSCAN** root,BOOL dir,DWORD log_idx,DWORD index);
BOOL	ssec_LogDoScan(SSEC_LOGSCAN** root,u64 u_scan,LPSTR* p_msg);
BOOL	ssec_LogEndScan(SSEC_LOGSCAN** root,u64 u_scan);

u64		ssec_LocalLogOpen(LPSTR fname,LPSTR pwd);
BOOL	ssec_LocalLogScan(u64 u_scan,LPSTR* p_msg);
VOID	ssec_LocalLogEndScan(u64 u_scan);


PVOID	ifss_alloc(DWORD dw_size);
VOID	ifss_free(PVOID p);
PVOID	ifss_realloc(PVOID p, DWORD dw_size);


//	intergrity functions
LPSTR	ssec_CheckInstallationIntegrityManually(LPSTR ext_list,LPSTR rootsig);
VOID	ssec_IntegrityCheckerStart();
VOID	ssec_IntegrityCheckerStop();




//////////	uini

BOOL	ssec_UiniInitAccess();
BOOL	ssec_UiniCleanupReinit();

BOOL	ssec_UiniSetBin(LPSTR uname,LPSTR oname,LPSTR dname,PBYTE p_data,DWORD dlen);
DWORD	ssec_UiniGetBin(LPSTR uname,LPSTR oname,LPSTR dname,PBYTE p_buf,DWORD cb_buf);
DWORD	ssec_UiniGetDword(LPSTR sec,LPSTR oname,LPSTR dname,DWORD def);
VOID	ssec_UiniSetDword(LPSTR sec,LPSTR oname,LPSTR dname,DWORD value);

LPSTR	ssec_UiniReadString(LPSTR uname,LPSTR keyname);
BOOL	ssec_UiniWriteString(LPSTR uname,LPSTR keyname, LPSTR value);
BOOL	ssec_UiniWriteStringLen(LPSTR uname,LPSTR keyname, LPSTR value, DWORD cb_data);

BOOL	ssec_UiniDeleteUser(LPSTR uname);
BOOL	ssec_UiniEnumUsers(LPSTR buf,DWORD cb_buf,BOOL b_comment);
BYTE	ssec_UiniGetUserType(LPSTR uname);
BYTE	ssec_UiniGetPwdTypes();
DWORD	ssec_UiniGetSetAccessMask(LPSTR uname,LPSTR oname,PDWORD pacc/*set it non-zero*/);
DWORD	ssec_UiniGetAccess(LPSTR uname,LPSTR oname,BOOL fExc,GENERIC_MAPPING* pGenMapping);


VOID	ssec_ExpandPassword(LPSTR buf,DWORD cb_buf);
BOOL	ssec_UiniSetPassword(LPSTR uname,LPSTR pwd);
BOOL	ssec_UiniCheckPassword(LPSTR uname,LPSTR digest);
DWORD	ssec_UiniNeedChgPwd(LPSTR uname);


BOOL	ssec_UiniLogonResult(DWORD sesid,LPSTR uname,PBYTE p_mac, DWORD c_mac,BOOL fOk,BOOL fCredLogon);
VOID	ssec_UiniUserDisconnected(DWORD sesid,LPSTR uname);
BOOL	ssec_UiniCheckUserAllowed(DWORD sesid,LPSTR uname,PBYTE p_mac, DWORD c_mac);


LPSTR	ssec_UiniDoRestore(DWORD sesid, LPSTR uname, LPSTR filename,LPSTR server_name_and_pfx,LPSTR pwd);
LPSTR	ssec_UiniDoBackup(DWORD sesid, LPSTR uname, LPSTR path,LPSTR tempdir,LPSTR server_name_and_pfx,LPSTR pwd);
VOID	ssec_UiniGetFileTime(FILETIME* ft);

LPSTR	ssec_GetStats();

VOID	ssec_SetCommercialProtection(DWORD code);

VOID	ssec_GetUserSalt(LPSTR uname, PBYTE salt/* 8 */);

BYTE	ssec_UiniGetPwdTypesUser(LPSTR name);
BOOL	ssec_SetAutobackupPwd(LPSTR pwd);

////
VOID	ssec_SaveUser(LPSTR user, LPSTR pwd, LPSTR where /*MAX_PWD_LEN*2*/);	//not serialized
BOOL	ssec_RecallUser(LPSTR user, DWORD user_len, LPSTR pwd, DWORD pwd_len,LPSTR where /*MAX_PWD_LEN*2*/);	//not serialized
//////////	digests
void		_CDECL cfsMD5(void *dest, void *orig, unsigned int len);
BOOL		cfsMD5Init(PVOID ct,DWORD dws);
VOID		cfsMD5Update(PVOID ct,PVOID data, DWORD cb_data);
VOID		cfsMD5Final(PVOID ct,PVOID dest);

#define		MD5	cfsMD5

LPSTR _CDECL SHA256_Data(PBYTE data, DWORD len, LPSTR buffer);
LPSTR _CDECL SHA512_Data(PBYTE data, DWORD len, LPSTR buffer);



//////////	security-encoding

DWORD	sec_EncSupported(BYTE en_t);	//returns required length of the key

DWORD	sec_EncBlockLen(BYTE en_t);

DWORD	sec_EncContextSize(BYTE en_t);

BOOL	sec_EncDecryptBlock(BYTE en_t,PVOID decrypt_ctx, PVOID block);

BOOL	sec_EncEncryptBlock(BYTE en_t,PVOID encrypt_ctx, PVOID block);

BOOL	sec_EncInitDecryptContext(BYTE en_t,PVOID* p_decrypt_ctx,PVOID en_k);

BOOL	sec_EncInitEncryptContext(BYTE en_t,PVOID* p_encrypt_ctx,PVOID en_k);


//////////	security log

VOID	Slog_Init(PVOID	key /*16*/);
VOID	Slog_FixerDone();

VOID	Slog_GarbageCollectorStart();
VOID	Slog_GarbageCollectorStop();

VOID	Slog_FixMessage(
	DWORD	flags,
	LPSTR	text,
	DWORD	sesid,
	LPSTR	user,
	LPSTR	source,
	LPSTR	thid
);

VOID	Slog_DeleteAllLogs();

//////////	pwdstr

BOOL	PwdStr_Init();
VOID	PwdStr_Deinit();

extern	LPSTR	ScadaSec_SourceName;

extern LPSTR litTmservDll;
extern LPSTR litRbaseDll;
//////////	end uini
#endif

 
/////////////////////////////////////////

#endif //_PC_CFSCOMMON_H



