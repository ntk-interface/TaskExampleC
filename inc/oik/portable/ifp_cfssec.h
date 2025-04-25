#ifndef _IFP_CFSSEC_H
#define _IFP_CFSSEC_H

// --------------

#define CFS_FEATCODE_TERMINATOR		0
#define CFS_FEATCODE_EXPIRATION		1
#define CFS_FEATCODE_TELEPARMS		2
#define CFS_FEATCODE_MAXUSERS		3
#define CFS_FEATCODE_HOTRES			4
#define CFS_FEATCODE_UPDLIMIT		5
#define CFS_FEATCODE_USEMODUS		6
#define CFS_FEATCODE_USE_SPA		7
#define CFS_FEATCODE_USE_IEC101		8
#define CFS_FEATCODE_USE_IPC		9
#define CFS_FEATCODE_MAGAZINE		10
#define CFS_FEATCODE_CR_TIME		11
#define CFS_FEATCODE_PLCDIR			12
#define CFS_FEATCODE_USE_IEC103		13
#define CFS_FEATCODE_USE_OPC		14
#define CFS_FEATCODE_USE_SMSGATE	15
#define CFS_FEATCODE_USE_IEC850		16
#define CFS_FEATCODE_USE_SQLGATE	17
#define CFS_FEATCODE_ARIS_SCADA		18
#define CFS_FEATCODE_WEB_CLIENT		19
#define CFS_FEATCODE_AAN			20
#define CFS_FEATCODE_PIN			21
#define CFS_FEATCODE_PLATFORM		22
#define	CFS_FEATCODE_ATI_SCADA		23
#define	CFS_FEATCODE_USE_DNP3		24
#define	CFS_FEATCODE_SCADASEC		25
#define	CFS_FEATCODE_TOTPARMS		26
#define	CFS_FEATCODE_VERSION		27
#define CFS_FEATCODE_LOCCLIENT		28
#define CFS_FEATCODE_USE_DLMS		29
#define CFS_FEATCODE_USE_CLI_10		30
#define CFS_FEATCODE_USE_WCLI_10	31
#define CFS_FEATCODE_USE_CLIENT		32
#define CFS_FEATCODE_LICNUM			1024


#define CFS_FEATCODE_TERMINATION	0xf0001


#define CFS_FEAT_OK	 1
#define CFS_FEAT_NO	 0
#define CFS_FEAT_WAIT -1
#define CFS_FEAT_ERR -2

#define CFS_EC_NO_COMM					0
#define CFS_EC_CANNOT_OPEN_COM			1
#define CFS_EC_NO_IBUTTON				2
#define CFS_EC_CANNOT_READ				3
#define CFS_EC_KEY_MISMATCH				4
#define CFS_EC_THREAD					5
#define CFS_EC_TIMEOUT					6
#define CFS_EC_FILE						7
#define CFS_EC_NO_MEMORY				8
#define CFS_EC_INTERNAL					9
#define CFS_EC_CHECKSUM					10
#define CFS_EC_ILLUPDATE				11
#define CFS_EC_OLDFILE					12
#define	CFS_EC_BAD_TIME					13
#define	CFS_EC_ANNULED					14
#define	CFS_EC_SHARING					15
#define	CFS_EC_VERSION					16

#define CFS_EC_TOO_MANY_USERS			101
#define CFS_EC_EXPIRATION_DATE			102
#define CFS_EC_TOO_MANY_TELEPARAMETERS	103
#define CFS_EC_NO_RESERVATION			104
#define CFS_EC_HL_NO_KEY				105
#define CFS_EC_NO_ARIS_SCADA			106


#define CFS_FFL_EXPIRATION		1
#define CFS_FFL_BADTIME			2

#ifndef DLS_SF_DEFINED
//#pragma pack(1)
#define DLS_SF_DEFINED 1
typedef struct {
	DWORD prp;
	DWORD val;
	DWORD n_prp;
	DWORD n_val;
}DLS_SEC_PROP;
typedef struct {
	BYTE randomizer[8];
	BYTE str[32];
	BYTE passwords[3][8];
	BYTE privtpass[8];
	BYTE signature[8];
}DLS_SEC_FILE;
//#pragma pack()
#endif //DLS_SF_DEFINED

typedef VOID (_CDECL* CFS_FEAT_CALLBACK)(BOOL fSuccess,PBYTE bid);




VOID	featOutputError(DWORD code);
VOID	featKeyErrorFatal(DWORD kerr);
INT		featGetValue(DWORD Feat,PDWORD pValue);
VOID	featSetCallback(PVOID cback,PVOID pinst,BOOL f_set);
LPSTR	cfsGetFeatReport();
PDWORD	_CDECL cfsFeatGetPs();



