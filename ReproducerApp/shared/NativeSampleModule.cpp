#include "NativeSampleModule.h"

namespace facebook::react {

NativeSampleModule::NativeSampleModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeSampleModuleCxxSpec(std::move(jsInvoker)) {}

std::string NativeSampleModule::reverseString(jsi::Runtime& rt, std::string input) {
  jsi::String jsMessage = jsi::String::createFromUtf8(rt, "My custom js error message");
  jsi::Value error = rt
    .global()
    .getProperty(rt, "Error")
    .asObject(rt)
    .asFunction(rt)
    .callAsConstructor(rt, {
      jsi::Value(rt, jsMessage)
    });

  throw jsi::JSError(rt, jsi::Value(rt, error));

  return std::string(input.rbegin(), input.rend());
}

} // namespace facebook::react
