#ifndef CUSTOM_BIN_DECODER_LUA_SCRIPT_H
#define CUSTOM_BIN_DECODER_LUA_SCRIPT_H

extern "C" {
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

#include <string>

namespace custom_bin_decoder::lua_script {

class LuaScript {
 private:
  lua_State* lua_state;

 public:
  LuaScript();
  ~LuaScript();
  std::string DoFile(std::string lua_file_name);
  std::string DoString(std::string lua_code);
  void SetGlobalString(std::string value, std::string var_name);
};

std::string Decode(std::string binary_number, std::string lua_code);

}  // namespace custom_bin_decoder::lua_script

#endif  // CUSTOM_BIN_DECODER_LUA_SCRIPT_H
