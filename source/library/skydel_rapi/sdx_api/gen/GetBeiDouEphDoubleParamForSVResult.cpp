#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphDoubleParamForSVResult
///
#include "gen/GetBeiDouEphDoubleParamForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphDoubleParamForSVResult::CmdName = "GetBeiDouEphDoubleParamForSVResult";
    const char* const GetBeiDouEphDoubleParamForSVResult::Documentation = "Result of GetBeiDouEphDoubleParamForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouEphDoubleParamForSVResult);


    GetBeiDouEphDoubleParamForSVResult::GetBeiDouEphDoubleParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphDoubleParamForSVResult::GetBeiDouEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }


    GetBeiDouEphDoubleParamForSVResultPtr GetBeiDouEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
    {
      return GetBeiDouEphDoubleParamForSVResultPtr(new GetBeiDouEphDoubleParamForSVResult(relatedCommand, svId, paramName, val));
    }

    GetBeiDouEphDoubleParamForSVResultPtr GetBeiDouEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphDoubleParamForSVResult>(ptr);
    }

    bool GetBeiDouEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetBeiDouEphDoubleParamForSVResult::documentation() const { return Documentation; }


    int GetBeiDouEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
