//------------------------------------------------------------
//��Config�ļ�û�й̶�����չ�����û������Լ���Ҫ������չ����
//��Config�ļ��ڲ�֧��ע����䣬ÿһ�е����ݶ������Ǽ�ֵ�ԡ�
//ÿһ�ж���һ���ַ���'='�ַ����Ⱥ������Key���Ⱥ��ұ���Value��
//Key��Value����Ϊ���ַ�����
//���һ������û��'='�ַ�������б������������ܽ�������ֵ�ԡ�
//�û����԰�û��'='�ַ�������Ϊע���С�
//------------------------------------------------------------
#ifndef _SoConfigFile_h_
#define _SoConfigFile_h_
//------------------------------------------------------------
#include <string>
#include <map>
//------------------------------------------------------------
class SoConfigFile
{
public:
	SoConfigFile();
	~SoConfigFile();

	//�Ӵ����ϼ��ز�����ָ�����ļ���
	//������ļ��������ڣ����ʾ������һ�����ļ�����ִ��WriteFile()ʱ��д������ļ���
	//--pFileName �ļ�������ֵ����ΪNULL��
	void ReadFile(const char* pFileName);

	//�ѵ�ǰ��������Ϣд���ļ��С�
	//�����������л���������һ�����������
	void WriteFile();

	//����ָ����Key����ȡ��Ӧ��Value�����Key�����ڣ��򷵻ظ�����Ĭ��ֵ��
	int GetValue_int(const std::string& strKey, const int nDefaultValue);
	float GetValue_float(const std::string& strKey, const float fDefaultValue);
	const char* GetValue_string(const std::string& strKey, const char* pszDefaultValue);

	//����µļ�ֵ�ԡ����������Key�Ѿ����ڣ��������Ӧ��Value��ֵ��
	void SetValue_int(const std::string& strKey, const int nValue);
	void SetValue_float(const std::string& strKey, const float fValue);
	void SetValue_string(const std::string& strKey, const std::string& strValue);

private:
	//������еĳ�Ա������
	void ClearConfig();

	//�����ļ��е�һ�����ݿ飬��ȡ��ÿһ�е����ݡ�
	//--bEndOfFile �Ƿ��Ѿ��������ļ���β��
	void ParseFileChunk(const char* pBuff, const int nValidSize, const bool bEndOfFile);

	//���ļ��е�һ�����ݽ�������ֵ�ԡ�
	void ParseFileLine();

	//���ַ������׺;�β��ĳЩ�ַ��޳������޳������ַ������ո�Tab�ַ���
	//--pBuff �ַ���
	//--nValidSize �ַ�����Ч�ַ�����
	//--nAdjustStartIndex [out] �ַ�����pBuff�е���ʼ��ַ������ʱ��ֵΪ0�������ڲ���������ֵ��
	void SlimString(char* pBuff, int nValidSize, int& nAdjustStartIndex);

private:
	typedef std::map<std::string, std::string> mapKey2Value;

private:
	//�洢�ļ�������������·����
	std::string m_strFileName;
	//�洢��ֵ�ԡ�
	mapKey2Value m_mapKey2Value;

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//���ز����������ļ�ʱ��ʹ�õ�������Щ��Ա��
	//�洢�ļ���һ�е����ݡ�
	char* m_pFileLineBuff;
	//��ǰm_pFileLineBuff�е���Ч���ȡ�
	int m_nValidLineSize;
	//�ļ��е�һ�а��������ַ������͡�ֵ�ַ�������
	//���ֵ��ʾ�����ַ�������m_pFileLineBuff�е��׵�ַ��
	int m_nKeyStartIndex;
	//���ֵ��ʾ��ֵ�ַ�������m_pFileLineBuff�е��׵�ַ��
	int m_nValueStartIndex;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//��¼��ֵ���Ƿ����˱仯��
	//���û�з����仯������WriteFile()ʱ�������ִ��д������
	bool m_bDirty;
};
//------------------------------------------------------------
#endif //_SoConfigFile_h_
//------------------------------------------------------------
