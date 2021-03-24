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
    /// Please note the command SetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use SetGalileoEphDoubleParamForEachSV.
    /// 
    /// Set Galileo ephemeris parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGalileoEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetGalileoEphemerisDoubleParams;
    typedef std::shared_ptr<SetGalileoEphemerisDoubleParams> SetGalileoEphemerisDoubleParamsPtr;
    
    
    class SetGalileoEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoEphemerisDoubleParams();

      SetGalileoEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val);
  
      static SetGalileoEphemerisDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetGalileoEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
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

