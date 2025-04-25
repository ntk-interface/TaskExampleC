#ifndef _TMCONN_H
#define _TMCONN_H

#ifdef IF_PORTCORE
#define TMCONN_NEW 1
#endif


#ifndef  TMCONN_NEW
typedef unsigned __int64 u64;
#define _STDCALL    __stdcall
#define _CDECL      __cdecl
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
#ifndef __TIME_H
#include <time.h>
#endif
*/

#define ERROR_TM_NOT_CONNECTED 0xc0001
#define TM_KERNEL_SIGNATURE 0x0830

#ifndef INVALID
#define INVALID 0xffffffff
#endif



#define SUCCESS 1                 // Успешное завершение функции
#define FAILURE 0                 // Ошибка при обработке запроса

/*------------- Определения флагов доступа -----------------*/

#define TMS_ACCESS_TM_READ			0x00000001
#define TMS_ACCESS_STATUS_CHANGE	0x00000002
#define TMS_ACCESS_ANALOG_CHANGE	0x00000004
#define TMS_ACCESS_ACCUM_CHANGE		0x00000008
#define TMS_ACCESS_TELECONTROL		0x00000010
#define TMS_ACCESS_RETRO_VIEW		0x00000020
#define TMS_ACCESS_LOG_VIEW			0x00000040
#define TMS_ACCESS_ALARM_CHANGE		0x00000080
#define TMS_ACCESS_TM_SOURCE		0x00000100
#define TMS_ACCESS_TMSRC_DIALOG		0x00000200
#define TMS_ACCESS_TOB_CHANGE		0x00000400
#define TMS_ACCESS_BACKUP			0x00000800
#define TMS_ACCESS_TM_SUBS			0x00001000

#define TMS_GENERIC_READ	TMS_ACCESS_TM_READ

#define TMS_GENERIC_WRITE	(TMS_ACCESS_TM_READ|TMS_ACCESS_STATUS_CHANGE|TMS_ACCESS_ANALOG_CHANGE|TMS_ACCESS_ACCUM_CHANGE| \
 TMS_ACCESS_RETRO_VIEW|TMS_ACCESS_LOG_VIEW|TMS_ACCESS_ALARM_CHANGE|TMS_ACCESS_TMSRC_DIALOG)

#define TMS_GENERIC_EXECUTE	TMS_GENERIC_READ

#define TMS_GENERIC_ALL (TMS_GENERIC_WRITE|TMS_ACCESS_TELECONTROL|TMS_ACCESS_TM_SOURCE|TMS_ACCESS_TOB_CHANGE|TMS_ACCESS_BACKUP|TMS_ACCESS_TM_SUBS)

// -----------------------
#define RBS_ACCESS_READ				0x00000001
#define RBS_ACCESS_WRITE			0x00000002
#define RBS_ACCESS_BACKUP			0x00000004

#define RBS_GENERIC_READ			RBS_ACCESS_READ
#define RBS_GENERIC_WRITE			RBS_ACCESS_WRITE
#define RBS_GENERIC_EXECUTE			RBS_GENERIC_READ
#define RBS_GENERIC_ALL				(RBS_ACCESS_READ|RBS_ACCESS_WRITE|RBS_ACCESS_BACKUP)

/*------------- Определения флагов телепараметров -----------------*/
#define UNRELIABLE_HDW     0x0001   // Недостоверность аппаратная
#define UNRELIABLE_MANU    0x0002   // Недостоверность от пользователя
#define REQUESTED          0x0004   // Идет опрос
#define MANUALLY_SET       0x0008   // Установлено вручную
#define LEVEL_A            0x0010   // Сработала уставка первого уровня
#define LEVEL_B            0x0020   // ------- " ------- второго уровня
#define LEVEL_C            0x0040   // ------- " ------- третьего уровня
#define LEVEL_D            0x0080   // ------- " ------- четвертого уровня
#define INVERTED           0x0100   // ТС инвертируется при занесен
#define RESCHANNEL         0x0200	// Данные взяты с резервного канала
#define TMCTRL_PRESENT     0x0400	// Есть команда - volatile [ТС]
#define HAS_ALARM          0x0400	// Есть уставки - volatile [ТИТ]

#define STATUS_CLASS_APS   0x0800	// АПС [ТС]
#define AP_UNDER_CONTROL   0x0800   // Есть управление/регулирование [ТИТ]
#define TMSTREAMING        0x1000	// Передавать со временем
#define F_ABNORMAL         0x2000   // Отлично от нормального
#define F_UNACKED          0x4000   // Несквитирован
#define F_IV               0x8000   // 101 IV

#define F_INTERIM          0x02000000   // Промежуточное состояние

#define SF_CONFIG			 0x40000000
#define SF_INIT				 0x80000000

#define TM_F_FCH			 0x40000000	  //used in aggregator instead of SF_CONFIG	- flags change
#define TM_F_SLC			 0x80000000	  //used in aggregator instead of SF_INIT	- cycle


// S2
#define S2_BREAK			 0x0001		// разрыв?
#define	S2_MALFUNCTION		 0x0002		// неисправность датчиков?
#define	S2_INTERIM			 0x4000

// S2	Старший бит
#define S2_FLAGSONLY		 0x8000

////////////////////// TELEMETRY FLAGS 2 (WORD)
#define FL2_OUTDATED			0x0001		// устарел по времени
#define FL2_MANRETR				0x0002		// ретрансляция руч, устаонвок в ССПИ
#define FL2_MANBLOCK			0x0004		// ретрансляция блокировок в ССПИ
#define	FL2_IN_TM				0x0008		// принимался от ТМ
#define	FL2_IN_USER				0x0010		// принимался от пользователя
#define	FL2_IN_CALC				0x0020		// принимался от дорасчета
#define	FL2_IN_TMS				0x0040		// устанавливался самим сервером
#define	FL2_IN_EXPR				0x0080		// присваивался ч-з выражение
#define FL2_NONINTR_TC			0x0100		// возможно ТУ от автопроцесса
#define FL2_CTLBLOCK			0x0200		// ТУ заблокировано
#define FL2_REG_SET				0x0400		// Телерегулирование ТИИ установкой
#define FL2_REG_INC				0x0800		// Телерегулирование ТИИ инкрементами
#define FL2_ACTL				0x1000		// Вытолняется асинхронное ТУ
#define FL2_JITTER				0x2000		// Систематический дребезг


/*------------------------ Типы событий ---------------------------*/
#define evSTATUS_CHANGE      0x0001   // Телесигнал
#define evALARM              0x0002   // Уставка ТИТ
#define evCONTROL            0x0004   // Телеуправление
#define evACKNOWLEDGE		 0x0008
//#define evMANUAL_CONTROL     0x0008   // ТУ со щита
#define evMANUAL_STATUS_SET  0x0010   // Обозначение положения ТС
#define evMANUAL_ANALOG_SET  0x0020   // Ручная установка ТИТ
#define evFLAGS_CHANGE       0x0040   // Изменение флагов ТП
#define evREGULATION         0x0080

#define evEXT_LNK			 0x2000	  // Служебное значение - не использовать!
#define evEXT_FILE_LNK		 0x4000	  // Служебное значение - не использовать!
#define evEXTENDED			 0x8000	  // Расширенный формат
#define evMASK_EXTENDED		 0xe000

#define EXTEVL_KIND_STRBIN		0x100
#define EXTEVL_KIND_MODEL		0x200

#define EXTEVL_SOURCE_SERVER			0
#define EXTEVL_SOURCE_COMTRADE			1
#define EXTEVL_SOURCE_OMP				2
#define EXTEVL_SOURCE_AUTOSECT			3
#define EXTEVL_SOURCE_I850				50
#define EXTEVL_SOURCE_BLACK_BOX			90
#define EXTEVL_SOURCE_IEC101_MESSAGE	101
#define EXTEVL_SOURCE_AURA_FILE			102
#define EXTEVL_SOURCE_IEC103_MESSAGE	103
#define EXTEVL_SOURCE_SPA_MESSAGE		105
#define EXTEVL_SOURCE_MODBUS			106
#define EXTEVL_SOURCE_DNP3				107
#define EXTEVL_SOURCE_DLMS				108
#define EXTEVL_SOURCE_TMA_RELATED		109
#define EXTEVL_SOURCE_SNMP				161


#ifndef	FLAGS_IGNORE
#define FLAGS_IGNORE			0x00
#define FLAGS_SET				0x01
#define FLAGS_CLEAR				0x02
#define FLAGS_COPY				0x03
#define FLAGS_RESET				0x10
#define	CHANGE_ALWAYS			0x80
#endif

//////////////////////// SERVER CAPABILITIES
#define TMS_CAPS_SEQST				0
#define TMS_CAPS_ALRNEW				1
#define TMS_CAPS_COMTRADE			2
#define TMS_CAPS_EVLARCH			3
#define TMS_CAPS_SFBIEX				4
#define TMS_CAPS_FBFLAGS			5
#define TMS_CAPS_USERS				6
#define TMS_CAPS_EVLEXT				7
#define TMS_CAPS_LOGAUDIT			8
#define TMS_CAPS_RESVALEX			9
#define TMS_CAPS_MICROSERIES		10

#define TMS_CAPS_CFGT				120
#define TMS_CAPS_CNT				127

//////////////////////// TM-DATA TYPES
#define TM_STATUS			((WORD)0x8000)
#define TM_ANALOG			((WORD)0x8001)
#define TM_ACCUM			((WORD)0x8002)
#define TM_CONTROL			((WORD)0x8003)
#define TM_REGUL			((WORD)0x8004)
#define TM_STRING 			((WORD)0x8005)

#define TM_CHANNEL 			((WORD)0x9000)
#define TM_RTU 				((WORD)0x9001)

#define TM_RETRO_STATUS		((WORD)0x9010)
#define TM_RETRO_ANALOG		((WORD)0x9011)
#define TM_RETRO_ACCUM 		((WORD)0x9012)

#define TM_TAGGED_INFO		((WORD)0xff00)

#define TAGINF_SIMPLE		0


#define TMSV_PRFL_LINK				0x00000001
#define TMSV_PRFL_VSCRIPT			0x00000002

#define MAP_COMMAND_SUPPORTED		0
#define MAP_COMMAND_ACKNOWLEDGE		1
#define MAP_COMMAND_SET_BRIGHTNESS	2
#define MAP_COMMAND_ON_MODE			3
#define MAP_COMMAND_OFF_MODE		4
#define MAP_COMMAND_NORMAL_MODE		5
#define MAP_COMMAND_SET_BLINK_RATE	6
#define MAP_COMMAND_SHOW_UNDEFINED  7
#define MAP_COMMAND_DARK_MODE		8
#define MAP_COMMAND_STNORM_MODE		9
#define MAP_COMMAND_IND_ADDRESS		10




#define DNTT_DRIVER		'0'
#define DNTT_ADAPTER	'1'
#define DNTT_PORT		'2'
#define DNTT_RTU		'3'
#define DNTT_ARRAY		'4'
#define DNTT_BLOCK		'5'
#define DNTT_INFO		'6'
#define DNTT_FAILED		'9'

#define DNTERR_OK			0
#define DNTERR_THREAD		1
#define DNTERR_RESOURCE		2
#define DNTERR_MEMORY		3
#define DNTERR_UNKNOWN		100

////////////	Delta trace flags
#define DNT_TRACE_ERROR		0
#define DNT_TRACE_MSG		1
#define DNT_TRACE_DEBUG		2
#define DNT_TRACE_TM_IN		3
#define DNT_TRACE_TM_OUT	4
#define DNT_TRACE_S_IN		5
#define DNT_TRACE_S_OUT		6
#define DNT_TRACE_LOG		0x4000
#define DNT_TRACE_DRV		0x8000

////////////	TMS trace flags
#define TMS_TR_ERROR		0x0001
#define TMS_TR_MSG			0x0002
#define TMS_TR_DEBUG		0x0004
#define TMS_TR_TM_IN		0x0008
#define TMS_TR_TM_OUT		0x0010
////////////////////////////////

#define DNT_DRIVER_ETHERNET	1
#define DNT_DRIVER_COM		2

#ifndef TMS_BACKUP_
#define TMS_BACKUP_
#define TMS_BACKUP_CONFIG	1
#define TMS_BACKUP_ARRAY	2
#define TMS_BACKUP_EVLOG	4
#define TMS_BACKUP_ALARMS	8
#define TMS_BACKUP_RETRO	0x10
#define TMS_BACKUP_SECURITY	0x20
#endif

#define TMV_MAX_CLASSES		256

#ifndef RBS_BACKUP_
#define RBS_BACKUP_
#define RBS_BACKUP_BASES	1
#define RBS_BACKUP_SECURITY 2
#endif

#define DGM_DATASOURCE 			0x00000001
#define DGM_TRACEALL			0x00000002
#define DGM_TRACEDEF			0x00000004
#define DGM_TMNOTIFY			0x00000008
#define DGM_RETRANS				0x00000010
#define DGM_RETRANS_CHANGES		0x00000020
#define	DGM_RETRANS_STRBIN		0x00000040
#define	DGM_RETRANS_NOSTREAM	0x00000080
#define	EXTS_SHOW_S2			0x00000100
#define	DGM_TOB_CHANGE			0x00000200
#define	DGM_CALC				0x00000400
#define	DGM_TOB_RETRANS			0x00000800
#define DGM_DELTA				0x00001000
#define DGM_NEW_CLIENT			0x00002000

