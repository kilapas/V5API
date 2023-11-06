#include <string>

#define V5API __declspec(dllimport)

V5API bool V5API_Init(const std::wstring& vocaloidPath, std::string& error);
V5API void V5API_Destroy();
V5API bool V5API_Render(const std::wstring& filePath, const std::wstring& wavPath, std::string& error);
