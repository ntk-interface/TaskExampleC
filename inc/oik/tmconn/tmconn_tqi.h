// Table Query Interface (TQI)

#ifndef _TMCONN_TQI_H
#define _TMCONN_TQI_H
/////////////////////////////////////////////////////////////////////////

#ifndef IF_PORTABLE

#ifdef _WIN64
typedef unsigned __int64 PTRUINT;
#elif defined _WIN32
typedef unsigned __int32 PTRUINT;
#endif

#endif

typedef PVOID		TQI_HANDLE;
typedef INT			TQI_RESULT;
typedef PTRUINT		TQI_Datum;

typedef enum tqiTableId
{
	TQI_TABLE_Invalid = 0,
	TQI_TABLE_CUR_TS,
	TQI_TABLE_CUR_TT,
	TQI_TABLE_CUR_TI,
	TQI_TABLE_RETRO_TS,
	TQI_TABLE_RETRO_TT,
	TQI_TABLE_RETRO_TI,
	TQI_TABLE_AAN,
	TQI_TABLE_EVENT_LOG,
	TQI_TABLE_EVENT_LOG_ELIX,
	TQI_TABLE_RETRO_LIST,
	TQI_TABLE_ALARMS,
	TQI_TABLE_EVENT_LOG_RB,
	TQI_TABLE_RTU,
	TQI_TABLE_CHN,
	TQI_TABLE_ALERTS,
	TQI_TABLE_AN_MICROSERIES,
	TQI_TABLE_EVENT_BLOCKS
}tqiTableId;

