#ifndef __OLORIN_FRAMEWORK_DLL__
#define __OLORIN_FRAMEWORK_DLL__

#if __OLORIN_FRAMEWORK_EXPORT__
#define FRAMEWORK_DLL __declspec (dllexport)
#else
#define FRAMEWORK_DLL __declspec (dllimport)
#endif

#endif