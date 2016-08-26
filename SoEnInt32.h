//----------------------------------------------------------------
#ifndef _SoEnInt32_h_
#define _SoEnInt32_h_
//����(encrypted)���int32
//----------------------------------------------------------------
#include "SoIntType.h"
//----------------------------------------------------------------
//�������������Ĺ̶�ֵ
#define XOR_Value32 (0xA59CF5B6)
//----------------------------------------------------------------
class soenint32
{
public:
	soenint32();
	soenint32(const soint32 nValue);
	//�������캯��
	soenint32(const soenint32& kEnValue);
	//���ظ�ֵ�����
	soenint32& operator=(const soenint32& kEnValue);

	void SetValue(const soint32 nValue);
	soint32 GetValue() const;

private:
	//����洢���Ǽ��ܺ��ֵ
	soint32 m_nEnValue;
};
//----------------------------------------------------------------
inline soenint32::soenint32()
:m_nEnValue(0)
{

}
//----------------------------------------------------------------
inline soenint32::soenint32(const soint32 nValue)
{
	SetValue(nValue);
}
//----------------------------------------------------------------
inline soenint32::soenint32(const soenint32& kEnValue)
{
	//SetValue(kEnValue.GetValue());
	m_nEnValue = kEnValue.m_nEnValue;
}
//----------------------------------------------------------------
inline soenint32& soenint32::operator=(const soenint32& kEnValue)
{
	//SetValue(kEnValue.GetValue());
	m_nEnValue = kEnValue.m_nEnValue;
	return *this;
}
//----------------------------------------------------------------
inline void soenint32::SetValue(const soint32 nValue)
{
	m_nEnValue = XOR_Value32 ^ nValue;
}
//----------------------------------------------------------------
inline soint32 soenint32::GetValue() const
{
	return (XOR_Value32 ^ m_nEnValue);
}
//----------------------------------------------------------------
#endif //_SoEnInt32_h_
//----------------------------------------------------------------
