#ifndef _PC_WERR_H
#define _PC_WERR_H


//////////////////////////////////////////////////////////
// IF specific

#define pR_ERROR_SAME_FILETIME			0x80ffffff

#define pR_ERROR_BAD_DATA_RECEIVED		21200
#define pR_ERROR_CFS_INTERNAL			21201
#define pR_ERROR_LOCAL_EXCEPTION		21202
#define pR_ERROR_NOT_INITIALIZED		21203
#define pR_ERROR_SERVER_INTERNAL		21204
#define pR_ERROR_LOCAL_UNKNOWN			21205
#define pR_ERROR_STRUCTURE_FORMAT		21206

#define pR_ERROR_BAD_DATA_0				21250
#define pR_ERROR_BAD_DATA_1				21251
#define pR_ERROR_BAD_DATA_2				21252
#define pR_ERROR_BAD_DATA_3				21253
#define pR_ERROR_BAD_DATA_4				21254
#define pR_ERROR_BAD_DATA_5				21255

#define pR_EXIT_CODE_RESTART			21300
#define pR_EXIT_CODE_NO_RESTART			21301

#define TMDERR_SUCCESS				0
#define TMDERR_BASE					21000
#define TMDERR_UNKNOWN				(TMDERR_BASE+0)
#define TMDERR_NO_SUCHDEV 			(TMDERR_BASE+1)
#define TMDERR_WRONG_PACKET			(TMDERR_BASE+2)
#define TMDERR_SEND_FAILED			(TMDERR_BASE+3)
#define TMDERR_UNKNOWN_ADDRESS		(TMDERR_BASE+4)
#define TMDERR_BAD_LOC_ADAPTER		(TMDERR_BASE+5)
#define TMDERR_EXCEPTION			(TMDERR_BASE+6)
#define TMDERR_WRONG_DRIVER			(TMDERR_BASE+7)
#define TMDERR_WRONG_ADAPTER		(TMDERR_BASE+8)
#define TMDERR_WRONG_PORT			(TMDERR_BASE+9)
#define TMDERR_WRONG_PROTO			(TMDERR_BASE+10)
#define TMDERR_NO_RESOURCES			(TMDERR_BASE+11)
#define TMDERR_DRIVER_INIT			(TMDERR_BASE+12)
#define TMDERR_INVALID_PARAMETER	(TMDERR_BASE+13)
#define TMDERR_BROKEN_STRUCT		(TMDERR_BASE+14)
#define TMDERR_LOAD_TMLIB			(TMDERR_BASE+15)
#define TMDERR_WRONG_TMLIB			(TMDERR_BASE+16)
#define TMDERR_ANOTHER_TMLIB		(TMDERR_BASE+17)
#define TMDERR_NOT_SUPPORTED		(TMDERR_BASE+18)
#define TMDERR_DEFINE_ADDR			(TMDERR_BASE+19)

#define TMDERR_NONCR__ 				(TMDERR_BASE+128)
#define TMDERR_ACK_TIMEOUT			(TMDERR_NONCR__+0)
#define TMDERR_NETWORK_UNKNOWN		(TMDERR_NONCR__+1)
#define TMDERR_NOTMSERVER			(TMDERR_NONCR__+2)
#define TMDERR_TMSUNREACH			(TMDERR_NONCR__+3)
#define TMDERR_CANCELLED			(TMDERR_NONCR__+4)

#define TMDERR_MAX					(TMDERR_BASE+199)


//////////////////////////////////////////////////////////
//
// MessageId: pR_ERROR_SUCCESS
//
// MessageText:
//
//  The operation completed successfully.
//
#define pR_ERROR_SUCCESS                    0L
#define pR_NO_ERROR							0L

#ifndef	NO_ERROR
#define NO_ERROR 0L                                                 // dderror
#endif

//
// MessageId: pR_ERROR_INVALID_FUNCTION
//
// MessageText:
//
//  Incorrect function.
//
#define pR_ERROR_INVALID_FUNCTION           1L    // dderror

//
// MessageId: pR_ERROR_FILE_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the file specified.
//
#define pR_ERROR_FILE_NOT_FOUND             2L

//
// MessageId: pR_ERROR_PATH_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the path specified.
//
#define pR_ERROR_PATH_NOT_FOUND             3L

//
// MessageId: pR_ERROR_TOO_MANY_OPEN_FILES
//
// MessageText:
//
//  The system cannot open the file.
//
#define pR_ERROR_TOO_MANY_OPEN_FILES        4L

//
// MessageId: pR_ERROR_ACCESS_DENIED
//
// MessageText:
//
//  Access is denied.
//
#define pR_ERROR_ACCESS_DENIED              5L

//
// MessageId: pR_ERROR_INVALID_HANDLE
//
// MessageText:
//
//  The handle is invalid.
//
#define pR_ERROR_INVALID_HANDLE             6L

//
// MessageId: pR_ERROR_ARENA_TRASHED
//
// MessageText:
//
//  The storage control blocks were destroyed.
//
#define pR_ERROR_ARENA_TRASHED              7L

//
// MessageId: pR_ERROR_NOT_ENOUGH_MEMORY
//
// MessageText:
//
//  Not enough storage is available to process this command.
//
#define pR_ERROR_NOT_ENOUGH_MEMORY          8L    // dderror

//
// MessageId: pR_ERROR_INVALID_BLOCK
//
// MessageText:
//
//  The storage control block address is invalid.
//
#define pR_ERROR_INVALID_BLOCK              9L

//
// MessageId: pR_ERROR_BAD_ENVIRONMENT
//
// MessageText:
//
//  The environment is incorrect.
//
#define pR_ERROR_BAD_ENVIRONMENT            10L

//
// MessageId: pR_ERROR_BAD_FORMAT
//
// MessageText:
//
//  An attempt was made to load a program with an
//  incorrect format.
//
#define pR_ERROR_BAD_FORMAT                 11L

//
// MessageId: pR_ERROR_INVALID_ACCESS
//
// MessageText:
//
//  The access code is invalid.
//
#define pR_ERROR_INVALID_ACCESS             12L

//
// MessageId: pR_ERROR_INVALID_DATA
//
// MessageText:
//
//  The data is invalid.
//
#define pR_ERROR_INVALID_DATA               13L

//
// MessageId: pR_ERROR_OUTOFMEMORY
//
// MessageText:
//
//  Not enough storage is available to complete this operation.
//
#define pR_ERROR_OUTOFMEMORY                14L

//
// MessageId: pR_ERROR_INVALID_DRIVE
//
// MessageText:
//
//  The system cannot find the drive specified.
//
#define pR_ERROR_INVALID_DRIVE              15L

//
// MessageId: pR_ERROR_CURRENT_DIRECTORY
//
// MessageText:
//
//  The directory cannot be removed.
//
#define pR_ERROR_CURRENT_DIRECTORY          16L

//
// MessageId: pR_ERROR_NOT_SAME_DEVICE
//
// MessageText:
//
//  The system cannot move the file
//  to a different disk drive.
//
#define pR_ERROR_NOT_SAME_DEVICE            17L

//
// MessageId: pR_ERROR_NO_MORE_FILES
//
// MessageText:
//
//  There are no more files.
//
#define pR_ERROR_NO_MORE_FILES              18L

//
// MessageId: pR_ERROR_WRITE_PROTECT
//
// MessageText:
//
//  The media is write protected.
//
#define pR_ERROR_WRITE_PROTECT              19L

//
// MessageId: pR_ERROR_BAD_UNIT
//
// MessageText:
//
//  The system cannot find the device specified.
//
#define pR_ERROR_BAD_UNIT                   20L

//
// MessageId: pR_ERROR_NOT_READY
//
// MessageText:
//
//  The device is not ready.
//
#define pR_ERROR_NOT_READY                  21L

//
// MessageId: pR_ERROR_BAD_COMMAND
//
// MessageText:
//
//  The device does not recognize the command.
//
#define pR_ERROR_BAD_COMMAND                22L

//
// MessageId: pR_ERROR_CRC
//
// MessageText:
//
//  Data error (cyclic redundancy check).
//
#define pR_ERROR_CRC                        23L

//
// MessageId: pR_ERROR_BAD_LENGTH
//
// MessageText:
//
//  The program issued a command but the
//  command length is incorrect.
//
#define pR_ERROR_BAD_LENGTH                 24L

//
// MessageId: pR_ERROR_SEEK
//
// MessageText:
//
//  The drive cannot locate a specific
//  area or track on the disk.
//
#define pR_ERROR_SEEK                       25L

//
// MessageId: pR_ERROR_NOT_DOS_DISK
//
// MessageText:
//
//  The specified disk or diskette cannot be accessed.
//
#define pR_ERROR_NOT_DOS_DISK               26L

//
// MessageId: pR_ERROR_SECTOR_NOT_FOUND
//
// MessageText:
//
//  The drive cannot find the sector requested.
//
#define pR_ERROR_SECTOR_NOT_FOUND           27L

//
// MessageId: pR_ERROR_OUT_OF_PAPER
//
// MessageText:
//
//  The printer is out of paper.
//
#define pR_ERROR_OUT_OF_PAPER               28L

//
// MessageId: pR_ERROR_WRITE_FAULT
//
// MessageText:
//
//  The system cannot write to the specified device.
//
#define pR_ERROR_WRITE_FAULT                29L

//
// MessageId: pR_ERROR_READ_FAULT
//
// MessageText:
//
//  The system cannot read from the specified device.
//
#define pR_ERROR_READ_FAULT                 30L

//
// MessageId: pR_ERROR_GEN_FAILURE
//
// MessageText:
//
//  A device attached to the system is not functioning.
//
#define pR_ERROR_GEN_FAILURE                31L

//
// MessageId: pR_ERROR_SHARING_VIOLATION
//
// MessageText:
//
//  The process cannot access the file because
//  it is being used by another process.
//
#define pR_ERROR_SHARING_VIOLATION          32L

//
// MessageId: pR_ERROR_LOCK_VIOLATION
//
// MessageText:
//
//  The process cannot access the file because
//  another process has locked a portion of the file.
//
#define pR_ERROR_LOCK_VIOLATION             33L

//
// MessageId: pR_ERROR_WRONG_DISK
//
// MessageText:
//
//  The wrong diskette is in the drive.
//  Insert %2 (Volume Serial Number: %3)
//  into drive %1.
//
#define pR_ERROR_WRONG_DISK                 34L

//
// MessageId: pR_ERROR_SHARING_BUFFER_EXCEEDED
//
// MessageText:
//
//  Too many files opened for sharing.
//
#define pR_ERROR_SHARING_BUFFER_EXCEEDED    36L

//
// MessageId: pR_ERROR_HANDLE_EOF
//
// MessageText:
//
//  Reached the end of the file.
//
#define pR_ERROR_HANDLE_EOF                 38L

//
// MessageId: pR_ERROR_HANDLE_DISK_FULL
//
// MessageText:
//
//  The disk is full.
//
#define pR_ERROR_HANDLE_DISK_FULL           39L

//
// MessageId: pR_ERROR_NOT_SUPPORTED
//
// MessageText:
//
//  The network request is not supported.
//
#define pR_ERROR_NOT_SUPPORTED              50L

//
// MessageId: pR_ERROR_REM_NOT_LIST
//
// MessageText:
//
//  The remote computer is not available.
//
#define pR_ERROR_REM_NOT_LIST               51L

//
// MessageId: pR_ERROR_DUP_NAME
//
// MessageText:
//
//  A duplicate name exists on the network.
//
#define pR_ERROR_DUP_NAME                   52L

//
// MessageId: pR_ERROR_BAD_NETPATH
//
// MessageText:
//
//  The network path was not found.
//
#define pR_ERROR_BAD_NETPATH                53L

//
// MessageId: pR_ERROR_NETWORK_BUSY
//
// MessageText:
//
//  The network is busy.
//
#define pR_ERROR_NETWORK_BUSY               54L

//
// MessageId: pR_ERROR_DEV_NOT_EXIST
//
// MessageText:
//
//  The specified network resource or device is no longer
//  available.
//
#define pR_ERROR_DEV_NOT_EXIST              55L    // dderror

//
// MessageId: pR_ERROR_TOO_MANY_CMDS
//
// MessageText:
//
//  The network BIOS command limit has been reached.
//
#define pR_ERROR_TOO_MANY_CMDS              56L

//
// MessageId: pR_ERROR_ADAP_HDW_ERR
//
// MessageText:
//
//  A network adapter hardware error occurred.
//
#define pR_ERROR_ADAP_HDW_ERR               57L

//
// MessageId: pR_ERROR_BAD_NET_RESP
//
// MessageText:
//
//  The specified server cannot perform the requested
//  operation.
//
#define pR_ERROR_BAD_NET_RESP               58L

//
// MessageId: pR_ERROR_UNEXP_NET_ERR
//
// MessageText:
//
//  An unexpected network error occurred.
//
#define pR_ERROR_UNEXP_NET_ERR              59L

//
// MessageId: pR_ERROR_BAD_REM_ADAP
//
// MessageText:
//
//  The remote adapter is not compatible.
//
#define pR_ERROR_BAD_REM_ADAP               60L

//
// MessageId: pR_ERROR_PRINTQ_FULL
//
// MessageText:
//
//  The printer queue is full.
//
#define pR_ERROR_PRINTQ_FULL                61L

//
// MessageId: pR_ERROR_NO_SPOOL_SPACE
//
// MessageText:
//
//  Space to store the file waiting to be printed is
//  not available on the server.
//
#define pR_ERROR_NO_SPOOL_SPACE             62L

//
// MessageId: pR_ERROR_PRINT_CANCELLED
//
// MessageText:
//
//  Your file waiting to be printed was deleted.
//
#define pR_ERROR_PRINT_CANCELLED            63L

//
// MessageId: pR_ERROR_NETNAME_DELETED
//
// MessageText:
//
//  The specified network name is no longer available.
//
#define pR_ERROR_NETNAME_DELETED            64L

//
// MessageId: pR_ERROR_NETWORK_ACCESS_DENIED
//
// MessageText:
//
//  Network access is denied.
//
#define pR_ERROR_NETWORK_ACCESS_DENIED      65L

//
// MessageId: pR_ERROR_BAD_DEV_TYPE
//
// MessageText:
//
//  The network resource type is not correct.
//
#define pR_ERROR_BAD_DEV_TYPE               66L

//
// MessageId: pR_ERROR_BAD_NET_NAME
//
// MessageText:
//
//  The network name cannot be found.
//
#define pR_ERROR_BAD_NET_NAME               67L

//
// MessageId: pR_ERROR_TOO_MANY_NAMES
//
// MessageText:
//
//  The name limit for the local computer network
//  adapter card was exceeded.
//
#define pR_ERROR_TOO_MANY_NAMES             68L

//
// MessageId: pR_ERROR_TOO_MANY_SESS
//
// MessageText:
//
//  The network BIOS session limit was exceeded.
//
#define pR_ERROR_TOO_MANY_SESS              69L

//
// MessageId: pR_ERROR_SHARING_PAUSED
//
// MessageText:
//
//  The remote server has been paused or is in the
//  process of being started.
//
#define pR_ERROR_SHARING_PAUSED             70L

//
// MessageId: pR_ERROR_REQ_NOT_ACCEP
//
// MessageText:
//
//  No more connections can be made to this remote computer at this time
//  because there are already as many connections as the computer can accept.
//
#define pR_ERROR_REQ_NOT_ACCEP              71L

//
// MessageId: pR_ERROR_REDIR_PAUSED
//
// MessageText:
//
//  The specified printer or disk device has been paused.
//
#define pR_ERROR_REDIR_PAUSED               72L

//
// MessageId: pR_ERROR_FILE_EXISTS
//
// MessageText:
//
//  The file exists.
//
#define pR_ERROR_FILE_EXISTS                80L

//
// MessageId: pR_ERROR_CANNOT_MAKE
//
// MessageText:
//
//  The directory or file cannot be created.
//
#define pR_ERROR_CANNOT_MAKE                82L

//
// MessageId: pR_ERROR_FAIL_I24
//
// MessageText:
//
//  Fail on INT 24.
//
#define pR_ERROR_FAIL_I24                   83L

