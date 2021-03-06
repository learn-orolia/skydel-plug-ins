#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssUraIndexForSV
///
#include "gen/SetQzssUraIndexForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssUraIndexForSV::CmdName = "SetQzssUraIndexForSV";
    const char* const SetQzssUraIndexForSV::Documentation = "Please note the command SetQzssUraIndex is deprecated since 21.3. You may use SetQzssUraIndexForSV.\n\nSet the URA index of a QZSS satellite";

    REGISTER_COMMAND_FACTORY(SetQzssUraIndexForSV);


    SetQzssUraIndexForSV::SetQzssUraIndexForSV()
      : CommandBase(CmdName)
    {}

    SetQzssUraIndexForSV::SetQzssUraIndexForSV(int svId, int urai)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setUrai(urai);
    }


    SetQzssUraIndexForSVPtr SetQzssUraIndexForSV::create(int svId, int urai)
    {
      return SetQzssUraIndexForSVPtr(new SetQzssUraIndexForSV(svId, urai));
    }

    SetQzssUraIndexForSVPtr SetQzssUraIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssUraIndexForSV>(ptr);
    }

    bool SetQzssUraIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
        ;

    }

    std::string SetQzssUraIndexForSV::documentation() const { return Documentation; }


    int SetQzssUraIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetQzssUraIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssUraIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssUraIndexForSV::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetQzssUraIndexForSV::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
