//--------------------------------------------------------------------
//致力于跨平台，跨编译器
#ifndef _SoStringHelp_h_
#define _SoStringHelp_h_
//--------------------------------------------------------------------
#include <cstdlib>
//--------------------------------------------------------------------
#define SoStringHelp_GlobalBuffSize 2048
//--------------------------------------------------------------------
//计算字符串长度。
//字符串长度不能大于0x3FFFFFFF（1G多）。
//这里设置最大值的目的是，防止用户传入了一个没有以0结尾的字符串而陷入死循环。
int SoStrLen(const char* szString);
int SoWStrLen(const wchar_t* szString);

//字符串拷贝。
//返回字符串长度。
int SoStrCpy(char* DestBuff, const int nDestBuffSize, const char* szSourceString);
int SoWStrCpy(wchar_t* DestBuff, const int nDestBuffSize, const wchar_t* szSourceString);

//字符串格式化，使用本模块提供的字符串缓存。
//返回值不是const char*，是可以修改的字符串缓存，用意是外界可以对字符串做一些修改。
char* SoStrFmt(const char* szFormat, ...);
//字符串格式化，使用指定的字符串缓存
void SoStrFmtSelf(char* Buff, const int nBuffSize, const char* szFormat, ...);
char* SoStrFmtByVaList(const char* szFormat, const void* pValist);
void SoStrFmtSelfByVaList(char* Buff, const int nBuffSize, const char* szFormat, const void* pValist);

//比较两个字符串
int SoStrCmp(const char* s1, const char* s2);
int SoWStrCmp(const wchar_t* s1, const wchar_t* s2);
//比较两个字符串，不考虑大小写问题
int SoStrCmpNoCase(const char* s1, const char* s2);
int SoWStrCmpNoCase(const wchar_t* s1, const wchar_t* s2);

//查找字符c在字符串str中首次出现的位置序号。
//外界可以传入字符串str的长度；如果不传入的话，函数内部会计算字符串长度。
//如果找的到，返回值范围[0, SoStrLen(str))；
//如果找不到，返回值为-1；
int SoStrChr(const char* str, const char c, int nStrLen = -1);
int SoWStrChr(const wchar_t* str, const wchar_t c, int nStrLen = -1);
//查找字符c在字符串str中末次出现的位置序号。
//外界可以传入字符串str的长度；如果不传入的话，函数内部会计算字符串长度。
//如果找的到，返回值范围[0, SoStrLen(str))；
//如果找不到，返回值为-1；
int SoStrRChr(const char* str, const char c, int nStrLen = -1);
int SoWStrRChr(const wchar_t* str, const wchar_t c, int nStrLen = -1);

//从str中获取一个子字符串。
//子字符串包含的内容是，位置序号属于[nStartIndex, nEndIndex]内的字符。
char* SoSubStr(const char* str, int nStartIndex, int nEndIndex);

//字符串瘦身，把头部和尾部的空格和tab字符去掉。
char* SoStrSlim(const char* str, int nStrLen = -1);

//把字符串中的字符替换成大写字母
char* SoStrToUpper(const char* szString);
void SoStrToUpperSelf(char* szString);

//把字符串中的字符替换成小写字母
char* SoStrToLower(const char* szString);
void SoStrToLowerSelf(char* szString);

//路径字符串标准化
//把传入的字符串修改成如下格式：
//1，把'\\'修改成'/'；
//2，把大写字母修改成小写字母；
//返回值是一个全局的字符串数组，外界要尽快将返回值取走。
char* SoPathNormalize(const char* pszString);
void SoPathNormalizeSelf(char* szString);

//获取utf8字符串中的一个字符。
//--pByteCountOfTheCharacter 如果为有效值，则函数退出后携带了字符的字节个数。
char* SoGetOneCharacterFromUtf8String(const char* pszUtf8Str, const int nUtf8StrLen, const int nStartIndex, int* pByteCountOfTheCharacter);
//判断utf8字符串是否符合规范。
bool SoCheckUtf8WellFormed(const unsigned char *str, int len);

// Same to ::atof, but strip the string, remain 7 numbers after '.' before call atof.
// Why we need this? Because in android c++_static, atof ( and std::atof ) is unsupported for numbers
// have long decimal part and contain several numbers can approximate to 1 ( like 90.099998474121094 ), 
// it will return inf. This function is used to fix this bug.
double Soatof(const char* szString);
double SoWatof(const wchar_t* szString);
// Same to atoi
#define Soatoi atoi
#define SoWatoi _wtoi
#define Sostrtol strtol
#define SoWstrtol wcstol
#define Sostrtoul strtoul
#define SoWstrtoul wcstoul
//--------------------------------------------------------------------
#endif //_SoStringHelp_h_
//--------------------------------------------------------------------
