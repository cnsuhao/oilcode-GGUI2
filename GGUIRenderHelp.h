//----------------------------------------------------------------
#ifndef _GGUIRenderHelp_h_
#define _GGUIRenderHelp_h_
//----------------------------------------------------------------
class GGUIWindowContainer;
class GGUIWindowText;
class GGUIWindowImage;
class GGUIWindowButton;
class GGUIComponentText;
//----------------------------------------------------------------
void GGUIRenderProcess();
void GGUIRender_UIContainer(const GGUIWindowContainer* pUIContainer);
void GGUIRender_UIText(const GGUIWindowText* pUIText);
void GGUIRender_UIImage(const GGUIWindowImage* pUIImage);
void GGUIRender_UIButton(const GGUIWindowButton* pUIButton);
void GGUIRender_ComponetText(const GGUIComponentText* pCompText);
//----------------------------------------------------------------
#endif //_GGUIRenderHelp_h_
//----------------------------------------------------------------