//
// MessageId: pR_ERROR_OUT_OF_STRUCTURES
//
// MessageText:
//
//  Storage to process this request is not available.
//
#define pR_ERROR_OUT_OF_STRUCTURES          84L

//
// MessageId: pR_ERROR_ALREADY_ASSIGNED
//
// MessageText:
//
//  The local device name is already in use.
//
#define pR_ERROR_ALREADY_ASSIGNED           85L

//
// MessageId: pR_ERROR_INVALID_PASSWORD
//
// MessageText:
//
//  The specified network password is not correct.
//
#define pR_ERROR_INVALID_PASSWORD           86L

//
// MessageId: pR_ERROR_INVALID_PARAMETER
//
// MessageText:
//
//  The parameter is incorrect.
//
#define pR_ERROR_INVALID_PARAMETER          87L    // dderror

//
// MessageId: pR_ERROR_NET_WRITE_FAULT
//
// MessageText:
//
//  A write fault occurred on the network.
//
#define pR_ERROR_NET_WRITE_FAULT            88L

//
// MessageId: pR_ERROR_NO_PROC_SLOTS
//
// MessageText:
//
//  The system cannot start another process at
//  this time.
//
#define pR_ERROR_NO_PROC_SLOTS              89L

//
// MessageId: pR_ERROR_TOO_MANY_SEMAPHORES
//
// MessageText:
//
//  Cannot create another system semaphore.
//
#define pR_ERROR_TOO_MANY_SEMAPHORES        100L

//
// MessageId: pR_ERROR_EXCL_SEM_ALREADY_OWNED
//
// MessageText:
//
//  The exclusive semaphore is owned by another process.
//
#define pR_ERROR_EXCL_SEM_ALREADY_OWNED     101L

//
// MessageId: pR_ERROR_SEM_IS_SET
//
// MessageText:
//
//  The semaphore is set and cannot be closed.
//
#define pR_ERROR_SEM_IS_SET                 102L

//
// MessageId: pR_ERROR_TOO_MANY_SEM_REQUESTS
//
// MessageText:
//
//  The semaphore cannot be set again.
//
#define pR_ERROR_TOO_MANY_SEM_REQUESTS      103L

//
// MessageId: pR_ERROR_INVALID_AT_INTERRUPT_TIME
//
// MessageText:
//
//  Cannot request exclusive semaphores at interrupt time.
//
#define pR_ERROR_INVALID_AT_INTERRUPT_TIME  104L

//
// MessageId: pR_ERROR_SEM_OWNER_DIED
//
// MessageText:
//
//  The previous ownership of this semaphore has ended.
//
#define pR_ERROR_SEM_OWNER_DIED             105L

//
// MessageId: pR_ERROR_SEM_USER_LIMIT
//
// MessageText:
//
//  Insert the diskette for drive %1.
//
#define pR_ERROR_SEM_USER_LIMIT             106L

//
// MessageId: pR_ERROR_DISK_CHANGE
//
// MessageText:
//
//  The program stopped because an alternate diskette was not inserted.
//
#define pR_ERROR_DISK_CHANGE                107L

//
// MessageId: pR_ERROR_DRIVE_LOCKED
//
// MessageText:
//
//  The disk is in use or locked by
//  another process.
//
#define pR_ERROR_DRIVE_LOCKED               108L

//
// MessageId: pR_ERROR_BROKEN_PIPE
//
// MessageText:
//
//  The pipe has been ended.
//
#define pR_ERROR_BROKEN_PIPE                109L

//
// MessageId: pR_ERROR_OPEN_FAILED
//
// MessageText:
//
//  The system cannot open the
//  device or file specified.
//
#define pR_ERROR_OPEN_FAILED                110L

//
// MessageId: pR_ERROR_BUFFER_OVERFLOW
//
// MessageText:
//
//  The file name is too long.
//
#define pR_ERROR_BUFFER_OVERFLOW            111L

//
// MessageId: pR_ERROR_DISK_FULL
//
// MessageText:
//
//  There is not enough space on the disk.
//
#define pR_ERROR_DISK_FULL                  112L

//
// MessageId: pR_ERROR_NO_MORE_SEARCH_HANDLES
//
// MessageText:
//
//  No more internal file identifiers available.
//
#define pR_ERROR_NO_MORE_SEARCH_HANDLES     113L

//
// MessageId: pR_ERROR_INVALID_TARGET_HANDLE
//
// MessageText:
//
//  The target internal file identifier is incorrect.
//
#define pR_ERROR_INVALID_TARGET_HANDLE      114L

//
// MessageId: pR_ERROR_INVALID_CATEGORY
//
// MessageText:
//
//  The IOCTL call made by the application program is
//  not correct.
//
#define pR_ERROR_INVALID_CATEGORY           117L

//
// MessageId: pR_ERROR_INVALID_VERIFY_SWITCH
//
// MessageText:
//
//  The verify-on-write switch parameter value is not
//  correct.
//
#define pR_ERROR_INVALID_VERIFY_SWITCH      118L

//
// MessageId: pR_ERROR_BAD_DRIVER_LEVEL
//
// MessageText:
//
//  The system does not support the command requested.
//
#define pR_ERROR_BAD_DRIVER_LEVEL           119L

//
// MessageId: pR_ERROR_CALL_NOT_IMPLEMENTED
//
// MessageText:
//
//  This function is not supported on this system.
//
#define pR_ERROR_CALL_NOT_IMPLEMENTED       120L

//
// MessageId: pR_ERROR_SEM_TIMEOUT
//
// MessageText:
//
//  The semaphore timeout period has expired.
//
#define pR_ERROR_SEM_TIMEOUT                121L

//
// MessageId: pR_ERROR_INSUFFICIENT_BUFFER
//
// MessageText:
//
//  The data area passed to a system call is too
//  small.
//
#define pR_ERROR_INSUFFICIENT_BUFFER        122L    // dderror

//
// MessageId: pR_ERROR_INVALID_NAME
//
// MessageText:
//
//  The filename, directory name, or volume label syntax is incorrect.
//
#define pR_ERROR_INVALID_NAME               123L

//
// MessageId: pR_ERROR_INVALID_LEVEL
//
// MessageText:
//
//  The system call level is not correct.
//
#define pR_ERROR_INVALID_LEVEL              124L

//
// MessageId: pR_ERROR_NO_VOLUME_LABEL
//
// MessageText:
//
//  The disk has no volume label.
//
#define pR_ERROR_NO_VOLUME_LABEL            125L

//
// MessageId: pR_ERROR_MOD_NOT_FOUND
//
// MessageText:
//
//  The specified module could not be found.
//
#define pR_ERROR_MOD_NOT_FOUND              126L

//
// MessageId: pR_ERROR_PROC_NOT_FOUND
//
// MessageText:
//
//  The specified procedure could not be found.
//
#define pR_ERROR_PROC_NOT_FOUND             127L

//
// MessageId: pR_ERROR_WAIT_NO_CHILDREN
//
// MessageText:
//
//  There are no child processes to wait for.
//
#define pR_ERROR_WAIT_NO_CHILDREN           128L

//
// MessageId: pR_ERROR_CHILD_NOT_COMPLETE
//
// MessageText:
//
//  The %1 application cannot be run in Win32 mode.
//
#define pR_ERROR_CHILD_NOT_COMPLETE         129L

//
// MessageId: pR_ERROR_DIRECT_ACCESS_HANDLE
//
// MessageText:
//
//  Attempt to use a file handle to an open disk partition for an
//  operation other than raw disk I/O.
//
#define pR_ERROR_DIRECT_ACCESS_HANDLE       130L

//
// MessageId: pR_ERROR_NEGATIVE_SEEK
//
// MessageText:
//
//  An attempt was made to move the file pointer before the beginning of the file.
//
#define pR_ERROR_NEGATIVE_SEEK              131L

//
// MessageId: pR_ERROR_SEEK_ON_DEVICE
//
// MessageText:
//
//  The file pointer cannot be set on the specified device or file.
//
#define pR_ERROR_SEEK_ON_DEVICE             132L

//
// MessageId: pR_ERROR_IS_JOIN_TARGET
//
// MessageText:
//
//  A JOIN or SUBST command
//  cannot be used for a drive that
//  contains previously joined drives.
//
#define pR_ERROR_IS_JOIN_TARGET             133L

//
// MessageId: pR_ERROR_IS_JOINED
//
// MessageText:
//
//  An attempt was made to use a
//  JOIN or SUBST command on a drive that has
//  already been joined.
//
#define pR_ERROR_IS_JOINED                  134L

//
// MessageId: pR_ERROR_IS_SUBSTED
//
// MessageText:
//
//  An attempt was made to use a
//  JOIN or SUBST command on a drive that has
//  already been substituted.
//
#define pR_ERROR_IS_SUBSTED                 135L

//
// MessageId: pR_ERROR_NOT_JOINED
//
// MessageText:
//
//  The system tried to delete
//  the JOIN of a drive that is not joined.
//
#define pR_ERROR_NOT_JOINED                 136L

//
// MessageId: pR_ERROR_NOT_SUBSTED
//
// MessageText:
//
//  The system tried to delete the
//  substitution of a drive that is not substituted.
//
#define pR_ERROR_NOT_SUBSTED                137L

//
// MessageId: pR_ERROR_JOIN_TO_JOIN
//
// MessageText:
//
//  The system tried to join a drive
//  to a directory on a joined drive.
//
#define pR_ERROR_JOIN_TO_JOIN               138L

//
// MessageId: pR_ERROR_SUBST_TO_SUBST
//
// MessageText:
//
//  The system tried to substitute a
//  drive to a directory on a substituted drive.
//
#define pR_ERROR_SUBST_TO_SUBST             139L

//
// MessageId: pR_ERROR_JOIN_TO_SUBST
//
// MessageText:
//
//  The system tried to join a drive to
//  a directory on a substituted drive.
//
#define pR_ERROR_JOIN_TO_SUBST              140L

//
// MessageId: pR_ERROR_SUBST_TO_JOIN
//
// MessageText:
//
//  The system tried to SUBST a drive
//  to a directory on a joined drive.
//
#define pR_ERROR_SUBST_TO_JOIN              141L

//
// MessageId: pR_ERROR_BUSY_DRIVE
//
// MessageText:
//
//  The system cannot perform a JOIN or SUBST at this time.
//
#define pR_ERROR_BUSY_DRIVE                 142L

//
// MessageId: pR_ERROR_SAME_DRIVE
//
// MessageText:
//
//  The system cannot join or substitute a
//  drive to or for a directory on the same drive.
//
#define pR_ERROR_SAME_DRIVE                 143L

//
// MessageId: pR_ERROR_DIR_NOT_ROOT
//
// MessageText:
//
//  The directory is not a subdirectory of the root directory.
//
#define pR_ERROR_DIR_NOT_ROOT               144L

//
// MessageId: pR_ERROR_DIR_NOT_EMPTY
//
// MessageText:
//
//  The directory is not empty.
//
#define pR_ERROR_DIR_NOT_EMPTY              145L

//
// MessageId: pR_ERROR_IS_SUBST_PATH
//
// MessageText:
//
//  The path specified is being used in
//  a substitute.
//
#define pR_ERROR_IS_SUBST_PATH              146L

//
// MessageId: pR_ERROR_IS_JOIN_PATH
//
// MessageText:
//
//  Not enough resources are available to
//  process this command.
//
#define pR_ERROR_IS_JOIN_PATH               147L

//
// MessageId: pR_ERROR_PATH_BUSY
//
// MessageText:
//
//  The path specified cannot be used at this time.
//
#define pR_ERROR_PATH_BUSY                  148L

//
// MessageId: pR_ERROR_IS_SUBST_TARGET
//
// MessageText:
//
//  An attempt was made to join
//  or substitute a drive for which a directory
//  on the drive is the target of a previous
//  substitute.
//
#define pR_ERROR_IS_SUBST_TARGET            149L

//
// MessageId: pR_ERROR_SYSTEM_TRACE
//
// MessageText:
//
//  System trace information was not specified in your
//  CONFIG.SYS file, or tracing is disallowed.
//
#define pR_ERROR_SYSTEM_TRACE               150L

//
// MessageId: pR_ERROR_INVALID_EVENT_COUNT
//
// MessageText:
//
//  The number of specified semaphore events for
//  DosMuxSemWait is not correct.
//
#define pR_ERROR_INVALID_EVENT_COUNT        151L

//
// MessageId: pR_ERROR_TOO_MANY_MUXWAITERS
//
// MessageText:
//
//  DosMuxSemWait did not execute; too many semaphores
//  are already set.
//
#define pR_ERROR_TOO_MANY_MUXWAITERS        152L

//
// MessageId: pR_ERROR_INVALID_LIST_FORMAT
//
// MessageText:
//
//  The DosMuxSemWait list is not correct.
//
#define pR_ERROR_INVALID_LIST_FORMAT        153L

//
// MessageId: pR_ERROR_LABEL_TOO_LONG
//
// MessageText:
//
//  The volume label you entered exceeds the label character
//  limit of the target file system.
//
#define pR_ERROR_LABEL_TOO_LONG             154L

//
// MessageId: pR_ERROR_TOO_MANY_TCBS
//
// MessageText:
//
//  Cannot create another thread.
//
#define pR_ERROR_TOO_MANY_TCBS              155L

//
// MessageId: pR_ERROR_SIGNAL_REFUSED
//
// MessageText:
//
//  The recipient process has refused the signal.
//
#define pR_ERROR_SIGNAL_REFUSED             156L

//
// MessageId: pR_ERROR_DISCARDED
//
// MessageText:
//
//  The segment is already discarded and cannot be locked.
//
#define pR_ERROR_DISCARDED                  157L

//
// MessageId: pR_ERROR_NOT_LOCKED
//
// MessageText:
//
//  The segment is already unlocked.
//
#define pR_ERROR_NOT_LOCKED                 158L

//
// MessageId: pR_ERROR_BAD_THREADID_ADDR
//
// MessageText:
//
//  The address for the thread ID is not correct.
//
#define pR_ERROR_BAD_THREADID_ADDR          159L

//
// MessageId: pR_ERROR_BAD_ARGUMENTS
//
// MessageText:
//
//  The argument string passed to DosExecPgm is not correct.
//
#define pR_ERROR_BAD_ARGUMENTS              160L

//
// MessageId: pR_ERROR_BAD_PATHNAME
//
// MessageText:
//
//  The specified path is invalid.
//
#define pR_ERROR_BAD_PATHNAME               161L

//
// MessageId: pR_ERROR_SIGNAL_PENDING
//
// MessageText:
//
//  A signal is already pending.
//
#define pR_ERROR_SIGNAL_PENDING             162L

//
// MessageId: pR_ERROR_MAX_THRDS_REACHED
//
// MessageText:
//
//  No more threads can be created in the system.
//
#define pR_ERROR_MAX_THRDS_REACHED          164L

//
// MessageId: pR_ERROR_LOCK_FAILED
//
// MessageText:
//
//  Unable to lock a region of a file.
//
#define pR_ERROR_LOCK_FAILED                167L

//
// MessageId: pR_ERROR_BUSY
//
// MessageText:
//
//  The requested resource is in use.
//
#define pR_ERROR_BUSY                       170L

//
// MessageId: pR_ERROR_CANCEL_VIOLATION
//
// MessageText:
//
//  A lock request was not outstanding for the supplied cancel region.
//
#define pR_ERROR_CANCEL_VIOLATION           173L

//
// MessageId: pR_ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
//
// MessageText:
//
//  The file system does not support atomic changes to the lock type.
//
#define pR_ERROR_ATOMIC_LOCKS_NOT_SUPPORTED 174L

//
// MessageId: pR_ERROR_INVALID_SEGMENT_NUMBER
//
// MessageText:
//
//  The system detected a segment number that was not correct.
//
#define pR_ERROR_INVALID_SEGMENT_NUMBER     180L

//
// MessageId: pR_ERROR_INVALID_ORDINAL
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_ORDINAL            182L

