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
    /// Please note the command PrnsEnabled is deprecated since 21.3. You may use EnableEachSV.
    /// 
    /// Set  enabled or disabled satellites for this constellation.
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class EnablePrns;
    typedef std::shared_ptr<EnablePrns> EnablePrnsPtr;
    
    
    class EnablePrns : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnablePrns();

      EnablePrns(const std::string& system, const std::vector<bool>& enabled);
  
      static EnablePrnsPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnablePrnsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

