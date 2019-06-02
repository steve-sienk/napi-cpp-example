#include "functionexample.h"

std::string functionexample::helloworld(){
  return "Hello Werld!";
}

std::string functionexample::bye(){
  return "Byeeee!";
}

int functionexample::add(int a, int b){
  return a + b;
}

Napi::String functionexample::ByeWrapped(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, functionexample::bye());
}

Napi::String functionexample::HelloWorldWrapped(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, functionexample::helloworld());
}

Napi::Number functionexample::AddWrapped(const Napi::CallbackInfo& info) {
  if(info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(info.Env(), "Number expected").ThrowAsJavaScriptException();
  }
  int x = info[0].As<Napi::Number>().Int32Value();
  int y = info[1].As<Napi::Number>().Int32Value();
  return Napi::Number::New(info.Env(), functionexample::add(x, y));
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) {
  exports.Set("helloworld", Napi::Function::New(env, functionexample::HelloWorldWrapped));
  exports.Set("bye", Napi::Function::New(env, functionexample::ByeWrapped));
  exports.Set("add", Napi::Function::New(env, functionexample::AddWrapped));
  return exports;
}
