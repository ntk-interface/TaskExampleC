#ifndef _IFP_INI_H
#define _IFP_INI_H

#ifdef __cplusplus
extern "C" {
#endif

#define CFS_INI_COMMIT	1
#define CFS_INI_RELOAD	2

/////////////////
#if INI_SYSTEM
#define pR_IniFilesInit(x)					TRUE
#define pR_IniFilesDeinit()					TRUE		
#define pR_GetPrivateProfileString			GetPrivateProfileString
#define pR_GetPrivateProfileInt				GetPrivateProfileInt
#define pR_GetPrivateProfileStruct			GetPrivateProfileStruct
#define pR_GetPrivateProfileSectionNames	GetPrivateProfileSectionNames
#define pR_GetPrivateProfileSection			GetPrivateProfileSection
#define pR_WritePrivateProfileString		WritePrivateProfileString
#define pR_WritePrivateProfileInt			WritePrivateProfileInt
#define pR_WritePrivateProfileStruct		WritePrivateProfileStruct
#define pR_WritePrivateProfileSection		WritePrivateProfileSection
#define cfsIniCommit(bImmed)

#else
BOOL	cfsIniFilesInit(DWORD suid);
BOOL	cfsIniFilesDeinit();
VOID	cfsIniCommit(BOOL bImmediate);
VOID	cfsIniCommandFile(PVOID f,LPSTR fname,PVOID pf, DWORD cmd);
DWORD	cfsGetPrivateProfileString(LPSTR sec,LPSTR key,LPSTR Default,LPSTR Dest,DWORD cbDest,LPSTR fname);
INT		cfsGetPrivateProfileInt(LPSTR sec,LPSTR key,INT Default,LPSTR fname);
DWORD	cfsGetPrivateProfileStruct(LPSTR sec,LPSTR key,PVOID Dest,DWORD cbDest,LPSTR fname);
DWORD	cfsGetPrivateProfileSectionNames(LPSTR dest,DWORD cbdest,LPSTR fname);
DWORD	cfsGetPrivateProfileSection(LPSTR sec,LPSTR Dest,DWORD cbDest,LPSTR fname);
BOOL	cfsWritePrivateProfileString(LPSTR sec,LPSTR str,LPSTR value,LPSTR fname);
BOOL	cfsWritePrivateProfileInt(LPSTR sec,LPSTR str,INT value,LPSTR fname);
BOOL	cfsWritePrivateProfileStruct(LPSTR sec,LPSTR str,PVOID Struct,DWORD cbStruct,LPSTR fname);
BOOL	cfsWritePrivateProfileSection(LPSTR sec,LPSTR str,LPSTR fname);


#define pR_IniFilesInit						cfsIniFilesInit
#define pR_IniFilesDeinit					cfsIniFilesDeinit
#define pR_GetPrivateProfileString			cfsGetPrivateProfileString
#define pR_GetPrivateProfileInt				cfsGetPrivateProfileInt
#define pR_GetPrivateProfileStruct			cfsGetPrivateProfileStruct
#define pR_GetPrivateProfileSectionNames	cfsGetPrivateProfileSectionNames
#define pR_GetPrivateProfileSection			cfsGetPrivateProfileSection
#define pR_WritePrivateProfileString		cfsWritePrivateProfileString
#define pR_WritePrivateProfileInt			cfsWritePrivateProfileInt
#define pR_WritePrivateProfileStruct		cfsWritePrivateProfileStruct
#define pR_WritePrivateProfileSection		cfsWritePrivateProfileSection

#endif

PVOID	cfsConfGetParameter(LPSTR dir,LPSTR ini,LPSTR sec,LPSTR key,PDWORD pdwType,PDWORD pdwLen);
BOOL	cfsConfPutParameter(LPSTR dir,LPSTR ini, LPSTR sec,LPSTR key,DWORD dwType,PVOID pData,DWORD dwSize);

DWORD	cfsPrivateDwordEx(LPSTR fname,LPSTR secname,LPSTR keyname,DWORD def);
DWORD	cfsPrivateDword(LPSTR name,DWORD def);
BOOL	cfsPutPrivateDwordEx(LPSTR fname,LPSTR secname,LPSTR keyname,DWORD val);
BOOL	cfsPutPrivateDword(LPSTR name,DWORD val);
LPSTR	cfsPrivateString(LPSTR keyname,LPSTR def);
LPSTR	cfsPrivateStringEx(LPSTR fname,LPSTR secname,LPSTR keyname,LPSTR def);
BOOL	cfsPutPrivateString(LPSTR keyname,LPSTR str);
BOOL	cfsPutPrivateStringEx(LPSTR fname,LPSTR secname,LPSTR keyname,LPSTR str);
LPSTR	cfsPrivateMstring(LPSTR name);
BOOL	cfsPrivateWriteMstring(LPSTR name,LPSTR ms,DWORD len);

VOID	inifProcessAttach();
VOID	inifProcessDetach();



CFS_EXPORT	PVOID	_calltype_ ini_Open(LPSTR name);
CFS_EXPORT	VOID	_calltype_ ini_Close(PVOID pf);
CFS_EXPORT	BOOL	_calltype_ ini_Flush(PVOID pf);
CFS_EXPORT	BOOL	_calltype_ ini_CheckFile(PVOID pf);
CFS_EXPORT	VOID	_calltype_ ini_GetFileTime(PVOID pf,FILETIME* ft);
CFS_EXPORT	VOID	_calltype_ ini_Reload(PVOID pf);
CFS_EXPORT	DWORD	_calltype_ ini_ReadString(PVOID pf,LPSTR sec,LPSTR key,LPSTR Default,LPSTR Dest,DWORD cbDest);
CFS_EXPORT	INT		_calltype_ ini_ReadInteger(PVOID pf,LPSTR sec,LPSTR key,INT Default);
CFS_EXPORT	DWORD	_calltype_ ini_ReadStruct(PVOID pf,LPSTR sec,LPSTR key,PVOID Dest,DWORD cbDest);
CFS_EXPORT	DWORD	_calltype_ ini_ReadSection(PVOID pf,LPSTR sec,LPSTR Dest,DWORD cbDest);
CFS_EXPORT	DWORD	_calltype_ ini_EnumSections(PVOID pf,LPSTR Dest,DWORD cbDest);
CFS_EXPORT	BOOL	_calltype_ ini_WriteString(PVOID pf,LPSTR sec,LPSTR str,LPSTR value);
CFS_EXPORT	BOOL	_calltype_ ini_WriteInteger(PVOID pf,LPSTR sec,LPSTR str,INT value);
CFS_EXPORT	BOOL	_calltype_ ini_WriteStruct(PVOID pf,LPSTR sec,LPSTR str,PVOID Struct,DWORD cbStruct);
CFS_EXPORT	VOID	_calltype_ ini_EraseSection(PVOID pf,LPSTR sec);
CFS_EXPORT	BOOL	_calltype_ ini_ChangeEnc(PVOID pf, LPSTR name, BYTE en_t, PBYTE en_k);

#ifndef USE_CFSHARE_DLL
#define	cfsGetConfDword		cfsPrivateDword
//#define	cfsGetConfDwordEx	cfsPrivateDwordEx
#endif

#ifdef __cplusplus
}
#endif
#endif	//_IFP_INI_H