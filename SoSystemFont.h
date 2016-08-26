//----------------------------------------------------------------
#ifndef _SoSystemFont_h_
#define _SoSystemFont_h_
//----------------------------------------------------------------
#include <Windows.h>
#include "SoTinyString.h"
//----------------------------------------------------------------
#define SoSystemFont_MaxFontSize 64
//��ɫλ�32λ���ɫ
#define SoSystemFont_BitCount 32
//ÿ������ռ�ü����ֽ�
#define SoSystemFont_BytePerPixel 4
//��ascii�ַ����У��ӵ�32�����Ųſ�ʼ����Ч������
#define SoSystemFont_ASCII_MinValidCharGlyph 32
//----------------------------------------------------------------
struct stSystemFontParam
{
	SoTinyString kFontName;
	int nFontSize; //�ֺ�
	int nFontWeight; //�����ϸ��The weight of the font in the range 0 through 1000. For example, 400 is normal and 700 is bold.
	bool bItalic; //�Ƿ�б��
	bool bUnderline; //�Ƿ���»���
	bool bStrikeOut; //�Ƿ��ɾ����

	stSystemFontParam()
	{
		Clear();
	}
	void Clear()
	{
		kFontName.Clear();
		nFontSize = SoSystemFont_MaxFontSize;
		nFontWeight = FW_NORMAL;
		bItalic = false;
		bUnderline = false;
		bStrikeOut = false;
	}
};
//----------------------------------------------------------------
struct stSystemFontCharGlyphBitData
{
	wchar_t Char;
	int nGlyphWidth;
	int nGlyphHeight;
	//���ݴ洢��ʽ�Ǵ����ң����ϵ��¡�
	char* pGlyphBitData;

	stSystemFontCharGlyphBitData()
	{
		Clear();
	}
	void Clear()
	{
		Char = 0;
		nGlyphWidth = 0;
		nGlyphHeight = 0;
		pGlyphBitData = 0;
	}
};
//----------------------------------------------------------------
class SoSystemFont
{
public:
	SoSystemFont();
	~SoSystemFont();

	bool InitSystemFont(const stSystemFontParam* pParam);
	void ClearSystemFont();

	const stSystemFontCharGlyphBitData* GetCharGlyphBitData(wchar_t Char);
	const void* GetBitData();
	const stSystemFontParam& GetFontParam() const;

private:
	bool InitDevice();
	void ClearDevice();

private:
	//
	HDC m_hDrawDC;
	HFONT m_hDrawFont;
	HFONT m_hOldFont;
	HBITMAP m_hDrawBitmap;
	HBITMAP m_hOldBitmap;
	//m_pBitDataָ��һ���洢Bitmap���ݵ��ڴ�飬���ڴ����GDIϵͳ����ͻ����ͷš�
	//��Bitmap���ݵĿ�߶���SoSystemFont_MaxFontSize���ء�
	//ÿ�λ����µ�����ʱ�����ڴ��ᱻGDIϵͳ���㣬Ȼ��������µ����ε����ݡ�
	//Bitmap�����ݴ洢��ʽ�Ǵ����ң����µ��ϣ�
	//�����������⴦���Ѿ���m_pBitData�����ݴ洢��ʽ��ɴ����ң����ϵ��¡�
	char* m_pBitData;
	RECT m_kDrawRect;
	//�����������
	stSystemFontParam m_kFontParam;
	//�洢���һ�ζ�ȡ����������
	stSystemFontCharGlyphBitData m_kCurrentCharGlyph;
};
//----------------------------------------------------------------
#endif //_SoSystemFont_h_
//----------------------------------------------------------------
