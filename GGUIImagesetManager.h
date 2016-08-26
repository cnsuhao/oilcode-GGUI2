//----------------------------------------------------------------
#ifndef _GGUIImagesetManager_h_
#define _GGUIImagesetManager_h_
//----------------------------------------------------------------
#include "GGUIDefine.h"
//----------------------------------------------------------------
class SoD3DTexture;
class GGUIImageset;
//----------------------------------------------------------------
struct stImagesetParam
{
	//Imageset�����֡�
	SoTinyString kName;
	//Ԥ������ٸ�GGUIRect��
	int nInitRectCount;
	//��ͼ����
	SoD3DTexture* pD3DTexture;
};
//----------------------------------------------------------------
class GGUIImagesetManager
{
public:
	static bool CreateUIImagesetManager();
	static void ReleaseUIImagesetManager();
	static GGUIImagesetManager* Get();

	//����һ���µ�Imageset����
	//����ֵΪImagesetID��
	int CreateImageset(const stImagesetParam& kParam);
	int GetImagesetIndex(const SoTinyString& kName);
	GGUIImageset* GetImagesetByID(int nImagesetID);
	GGUIImageset* GetImagesetByName(const SoTinyString& kName);

private:
	GGUIImagesetManager();
	~GGUIImagesetManager();
	bool InitUIImagesetManager();
	void ClearUIImagesetManager();

private:
	typedef std::map<SoTinyString, int> mapName2Index;

private:
	static GGUIImagesetManager* ms_pInstance;
	//���飬�洢��Ԫ����GGUIImageset*��
	SoArrayUID m_kImagesetArray;
	//Imageset���ֵ�Imageset��ŵ�ӳ�䡣
	mapName2Index m_kName2IndexMap;
};
//----------------------------------------------------------------
inline GGUIImagesetManager* GGUIImagesetManager::Get()
{
	return ms_pInstance;
}
//----------------------------------------------------------------
#endif //_GGUIImagesetManager_h_
//----------------------------------------------------------------
