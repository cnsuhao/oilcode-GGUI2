//----------------------------------------------------------------
#include "GGUIComponentText.h"
//----------------------------------------------------------------
GGUIComponentText::GGUIComponentText()
:m_fMaxWidth(0.0f)
,m_fMaxHeight(0.0f)
{
	//��ʼʱû��Ϊ m_kTextChunkArray �����ڴ棬���Ҫ�������� ResizeTextChunkArray() ��
	m_kTextChunkArray.InitArray(sizeof(GGUITextChunk), 0, GGUI_ComponentText_TextChunkAddCount);
}
//----------------------------------------------------------------
GGUIComponentText::~GGUIComponentText()
{
	ClearComponentText();
}
//----------------------------------------------------------------
void GGUIComponentText::ClearComponentText()
{
	m_kTextChunkArray.ClearArray();
}
//----------------------------------------------------------------
void GGUIComponentText::ResizeTextChunkArray(int nCount)
{
	m_kTextChunkArray.ResizeArray(nCount);
}
//----------------------------------------------------------------
void GGUIComponentText::AddTextChunk(const GGUITextChunk* pChunk)
{
	m_kTextChunkArray.PushBack(pChunk);
}
//----------------------------------------------------------------
void GGUIComponentText::ClearTextChunk()
{
	m_kTextChunkArray.ClearArray();
}
//----------------------------------------------------------------
int GGUIComponentText::GetTextChunkCount() const
{
	return m_kTextChunkArray.GetSize();
}
//----------------------------------------------------------------
const GGUITextChunk* GGUIComponentText::GetTextChunk(int nIndex) const
{
	return (GGUITextChunk*)(m_kTextChunkArray.GetAt(nIndex));
}
//----------------------------------------------------------------