typedef enum tqiFieldId
{
	TQI_FIELD_Invalid = 0,

	/* common fields static*/
	TQI_FIELD_Name,				//string
	TQI_FIELD_TmType,			//word (TM_STATUS,TM_ANALOG etc)
	TQI_FIELD_TmTypeName,		//string
	TQI_FIELD_Tma,				//dword, serves as index for CUR, ALARMS
	TQI_FIELD_Chn,				//word
	TQI_FIELD_Rtu,				//word
	TQI_FIELD_Point,			//word
	TQI_FIELD_Class,			//word
	TQI_FIELD_Group,			//word
	TQI_FIELD_TmaWithType,		//unsigned64, used in TQI_TABLE_EVENT_LOG, TQI_TABLE_EVENT_LOG_ELIX, TQI_TABLE_ALERTS,TQI_TABLE_EVENT_BLOCKS


	/* common fields - have different meanings for different tables*/
	TQI_FIELD_Flags				=50,//dword
	TQI_FIELD_UpdateTime,		//uxtime (millisec64), serves as index for EVENT_LOG, RETRO,AAN

	/* specific to all CUR values */
	TQI_FIELD_CUR_start			=100,
	TQI_FIELD_ChangeTime,		//uxtime (millisec64)
	TQI_FIELD_TmTime,			//uxtime (millisec64)
	TQI_FIELD_ExFlags,			//dword
	TQI_FIELD_Flags2,			//word
	TQI_FIELD_Provider,			//string, items separated by ';'


	/* specific to TS */
	TQI_FIELD_TS_start			=200,

	TQI_FIELD_TS_Code,			//byte
	TQI_FIELD_TS_S2,			//word
	TQI_FIELD_TS_Importance,	//byte
	TQI_FIELD_TS_StateText,		//string
	TQI_FIELD_TS_NormalState,	//byte

	TQI_FIELD_TS_Cl_Name		=250,		//string
	TQI_FIELD_TS_Cl_GenAck,		//bool	- general acknowledge sensitivity
	TQI_FIELD_TS_Cl_Unack0,		//bool	- set unacked when zero
	TQI_FIELD_TS_Cl_Unack1,		//bool	- set unacked when nonero
	TQI_FIELD_TS_Cl_Text0,		//string
	TQI_FIELD_TS_Cl_Text1,		//string
	TQI_FIELD_TS_Cl_TextBreak,	//string - for S2_BREAK
	TQI_FIELD_TS_Cl_TextMalfun,	//string - for S2_MALFUNCTION
	TQI_FIELD_TS_Cl_FLA_Name,	//string
	TQI_FIELD_TS_Cl_FLB_Name,	//string
	TQI_FIELD_TS_Cl_FLC_Name,	//string
	TQI_FIELD_TS_Cl_FLD_Name,	//string
	TQI_FIELD_TS_Cl_FLA_Text0,	//string
	TQI_FIELD_TS_Cl_FLA_Text1,	//string
	TQI_FIELD_TS_Cl_FLB_Text0,	//string
	TQI_FIELD_TS_Cl_FLB_Text1,	//string
	TQI_FIELD_TS_Cl_FLC_Text0,	//string
	TQI_FIELD_TS_Cl_FLC_Text1,	//string
	TQI_FIELD_TS_Cl_FLD_Text0,	//string
	TQI_FIELD_TS_Cl_FLD_Text1,	//string

	/* specific to TT */
	TQI_FIELD_TT_start			=300,
	TQI_FIELD_TT_Value,			//float4
	TQI_FIELD_TT_Code,			//int16
	TQI_FIELD_TT_Units,			//string
	TQI_FIELD_TT_Format,		//string
	TQI_FIELD_TT_Mult,			//float4
	TQI_FIELD_TT_Shift,			//float4

	TQI_FIELD_TT_Cl_Name		=350,		//string
	TQI_FIELD_TT_Cl_MinVal,		//float4
	TQI_FIELD_TT_Cl_MaxVal,		//float4
	TQI_FIELD_TT_Cl_Aperture,	//float4

	TQI_FIELD_TT_MS_Times,		//unixtime array
	TQI_FIELD_TT_MS_Sflgs,		//int8 array 
	TQI_FIELD_TT_MS_Values,		//float4 array
	TQI_FIELD_TT_MS_Intv,		//word

	TQI_FIELD_TT_TPR_Nominal,	//float4
	TQI_FIELD_TT_TPR_MinVal,	//float4
	TQI_FIELD_TT_TPR_MaxVal,	//float4
	TQI_FIELD_TT_TPR_ZoneDLow,	//float4
	TQI_FIELD_TT_TPR_ZoneCLow,	//float4
	TQI_FIELD_TT_TPR_ZoneCHigh,	//float4
	TQI_FIELD_TT_TPR_ZoneDHigh,	//float4
	TQI_FIELD_TT_TPR_AlrPresent,//bool
	TQI_FIELD_TT_TPR_AlrInUse,	//bool
	TQI_FIELD_TT_TPR_AlrID,		//byte

	/* specific to TI */
	TQI_FIELD_TI_start			=400,
	TQI_FIELD_TI_Value,			//float4
	TQI_FIELD_TI_Load,			//float4
	TQI_FIELD_TI_Units,			//string
	TQI_FIELD_TI_Format,		//string
	TQI_FIELD_TI_CounterFormat,	//string
	TQI_FIELD_TI_Mult,			//float4
	TQI_FIELD_TI_LoadMult,		//float4
	TQI_FIELD_TI_DifInterval,	//word
	TQI_FIELD_TI_DType,			//word

	/* specific to RETRO */
	TQI_FIELD_RETRO_start		=500,
	TQI_FIELD_RETRO_NumRetro,	//word

	/* specific to AAN */
	/* additional: common fields+ TT fields */
	TQI_FIELD_AAN_start			=600,
	TQI_FIELD_AAN_ElType,		//byte
	TQI_FIELD_AAN_AAFlags,		//byte
	TQI_FIELD_AAN_Interval,		//DWORD

	/* specific to EVLOG */
	/* additional: common fields +
		TQI_FIELD_TS_Code,
		TQI_FIELD_TS_S2
		TQI_FIELD_TT_Value
		TQI_FIELD_ALRM_AlarmId
		TQI_FIELD_ALRM_Active,
		TQI_FIELD_TmaWithType,
		TQI_FIELD_ALRM_Value,
	*/
	TQI_FIELD_EVLOG_start		=700,
	TQI_FIELD_EVLOG_RecType,	//word
	TQI_FIELD_EVLOG_RecTypeName,//string
	TQI_FIELD_EVLOG_State,		//byte
	TQI_FIELD_EVLOG_CmdResult,	//byte
	TQI_FIELD_EVLOG_StateText,	//string
	TQI_FIELD_EVLOG_Elix,		//binary 16 bytes
	TQI_FIELD_EVLOG_FixTime,	//uxtime (millisec64)
	TQI_FIELD_EVLOG_Text,		//string
	TQI_FIELD_EVLOG_UserName,	//string
	TQI_FIELD_EVLOG_ExtKind,	//word
	TQI_FIELD_EVLOG_ExtSource,	//word
	TQI_FIELD_EVLOG_ExtBinary,	//bin variable bytes
	TQI_FIELD_EVLOG_TS_AddFlags,//byte
	TQI_FIELD_EVLOG_AckTime,	//uxtime
	TQI_FIELD_EVLOG_AckUser,	//string
	TQI_FIELD_EVLOG_Importance,	//byte
	TQI_FIELD_EVLOG_OldFlags,	//dword

	/* specific to RETRO list*/
	/* no common fields */
	TQI_FIELD_RLIST_start		=800,
	TQI_FIELD_RLIST_Type,		//word
	TQI_FIELD_RLIST_Name,		//string
	TQI_FIELD_RLIST_Descrition,	//string
	TQI_FIELD_RLIST_Avg,		//bool
	TQI_FIELD_RLIST_Period,		//dword
	TQI_FIELD_RLIST_Maxrec,		//dword
	TQI_FIELD_RLIST_NumRetro,		//dword
	TQI_FIELD_RLIST_StartTime,	//uxtime (millisec64)
	TQI_FIELD_RLIST_EndTime,	//uxtime (millisec64)
	TQI_FIELD_RLIST_Megabytes,	//dword

	/* specific to alarms */
	/*	common fields: TQI_FIELD_Tma,TQI_FIELD_Chn,TQI_FIELD_Rtu,TQI_FIELD_Point*/
	TQI_FIELD_ALRM_start		=900,
	TQI_FIELD_ALRM_AlarmName,	//string
	TQI_FIELD_ALRM_AlarmId,		//byte
	TQI_FIELD_ALRM_GroupId,		//byte
	TQI_FIELD_ALRM_Value,		//float4
	TQI_FIELD_ALRM_Expression,	//string


	TQI_FIELD_ALRM_Sign,		//byte
	TQI_FIELD_ALRM_Seconds,		//byte
	TQI_FIELD_ALRM_FiltType,	//byte

	TQI_FIELD_ALRM_Active,		//bool
	TQI_FIELD_ALRM_InUse,		//byte;
	TQI_FIELD_ALRM_Importance,	//byte

	TQI_FIELD_ALRM_Period,		//word
	TQI_FIELD_ALRM_DayMap,		//binary 6 bytes
	TQI_FIELD_ALRM_WeekMap,		//byte
	TQI_FIELD_ALRM_YearMap,		//binary 6 bytes
	TQI_FIELD_ALRM_InDirect,	//byte
	TQI_FIELD_ALRM_CountDown,	//word
	TQI_FIELD_ALRM_CurVal,		//float4
	TQI_FIELD_ALRM_CmpVal,		//float4
	TQI_FIELD_ALRM_Param1,		//float4
	TQI_FIELD_ALRM_Param2,		//float4
	TQI_FIELD_ALRM_Param1Name,	//string
	TQI_FIELD_ALRM_Param2Name,	//string
	TQI_FIELD_ALRM_Type,		//byte

	/* specific to alerts */
	/*	common fields: TQI_FIELD_TmType,
		TQI_FIELD_Tma,
		TQI_FIELD_Chn,
		TQI_FIELD_Rtu,
		TQI_FIELD_Point,	
		TQI_FIELD_Class,
		TQI_FIELD_Group,
		TQI_FIELD_TmaWithType
	*/
	TQI_FIELD_ALERT_start		=1000,
	TQI_FIELD_ALERT_Id,			//binary 16 bytes 
	TQI_FIELD_ALERT_Improtance,	//byte
	TQI_FIELD_ALERT_Active,		//bool
	TQI_FIELD_ALERT_Unack,		//bool
	TQI_FIELD_ALERT_OnTime,		//uxtime (millisec64)
	TQI_FIELD_ALERT_OffTime,	//uxtime (millisec64)
	TQI_FIELD_ALERT_TypeName,	//string
	TQI_FIELD_ALERT_Name,		//string
	TQI_FIELD_ALERT_ValueText,	//string
	TQI_FIELD_ALERT_CurTime,	//uxtime (millisec64)
	TQI_FIELD_ALERT_CurValue,	//float4
	TQI_FIELD_ALERT_ActValue,	//float4
	TQI_FIELD_ALERT_AckUser,	//string
	TQI_FIELD_ALERT_AckTime,	//uxtime (millisec64)

	/* specific to analog micro series */
	/*	common fields: TQI_FIELD_Tma,TQI_FIELD_Chn,TQI_FIELD_Rtu,TQI_FIELD_Point*/
	TQI_FIELD_AN_MS_start		=1100,
	TQI_FIELD_AN_MS_Idx,		//word
	TQI_FIELD_AN_MS_Intv,		//word
	TQI_FIELD_AN_MS_Time,		//uxtime (millisec64)
	TQI_FIELD_AN_MS_Val,		//float4
	TQI_FIELD_AN_MS_Sflg,		//byte

	/* specific to event blocks */
	/*	common fields: TQI_FIELD_TmType,
		TQI_FIELD_Name,
		TQI_FIELD_TmType,
		TQI_FIELD_TmTypeName,
		TQI_FIELD_Tma,
		TQI_FIELD_Chn,
		TQI_FIELD_Rtu,
		TQI_FIELD_Point,	
		TQI_FIELD_Class,
		TQI_FIELD_Group,
		TQI_FIELD_TmaWithType,
	*/

	TQI_FIELD_EVBLK_start		=1120,
	TQI_FIELD_EVBLK_UnblkTime,	//uxtime (millisec64)

	/*	END*/
	TQI_FIELD_end,				//should be the last
}tqiFieldId;

