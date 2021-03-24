#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the PRN transmitted by the SV ID for this signal.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "G1", "G2", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "QZSSL1CA", "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// SvId   int    Satellite SV ID.
    /// Prn    int    PRN number.
    ///

    class SetPrnOfSVID;
    typedef std::shared_ptr<SetPrnOfSVID> SetPrnOfSVIDPtr;
    
    
    class SetPrnOfSVID : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPrnOfSVID();

      SetPrnOfSVID(const std::string& signal, int svId, int prn);
  
      static SetPrnOfSVIDPtr create(const std::string& signal, int svId, int prn);
      static SetPrnOfSVIDPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}
