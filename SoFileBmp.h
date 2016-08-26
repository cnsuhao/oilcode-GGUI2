//----------------------------------------------------------------
#ifndef _SoFileBmp_h_
#define _SoFileBmp_h_
//----------------------------------------------------------------
//BMPͼƬ��֧��͸��ͨ����
//������BMPͼƬʱ��Դ���ݿ�����FileBmpPixelFormat_RGBA����FileBmpPixelFormat_ARGB��
enum eFileBmpPixelFormat
{
	FileBmpPixelFormat_RGB, //�ڴ��ַ 0xBBGGRR
	FileBmpPixelFormat_RGBA, //�ڴ��ַ 0xAABBGGRR
	FileBmpPixelFormat_ARGB, //�ڴ��ַ 0xBBGGRRAA
};
//----------------------------------------------------------------
//�������ݵ�����ϵ���͡�
//����һ��BMPͼƬ������������������ϵ��FileBmpDataCoordSystem_Left2Right_Down2Up��
enum eFileBmpDataCoordSystemType
{
	FileBmpDataCoordSystem_Left2Right_Up2Down,
	FileBmpDataCoordSystem_Left2Right_Down2Up,
};
//----------------------------------------------------------------
struct stFileBmpBaseInfo
{
	int nPictureWidth;
	int nPictureHeight;
	eFileBmpPixelFormat ePixelFormat;
	eFileBmpDataCoordSystemType eCoordSysType;
	int nDataSize;
	char* pData;

	stFileBmpBaseInfo()
	{
		Clear();
	}
	void Clear()
	{
		nPictureWidth = 0;
		nPictureHeight = 0;
		ePixelFormat = FileBmpPixelFormat_RGB;
		eCoordSysType = FileBmpDataCoordSystem_Left2Right_Down2Up;
		nDataSize = 0;
		pData = 0;
	}
};
//----------------------------------------------------------------
class SoFileBmp
{
public:
	static bool ReadBmpFile(const char* szFile, stFileBmpBaseInfo* pInfo);
	static bool WriteBmpFile(const char* szFile, const stFileBmpBaseInfo* pInfo);
};
//----------------------------------------------------------------
#endif //_SoFileBmp_h_
//----------------------------------------------------------------
