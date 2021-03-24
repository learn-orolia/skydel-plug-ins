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
    /// Please note the command SetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use SetBeiDouEphDoubleParamForEachSV.
    /// 
    /// Set BeiDou ephemeris parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetBeiDouEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetBeiDouEphemerisDoubleParams;
    typedef std::shared_ptr<SetBeiDouEphemerisDoubleParams> SetBeiDouEphemerisDoubleParamsPtr;
    
    
    class SetBeiDouEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouEphemerisDoubleParams();

      SetBeiDouEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val);
  
      static SetBeiDouEphemerisDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetBeiDouEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
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

