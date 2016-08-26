//----------------------------------------------------------------
#ifndef _GGUIImageset_h_
#define _GGUIImageset_h_
//----------------------------------------------------------------
#include "GGUIDefine.h"
//----------------------------------------------------------------
class SoD3DTexture;
//----------------------------------------------------------------
class GGUIImageset
{
public:
	void AddRect(const SoTinyString& kName, const GGUIRect& kRect);
	int GetRectID(const SoTinyString& kName) const;
	const GGUIRect& GetRect(int nID) const;
	int GetRectCount() const;
	//����ֵΪID3D11ShaderResourceView*���͡�
	void* GetTexture() const;
	float GetTextureWidth() const;
	float GetTextureHeight() const;

protected:
	friend class GGUIImagesetManager;
	GGUIImageset();
	~GGUIImageset();
	//��ʼ��������
	//--nInitRectCount Ԥ������ٸ�GGUIRect��
	bool InitImageset(int nInitRectCount);
	void ClearImageset();
	void SetD3DTexture(SoD3DTexture* pD3DTexture);

private:
	typedef std::map<SoTinyString, int> mapName2ID;

private:
	//���飬�洢��Ԫ����GGUIRect��
	SoArrayUID m_kRectArray;
	//GGUIRect���ֵ�GGUIRect��ŵ�ӳ�䡣
	mapName2ID m_kName2IDMap;
	//��ͼ����ָ�롣
	SoD3DTexture* m_pD3DTexture;
};
//----------------------------------------------------------------
#endif //_GGUIImageset_h_
//----------------------------------------------------------------
