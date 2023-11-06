#include "VocaloidCore.h"
#include "VSM/WIVSMSequenceManager.h"
#include "VSM/VSMSequenceData.h"

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
    auto sequence = vocaloid::getSequenceManager().OpenSequence(
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
