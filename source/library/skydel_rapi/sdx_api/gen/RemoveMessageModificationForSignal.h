#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the signal for the message modification.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "QZSSL1CA", "QZSSL1S" and "NAVICL5"
    /// Id     string Unique identifier
    ///

    class RemoveMessageModificationForSignal;
    typedef std::shared_ptr<RemoveMessageModificationForSignal> RemoveMessageModificationForSignalPtr;
    
    
    class RemoveMessageModificationForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveMessageModificationForSignal();

      RemoveMessageModificationForSignal(const std::string& signal, const std::string& id);
  
      static RemoveMessageModificationForSignalPtr create(const std::string& signal, const std::string& id);
      static RemoveMessageModificationForSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

