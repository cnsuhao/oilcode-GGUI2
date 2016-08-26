//---------------------------------------------------------------
#ifndef _SoGameTime_h_
#define _SoGameTime_h_
//---------------------------------------------------------------
class SoGameTime
{
public:
	static void CreateGameTime();
	static void ReleaseGameTime();
	static SoGameTime* Get();

	float FrameBegin();
	void FrameEnd();

	//������Ϸ֡�����ޡ�
	void SetMaxFPS(int nMaxFPS);
	//��ȡ��ǰ����Ϸ֡�ʡ�
	int GetCurrentFPS();

private:
	SoGameTime();
	~SoGameTime();
	void InitGameTime();
	void ClearGameTime();

private:
	static SoGameTime* ms_pInstance;
	//��Ϸ����ʱ��ʱ�̡�
	__int64 m_GameStartTime;
	//��Ϸ����ʱ����
	__int64 m_GameAccTime;
	//��һ֡������ʱ�̡�Ҳ����֡��ʼ��ʱ�̡�
	__int64 m_LastFrameEndTime;
	//��֡������ʱ�̡�
	__int64 m_CurrentFrameEndTime;
	//��ʱ����Ƶ�ʣ�Ҳ��һ�����߶��ٸ�����
	//��ֵֻ���ȡһ�Σ������ᷢ���仯��
	__int64 m_TimerFrequence;
	//��¼�������ڣ��Ѿ����˶��ٸ�����
	__int64 m_CurrentAccFrequence;
	//��֡�ʴﵽ���޵�����£�ÿ֡�߶��ٸ�����
	__int64 m_FrameIntervalAtMaxFPS;

	//��Ϸ֡������
	int m_nMaxFPS;
	//��ǰ����Ϸ֡��
	int m_nCurrentFPS;
	//��¼�������ڣ��Ѿ����˶���֡��
	int m_nAccFrame;

	float m_fFrameDeltaTime;
};
//---------------------------------------------------------------
inline SoGameTime* SoGameTime::Get()
{
	return ms_pInstance;
}
//---------------------------------------------------------------
#endif
//---------------------------------------------------------------