/*	special request field ids	*/


typedef enum tqiFieldType
{
  TQI_FT_Invalid = 0,

  /* get by value */

  TQI_FT_Unsigned8,
  TQI_FT_Unsigned16,
  TQI_FT_Unsigned32,
  TQI_FT_Int8,
  TQI_FT_Int16,
  TQI_FT_Int32,
  TQI_FT_Bool,

  /* get by pointer */
  TQI_FT_ByPtr_start= 100,
  TQI_FT_Unsigned64,
  TQI_FT_Int64,
  TQI_FT_Float4,
  TQI_FT_Float8,
  TQI_FT_Unixtime,
  TQI_FT_CString,   /* NULL-terminated */
  TQI_FT_CharArray,
  TQI_FT_ByteArray,// конвертируется в SQL column bytea

  // john added 21.08.2020
  // tqi_getbinvalue возвращает size_in_bytes = размер массива в байтах
  TQI_FT_Int8Array,     // указатель на массив byte   // конвертируется в SQL column smallint[]
  TQI_FT_Int16Array,    // указатель на массив int16  // конвертируется в SQL column smallint[]
  TQI_FT_Int32Array,    // указатель на массив int32  // конвертируется в SQL column int[]
  TQI_FT_Float4Array,   // указатель на массив float4 // конвертируется в SQL column real[]
  TQI_FT_Float8Array,   // указатель на массив float8 // конвертируется в SQL column double[]
  TQI_FT_UnixtimeArray, // указатель на массив int64  // конвертируется в SQL column timestamp[]

}tqiFieldType;


