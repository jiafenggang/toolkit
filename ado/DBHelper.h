#pragma once
#include"stdafx.h"
#include"WLUtil.h"
class CDBHelper
{
public:
	CDBHelper();
	virtual ~CDBHelper();
	BOOL InitialConnect();
	void ExitConnect();
	virtual std::vector<std::map<M_DCM_TAG, CString>>& Retrieve();
protected:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr	   m_pRecordset;
	std::vector<std::map<M_DCM_TAG, CString>> m_list;		//存放查询记录集合
	BOOL UpdateFlag();
};

