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
    /// Please note the command SetQzssEphemerisDoubleParams is deprecated since 21.3. You may use SetQzssEphDoubleParamForEachSV.
    /// 
    /// Set QZSS ephemeris parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetQzssEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetQzssEphemerisDoubleParams;
    typedef std::shared_ptr<SetQzssEphemerisDoubleParams> SetQzssEphemerisDoubleParamsPtr;
    
    
    class SetQzssEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssEphemerisDoubleParams();

      SetQzssEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val);
  
      static SetQzssEphemerisDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetQzssEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
  }
}

