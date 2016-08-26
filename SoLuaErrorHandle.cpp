//-----------------------------------------------------------------------------
//去除编译warning
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //_CRT_SECURE_NO_WARNINGS
//-----------------------------------------------------------------------------
#include "SoLuaErrorHandle.h"
#include <stdio.h>
#include <Windows.h>
//-----------------------------------------------------------------------------
char SoLuaErrorHandle::ms_szPrintBuff[SoLuaErrorHandle_BuffSize];
//-----------------------------------------------------------------------------
void SoLuaErrorHandle::Print(const char* szFormat, ...)
{
	va_list klist;
	va_start(klist, szFormat);
	vsnprintf(ms_szPrintBuff, SoLuaErrorHandle_BuffSize, szFormat, klist);
	va_end(klist);
	//
	OutputDebugStringA(ms_szPrintBuff);
	OutputDebugStringA("\n");
}
//-----------------------------------------------------------------------------
