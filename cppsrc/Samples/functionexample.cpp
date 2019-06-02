#include "functionexample.h"

std::string functionexample::helloworld(){
  return "Hello Werld!";
}

std::string functionexample::bye(){
  return "Byeeee!";
}

Napi::String functionexample::ByeWrapped(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, functionexample::bye());
}

Napi::String functionexample::HelloWorldWrapped(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, functionexample::helloworld());
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) {
  exports.Set("helloworld",
    Napi::Function::New(env, functionexample::HelloWorldWrapped));
  exports.Set("bye",
    Napi::Function::New(env, functionexample::ByeWrapped));
  return exports;
}
