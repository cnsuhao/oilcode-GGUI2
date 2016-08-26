//----------------------------------------------------------------
#include "SoD3DLogicFlowHelp.h"
#include "SoD3DSystem.h"
#include "SoD3DTextureManager.h"
#include "SoD3DShaderManager.h"
#include "SoD3DCameraUI.h"
//----------------------------------------------------------------
bool SoD3DLogicFlowHelp_Create()
{
	///////////////////////////////////////
	if (SoD3DSystem::CreateD3DSystem() == false)
	{
		return false;
	}
	///////////////////////////////////////
	if (SoD3DTextureManager::CreateD3DTextureManager() == false)
	{
		return false;
	}
	///////////////////////////////////////
	if (SoD3DShaderManager::CreateD3DShaderManager() == false)
	{
		return false;
	}
	///////////////////////////////////////
	if (SoD3DCameraUI::CreateD3DCameraUI() == false)
	{
		return false;
	}
	///////////////////////////////////////
	return true;
}
//----------------------------------------------------------------
void SoD3DLogicFlowHelp_Release()
{
	///////////////////////////////////////
	SoD3DCameraUI::ReleaseD3DCameraUI();
	SoD3DShaderManager::ReleaseD3DShaderManager();
	SoD3DTextureManager::ReleaseD3DTextureManager();
	SoD3DSystem::ReleaseD3DSystem();
	///////////////////////////////////////
}
//----------------------------------------------------------------
void SoD3DLogicFlowHelp_Update(float fDeltaTime)
{

}
//----------------------------------------------------------------
void SoD3DLogicFlowHelp_PreRender()
{

}
//----------------------------------------------------------------
bool SoD3DLogicFlowHelp_BeginRender()
{
	if (SoD3DSystem::Get() == NULL)
	{
		return false;
	}

	SoD3DSystem::Get()->BeginRender();

	return true;
}
//----------------------------------------------------------------
void SoD3DLogicFlowHelp_EndRender()
{
	SoD3DSystem::Get()->EndRender();
}
//----------------------------------------------------------------