#define USER_DGM_FLAGS			(EXTS_SHOW_S2|DGM_TOB_CHANGE|DGM_NEW_CLIENT)


/*-------------------------------- * ------------------------------*/
#pragma pack(1)
typedef struct
	{
    short Ch;
    short RTU;
    short Point;
    } TADRtm;

typedef struct
	{
	WORD Type;
    WORD Ch;
    WORD RTU;
    WORD Point;
} TTMVAddr;

typedef struct
	{
	short Status;            // состояние объекта
	short Flags;             // флаги
	} TStatusPoint;			// Объект ТС

typedef struct
	{
	float asFloat;           // реальное значение ТИТ
	short asCode;            // код ТИТ, поступивший с ТМ
	short Flags;             // флаги
	CHAR  Unit[8];           // единицы измерения
	} TAnalogPoint;  // Объект ТИТ

typedef struct {
	float Value;
	short Flags;
}TAnalogPointShort;

typedef struct {
	DWORD fix_time;
	DWORD tm_time;
	WORD  chn;
	WORD  rtu;
	WORD  point;
	WORD  asCode;
	float asFloat;
	WORD  flags;
}TAnalogQueueRecord;

typedef struct {
	WORD	tm_type;
	WORD	Ch;
	WORD	RTU;
	WORD	Point;
	DWORD	unblk_ut;
}TPointEvBlock;

typedef struct {
	WORD level;
	WORD a[4];
	LPSTR name;
}TBaseObjectInfo;

typedef struct {
	TADRtm	a;
	BYTE type;
//	possible bits

#define VF_TYPE_STATUS				0x10
#define VF_TYPE_ANALOG_CODE			0x20
#define VF_TYPE_ANALOG_FLOAT		0x30
#define VF_TYPE_ACCUM_VALUE			0x40
#define VF_TYPE_ACCUM_CODE			0x50
#define VF_TYPE_ACCUM_INCREMENT		0x60
#define VF_TYPE_TELECTRL			0x70
#define VF_TYPE_ACCUM_FLOAT			0x80
#define VF_TYPE_ACCUM_DIRECT		0x90
#define VF_TYPE_ACCUM_FLT_DIRECT	0xa0
#define VF_TYPE_TC_ACK				0xb0
#define VF_TYPE_ANALOG_FLOATCODE	0xc0
#define VF_TYPE_REGULATION			0xd0

#define VF_FLG_IGNORE			0x00
#define VF_FLG_SET				0x01
#define VF_FLG_CLEAR			0x02
#define VF_FLG_COPY				0x03

#define VF_SIGNED				0x04
#define VF_ALWAYS_SET_VALUE		0x08

	BYTE					flags;
	BYTE					bits;

	union {
		BYTE				uchar;
		CHAR				schar;
		WORD				ushort;
		SHORT				sshort;
		DWORD           	ulong;
		INT	                slong;
		float				flt;
	};
}TValueAndFlags;

typedef struct {
	TValueAndFlags	vf;
	 WORD			s2;
} TVF_S2;

typedef struct {
	DWORD	sec;
	WORD	ms;
	WORD	flags;
#define TMXT_FLAG_GREENWICH		0x0001
#define TMXT_FLAG_CURDATA		0x0002
#define TMXT_FLAG_IV			0x0004
#define TMXT_FLAG_ZIMP			0x0008
#define TMXT_FLAG_USER			0x0010
#define TMXT_FLAG_MANRTR		0x0020
#define TMXT_FLAG_OFFSET		0x0040
#define TMXT_FLAG_NOSCRIPT		0x0080
#define TMXT_FLAG_TF_RES1		0x0100
#define TMXT_FLAG_TF_IV			0x0200


}TMXTime;

typedef struct {
	TValueAndFlags	vf;
	TMXTime			xt;
}TTimedValueAndFlags;

#define _TMSVX_TIMED	1
#define _TMSVX_S2		2
#define _TMSVX_ID		4
#define _TMSVX_EXF		8

typedef struct {
	WORD			Ch;
	WORD			RTU;
	WORD			Point;		//6
	DWORD			Value;		//10
	DWORD			sec;			//14
	BYTE			hund;		//15
    BYTE			DataType;	//16
}TTimedAccum;
typedef struct {
	WORD			Ch;
	WORD			RTU;
	WORD			Point;		//6
	DWORD			sec;			//10
	BYTE			hund;		//11
	BYTE			flags_type;	//12
    WORD			DataType;	//14
	BYTE			Data[16];	//30
}TTimedAccumEx;
typedef struct {
	WORD			Ch;
	WORD			RTU;
	WORD			Point;		//6
	DWORD			sec;		//10
	BYTE			hund;		//11
	BYTE			flags_type;	//12
    WORD			DataType;	//14
#define ACCFLG_INC		1
#define ACCFLG_DIRECT	2
	WORD			AccFlags;	//16
	BYTE			Data[16];	//32
}TAccumData;

typedef struct
    {
    WORD			Point;
    BYTE			RTU;
    BYTE			Ch;
	BYTE			GroupId;
	BYTE			AlarmId;
	float 			Value;
	WORD			Sign		:1;
	WORD			Sensibility	:7;
	WORD			Active		:2;
	WORD			InUse		:1;
	WORD			Zonal		:1;
	WORD			Importance	:4;
	WORD			Period;
	BYTE			DayMap[6];
	BYTE			WeekMap;
	BYTE			YearMap[6];
	BYTE			InDirect;
	WORD			CountDown;
	double 			Sum;
    } TAlarm;
#define ALARM_FILTER_DEFAULT	0
#define ALARM_FILTER_IIR_1		1
typedef struct
    {
    WORD			Point;
    BYTE			RTU;
    BYTE			Ch;
	BYTE			GroupId;
	BYTE			AlarmId;
	float 			Value;
	WORD			Sign		:1;
	WORD			Seconds		:3;
	WORD			FiltType	:4;
	WORD			Active		:2;	//modified by server
	WORD			InUse		:1;
	WORD			Zonal		:1;
	WORD			Importance	:4;
	WORD			Period;
	BYTE			DayMap[6];
	BYTE			WeekMap;
	BYTE			YearMap[6];
	BYTE			InDirect;
	WORD			CountDown;	//modified by server
	double 			Sum;		//modified by server

	BYTE			cRes[16];
	float			Param[2];
	DWORD	        lRes[6];

    } TAlarmNew;

typedef struct {
	float			Param;
	CHAR			ParamName[128];
	} TAlarmParam;

typedef struct {
	unsigned		short	bit_fields;
	float					cur_val;
	float					comp_val;

	} TAlarmState;

typedef struct
	{
	float Value;             // значение счетчика
	float Load;              // нагрузка
	short Flags;             // фла
	CHAR Unit[8];            // единицы измерения
	} TAccumPoint;   // Объект ТИИ


typedef struct {
	DWORD	sec;
	BYTE	hund;
	BYTE	ms;
}TTmsTime;

#define TMCPF_NAME		0x01
#define TMCPF_ALLFLAGS	0x02
#define TMCPF_ST0		0x04	
#define TMCPF_ST1		0x08	
#define TMCPF_SKIPRES	0x10
#define TMCPF_NOTIMOVRR	0x40


typedef struct {
	LPSTR	name;
	BYTE	cp_flags;
	BYTE	res1;

	WORD	Type;
	WORD	Ch;
	WORD	RTU;
	WORD	Point;
	DWORD	TM_Flags;

	WORD	tm_s2;
	WORD	tm_flags2;

	DWORD	tm_change_ut;
	DWORD	tm_tm_ut;
	WORD	tm_change_ms;
	WORD	tm_tm_ms;
	union {
		TStatusPoint st;
		TAnalogPoint an;
		TAccumPoint	 ac;
		BYTE		 padding[32];
	};
}TCommonPoint;


//	WORD	length;
//	WORD	signature;
//	BYTE	flags;
//	BYTE	importance;
//	WORD	type;

typedef struct {
	DWORD	name_off;
	BYTE	cp_flags;
	BYTE	res1;

	WORD	Type;
	WORD	Ch;
	WORD	RTU;
	WORD	Point;
	DWORD	TM_Flags;

	WORD	tm_s2;
	WORD	tm_flags2;

	DWORD	tm_change_ut;
	DWORD	tm_tm_ut;
	WORD	tm_change_ms;
	WORD	tm_tm_ms;
	union {
		TStatusPoint st;
		TAnalogPoint an;
		TAccumPoint	 ac;
		BYTE		 padding[32];
	};
}TCommonPoint32;

typedef	struct
{
	WORD	tm_type;
	DWORD	tms_flags;
	DWORD	tms_flags2;
}TFeedbackPropsSt;

typedef	struct
{
	WORD	tm_type;
	DWORD	tms_flags;
	DWORD	tms_flags2;
}TFeedbackPropsAn;

typedef	struct
{
	WORD	tm_type;
	DWORD	tms_flags;
	DWORD	tms_flags2;
}TFeedbackPropsAc;

#define TM_FBP_MAX_SIZE max(sizeof(TFeedbackPropsSt),max(sizeof(TFeedbackPropsAn),sizeof(TFeedbackPropsAc)))
#ifndef EXF_Present

#define EXF_NotTopical		0x00000001
#define EXF_Invalid			0x00000002
#define EXF_Overflow		0x00000004
#define EXF_OutofRange		0x00000008
#define EXF_BadReference	0x00000010
#define EXF_Oscillatory		0x00000020
#define EXF_Failure			0x00000040
#define EXF_OldData			0x00000080
#define EXF_Inconsistent	0x00000100
#define EXF_Inaccurate		0x00000200
#define EXF_Substituted		0x00000400
#define EXF_Test			0x00000800
#define EXF_OperatorBlocked	0x00001000

#define EXF_Present			0x80000000

#endif


typedef struct {
	float	val;
	DWORD	ut;
#define AMS_F_PRESENT	1
#define AMS_F_RELIABLE	2
	BYTE	sflg;
}TMSAnalogMSeriesElement;

typedef struct {
	WORD	interval;
	WORD	count;
	TMSAnalogMSeriesElement el[1];
}TMSAnalogMSeries;

typedef struct	{
	CHAR DateTime[24];       // время события в формате ДД.ММ.ГГГГ ЧЧ:ММ:СС.cc

	WORD			Imp;      // уровень важнос
	WORD			ID;       // тип события

	union {
		struct {
			WORD			Ch;       // кана
			WORD			RTU;      // номер КП  (c 1)
			WORD			Point;    // объект    (c 1)
		}Common;
		struct {
			WORD Kind;
			WORD DataLen;
			WORD Reserved;
		}Extended;
	};

	CHAR Data[22];
} TEvent;      // Событие


typedef struct
	{
	DWORD			Time;     // время в сек. с 01.01.1970
	BYTE			Hund;     // сотые доли сек.

	BYTE			Imp;      // уровень важнос
	WORD			ID;       // тип события
	union {
		struct {
			BYTE			Ch;       // кана
			BYTE			RTU;      // номер КП  (c 1)
			WORD			Point;    // объект    (c 1)
		}Common;
		struct {
			WORD			Kind;
			WORD			DataLen;
		}Extended;
	};
#define TTMSEVENT_HEADER_SIZE	12
	union
		{
		char EndOfHeader;
		BYTE end_header;
		struct
			{
			BYTE State;     // новое состояние ТС
			BYTE Class;     // класс телесигнала (К.А. - 0  АПС - 1)
#ifdef		TMCONN_NEW
			DWORD		ExtSig;									//6
			BYTE		ResCh;									//7
			BYTE		ResRTU;									//8
			WORD		ResPoint;								//10
			DWORD		FixUT;									//14
			WORD		S2;										//16
			DWORD		Flags;									//20
			WORD		FixMS;									//22  -- no more fields!
#endif
			} Status;  // параметры переключения ТС
		struct
			{
			float Val;      // значение контролируемого ТИТ
			WORD AlarmID;  // идентификатор уставк
			CHAR  State;    // 0 - уставка снята, 1 - уставка взведена
			} Alarm;   // параметры сработавшей уставк
		struct
			{
			BYTE  Ch;
			BYTE  RTU;
			WORD Point;
			BYTE  Cmd;     // выданная команда
			BYTE  Result;  // == SUCCESS если ТУ успешно, иначе FAILURE
			CHAR  UserName[16];  // пользователь, выдавший ТУ
			} Control; // параметры выданного телеуправления
		struct
			{
			union	{
				float F_val;
				SHORT S_val;
			};
			BYTE  Cmd;     // выданная команда
			BYTE  Result;  // == SUCCESS если ТУ успешно, иначе FAILURE
			CHAR  UserName[16];  // пользователь, выдавший ТУ
			} Regulation; // параметры выданного телерегулирования

		struct {
			float		Value;
			BYTE		State;
			CHAR		UserName[16];
		} AnalogSet;

		struct {
			BYTE data[1];
		} Extended;

		struct
			{
			DWORD index;
		} ExtendedLink;

		struct {
			FILETIME ft;
			WORD SavedID;
		} ExtFileLnk;

		struct {
			WORD		tmType;
			WORD		reserved1;
			WORD		reserved2;
			CHAR		UserName[16];  										// 22
		} Acknowledge;

		struct {
			WORD		tmType;
			DWORD		oldFlags;
			DWORD		newFlags;
		} FlagsChange;

	} Data;

} TTMSEvent;        // Событие в обмене

