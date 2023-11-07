#include "VocaloidCore.h"
#include "VSM/WIVSMSequenceManager.h"
#include "VSM/VSMSequenceData.h"
#include "VDM/DatabaseManager.h"

#define V5API __declspec(dllexport)

V5API bool V5API_Init(const std::wstring& vocaloidPath, std::string& error)
{
    return vocaloid::Init(vocaloidPath, error);
}

V5API void V5API_Destroy()
{
    vocaloid::Destroy();
}

V5API bool V5API_Render(const std::wstring& filePath, const std::wstring& wavPath, std::string& error)
{
    auto sequence = vocaloid::GetSequenceManager().OpenSequence(
        filePath, 
        {vocaloid::vsm::VSMSamplingRate::_44100, 128, 0});
    
    if (!sequence)
    {
        error = "open file failed";
        return false;
    }

    auto result = sequence.GetTrack(0).GetPart(0).Render(wavPath);
    if (result != vocaloid::vsm::NoError)
    {
        error = vocaloid::vsm::enumToString(result);
        return false;
    }

    return true;
}

V5API size_t V5API_NumVoiceBanks()
{
    return vocaloid::GetDatabaseManager().NumVoiceBanks();
}

V5API void* V5API_GetVoiceBankByIndex(size_t index)
{
    return vocaloid::GetDatabaseManager().GetVoiceBankByIndex(index);
}

V5API void* V5API_GetVoiceBankByCompID(const std::wstring& compID)
{
    return vocaloid::GetDatabaseManager().GetVoiceBankByCompID(compID);
}

V5API const wchar_t* V5API_GetVoiceBankCompID(void* voiceBankHandle)
{
    return vocaloid::vdm::VoiceBank(voiceBankHandle).CompID();
}

V5API const wchar_t* V5API_GetVoiceBankName(void* voiceBankHandle)
{
    return vocaloid::vdm::VoiceBank(voiceBankHandle).Name();
}
