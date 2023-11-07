#include <string>

#define V5API __declspec(dllimport)

V5API bool V5API_Init(const std::wstring& vocaloidPath, std::string& error);
V5API void V5API_Destroy();
V5API bool V5API_Render(const std::wstring& filePath, const std::wstring& wavPath, std::string& error);
V5API size_t V5API_NumVoiceBanks();
V5API void* V5API_GetVoiceBankByIndex(size_t index);
V5API void* V5API_GetVoiceBankByCompID(const std::wstring& compID);
V5API const wchar_t* V5API_GetVoiceBankCompID(void* voiceBankHandle);
V5API const wchar_t* V5API_GetVoiceBankName(void* voiceBankHandle);