typedef struct {
			WORD		tmType;
			DWORD		oldFlags;
			DWORD		newFlags;
			union		{
				struct {
					BYTE Status;
					BYTE S2;
				}st;
				struct {
					WORD	asCode;
					float	asFloat;
				}an;
			};
			BYTE	reserved[4];
			CHAR	UserName[16];
}TTMSFlagsChangeData;

typedef struct
	{
	BYTE		State;     	
	BYTE		Class;     	
	DWORD		ExtSig;	
	BYTE		ResCh;	
	BYTE		ResRTU;
	WORD		ResPoint;
	DWORD		FixUT;
	WORD		S2;
	DWORD		Flags;
	WORD		FixMS;
	DWORD		oldFlags;
	CHAR		UserName[16];
}TTMSStatusChangeData;

typedef struct _TEventEx{
#ifdef IF_PORTCORE
    PVOID   next;
#else
	struct _TEventEx* next;
#endif
	DWORD size;
	TEvent evt;
}TEventEx;

typedef struct {
	u64 r;
	u64 m;
}TTMSElix;

typedef struct {
	TTMSElix elix;
	TTMSEvent ev;
}TTMSEventElix;

typedef struct {
	TTMSElix	elix;
	DWORD		ack_sec;
	WORD		ack_ms;
	CHAR		uname[16];
}TTMSEventAddData_v1;

typedef struct _TEventElix{
	struct _TEventElix* next;
	TTMSElix			elix;
	DWORD				ev_size;	//sizeof(ptr)+sizeof(TTMSElix)
	TEvent				evt;		//sizeof(ptr)+sizeof(TTMSElix)+sizeof(DWORD)
}TEventElix;

typedef struct {
	DWORD	ItemsLimit;
	DWORD	MemoryLimit;
	HANDLE	hStop;
	BOOL	Interrupted;
	BOOL	EvlArch;
}TEventExCriteria;

typedef	struct	{
	TTmsTime		time_act;
	TTmsTime		time_deact;
	TTMSEvent		ev;
}TAlertData;		//46

typedef struct {
	union {
		DWORD		uval;
		float		fval;
	}				cur_val;
	WORD			cur_s2;
	DWORD			cur_flags;
	DWORD			reserved;
	TAlertData		alert;
}TAlertListElement;

typedef struct {
	BYTE			idata[16];
}TAlertListId;

typedef struct {
	WORD Source;
	BYTE Rtu;
	BYTE Chn;
	BYTE Str_And_Bin;
}EXTEVL_STRBIN;

typedef struct {
	WORD Source;	//==0
	WORD Reserved;	//==0
	CHAR Str[1];
}EXTEVL_MODEL;

typedef struct {
	CHAR	sig[2];	//'T','D'
	DWORD	id;
	DWORD	delta_addr[16];
	DWORD	value_idx;
	CHAR	name[296];
	CHAR	value[128];
}TAGGED_DATA_DG;

struct StatusData  // параметры переключения ТС
	{
	BYTE	State;    // новое состояние ТС
	BYTE	Class;    // класс телесигнала (К.А. - 0  АПС - 1)
	DWORD		ExtSig;									//6
	BYTE		ResCh;									//7
	BYTE		ResRTU;									//8
	WORD		ResPoint;								//10
	DWORD		FixUT;									//14
	WORD		S2;										//16
	DWORD		Flags;									//20
	WORD		FixMS;									//22  -- no more fields!
	};
struct AlarmData   // параметры сработавшей уставки
	{
	float	Val;     // значение контролируемого ТИТ
	WORD	AlarmID; // идентификатор уставк
	BYTE	State;   // 0 - уставка снята, 1 - уставка взведена
	};
struct ControlData // параметры выданного телеуправления
	{
	BYTE	Ch;
	BYTE	RTU;
	WORD	Point;
	BYTE	Cmd;     // выданная команда
	BYTE	Result;  // == SUCCESS если ТУ успешно, иначе FAILURE
	CHAR	UserName[16];  // пользователь, выдавший ТУ
	};

////////////////////////	AAN

//	DON'T EVER CHANGE THE STRUCTURES!

typedef struct{
	WORD	ms;
	float	value;
	DWORD	flags;
}TMAAN_SR_DATA;

#define AANSR_LAST	0xffff

typedef struct {
	BYTE			legend;
	BYTE			mdflg;	//l=2
	float			v_min;	//l=6
	float			v_max;	//l=10
	float			v_last;	//l=14
	WORD			v_avg;	//l=16
	DWORD			v_tmflg;//l=20
	DWORD			series;	//l=24
}TMAAN_MIN_DATA;

#define AAMDF_OVF			1

#define AAMDL_NO_DATA		0
#define AAMDL_NOT_WR		0xff
#define AAMDL_OK			1
//////////////////////////////////////////////

typedef struct {
	DWORD		ok;
	DWORD		last_mc_ms;
	DWORD		last_hc_ms;
	DWORD		last_dc_ms;
	DWORD		megabytes;
}TM_AAN_STATS;

#define AAV_MOM			0
#define AAV_AVG			1
#define AAV_MIN			2
#define AAV_MAX			3

#define AAVR_MOM			(1<<AAV_MOM)
#define AAVR_AVG			(1<<AAV_AVG)
#define AAVR_MIN			(1<<AAV_MIN)
#define AAVR_MAX			(1<<AAV_MAX)

#define AAVF_OVF			1

typedef struct {
	BYTE	tag;
	BYTE	aav_flg;
	DWORD	ut;
	WORD	ms;
	DWORD	flags;
	float	value;
}TMAAN_ARCH_VALUE;				//16 bytes

//////////////////////
typedef struct
    {
    WORD			TII_RETRO_PERIOD;
    WORD			TII_RETRO_DEPTH;
    WORD			TIT_RETRO_PERIOD[3];
    WORD			TIT_RETRO_DEPTH[3];
    CHAR           TIT_RETRO_NAME[3][30];
    } TRetroInfo;

typedef struct {
	WORD	type;
	CHAR	name[128];
	CHAR	descr[30];
	DWORD	period;
	DWORD	capacity;
	DWORD	start;
	DWORD	stop;
	DWORD	rec_count;
	DWORD	reserved[16];
}TRetroInfoEx;
typedef struct {
	DWORD Id;
	CHAR  Name[64];
}TTelemetrySource;
#ifndef TServerInfo_DEEFINED
#define TServerInfo_DEEFINED
typedef struct {
	CHAR  Description[64];

	DWORD dwType;
	DWORD dwHeapUsage;
	DWORD dwWSMin;
	DWORD dwWSMax;

	DWORD HandleCount;
	DWORD StartTime;
	DWORD ConfChangeTime;
	DWORD ThreadCount;

	DWORD UserCount;
	DWORD LogonCount;

	DWORD PresenceFlags;
#define SIPF_UNIQ_USERS_COUNT	0x00000001
#define SIPF_TM_VALUE_COUNT		0x00000002
#define SIPF_RB_FILL			0x00000004
#define SIPF_RB_MAX_FILL		0x00000008
#define SIPF_TM_TOTVALCNT		0x00000010
#define SIPF_R_ASYNCB			0x00000020
#define SIPF_EXT_VAL_CNT		0x00000040
#define SIPF_RB_SIZE			0x00000080
#define SIPF_PASSIVE_SERVER		0x00000100
#define SIPF_R_SYNCB			0x00000200
#define SIPF_KEYID				0x00000400


	DWORD UniqUserCount;
	DWORD TmValueCount;

	DWORD ReserveBufFill;
	DWORD ReserveBufMaxFill;
	DWORD TmTotValCnt;
	DWORD ReserveSentAsyncBytes;
	DWORD TmExtValueCnt;

	DWORD DtmxLastCommit;
	DWORD DtmxBufFill;
	DWORD AnalogRetroWrites;
	DWORD ReserveBufSize;
	DWORD ReserveSentSyncBytes;
	DWORD ReserveAsyncPackets;
	DWORD ReserveSeconds;
	DWORD ReserveAsyncXPercent;	/* x 100 */
	DWORD TobSetCount;
	BYTE  KeyId[8];
	BYTE  reserverd[44];
} TServerInfo;
#endif //TServerInfo_DEEFINED
typedef struct {
	DWORD	Id;
	WORD	type;
	TADRtm	a;
} TRetransInfo;

#define TMVRF_CHTIME	0x0100	//a.Ch, >=0x100


typedef struct {
	BOOL	valid;

	CHAR	UserName		[0x10];
	CHAR	UserComment		[0x40];
	CHAR	NtUserName		[0x20];
	CHAR	NtUserDomain	[0x20];

	DWORD	DatagramMask;
	DWORD	AccessMask;
	DWORD	ConnectTime;

	CHAR	UserCategory	[0x40];
	BYTE	reserved		[0x20];

}TUserInfo;

#define TRETRANS_ITEMS_MAX 128

typedef struct {
	BYTE Ok;
#define TRIR_GROUP 1
#define TRIR_CLASS 2
	BYTE flags;
	WORD Group;
	WORD Class;
	WORD reserved2[3];
}TRetransInfoReply;

typedef struct {
	DWORD Id;
	WORD type;
	BYTE count;
	BYTE fbType;
	TADRtm a;
} TFeedbackInfo;

typedef struct {
	WORD Ch;
	WORD RTU;
	WORD Point;
	short Flags;
	short Status;
}TRetroStatusElement;
typedef struct {
	WORD Ch;
	WORD RTU;
	WORD Point;
	short Flags;
	float asFloat;
	short asCode;
}TRetroAnalogElement;
typedef struct {
	WORD Ch;
	WORD RTU;
	WORD Point;
	short Flags;
	float Value;
	float Load;
}TRetroAccumElement;

typedef struct {
	DWORD dwNumber;
	CHAR szName[32];
}TServerConfig;


typedef struct {
	BOOL	success;
	DWORD	bflags;
	CHAR	fname_or_error[1024];
}TServerBackupData;

typedef struct {
	DWORD	dwFreeSpace;
	DWORD	dwErr;
	DWORD	reserved[14];
	CHAR	errs[512];
}TPreRestoreServer;


#define TOF_WR_REPL		0
#define	TOF_WR_ADDT		1

typedef struct {
	BYTE	tob_flg;
	DWORD	scheme;
	WORD	type;
	DWORD	object;		//0xffffffff - not present
}TTechObj;

typedef struct {
	BYTE	tob_flg;
	DWORD	scheme;
	WORD	type;
	DWORD	object;
	LPSTR	props;		// "Prop1=aa\0Prop1=bbbb\0Prop2=ccc\0\0"
}TTechObjProps;

typedef struct {
	float	nominal;
	float	min_val;
	float	max_val;

	BYTE	alr_present;
	BYTE	alr_inuse;
	BYTE	alr_id;
	BYTE	reserved1;
	float	zone_lim[4];

	DWORD	reserved[64-8];
}TAnalogTechParms;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////	DELTA STRUCTURES

typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;

	BYTE value;
}DeltaStatus;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	BYTE value;
	BYTE hinum;
}DeltaStatus2;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	INT value;
}DeltaAnalog;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	INT value;
	BYTE hinum;
}DeltaAnalog2;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	float value;
}DeltaAnalogF;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	float value;
	BYTE hinum;
}DeltaAnalogF2;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	INT value;
}DeltaAccum;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	INT value;
	BYTE hinum;
}DeltaAccum2;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	float value;
}DeltaAccumF;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;
	float value;
	BYTE hinum;
}DeltaAccumF2;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;

	WORD ctrlBlock;
	WORD ctrlGroup;
	WORD ctrlPoint;
}DeltaControl;
typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;

	WORD ctrlBlock;
	WORD ctrlGroup;
	WORD ctrlPoint;
	BYTE hinum;
}DeltaControl2;

typedef struct {
	BYTE type;
	BYTE length;
	DWORD current;
}DeltaSliceTime;

typedef struct {
	BYTE type;
	BYTE length;
	CHAR text[1];
}DeltaDescription;


typedef struct {
	BYTE type;
	BYTE length;
	WORD number;
	DWORD lastUpdate;
	WORD flags;
	WORD tmsChn;
	WORD tmsRtu;
	WORD tmsPoint;

	CHAR s[1];

}DeltaStrval;

typedef struct {
	BYTE type;
	BYTE length;
}DeltaCommon;

/*subj to endian conversion in if_portcore*/

#define DELTA_ITEM_DESCRIPTION	0
#define DELTA_ITEM_TIME			1
#define	DELTA_ITEM_STATUS		2
#define DELTA_ITEM_ANALOG		3
#define DELTA_ITEM_ACCUM		4
#define DELTA_ITEM_CONTROL		5
#define DELTA_ITEM_ANALOGF		6
#define DELTA_ITEM_ACCUMF		7
#define DELTA_ITEM_STRVAL		8


