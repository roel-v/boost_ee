
#define ADDIN_API __declspec(dllexport)
//#define ADDIN_API 

extern "C" ADDIN_API HRESULT __stdcall AddIn_Boost_Posix_time_Ptime(DWORD dwAddress, DEBUGHELPER* pHelper, int nBase, BOOL bUniStrings, char* pResult, size_t max, DWORD reserved);
extern "C" ADDIN_API HRESULT __stdcall AddIn_Boost_Gregorian_Date(DWORD dwAddress, DEBUGHELPER* pHelper, int nBase, BOOL bUniStrings, char* pResult, size_t max, DWORD reserved);