//
// MessageId: pR_ERROR_ALREADY_EXISTS
//
// MessageText:
//
//  Cannot create a file when that file already exists.
//
#define pR_ERROR_ALREADY_EXISTS             183L

//
// MessageId: pR_ERROR_INVALID_FLAG_NUMBER
//
// MessageText:
//
//  The flag passed is not correct.
//
#define pR_ERROR_INVALID_FLAG_NUMBER        186L

//
// MessageId: pR_ERROR_SEM_NOT_FOUND
//
// MessageText:
//
//  The specified system semaphore name was not found.
//
#define pR_ERROR_SEM_NOT_FOUND              187L

//
// MessageId: pR_ERROR_INVALID_STARTING_CODESEG
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_STARTING_CODESEG   188L

//
// MessageId: pR_ERROR_INVALID_STACKSEG
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_STACKSEG           189L

//
// MessageId: pR_ERROR_INVALID_MODULETYPE
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_MODULETYPE         190L

//
// MessageId: pR_ERROR_INVALID_EXE_SIGNATURE
//
// MessageText:
//
//  Cannot run %1 in Win32 mode.
//
#define pR_ERROR_INVALID_EXE_SIGNATURE      191L

//
// MessageId: pR_ERROR_EXE_MARKED_INVALID
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_EXE_MARKED_INVALID         192L

//
// MessageId: pR_ERROR_BAD_EXE_FORMAT
//
// MessageText:
//
//  %1 is not a valid Win32 application.
//
#define pR_ERROR_BAD_EXE_FORMAT             193L

//
// MessageId: pR_ERROR_ITERATED_DATA_EXCEEDS_64k
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_ITERATED_DATA_EXCEEDS_64k  194L

//
// MessageId: pR_ERROR_INVALID_MINALLOCSIZE
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_MINALLOCSIZE       195L

//
// MessageId: pR_ERROR_DYNLINK_FROM_INVALID_RING
//
// MessageText:
//
//  The operating system cannot run this
//  application program.
//
#define pR_ERROR_DYNLINK_FROM_INVALID_RING  196L

//
// MessageId: pR_ERROR_IOPL_NOT_ENABLED
//
// MessageText:
//
//  The operating system is not presently
//  configured to run this application.
//
#define pR_ERROR_IOPL_NOT_ENABLED           197L

//
// MessageId: pR_ERROR_INVALID_SEGDPL
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INVALID_SEGDPL             198L

//
// MessageId: pR_ERROR_AUTODATASEG_EXCEEDS_64k
//
// MessageText:
//
//  The operating system cannot run this
//  application program.
//
#define pR_ERROR_AUTODATASEG_EXCEEDS_64k    199L

//
// MessageId: pR_ERROR_RING2SEG_MUST_BE_MOVABLE
//
// MessageText:
//
//  The code segment cannot be greater than or equal to 64K.
//
#define pR_ERROR_RING2SEG_MUST_BE_MOVABLE   200L

//
// MessageId: pR_ERROR_RELOC_CHAIN_XEEDS_SEGLIM
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_RELOC_CHAIN_XEEDS_SEGLIM   201L

//
// MessageId: pR_ERROR_INFLOOP_IN_RELOC_CHAIN
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define pR_ERROR_INFLOOP_IN_RELOC_CHAIN     202L

//
// MessageId: pR_ERROR_ENVVAR_NOT_FOUND
//
// MessageText:
//
//  The system could not find the environment
//  option that was entered.
//
#define pR_ERROR_ENVVAR_NOT_FOUND           203L

//
// MessageId: pR_ERROR_NO_SIGNAL_SENT
//
// MessageText:
//
//  No process in the command subtree has a
//  signal handler.
//
#define pR_ERROR_NO_SIGNAL_SENT             205L

//
// MessageId: pR_ERROR_FILENAME_EXCED_RANGE
//
// MessageText:
//
//  The filename or extension is too long.
//
#define pR_ERROR_FILENAME_EXCED_RANGE       206L

//
// MessageId: pR_ERROR_RING2_STACK_IN_USE
//
// MessageText:
//
//  The ring 2 stack is in use.
//
#define pR_ERROR_RING2_STACK_IN_USE         207L

//
// MessageId: pR_ERROR_META_EXPANSION_TOO_LONG
//
// MessageText:
//
//  The global filename characters, * or ?, are entered
//  incorrectly or too many global filename characters are specified.
//
#define pR_ERROR_META_EXPANSION_TOO_LONG    208L

//
// MessageId: pR_ERROR_INVALID_SIGNAL_NUMBER
//
// MessageText:
//
//  The signal being posted is not correct.
//
#define pR_ERROR_INVALID_SIGNAL_NUMBER      209L

//
// MessageId: pR_ERROR_THREAD_1_INACTIVE
//
// MessageText:
//
//  The signal handler cannot be set.
//
#define pR_ERROR_THREAD_1_INACTIVE          210L

//
// MessageId: pR_ERROR_LOCKED
//
// MessageText:
//
//  The segment is locked and cannot be reallocated.
//
#define pR_ERROR_LOCKED                     212L

//
// MessageId: pR_ERROR_TOO_MANY_MODULES
//
// MessageText:
//
//  Too many dynamic-link modules are attached to this
//  program or dynamic-link module.
//
#define pR_ERROR_TOO_MANY_MODULES           214L

//
// MessageId: pR_ERROR_NESTING_NOT_ALLOWED
//
// MessageText:
//
//  Can't nest calls to LoadModule.
//
#define pR_ERROR_NESTING_NOT_ALLOWED        215L

//
// MessageId: pR_ERROR_EXE_MACHINE_TYPE_MISMATCH
//
// MessageText:
//
//  The image file %1 is valid, but is for a machine type other
//  than the current machine.
//
#define pR_ERROR_EXE_MACHINE_TYPE_MISMATCH  216L

//
// MessageId: pR_ERROR_BAD_PIPE
//
// MessageText:
//
//  The pipe state is invalid.
//
#define pR_ERROR_BAD_PIPE                   230L

//
// MessageId: pR_ERROR_PIPE_BUSY
//
// MessageText:
//
//  All pipe instances are busy.
//
#define pR_ERROR_PIPE_BUSY                  231L

//
// MessageId: pR_ERROR_NO_DATA
//
// MessageText:
//
//  The pipe is being closed.
//
#define pR_ERROR_NO_DATA                    232L

//
// MessageId: pR_ERROR_PIPE_NOT_CONNECTED
//
// MessageText:
//
//  No process is on the other end of the pipe.
//
#define pR_ERROR_PIPE_NOT_CONNECTED         233L

//
// MessageId: pR_ERROR_MORE_DATA
//
// MessageText:
//
//  More data is available.
//
#define pR_ERROR_MORE_DATA                  234L    // dderror

//
// MessageId: pR_ERROR_VC_DISCONNECTED
//
// MessageText:
//
//  The session was canceled.
//
#define pR_ERROR_VC_DISCONNECTED            240L

//
// MessageId: pR_ERROR_INVALID_EA_NAME
//
// MessageText:
//
//  The specified extended attribute name was invalid.
//
#define pR_ERROR_INVALID_EA_NAME            254L

//
// MessageId: pR_ERROR_EA_LIST_INCONSISTENT
//
// MessageText:
//
//  The extended attributes are inconsistent.
//
#define pR_ERROR_EA_LIST_INCONSISTENT       255L

//
// MessageId: pR_ERROR_NO_MORE_ITEMS
//
// MessageText:
//
//  No more data is available.
//
#define pR_ERROR_NO_MORE_ITEMS              259L

//
// MessageId: pR_ERROR_CANNOT_COPY
//
// MessageText:
//
//  The copy functions cannot be used.
//
#define pR_ERROR_CANNOT_COPY                266L

//
// MessageId: pR_ERROR_DIRECTORY
//
// MessageText:
//
//  The directory name is invalid.
//
#define pR_ERROR_DIRECTORY                  267L

//
// MessageId: pR_ERROR_EAS_DIDNT_FIT
//
// MessageText:
//
//  The extended attributes did not fit in the buffer.
//
#define pR_ERROR_EAS_DIDNT_FIT              275L

//
// MessageId: pR_ERROR_EA_FILE_CORRUPT
//
// MessageText:
//
//  The extended attribute file on the mounted file system is corrupt.
//
#define pR_ERROR_EA_FILE_CORRUPT            276L

//
// MessageId: pR_ERROR_EA_TABLE_FULL
//
// MessageText:
//
//  The extended attribute table file is full.
//
#define pR_ERROR_EA_TABLE_FULL              277L

//
// MessageId: pR_ERROR_INVALID_EA_HANDLE
//
// MessageText:
//
//  The specified extended attribute handle is invalid.
//
#define pR_ERROR_INVALID_EA_HANDLE          278L

//
// MessageId: pR_ERROR_EAS_NOT_SUPPORTED
//
// MessageText:
//
//  The mounted file system does not support extended attributes.
//
#define pR_ERROR_EAS_NOT_SUPPORTED          282L

//
// MessageId: pR_ERROR_NOT_OWNER
//
// MessageText:
//
//  Attempt to release mutex not owned by caller.
//
#define pR_ERROR_NOT_OWNER                  288L

//
// MessageId: pR_ERROR_TOO_MANY_POSTS
//
// MessageText:
//
//  Too many posts were made to a semaphore.
//
#define pR_ERROR_TOO_MANY_POSTS             298L

//
// MessageId: pR_ERROR_PARTIAL_COPY
//
// MessageText:
//
//  Only part of a ReadProcessMemoty or WriteProcessMemory request was completed.
//
#define pR_ERROR_PARTIAL_COPY               299L

//
// MessageId: pR_ERROR_OPLOCK_NOT_GRANTED
//
// MessageText:
//
//  The oplock request is denied.
//
#define pR_ERROR_OPLOCK_NOT_GRANTED         300L

//
// MessageId: pR_ERROR_INVALID_OPLOCK_PROTOCOL
//
// MessageText:
//
//  An invalid oplock acknowledgment was received by the system.
//
#define pR_ERROR_INVALID_OPLOCK_PROTOCOL    301L

//
// MessageId: pR_ERROR_MR_MID_NOT_FOUND
//
// MessageText:
//
//  The system cannot find message text for message number 0x%1
//  in the message file for %2.
//
#define pR_ERROR_MR_MID_NOT_FOUND           317L

//
// MessageId: pR_ERROR_INVALID_ADDRESS
//
// MessageText:
//
//  Attempt to access invalid address.
//
#define pR_ERROR_INVALID_ADDRESS            487L

//
// MessageId: pR_ERROR_ARITHMETIC_OVERFLOW
//
// MessageText:
//
//  Arithmetic result exceeded 32 bits.
//
#define pR_ERROR_ARITHMETIC_OVERFLOW        534L

//
// MessageId: pR_ERROR_PIPE_CONNECTED
//
// MessageText:
//
//  There is a process on other end of the pipe.
//
#define pR_ERROR_PIPE_CONNECTED             535L

//
// MessageId: pR_ERROR_PIPE_LISTENING
//
// MessageText:
//
//  Waiting for a process to open the other end of the pipe.
//
#define pR_ERROR_PIPE_LISTENING             536L

//
// MessageId: pR_ERROR_EA_ACCESS_DENIED
//
// MessageText:
//
//  Access to the extended attribute was denied.
//
#define pR_ERROR_EA_ACCESS_DENIED           994L

//
// MessageId: pR_ERROR_OPERATION_ABORTED
//
// MessageText:
//
//  The I/O operation has been aborted because of either a thread exit
//  or an application request.
//
#define pR_ERROR_OPERATION_ABORTED          995L

//
// MessageId: pR_ERROR_IO_INCOMPLETE
//
// MessageText:
//
//  Overlapped I/O event is not in a signaled state.
//
#define pR_ERROR_IO_INCOMPLETE              996L

//
// MessageId: pR_ERROR_IO_PENDING
//
// MessageText:
//
//  Overlapped I/O operation is in progress.
//
#define pR_ERROR_IO_PENDING                 997L    // dderror

//
// MessageId: pR_ERROR_NOACCESS
//
// MessageText:
//
//  Invalid access to memory location.
//
#define pR_ERROR_NOACCESS                   998L

//
// MessageId: pR_ERROR_SWAPERROR
//
// MessageText:
//
//  Error performing inpage operation.
//
#define pR_ERROR_SWAPERROR                  999L

//
// MessageId: pR_ERROR_STACK_OVERFLOW
//
// MessageText:
//
//  Recursion too deep; the stack overflowed.
//
#define pR_ERROR_STACK_OVERFLOW             1001L

//
// MessageId: pR_ERROR_INVALID_MESSAGE
//
// MessageText:
//
//  The window cannot act on the sent message.
//
#define pR_ERROR_INVALID_MESSAGE            1002L

//
// MessageId: pR_ERROR_CAN_NOT_COMPLETE
//
// MessageText:
//
//  Cannot complete this function.
//
#define pR_ERROR_CAN_NOT_COMPLETE           1003L

//
// MessageId: pR_ERROR_INVALID_FLAGS
//
// MessageText:
//
//  Invalid flags.
//
#define pR_ERROR_INVALID_FLAGS              1004L

//
// MessageId: pR_ERROR_UNRECOGNIZED_VOLUME
//
// MessageText:
//
//  The volume does not contain a recognized file system.
//  Please make sure that all required file system drivers are loaded and that the
//  volume is not corrupted.
//
#define pR_ERROR_UNRECOGNIZED_VOLUME        1005L

//
// MessageId: pR_ERROR_FILE_INVALID
//
// MessageText:
//
//  The volume for a file has been externally altered so that the
//  opened file is no longer valid.
//
#define pR_ERROR_FILE_INVALID               1006L

//
// MessageId: pR_ERROR_FULLSCREEN_MODE
//
// MessageText:
//
//  The requested operation cannot be performed in full-screen mode.
//
#define pR_ERROR_FULLSCREEN_MODE            1007L

//
// MessageId: pR_ERROR_NO_TOKEN
//
// MessageText:
//
//  An attempt was made to reference a token that does not exist.
//
#define pR_ERROR_NO_TOKEN                   1008L

//
// MessageId: pR_ERROR_BADDB
//
// MessageText:
//
//  The configuration registry database is corrupt.
//
#define pR_ERROR_BADDB                      1009L

//
// MessageId: pR_ERROR_BADKEY
//
// MessageText:
//
//  The configuration registry key is invalid.
//
#define pR_ERROR_BADKEY                     1010L

//
// MessageId: pR_ERROR_CANTOPEN
//
// MessageText:
//
//  The configuration registry key could not be opened.
//
#define pR_ERROR_CANTOPEN                   1011L

//
// MessageId: pR_ERROR_CANTREAD
//
// MessageText:
//
//  The configuration registry key could not be read.
//
#define pR_ERROR_CANTREAD                   1012L

//
// MessageId: pR_ERROR_CANTWRITE
//
// MessageText:
//
//  The configuration registry key could not be written.
//
#define pR_ERROR_CANTWRITE                  1013L

//
// MessageId: pR_ERROR_REGISTRY_RECOVERED
//
// MessageText:
//
//  One of the files in the registry database had to be recovered
//  by use of a log or alternate copy.  The recovery was successful.
//
#define pR_ERROR_REGISTRY_RECOVERED         1014L

//
// MessageId: pR_ERROR_REGISTRY_CORRUPT
//
// MessageText:
//
//  The registry is corrupted. The structure of one of the files that contains
//  registry data is corrupted, or the system's image of the file in memory
//  is corrupted, or the file could not be recovered because the alternate
//  copy or log was absent or corrupted.
//
#define pR_ERROR_REGISTRY_CORRUPT           1015L

//
// MessageId: pR_ERROR_REGISTRY_IO_FAILED
//
// MessageText:
//
//  An I/O operation initiated by the registry failed unrecoverably.
//  The registry could not read in, or write out, or flush, one of the files
//  that contain the system's image of the registry.
//
#define pR_ERROR_REGISTRY_IO_FAILED         1016L

