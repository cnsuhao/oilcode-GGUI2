//------------------------------------------------------------
#ifndef _SoCoroutineHelp_h_
#define _SoCoroutineHelp_h_
//------------------------------------------------------------
#include "SoCoroutine.h"
//------------------------------------------------------------
enum SoCoroutineObjType
{
	SoCoroutineObjType_None, //SoCoroutine::m_pObjFunc��ֵΪSoCoroutineFuncPointer��
	SoCoroutineObjType_Test, //SoCoroutine::m_pObjFunc��ֵΪTestClass������ָ�롣
};
//------------------------------------------------------------
void SoCoroutineHelp_CallFunc(SoCoroutine* pCo);
//------------------------------------------------------------
#endif //_SoCoroutineHelp_h_
//------------------------------------------------------------
