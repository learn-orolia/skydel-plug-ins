#pragma once

#include <memory>
#include "command_result.h"
#include <vector>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphDoubleParamForEachSV
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGpsEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetGpsEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetGpsEphDoubleParamForEachSVResult> GetGpsEphDoubleParamForEachSVResultPtr;
    typedef GetGpsEphDoubleParamForEachSVResult GetGpsEphemerisDoubleParamsResult;
    typedef std::shared_ptr<GetGpsEphemerisDoubleParamsResult> GetGpsEphemerisDoubleParamsResultPtr;
    
    class GetGpsEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphDoubleParamForEachSVResult();

      GetGpsEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
  
      static GetGpsEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
      static GetGpsEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
  }
}