//
// MessageId: pR_ERROR_NOT_REGISTRY_FILE
//
// MessageText:
//
//  The system has attempted to load or restore a file into the registry, but the
//  specified file is not in a registry file format.
//
#define pR_ERROR_NOT_REGISTRY_FILE          1017L

//
// MessageId: pR_ERROR_KEY_DELETED
//
// MessageText:
//
//  Illegal operation attempted on a registry key that has been marked for deletion.
//
#define pR_ERROR_KEY_DELETED                1018L

//
// MessageId: pR_ERROR_NO_LOG_SPACE
//
// MessageText:
//
//  System could not allocate the required space in a registry log.
//
#define pR_ERROR_NO_LOG_SPACE               1019L

//
// MessageId: pR_ERROR_KEY_HAS_CHILDREN
//
// MessageText:
//
//  Cannot create a symbolic link in a registry key that already
//  has subkeys or values.
//
#define pR_ERROR_KEY_HAS_CHILDREN           1020L

//
// MessageId: pR_ERROR_CHILD_MUST_BE_VOLATILE
//
// MessageText:
//
//  Cannot create a stable subkey under a volatile parent key.
//
#define pR_ERROR_CHILD_MUST_BE_VOLATILE     1021L

//
// MessageId: pR_ERROR_NOTIFY_ENUM_DIR
//
// MessageText:
//
//  A notify change request is being completed and the information
//  is not being returned in the caller's buffer. The caller now
//  needs to enumerate the files to find the changes.
//
#define pR_ERROR_NOTIFY_ENUM_DIR            1022L

//
// MessageId: pR_ERROR_DEPENDENT_SERVICES_RUNNING
//
// MessageText:
//
//  A stop control has been sent to a service that other running services
//  are dependent on.
//
#define pR_ERROR_DEPENDENT_SERVICES_RUNNING 1051L

//
// MessageId: pR_ERROR_INVALID_SERVICE_CONTROL
//
// MessageText:
//
//  The requested control is not valid for this service.
//
#define pR_ERROR_INVALID_SERVICE_CONTROL    1052L

//
// MessageId: pR_ERROR_SERVICE_REQUEST_TIMEOUT
//
// MessageText:
//
//  The service did not respond to the start or control request in a timely
//  fashion.
//
#define pR_ERROR_SERVICE_REQUEST_TIMEOUT    1053L

//
// MessageId: pR_ERROR_SERVICE_NO_THREAD
//
// MessageText:
//
//  A thread could not be created for the service.
//
#define pR_ERROR_SERVICE_NO_THREAD          1054L

//
// MessageId: pR_ERROR_SERVICE_DATABASE_LOCKED
//
// MessageText:
//
//  The service database is locked.
//
#define pR_ERROR_SERVICE_DATABASE_LOCKED    1055L

//
// MessageId: pR_ERROR_SERVICE_ALREADY_RUNNING
//
// MessageText:
//
//  An instance of the service is already running.
//
#define pR_ERROR_SERVICE_ALREADY_RUNNING    1056L

//
// MessageId: pR_ERROR_INVALID_SERVICE_ACCOUNT
//
// MessageText:
//
//  The account name is invalid or does not exist.
//
#define pR_ERROR_INVALID_SERVICE_ACCOUNT    1057L

//
// MessageId: pR_ERROR_SERVICE_DISABLED
//
// MessageText:
//
//  The service cannot be started, either because it is disabled or because
//  it has no enabled devices associated with it.
//
#define pR_ERROR_SERVICE_DISABLED           1058L

//
// MessageId: pR_ERROR_CIRCULAR_DEPENDENCY
//
// MessageText:
//
//  Circular service dependency was specified.
//
#define pR_ERROR_CIRCULAR_DEPENDENCY        1059L

//
// MessageId: pR_ERROR_SERVICE_DOES_NOT_EXIST
//
// MessageText:
//
//  The specified service does not exist as an installed service.
//
#define pR_ERROR_SERVICE_DOES_NOT_EXIST     1060L

//
// MessageId: pR_ERROR_SERVICE_CANNOT_ACCEPT_CTRL
//
// MessageText:
//
//  The service cannot accept control messages at this time.
//
#define pR_ERROR_SERVICE_CANNOT_ACCEPT_CTRL 1061L

//
// MessageId: pR_ERROR_SERVICE_NOT_ACTIVE
//
// MessageText:
//
//  The service has not been started.
//
#define pR_ERROR_SERVICE_NOT_ACTIVE         1062L

//
// MessageId: pR_ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
//
// MessageText:
//
//  The service process could not connect to the service controller.
//
#define pR_ERROR_FAILED_SERVICE_CONTROLLER_CONNECT 1063L

//
// MessageId: pR_ERROR_EXCEPTION_IN_SERVICE
//
// MessageText:
//
//  An exception occurred in the service when handling the control request.
//
#define pR_ERROR_EXCEPTION_IN_SERVICE       1064L

//
// MessageId: pR_ERROR_DATABASE_DOES_NOT_EXIST
//
// MessageText:
//
//  The database specified does not exist.
//
#define pR_ERROR_DATABASE_DOES_NOT_EXIST    1065L

//
// MessageId: pR_ERROR_SERVICE_SPECIFIC_ERROR
//
// MessageText:
//
//  The service has returned a service-specific error code.
//
#define pR_ERROR_SERVICE_SPECIFIC_ERROR     1066L

//
// MessageId: pR_ERROR_PROCESS_ABORTED
//
// MessageText:
//
//  The process terminated unexpectedly.
//
#define pR_ERROR_PROCESS_ABORTED            1067L

//
// MessageId: pR_ERROR_SERVICE_DEPENDENCY_FAIL
//
// MessageText:
//
//  The dependency service or group failed to start.
//
#define pR_ERROR_SERVICE_DEPENDENCY_FAIL    1068L

//
// MessageId: pR_ERROR_SERVICE_LOGON_FAILED
//
// MessageText:
//
//  The service did not start due to a logon failure.
//
#define pR_ERROR_SERVICE_LOGON_FAILED       1069L

//
// MessageId: pR_ERROR_SERVICE_START_HANG
//
// MessageText:
//
//  After starting, the service hung in a start-pending state.
//
#define pR_ERROR_SERVICE_START_HANG         1070L

//
// MessageId: pR_ERROR_INVALID_SERVICE_LOCK
//
// MessageText:
//
//  The specified service database lock is invalid.
//
#define pR_ERROR_INVALID_SERVICE_LOCK       1071L

//
// MessageId: pR_ERROR_SERVICE_MARKED_FOR_DELETE
//
// MessageText:
//
//  The specified service has been marked for deletion.
//
#define pR_ERROR_SERVICE_MARKED_FOR_DELETE  1072L

//
// MessageId: pR_ERROR_SERVICE_EXISTS
//
// MessageText:
//
//  The specified service already exists.
//
#define pR_ERROR_SERVICE_EXISTS             1073L

//
// MessageId: pR_ERROR_ALREADY_RUNNING_LKG
//
// MessageText:
//
//  The system is currently running with the last-known-good configuration.
//
#define pR_ERROR_ALREADY_RUNNING_LKG        1074L

//
// MessageId: pR_ERROR_SERVICE_DEPENDENCY_DELETED
//
// MessageText:
//
//  The dependency service does not exist or has been marked for
//  deletion.
//
#define pR_ERROR_SERVICE_DEPENDENCY_DELETED 1075L

//
// MessageId: pR_ERROR_BOOT_ALREADY_ACCEPTED
//
// MessageText:
//
//  The current boot has already been accepted for use as the
//  last-known-good control set.
//
#define pR_ERROR_BOOT_ALREADY_ACCEPTED      1076L

//
// MessageId: pR_ERROR_SERVICE_NEVER_STARTED
//
// MessageText:
//
//  No attempts to start the service have been made since the last boot.
//
#define pR_ERROR_SERVICE_NEVER_STARTED      1077L

//
// MessageId: pR_ERROR_DUPLICATE_SERVICE_NAME
//
// MessageText:
//
//  The name is already in use as either a service name or a service display
//  name.
//
#define pR_ERROR_DUPLICATE_SERVICE_NAME     1078L

//
// MessageId: pR_ERROR_DIFFERENT_SERVICE_ACCOUNT
//
// MessageText:
//
//  The account specified for this service is different from the account
//  specified for other services running in the same process.
//
#define pR_ERROR_DIFFERENT_SERVICE_ACCOUNT  1079L

//
// MessageId: pR_ERROR_CANNOT_DETECT_DRIVER_FAILURE
//
// MessageText:
//
//  Failure actions can only be set for Win32 services, not for drivers.
//
#define pR_ERROR_CANNOT_DETECT_DRIVER_FAILURE 1080L

//
// MessageId: pR_ERROR_CANNOT_DETECT_PROCESS_ABORT
//
// MessageText:
//
//  This service runs in the same process as the service control manager.
//  Therefore, the service control manager cannot take action if this
//  service's process terminates unexpectedly.
//
#define pR_ERROR_CANNOT_DETECT_PROCESS_ABORT 1081L

//
// MessageId: pR_ERROR_NO_RECOVERY_PROGRAM
//
// MessageText:
//
//  No recovery program has been configured for this service.
//
#define pR_ERROR_NO_RECOVERY_PROGRAM        1082L

//
// MessageId: pR_ERROR_END_OF_MEDIA
//
// MessageText:
//
//  The physical end of the tape has been reached.
//
#define pR_ERROR_END_OF_MEDIA               1100L

//
// MessageId: pR_ERROR_FILEMARK_DETECTED
//
// MessageText:
//
//  A tape access reached a filemark.
//
#define pR_ERROR_FILEMARK_DETECTED          1101L

//
// MessageId: pR_ERROR_BEGINNING_OF_MEDIA
//
// MessageText:
//
//  The beginning of the tape or a partition was encountered.
//
#define pR_ERROR_BEGINNING_OF_MEDIA         1102L

//
// MessageId: pR_ERROR_SETMARK_DETECTED
//
// MessageText:
//
//  A tape access reached the end of a set of files.
//
#define pR_ERROR_SETMARK_DETECTED           1103L

//
// MessageId: pR_ERROR_NO_DATA_DETECTED
//
// MessageText:
//
//  No more data is on the tape.
//
#define pR_ERROR_NO_DATA_DETECTED           1104L

//
// MessageId: pR_ERROR_PARTITION_FAILURE
//
// MessageText:
//
//  Tape could not be partitioned.
//
#define pR_ERROR_PARTITION_FAILURE          1105L

//
// MessageId: pR_ERROR_INVALID_BLOCK_LENGTH
//
// MessageText:
//
//  When accessing a new tape of a multivolume partition, the current
//  blocksize is incorrect.
//
#define pR_ERROR_INVALID_BLOCK_LENGTH       1106L

//
// MessageId: pR_ERROR_DEVICE_NOT_PARTITIONED
//
// MessageText:
//
//  Tape partition information could not be found when loading a tape.
//
#define pR_ERROR_DEVICE_NOT_PARTITIONED     1107L

//
// MessageId: pR_ERROR_UNABLE_TO_LOCK_MEDIA
//
// MessageText:
//
//  Unable to lock the media eject mechanism.
//
#define pR_ERROR_UNABLE_TO_LOCK_MEDIA       1108L

//
// MessageId: pR_ERROR_UNABLE_TO_UNLOAD_MEDIA
//
// MessageText:
//
//  Unable to unload the media.
//
#define pR_ERROR_UNABLE_TO_UNLOAD_MEDIA     1109L

//
// MessageId: pR_ERROR_MEDIA_CHANGED
//
// MessageText:
//
//  The media in the drive may have changed.
//
#define pR_ERROR_MEDIA_CHANGED              1110L

//
// MessageId: pR_ERROR_BUS_RESET
//
// MessageText:
//
//  The I/O bus was reset.
//
#define pR_ERROR_BUS_RESET                  1111L

//
// MessageId: pR_ERROR_NO_MEDIA_IN_DRIVE
//
// MessageText:
//
//  No media in drive.
//
#define pR_ERROR_NO_MEDIA_IN_DRIVE          1112L

//
// MessageId: pR_ERROR_NO_UNICODE_TRANSLATION
//
// MessageText:
//
//  No mapping for the Unicode character exists in the target multi-byte code page.
//
#define pR_ERROR_NO_UNICODE_TRANSLATION     1113L

//
// MessageId: pR_ERROR_DLL_INIT_FAILED
//
// MessageText:
//
//  A dynamic link library (DLL) initialization routine failed.
//
#define pR_ERROR_DLL_INIT_FAILED            1114L

//
// MessageId: pR_ERROR_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
//  A system shutdown is in progress.
//
#define pR_ERROR_SHUTDOWN_IN_PROGRESS       1115L

//
// MessageId: pR_ERROR_NO_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
//  Unable to abort the system shutdown because no shutdown was in progress.
//
#define pR_ERROR_NO_SHUTDOWN_IN_PROGRESS    1116L

//
// MessageId: pR_ERROR_IO_DEVICE
//
// MessageText:
//
//  The request could not be performed because of an I/O device error.
//
#define pR_ERROR_IO_DEVICE                  1117L

//
// MessageId: pR_ERROR_SERIAL_NO_DEVICE
//
// MessageText:
//
//  No serial device was successfully initialized.  The serial driver will unload.
//
#define pR_ERROR_SERIAL_NO_DEVICE           1118L

//
// MessageId: pR_ERROR_IRQ_BUSY
//
// MessageText:
//
//  Unable to open a device that was sharing an interrupt request (IRQ)
//  with other devices. At least one other device that uses that IRQ
//  was already opened.
//
#define pR_ERROR_IRQ_BUSY                   1119L

//
// MessageId: pR_ERROR_MORE_WRITES
//
// MessageText:
//
//  A serial I/O operation was completed by another write to the serial port.
//  (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
//
#define pR_ERROR_MORE_WRITES                1120L

//
// MessageId: pR_ERROR_COUNTER_TIMEOUT
//
// MessageText:
//
//  A serial I/O operation completed because the timeout period expired.
//  (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
//
#define pR_ERROR_COUNTER_TIMEOUT            1121L

//
// MessageId: pR_ERROR_FLOPPY_ID_MARK_NOT_FOUND
//
// MessageText:
//
//  No ID address mark was found on the floppy disk.
//
#define pR_ERROR_FLOPPY_ID_MARK_NOT_FOUND   1122L

//
// MessageId: pR_ERROR_FLOPPY_WRONG_CYLINDER
//
// MessageText:
//
//  Mismatch between the floppy disk sector ID field and the floppy disk
//  controller track address.
//
#define pR_ERROR_FLOPPY_WRONG_CYLINDER      1123L

//
// MessageId: pR_ERROR_FLOPPY_UNKNOWN_ERROR
//
// MessageText:
//
//  The floppy disk controller reported an error that is not recognized
//  by the floppy disk driver.
//
#define pR_ERROR_FLOPPY_UNKNOWN_ERROR       1124L

//
// MessageId: pR_ERROR_FLOPPY_BAD_REGISTERS
//
// MessageText:
//
//  The floppy disk controller returned inconsistent results in its registers.
//
#define pR_ERROR_FLOPPY_BAD_REGISTERS       1125L

//
// MessageId: pR_ERROR_DISK_RECALIBRATE_FAILED
//
// MessageText:
//
//  While accessing the hard disk, a recalibrate operation failed, even after retries.
//
#define pR_ERROR_DISK_RECALIBRATE_FAILED    1126L

//
// MessageId: pR_ERROR_DISK_OPERATION_FAILED
//
// MessageText:
//
//  While accessing the hard disk, a disk operation failed even after retries.
//
#define pR_ERROR_DISK_OPERATION_FAILED      1127L

//
// MessageId: pR_ERROR_DISK_RESET_FAILED
//
// MessageText:
//
//  While accessing the hard disk, a disk controller reset was needed, but
//  even that failed.
//
#define pR_ERROR_DISK_RESET_FAILED          1128L

//
// MessageId: pR_ERROR_EOM_OVERFLOW
//
// MessageText:
//
//  Physical end of tape encountered.
//
#define pR_ERROR_EOM_OVERFLOW               1129L

