#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSV
///
#include "gen/GetQzssEphBoolParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSV::CmdName = "GetQzssEphBoolParamForEachSV";
    const char* const GetQzssEphBoolParamForEachSV::Documentation = "Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.\n\nGet QZSS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetQzssEphBoolParamForEachSV);


    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::create(const std::string& paramName)
    {
      return GetQzssEphBoolParamForEachSVPtr(new GetQzssEphBoolParamForEachSV(paramName));
    }

    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSV>(ptr);
    }

    bool GetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }


    int GetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
