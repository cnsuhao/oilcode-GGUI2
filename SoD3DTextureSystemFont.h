//----------------------------------------------------------------
#ifndef _SoD3DTextureSystemFont_h_
#define _SoD3DTextureSystemFont_h_
//----------------------------------------------------------------
#include "SoD3DInclude.h"
//----------------------------------------------------------------
class SoD3DTexture;
class SoSystemFont;
class GGUIImageset;
struct stSystemFontParam;
struct stSystemFontCharGlyphBitData;
//----------------------------------------------------------------
class SoD3DTextureSystemFont
{
public:
	static bool CreateD3DTextureSystemFont();
	static void ReleaseD3DTextureSystemFont();
	static SoD3DTextureSystemFont* Get();

	SoD3DTextureSystemFont();
	~SoD3DTextureSystemFont();

	bool InitD3DTextureSystemFont(const stSystemFontParam* pParam, const int nMaxGlyphCount);
	void ClearD3DTextureSystemFont();
	void PreRenderD3DTextureSystemFont();

	//�������Σ�����ӵ�Imageset�С�
	//--szString ����ַ���û����0��β����nLen����Ϊ��Чֵ��
	//--nLen �ַ�����������Ϊ0����-1����Чֵ����Ϊ��Чֵʱ��szString����Ϊ��0��β���ַ�����
	void DrawString(const wchar_t* szString, int nLen);

private:
	bool DoCreateTexture();
	void DoReleaseTexture();
	bool DoCreateImageset();
	void DoReleaseImageset();
	void GenerateImagesetName();
	void GenerateTextureResolution(const int nFontSize, const int nDestGlyphCount);
	void CopyGlyphData(const stSystemFontCharGlyphBitData* pGlyphData, GGUIImageset* pImageset, const SoTinyString& kRectName);

private:
	static SoD3DTextureSystemFont* ms_pInstance;
	SoD3DTexture* m_pTexture;
	SoSystemFont* m_pSystemFont;
	char* m_pBitData;
	int m_nSizeOfBitData;
	int m_nTextureWidth;
	int m_nTextureHeight;
	int m_nGlyphCountInWidth;
	int m_nGlyphCountInHeight;
	//������ͼ�ᱻ��װ��Imageset�������ֱ��������
	SoTinyString m_kImagesetName;
	int m_nImagesetIndex;
	bool m_bPixelDataChanged;
};
//----------------------------------------------------------------
inline SoD3DTextureSystemFont* SoD3DTextureSystemFont::Get()
{
	return ms_pInstance;
}
//----------------------------------------------------------------
#endif //_SoD3DTextureSystemFont_h_
//----------------------------------------------------------------