//
// MessageId: pR_ERROR_NOT_ENOUGH_SERVER_MEMORY
//
// MessageText:
//
//  Not enough server storage is available to process this command.
//
#define pR_ERROR_NOT_ENOUGH_SERVER_MEMORY   1130L

//
// MessageId: pR_ERROR_POSSIBLE_DEADLOCK
//
// MessageText:
//
//  A potential deadlock condition has been detected.
//
#define pR_ERROR_POSSIBLE_DEADLOCK          1131L

//
// MessageId: pR_ERROR_MAPPED_ALIGNMENT
//
// MessageText:
//
//  The base address or the file offset specified does not have the proper
//  alignment.
//
#define pR_ERROR_MAPPED_ALIGNMENT           1132L

//
// MessageId: pR_ERROR_SET_POWER_STATE_VETOED
//
// MessageText:
//
//  An attempt to change the system power state was vetoed by another
//  application or driver.
//
#define pR_ERROR_SET_POWER_STATE_VETOED     1140L

//
// MessageId: pR_ERROR_SET_POWER_STATE_FAILED
//
// MessageText:
//
//  The system BIOS failed an attempt to change the system power state.
//
#define pR_ERROR_SET_POWER_STATE_FAILED     1141L

//
// MessageId: pR_ERROR_TOO_MANY_LINKS
//
// MessageText:
//
//  An attempt was made to create more links on a file than
//  the file system supports.
//
#define pR_ERROR_TOO_MANY_LINKS             1142L

//
// MessageId: pR_ERROR_OLD_WIN_VERSION
//
// MessageText:
//
//  The specified program requires a newer version of Windows.
//
#define pR_ERROR_OLD_WIN_VERSION            1150L

//
// MessageId: pR_ERROR_APP_WRONG_OS
//
// MessageText:
//
//  The specified program is not a Windows or MS-DOS program.
//
#define pR_ERROR_APP_WRONG_OS               1151L

//
// MessageId: pR_ERROR_SINGLE_INSTANCE_APP
//
// MessageText:
//
//  Cannot start more than one instance of the specified program.
//
#define pR_ERROR_SINGLE_INSTANCE_APP        1152L

//
// MessageId: pR_ERROR_RMODE_APP
//
// MessageText:
//
//  The specified program was written for an earlier version of Windows.
//
#define pR_ERROR_RMODE_APP                  1153L

//
// MessageId: pR_ERROR_INVALID_DLL
//
// MessageText:
//
//  One of the library files needed to run this application is damaged.
//
#define pR_ERROR_INVALID_DLL                1154L

//
// MessageId: pR_ERROR_NO_ASSOCIATION
//
// MessageText:
//
//  No application is associated with the specified file for this operation.
//
#define pR_ERROR_NO_ASSOCIATION             1155L

//
// MessageId: pR_ERROR_DDE_FAIL
//
// MessageText:
//
//  An error occurred in sending the command to the application.
//
#define pR_ERROR_DDE_FAIL                   1156L

//
// MessageId: pR_ERROR_DLL_NOT_FOUND
//
// MessageText:
//
//  One of the library files needed to run this application cannot be found.
//
#define pR_ERROR_DLL_NOT_FOUND              1157L

//
// MessageId: pR_ERROR_NO_MORE_USER_HANDLES
//
// MessageText:
//
//  The current process has used all of its system allowance of handles for Window Manager objects.
//
#define pR_ERROR_NO_MORE_USER_HANDLES       1158L

//
// MessageId: pR_ERROR_MESSAGE_SYNC_ONLY
//
// MessageText:
//
//  The message can be used only with synchronous operations.
//
#define pR_ERROR_MESSAGE_SYNC_ONLY          1159L

//
// MessageId: pR_ERROR_SOURCE_ELEMENT_EMPTY
//
// MessageText:
//
//  The indicated source element has no media.
//
#define pR_ERROR_SOURCE_ELEMENT_EMPTY       1160L

//
// MessageId: pR_ERROR_DESTINATION_ELEMENT_FULL
//
// MessageText:
//
//  The indicated destination element already contains media.
//
#define pR_ERROR_DESTINATION_ELEMENT_FULL   1161L

//
// MessageId: pR_ERROR_ILLEGAL_ELEMENT_ADDRESS
//
// MessageText:
//
//  The indicated element does not exist.
//
#define pR_ERROR_ILLEGAL_ELEMENT_ADDRESS    1162L

//
// MessageId: pR_ERROR_MAGAZINE_NOT_PRESENT
//
// MessageText:
//
//  The indicated element is part of a magazine that is not present.
//
#define pR_ERROR_MAGAZINE_NOT_PRESENT       1163L

//
// MessageId: pR_ERROR_DEVICE_REINITIALIZATION_NEEDED
//
// MessageText:
//
//  The indicated device requires reinitialization due to hardware errors.
//
#define pR_ERROR_DEVICE_REINITIALIZATION_NEEDED 1164L    // dderror

//
// MessageId: pR_ERROR_DEVICE_REQUIRES_CLEANING
//
// MessageText:
//
//  The device has indicated that cleaning is required before further operations are attempted.
//
#define pR_ERROR_DEVICE_REQUIRES_CLEANING   1165L

//
// MessageId: pR_ERROR_DEVICE_DOOR_OPEN
//
// MessageText:
//
//  The device has indicated that its door is open.
//
#define pR_ERROR_DEVICE_DOOR_OPEN           1166L

//
// MessageId: pR_ERROR_DEVICE_NOT_CONNECTED
//
// MessageText:
//
//  The device is not connected.
//
#define pR_ERROR_DEVICE_NOT_CONNECTED       1167L

//
// MessageId: pR_ERROR_NOT_FOUND
//
// MessageText:
//
//  Element not found.
//
#define pR_ERROR_NOT_FOUND                  1168L

//
// MessageId: pR_ERROR_NO_MATCH
//
// MessageText:
//
//  There was no match for the specified key in the index.
//
#define pR_ERROR_NO_MATCH                   1169L

//
// MessageId: pR_ERROR_SET_NOT_FOUND
//
// MessageText:
//
//  The property set specified does not exist on the object.
//
#define pR_ERROR_SET_NOT_FOUND              1170L

//
// MessageId: pR_ERROR_POINT_NOT_FOUND
//
// MessageText:
//
//  The point passed to GetMouseMovePoints is not in the buffer.
//
#define pR_ERROR_POINT_NOT_FOUND            1171L

//
// MessageId: pR_ERROR_NO_TRACKING_SERVICE
//
// MessageText:
//
//  The tracking (workstation) service is not running.
//
#define pR_ERROR_NO_TRACKING_SERVICE        1172L

//
// MessageId: pR_ERROR_NO_VOLUME_ID
//
// MessageText:
//
//  The Volume ID could not be found.
//
#define pR_ERROR_NO_VOLUME_ID               1173L




///////////////////////////
//                       //
// Winnet32 Status Codes //
//                       //
///////////////////////////


//
// MessageId: pR_ERROR_CONNECTED_OTHER_PASSWORD
//
// MessageText:
//
//  The network connection was made successfully, but the user had to be prompted
//  for a password other than the one originally specified.
//
#define pR_ERROR_CONNECTED_OTHER_PASSWORD   2108L

//
// MessageId: pR_ERROR_BAD_USERNAME
//
// MessageText:
//
//  The specified username is invalid.
//
#define pR_ERROR_BAD_USERNAME               2202L

//
// MessageId: pR_ERROR_NOT_CONNECTED
//
// MessageText:
//
//  This network connection does not exist.
//
#define pR_ERROR_NOT_CONNECTED              2250L

//
// MessageId: pR_ERROR_OPEN_FILES
//
// MessageText:
//
//  This network connection has files open or requests pending.
//
#define pR_ERROR_OPEN_FILES                 2401L

//
// MessageId: pR_ERROR_ACTIVE_CONNECTIONS
//
// MessageText:
//
//  Active connections still exist.
//
#define pR_ERROR_ACTIVE_CONNECTIONS         2402L

//
// MessageId: pR_ERROR_DEVICE_IN_USE
//
// MessageText:
//
//  The device is in use by an active process and cannot be disconnected.
//
#define pR_ERROR_DEVICE_IN_USE              2404L

//
// MessageId: pR_ERROR_BAD_DEVICE
//
// MessageText:
//
//  The specified device name is invalid.
//
#define pR_ERROR_BAD_DEVICE                 1200L

//
// MessageId: pR_ERROR_CONNECTION_UNAVAIL
//
// MessageText:
//
//  The device is not currently connected but it is a remembered connection.
//
#define pR_ERROR_CONNECTION_UNAVAIL         1201L

//
// MessageId: pR_ERROR_DEVICE_ALREADY_REMEMBERED
//
// MessageText:
//
//  An attempt was made to remember a device that had previously been remembered.
//
#define pR_ERROR_DEVICE_ALREADY_REMEMBERED  1202L

//
// MessageId: pR_ERROR_NO_NET_OR_BAD_PATH
//
// MessageText:
//
//  No network provider accepted the given network path.
//
#define pR_ERROR_NO_NET_OR_BAD_PATH         1203L

//
// MessageId: pR_ERROR_BAD_PROVIDER
//
// MessageText:
//
//  The specified network provider name is invalid.
//
#define pR_ERROR_BAD_PROVIDER               1204L

//
// MessageId: pR_ERROR_CANNOT_OPEN_PROFILE
//
// MessageText:
//
//  Unable to open the network connection profile.
//
#define pR_ERROR_CANNOT_OPEN_PROFILE        1205L

//
// MessageId: pR_ERROR_BAD_PROFILE
//
// MessageText:
//
//  The network connection profile is corrupted.
//
#define pR_ERROR_BAD_PROFILE                1206L

//
// MessageId: pR_ERROR_NOT_CONTAINER
//
// MessageText:
//
//  Cannot enumerate a noncontainer.
//
#define pR_ERROR_NOT_CONTAINER              1207L

//
// MessageId: pR_ERROR_EXTENDED_ERROR
//
// MessageText:
//
//  An extended error has occurred.
//
#define pR_ERROR_EXTENDED_ERROR             1208L

//
// MessageId: pR_ERROR_INVALID_GROUPNAME
//
// MessageText:
//
//  The format of the specified group name is invalid.
//
#define pR_ERROR_INVALID_GROUPNAME          1209L

//
// MessageId: pR_ERROR_INVALID_COMPUTERNAME
//
// MessageText:
//
//  The format of the specified computer name is invalid.
//
#define pR_ERROR_INVALID_COMPUTERNAME       1210L

//
// MessageId: pR_ERROR_INVALID_EVENTNAME
//
// MessageText:
//
//  The format of the specified event name is invalid.
//
#define pR_ERROR_INVALID_EVENTNAME          1211L

//
// MessageId: pR_ERROR_INVALID_DOMAINNAME
//
// MessageText:
//
//  The format of the specified domain name is invalid.
//
#define pR_ERROR_INVALID_DOMAINNAME         1212L

//
// MessageId: pR_ERROR_INVALID_SERVICENAME
//
// MessageText:
//
//  The format of the specified service name is invalid.
//
#define pR_ERROR_INVALID_SERVICENAME        1213L

//
// MessageId: pR_ERROR_INVALID_NETNAME
//
// MessageText:
//
//  The format of the specified network name is invalid.
//
#define pR_ERROR_INVALID_NETNAME            1214L

//
// MessageId: pR_ERROR_INVALID_SHARENAME
//
// MessageText:
//
//  The format of the specified share name is invalid.
//
#define pR_ERROR_INVALID_SHARENAME          1215L

//
// MessageId: pR_ERROR_INVALID_PASSWORDNAME
//
// MessageText:
//
//  The format of the specified password is invalid.
//
#define pR_ERROR_INVALID_PASSWORDNAME       1216L

//
// MessageId: pR_ERROR_INVALID_MESSAGENAME
//
// MessageText:
//
//  The format of the specified message name is invalid.
//
#define pR_ERROR_INVALID_MESSAGENAME        1217L

//
// MessageId: pR_ERROR_INVALID_MESSAGEDEST
//
// MessageText:
//
//  The format of the specified message destination is invalid.
//
#define pR_ERROR_INVALID_MESSAGEDEST        1218L

//
// MessageId: pR_ERROR_SESSION_CREDENTIAL_CONFLICT
//
// MessageText:
//
//  The credentials supplied conflict with an existing set of credentials.
//
#define pR_ERROR_SESSION_CREDENTIAL_CONFLICT 1219L

//
// MessageId: pR_ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
//
// MessageText:
//
//  An attempt was made to establish a session to a network server, but there
//  are already too many sessions established to that server.
//
#define pR_ERROR_REMOTE_SESSION_LIMIT_EXCEEDED 1220L

//
// MessageId: pR_ERROR_DUP_DOMAINNAME
//
// MessageText:
//
//  The workgroup or domain name is already in use by another computer on the
//  network.
//
#define pR_ERROR_DUP_DOMAINNAME             1221L

//
// MessageId: pR_ERROR_NO_NETWORK
//
// MessageText:
//
//  The network is not present or not started.
//
#define pR_ERROR_NO_NETWORK                 1222L

//
// MessageId: pR_ERROR_CANCELLED
//
// MessageText:
//
//  The operation was canceled by the user.
//
#define pR_ERROR_CANCELLED                  1223L

//
// MessageId: pR_ERROR_USER_MAPPED_FILE
//
// MessageText:
//
//  The requested operation cannot be performed on a file with a user-mapped section open.
//
#define pR_ERROR_USER_MAPPED_FILE           1224L

//
// MessageId: pR_ERROR_CONNECTION_REFUSED
//
// MessageText:
//
//  The remote system refused the network connection.
//
#define pR_ERROR_CONNECTION_REFUSED         1225L

//
// MessageId: pR_ERROR_GRACEFUL_DISCONNECT
//
// MessageText:
//
//  The network connection was gracefully closed.
//
#define pR_ERROR_GRACEFUL_DISCONNECT        1226L

//
// MessageId: pR_ERROR_ADDRESS_ALREADY_ASSOCIATED
//
// MessageText:
//
//  The network transport endpoint already has an address associated with it.
//
#define pR_ERROR_ADDRESS_ALREADY_ASSOCIATED 1227L

//
// MessageId: pR_ERROR_ADDRESS_NOT_ASSOCIATED
//
// MessageText:
//
//  An address has not yet been associated with the network endpoint.
//
#define pR_ERROR_ADDRESS_NOT_ASSOCIATED     1228L

//
// MessageId: pR_ERROR_CONNECTION_INVALID
//
// MessageText:
//
//  An operation was attempted on a nonexistent network connection.
//
#define pR_ERROR_CONNECTION_INVALID         1229L

//
// MessageId: pR_ERROR_CONNECTION_ACTIVE
//
// MessageText:
//
//  An invalid operation was attempted on an active network connection.
//
#define pR_ERROR_CONNECTION_ACTIVE          1230L

//
// MessageId: pR_ERROR_NETWORK_UNREACHABLE
//
// MessageText:
//
//  The remote network is not reachable by the transport.
//
#define pR_ERROR_NETWORK_UNREACHABLE        1231L

//
// MessageId: pR_ERROR_HOST_UNREACHABLE
//
// MessageText:
//
//  The remote system is not reachable by the transport.
//
#define pR_ERROR_HOST_UNREACHABLE           1232L

//
// MessageId: pR_ERROR_PROTOCOL_UNREACHABLE
//
// MessageText:
//
//  The remote system does not support the transport protocol.
//
#define pR_ERROR_PROTOCOL_UNREACHABLE       1233L

//
// MessageId: pR_ERROR_PORT_UNREACHABLE
//
// MessageText:
//
//  No service is operating at the destination network endpoint
//  on the remote system.
//
#define pR_ERROR_PORT_UNREACHABLE           1234L

//
// MessageId: pR_ERROR_REQUEST_ABORTED
//
// MessageText:
//
//  The request was aborted.
//
#define pR_ERROR_REQUEST_ABORTED            1235L

//
// MessageId: pR_ERROR_CONNECTION_ABORTED
//
// MessageText:
//
//  The network connection was aborted by the local system.
//
#define pR_ERROR_CONNECTION_ABORTED         1236L

