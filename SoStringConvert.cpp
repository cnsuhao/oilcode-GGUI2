//--------------------------------------------------------------------
#include <Windows.h>
#include <strsafe.h>
#include "SoStringConvert.h"
//--------------------------------------------------------------------
//�ַ����������洢�ַ���ת����Ľ����
//ע�⣬�������Ĵ�С�ǹ̶��ģ������ú���ʱҪС�ģ�ת������ַ���������̫�ࡣ
const int MaxBufferSize = 2048;
char theCharBuffer[MaxBufferSize];
//--------------------------------------------------------------------
int SoUnicodeCountFromAnsi(const char* pString)
{
	return ::MultiByteToWideChar(CP_ACP, 0, pString, -1, NULL, 0);
}
//--------------------------------------------------------------------
int SoAnsiCountFromUnicode(const wchar_t* pString)
{
	return ::WideCharToMultiByte(CP_ACP, 0, pString, -1, NULL, 0, NULL, NULL);
}
//--------------------------------------------------------------------
int SoUnicodeCountFromUtf8(const char* pString)
{
	return ::MultiByteToWideChar(CP_UTF8, 0, pString, -1, NULL, 0);
}
//--------------------------------------------------------------------
int SoUtf8CountFromUnicode(const wchar_t* pString)
{
	return ::WideCharToMultiByte(CP_UTF8, 0, pString, -1, NULL, 0, NULL, NULL);
}
//--------------------------------------------------------------------
wchar_t* SoAnsiToUnicode(const char* pSrcString) 
{
	wchar_t* pResult = (wchar_t*)theCharBuffer;
	pResult[0] = 0;
	//
	if (pSrcString == NULL)
	{
		return pResult;
	}
	int nWCharCount = SoUnicodeCountFromAnsi(pSrcString);
	if (nWCharCount == 0)
	{
		//���ִ���
		return pResult;
	}
	if (nWCharCount*2 >= MaxBufferSize)
	{
		//�ַ�����̫�࣬������������С��
		return pResult;
	}
	::MultiByteToWideChar(CP_ACP, 0, pSrcString, -1, pResult, nWCharCount);
	return pResult;
}
//--------------------------------------------------------------------
char* SoUnicodeToAnsi(const wchar_t* pSrcString)
{
	char* pResult = theCharBuffer;
	pResult[0] = 0;
	//
	if (pSrcString == NULL)
	{
		return pResult;
	}
	int nByteCount = SoAnsiCountFromUnicode(pSrcString);
	if (nByteCount == 0)
	{
		//���ִ���
		return pResult;
	}
	if (nByteCount >= MaxBufferSize)
	{
		//�ַ�����̫�࣬������������С��
		return pResult;
	}
	::WideCharToMultiByte(CP_ACP, 0, pSrcString, -1, pResult, nByteCount, NULL, NULL);
	return pResult;
}
//--------------------------------------------------------------------
wchar_t* SoUtf8ToUnicode(const char* pSrcString)
{
	wchar_t* pResult = (wchar_t*)theCharBuffer;
	pResult[0] = 0;
	//
	if (pSrcString == NULL)
	{
		return pResult;
	}
	int nWCharCount = SoUnicodeCountFromUtf8(pSrcString);
	if (nWCharCount == 0)
	{
		//���ִ���
		return pResult;
	}
	if (nWCharCount*2 >= MaxBufferSize)
	{
		//�ַ�����̫�࣬������������С��
		return pResult;
	}
	::MultiByteToWideChar(CP_UTF8, 0, pSrcString, -1, pResult, nWCharCount);
	return pResult;
}
//--------------------------------------------------------------------
char* SoUnicodeToUtf8(const wchar_t* pSrcString)
{
	char* pResult = theCharBuffer;
	pResult[0] = 0;
	//
	if (pSrcString == NULL)
	{
		return pResult;
	}
	int nByteCount = SoUtf8CountFromUnicode(pSrcString);
	if (nByteCount == 0)
	{
		//���ִ���
		return pResult;
	}
	if (nByteCount >= MaxBufferSize)
	{
		//�ַ�����̫�࣬������������С��
		return pResult;
	}
	::WideCharToMultiByte(CP_UTF8, 0, pSrcString, -1, pResult, nByteCount, NULL, NULL);
	return pResult;
}
//--------------------------------------------------------------------
char* SoAnsiToUtf8(const char* pSrcString)
{
	//���Ȱ�Ansi�ַ���ת����Unicode��ʽ��
	wchar_t* pUnicodeString = SoAnsiToUnicode(pSrcString);
	if (pUnicodeString[0] == 0)
	{
		return theCharBuffer;
	}
	//
	wchar_t tempBuffer[MaxBufferSize];
	StringCbCopyW(tempBuffer, sizeof(tempBuffer), pUnicodeString);
	//�ٰ�Unicode�ַ���ת����Utf8��ʽ��
	return SoUnicodeToUtf8(tempBuffer);
}
//--------------------------------------------------------------------
char* SoUtf8ToAnsi(const char* pSrcString)
{
	//���Ȱ�Utf8�ַ���ת����Unicode��ʽ��
	wchar_t* pUnicodeString = SoUtf8ToUnicode(pSrcString);
	if (pUnicodeString[0] == 0)
	{
		return theCharBuffer;
	}
	//
	wchar_t tempBuffer[MaxBufferSize];
	StringCbCopyW(tempBuffer, sizeof(tempBuffer), pUnicodeString);
	//�ٰ�Unicode�ַ���ת����Ansi��ʽ��
	return SoUnicodeToAnsi(tempBuffer);
}
//--------------------------------------------------------------------
