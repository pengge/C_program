// ReceiveInforView.cpp : implementation file
//

#include "stdafx.h"
#include "GpsServer.h"
#include "ViewNemaData.h"
#include "GPSPublic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewNemaData

IMPLEMENT_DYNCREATE(CViewNemaData, CViewBase)

CViewNemaData::CViewNemaData()
{
	InitColumns();
}

CViewNemaData::~CViewNemaData()
{
}


BEGIN_MESSAGE_MAP(CViewNemaData, CViewBase)
	//{{AFX_MSG_MAP(CViewNemaData)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CViewNemaData diagnostics

#ifdef _DEBUG

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewNemaData message handlers
void CViewNemaData::InitColumns()
{
	_gColText.Add(IDS_COL_NEMA_1);
	_gColText.Add(IDS_COL_NEMA_2);
	_gColText.Add(IDS_COL_NEMA_3);	

	_gColWidth.Add(50);
	_gColWidth.Add(75);
	_gColWidth.Add(400);
}

void CViewNemaData::InsertNema(CString source, GPSPack *pack)
{
	// ��ȡ��ǰ�б���еļ�¼��Ŀ����������������־����,���б���е���־ɾ��
	if ((GetListCtrl().GetItemCount()) > VIEW_LOG_COUNT) 
	{
		ClearLogs();
	}

	//id
	CString sid="";
	sid.Format("%d",(GetListCtrl().GetItemCount()+1));

	CString content="";
	CString temp = "";
	CString temp1 = "";
	int i = 0;
	switch(pack->GPS_NEMA_TEXT.bodyType)
	{
		case NEMATYPE_STANDARD_GPGSA://��ǰ������Ϣ
			for (i = 0; i < MAX_SATE_TOTAL;i++)
			{
				if (pack->GPS_NEMA_GPGSA.body.prn[i] != 0)
				{
					temp1.Format("����%d,", pack->GPS_NEMA_GPGSA.body.prn[i]);
					temp += temp1;					
				}
			}
			content.Format("ģʽ=%s----��λ����=%s----PRN=%s----PDOP=%f----\
				HDOP=%f----VDOP=%f",
				CGPSPublic::GetGPSMode(pack->GPS_NEMA_GPGSA.body.gpsmode),		
				CGPSPublic::GetPosType(pack->GPS_NEMA_GPGSA.body.postype, 1) ,
				temp,
				pack->GPS_NEMA_GPGSA.body.pdop,
				pack->GPS_NEMA_GPGSA.body.hdop,
				pack->GPS_NEMA_GPGSA.body.vdop);
			break;
		
		case NEMATYPE_STANDARD_GPGSV://�ɼ�������Ϣ
			for (i = 0; i < MAX_SATE_ONE_TOTAL;i++)
			{
				if (pack->GPS_NEMA_GPGSA.body.prn[i] != 0)
				{
					temp1.Format("----PRN��=%d,��������=%d,���Ƿ�λ��=%d,�����=%d", 
						pack->GPS_NEMA_GPGSV.body.prn[i],
						pack->GPS_NEMA_GPGSV.body.yj[i],
						pack->GPS_NEMA_GPGSV.body.fwj[i],
						pack->GPS_NEMA_GPGSV.body.xzb[i]);
					temp += temp1;				
				}
			}
			content.Format("����=%d----���=%d----�ɼ�=%d----%s",
				pack->GPS_NEMA_GPGSV.body.total ,		
				pack->GPS_NEMA_GPGSV.body.no ,
				pack->GPS_NEMA_GPGSV.body.validsate, temp);
			break;

		case NEMATYPE_STANDARD_GPVTG://�����ٶ���Ϣ
			content.Format("�汱����=%d----�ű�����=%d----��������(��)=%f----��������(����/Сʱ)=%f----\
				ģʽָʾ=%s",
				pack->GPS_NEMA_GPVTG.body.directtn ,		
				pack->GPS_NEMA_GPVTG.body.directcn ,
				pack->GPS_NEMA_GPVTG.body.volityj,
				pack->GPS_NEMA_GPVTG.body.volitykm,
				CGPSPublic::GetMode(pack->GPS_NEMA_GPVTG.body.mode));
			break;

		case NEMATYPE_STANDARD_GPDTM://�������ϵ��Ϣ
			content.Format("��������ϵ����=%s----����ϵ�Ӵ���=%s\
			----%sγ��ƫ����=%f----%s����ƫ����=%f----�߶�ƫ����=%f----����ϵ����=%s",
				pack->GPS_NEMA_GPDTM.body.localdatum ,		
				pack->GPS_NEMA_GPDTM.body.subdatum,
				CGPSPublic::GetLatitudeType(pack->GPS_NEMA_GPDTM.body.latitudetype),
				pack->GPS_NEMA_GPDTM.body.latitudeoffset,
				CGPSPublic::GetLongitudeType(pack->GPS_NEMA_GPDTM.body.longitudetype),
				pack->GPS_NEMA_GPDTM.body.longitudeoffset,
				pack->GPS_NEMA_GPDTM.body.alitudeoffset,
				pack->GPS_NEMA_GPDTM.body.datum);
			break;		

		case NEMATYPE_GARMIN_PGRME://���������Ϣ
			content.Format("ˮƽ�������=%f----��ֱ�������=%f----λ�ù������=%f",
				pack->GPS_NEMA_PGRME.body.hpe ,		
				pack->GPS_NEMA_PGRME.body.vpe,			
				pack->GPS_NEMA_PGRME.body.epe);
			break;

		case NEMATYPE_GARMIN_PGRMM://����ϵͳ��Ϣ,����Ϣ����MapSource����ʵʱ���ӵ�ʱ��ʹ�á�
			content.Format("����ϵ����=%s(��MapSource����ʵʱ���ӵ�ʱ��ʹ��)",
			pack->GPS_NEMA_PGRMM.body.datum );
			break;

		case NEMATYPE_GARMIN_PGRMT://����״̬��Ϣ
			content.Format("�汾=%s----ROMУ�����=%s\
				----���ջ�����������=%s-----�洢������=%s\
				----ʱ�ӵ���Ϣ=%s----����������Ư��=%s\
				----���ݲ������ɼ�=%s----GPS���ջ��¶�=%f\
				----GPS���ջ���������=%s",
				pack->GPS_NEMA_PGRMT.body.version ,		
				CGPSPublic::GetFaultStatu(pack->GPS_NEMA_PGRMT.body.romcheck),
				CGPSPublic::GetFaultStatu(pack->GPS_NEMA_PGRMT.body.fault),
				CGPSPublic::GetSaveStatu(pack->GPS_NEMA_PGRMT.body.storedata),
				CGPSPublic::GetSaveStatu(pack->GPS_NEMA_PGRMT.body.clock),
				CGPSPublic::GetOffsetStatu(pack->GPS_NEMA_PGRMT.body.piaoyi),
				CGPSPublic::GetCollectStatu(pack->GPS_NEMA_PGRMT.body.datacollect),
				pack->GPS_NEMA_PGRMT.body.temperature,
				CGPSPublic::GetSaveStatu(pack->GPS_NEMA_PGRMT.body.configdata));
			break;

		case NEMATYPE_GARMIN_PGRMB://�ű�����Ϣ
			content.Format("�ű�վƵ��=%f----�ű������=%d\
			----SNR�����=%d----�ű���������=%d----����=%f----ͨѶ״̬=%s\
			----���Դ=%s----���״̬=%s",
				pack->GPS_NEMA_PGRMB.body.freq , pack->GPS_NEMA_PGRMB.body.banud,
				pack->GPS_NEMA_PGRMB.body.snr, pack->GPS_NEMA_PGRMB.body.quality,
				pack->GPS_NEMA_PGRMB.body.distance,
				CGPSPublic::GetCommStatu(pack->GPS_NEMA_PGRMB.body.commstatu),
				CGPSPublic::GetDiffSource(pack->GPS_NEMA_PGRMB.body.source),
				CGPSPublic::GetDiffStatu(pack->GPS_NEMA_PGRMB.body.statu));
			break;
	}

	LV_ITEM	lvItem;
	lvItem.mask = LVIF_TEXT | LVIF_STATE;
	lvItem.iItem = 0;
	lvItem.iSubItem = 0;
	lvItem.iImage = 0;
	lvItem.stateMask = LVIS_STATEIMAGEMASK;
	lvItem.state = INDEXTOSTATEIMAGEMASK(1);	
	lvItem.pszText = (char*)(LPCTSTR)(sid);	
	int result = GetListCtrl().InsertItem(&lvItem);
	if (result != -1)
	{		
		GetListCtrl().SetItemText(0, 1, source);
		GetListCtrl().SetItemText(0, 2, content);		
	}
}
