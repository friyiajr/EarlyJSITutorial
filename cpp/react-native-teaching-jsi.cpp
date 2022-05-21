#include <cmath>

#include "react-native-teaching-jsi.h"

using namespace facebook;

auto jsiCeil = [](
  jsi::Runtime & rt,
  const jsi::Value &thisValue,
  const jsi::Value *args,
  size_t count
) -> jsi::Value {
  auto param = args[0].asNumber();
  return jsi::Value(ceil(param));
};

auto jsiFloor = [](
  jsi::Runtime & rt,
  const jsi::Value &thisValue,
  const jsi::Value *args,
  size_t count
) -> jsi::Value {
  auto param = args[0].asNumber();
  return jsi::Value(floor(param));
};

void installMath(jsi::Runtime & rt) {
  auto floorId = jsi::PropNameID::forAscii(rt, "floor");
  jsi::Function floor =
    jsi::Function::createFromHostFunction(rt, floorId, 1, jsiFloor);
  rt.global().setProperty(rt, "jsiFloor", floor);
  
  auto ceilId = jsi::PropNameID::forAscii(rt, "ceil");
  jsi::Function ceil =
    jsi::Function::createFromHostFunction(rt, ceilId, 1, jsiCeil);
  rt.global().setProperty(rt, "jsiCeil", ceil);
}
