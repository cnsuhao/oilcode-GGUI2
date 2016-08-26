//----------------------------------------------------------------
#include "SoD3DShaderManager.h"
//----------------------------------------------------------------
SoD3DShaderManager* SoD3DShaderManager::ms_pInstance = 0;
//----------------------------------------------------------------
bool SoD3DShaderManager::CreateD3DShaderManager()
{
	bool br = true;
	if (ms_pInstance == 0)
	{
		ms_pInstance = new SoD3DShaderManager;
		if (ms_pInstance && ms_pInstance->InitD3DShaderManager())
		{
			br = true;
		}
		else
		{
			ReleaseD3DShaderManager();
			br = false;
		}
	}
	return br;
}
//----------------------------------------------------------------
void SoD3DShaderManager::ReleaseD3DShaderManager()
{
	if (ms_pInstance)
	{
		delete ms_pInstance;
		ms_pInstance = 0;
	}
}
//----------------------------------------------------------------
SoD3DShaderManager::SoD3DShaderManager()
{
	for (int i = 0; i < SoD3DShaderType_Max; ++i)
	{
		m_pShaderList[i] = 0;
	}
}
//----------------------------------------------------------------
SoD3DShaderManager::~SoD3DShaderManager()
{
	ClearD3DShaderManager();
}
//----------------------------------------------------------------
bool SoD3DShaderManager::InitD3DShaderManager()
{
	SoD3DShaderGGUI* pShaderGGUI = new SoD3DShaderGGUI;
	if (pShaderGGUI && pShaderGGUI->InitD3DShaderGGUI())
	{
		pShaderGGUI->SetType(SoD3DShaderType_GGUI);
		m_pShaderList[SoD3DShaderType_GGUI] = pShaderGGUI;
	}
	else
	{
		return false;
	}
	//
	return true;
}
//----------------------------------------------------------------
void SoD3DShaderManager::ClearD3DShaderManager()
{
	for (int i = 0; i < SoD3DShaderType_Max; ++i)
	{
		if (m_pShaderList[i])
		{
			delete m_pShaderList[i];
			m_pShaderList[i] = 0;
		}
	}
}
//----------------------------------------------------------------
SoD3DShaderBase* SoD3DShaderManager::GetShader(int theType)
{
	if (theType >= 0 && theType < SoD3DShaderType_Max)
	{
		return m_pShaderList[theType];
	}
	else
	{
		return 0;
	}
}
//----------------------------------------------------------------
