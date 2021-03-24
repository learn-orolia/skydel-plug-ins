#ifndef SKYDEL_RAPI_INTERFACE_H
#define SKYDEL_RAPI_INTERFACE_H

#include <functional>
#include <string>

class SkydelRapi
{
public:
  virtual ~SkydelRapi() = default;

  virtual void post(const std::string &cmd, double timestamp = 0.0, std::function<void(const std::string &result)> resultCallback = {}) = 0;
};

class SkydelRapiInterface
{
public:
  virtual ~SkydelRapiInterface() = default;

  virtual void setRapi(SkydelRapi* rapi) = 0;

  static constexpr auto ID = "SkydelRapi";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_RAPI_INTERFACE_H