//
// MessageId: pR_ERROR_RETRY
//
// MessageText:
//
//  The operation could not be completed.  A retry should be performed.
//
#define pR_ERROR_RETRY                      1237L

//
// MessageId: pR_ERROR_CONNECTION_COUNT_LIMIT
//
// MessageText:
//
//  A connection to the server could not be made because the limit on the number of
//  concurrent connections for this account has been reached.
//
#define pR_ERROR_CONNECTION_COUNT_LIMIT     1238L

//
// MessageId: pR_ERROR_LOGIN_TIME_RESTRICTION
//
// MessageText:
//
//  Attempting to log in during an unauthorized time of day for this account.
//
#define pR_ERROR_LOGIN_TIME_RESTRICTION     1239L

//
// MessageId: pR_ERROR_LOGIN_WKSTA_RESTRICTION
//
// MessageText:
//
//  The account is not authorized to log in from this station.
//
#define pR_ERROR_LOGIN_WKSTA_RESTRICTION    1240L

//
// MessageId: pR_ERROR_INCORRECT_ADDRESS
//
// MessageText:
//
//  The network address could not be used for the operation requested.
//
#define pR_ERROR_INCORRECT_ADDRESS          1241L

//
// MessageId: pR_ERROR_ALREADY_REGISTERED
//
// MessageText:
//
//  The service is already registered.
//
#define pR_ERROR_ALREADY_REGISTERED         1242L

//
// MessageId: pR_ERROR_SERVICE_NOT_FOUND
//
// MessageText:
//
//  The specified service does not exist.
//
#define pR_ERROR_SERVICE_NOT_FOUND          1243L

//
// MessageId: pR_ERROR_NOT_AUTHENTICATED
//
// MessageText:
//
//  The operation being requested was not performed because the user
//  has not been authenticated.
//
#define pR_ERROR_NOT_AUTHENTICATED          1244L

//
// MessageId: pR_ERROR_NOT_LOGGED_ON
//
// MessageText:
//
//  The operation being requested was not performed because the user
//  has not logged on to the network.
//  The specified service does not exist.
//
#define pR_ERROR_NOT_LOGGED_ON              1245L

//
// MessageId: pR_ERROR_CONTINUE
//
// MessageText:
//
//  Continue with work in progress.
//
#define pR_ERROR_CONTINUE                   1246L

//
// MessageId: pR_ERROR_ALREADY_INITIALIZED
//
// MessageText:
//
//  An attempt was made to perform an initialization operation when
//  initialization has already been completed.
//
#define pR_ERROR_ALREADY_INITIALIZED        1247L

//
// MessageId: pR_ERROR_NO_MORE_DEVICES
//
// MessageText:
//
//  No more local devices.
//
#define pR_ERROR_NO_MORE_DEVICES            1248L

//
// MessageId: pR_ERROR_NO_SUCH_SITE
//
// MessageText:
//
//  The specified site does not exist.
//
#define pR_ERROR_NO_SUCH_SITE               1249L

//
// MessageId: pR_ERROR_DOMAIN_CONTROLLER_EXISTS
//
// MessageText:
//
//  A domain controller with the specified name already exists.
//
#define pR_ERROR_DOMAIN_CONTROLLER_EXISTS   1250L

//
// MessageId: pR_ERROR_DS_NOT_INSTALLED
//
// MessageText:
//
//  An error occurred while installing the Windows NT directory service. Please view the event log for more information.
//
#define pR_ERROR_DS_NOT_INSTALLED           1251L




///////////////////////////
//                       //
// Security Status Codes //
//                       //
///////////////////////////


//
// MessageId: pR_ERROR_NOT_ALL_ASSIGNED
//
// MessageText:
//
//  Not all privileges referenced are assigned to the caller.
//
#define pR_ERROR_NOT_ALL_ASSIGNED           1300L

//
// MessageId: pR_ERROR_SOME_NOT_MAPPED
//
// MessageText:
//
//  Some mapping between account names and security IDs was not done.
//
#define pR_ERROR_SOME_NOT_MAPPED            1301L

//
// MessageId: pR_ERROR_NO_QUOTAS_FOR_ACCOUNT
//
// MessageText:
//
//  No system quota limits are specifically set for this account.
//
#define pR_ERROR_NO_QUOTAS_FOR_ACCOUNT      1302L

//
// MessageId: pR_ERROR_LOCAL_USER_SESSION_KEY
//
// MessageText:
//
//  No encryption key is available.  A well-known encryption key was returned.
//
#define pR_ERROR_LOCAL_USER_SESSION_KEY     1303L

//
// MessageId: pR_ERROR_NULL_LM_PASSWORD
//
// MessageText:
//
//  The Windows NT password is too complex to be converted to a LAN Manager
//  password.  The LAN Manager password returned is a NULL string.
//
#define pR_ERROR_NULL_LM_PASSWORD           1304L

//
// MessageId: pR_ERROR_UNKNOWN_REVISION
//
// MessageText:
//
//  The revision level is unknown.
//
#define pR_ERROR_UNKNOWN_REVISION           1305L

//
// MessageId: pR_ERROR_REVISION_MISMATCH
//
// MessageText:
//
//  Indicates two revision levels are incompatible.
//
#define pR_ERROR_REVISION_MISMATCH          1306L

//
// MessageId: pR_ERROR_INVALID_OWNER
//
// MessageText:
//
//  This security ID may not be assigned as the owner of this object.
//
#define pR_ERROR_INVALID_OWNER              1307L

//
// MessageId: pR_ERROR_INVALID_PRIMARY_GROUP
//
// MessageText:
//
//  This security ID may not be assigned as the primary group of an object.
//
#define pR_ERROR_INVALID_PRIMARY_GROUP      1308L

//
// MessageId: pR_ERROR_NO_IMPERSONATION_TOKEN
//
// MessageText:
//
//  An attempt has been made to operate on an impersonation token
//  by a thread that is not currently impersonating a client.
//
#define pR_ERROR_NO_IMPERSONATION_TOKEN     1309L

//
// MessageId: pR_ERROR_CANT_DISABLE_MANDATORY
//
// MessageText:
//
//  The group may not be disabled.
//
#define pR_ERROR_CANT_DISABLE_MANDATORY     1310L

//
// MessageId: pR_ERROR_NO_LOGON_SERVERS
//
// MessageText:
//
//  There are currently no logon servers available to service the logon
//  request.
//
#define pR_ERROR_NO_LOGON_SERVERS           1311L

//
// MessageId: pR_ERROR_NO_SUCH_LOGON_SESSION
//
// MessageText:
//
//   A specified logon session does not exist.  It may already have
//   been terminated.
//
#define pR_ERROR_NO_SUCH_LOGON_SESSION      1312L

//
// MessageId: pR_ERROR_NO_SUCH_PRIVILEGE
//
// MessageText:
//
//   A specified privilege does not exist.
//
#define pR_ERROR_NO_SUCH_PRIVILEGE          1313L

//
// MessageId: pR_ERROR_PRIVILEGE_NOT_HELD
//
// MessageText:
//
//   A required privilege is not held by the client.
//
#define pR_ERROR_PRIVILEGE_NOT_HELD         1314L

//
// MessageId: pR_ERROR_INVALID_ACCOUNT_NAME
//
// MessageText:
//
//  The name provided is not a properly formed account name.
//
#define pR_ERROR_INVALID_ACCOUNT_NAME       1315L

//
// MessageId: pR_ERROR_USER_EXISTS
//
// MessageText:
//
//  The specified user already exists.
//
#define pR_ERROR_USER_EXISTS                1316L

//
// MessageId: pR_ERROR_NO_SUCH_USER
//
// MessageText:
//
//  The specified user does not exist.
//
#define pR_ERROR_NO_SUCH_USER               1317L

//
// MessageId: pR_ERROR_GROUP_EXISTS
//
// MessageText:
//
//  The specified group already exists.
//
#define pR_ERROR_GROUP_EXISTS               1318L

//
// MessageId: pR_ERROR_NO_SUCH_GROUP
//
// MessageText:
//
//  The specified group does not exist.
//
#define pR_ERROR_NO_SUCH_GROUP              1319L

//
// MessageId: pR_ERROR_MEMBER_IN_GROUP
//
// MessageText:
//
//  Either the specified user account is already a member of the specified
//  group, or the specified group cannot be deleted because it contains
//  a member.
//
#define pR_ERROR_MEMBER_IN_GROUP            1320L

//
// MessageId: pR_ERROR_MEMBER_NOT_IN_GROUP
//
// MessageText:
//
//  The specified user account is not a member of the specified group account.
//
#define pR_ERROR_MEMBER_NOT_IN_GROUP        1321L

//
// MessageId: pR_ERROR_LAST_ADMIN
//
// MessageText:
//
//  The last remaining administration account cannot be disabled
//  or deleted.
//
#define pR_ERROR_LAST_ADMIN                 1322L

//
// MessageId: pR_ERROR_WRONG_PASSWORD
//
// MessageText:
//
//  Unable to update the password.  The value provided as the current
//  password is incorrect.
//
#define pR_ERROR_WRONG_PASSWORD             1323L

//
// MessageId: pR_ERROR_ILL_FORMED_PASSWORD
//
// MessageText:
//
//  Unable to update the password.  The value provided for the new password
//  contains values that are not allowed in passwords.
//
#define pR_ERROR_ILL_FORMED_PASSWORD        1324L

//
// MessageId: pR_ERROR_PASSWORD_RESTRICTION
//
// MessageText:
//
//  Unable to update the password because a password update rule has been
//  violated.
//
#define pR_ERROR_PASSWORD_RESTRICTION       1325L

//
// MessageId: pR_ERROR_LOGON_FAILURE
//
// MessageText:
//
//  Logon failure: unknown user name or bad password.
//
#define pR_ERROR_LOGON_FAILURE              1326L

//
// MessageId: pR_ERROR_ACCOUNT_RESTRICTION
//
// MessageText:
//
//  Logon failure: user account restriction.
//
#define pR_ERROR_ACCOUNT_RESTRICTION        1327L

//
// MessageId: pR_ERROR_INVALID_LOGON_HOURS
//
// MessageText:
//
//  Logon failure: account logon time restriction violation.
//
#define pR_ERROR_INVALID_LOGON_HOURS        1328L

//
// MessageId: pR_ERROR_INVALID_WORKSTATION
//
// MessageText:
//
//  Logon failure: user not allowed to log on to this computer.
//
#define pR_ERROR_INVALID_WORKSTATION        1329L

//
// MessageId: pR_ERROR_PASSWORD_EXPIRED
//
// MessageText:
//
//  Logon failure: the specified account password has expired.
//
#define pR_ERROR_PASSWORD_EXPIRED           1330L

//
// MessageId: pR_ERROR_ACCOUNT_DISABLED
//
// MessageText:
//
//  Logon failure: account currently disabled.
//
#define pR_ERROR_ACCOUNT_DISABLED           1331L

//
// MessageId: pR_ERROR_NONE_MAPPED
//
// MessageText:
//
//  No mapping between account names and security IDs was done.
//
#define pR_ERROR_NONE_MAPPED                1332L

//
// MessageId: pR_ERROR_TOO_MANY_LUIDS_REQUESTED
//
// MessageText:
//
//  Too many local user identifiers (LUIDs) were requested at one time.
//
#define pR_ERROR_TOO_MANY_LUIDS_REQUESTED   1333L

//
// MessageId: pR_ERROR_LUIDS_EXHAUSTED
//
// MessageText:
//
//  No more local user identifiers (LUIDs) are available.
//
#define pR_ERROR_LUIDS_EXHAUSTED            1334L

//
// MessageId: pR_ERROR_INVALID_SUB_AUTHORITY
//
// MessageText:
//
//  The subauthority part of a security ID is invalid for this particular use.
//
#define pR_ERROR_INVALID_SUB_AUTHORITY      1335L

//
// MessageId: pR_ERROR_INVALID_ACL
//
// MessageText:
//
//  The access control list (ACL) structure is invalid.
//
#define pR_ERROR_INVALID_ACL                1336L

//
// MessageId: pR_ERROR_INVALID_SID
//
// MessageText:
//
//  The security ID structure is invalid.
//
#define pR_ERROR_INVALID_SID                1337L

//
// MessageId: pR_ERROR_INVALID_SECURITY_DESCR
//
// MessageText:
//
//  The security descriptor structure is invalid.
//
#define pR_ERROR_INVALID_SECURITY_DESCR     1338L

//
// MessageId: pR_ERROR_BAD_INHERITANCE_ACL
//
// MessageText:
//
//  The inherited access control list (ACL) or access control entry (ACE)
//  could not be built.
//
#define pR_ERROR_BAD_INHERITANCE_ACL        1340L

//
// MessageId: pR_ERROR_SERVER_DISABLED
//
// MessageText:
//
//  The server is currently disabled.
//
#define pR_ERROR_SERVER_DISABLED            1341L

//
// MessageId: pR_ERROR_SERVER_NOT_DISABLED
//
// MessageText:
//
//  The server is currently enabled.
//
#define pR_ERROR_SERVER_NOT_DISABLED        1342L

//
// MessageId: pR_ERROR_INVALID_ID_AUTHORITY
//
// MessageText:
//
//  The value provided was an invalid value for an identifier authority.
//
#define pR_ERROR_INVALID_ID_AUTHORITY       1343L

//
// MessageId: pR_ERROR_ALLOTTED_SPACE_EXCEEDED
//
// MessageText:
//
//  No more memory is available for security information updates.
//
#define pR_ERROR_ALLOTTED_SPACE_EXCEEDED    1344L

//
// MessageId: pR_ERROR_INVALID_GROUP_ATTRIBUTES
//
// MessageText:
//
//  The specified attributes are invalid, or incompatible with the
//  attributes for the group as a whole.
//
#define pR_ERROR_INVALID_GROUP_ATTRIBUTES   1345L

//
// MessageId: pR_ERROR_BAD_IMPERSONATION_LEVEL
//
// MessageText:
//
//  Either a required impersonation level was not provided, or the
//  provided impersonation level is invalid.
//
#define pR_ERROR_BAD_IMPERSONATION_LEVEL    1346L

//
// MessageId: pR_ERROR_CANT_OPEN_ANONYMOUS
//
// MessageText:
//
//  Cannot open an anonymous level security token.
//
#define pR_ERROR_CANT_OPEN_ANONYMOUS        1347L

//
// MessageId: pR_ERROR_BAD_VALIDATION_CLASS
//
// MessageText:
//
//  The validation information class requested was invalid.
//
#define pR_ERROR_BAD_VALIDATION_CLASS       1348L

//
// MessageId: pR_ERROR_BAD_TOKEN_TYPE
//
// MessageText:
//
//  The type of the token is inappropriate for its attempted use.
//
#define pR_ERROR_BAD_TOKEN_TYPE             1349L

//
// MessageId: pR_ERROR_NO_SECURITY_ON_OBJECT
//
// MessageText:
//
//  Unable to perform a security operation on an object
//  that has no associated security.
//
#define pR_ERROR_NO_SECURITY_ON_OBJECT      1350L

//
// MessageId: pR_ERROR_CANT_ACCESS_DOMAIN_INFO
//
// MessageText:
//
//  Indicates a Windows NT Server could not be contacted or that
//  objects within the domain are protected such that necessary
//  information could not be retrieved.
//
#define pR_ERROR_CANT_ACCESS_DOMAIN_INFO    1351L

//
// MessageId: pR_ERROR_INVALID_SERVER_STATE
//
// MessageText:
//
//  The security account manager (SAM) or local security
//  authority (LSA) server was in the wrong state to perform
//  the security operation.
//
#define pR_ERROR_INVALID_SERVER_STATE       1352L

//
// MessageId: pR_ERROR_INVALID_DOMAIN_STATE
//
// MessageText:
//
//  The domain was in the wrong state to perform the security operation.
//
#define pR_ERROR_INVALID_DOMAIN_STATE       1353L

