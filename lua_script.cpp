#include "lua_script.h"

namespace custom_bin_decoder::lua_script {

LuaScript::LuaScript() {
  lua_state = luaL_newstate();
  static const luaL_Reg lualibs[] = {{"base", luaopen_base},
                                     {"io", luaopen_io},
                                     {"string", luaopen_string},
                                     {NULL, NULL}};

  for (const luaL_Reg* lib = lualibs; lib->func != NULL; lib++) {
    luaL_requiref(lua_state, lib->name, lib->func, 1);
    lua_settop(lua_state, 0);
  }
}

LuaScript::~LuaScript() { lua_close(lua_state); }

std::string LuaScript::DoFile(std::string lua_file_name) {
  luaL_dofile(lua_state, lua_file_name.c_str());
  return lua_tostring(lua_state, lua_gettop(lua_state));
}

std::string LuaScript::DoString(std::string lua_code) {
  luaL_dostring(lua_state, lua_code.c_str());
  return lua_tostring(lua_state, lua_gettop(lua_state));
}

void LuaScript::SetGlobalString(std::string value, std::string var_name) {
  lua_pushstring(lua_state, value.c_str());
  lua_setglobal(lua_state, var_name.c_str());
}

std::string Decode(std::string binary_number, std::string lua_code) {
  LuaScript lua_script;
  lua_script.SetGlobalString(binary_number, "Data");
  return lua_script.DoString(lua_code);
}

}  // namespace lua_testing::lua_script