#define DELTA_ITEMF_RELIABLE	1
#define DELTA_ITEMF_ZEROENUM    2
#define DELTA_ITEMF_DESTRELI	4
#define DELTA_ITEMF_DESTVAL		8
#define DELTA_ITEMF_HEX			0x10
#define DELTA_ITEMF_GROUP8		0x20
#define DELTA_ITEMF_N_PRSNT		0x40
#define DELTA_ITEMF_BINVAL		0x80
#define DELTA_ITEMF_WRITABLE	0x100
#define DELTA_ITEMF_CTLVALUE	0x200
#define DELTA_ITEMF_S2_BREAK	0x400
#define DELTA_ITEMF_S2_MALFN	0x800
#define DELTA_ITEMF_ANALONG		0x1000

#ifndef _BORLAND_TIME
#define _BORLAND_TIME
typedef struct {
		WORD year;
		BYTE day;
		BYTE month;
		BYTE min;
		BYTE hour;
		BYTE hund;
		BYTE sec;
}BorlandTime;
#endif

#pragma pack()



typedef struct {
	BYTE storage[0x100];
}ANALOG_QUEUE_FIND;


#define	huge_flt	FLT_MAX

typedef VOID (_STDCALL * tmcDatagramFn)(DWORD count,LPBYTE buf,LPVOID param);
typedef VOID (_STDCALL * tmcProgressFn)(DWORD count,LPVOID str,LPVOID param);
typedef INT (_STDCALL * tmcTelecontrolCallback)(DWORD cid,PVOID parm,LPSTR estr);
typedef VOID (_CDECL   * tcapRecvFunc)(DWORD count,LPBYTE buf,DWORD cid,BYTE proto);

#define TMTCCB_OK		1
#define TMTCCB_CANCEL	0
#define TMTCCB_NOKEY	-1

#define TMC_IMPEX

#ifdef _TMCONN_DLL
#undef	TMC_IMPEX
#define TMC_IMPEX	__declspec(dllexport)
#else

#ifdef LIBCFS_EXPORTS
#undef	TMC_IMPEX
#define TMC_IMPEX	__declspec(dllexport)
#endif

#ifndef TMCONN_NEW
#undef	TMC_IMPEX
#define TMC_IMPEX	__declspec(dllimport)
#endif // TMCONN_NEW

#endif

#ifdef __cplusplus
#endif
/*----------------------- ОБЩИЕ ФУНКЦИИ --------------------------*/
//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcFreeMemory(PVOID p);

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcConnect(
					LPSTR server,
					LPSTR pipe,
					LPSTR user,
					tmcDatagramFn cback,
					LPVOID cback_param);
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcConnectEx(
					LPSTR server,
					LPSTR pipe,
					LPSTR user,
					tmcDatagramFn cback,
					LPVOID cback_param,
					DWORD	cbProps,
					PDWORD	pProps,
					PDWORD	pPropValues	);

#define				TMC_MAX_CPROPS			8
#define				TMCCPROP_DGTYPE			1
#define				TMCCPROP_STATIDX		2
#define				TMCCPROP_JOIN			3

#define				JOIN_ID_FDW_PLUGIN		0xff01
//
//***************************************************************