//
// MessageId: pR_ERROR_INVALID_DOMAIN_ROLE
//
// MessageText:
//
//  This operation is only allowed for the Primary Domain Controller of the domain.
//
#define pR_ERROR_INVALID_DOMAIN_ROLE        1354L

//
// MessageId: pR_ERROR_NO_SUCH_DOMAIN
//
// MessageText:
//
//  The specified domain did not exist.
//
#define pR_ERROR_NO_SUCH_DOMAIN             1355L

//
// MessageId: pR_ERROR_DOMAIN_EXISTS
//
// MessageText:
//
//  The specified domain already exists.
//
#define pR_ERROR_DOMAIN_EXISTS              1356L

//
// MessageId: pR_ERROR_DOMAIN_LIMIT_EXCEEDED
//
// MessageText:
//
//  An attempt was made to exceed the limit on the number of domains per server.
//
#define pR_ERROR_DOMAIN_LIMIT_EXCEEDED      1357L

//
// MessageId: pR_ERROR_INTERNAL_DB_CORRUPTION
//
// MessageText:
//
//  Unable to complete the requested operation because of either a
//  catastrophic media failure or a data structure corruption on the disk.
//
#define pR_ERROR_INTERNAL_DB_CORRUPTION     1358L

//
// MessageId: pR_ERROR_INTERNAL_ERROR
//
// MessageText:
//
//  The security account database contains an internal inconsistency.
//
#define pR_ERROR_INTERNAL_ERROR             1359L

//
// MessageId: pR_ERROR_GENERIC_NOT_MAPPED
//
// MessageText:
//
//  Generic access types were contained in an access mask which should
//  already be mapped to nongeneric types.
//
#define pR_ERROR_GENERIC_NOT_MAPPED         1360L

//
// MessageId: pR_ERROR_BAD_DESCRIPTOR_FORMAT
//
// MessageText:
//
//  A security descriptor is not in the right format (absolute or self-relative).
//
#define pR_ERROR_BAD_DESCRIPTOR_FORMAT      1361L

//
// MessageId: pR_ERROR_NOT_LOGON_PROCESS
//
// MessageText:
//
//  The requested action is restricted for use by logon processes
//  only.  The calling process has not registered as a logon process.
//
#define pR_ERROR_NOT_LOGON_PROCESS          1362L

//
// MessageId: pR_ERROR_LOGON_SESSION_EXISTS
//
// MessageText:
//
//  Cannot start a new logon session with an ID that is already in use.
//
#define pR_ERROR_LOGON_SESSION_EXISTS       1363L

//
// MessageId: pR_ERROR_NO_SUCH_PACKAGE
//
// MessageText:
//
//  A specified authentication package is unknown.
//
#define pR_ERROR_NO_SUCH_PACKAGE            1364L

//
// MessageId: pR_ERROR_BAD_LOGON_SESSION_STATE
//
// MessageText:
//
//  The logon session is not in a state that is consistent with the
//  requested operation.
//
#define pR_ERROR_BAD_LOGON_SESSION_STATE    1365L

//
// MessageId: pR_ERROR_LOGON_SESSION_COLLISION
//
// MessageText:
//
//  The logon session ID is already in use.
//
#define pR_ERROR_LOGON_SESSION_COLLISION    1366L

//
// MessageId: pR_ERROR_INVALID_LOGON_TYPE
//
// MessageText:
//
//  A logon request contained an invalid logon type value.
//
#define pR_ERROR_INVALID_LOGON_TYPE         1367L

//
// MessageId: pR_ERROR_CANNOT_IMPERSONATE
//
// MessageText:
//
//  Unable to impersonate using a named pipe until data has been read
//  from that pipe.
//
#define pR_ERROR_CANNOT_IMPERSONATE         1368L

//
// MessageId: pR_ERROR_RXACT_INVALID_STATE
//
// MessageText:
//
//  The transaction state of a registry subtree is incompatible with the
//  requested operation.
//
#define pR_ERROR_RXACT_INVALID_STATE        1369L

//
// MessageId: pR_ERROR_RXACT_COMMIT_FAILURE
//
// MessageText:
//
//  An internal security database corruption has been encountered.
//
#define pR_ERROR_RXACT_COMMIT_FAILURE       1370L

//
// MessageId: pR_ERROR_SPECIAL_ACCOUNT
//
// MessageText:
//
//  Cannot perform this operation on built-in accounts.
//
#define pR_ERROR_SPECIAL_ACCOUNT            1371L

//
// MessageId: pR_ERROR_SPECIAL_GROUP
//
// MessageText:
//
//  Cannot perform this operation on this built-in special group.
//
#define pR_ERROR_SPECIAL_GROUP              1372L

//
// MessageId: pR_ERROR_SPECIAL_USER
//
// MessageText:
//
//  Cannot perform this operation on this built-in special user.
//
#define pR_ERROR_SPECIAL_USER               1373L

//
// MessageId: pR_ERROR_MEMBERS_PRIMARY_GROUP
//
// MessageText:
//
//  The user cannot be removed from a group because the group
//  is currently the user's primary group.
//
#define pR_ERROR_MEMBERS_PRIMARY_GROUP      1374L

//
// MessageId: pR_ERROR_TOKEN_ALREADY_IN_USE
//
// MessageText:
//
//  The token is already in use as a primary token.
//
#define pR_ERROR_TOKEN_ALREADY_IN_USE       1375L

//
// MessageId: pR_ERROR_NO_SUCH_ALIAS
//
// MessageText:
//
//  The specified local group does not exist.
//
#define pR_ERROR_NO_SUCH_ALIAS              1376L

//
// MessageId: pR_ERROR_MEMBER_NOT_IN_ALIAS
//
// MessageText:
//
//  The specified account name is not a member of the local group.
//
#define pR_ERROR_MEMBER_NOT_IN_ALIAS        1377L

//
// MessageId: pR_ERROR_MEMBER_IN_ALIAS
//
// MessageText:
//
//  The specified account name is already a member of the local group.
//
#define pR_ERROR_MEMBER_IN_ALIAS            1378L

//
// MessageId: pR_ERROR_ALIAS_EXISTS
//
// MessageText:
//
//  The specified local group already exists.
//
#define pR_ERROR_ALIAS_EXISTS               1379L

//
// MessageId: pR_ERROR_LOGON_NOT_GRANTED
//
// MessageText:
//
//  Logon failure: the user has not been granted the requested
//  logon type at this computer.
//
#define pR_ERROR_LOGON_NOT_GRANTED          1380L

//
// MessageId: pR_ERROR_TOO_MANY_SECRETS
//
// MessageText:
//
//  The maximum number of secrets that may be stored in a single system has been
//  exceeded.
//
#define pR_ERROR_TOO_MANY_SECRETS           1381L

//
// MessageId: pR_ERROR_SECRET_TOO_LONG
//
// MessageText:
//
//  The length of a secret exceeds the maximum length allowed.
//
#define pR_ERROR_SECRET_TOO_LONG            1382L

//
// MessageId: pR_ERROR_INTERNAL_DB_ERROR
//
// MessageText:
//
//  The local security authority database contains an internal inconsistency.
//
#define pR_ERROR_INTERNAL_DB_ERROR          1383L

//
// MessageId: pR_ERROR_TOO_MANY_CONTEXT_IDS
//
// MessageText:
//
//  During a logon attempt, the user's security context accumulated too many
//  security IDs.
//
#define pR_ERROR_TOO_MANY_CONTEXT_IDS       1384L

//
// MessageId: pR_ERROR_LOGON_TYPE_NOT_GRANTED
//
// MessageText:
//
//  Logon failure: the user has not been granted the requested logon type
//  at this computer.
//
#define pR_ERROR_LOGON_TYPE_NOT_GRANTED     1385L

//
// MessageId: pR_ERROR_NT_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
//  A cross-encrypted password is necessary to change a user password.
//
#define pR_ERROR_NT_CROSS_ENCRYPTION_REQUIRED 1386L

//
// MessageId: pR_ERROR_NO_SUCH_MEMBER
//
// MessageText:
//
//  A new member could not be added to a local group because the member does
//  not exist.
//
#define pR_ERROR_NO_SUCH_MEMBER             1387L

//
// MessageId: pR_ERROR_INVALID_MEMBER
//
// MessageText:
//
//  A new member could not be added to a local group because the member has the
//  wrong account type.
//
#define pR_ERROR_INVALID_MEMBER             1388L

//
// MessageId: pR_ERROR_TOO_MANY_SIDS
//
// MessageText:
//
//  Too many security IDs have been specified.
//
#define pR_ERROR_TOO_MANY_SIDS              1389L

//
// MessageId: pR_ERROR_LM_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
//  A cross-encrypted password is necessary to change this user password.
//
#define pR_ERROR_LM_CROSS_ENCRYPTION_REQUIRED 1390L

//
// MessageId: pR_ERROR_NO_INHERITANCE
//
// MessageText:
//
//  Indicates an ACL contains no inheritable components.
//
#define pR_ERROR_NO_INHERITANCE             1391L

//
// MessageId: pR_ERROR_FILE_CORRUPT
//
// MessageText:
//
//  The file or directory is corrupted and unreadable.
//
#define pR_ERROR_FILE_CORRUPT               1392L

//
// MessageId: pR_ERROR_DISK_CORRUPT
//
// MessageText:
//
//  The disk structure is corrupted and unreadable.
//
#define pR_ERROR_DISK_CORRUPT               1393L

//
// MessageId: pR_ERROR_NO_USER_SESSION_KEY
//
// MessageText:
//
//  There is no user session key for the specified logon session.
//
#define pR_ERROR_NO_USER_SESSION_KEY        1394L

//
// MessageId: pR_ERROR_LICENSE_QUOTA_EXCEEDED
//
// MessageText:
//
//  The service being accessed is licensed for a particular number of connections.
//  No more connections can be made to the service at this time
//  because there are already as many connections as the service can accept.
//
#define pR_ERROR_LICENSE_QUOTA_EXCEEDED     1395L

// End of security error codes



///////////////////////////
//                       //
// WinUser Error Codes   //
//                       //
///////////////////////////


//
// MessageId: pR_ERROR_INVALID_WINDOW_HANDLE
//
// MessageText:
//
//  Invalid window handle.
//
#define pR_ERROR_INVALID_WINDOW_HANDLE      1400L

//
// MessageId: pR_ERROR_INVALID_MENU_HANDLE
//
// MessageText:
//
//  Invalid menu handle.
//
#define pR_ERROR_INVALID_MENU_HANDLE        1401L

//
// MessageId: pR_ERROR_INVALID_CURSOR_HANDLE
//
// MessageText:
//
//  Invalid cursor handle.
//
#define pR_ERROR_INVALID_CURSOR_HANDLE      1402L

//
// MessageId: pR_ERROR_INVALID_ACCEL_HANDLE
//
// MessageText:
//
//  Invalid accelerator table handle.
//
#define pR_ERROR_INVALID_ACCEL_HANDLE       1403L

//
// MessageId: pR_ERROR_INVALID_HOOK_HANDLE
//
// MessageText:
//
//  Invalid hook handle.
//
#define pR_ERROR_INVALID_HOOK_HANDLE        1404L

//
// MessageId: pR_ERROR_INVALID_DWP_HANDLE
//
// MessageText:
//
//  Invalid handle to a multiple-window position structure.
//
#define pR_ERROR_INVALID_DWP_HANDLE         1405L

//
// MessageId: pR_ERROR_TLW_WITH_WSCHILD
//
// MessageText:
//
//  Cannot create a top-level child window.
//
#define pR_ERROR_TLW_WITH_WSCHILD           1406L

//
// MessageId: pR_ERROR_CANNOT_FIND_WND_CLASS
//
// MessageText:
//
//  Cannot find window class.
//
#define pR_ERROR_CANNOT_FIND_WND_CLASS      1407L

//
// MessageId: pR_ERROR_WINDOW_OF_OTHER_THREAD
//
// MessageText:
//
//  Invalid window; it belongs to other thread.
//
#define pR_ERROR_WINDOW_OF_OTHER_THREAD     1408L

//
// MessageId: pR_ERROR_HOTKEY_ALREADY_REGISTERED
//
// MessageText:
//
//  Hot key is already registered.
//
#define pR_ERROR_HOTKEY_ALREADY_REGISTERED  1409L

//
// MessageId: pR_ERROR_CLASS_ALREADY_EXISTS
//
// MessageText:
//
//  Class already exists.
//
#define pR_ERROR_CLASS_ALREADY_EXISTS       1410L

//
// MessageId: pR_ERROR_CLASS_DOES_NOT_EXIST
//
// MessageText:
//
//  Class does not exist.
//
#define pR_ERROR_CLASS_DOES_NOT_EXIST       1411L

//
// MessageId: pR_ERROR_CLASS_HAS_WINDOWS
//
// MessageText:
//
//  Class still has open windows.
//
#define pR_ERROR_CLASS_HAS_WINDOWS          1412L

//
// MessageId: pR_ERROR_INVALID_INDEX
//
// MessageText:
//
//  Invalid index.
//
#define pR_ERROR_INVALID_INDEX              1413L

//
// MessageId: pR_ERROR_INVALID_ICON_HANDLE
//
// MessageText:
//
//  Invalid icon handle.
//
#define pR_ERROR_INVALID_ICON_HANDLE        1414L

//
// MessageId: pR_ERROR_PRIVATE_DIALOG_INDEX
//
// MessageText:
//
//  Using private DIALOG window words.
//
#define pR_ERROR_PRIVATE_DIALOG_INDEX       1415L

//
// MessageId: pR_ERROR_LISTBOX_ID_NOT_FOUND
//
// MessageText:
//
//  The list box identifier was not found.
//
#define pR_ERROR_LISTBOX_ID_NOT_FOUND       1416L

//
// MessageId: pR_ERROR_NO_WILDCARD_CHARACTERS
//
// MessageText:
//
//  No wildcards were found.
//
#define pR_ERROR_NO_WILDCARD_CHARACTERS     1417L

//
// MessageId: pR_ERROR_CLIPBOARD_NOT_OPEN
//
// MessageText:
//
//  Thread does not have a clipboard open.
//
#define pR_ERROR_CLIPBOARD_NOT_OPEN         1418L

//
// MessageId: pR_ERROR_HOTKEY_NOT_REGISTERED
//
// MessageText:
//
//  Hot key is not registered.
//
#define pR_ERROR_HOTKEY_NOT_REGISTERED      1419L

//
// MessageId: pR_ERROR_WINDOW_NOT_DIALOG
//
// MessageText:
//
//  The window is not a valid dialog window.
//
#define pR_ERROR_WINDOW_NOT_DIALOG          1420L

//
// MessageId: pR_ERROR_CONTROL_ID_NOT_FOUND
//
// MessageText:
//
//  Control ID not found.
//
#define pR_ERROR_CONTROL_ID_NOT_FOUND       1421L

//
// MessageId: pR_ERROR_INVALID_COMBOBOX_MESSAGE
//
// MessageText:
//
//  Invalid message for a combo box because it does not have an edit control.
//
#define pR_ERROR_INVALID_COMBOBOX_MESSAGE   1422L

//
// MessageId: pR_ERROR_WINDOW_NOT_COMBOBOX
//
// MessageText:
//
//  The window is not a combo box.
//
#define pR_ERROR_WINDOW_NOT_COMBOBOX        1423L

//
// MessageId: pR_ERROR_INVALID_EDIT_HEIGHT
//
// MessageText:
//
//  Height must be less than 256.
//
#define pR_ERROR_INVALID_EDIT_HEIGHT        1424L

//
// MessageId: pR_ERROR_DC_NOT_FOUND
//
// MessageText:
//
//  Invalid device context (DC) handle.
//
#define pR_ERROR_DC_NOT_FOUND               1425L

//
// MessageId: pR_ERROR_INVALID_HOOK_FILTER
//
// MessageText:
//
//  Invalid hook procedure type.
//
#define pR_ERROR_INVALID_HOOK_FILTER        1426L

//
// MessageId: pR_ERROR_INVALID_FILTER_PROC
//
// MessageText:
//
//  Invalid hook procedure.
//
#define pR_ERROR_INVALID_FILTER_PROC        1427L

