#ifndef		CFT_CFS_FUNS
#define		CFT_CFS_FUNS
#ifdef __cplusplus
extern "C" {
#endif

#define CFFLAG_XML		1

BOOL		_calltype_ cftNPropSet(CFT_HANDLE id,LPSTR szName,LPSTR szText);
BOOL 		_calltype_ cftNPropRemove(CFT_HANDLE id,LPSTR szName);
BOOL		_calltype_ cftNPropRemoveAll(CFT_HANDLE id);
LPSTR		_calltype_ cftNPropGetText(CFT_HANDLE id,LPSTR name,LPSTR buf,DWORD count);
LPSTR		_calltype_ cftNPropEnum(CFT_HANDLE id,DWORD idx,LPSTR buf,DWORD count);

BOOL 		_calltype_ cftNodeMove(CFT_HANDLE id,CFT_HANDLE destid,BOOL fCheck);
CFT_HANDLE	_calltype_ cftNodeInsertAfter(CFT_HANDLE id,LPSTR szText);
CFT_HANDLE	_calltype_ cftNodeInsertDown(CFT_HANDLE id,LPSTR szText);
CFT_HANDLE	_calltype_ cftNodeFindSubNode(CFT_HANDLE id,LPSTR name);
CFT_HANDLE	_calltype_ cftNodeClone(CFT_HANDLE id);

VOID 		_calltype_ cftNodeRemove(CFT_HANDLE id);
VOID 		_calltype_ cftNodeFreeTree(CFT_HANDLE id);
LPSTR		_calltype_ cftNodeGetName(CFT_HANDLE id,LPSTR buf,DWORD count);
CFT_HANDLE	_calltype_ cftNodeEnum(CFT_HANDLE id,DWORD idx);
CFT_HANDLE	_calltype_ cftNodeGetNext(CFT_HANDLE id);
CFT_HANDLE  _calltype_ cftNodeGetNextAll(CFT_HANDLE id);

CFT_HANDLE	_calltype_ cftNodeFind(CFT_HANDLE id,LPSTR name);
CFT_HANDLE	_calltype_ cftNodeEnumAll(CFT_HANDLE id,DWORD idx);
VOID 		_calltype_ cftNodeMarkDirty(CFT_HANDLE id);
VOID 		_calltype_ cftNodeMarkClean(CFT_HANDLE id);
BOOL 		_calltype_ cftNodeIsDirty(CFT_HANDLE id);
DWORD		_calltype_ cftNodeGetChangeCount(CFT_HANDLE id);
CFT_HANDLE	_calltype_ cftNodeGetParent(CFT_HANDLE id);


BOOL		_calltype_ cftNodeIsEnabled(CFT_HANDLE id);
VOID		_calltype_ cftNodeEnable(CFT_HANDLE id,BOOL fEnable);
VOID		_calltype_ cftNodeSetSilent(CFT_HANDLE id,BOOL fSilent);
BOOL		_calltype_ cftNodeIsSilent(CFT_HANDLE id);

BOOL		_calltype_ cftNodeInsertNodeAfter(CFT_HANDLE id,CFT_HANDLE nid);
BOOL		_calltype_ cftNodeInsertNodeDown(CFT_HANDLE id,CFT_HANDLE nid);

CFT_HANDLE	_calltype_ cftNodeNewTree();

u64			_calltype_ cftNodeGetChecksum(CFT_HANDLE id);
CFT_HANDLE	_calltype_ cftConfLoad(LPSTR fname,BOOL fNoFirstLev);

BOOL		_calltype_ cftConfSave(LPSTR fname,CFT_HANDLE tid,BOOL fFirstLev);


#define		CFT_OPT_ATTRS		0x00000001
VOID		_calltype_ cftNodeSetOptions(DWORD opt);

#ifdef		IF_PORTCORE
VOID		_calltype_ cftNodeSetAttrs(CFT_HANDLE id, PVOID digest,LPSTR name,DWORD dw_access,u64 utms);
BOOL		_calltype_ cftNodeGetAttrs(CFT_HANDLE id, PVOID digest,LPSTR name,PDWORD pdw_access,u64* p_uitms);
BOOL		_calltype_ cfsConfFileTouch(LPSTR fname);
#else
#define		cfsConfFileTouch(fname)
#endif


CHAR		getNPropChar(CFT_HANDLE tid,LPSTR prop, CHAR def);
BOOL		getNPropBool(CFT_HANDLE tid,LPSTR prop, BOOL def);
DWORD		getNPropDword(CFT_HANDLE tid,LPSTR prop,DWORD def);
float		getNPropFloat(CFT_HANDLE tid,LPSTR prop,float def);
DWORD		getNPropMinSec(CFT_HANDLE tid,LPSTR prop,DWORD minv,DWORD maxv,DWORD def);
BOOL		getNPropText(CFT_HANDLE tid,LPSTR prop,LPSTR buf, DWORD cb_buf);
PVOID		getNPropHexs(CFT_HANDLE tid,LPSTR prop,PDWORD plen);
DWORD		getNPropTma(CFT_HANDLE tid,LPSTR pname);
DWORD		getNPropTmas(CFT_HANDLE tid,LPSTR pname,PDWORD p_add_tma,PDWORD p_cb_add_tma);
BOOL		getNPropMac(CFT_HANDLE tid,LPSTR prop,PBYTE pmac);
BOOL		getNPropString(CFT_HANDLE tid,LPSTR pname,LPSTR buf,DWORD cb_buf,LPSTR def);
LPSTR		getNPropStr(CFT_HANDLE tid,LPSTR pname,LPSTR def);

extern		DWORD CftOpts;

#ifdef __cplusplus
}
#endif

#endif		//CFT_CFS_FUNS

