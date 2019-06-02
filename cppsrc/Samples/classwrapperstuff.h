/* cppsrc/Samples/classwrapperstuff.h */

#include <napi.h>
#include "myclass.h"

class ClassWrapperStuff : public Napi::ObjectWrap<ClassWrapperStuff> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    ClassWrapperStuff(const Napi::CallbackInfo& info);
    MyClass* GetInternalInstance();
  private:
    static Napi::FunctionReference constructor; // ref to store class def that needs to be exported to JS
    Napi::Value GetValue(const Napi::CallbackInfo& info);
    Napi::Value Append(const Napi::CallbackInfo& info);
    MyClass *instanceOfMyAwesomeClass_;
};
