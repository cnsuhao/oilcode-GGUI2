//----------------------------------------------------------------
#ifndef _GGUIUserDefine_h_
#define _GGUIUserDefine_h_
//----------------------------------------------------------------
//��Ⱦ����˳�����ɾ���Զ�������ġ���������ZֵԽ�󣬾���ԽԶ��Խ���ױ�������Ĵ��ڸ��ǡ�
//������Ĺ۲췶Χ��[0,10000]���� SoD3DCameraUI::InitD3DCameraUI() ��Ҫ�뱻��������������Ļ���
//���ڶ�������Zֵ��ȡֵ��Χ�����[1,9999]��
//����������ϵ�£�������������Z�Ḻ�������Դ��ڶ�������Zֵ��ȡֵ��Χ�����[-1,-9999]��
#define GGUI_RenderOrder_Max -9999.0f
//ÿ����һ�����ڣ�RenderOrder�ͼ��� GGUI_RenderOrder_Step ����ʹ����һ�����ڻ����������ϲ㣬�´��ڸ��Ǿɴ��ڡ�
//ע�⣬GGUI_RenderOrder_Step��ֵ����̫С����Ϊfloat�������;��ȱȽϵͣ��ᵼ�����ڵ���Ƭ������ȷ����
#define GGUI_RenderOrder_Step 0.1f
//----------------------------------------------------------------
#define GGUI_ButtonStateHover_ColorR 1.0f
#define GGUI_ButtonStateHover_ColorG 0.0f
#define GGUI_ButtonStateHover_ColorB 0.0f
#define GGUI_ButtonStateHover_ColorA 0.5f
#define GGUI_ButtonStateHover_DeltaX -1.0f
#define GGUI_ButtonStateHover_DeltaY -1.0f
#define GGUI_ButtonStatePush_ColorR 1.0f
#define GGUI_ButtonStatePush_ColorG 0.0f
#define GGUI_ButtonStatePush_ColorB 0.0f
#define GGUI_ButtonStatePush_ColorA 0.5f
#define GGUI_ButtonStatePush_DeltaX 2.0f
#define GGUI_ButtonStatePush_DeltaY 2.0f
//----------------------------------------------------------------
#define GGUI_ComponentText_TextChunkAddCount 4
#define GGUI_ComponentText_NewChunkCountPrePause 2
//----------------------------------------------------------------
#endif //_GGUIUserDefine_h_
//----------------------------------------------------------------
