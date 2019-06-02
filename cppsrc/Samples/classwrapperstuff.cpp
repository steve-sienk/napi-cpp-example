/* cppsrc/samples/classwrapperstuff.cpp */

#include "classwrapperstuff.h"

Napi::FunctionReference ClassWrapperStuff::constructor;

Napi::Object ClassWrapperStuff::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "MyAwesomeClass", {
    InstanceMethod("append", &ClassWrapperStuff::Append),
    InstanceMethod("bamboo", &ClassWrapperStuff::GetValue)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("MyAwesomeClass", func);
  return exports;
};

ClassWrapperStuff::ClassWrapperStuff(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ClassWrapperStuff>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if(info.Length() != 1) {
    Napi::TypeError::New(env, "Only one arg expected!").ThrowAsJavaScriptException();
  }

  if(!info[0].IsString()) {
    Napi::Object parent = info[0].As<Napi::Object>();

    ClassWrapperStuff* parent_wrapper_stuff =
      Napi::ObjectWrap<ClassWrapperStuff>::Unwrap(parent);

    MyClass* parent_myclass_instance = parent_wrapper_stuff->GetInternalInstance();
    std::string bamboo = parent_myclass_instance->getValue();
    this->instanceOfMyAwesomeClass_ = new MyClass(parent_myclass_instance->getValue());
    return;
  }

  Napi::String pandaling = info[0].As<Napi::String>();
  this->instanceOfMyAwesomeClass_ = new MyClass(pandaling);
}

Napi::Value ClassWrapperStuff::GetValue(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), this->instanceOfMyAwesomeClass_->getValue());
}

Napi::Value ClassWrapperStuff::Append(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if(info.Length() != 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected!").ThrowAsJavaScriptException();
  }

  Napi::String pandlingToAdd = info[0].As<Napi::String>();
  std::string bamboo = this->instanceOfMyAwesomeClass_->append(pandlingToAdd);

  return Napi::String::New(info.Env(), bamboo);
};


MyClass* ClassWrapperStuff::GetInternalInstance() {
  return this->instanceOfMyAwesomeClass_;
}
