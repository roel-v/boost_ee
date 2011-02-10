
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>

#include "custview.h"

#include "TimeAddIn.h"

#include <atlstr.h>

#include <boost/date_time/posix_time/posix_time.hpp>

ADDIN_API HRESULT __stdcall AddIn_Boost_Posix_time_Ptime( DWORD dwAddress, DEBUGHELPER *pHelper, int nBase, BOOL bUniStrings, char *pResult, size_t max, DWORD reserved )
{
	boost::posix_time::ptime var;
    DWORD nGot;

	if (pHelper->ReadDebuggeeMemoryEx(pHelper, pHelper->GetRealAddress(pHelper), sizeof(var), &var, &nGot) != S_OK) {
        return E_FAIL;
	}
	if (nGot != sizeof(var)) {
        return E_FAIL;
	}

	std::string str = boost::posix_time::to_simple_string(var);
	if (bUniStrings) {
		//wcsncpy((wchar_t*)pResult, str.c_str(), max);
		::MessageBox(NULL, L"", L"", MB_ICONERROR);
	} else {
		strncpy(pResult, str.c_str(), max);
	}

	return S_OK;
}

ADDIN_API HRESULT __stdcall AddIn_Boost_Gregorian_Date(DWORD dwAddress, DEBUGHELPER* pHelper, int nBase, BOOL bUniStrings, char* pResult, size_t max, DWORD reserved)
{
	boost::gregorian::date var;
    DWORD nGot;

	if (pHelper->ReadDebuggeeMemoryEx(pHelper, pHelper->GetRealAddress(pHelper), sizeof(var), &var, &nGot) != S_OK) {
        return E_FAIL;
	}
	if (nGot != sizeof(var)) {
        return E_FAIL;
	}

	std::string str = boost::gregorian::to_simple_string(var);
	if (bUniStrings) {
		//wcsncpy((wchar_t*)pResult, str.c_str(), max);
		::MessageBox(NULL, L"", L"", MB_ICONERROR);
	} else {
		strncpy(pResult, str.c_str(), max);
	}

	return S_OK;
}
