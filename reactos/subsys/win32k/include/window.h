#ifndef __WIN32K_WINDOW_H
#define __WIN32K_WINDOW_H

struct _PROPERTY;
struct _WINDOW_OBJECT;

#include <windows.h>
#include <ddk/ntddk.h>
#include <include/class.h>
#include <include/msgqueue.h>
#include <include/winsta.h>
#include <include/dce.h>
#include <include/prop.h>

typedef struct _PROPERTY
{
  LIST_ENTRY PropListEntry;
  HANDLE Data;
  ATOM Atom;
} PROPERTY, *PPROPERTY;

VOID FASTCALL
WinPosSetupInternalPos(VOID);

typedef struct _WINDOW_OBJECT
{
  /* Pointer to the window class. */
  PWNDCLASS_OBJECT Class;
  /* Extended style. */
  DWORD ExStyle;
  /* Window name. */
  UNICODE_STRING WindowName;
  /* Style. */
  DWORD Style;
  /* Initial window position. */
  INT x;
  INT y;
  INT Width;
  INT Height;
  /* Parent window handle. */
  HWND ParentHandle;
  /* Window menu handle. */
  HMENU Menu;
  /* Handle of the module that created the window. */
  HINSTANCE Instance;
  /* Unknown. */
  LPVOID Parameters;
  /* Entry in the thread's list of windows. */
  LIST_ENTRY ListEntry;
  /* Pointer to the extra data associated with the window. */
  PULONG ExtraData;
  /* Size of the extra data associated with the window. */
  ULONG ExtraDataSize;
  /* Position of the window. */
  RECT WindowRect;
  /* Position of the window's client area. */
  RECT ClientRect;
  /* Handle for the window. */
  HANDLE Self;
  /* Window flags. */
  ULONG Flags;
  /* FIXME: Don't know. */
  UINT IDMenu;
  /* Handle of region of the window to be updated. */
  HANDLE UpdateRegion;
  /* Pointer to the owning thread's message queue. */
  PUSER_MESSAGE_QUEUE MessageQueue;
  struct _WINDOW_OBJECT* FirstChild;
  struct _WINDOW_OBJECT* LastChild;
  /* Lock for the list of child windows. */
  FAST_MUTEX ChildrenListLock;
  struct _WINDOW_OBJECT* NextSibling;
  struct _WINDOW_OBJECT* PrevSibling;
  /* Entry in the list of thread windows. */
  LIST_ENTRY ThreadListEntry;
  /* Pointer to the parent window. */
  struct _WINDOW_OBJECT* Parent;
  /* DC Entries (DCE) */
  PDCE Dce;
  /* Property list head.*/
  LIST_ENTRY PropListHead;
  /* Scrollbar info */
  PSCROLLBARINFO pHScroll;
  PSCROLLBARINFO pVScroll;
  PSCROLLBARINFO wExtra;
  LONG UserData;
  BOOL Unicode;
  WNDPROC WndProcA;
  WNDPROC WndProcW;
  PETHREAD OwnerThread;
  HWND hWndOwner; /* handle to the owner window (wine doesn't use pointer, for unk. reason)*/
  HWND hWndLastPopup; /* handle to last active popup window (wine doesn't use pointer, for unk. reason)*/
} WINDOW_OBJECT, *PWINDOW_OBJECT;

/* Window flags. */
#define WINDOWOBJECT_NEED_SIZE            (0x00000001)
/* Not used anymore: define WINDOWOBJECT_NEED_BEGINPAINT      (0x00000002) */
#define WINDOWOBJECT_NEED_ERASEBACKGRD    (0x00000004)
#define WINDOWOBJECT_NEED_NCPAINT         (0x00000008)
#define WINDOWOBJECT_NEED_INTERNALPAINT   (0x00000010)
#define WINDOWOBJECT_RESTOREMAX           (0x00000020)

inline BOOL W32kIsDesktopWindow(PWINDOW_OBJECT WindowObject);

inline BOOL W32kIsBroadcastHwnd( HWND hwnd );

NTSTATUS FASTCALL
InitWindowImpl (VOID);

NTSTATUS FASTCALL
CleanupWindowImpl (VOID);

VOID FASTCALL
W32kGetClientRect (PWINDOW_OBJECT WindowObject, PRECT Rect);

PWINDOW_OBJECT FASTCALL
W32kGetWindowObject (HWND hWnd);

VOID FASTCALL
W32kReleaseWindowObject (PWINDOW_OBJECT Window);

HWND STDCALL
W32kCreateDesktopWindow (PWINSTATION_OBJECT WindowStation,
			PWNDCLASS_OBJECT DesktopClass,
			ULONG Width, ULONG Height);

HWND FASTCALL
W32kGetActiveWindow (VOID);

BOOL FASTCALL
W32kIsWindowVisible (HWND Wnd);

BOOL FASTCALL
W32kIsChildWindow (HWND Parent, HWND Child);

HWND FASTCALL
W32kGetDesktopWindow (VOID);

HWND FASTCALL
W32kGetFocusWindow (VOID);

HWND FASTCALL
W32kSetFocusWindow (HWND hWnd);

BOOL FASTCALL
W32kSetProp(PWINDOW_OBJECT Wnd, ATOM Atom, HANDLE Data);

PPROPERTY FASTCALL
W32kGetProp(PWINDOW_OBJECT WindowObject, ATOM Atom);

DWORD FASTCALL
W32kGetWindowThreadProcessId(PWINDOW_OBJECT Wnd, PDWORD pid);

ULONG
UserHasDlgFrameStyle(ULONG Style, ULONG ExStyle);

ULONG
UserHasThickFrameStyle(ULONG Style, ULONG ExStyle);

PWINDOW_OBJECT FASTCALL
W32kGetAncestor(PWINDOW_OBJECT Wnd, UINT Type);

PWINDOW_OBJECT FASTCALL
W32kGetParent(PWINDOW_OBJECT Wnd);

typedef enum _WINLOCK_TYPE
{
  None,
  Any,
  Shared,
  Exclusive
} WINLOCK_TYPE; 

#define ASSERT_WINLOCK(a) assert(W32kVerifyWinLock(a))

inline VOID W32kAcquireWinLockShared();
inline VOID W32kAcquireWinLockExclusive();
inline VOID W32kReleaseWinLock();
BOOL FASTCALL W32kVerifyWinLock(WINLOCK_TYPE Type);
WINLOCK_TYPE FASTCALL W32kSuspendWinLock();
VOID FASTCALL W32kRestoreWinLock(WINLOCK_TYPE Type);
inline BOOL W32kInitializeWinLock();
inline VOID W32kDeleteWinLock();

#endif /* __WIN32K_WINDOW_H */

/* EOF */
