#include "stdafx.h"
#include "DBHelper.h"


CDBHelper::CDBHelper()
{
	
}


CDBHelper::~CDBHelper()
{
}

BOOL CDBHelper::InitialConnect(){
	::CoInitialize(NULL);	//初始化com
	try{
		m_pConnection.CreateInstance(__uuidof(Connection));
		_bstr_t strConnect = _T("Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=RIS;Data Source=WIN-EOXCGUMP4UD\PERLOVE_PACS");
		_bstr_t userID = _T("sa");
		_bstr_t passWord = _T("123456");
		m_pConnection->Open(strConnect, userID, passWord,adModeUnknown);
		TRACE(_T("数据库连接成功！"));
		return TRUE;
	}
	catch (_com_error e){
		CString info;
		info.Format(_T("数据库连接有问题%s"), e.Description());
		//TRACE(info);   致命错误别用TRACE
		AfxMessageBox(info);
		return FALSE;
	}
}

void CDBHelper::ExitConnect(){
	if (!m_pRecordset){
		m_pRecordset->Close();
		m_pRecordset = NULL;
	}
	m_pConnection->Close();
	m_pConnection = NULL;
	::CoUninitialize();
}


std::vector<std::map<M_DCM_TAG, CString>>& CDBHelper::Retrieve(){
	try{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		CString sqlState = _T("select * from WLOrder_ where WLFlag_ is  null or WLFlag_=1 ");
		m_pRecordset->Open(_bstr_t(sqlState), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);

		m_list.clear();
		if (m_pRecordset->adoEOF|| m_pRecordset->adoBOF){
			m_pRecordset->Close();
			return m_list;
		}
		CString patientName;
		CString	
		while (!m_pRecordset->adoEOF){
			std::map<M_DCM_TAG, CString> m_map;

		}
	}
	catch (_com_error e){
		CString info;
		info.Format(_T("查询失败！%s"), e.Description());
		TRACE(info);
	}
}