typedef enum tqiOperatorType /* поле структуры tqiQueryCondition */
{
	/* operators with argument */
  TQI_OP_Invalid = 0,
	TQI_OP_EQ,
	TQI_OP_GT,
	TQI_OP_GT_EQ,
	TQI_OP_LT,
	TQI_OP_LT_EQ,
	TQI_OP_MASK_ALLBITS_1,
	TQI_OP_MASK_ANYBIT_1,
	TQI_OP_MASK_ALLBITS_0,
	TQI_OP_MASK_ANYBIT_0,
	TQI_OP_LIKE,

	/* operators with no argument */
	TQI_OP_IS_NULL,
	TQI_OP_LIST_AND,	/* список tqiQueryCondition, объединенный посредством AND. */
	TQI_OP_LIST_OR,		/* список tqiQueryCondition, объединенный посредством OR. */
} tqiOperatorType;

typedef struct tqiQueryCondition
{
  tqiOperatorType       op_type;
  BOOL                  op_type_not; /* apply NOT to op_type */

  tqiFieldId            field_id;
  DWORD					field_mask;

  /* operator argument */
  tqiFieldType          arg_type;
  TQI_Datum             arg_datum; /* либо значение, либо ссылка */
  BOOL                  arg_ispointer;
  BOOL                  arg_iscstring; /* NULL-terminated */
  int                   arg_size_in_bytes;

  /* вложенные условия, op_type IN  */
  struct tqiQueryCondition     *nested_conditions; /* массив */
  int                   nested_condition_count; /* количество */

}tqiQueryCondition;


