#include <node.h>

namespace demo
{

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void GetHelloMessage(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello from cpp context aware module").ToLocalChecked());
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "getHelloMessage", GetHelloMessage);
  }

  NODE_MODULE_INIT()
  {
    NODE_SET_METHOD(exports, "getHelloMessage", GetHelloMessage);
  }

} // namespace demo
