#ifndef _IFP_LOGMSG_H
#define _IFP_LOGMSG_H


#ifdef __cplusplus
extern "C" {
#endif

typedef void (_CDECL* __printf_func)(LPCSTR pformat,...);

VOID _CDECL e_printf(LPCSTR pformat,...);
VOID _CDECL m_printf(LPCSTR pformat,...);
VOID _CDECL d_printf(LPCSTR pformat,...);

VOID _CDECL e_cfsprintf(LPCSTR pformat,...);
VOID _CDECL m_cfsprintf(LPCSTR pformat,...);
VOID _CDECL d_cfsprintf(LPCSTR pformat,...);

VOID _CDECL ch_e_printf(LPCSTR pformat,...);
VOID _CDECL ch_m_printf(LPCSTR pformat,...);
VOID _CDECL ch_d_printf(LPCSTR pformat,...);

#ifdef __cplusplus
}
#endif

#endif //_IFP_LOGMSG_H
