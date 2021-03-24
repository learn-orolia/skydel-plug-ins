#pragma once

#include <memory>
#include "command_base.h"
#include <vector>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type       Description
    /// --------- ---------- --------------------------------------------------------------------------------------------------
    /// ParamName string     Refer to SetBeiDouEphBoolParamForSV for accepted names
    /// Val       array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetBeiDouEphBoolParamForEachSV;
    typedef std::shared_ptr<SetBeiDouEphBoolParamForEachSV> SetBeiDouEphBoolParamForEachSVPtr;
    
    
    class SetBeiDouEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouEphBoolParamForEachSV();

      SetBeiDouEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val);
  
      static SetBeiDouEphBoolParamForEachSVPtr create(const std::string& paramName, const std::vector<bool>& val);
      static SetBeiDouEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);
    };
  }
}