//
// MessageId: pR_ERROR_HOOK_NEEDS_HMOD
//
// MessageText:
//
//  Cannot set nonlocal hook without a module handle.
//
#define pR_ERROR_HOOK_NEEDS_HMOD            1428L

//
// MessageId: pR_ERROR_GLOBAL_ONLY_HOOK
//
// MessageText:
//
//  This hook procedure can only be set globally.
//
#define pR_ERROR_GLOBAL_ONLY_HOOK           1429L

//
// MessageId: pR_ERROR_JOURNAL_HOOK_SET
//
// MessageText:
//
//  The journal hook procedure is already installed.
//
#define pR_ERROR_JOURNAL_HOOK_SET           1430L

//
// MessageId: pR_ERROR_HOOK_NOT_INSTALLED
//
// MessageText:
//
//  The hook procedure is not installed.
//
#define pR_ERROR_HOOK_NOT_INSTALLED         1431L

//
// MessageId: pR_ERROR_INVALID_LB_MESSAGE
//
// MessageText:
//
//  Invalid message for single-selection list box.
//
#define pR_ERROR_INVALID_LB_MESSAGE         1432L

//
// MessageId: pR_ERROR_SETCOUNT_ON_BAD_LB
//
// MessageText:
//
//  LB_SETCOUNT sent to non-lazy list box.
//
#define pR_ERROR_SETCOUNT_ON_BAD_LB         1433L

//
// MessageId: pR_ERROR_LB_WITHOUT_TABSTOPS
//
// MessageText:
//
//  This list box does not support tab stops.
//
#define pR_ERROR_LB_WITHOUT_TABSTOPS        1434L

//
// MessageId: pR_ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
//
// MessageText:
//
//  Cannot destroy object created by another thread.
//
#define pR_ERROR_DESTROY_OBJECT_OF_OTHER_THREAD 1435L

//
// MessageId: pR_ERROR_CHILD_WINDOW_MENU
//
// MessageText:
//
//  Child windows cannot have menus.
//
#define pR_ERROR_CHILD_WINDOW_MENU          1436L

//
// MessageId: pR_ERROR_NO_SYSTEM_MENU
//
// MessageText:
//
//  The window does not have a system menu.
//
#define pR_ERROR_NO_SYSTEM_MENU             1437L

//
// MessageId: pR_ERROR_INVALID_MSGBOX_STYLE
//
// MessageText:
//
//  Invalid message box style.
//
#define pR_ERROR_INVALID_MSGBOX_STYLE       1438L

//
// MessageId: pR_ERROR_INVALID_SPI_VALUE
//
// MessageText:
//
//  Invalid system-wide (SPI_*) parameter.
//
#define pR_ERROR_INVALID_SPI_VALUE          1439L

//
// MessageId: pR_ERROR_SCREEN_ALREADY_LOCKED
//
// MessageText:
//
//  Screen already locked.
//
#define pR_ERROR_SCREEN_ALREADY_LOCKED      1440L

//
// MessageId: pR_ERROR_HWNDS_HAVE_DIFF_PARENT
//
// MessageText:
//
//  All handles to windows in a multiple-window position structure must
//  have the same parent.
//
#define pR_ERROR_HWNDS_HAVE_DIFF_PARENT     1441L

//
// MessageId: pR_ERROR_NOT_CHILD_WINDOW
//
// MessageText:
//
//  The window is not a child window.
//
#define pR_ERROR_NOT_CHILD_WINDOW           1442L

//
// MessageId: pR_ERROR_INVALID_GW_COMMAND
//
// MessageText:
//
//  Invalid GW_* command.
//
#define pR_ERROR_INVALID_GW_COMMAND         1443L

//
// MessageId: pR_ERROR_INVALID_THREAD_ID
//
// MessageText:
//
//  Invalid thread identifier.
//
#define pR_ERROR_INVALID_THREAD_ID          1444L

//
// MessageId: pR_ERROR_NON_MDICHILD_WINDOW
//
// MessageText:
//
//  Cannot process a message from a window that is not a multiple document
//  interface (MDI) window.
//
#define pR_ERROR_NON_MDICHILD_WINDOW        1445L

//
// MessageId: pR_ERROR_POPUP_ALREADY_ACTIVE
//
// MessageText:
//
//  Popup menu already active.
//
#define pR_ERROR_POPUP_ALREADY_ACTIVE       1446L

//
// MessageId: pR_ERROR_NO_SCROLLBARS
//
// MessageText:
//
//  The window does not have scroll bars.
//
#define pR_ERROR_NO_SCROLLBARS              1447L

//
// MessageId: pR_ERROR_INVALID_SCROLLBAR_RANGE
//
// MessageText:
//
//  Scroll bar range cannot be greater than 0x7FFF.
//
#define pR_ERROR_INVALID_SCROLLBAR_RANGE    1448L

//
// MessageId: pR_ERROR_INVALID_SHOWWIN_COMMAND
//
// MessageText:
//
//  Cannot show or remove the window in the way specified.
//
#define pR_ERROR_INVALID_SHOWWIN_COMMAND    1449L

//
// MessageId: pR_ERROR_NO_SYSTEM_RESOURCES
//
// MessageText:
//
//  Insufficient system resources exist to complete the requested service.
//
#define pR_ERROR_NO_SYSTEM_RESOURCES        1450L

//
// MessageId: pR_ERROR_NONPAGED_SYSTEM_RESOURCES
//
// MessageText:
//
//  Insufficient system resources exist to complete the requested service.
//
#define pR_ERROR_NONPAGED_SYSTEM_RESOURCES  1451L

//
// MessageId: pR_ERROR_PAGED_SYSTEM_RESOURCES
//
// MessageText:
//
//  Insufficient system resources exist to complete the requested service.
//
#define pR_ERROR_PAGED_SYSTEM_RESOURCES     1452L

//
// MessageId: pR_ERROR_WORKING_SET_QUOTA
//
// MessageText:
//
//  Insufficient quota to complete the requested service.
//
#define pR_ERROR_WORKING_SET_QUOTA          1453L

//
// MessageId: pR_ERROR_PAGEFILE_QUOTA
//
// MessageText:
//
//  Insufficient quota to complete the requested service.
//
#define pR_ERROR_PAGEFILE_QUOTA             1454L

//
// MessageId: pR_ERROR_COMMITMENT_LIMIT
//
// MessageText:
//
//  The paging file is too small for this operation to complete.
//
#define pR_ERROR_COMMITMENT_LIMIT           1455L

//
// MessageId: pR_ERROR_MENU_ITEM_NOT_FOUND
//
// MessageText:
//
//  A menu item was not found.
//
#define pR_ERROR_MENU_ITEM_NOT_FOUND        1456L

//
// MessageId: pR_ERROR_INVALID_KEYBOARD_HANDLE
//
// MessageText:
//
//  Invalid keyboard layout handle.
//
#define pR_ERROR_INVALID_KEYBOARD_HANDLE    1457L

//
// MessageId: pR_ERROR_HOOK_TYPE_NOT_ALLOWED
//
// MessageText:
//
//  Hook type not allowed.
//
#define pR_ERROR_HOOK_TYPE_NOT_ALLOWED      1458L

//
// MessageId: pR_ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
//
// MessageText:
//
//  This operation requires an interactive window station.
//
#define pR_ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION 1459L

//
// MessageId: pR_ERROR_TIMEOUT
//
// MessageText:
//
//  This operation returned because the timeout period expired.
//
#define pR_ERROR_TIMEOUT                    1460L

//
// MessageId: pR_ERROR_INVALID_MONITOR_HANDLE
//
// MessageText:
//
//  Invalid monitor handle.
//
#define pR_ERROR_INVALID_MONITOR_HANDLE     1461L

// End of WinUser error codes



///////////////////////////
//                       //
// Eventlog Status Codes //
//                       //
///////////////////////////


//
// MessageId: pR_ERROR_EVENTLOG_FILE_CORRUPT
//
// MessageText:
//
//  The event log file is corrupted.
//
#define pR_ERROR_EVENTLOG_FILE_CORRUPT      1500L

//
// MessageId: pR_ERROR_EVENTLOG_CANT_START
//
// MessageText:
//
//  No event log file could be opened, so the event logging service did not start.
//
#define pR_ERROR_EVENTLOG_CANT_START        1501L

//
// MessageId: pR_ERROR_LOG_FILE_FULL
//
// MessageText:
//
//  The event log file is full.
//
#define pR_ERROR_LOG_FILE_FULL              1502L

//
// MessageId: pR_ERROR_EVENTLOG_FILE_CHANGED
//
// MessageText:
//
//  The event log file has changed between read operations.
//
#define pR_ERROR_EVENTLOG_FILE_CHANGED      1503L

// End of eventlog error codes



///////////////////////////
//                       //
// MSI Error Codes       //
//                       //
///////////////////////////


//
// MessageId: pR_ERROR_INSTALL_SERVICE
//
// MessageText:
//
//  Failure accessing install service.
//
#define pR_ERROR_INSTALL_SERVICE            1601L

//
// MessageId: pR_ERROR_INSTALL_USEREXIT
//
// MessageText:
//
//  The user canceled the installation.
//
#define pR_ERROR_INSTALL_USEREXIT           1602L

//
// MessageId: pR_ERROR_INSTALL_FAILURE
//
// MessageText:
//
//  Fatal error during installation.
//
#define pR_ERROR_INSTALL_FAILURE            1603L

//
// MessageId: pR_ERROR_INSTALL_SUSPEND
//
// MessageText:
//
//  Installation suspended, incomplete.
//
#define pR_ERROR_INSTALL_SUSPEND            1604L

//
// MessageId: pR_ERROR_UNKNOWN_PRODUCT
//
// MessageText:
//
//  Product code not registered.
//
#define pR_ERROR_UNKNOWN_PRODUCT            1605L

//
// MessageId: pR_ERROR_UNKNOWN_FEATURE
//
// MessageText:
//
//  Feature ID not registered.
//
#define pR_ERROR_UNKNOWN_FEATURE            1606L

//
// MessageId: pR_ERROR_UNKNOWN_COMPONENT
//
// MessageText:
//
//  Component ID not registered.
//
#define pR_ERROR_UNKNOWN_COMPONENT          1607L

//
// MessageId: pR_ERROR_UNKNOWN_PROPERTY
//
// MessageText:
//
//  Unknown property.
//
#define pR_ERROR_UNKNOWN_PROPERTY           1608L

//
// MessageId: pR_ERROR_INVALID_HANDLE_STATE
//
// MessageText:
//
//  Handle is in an invalid state.
//
#define pR_ERROR_INVALID_HANDLE_STATE       1609L

//
// MessageId: pR_ERROR_BAD_CONFIGURATION
//
// MessageText:
//
//  Configuration data corrupt.
//
#define pR_ERROR_BAD_CONFIGURATION          1610L

//
// MessageId: pR_ERROR_INDEX_ABSENT
//
// MessageText:
//
//  Language not available.
//
#define pR_ERROR_INDEX_ABSENT               1611L

//
// MessageId: pR_ERROR_INSTALL_SOURCE_ABSENT
//
// MessageText:
//
//  Install source unavailable.
//
#define pR_ERROR_INSTALL_SOURCE_ABSENT      1612L

//
// MessageId: pR_ERROR_BAD_DATABASE_VERSION
//
// MessageText:
//
//  Database version unsupported.
//
#define pR_ERROR_BAD_DATABASE_VERSION       1613L

//
// MessageId: pR_ERROR_PRODUCT_UNINSTALLED
//
// MessageText:
//
//  Product is uninstalled.
//
#define pR_ERROR_PRODUCT_UNINSTALLED        1614L

//
// MessageId: pR_ERROR_BAD_QUERY_SYNTAX
//
// MessageText:
//
//  SQL query syntax invalid or unsupported.
//
#define pR_ERROR_BAD_QUERY_SYNTAX           1615L

//
// MessageId: pR_ERROR_INVALID_FIELD
//
// MessageText:
//
//  Record field does not exist.
//
#define pR_ERROR_INVALID_FIELD              1616L

// End of MSI error codes


//////////////////////////////////////////////////////////
///////////////////			WINSOCK ERRORs

#define pR_WSABASEERR              10000
/*
 * Windows Sockets definitions of regular Microsoft C error constants
 */
#define pR_WSAEINTR                (pR_WSABASEERR+4)
#define pR_WSAEBADF                (pR_WSABASEERR+9)
#define pR_WSAEACCES               (pR_WSABASEERR+13)
#define pR_WSAEFAULT               (pR_WSABASEERR+14)
#define pR_WSAEINVAL               (pR_WSABASEERR+22)
#define pR_WSAEMFILE               (pR_WSABASEERR+24)

/*
 * Windows Sockets definitions of regular Berkeley error constants
 */
#define pR_WSAEWOULDBLOCK          (pR_WSABASEERR+35)
#define pR_WSAEINPROGRESS          (pR_WSABASEERR+36)
#define pR_WSAEALREADY             (pR_WSABASEERR+37)
#define pR_WSAENOTSOCK             (pR_WSABASEERR+38)
#define pR_WSAEDESTADDRREQ         (pR_WSABASEERR+39)
#define pR_WSAEMSGSIZE             (pR_WSABASEERR+40)
#define pR_WSAEPROTOTYPE           (pR_WSABASEERR+41)
#define pR_WSAENOPROTOOPT          (pR_WSABASEERR+42)
#define pR_WSAEPROTONOSUPPORT      (pR_WSABASEERR+43)
#define pR_WSAESOCKTNOSUPPORT      (pR_WSABASEERR+44)
#define pR_WSAEOPNOTSUPP           (pR_WSABASEERR+45)
#define pR_WSAEPFNOSUPPORT         (pR_WSABASEERR+46)
#define pR_WSAEAFNOSUPPORT         (pR_WSABASEERR+47)
#define pR_WSAEADDRINUSE           (pR_WSABASEERR+48)
#define pR_WSAEADDRNOTAVAIL        (pR_WSABASEERR+49)
#define pR_WSAENETDOWN             (pR_WSABASEERR+50)
#define pR_WSAENETUNREACH          (pR_WSABASEERR+51)
#define pR_WSAENETRESET            (pR_WSABASEERR+52)
#define pR_WSAECONNABORTED         (pR_WSABASEERR+53)
#define pR_WSAECONNRESET           (pR_WSABASEERR+54)
#define pR_WSAENOBUFS              (pR_WSABASEERR+55)
#define pR_WSAEISCONN              (pR_WSABASEERR+56)
#define pR_WSAENOTCONN             (pR_WSABASEERR+57)
#define pR_WSAESHUTDOWN            (pR_WSABASEERR+58)
#define pR_WSAETOOMANYREFS         (pR_WSABASEERR+59)
#define pR_WSAETIMEDOUT            (pR_WSABASEERR+60)
#define pR_WSAECONNREFUSED         (pR_WSABASEERR+61)
#define pR_WSAELOOP                (pR_WSABASEERR+62)
#define pR_WSAENAMETOOLONG         (pR_WSABASEERR+63)
#define pR_WSAEHOSTDOWN            (pR_WSABASEERR+64)
#define pR_WSAEHOSTUNREACH         (pR_WSABASEERR+65)
#define pR_WSAENOTEMPTY            (pR_WSABASEERR+66)
#define pR_WSAEPROCLIM             (pR_WSABASEERR+67)
#define pR_WSAEUSERS               (pR_WSABASEERR+68)
#define pR_WSAEDQUOT               (pR_WSABASEERR+69)
#define pR_WSAESTALE               (pR_WSABASEERR+70)
#define pR_WSAEREMOTE              (pR_WSABASEERR+71)

#define pR_WSAEDISCON              (pR_WSABASEERR+101)

/*
 * Extended Windows Sockets error constant definitions
 */
#define pR_WSASYSNOTREADY          (pR_WSABASEERR+91)
#define pR_WSAVERNOTSUPPORTED      (pR_WSABASEERR+92)
#define pR_WSANOTINITIALISED       (pR_WSABASEERR+93)

//////////////////////////////////////////////////////////

#endif //_PC_WERR_H

