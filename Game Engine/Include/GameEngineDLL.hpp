#ifndef __OLORIN_GAMEENGINE_DLL__
#define __OLORIN_GAMEENGINE_DLL__

#if __OLORIN_GAMEENGINE_EXPORT__
#define GAMEENGINE_DLL __declspec (dllexport)
#else
#define GAMEENGINE_DLL __declspec (dllimport)
#endif

#endif