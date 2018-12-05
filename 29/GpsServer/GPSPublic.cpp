// GPSPublic.cpp : implementation file
//

#include "stdafx.h"
#include "gpsserver.h"
#include "GPSPublic.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGPSPublic

CGPSPublic::CGPSPublic()
{
}

CGPSPublic::~CGPSPublic()
{
}


BEGIN_MESSAGE_MAP(CGPSPublic, CWnd)
	//{{AFX_MSG_MAP(CGPSPublic)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CGPSPublic message handlers

CString CGPSPublic::GetDirectXType(char type)
{
	CString result;
	switch (type)
	{
	case 'E':
		result = "��";
		break;
	case 'W':
		result = "����";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetDirectYType(char type)
{
	CString result;
	switch (type)
	{
	case 'N':
		result = "��";
		break;
	case 'S':
		result = "����";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetDirectZType(char type)
{
	CString result;
	switch (type)
	{
	case 'D':
		result = "����";
		break;
	case 'U':
		result = "����";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetLatitudeType(char type)
{
	CString result;
	switch (type)
	{
	case 'N':
		result = "��γ";
		break;
	case 'S':
		result = "��γ";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetLongitudeType(char type)
{
	CString result;
	switch (type)
	{
	case 'E':
		result = "����";
		break;
	case 'W':
		result = "����";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}


CString CGPSPublic::GetMode(char type)
{
	CString result;
	switch (type)
	{
	case 'A':
		result = "������λ";
		break;
	case 'D':
		result = "���";
		break;
	case 'E':
		result = "����D";
		break;
	case 'N':
		result = "������Ч";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}
		
CString CGPSPublic::GetCommStatu(char type)
{
	CString result;
	switch (type)
	{
	case '0':
		result = "������";
		break;
	case '1':
		result = "���ź�";
		break;
	case '2':
		result = "���ڵ�г";
		break;	
	case '3':
		result = "���ڽ���";
		break;
	case '4':
		result = "����ɨ��";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetFaultStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'P':
		result = "ͨ��";
		break;
	case 'F':
		result = "ʧ��";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetSaveStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'R':
		result = "����";
		break;
	case 'L':
		result = "��ʧ";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetOffsetStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'P':
		result = "ͨ��";
		break;
	case 'F':
		result = "��⵽����Ư��";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetCollectStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'C':
		result = "���ڲɼ�";
		break;
	default:
		result = "û�вɼ�";
		break;
	}
	return result;
}	
		
CString CGPSPublic::GetDiffSource(char type)
{
	CString result;
	switch (type)
	{
	case 'W':
		result = "WAAS";
		break;
	case 'R':
		result = "RTCM";
		break;
	case 'N':
		result = "�ǲ�ֶ�λ";
		break;	
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetDiffStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'A':
		result = "�Զ�";
		break;
	case 'W':
		result = "��ΪWAAS";
		break;
	case 'R':
		result = "RTCM";
		break;
	case 'N':
		result = "�����ղ���ź�";
		break;	
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetGPSMode(char type)
{
	CString result;
	switch (type)
	{
	case 'A':
		result = "�Զ�";
		break;
	case 'M':
		result = "�ֶ�";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}


CString CGPSPublic::GetGPSValid(char type)
{
	CString result;
	switch (type)
	{
	case 'A':
		result = "��Ч��λ";
		break;
	case 'V':
		result = "��Ч��λ";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

CString CGPSPublic::GetGPSStatu(char type)
{
	CString result;
	switch (type)
	{
	case '0':
		result = "δ��λ";
		break;
	case '1':
		result = "�ǲ�ֶ�λ";
		break;
	case '2':
		result = "��ֶ�λ";
		break;
	case '6':
		result = "���ڹ���";
		break;	
	default:
		result = "δ֪";
		break;
	}
	return result;
}


CString CGPSPublic::GetPosType(char type, int stardand)
{
	CString result;

	// ����Ǳ�׼��NEMA�����
	if (stardand == 1)
	{
		switch (type)
		{
		case '1':
			result = "û�ж�λ";
			break;
		case '2':
			result = "2D��λ";
			break;
		case '3':
			result = "3D��λ";
			break;	
		default:
			result = "δ֪";
			break;
		}
	}
	// �����GARMIN��˾����
	else
	{
		switch (type)
		{
		case '0':
			result = "û�ж�λ";
			break;
		case '1':
			result = "2D��λ";
			break;
		case '2':
			result = "3D��λ";
			break;	
		default:
			result = "δ֪";
			break;
		}
	}
	return result;
}

CString CGPSPublic::GetTextPosStatu(char type)
{
	CString result;
	switch (type)
	{
	case 'd':
		result = "2ά��ֶ�λ";
		break;
	case 'D':
		result = "3ά��ֶ�λ";
		break;
	case 'g':
		result = "2ά��λ";
		break;
	case 'G':
		result = "3ά��λ";
		break;
	case 'S':
		result = "ģ��״̬";
		break;
	case '_':
		result = "��Ч";
		break;
	default:
		result = "δ֪";
		break;
	}
	return result;
}

void CGPSPublic::ConvertToLongitude(double& longitude, CString inStr)
{
	if (inStr.GetLength() < 8)
	{
		return;
	}

	int degree = atoi((const char*)inStr.Mid(0, 3));
	CString minute;
	minute = inStr.Mid(3, 5);
	minute.Insert(2, '.');
	double dminute = atof((const char*)minute);
	longitude = degree + dminute/60;
}

void CGPSPublic::ConvertToLongitudeHavePoint(double& longitude, CString inStr)
{
	if (inStr.GetLength() < 8)
	{
		return;
	}

	int degree = atoi((const char*)inStr.Mid(0, 3));
	CString minute;
	minute = inStr.Mid(3, 5);	
	double dminute = atof((const char*)minute);
	longitude = degree + dminute/60;
}

void CGPSPublic::ConvertToLatitude(double& latitude, CString inStr)
{
	if (inStr.GetLength() < 7)
	{
		return;
	}

	int degree = atoi((const char*)inStr.Mid(0, 2));
	CString minute;
	minute = inStr.Mid(2, 5);
	minute.Insert(2, '.');
	double dminute = atof((const char*)minute);
	latitude = degree + dminute/60;
}

void CGPSPublic::ConvertToLatitudeHavePoint(double& latitude, CString inStr)
{
	if (inStr.GetLength() < 2)
	{
		return;
	}

	int degree = atoi((const char*)inStr.Mid(0, 2));
	CString minute;
	minute = inStr.Mid(2, 5);
	double dminute = atof((const char*)minute);
	latitude = degree + dminute/60;
}

void CGPSPublic::ConvertToDouble(double& value, CString inStr)
{
	value = atof((const char*)inStr);
}

void CGPSPublic::ConvertToInt(int& value, CString inStr)
{
	value = atoi((const char*)inStr);
}

void CGPSPublic::ConvertToDoubleAddPoint(double& value, CString inStr, int pos)
{	
	inStr.Insert(pos, '.');
	value = atof((const char*)inStr);
}

void CGPSPublic::ConvertToChar(char& value, CString inStr, int length)
{
	memcpy((void*)&value, (const void*)inStr, length);	
}
