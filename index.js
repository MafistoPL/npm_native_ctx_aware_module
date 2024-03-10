const cppModule = require("./build/Release/npm_native_ctx_aware_module");

console.log("npm_native_ctx_aware_module loaded");

const getHello = () => {
  return cppModule.getHelloMessage();
};

module.exports = { getHello };