//***************************************************************	IMPLEMENTED
#ifdef IF_PORTCORE
DWORD _STDCALL tmcConnectLocal(
					LPSTR pname,
					LPSTR user,
					tmcDatagramFn cback,
					LPVOID cback_param
);
#endif
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcCleanupThreadData();
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcSetTelecontrolCallback(
				DWORD cid,
				tmcTelecontrolCallback cb,
				PVOID parm);
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR  _STDCALL tmcDecodeTcError(WORD status);
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID  _STDCALL tmcDisconnect( DWORD cid );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID  _STDCALL tmcUpdateConnection( DWORD cid );
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcIsConnected(	DWORD cid );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetServerCaps(DWORD cid,PBYTE pCaps);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX CID_HANDLE _STDCALL tmcGetCfsHandle(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetConfigPath(DWORD cid,LPSTR path, DWORD cb_path);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetConfigType(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetCurrentServer(DWORD cid,LPSTR machine,DWORD cbMachine,LPSTR pipe,DWORD cbPipe);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetUrgentMessage(DWORD cid);
// returned pointer should be freed by tmcFreeMemory()
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetMapMode(DWORD cid, DWORD ModeType,PDWORD pMapMode);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcReconnectCount(	DWORD cid );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID  _STDCALL tmcReactError( DWORD cid, BOOL fReact );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX INT	_STDCALL tmcGetServerFeature(DWORD cid,DWORD dwCode);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcFeatCIDF(DWORD cid,PBYTE pi);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcFeatSB(DWORD cid,PBYTE pi,BYTE block,PBYTE data);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcSetRestraint(DWORD cid,BOOL fSet);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcGroupTMFlags(
	DWORD cid,
	WORD all,
	WORD tm_type,
	WORD ch, 
	WORD rtu, 
	WORD point,
	PWORD p_flags);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX PDWORD _STDCALL tmcGetUserList(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetUserInfo(DWORD cid,DWORD usid,TUserInfo* p_uinfo);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetUserInfoEx(DWORD cid,DWORD usid,TUserInfo* p_uinfo,LPSTR appx_buf,DWORD cb_appx);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcPostUserDatagram(DWORD cid,DWORD usid,PVOID p_data,DWORD cb_data);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetAnalogTechParms(	DWORD cid,TADRtm* addr, TAnalogTechParms* tpr);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetAnalogTechParms(	DWORD cid,TADRtm* addr, TAnalogTechParms* tpr);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetKnownxCfgPath(	DWORD cid,LPSTR app_tag, DWORD index);	
//	//free result with tmcFreeMemory()
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcComtradeEnumDays(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcComtradeEnumFiles(DWORD cid,LPSTR date);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcComtradeGetFile(DWORD cid,LPSTR fname,LPSTR locdir);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcBackupServerData ( DWORD cid, DWORD bflags, TServerBackupData* data );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcBackupServerProcedure(
	LPSTR machine,
	LPSTR pipe,
	LPSTR directory,
	PDWORD pbflags,
	HANDLE hCancel,
	tmcProgressFn prog_fn,
	LPVOID prog_parm
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcRestoreServer(
	BOOL tms_not_rbs,
	LPSTR machine,
	LPSTR servname,
	LPSTR filename,
	PDWORD pbflags,
	HANDLE hCancel,
	tmcProgressFn prog_fn,
	LPVOID prog_parm
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcPreRestoreServer(
	BOOL tms_not_rbs,
	LPSTR machine,
	LPSTR servname,
	LPSTR filename,
	TPreRestoreServer* pprs
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetBlob(
	DWORD cid,
	LPSTR name,
	LPSTR local_filename,
	PDWORD pcount,
	tmcProgressFn prog_fn,
	LPVOID prog_parm
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX TCommonPoint* _STDCALL tmcGetValuesByFlagMask(
	DWORD	cid,
	WORD	tm_type,
	DWORD	tm_flags,
	BYTE	q_flags,
	PDWORD	p_count
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX TCommonPoint* _STDCALL tmcGetValuesEx(
	DWORD	cid,
	WORD	tm_type,
	DWORD	tm_flags_set,
	DWORD	tm_flags_clr,
	BYTE	q_flags,
	LPSTR	group_name,
	DWORD	dw_ut,
	PDWORD	p_count
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX	TAnalogPoint* _STDCALL tmcRetroGetNamedAnalogGrpFull(	//have to free
	DWORD		cid,
	LPSTR		grp_name,
	DWORD		qry_flags,
	DWORD		dw_ut,
	DWORD		dw_step_back,
	DWORD		dw_step_cnt,
	TADRtm**	p_addrs,	//have to free
	DWORD*		p_addr_cnt
);
//
#define TMS_RETGRP_FAIL	1
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX	float* _STDCALL tmcRetroGetNamedAnalogGrp(	//have to free
	DWORD		cid,
	LPSTR		grp_name,
	DWORD		qry_flags,
	DWORD		dw_ut,
	DWORD		dw_step_back,
	DWORD		dw_step_cnt,
	TADRtm**	p_addrs,	//have to free
	DWORD*		p_addr_cnt
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX TCommonPoint* _STDCALL tmcTMValuesByListEx(
	DWORD	cid,
	WORD	tm_type,
	BYTE	q_flags,
	DWORD	a_count,
	TADRtm*	a
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcTMValueSetConfParm(
	DWORD	cid,
	WORD	tmType,
	TADRtm*	a, 
	WORD	parm,
	PVOID	data, 
	DWORD	cb_data
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcTMValueSetName(
	DWORD	cid,
	WORD	tmType,
	TADRtm* a, 
	LPSTR	name
);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetGrantedAccess(	DWORD cid ,PDWORD p_access);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcSetDgrmFlags(	DWORD cid, DWORD flags );
//
//		returns 0xffffffff on ERROR
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcClrDgrmFlags(	DWORD cid, DWORD flags  );
//
//		returns 0xffffffff on ERROR
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcClrFeedback(DWORD cid);
//
//		returns FAILURE on ERROR
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetFeedbackItems(DWORD cid,WORD type,
	short Ch, short RTU, short Point,BYTE count,BYTE fbType,DWORD Id);
//
//		returns FAILURE on ERROR
#define  FBTYPE_SIMPLE		((BYTE)0)
#define  FBTYPE_CONTROL		((BYTE)2)
#define  FBTYPE_SEQ			((BYTE)3)
#define  FBTYPE_CTLADD		((BYTE)4)

#define	 FBFLAG_MAINSRC		0x10

#define	 FBFLAG_REGUL_NO	0x00
#define	 FBFLAG_REGUL_STEP	0x20
#define	 FBFLAG_REGUL_CODE	0x40
#define	 FBFLAG_REGUL_VALUE	0x60

#define	 FBFLAG_REGUL_MASK	0x60

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetFeedbackItemsEx(DWORD cid,WORD count/*max=128*/,
	TFeedbackInfo* items);
//
//		returns FAILURE on ERROR
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetFeedbackItemsSrc(DWORD cid,PDWORD psrc,WORD count,TFeedbackInfo* items);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetFeedbackProps(DWORD cid,DWORD count,TTMVAddr* addrs, DWORD psize, PBYTE p_data);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED, OBSOLETE!!
TMC_IMPEX void _STDCALL tmcGetTmSource(DWORD cid,WORD type,
	short Ch, short RTU, short Point,TTelemetrySource* src);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetRetransInfo(DWORD cid,WORD count,TRetransInfo* ri);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcUpdRetransInfo(DWORD cid,WORD count,TRetransInfo* ri);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcRemoveRetransInfo(DWORD cid,WORD count,TRetransInfo* ri);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetRetransInfoEx(DWORD cid,WORD count,TRetransInfo* ri,TRetransInfoReply* rir);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcClrRetransInfo(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSendMapboardCommand(DWORD cid,BYTE cmd,BYTE parm1,BYTE parm2);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSendMapboardCommandEx(DWORD cid,BYTE cmd,PBYTE parms,DWORD cb_parms);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcConnState( DWORD cid );
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcSetLastError(DWORD error);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetLastError();
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetConnectErrorText(DWORD cid,LPSTR text, DWORD cb_text);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX INT _STDCALL tmcGetLastErrorText(DWORD cid,LPSTR* pp);
//
//	ОПИСАНИЕ:       получает текст последенего сообщения об ошибке
//					с контекста ползователя на ТМС
//
//	ПАРАМЕТРЫ:      pp    - в pp[0] кладется указатель на текстовую
//					      строку, которую в дальнейшем необходимо освободить
//					      с помощью tmcFreeMemory()
//
//	ВОЗВРАТ:         1  - успех
//					 0  - ошибка
//					-1 - не поддерживается сервером
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX VOID _STDCALL tmcSetUser(LPSTR user,LPSTR pwd);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BYTE _STDCALL tmcEnumObjects( DWORD cid ,WORD object_type,BYTE count,PWORD buf,
		short Ch,short RTU,short Point);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetServerInfo(DWORD cid,TServerInfo* info);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetServerThreads(DWORD cid);
//
//
//***************************************************************	IMPLEMENTED

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcRetroInfoEx(DWORD cid,WORD idx,TRetroInfoEx* info);
//
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetObjectName( DWORD cid ,WORD object_type,
		short Ch,short RTU,short Point,LPSTR buf,int buflen);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcDntGetObjectNames( DWORD cid ,TTMVAddr* tmva, DWORD tmva_cnt);
//	free result with tmcFreeMemory if nonzero
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetObjectNameEx(
	DWORD cid, short object_type,
	short Ch, short RTU, short Point, short SubObjectId,
	LPSTR buf,int buflen);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetObjectProperties( DWORD cid ,WORD object_type,
		short Ch,short RTU,short Point,LPSTR buf,int buflen);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetObjectPropertiesEx(
	DWORD cid ,WORD object_type,short Ch,short RTU,short Point);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetObjectProperties( DWORD cid ,WORD object_type,
		short Ch,short RTU,short Point,LPSTR prop_list,DWORD* p_mask);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX TPointEvBlock* _STDCALL tmcEnumPointEventBlocks(DWORD cid,WORD tm_type,PDWORD p_cnt);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetRetroFlags(DWORD cid); // return 0xffffffff on failure

#define RETROFLAG_COMMON	1
#define RETROFLAG_ARCHIVE	2
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetRetroFlags(DWORD cid,DWORD rflags); // return FALSE on failure

//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX PBYTE _STDCALL tmcGetNamedObject(DWORD cid,PDWORD paddr,LPSTR name,PDWORD pcb);

//		free result with tmcFreememory
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcEvaluateExpression(DWORD cid,LPSTR expr,LPSTR res,DWORD cbBytes);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcControlCmdResult(DWORD cid,DWORD Id,DWORD dwSuccess);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD*	_STDCALL tmcPerspEnum(DWORD cid,PDWORD pCount);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL		_STDCALL tmcPerspDelete(DWORD cid,DWORD ut);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL		_STDCALL tmcPerspPutAnalogs(DWORD cid, DWORD ut, DWORD count, TADRtm* addr,float* pVal);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL		_STDCALL tmcPerspPutValue(DWORD cid, DWORD ut,LPSTR Prop,LPSTR Value);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR		_STDCALL tmcPerspGet(DWORD cid,DWORD ut,PDWORD pLen);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX TBaseObjectInfo* _STDCALL tmcEnumBaseObjects(DWORD cid,PDWORD pCount);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR		_STDCALL tmcGetPerformanceData(DWORD cid);
//
//
//***************************************************************

//***************************************************************	OBSOLETE!!
TMC_IMPEX DWORD		_STDCALL tmcGetAnalogsFromQueueFirst(
	DWORD cid,ANALOG_QUEUE_FIND* aqf,TAnalogQueueRecord* records,
	DWORD count,DWORD start_time,DWORD stop_time,
	WORD chn,WORD rtu,WORD point);
//
//
//***************************************************************

//***************************************************************	OBSOLETE!!
TMC_IMPEX DWORD		_STDCALL tmcGetAnalogsFromQueueNext(
	DWORD cid,ANALOG_QUEUE_FIND* aqf,TAnalogQueueRecord* records,
	DWORD count);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short		_STDCALL tmcGetConfigInfo(DWORD cid, TServerConfig *pCfg, DWORD count);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetConfig(DWORD cid, PDWORD pConfig);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetConfig(DWORD cid, DWORD Config);
//
//
//***************************************************************

//****************************************************************		IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetReserveState(DWORD cid);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetValues(DWORD cid,DWORD count,TValueAndFlags* values);
// returns SUCCESS if implemented in server
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetTimedValues(DWORD cid,DWORD count,TTimedValueAndFlags* values);
// returns SUCCESS if implemented in server
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetValuesEx(DWORD cid,DWORD svx_flags,DWORD count,DWORD itemlen,PVOID data);
// returns SUCCESS if implemented in server
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcDeliverMultipleValues(DWORD cid,PVOID data,DWORD cb_data);
// returns SUCCESS if implemented in server
//
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR* _STDCALL tmcGetStatusClassData(DWORD cid,DWORD count /* max 128*/,TADRtm* statuses);
// return NULL on error
// returned pointer should be freed by tmcFreeMemory()
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR* _STDCALL tmcGetAnalogClassData(DWORD cid,DWORD count /* max 128*/,TADRtm* statuses);
// return NULL on error
// returned pointer should be freed by tmcFreeMemory()
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcControl(DWORD cid, short Ch, short RTU, short Point,
										  short Cmd);
//
//	ОПИСАНИЕ:       выдача команды телеуправления
//
//	ПАРАМЕТРЫ:      Ch    - канал,
//					RTU   - номер КП (с 1),
//					Point - номер объекта (с 1)
//					Cmd - команда ТУ (0-ОТКЛ, 1-ВКЛ)
//
//	ВОЗВРАТ:        SUCCESS - успех
//					иначе: FAILURE
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  INT _STDCALL  tmcExecuteControlScript(DWORD cid, short Ch, short RTU, short Point,
										  short Cmd);
//
//	ОПИСАНИЕ:       проверка разрешения ТУ через скрипт сервера
//
//	ПАРАМЕТРЫ:      Ch    - канал,
//					RTU   - номер КП (с 1),
//					Point - номер объекта (с 1)
//					Cmd - команда ТУ (0-ОТКЛ, 1-ВКЛ)
//
//	ВОЗВРАТ:        1  - ok
//					0  - нет разрешения
//					-1 - не поддерживается
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX	BOOL _STDCALL tmcOverrideControlScript(DWORD cid,BOOL fOverride);
//
//
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcControlByStatus(DWORD cid, short Ch, short RTU, short Point,
										  short Cmd);
//
//	ОПИСАНИЕ:       выдача команды телеуправления
//
//	ПАРАМЕТРЫ:      Ch    - канал,
//					RTU   - номер КП (с 1),
//					Point - номер объекта (с 1)
//					Cmd - команда ТУ (0-ОТКЛ, 1-ВКЛ)
//
//	ВОЗВРАТ:        SUCCESS - успех
//					иначе:
#define TMCTLERR_INVALID_ADDRESS	0
#define TMCTLERR_NO_RESOURCES		-1
#define TMCTLERR_TMSOURCE_FAILED	-2
#define TMCTLERR_WAIT_TIMEOUT		-3
#define TMCTLERR_CANNOT_REDIRECT	-4
#define TMCTLERR_NO_TMSOURCE		-5
#define TMCTLERR_NO_KEYCODE			-6
#define TMCTLERR_WRONG_KEYCODE		-7
#define TMCTLERR_KEYCODE_TIMEOUT	-8
#define TMCTLERR_USER_NAME_UNKNOWN	-9
#define TMCTLERR_ACCESS_DENIED		-10
#define TMCTLERR_NOT_SUPPORTED		-11
#define TMCTLERR_NO_TM_SERVER		-12
#define TMCTLERR_WRONG_KEY			-13
#define TMCTLERR_SCRIPT_ERROR		-14
#define TMCTLERR_EXCEPT				-15
#define	TMCTLERR_BUSY				-16
#define	TMCTLERR_TAKEOVER			-17
#define	TMCTLERR_CHANGE_TIMEOUT		-18
#define	TMCTLERR_I850_BASE			850
#define	TMCTLERR_I850_ADD_CAUSE_UNKNOWN							-(TMCTLERR_I850_BASE+0)
#define	TMCTLERR_I850_ADD_CAUSE_NOT_SUPPORTED					-(TMCTLERR_I850_BASE+1)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_SWITCHING_HIERARCHY	-(TMCTLERR_I850_BASE+2)
#define	TMCTLERR_I850_ADD_CAUSE_SELECT_FAILED					-(TMCTLERR_I850_BASE+3)
#define	TMCTLERR_I850_ADD_CAUSE_INVALID_POSITION				-(TMCTLERR_I850_BASE+4)
#define	TMCTLERR_I850_ADD_CAUSE_POSITION_REACHED				-(TMCTLERR_I850_BASE+5)
#define	TMCTLERR_I850_ADD_CAUSE_PARAMETER_CHANGE_IN_EXECUTION	-(TMCTLERR_I850_BASE+6)
#define	TMCTLERR_I850_ADD_CAUSE_STEP_LIMIT						-(TMCTLERR_I850_BASE+7)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_MODE					-(TMCTLERR_I850_BASE+8)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_PROCESS				-(TMCTLERR_I850_BASE+9)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_INTERLOCKING			-(TMCTLERR_I850_BASE+10)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_SYNCHROCHECK			-(TMCTLERR_I850_BASE+11)
#define	TMCTLERR_I850_ADD_CAUSE_COMMAND_ALREADY_IN_EXECUTION	-(TMCTLERR_I850_BASE+12)
#define	TMCTLERR_I850_ADD_CAUSE_BLOCKED_BY_HEALTH				-(TMCTLERR_I850_BASE+13)
#define	TMCTLERR_I850_ADD_CAUSE_1_OF_N_CONTROL					-(TMCTLERR_I850_BASE+14)
#define	TMCTLERR_I850_ADD_CAUSE_ABORTION_BY_CANCEL				-(TMCTLERR_I850_BASE+15)
#define	TMCTLERR_I850_ADD_CAUSE_TIME_LIMIT_OVER					-(TMCTLERR_I850_BASE+16)
#define	TMCTLERR_I850_ADD_CAUSE_ABORTION_BY_TRIP				-(TMCTLERR_I850_BASE+17)
#define	TMCTLERR_I850_ADD_CAUSE_OBJECT_NOT_SELECTED				-(TMCTLERR_I850_BASE+18)
#define	TMCTLERR_I850_ADD_CAUSE_OBJECT_ALREADY_SELECTED			-(TMCTLERR_I850_BASE+19)
#define	TMCTLERR_I850_ADD_CAUSE_NO_ACCESS_AUTHORITY				-(TMCTLERR_I850_BASE+20)
#define	TMCTLERR_I850_ADD_CAUSE_ENDED_WITH_OVERSHOOT			-(TMCTLERR_I850_BASE+21)
#define	TMCTLERR_I850_ADD_CAUSE_ABORTION_DUE_TO_DEVIATION		-(TMCTLERR_I850_BASE+22)
#define	TMCTLERR_I850_ADD_CAUSE_ABORTION_BY_COMMUNICATION_LOSS	-(TMCTLERR_I850_BASE+23)
#define	TMCTLERR_I850_ADD_CAUSE_ABORTION_BY_COMMAND				-(TMCTLERR_I850_BASE+24)
#define	TMCTLERR_I850_ADD_CAUSE_NONE							-(TMCTLERR_I850_BASE+25)
#define	TMCTLERR_I850_ADD_CAUSE_INCONSISTENT_PARAMETERS			-(TMCTLERR_I850_BASE+26)
#define	TMCTLERR_I850_ADD_CAUSE_LOCKED_BY_OTHER_CLIENT			-(TMCTLERR_I850_BASE+27)

// minimum val = -2048



//***************************************************************

#define	TMS_REGUL_STEP	1
#define	TMS_REGUL_CODE	2
#define	TMS_REGUL_VAL	3

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcRegulationByAnalog(DWORD cid, short Ch, short RTU, short Point,BYTE reg_type, PVOID p_data);
//
//	ОПИСАНИЕ:       выдача команды телеуправления
//
//	ПАРАМЕТРЫ:      Ch    - канал,
//					RTU   - номер КП (с 1),
//					Point - номер объекта (с 1)
//					reg_type - TMS_REGUL_XXX
//					p_data - для TMS_REGUL_STEP и TMS_REGUL_CODE - short*, 
//					p_data - для TMS_REGUL_VAL - float*, 
//
//	ВОЗВРАТ:        SUCCESS - успех
//					иначе:	TMCTLER_XXX
//***************************************************************

//*************************************************************** 	IMPLEMENTED
#define	TCWT_NO_WAIT			0		//не ждать результата
#define	TCWT_WAIT_RESPONSE		1		//дождаться ответа от телеметрии
#define	TCWT_EXEC_ASYNC			2		//исполнять асинхронно, результаты в дейтаграммах (с проверкой изменения параметра)
#define	TCWT_WAIT_CHANGE		3		//дождаться изменения телепараметра
#define	TCWT_WAIT_RESP_LOG		4		//дождаться ответа от телеметрии + запись неуспешного результата

TMC_IMPEX
short _STDCALL tmcControlByStatusEx(
	DWORD	cid, 
	short	Ch, 
	short	RTU, 
	short	Point,
	short	Cmd,
	BYTE	WaitType,	//тип ожидания результата
	PDWORD	pCmdId		//на выходе - идентификатор команды
);
//
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX
short _STDCALL tmcRegulationByAnalogEx(
	DWORD cid, 
	short Ch, 
	short RTU, 
	short Point,
	BYTE reg_type,
	PVOID reg_data,
	BYTE	WaitType,
	PDWORD	pCmdId
);
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSystemTime(DWORD cid, char *DateTime, struct tm *tm);
//
//	ОПИСАНИЕ:       Запрос времени на сервере
//
//	ПАРАМЕТРЫ:      DateTime - адрес строки для выдачи времен
//                             в формате "ДД.ММ.ГГГГ ЧЧ:ММ:СС" или NULL
//					tm       - адрес структуры tm (см. TIME.H) или NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************


/*--------------- ФУНКЦИИ ПОЛУЧЕНИЯ ДАННЫХ -----------------------*/

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcStatus(DWORD cid, short Ch, short RTU, short Point);
//
//	ОПИСАНИЕ:       Возвращает состояние объекта ТС
//
//	ПАРАМЕТРЫ:      Ch    - канал,
//					RTU   - номер КП (с 1),
//					Point - номер объекта (с 1)
//
//	ВОЗВРАТ:        0 - ОТКЛ,  1 - ВК
//				   -1 - ошибка, нет данных
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcStatusFull(DWORD cid, short Ch, short RTU, short Point,
											 TStatusPoint *SP);
//
//	ОПИСАНИЕ:       Возвращает состояние объекта ТС в структуре
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					SP             - указатель на структуру объекта ТС
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка, нет данных
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcStatusFullEx(DWORD cid, short Ch, short RTU, short Point,
											TStatusPoint *SP, DWORD Time);
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  float _STDCALL tmcAnalog(DWORD cid, short Ch, short RTU, short Point,
										 const char  *DateTime, short RetroNum);
//
//	ОПИСАНИЕ:       Возвращает значение объекта ТИТ
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					DateTime, RetroNum - опциональные параметры получения
//									     значения из ретроспективы.
//                                       DateTime задается в формате
//                                       "ДД.ММ.ГГ ЧЧ:ММ:СС"
//									     Если интересуют текущие значения,
//									     то DateTime == NULL
//
//	ВОЗВРАТ:        реальное значение ТИТ или huge_flt при отсутствии данных
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcAnalogFull(DWORD cid, short Ch, short RTU, short Point,
											 TAnalogPoint *AP,
											 const char *DateTime,
											 short RetroNum);
//
//	ОПИСАНИЕ:       Возвращает значение объекта ТИТ в структуре
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					AP             - указатель на структуру ТИТ
//									 если AP->asFloat == _huge_flt то
//									 преобразования из кода в значение не
//									 производится. При этом уменьшается
//									 время доступа.
//					DateTime, RetroNum - опциональные параметры получения
//									     значения из ретроспективы.
//                                       DateTime задается в формате
//                                       "ДД.ММ.ГГ ЧЧ:ММ:СС"
//									     Если интересуют текущие значения,
//									     то DateTime == NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка, нет данных
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcAnalogMicroSeries(
		DWORD				cid,
		DWORD				cnt,
		TADRtm*				addr_list,
		TMSAnalogMSeries**	result_list
);
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//	Каждый указатель в списке result_list должен быт освобожден
//  с помощью tmcFreeMemory()
//***************************************************************
	



//***************************************************************	IMPLEMENTED
TMC_IMPEX  float _STDCALL tmcAccumValue(DWORD cid, short Ch, short RTU, short Point,
											 const char *DateTime);
//
//	ОПИСАНИЕ:       Возвращает значение счетчика ТИИ
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					DateTime - опциональный параметр получения
//							   значения из ретроспективы.
//                             DateTime задается в формате
//                             "ДД.ММ.ГГ ЧЧ:ММ:СС"
//							   Если интересуют текущие значения,
//							   то DateTime == NULL
//
//	ВОЗВРАТ:        значение счетчика ТИИ или huge_flt при ошибке
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  float _STDCALL tmcAccumLoad(DWORD cid, short Ch, short RTU, short Point,
											const char *DateTime);
//
//	ОПИСАНИЕ:       Возвращает значение нагрузки из ТИИ
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					DateTime - опциональный параметр получения
//							   значения из ретроспективы.
//                             DateTime задается в формате
//                             "ДД.ММ.ГГ ЧЧ:ММ:СС"
//							   Если интересуют текущие значения,
//							   то DateTime == NULL
//
//	ВОЗВРАТ:        значение нагрузки или huge_flt при ошибке
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcAccumFull(DWORD cid, short Ch, short RTU, short Point,
											TAccumPoint *AP,
											const char *DateTime);
//
//	ОПИСАНИЕ:       Возвращает значение объекта ТИИ в структуре
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					AP       - указатель на структуру ТИИ
//					DateTime - опциональный параметр получения
//							   значения из ретроспективы.
//                             DateTime задается в формате
//                             "ДД.ММ.ГГ ЧЧ:ММ:СС"
//							   Если интересуют текущие значения,
//							   то DateTime == NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка, нет данных
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcAccumFullEx(
	DWORD cid,
	short Ch, short RTU, short Point,
	TAccumPoint *AcP,const char *DateTime,short RetroNum);

//***************************************************************

/*--------------- ФУНКЦИИ ЗАНЕСЕНИЯ ДАННЫХ -----------------------*/
//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetStatusNormal(DWORD cid, short Ch, short RTU, short Point,
											WORD NValue);

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcGetStatusNormal(DWORD cid, short Ch, short RTU, short Point,
											PWORD pNValue); // return SUCCESS/FAILURE

//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetNamedObject(DWORD cid,PDWORD paddr,LPSTR name,PBYTE pobj,DWORD cb);

//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcEnumNamedObjects(DWORD cid,PDWORD paddr);

//		double zero terminated list
//		free result with tmcFreememory
//***************************************************************


//***************************************************************	IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcSetAccumValueSeries(DWORD cid,WORD chn,WORD rtu,WORD point,
	float val, DWORD ut,BOOL allow_reformat,LPSTR errs,DWORD cb_errs);

//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetStatusUT (DWORD cid, short Ch, short RTU, short Point,
				   char Value,
				   DWORD ut,  BYTE hund,BYTE FlgCmd,BYTE Flags);
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetStatusUT_MS (DWORD cid, short Ch, short RTU, short Point,
				   char Value,
				   DWORD ut,  WORD ms, BYTE FlgCmd,BYTE Flags);
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetStatus(DWORD cid, short Ch, short RTU, short Point,
											char Value,
											const char *DateTime, short Hund);
//
//	ОПИСАНИЕ:       задает состояние объекта ТС
//
//	ПАРАМЕТРЫ:      Ch    		   - канал,
//					RTU            - номер КП (с 1),
//					Point          - номер объекта (с 1)
//					Value          - новое значение ТС
//					DateTime       - опциональный параметр реального
//									 времени возникновения ТС.
//									 формат: "ДД.ММ.ГГ ЧЧ:ММ:СС.сс"
//									 сс - сотые доли секунд
//									 Если реальное время неизвестно, то
//									 следует передать Time = NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************
TMC_IMPEX  short _STDCALL tmcFillStatusGroup(DWORD cid, short Ch, short RTU, short Point,
												  short Quan, char *SGroup);
//
//	ОПИСАНИЕ:       задает состояние группы ТС
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - начальный объект ТС
//					Quan           - количество ТС в группе
//					SGroup         - указатель на массив ТС (массив бит,
//									 младший бит в байте - меньший номе
//									 объекта)
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetStatusFlags(DWORD cid, short Ch, short RTU, short Point,
												 short Flags);
TMC_IMPEX  short _STDCALL tmcClrStatusFlags(DWORD cid, short Ch, short RTU, short Point,
													 short Flags);
//
//	ОПИСАНИЕ:       Устанавливают/сбрасывают флаги объекта ТС
//					tmSetStatusFlags - установка
//					tmClrStatusFlags - сброс
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - N объекта (с 1), если == 0 то
//									 операция производится со все
//									 объектами данного К
//					Flags          - битовая маска флагов
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalogUT(DWORD cid, short Ch, short RTU, short Point,
											float Value,DWORD ut,BYTE FlgCmd,BYTE Flags);

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalogFloatCodeUT(
	DWORD cid,
	short Ch,
	short RTU,
	short Point,
	float FCode,
	DWORD ut,BYTE FlgCmd,BYTE Flags);

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalog(DWORD cid, short Ch, short RTU, short Point,
											float Value,
											const char *DateTime);
//
//	ОПИСАНИЕ:       задает значение объекта ТИТ
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					Value          - новое значение ТИТ (реальное число)
//					DateTime       - опциональный параметр записи ТИТ
//									 в ретроспективу в формате "ДД.ММ.ГГ ЧЧ:ММ:СС"
//									 Если задается мгновенное значение, то
//									 следует передать DateTime = NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalogByCodeUT(DWORD cid, short Ch, short RTU, short Point,
												  short Value,DWORD ut,BYTE FlgCmd,BYTE Flags);

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalogByCode(DWORD cid, short Ch, short RTU, short Point,
												  short Value);
//
//	ОПИСАНИЕ:       задает значение объекта ТИТ в коде
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					Value          - код ТИТ. Отрицательные значения
//									 задаются в дополнительном коде
//									 (-1 == 0FFFFh)
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcFillAnalogGroup(DWORD cid, short Ch, short RTU, short Point,
											short Quan, short *AGroup);
//
//	ОПИСАНИЕ:       задает значения группы ТИТ
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - начальный объект ТИТ
//					Quan           - количество ТИТ в группе
//					AGroup         - указатель на массив ТИТ (коды)
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//*************************************************************** IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAnalogFlags(DWORD cid, short Ch, short RTU, short Point,
												 short Flags);
TMC_IMPEX  short _STDCALL tmcClrAnalogFlags(DWORD cid, short Ch, short RTU, short Point,
												 short Flags);
//
//	ОПИСАНИЕ:       Устанавливают/сбрасывают флаги объекта ТИТ
//					tmcSetAnalogFlags - установка
//					tmcClrAnalogFlags - сброс
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - N объекта (с 1), если == 0 то
//									 операция производится со все
//									 объектами данного К
//					Flags          - битовая маска флагов
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcIncAccumPoints(DWORD cid, short Ch, short RTU, short Point,
												 short DataType, short Quan,
												 void *AGroup);
//
//	ОПИСАНИЕ:       Поступление новых значений для объектов ТИИ
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - начальный объект ТИИ
//                  DataType       - разрядность аппаратного счетчика
//                                   если (DataType&0x8000) != 0 то
//							 		 предоставляемые данные - чистый
//                                   прирост импульсов
#define ACCUM_TYPE_EXT_FLOAT (32*1+1)
#define ACCUM_TYPE_EXT_LD	(32*1+2)
//					Quan           - количество ТИИ в группе
//					AGroup         - указатель на массив ТИИ
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcDeliverTimedAccum(DWORD cid, DWORD count,TTimedAccum* accums);

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcDeliverTimedAccumEx(DWORD cid, DWORD count,TTimedAccumEx* accums);

//*************************************************************** 	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcDeliverAccumData(DWORD cid, DWORD count,TAccumData* accums);


//***************************************************************	IMPLEMENTED
TMC_IMPEX short _STDCALL tmcSetAccumValueUT(DWORD cid, short Ch, short RTU, short Point,
												float Value, DWORD ut,BYTE FlgCmd,BYTE Flags);

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAccumValue(DWORD cid, short Ch, short RTU, short Point,
												float Value,
												const char *DateTime);
//
//	ОПИСАНИЕ:       задает значение счетчика ТИИ
//
//	ПАРАМЕТРЫ:      Ch, RTU, Point - см. выше
//					Value          - новое значение счетчика (реальное число)
//					DateTime       - опциональный параметр записи ТИТ
//									 в ретроспективу в формате "ДД.ММ.ГГ ЧЧ:ММ:СС"
//									 Если задается мгновенное значение, то
//									 следует передать DateTime = NULL
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcSetAccumFlags(DWORD cid, short Ch, short RTU, short Point,
												short Flags);
TMC_IMPEX  short _STDCALL tmcClrAccumFlags(DWORD cid, short Ch, short RTU, short Point,
												short Flags);
//
//	ОПИСАНИЕ:       Устанавливают/сбрасывают флаги объекта ТИИ
//					tmcSetAccumFlags - установка
//					tmcClrAccumFlags - сброс
//
//	ПАРАМЕТРЫ:      Ch, RTU        - см. выше
//					Point          - N объекта (с 1), если == 0 то
//									 операция производится со все
//									 объектами данного К
//					Flags          - битовая маска флагов
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************


/*--------------- ЖУРНАЛ РЕГИСТРАЦИИ СОБЫТИЙ ---------------------*/

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcRegEvent(DWORD cid, TEvent *tmEvent);
//
//	ОПИСАНИЕ:       регистрация события в ретроспективе
//
//	ПАРАМЕТРЫ:      tmEvent - указатель на структуру с событие
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short  _STDCALL tmcRegEventRaw(DWORD cid, TTMSEvent *tmsEvent);
//
//	ОПИСАНИЕ:       регистрация события в ретроспективе
//
//	ПАРАМЕТРЫ:      tmsEvent - указатель на структуру с событие
//
//	ВОЗВРАТ:        SUCCESS - успех
//					FAILURE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  BOOL _STDCALL tmcEvlogPutStrBin(DWORD cid,
		DWORD unix_time,BYTE unix_hund,
		BYTE importance,DWORD SourceTag,
		LPSTR str,PVOID bin,DWORD cb_bin);
//
//					FALSE - ошибка
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcEventLogUT(DWORD cid, DWORD Start, DWORD End,
				           short EvMask, TTMSEvent *Events,
				           short Cpct, DWORD *Cursor);
//
//
//***************************************************************

//***************************************************************	IMPLEMENTED
TMC_IMPEX  short _STDCALL tmcEventLog(DWORD cid,
										   const LPSTR StartTime,
										   const LPSTR EndTime,
										   short EvMask, TEvent *EvLog,
										   short Cpct, DWORD *Cursor);
//
//	ОПИСАНИЕ:       Выборка данных из журнала регистрации событий
//
//	ПАРАМЕТРЫ:      StartTime   - время начала выборк
//					EndTime     - время конца выборк
//					EvMask      - маска событий, попадающих в выборку
//					EvLog       - указатель на массив структур для
//								  занесения выбраных событий
//					Cpct        - количество элементов этого массива
//					Cursor      - указатель на служебную переменную
//								  текущей позиции в журнале. Используется
//								  для порционной выборки из ретроспективы.
//								  Перед первым вызовом *Cursor должно быть 0L
//								  При нехватке места в массиве для всех
//								  событий *Cursor будет установлено и его
//								  не следует менять при последовательных
//								  вызовах до полного получения всех событий
//
//	ВОЗВРАТ:        Количество считаных событий

//****************************************************************		IMPLEMENTED
TMC_IMPEX TTMSEvent* _STDCALL tmcEventLogByIndex(DWORD cid,DWORD index,DWORD ut,PDWORD pSize);

//****************************************************************		IMPLEMENTED
TMC_IMPEX TEventEx* _STDCALL tmcEventLogEx(DWORD cid,WORD ev_mask,DWORD ux_start,
								  DWORD ux_stop,TEventExCriteria* pCrit);


//****************************************************************		IMPLEMENTED
TMC_IMPEX TEventElix* _STDCALL tmcEventLogByElix(
	DWORD cid,
	TTMSElix* pElix,
	WORD ev_mask,
	DWORD ux_start,
	DWORD ux_stop
);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcGetCurrentElix(
	DWORD cid,
	TTMSElix* pElix);



//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcEventLogByElixList(
	DWORD		cid, 
	TTMSEventElix *Events,
	TTMSElix	*pElix,
	DWORD		count
);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL	_STDCALL tmcEventLogAdditionalDataByElixList(
	DWORD		cid, 
	TTMSElix	*pElix,
	DWORD		count
);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcEventLogAckRecords(
	DWORD cid,
	TTMSElix	*pElix,
	DWORD count);

//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcEventGetAdditionalRecData(DWORD idx,PBYTE p_buf,DWORD cb_buf);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSendTaggedData(
	DWORD cid,
	DWORD uid,
	PBYTE p_data,
	DWORD cb_data);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcRequestTaggedData(
	DWORD cid,
	DWORD id,
	DWORD inf_type,	//0 -all
	DWORD tma,
	DWORD reserved,
	LPSTR tagname);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcReturnTaggedData(
	DWORD			cid,
	TAGGED_DATA_DG*	p_tagd
);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetTracer(
	DWORD			cid,
	WORD			ch,
	WORD			rtu,
	WORD			pt,
	WORD			tm_type,
	WORD			msgf

);
//****************************************************************		IMPLEMENTED
TMC_IMPEX void _STDCALL tmcTakeRetroTit(DWORD cid, short Ch, short RTU, short Point,
								DWORD utime,WORD RetroNum, WORD count,WORD step,TAnalogPointShort* aps);
//****************************************************************		IMPLEMENTED
TMC_IMPEX TADRtm* _STDCALL tmcTakeAPS(DWORD cid);	// should free result with tmcFreeMemory
//****************************************************************		IMPLEMENTED
TMC_IMPEX void _STDCALL tmcReadRetroTimes(DWORD cid, WORD idx,
								PDWORD* ppdata,	// нужно освобождать с пом. tmcFreeMemory()
								DWORD* pcount,LPSTR pError);
//****************************************************************		IMPLEMENTED
TMC_IMPEX void _STDCALL tmcReadRetroSlice(DWORD cid,WORD idx,DWORD utime,
								 WORD* ptype,
								 PVOID* ppdata, // нужно освобождать с пом. tmcFreeMemory()
								 DWORD* pcount);
//****************************************************************		IMPLEMENTED
TMC_IMPEX short _STDCALL tmcRetroInfo(DWORD cid, TRetroInfo *RetroInfo);
//****************************************************************		IMPLEMENTED
TMC_IMPEX short _STDCALL tmcPeekAlarm(DWORD cid, short Ch, short RTU, short Point,
                  short AlarmID, TAlarm *Alarm);
//****************************************************************		IMPLEMENTED
TMC_IMPEX short _STDCALL tmcPokeAlarm(DWORD cid, short Ch, short RTU, short Point,
                  short AlarmID, TAlarm *Alarm);
//****************************************************************		IMPLEMENTED
TMC_IMPEX short _STDCALL tmcEnumAlarms(DWORD cid, short Ch, short RTU, short Point,
                  TAlarm *Alarm, short MaxQuan, short ActiveOnly);


//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcGetAlarm(
	DWORD		cid,
	short		Ch,
	short		RTU,
	short		Point,
	BYTE		AlarmID,
	TAlarmNew	*Alarm,
	DWORD		cbAlarm,
	LPSTR		*ppStrings
);
//возвращает 0 при ошибке или число байт
//pStrings нужно освобождать
//pStrings = "Expr=xxx""Name=xx""P1=xx""P2=xx"

//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmsGetAlarmParams(
	DWORD		cid,
	short		Ch,
	short		RTU,
	short		Point,
	BYTE		AlarmID,
	DWORD		count,
	TAlarmParam* params
 );
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmsSetAlarmParams(
	DWORD		cid,
	short		Ch,
	short		RTU,
	short		Point,
	BYTE		AlarmID,
	DWORD		count,
	float*		pvalues
 );
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDeleteAlarm(
	DWORD		cid,
	short		Ch,
	short		RTU,
	short		Point,
	BYTE		AlarmID
);
//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcReadAlarmState(
	DWORD		cid,
	short		Ch,
	short		RTU,
	short		Point,
	BYTE		AlarmID,
	TAlarmState	*ast,
	DWORD		cb_ast
);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetAlarm(
	DWORD		cid,
	TAlarmNew	*Alarm,
	DWORD		cbAlarm,
	LPSTR		pStrings
);
//возвращает FALSE при ошибке

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDownloadAlarms(DWORD	cid,LPSTR fname);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcUploadAlarms(DWORD	cid,LPSTR fname,LPSTR txt,DWORD cb_txt);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL  tmcAlertListRemove(DWORD cid, TAlertListId* list_id);

//****************************************************************		IMPLEMENTED
TMC_IMPEX short _STDCALL tmcDriverCall(DWORD cid, DWORD ADR, short Q_Code, short Command );

//****************************************************************		IMPLEMENTED
TMC_IMPEX void  _STDCALL tmcStatusByList(DWORD cid, short Quan, TADRtm *List, TStatusPoint *SPs);

//****************************************************************		IMPLEMENTED
TMC_IMPEX void _STDCALL tmcStatusByListEx(DWORD cid, short Quan, TADRtm *ADRs, TStatusPoint *SPs,DWORD Time);

//****************************************************************		IMPLEMENTED
TMC_IMPEX void  _STDCALL tmcAnalogByList(DWORD cid, short Quan, TADRtm *List, TAnalogPoint *APs,
                               DWORD Time, short RetroNum);

//****************************************************************		IMPLEMENTED
TMC_IMPEX void  _STDCALL tmcAccumByList (DWORD cid, short Quan, TADRtm *List, TAccumPoint *AcPs,
                               DWORD Time);
//****************************************************************		IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcGetTextualInfo(DWORD cid,WORD info,PBYTE data,DWORD cbdata);
//****************************************************************		IMPLEMENTED
TMC_IMPEX TADRtm* _STDCALL tmcTextSearch(DWORD cid,WORD type,LPSTR txt,PDWORD p_count);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSetDapName(DWORD cid,WORD driver,WORD adapter,WORD port,LPSTR name);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcSpTreeChangeCount(DWORD cid,PDWORD p_chgcnt);

//****************************************************************		IMPLEMENTED

TMC_IMPEX BOOL _STDCALL tmcAanGetStats(	DWORD cid,TM_AAN_STATS* stats, DWORD cb_stats);

//****************************************************************		IMPLEMENTED

TMC_IMPEX TMAAN_MIN_DATA* _STDCALL tmcAanGetValues(
	DWORD			cid,
	DWORD			tma,
	DWORD			ut,
	BYTE			b_ser ,
	PWORD			pcnt,
	LPSTR			p_errs,		//only if fails
	DWORD			cb_errs
);

//****************************************************************		IMPLEMENTED
TMC_IMPEX TMAAN_ARCH_VALUE* _STDCALL tmcAanReadArchive(
	DWORD cid,
	DWORD tma,
	DWORD start_ut,
	DWORD stop_ut,
	DWORD intv,
	DWORD aarf,
	PDWORD p_cnt,
	tmcProgressFn prog_fn,
	PVOID prog_parm
);


TMC_IMPEX BOOL _STDCALL tmcTechObjBeginUpdate(DWORD	cid);

TMC_IMPEX BOOL _STDCALL tmcTechObjEndUpdate(DWORD	cid);

TMC_IMPEX INT	_STDCALL tmcTechObjWriteValues(DWORD	cid,TTechObjProps* objp, DWORD count);	//1-full success, 0 -partial success, -1 -failure

TMC_IMPEX TTechObjProps* _STDCALL tmcTechObjReadValues(
	DWORD cid,
	TTechObj* pobj,
	DWORD count);	// zero on connection error, free result with tmcFreeMemory()

TMC_IMPEX TTechObjProps* _STDCALL tmcTechObjEnumValues(
	DWORD cid,
	DWORD tob_s,			//	0xffffffff if any
	DWORD tob_t,			//	0xffffffff if any
	LPSTR props,			//  "Prop1=aa\0Prop1=bbbb\0Prop2=ccc\0Prop3\0\0"
	PDWORD p_count);		// free result with tmcFreeMemory()



TMC_IMPEX LPSTR _STDCALL tmcTechObjReplReadLog(			
	DWORD cid,
	TTMSElix* p_elix);	// NULL on error or no data


//****************************************************************
#define TM_PUB_SUBS_QOS_0			0x00
#define TM_PUB_SUBS_QOS_1			0x01 
#define TM_PUB_SUBS_QOS_2			0x02 
#define TM_PUB_SUBS_NO_LOCAL		0x04
#define TM_PUB_SUBS_RETAIN_AS_PUB	0x08
#define TM_PUB_SUBS_RETHND_DEFAULT	0x00
#define TM_PUB_SUBS_RETHND_FIRST	0x10
#define TM_PUB_SUBS_RETHND_NO		0x20

//	pub flags
#define TM_PUBF_ADD_HDR				0x04
#define	TM_PUBF_OVERFLOW			0x80

TMC_IMPEX BOOL	_STDCALL tmcPubPublish(DWORD cid,LPSTR name, DWORD life_time, BYTE qos, PBYTE p_data, DWORD cb_data);

TMC_IMPEX BOOL	_STDCALL tmcPubSubscribe(DWORD cid,LPSTR name,DWORD subs_id,BYTE qos);

TMC_IMPEX BOOL	_STDCALL tmcPubAck(DWORD cid,LPSTR name,DWORD subs_id,BYTE qos,DWORD user_id,PVOID ack_data, DWORD cb_ack_data);

TMC_IMPEX BOOL	_STDCALL tmcPubUnsubscribe(DWORD cid,LPSTR name,DWORD subs_id);

TMC_IMPEX PBYTE	_STDCALL tmcPubGetRetainedData(DWORD cid,LPSTR name,PDWORD pcb_data); //null on error, use tmcFreeMemory() otherwise

TMC_IMPEX LPSTR	_STDCALL tmcPubGetRetainedInfo(DWORD cid,LPSTR name); //null on error, use tmcFreeMemory() otherwise

TMC_IMPEX LPSTR	_STDCALL tmcPubRetainedEnum(DWORD cid,LPSTR name); //null on error, use tmcFreeMemory() otherwise

TMC_IMPEX BOOL _STDCALL tmcPubParseDatagram(
	PBYTE	p_dgram,			//in
	DWORD	cb_dgram,			//in
	LPSTR	*p_tag,				//out
	PBYTE	*pp_data,			//out
	PDWORD	p_cb_data,			//out
	PDWORD	p_subs_id,			//out
	PBYTE	p_qos,				//out
	PBOOL	p_retained,			//out, can be NULL
	PBYTE	p_pub_flg			//out, can be NULL
);

//****************************************************************

TMC_IMPEX DWORD _STDCALL tmcAggrXact(DWORD cid,PVOID p_out,DWORD cb_out,PVOID p_in,DWORD cb_in);

//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL String2Utime(const char *DateTime);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL Utime2Str(DWORD t,char* buffer);

///////////////////////////////////////////////////////////////////////////////////
/////////////	K E Y   F U N C T I O N S
//////////////////////////////////////////////////////////////////////
TMC_IMPEX DWORD  _STDCALL tmcKeyGetTypeFlags(
	DWORD Type
);

#define TMC_KEY_TYPE_VALID		1
#define TMC_KEY_TYPE_WRITABLE	2
#define TMC_KEY_TYPE_DALLAS		4

TMC_IMPEX BOOL _STDCALL tmcKeyReadId(
	DWORD	type,
	DWORD	port,
	PBYTE	key_id			// OUT 8 BYTES
);

TMC_IMPEX BOOL  _STDCALL tmcKeyReadSubkey(
	DWORD	type,
	DWORD	port,
	PBYTE	key_id,			// OUT 8 BYTES
	PBYTE	password,		// IN 8 BYTES
	PBYTE	signature,		// IN 8 BYTES
	BYTE	sub_key_num,	// 0,1,2
	PBYTE	sub_key			// OUT 48 BYTES
);

TMC_IMPEX BOOL  _STDCALL tmcKeyWriteSubkey(
	DWORD	type,
	DWORD	port,
	PBYTE	password,		// IN 8 BYTES
	PBYTE	signature,		// IN 8 BYTES
	BYTE	sub_key_num,	// IN 0,1,2
	PBYTE	sub_key			// IN 48 BYTES
);

TMC_IMPEX BOOL  _STDCALL tmcKeyReadScratchPad(
	DWORD type,
	DWORD port,
	PBYTE key_id,			// OUT 8 BYTES
	PBYTE scratch_pad		// OUT 64 BYTES
);

TMC_IMPEX BOOL  _STDCALL tmcKeyWriteScratchPad(
	DWORD type,
	DWORD port,
	PBYTE scratch_pad		// IN 64 BYTES
);
//////////////////////////////////////////////////////////////////////
/////////////	D E L T A   F U N C T I O N S
//////////////////////////////////////////////////////////////////////
#pragma pack (1)

typedef struct {
	BYTE cmd[2];  //'D','P'
	BYTE prot;
	BYTE res;
	DWORD D;
	DWORD A;
	DWORD P;
	DWORD err;
}DELTA_USER_POST;

typedef struct {
	DWORD ft12_addr;
	DWORD typid;
	DWORD vsc;
	DWORD cot;
	DWORD asdu_addr;
}DELTA_GEN103_PAKHDR;

#pragma pack()
#define DNT_USERBUF_CMD_ATTACH		0
#define DNT_USERBUF_CMD_DETACH		1
#define DNT_USERBUF_ATTACH_GEN103	0x81

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntGetConfig(DWORD cid,LPSTR fname);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntRegisterUser(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntUnRegisterUser(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntBeginTrace(DWORD cid,DWORD count,PDWORD pmask);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntStopTrace(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcDntTreeChange(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX LPSTR _STDCALL tmcDntGetReserveState(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX LPVOID _STDCALL tmcDntOpenItem(DWORD cid,DWORD count,PDWORD pmask);
//****************************************************************		IMPLEMENTED
TMC_IMPEX DeltaCommon* _STDCALL tmcDntGetNextItem(LPVOID itid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX VOID  _STDCALL tmcDntCloseItem(LPVOID itid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntBeginDebug(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntStopDebug(DWORD cid);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntTeleControl(DWORD cid,DWORD count,PDWORD pmask,DWORD idx,DWORD cmd);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntReqValue(DWORD cid,DWORD count,PDWORD pmask,DWORD idx);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntWriteValue(DWORD cid,DWORD count,PDWORD pmask,DWORD idx,LPSTR value);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntPassPortBuffer(DWORD cid,DWORD masklen,PDWORD pmask,PBYTE pData,DWORD cbData);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntGetObjectName( DWORD cid ,WORD object_type,
		short Ch,short RTU,short Point,LPSTR buf,int buflen);
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntSetPortCapture(DWORD cid,BYTE driver,BYTE adapter,BYTE port);
//****************************************************************		IMPLEMENTED
TMC_IMPEX INT _STDCALL tmcDntGetPortCapture(DWORD cid,BYTE driver,BYTE adapter,BYTE port);
// returns 0 if not captured, 1 if captured by us, -1 if not by us or on error
//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntReleasePortCapture(DWORD cid,BYTE driver,BYTE adapter,BYTE port);
//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcDntGetLiveInfo(DWORD cid,DWORD count,PDWORD pmask,PVOID p_data,DWORD cb_data);
//****************************************************************		IMPLEMENTED
TMC_IMPEX DWORD _STDCALL tmcDntGetPortStats(DWORD cid,PDWORD p_dap,LPSTR buf, DWORD cb_buf);

//****************************************************************		IMPLEMENTED
TMC_IMPEX BOOL _STDCALL tmcDntSendPortPacket(
	DWORD cid,
	BYTE driver,
	BYTE adapter,
	BYTE port,
	BYTE proto,
	BYTE timeout,
	PBYTE pPacket,
	DWORD cbPacket
);
//****************************************************************		


//////////////////////////////////////////////////////////////////

TMC_IMPEX DWORD	_STDCALL tcapConnectDelta(LPSTR machine,LPSTR pipe,tcapRecvFunc rcv, LPSTR* perr);
TMC_IMPEX VOID	_STDCALL tcapDisconnectDelta(DWORD cid);
TMC_IMPEX LPSTR	_STDCALL tcapAttachNode(DWORD cid,DWORD masklen,PDWORD pmask,BYTE prot);
TMC_IMPEX LPSTR	_STDCALL tcapAttachNodeEx(DWORD cid,DWORD masklen,PDWORD pmask,BYTE prot,BYTE kind);
TMC_IMPEX LPSTR	_STDCALL tcapDetachNode(DWORD cid,DWORD masklen,PDWORD pmask,BYTE prot);
TMC_IMPEX LPSTR	_STDCALL tcapSendPacket(DWORD cid,PBYTE pData,DWORD cbData,DWORD masklen,PDWORD pmask,BYTE prot);
TMC_IMPEX VOID	_STDCALL tcapFreeMemory(PVOID p);



//////////////////////////////////////////////////////////////////
///////////////////// RBASE CONSTANTS AND FUNCTIONS

/*------------------ Константы кодов ошибок -----------------------*/
#define GL_OK         0
#define GL_BLOK       1
#define GL_ERROR_DISK 2
#define GL_ERROR_LINE 3
#define GL_FAULT      4

/*--------------- Константы для сетевого доступа ------------------*/
#define rbSYSTEM_DATE        1
#define rbINIT_BASE          9
#define rbUNBLOK_BASE       12

#define rbDELETE_STR        30
#define rbCALC_TABLE        40
#define rbADD_STR           50
#define rbREAD_STR          60
#define rbRESET_TABLE       70
#define rbUNBLOK_TABLE      80
#define rbFIND_STR          90

#define rbWRITE_STR        100
#define rbCALC_WHERE       101
#define rbDEL_WHERE        102
#define rbADD_PLUS         103
#define rbADD_MINUS        104
#define rbTEST_WHERE       105

#define rbTEST_TABLE       130
#define rbSET_WHERE        140
#define rbFIND_MIN_MAX     150
#define rbFIND_COL         170
#define rbWRITE_COL        180
#define rbDELETE_ALL       190

#define rbADD_GR_STR       200
#define rbREAD_COL         210
#define rbREAD_ADR_COL     220
#define rbREAD_ADR_STR     230
#define rbTABLE_INFO       250
#define rbSET_BLOK_TABLE   260
#define rbGET_USURPER_NAME 270

#define TEST              1000

#define STRUCT_GLOBAS   DWORD	 RecAdr

#define MAXBASE 16
#define MAX_BASES MAXBASE
#define MAXTAB  30

/*---------------------- Модификаторы  ------------------------*/
#define GBLOK     0x1000    // Чтение с блокировкой
#define GUNBLOK   0x1000
#define ADD_MAX   0x1000    // Для FindMinMax - резервирование номера
#define ADD_MIN   0x2000    // Для FindMinMax - резервирование номера
#define REVERSE   0x4000    // Чтение в обратном направлен

/*------------------- Константы условий -----------------------*/
#define _LIKE_     1        // Текстовые поля
#define _LE_       2        // Меньше или равно
#define _LT_       3        // Меньше
#define _GE_       4        // Больше или равно
#define _GT_       5        // Больше
#define _EQ_       6        // Равно
#define _BETWEEN_  8        // В диапазоне
#define _NULL_     7        // Нет значения

TMC_IMPEX int	_CDECL rbcOpenBases		(DWORD cid,/*char *BaseName,*/ ...);
TMC_IMPEX void	_CDECL rbcCloseBases	(DWORD cid);
TMC_IMPEX int	_CDECL rbcOpenTable		(DWORD cid, char *Base, char *Table);
TMC_IMPEX int	_CDECL rbcRecSize		(DWORD cid, int hTable );
TMC_IMPEX int	_CDECL rbcColSize		(DWORD cid, int hTable, int Column);
TMC_IMPEX int	_CDECL rbcResetTable	(DWORD cid, int hTable);
TMC_IMPEX int	_CDECL rbcReadStr		(DWORD cid, int hTable, int RecCount, void *Record);
TMC_IMPEX int	_CDECL rbcReadCol		(DWORD cid, int hTable, int RecCount, void *Record,/* int Column1,*/ ...);
TMC_IMPEX int	_CDECL rbcReadAdrStr	(DWORD cid, int hTable, int RecAdr, void *Record);
TMC_IMPEX int	_CDECL rbcReadAdrCol	(DWORD cid, int hTable, DWORD RecAdr, void *Record,/* int Column1,*/ ...);
TMC_IMPEX int	_CDECL rbcSetWhere		(DWORD cid, int hTable, /*DWORD Column,*/ ...);
TMC_IMPEX int	_CDECL rbcTestWhere		(DWORD cid, int hTable, /*DWORD Column,*/ ...);
TMC_IMPEX int	_CDECL rbcCalcWhere		(DWORD cid, int hTable, /*DWORD Column,*/ ...);
TMC_IMPEX int	_CDECL rbcFindStr		(DWORD cid, int hTable, int RecCount, void *Record);
TMC_IMPEX int	_CDECL rbcFindCol		(DWORD cid, int hTable, int RecCount, void *Record, /*int Column1,*/ ...);
TMC_IMPEX int	_CDECL rbcFindMinMax	(DWORD cid,int hTable, int Column, int *MinVal, int *MaxVal);
TMC_IMPEX int	_CDECL rbcCalcTable		(DWORD cid,int hTable);
TMC_IMPEX int	_CDECL rbcTestTable		(DWORD cid,int hTable);
TMC_IMPEX int	_CDECL rbcWriteStr		(DWORD cid,int hTable, void *Record);
TMC_IMPEX int	_CDECL rbcWriteCol		(DWORD cid,int hTable, void *Record, /*int Column1,*/ ...);
TMC_IMPEX int	_CDECL rbcAddStr		(DWORD cid,int hTable, void *Record);
TMC_IMPEX int	_CDECL rbcAddStrEx		(DWORD cid,int hTable, int RecCount, void *Records);
TMC_IMPEX int	_CDECL rbcAddStrInc		(DWORD cid, int hTable, int Column, void *Record);
TMC_IMPEX int	_CDECL rbcAddStrDec		(DWORD cid,int hTable, int Column, void *Record);
TMC_IMPEX int	_CDECL rbcDeleteStr		(DWORD cid,int hTable, void *Record);
TMC_IMPEX int	_CDECL rbcDeleteAll		(DWORD cid,int hTable);
TMC_IMPEX int	_CDECL rbcDeleteWhere	(DWORD cid, int hTable, /*unsigned Column,*/ ...);
TMC_IMPEX int	_CDECL rbcLockStr		(DWORD cid, int hTable, unsigned RecNum);
TMC_IMPEX int	_CDECL rbcGetUsurperName	(DWORD cid, int hBase, unsigned RecNum,LPSTR pName,DWORD cbName);

TMC_IMPEX int	_CDECL rbcUnlockStr		(DWORD cid, int hTable, unsigned RecNum);
TMC_IMPEX int	_CDECL rbcUnlockBases	(DWORD cid);
TMC_IMPEX unsigned _CDECL rbcRecCount	(DWORD cid,int hTable);
TMC_IMPEX int	_CDECL rbcGetSecurity	(DWORD cid,PBOOL pAdmin,PDWORD pAccessMask);
TMC_IMPEX int	_CDECL rbcGetUserId		(DWORD cid,PCHAR UserId /* max 16 */,PCHAR UserPwd /*max 32*/);
TMC_IMPEX int	_CDECL rbcReadUserId	(DWORD cid,DWORD index,PBOOL pDone,PBYTE UserSid /*max 128*/,
											PCHAR UserId /* max 16 */,PCHAR UserPwd /*max 32*/);
TMC_IMPEX int	_CDECL rbcWriteUserId	(DWORD cid,DWORD index,PBYTE UserSid /*max 128*/,
											PCHAR UserId /* max 16 */,PCHAR UserPwd /*max 32*/);
TMC_IMPEX LPSTR _CDECL rbcWsEnumDomains	(DWORD cid);
TMC_IMPEX LPSTR _CDECL rbcWsEnumDomainUsers(DWORD cid,LPSTR domain);
TMC_IMPEX PVOID _CDECL rbcWsGetUserSid	(DWORD cid,LPSTR domain,LPSTR user);
TMC_IMPEX BOOL	_CDECL rbcWsGetUserName	(DWORD cid,PVOID pSid,LPSTR domain /*max=128*/,LPSTR user/*max=128*/);
TMC_IMPEX LPSTR _STDCALL rbcGetReserveState(DWORD cid);

TMC_IMPEX BOOL _CDECL rbcBackupServerProcedure(
	LPSTR machine,
	LPSTR pipe,
	LPSTR directory,
	PDWORD pbflags,
	HANDLE hCancel,
	tmcProgressFn prog_fn,
	LPVOID prog_parm
);

TMC_IMPEX WORD	_CDECL	rbcIpgStartRedirector(DWORD cid,WORD portidx);
TMC_IMPEX BOOL	_CDECL	rbcIpgStopRedirector( DWORD cid,WORD portidx);

///////////////////////// TQI
#ifdef USE_TQI
#include "tmconn_tqi.h"
#endif
///////////////////////// INTERNAL
TMC_IMPEX DWORD _STDCALL tmcGetCurrentXaction(DWORD cid);

#ifdef __cplusplus
}
#endif

#endif //_TMCONN_H
