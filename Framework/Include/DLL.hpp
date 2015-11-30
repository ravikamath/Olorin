#ifndef __OLORIN_DLL__
#define __OLORIN_DLL__

#if _WINDLL
#define DLLAPI __declspec (dllexport)
#else
#define DLLAPI __declspec (dllimport)
#endif

#endif