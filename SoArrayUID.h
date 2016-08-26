//----------------------------------------------------------------
#ifndef _SoArrayUID_h_
#define _SoArrayUID_h_
//----------------------------------------------------------------
class SoArrayUID
{
public:
	enum eStatusType
	{
		Status_Invalid = -1,
		Status_Empty, //Ԫ��ֵΪ��
		Status_Using, //Ԫ��ֵ����Чֵ�����ڱ����ʹ��
	};

public:
	SoArrayUID();
	~SoArrayUID();
	//��ʼ��������Ҳ������Ϊ�������ú�������һ�����������ó������顣
	//--nElementSize Ԫ�ش�С������Ԫ��ִ��sizeof����õ��ķ���ֵ��
	//--nInitCapacity ��ʼʱ�����Ԫ�ظ�����Ҳ��Ԥ������ڴ��ܹ����ɶ��ٸ�Ԫ�ء�
	//--nAddCount ������Ԫ��������Ԥ��������ڴ�ʱ�������ӵ��ڴ��ܹ����ɶ��ٸ�Ԫ�ء�
	bool InitArray(int nElementSize, int nInitCapacity, int nAddCount);
	//���������ڴ棬�洢�����Ԫ�ء�
	//���newCapacity�ȵ�ǰ��m_nCapacityС����ʲô��������
	bool ResizeArray(int newCapacity);
	//������е�Ԫ�ء��ڴ治�ᱻ�ͷŵ���
	void ClearArray();
	//����Ԫ����䵽nUIDλ�ã����ԭnUIDλ�õ�Ԫ�ظ��ǵ���
	//����ֵΪ��Ԫ�ص�UID��
	//nUID��ֵΪ-1����ʾ�Զ���һ��Status_Emptyλ�ý�����䡣
	int FillAt(int nUID, const void* pElement);
	//����һ����Ԫ�أ�������������Ԫ�ص�ֵ��
	//�����ҵ�״̬ΪStatus_Empty��Ԫ�أ�Ȼ���ٷ��ء�
	//����ֵΪ��Ԫ�ص�λ��������
	int TakeNew(void** ppElement);
	//���nUIDλ�õ�Ԫ�أ�����״̬���ó�Status_Empty��
	void ClearAt(int nUID);
	//��ȡ������������
	int GetCapacity() const;
	//��ȡnUIDλ�õ�Ԫ�أ����Ҹ�Ԫ�ص�״̬������Status_Using�����򷵻�NULL��
	void* GetAt(int nUID) const;
	//״̬������
	int GetStatus(int nUID) const;
	//��ȡ��ЧԪ�صĸ�����
	int GetUsingElementCount() const;

private:
	//�ҵ���һ����Ԫ�ء�
	int FindFirstEmptyElement();

private:
	//�洢Ԫ�ض��󡣸�������±���ž���UID��
	//�б���Ԫ�صķֲ���������ģ����磬0��Ԫ��Ϊ��Чֵ��1��Ԫ��Ϊ��Чֵ��2��Ԫ��Ϊ��Чֵ���ȵȡ�
	char* m_pElementBuff;
	//�洢Ԫ��״̬����ֵΪeStatusTypeö��ֵ��
	char* m_pStatusBuff;
	int m_nCapacity;
	int m_nUsingElementCount;
	int m_nElementSize;
	int m_nAddCount;
};
//----------------------------------------------------------------
inline int SoArrayUID::GetCapacity() const
{
	return m_nCapacity;
}
//----------------------------------------------------------------
inline int SoArrayUID::GetUsingElementCount() const
{
	return m_nUsingElementCount;
}
//----------------------------------------------------------------
#endif //_SoArrayUID_h_
//----------------------------------------------------------------
