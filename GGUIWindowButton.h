//------------------------------------------------------------
#ifndef _GGUIWindowButton_h_
#define _GGUIWindowButton_h_
//------------------------------------------------------------
#include "GGUIWindowBase.h"
//------------------------------------------------------------
class GGUIWindowButton : public GGUIWindowBase
{
public:
	enum eButtonState
	{
		ButtonState_Normal,
		ButtonState_Hover,
		ButtonState_Push,
		ButtonState_Disable,
	};

public:
	//--szTexture "ImagesetName:RectName"
	void SetTexture(const char* szTexture);
	int GetImagesetIndex() const;
	int GetImageRectIndex() const;

	void SetButtonState(eButtonState eState);
	eButtonState GetButtonState() const;

protected:
	friend class GGUIWindowFactory;
	GGUIWindowButton();
	~GGUIWindowButton();
	//re-write parent function
	void ClearWindow();
	
private:
	int m_nImagesetIndex;
	int m_nImageRectIndex;
	eButtonState m_eButtonState;
};
//----------------------------------------------------------------
inline int GGUIWindowButton::GetImagesetIndex() const
{
	return m_nImagesetIndex;
}
//----------------------------------------------------------------
inline int GGUIWindowButton::GetImageRectIndex() const
{
	return m_nImageRectIndex;
}
//----------------------------------------------------------------
inline void GGUIWindowButton::SetButtonState(GGUIWindowButton::eButtonState eState)
{
	m_eButtonState = eState;
}
//------------------------------------------------------------
inline GGUIWindowButton::eButtonState GGUIWindowButton::GetButtonState() const
{
	return m_eButtonState;
}
//------------------------------------------------------------
#endif //_GGUIWindowButton_h_
//------------------------------------------------------------