DWORD	keyGetPort		();
PVOID	keyOpenPort		();
BOOL	keyReadId		(PVOID	KeyPort,PBYTE id);
BOOL	keyReadSubkey	(PVOID	KeyPort,BYTE block,	PBYTE pwd,PBYTE id,PBYTE data);
VOID	keyClosePort	(PVOID	KeyPort);
BOOL	keyReactivateKey(BOOL fCheck);
LPSTR	_STDCALL	_keyGetParms();
DWORD	_STDCALL	_keyGetReadSeqNum();
VOID	_STDCALL	_keySaveReadSeqNum(DWORD rsn);

/*
DWORD ifpcMakeSid(
	PVOID pbuf,
	DWORD auth,
	DWORD sa1,
	DWORD sa2,
	DWORD sa3,
	DWORD sa4,
	DWORD sa5,
	DWORD sa6,
	DWORD sa7,
	DWORD sa8,
	DWORD sa9,
	DWORD sa10
);
BOOL ifpcIsValidSid(PVOID psid);
DWORD ifpcGetLengthSid(PVOID psid);
BOOL ifpcEqualSid(PVOID psid1,PVOID psid2);
*/
#define	IF_SECTYPE_DEFAULT		0
#define	IF_SECTYPE_EXP			1
#define	IF_SECTYPE_NAT			2

#define CPRT_FIRM			0
#define CPRT_C_FIRM			1
#define CPRT_CPRT			2
#define CPRT_FIRM_E			3
#define CPRT_MAIN_SWNAME	4
#define CPRT_PHONE_FAX		5
#define CPRT_LIC_SECTION	6

#define CPRT_NATIVE			1000


CFS_INIT_DATA*	cfsInitApp();
LPSTR	cfsMakeInprocCrd(LPSTR machine, LPSTR user, LPSTR pwd);
BOOL	cfsDecInprocCrd(LPSTR crd,LPSTR machine,LPSTR user,LPSTR pwd);

BOOL  ntabGetName(DWORD idx,LPSTR Buf,DWORD cbBuf);

////// INI
#define		INI_OPENEX_CACHE	0x100
PVOID _calltype_ ini_OpenEx(LPSTR name,DWORD en_t, PBYTE en_k);
DWORD _calltype_ ini_GetFlags(PVOID pf);
VOID _calltype_ ini_CloseWithoutSaving(PVOID pf);
/////// 

#define PWDPOL_UPPER		0x00000001
#define PWDPOL_DIGITS		0x00000002
#define PWDPOL_SPEC			0x00000004
#define PWDPOL_CHK_REPT		0x00000008
#define PWDPOL_CHK_SEQ		0x00000010
#define PWDPOL_CHK_DICT		0x00000020
#define PWDPOL_CHK_CACHE	0x00010000

#define	PWDPOL_LEN_DEFAULT	8


#define CFS_SD_MAIN		0x80000000
#define CFS_SD_SERVER	0x80000001
typedef struct {
	DWORD ResourceType;
	struct {
		DWORD mask;
		CHAR eng[128];
		CHAR rus[128];
	}bit[32];
	struct {
		DWORD mask;
		CHAR eng[128];
		CHAR rus[128];
	}cplx[32];
	struct {
		DWORD mask;
		CHAR eng[128];
		CHAR rus[128];
	}audit[32];
	struct {
		CHAR eng[128];
		CHAR rus[128];
	}deflt;
	struct {
		CHAR eng[128];
		CHAR rus[128];
	}objtypename;
	GENERIC_MAPPING GenericMapping;
	CHAR name_prefix[128];
}CFS_ACCESS_DESCRIPTOR;

CFS_ACCESS_DESCRIPTOR*  cfsGetAccessDescriptor(LPSTR ini,LPSTR section);

typedef struct {
	BYTE		DoUserID;
	DWORD		MaxUserID;
    BYTE		DoGroup;
    BYTE		DoKeyID;
    BYTE		DoUserNick;
    BYTE		DoUserPwd;
    LPSTR		pRights;
	DWORD		recerved[512];
}CFS_EXT_SRVRT_DESCRIPTOR;

CFS_EXT_SRVRT_DESCRIPTOR*  cfsGetExtendedUserRightsDescriptor(LPSTR ini,LPSTR section,BOOL fCheck); 
VOID cfsInitSWF(LPSTR k);

//extern DWORD dwCfsSecurityType;


// --------------
#endif // _IFP_CFSSEC_H