/************/
#ifdef _TMCONN_H

TMC_IMPEX TQI_HANDLE _CDECL
tqi_create_query(
	DWORD cid,
	tqiTableId			table_id,
	tqiFieldId			*fields,
	int					fields_count,
    tqiQueryCondition   *conditions, /* joined by {AND|OR} */
    int                 conditions_count,
    BOOL                join_by_OR
);

/************/
TMC_IMPEX TQI_RESULT _CDECL
tqi_get_query_field_info(
	TQI_HANDLE			handle,
    int					field_no,
    tqiFieldType		*type
);

/************/
TMC_IMPEX TQI_RESULT _CDECL
		/*
		<0(error)
		0 (success, данных больше нет), >0(данные еще есть),
		1 (numrows_limit достигнут),
		2 (таймаут)
		3 (сервер ограничил выдачу)
		*/
tqi_fetch_all(
	TQI_HANDLE			handle,
    unsigned int		numrows_limit, /* ==0 no limit */
    unsigned int		fetch_timeout, /* ==0 no timeout,msec */
    unsigned int		*numrows
);

/************/
TMC_IMPEX TQI_RESULT _CDECL
		/*
		<0(error)
		0 (success, данных больше нет), >0(данные еще есть),
		1 (numrows_limit достигнут),
		2 (таймаут)
		3 (сервер ограничил выдачу)
		*/
tqi_fetch(
	TQI_HANDLE			handle,
    unsigned int		numrows_limit, /* ==0 no limit */
    unsigned int		fetch_timeout, /* ==0 no timeout,msec */
    unsigned int		*numrows
);

/************/
TMC_IMPEX TQI_Datum _CDECL
tqi_getbinvalue(
	TQI_HANDLE			handle,
	unsigned int		row,
	int					field_no,
    BOOL				*isnull,
    BOOL				*ispointer,
    BOOL				*iscstring, /* NULL-terminated */
    int					*size_in_bytes
);

/************/
TMC_IMPEX TQI_RESULT _CDECL
tqi_free_query(
	TQI_HANDLE handle
);


/************/
TMC_IMPEX DWORD	 _CDECL			/* number of ids*/
tqi_get_field_list(
	DWORD cid,
	INT**	field_id_list,	//free by tmcFreeeMemory
	INT**	field_type_list	//free by tmcFreeeMemory
);

TMC_IMPEX LPSTR _CDECL
tqi_get_field_names(
	DWORD	cid,
	INT		table_id
);

/************/
TMC_IMPEX  void _CDECL
tqi_set_temp_path(LPSTR path);


#endif //_TMCONN_H
/////////////////////////////////////////////////////////////////////////
#endif //_TMCONN_TQI_H
