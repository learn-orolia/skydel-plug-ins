#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL5HealthForSV
///
#include "gen/SetQzssL5HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL5HealthForSV::CmdName = "SetQzssL5HealthForSV";
    const char* const SetQzssL5HealthForSV::Documentation = "Please note the command SetQzssSatelliteL5Health is deprecated since 21.3. You may use SetQzssL5HealthForSV.\n\nSet QZSS L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(SetQzssL5HealthForSV);


    SetQzssL5HealthForSV::SetQzssL5HealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL5HealthForSV::SetQzssL5HealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetQzssL5HealthForSVPtr SetQzssL5HealthForSV::create(int svId, bool health)
    {
      return SetQzssL5HealthForSVPtr(new SetQzssL5HealthForSV(svId, health));
    }

    SetQzssL5HealthForSVPtr SetQzssL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL5HealthForSV>(ptr);
    }

    bool SetQzssL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetQzssL5HealthForSV::documentation() const { return Documentation; }


    int SetQzssL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}