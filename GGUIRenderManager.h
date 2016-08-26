//----------------------------------------------------------------
#ifndef _GGUIRenderManager_h_
#define _GGUIRenderManager_h_
//----------------------------------------------------------------
#include "SoD3DInclude.h"
//----------------------------------------------------------------
class SoD3DShaderBase;
//----------------------------------------------------------------
struct stUIRenderUnit
{
	float fRectLeft;
	float fRectTop;
	float fRectWidth;
	float fRectHeight;
	float fTexCoordLeft;
	float fTexCoordTop;
	float fTexCoordWidth;
	float fTexCoordHeight;
	void* pTexture; //��ֵΪID3D11ShaderResourceView*���͡�
	float fColorR;
	float fColorG;
	float fColorB;
	float fColorA;
};
//----------------------------------------------------------------
class GGUIRenderManager
{
public:
	static bool CreateUIRenderManager();
	static void ReleaseUIRenderManager();
	static GGUIRenderManager* Get();

	void AddRnederUnit(const stUIRenderUnit* pUIRenderUnit);
	void RenderUIRenderManager();

private:
	GGUIRenderManager();
	~GGUIRenderManager();
	bool InitUIRenderManager();
	void ClearUIRenderManager();
	//
	bool CreateVertexList();
	void ReleaseVertexList();
	bool CreateVertexBuffer();
	void ReleaseVertexBuffer();
	bool CreateIndexBuffer();
	void ReleaseIndexBuffer();
	bool CreateSRVList();
	void ReleaseSRVList();

private:
	struct stVertexType
	{
		XMFLOAT3 kPosition;
		XMFLOAT3 kTexCoordAndTexIndex;
		XMFLOAT4 kColorRGBA;
	};

private:
	static GGUIRenderManager* ms_pInstance;
	stVertexType* m_pVertexList;
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;
	ID3D11ShaderResourceView** m_pSRVList;
	SoD3DShaderBase* m_pShader;
	//��¼ m_pVertexList �е�Ԫ�ظ���
	int m_nMaxWindowCount;
	int m_nCurWindowCount;
	//��¼ m_pSRVList �е�Ԫ�ظ���
	int m_nMaxSRVCount;
	int m_nCurSRVCount;
	//���һ��ִ��AddRnederUnitʱ����ͼ����Ƕ��١�
	//����ִ��AddRnederUnitʱ����ͼ��ż��п������ϴε���ͼ�����ͬ��
	//��������Ŀ������������ʣ����ٱ�����
	int m_nLastTextureIndex;
	//���Ƶ�ǰ�� stUIRenderUnit ʱ��ʹ�õ�ZValue��ֵ�Ƕ��١�
	float m_fCurrentRenderOrder;
};
//----------------------------------------------------------------
inline GGUIRenderManager* GGUIRenderManager::Get()
{
	return ms_pInstance;
}
//----------------------------------------------------------------
#endif //_GGUIRenderManager_h_
//----------------------------------------------------------------
