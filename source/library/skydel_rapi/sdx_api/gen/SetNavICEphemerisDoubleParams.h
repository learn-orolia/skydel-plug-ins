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
    /// Please note the command SetNavICEphemerisDoubleParams is deprecated since 21.3. You may use SetNavICEphDoubleParamForEachSV.
    /// 
    /// Set NavIC ephemeris parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetNavICEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetNavICEphemerisDoubleParams;
    typedef std::shared_ptr<SetNavICEphemerisDoubleParams> SetNavICEphemerisDoubleParamsPtr;
    
    
    class SetNavICEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICEphemerisDoubleParams();

      SetNavICEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val);
  
      static SetNavICEphemerisDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetNavICEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
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

