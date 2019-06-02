#include <napi.h>

namespace functionexample {
  std::string helloworld();
  std::string bye();
  int add(int a, int b);
  Napi::String HelloWorldWrapped(const Napi::CallbackInfo& info);
  Napi::String ByeWrapped(const Napi::CallbackInfo& info);
  Napi::Number AddWrapped(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}
