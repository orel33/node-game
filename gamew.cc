/**
 * @file gamew.cc
 * @brief Game Wrapper for Node.js
 * @author aurelien.esnard@u-bordeaux.fr
 * @copyright University of Bordeaux. All rights reserved, 2022.
 **/

#include <napi.h>
#include <napi.h>
#include <cstdbool>
#include "gamew.hh"

/* ******************** include C game library  ******************** */

extern "C"
{
#include "game.h"
#include "game_aux.h"
#include "game_ext.h"
#include "game_tools.h"
}

/* ******************** error management ******************** */

#define ASSERT(env, msg, cond)                                         \
  do                                                                   \
  {                                                                    \
    if (!(cond))                                                       \
      Napi::TypeError::New((env), (msg)).ThrowAsJavaScriptException(); \
  } while (0)

/* ******************** constructor & destructor ******************** */

Game::Game(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<Game>(info)
{
  this->g = game_default();
}

Game::~Game()
{
  game_delete(this->g);
}

/* ******************** game play ******************** */

void Game::play_move(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 3);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  ASSERT(info.Env(), "arg #3: number expected", info[2].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  uint s = info[2].As<Napi::Number>().Uint32Value();
  game_play_move(this->g, i, j, (square)s);
}

Napi::Value Game::check_move(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 3);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  ASSERT(info.Env(), "arg #3: number expected", info[2].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  uint s = info[2].As<Napi::Number>().Uint32Value();
  bool ret = game_check_move(this->g, i, j, (square)s);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::is_over(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  bool ret = game_is_over(this->g);
  return Napi::Boolean::New(info.Env(), ret);
}

void Game::restart(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  game_restart(this->g);
}

Napi::Value Game::solve(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  bool ret = game_solve(this->g);
  return Napi::Boolean::New(info.Env(), ret);
}

void Game::undo(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  game_undo(this->g);
}

void Game::redo(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  game_redo(this->g);
}

/* ******************** game accessors ******************** */

Napi::Value Game::get_square(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  square s = game_get_square(this->g, i, j);
  return Napi::Number::New(info.Env(), s);
}

Napi::Value Game::get_state(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  square s = game_get_state(this->g, i, j);
  return Napi::Number::New(info.Env(), s);
}

Napi::Value Game::get_flags(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  square s = game_get_flags(this->g, i, j);
  return Napi::Number::New(info.Env(), s);
}

Napi::Value Game::is_blank(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_is_blank(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::is_lightbulb(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_is_lightbulb(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::is_black(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_is_black(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::get_black_number(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  int k = game_get_black_number(this->g, i, j);
  return Napi::Number::New(info.Env(), k);
}

Napi::Value Game::is_marked(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_is_marked(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::is_lighted(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_is_lighted(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::has_error(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 2);
  ASSERT(info.Env(), "arg #1: number expected", info[0].IsNumber());
  ASSERT(info.Env(), "arg #2: number expected", info[1].IsNumber());
  uint i = info[0].As<Napi::Number>().Uint32Value();
  uint j = info[1].As<Napi::Number>().Uint32Value();
  bool ret = game_has_error(this->g, i, j);
  return Napi::Boolean::New(info.Env(), ret);
}

Napi::Value Game::nb_rows(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  uint nb_rows = game_nb_rows(this->g);
  return Napi::Number::New(info.Env(), nb_rows);
}

Napi::Value Game::nb_cols(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  uint nb_cols = game_nb_cols(this->g);
  return Napi::Number::New(info.Env(), nb_cols);
}

Napi::Value Game::is_wrapping(const Napi::CallbackInfo &info)
{
  ASSERT(info.Env(), "bad number of arguments", info.Length() == 0);
  bool ret = game_is_wrapping(this->g);
  return Napi::Boolean::New(info.Env(), ret);
}

/* ******************** Export Class ******************** */

Napi::Object Game::Init(Napi::Env env, Napi::Object exports)
{

  Napi::Function func =
      DefineClass(env, "Game",
                  {
                      // game play
                      InstanceMethod("play_move", &Game::play_move),
                      InstanceMethod("check_move", &Game::check_move),
                      InstanceMethod("is_over", &Game::is_over),
                      InstanceMethod("restart", &Game::restart),
                      InstanceMethod("solve", &Game::solve),
                      InstanceMethod("undo", &Game::undo),
                      InstanceMethod("redo", &Game::redo),

                      // game accessors
                      InstanceMethod("get_square", &Game::get_square),
                      InstanceMethod("get_state", &Game::get_state),
                      InstanceMethod("get_flags", &Game::get_flags),
                      InstanceMethod("is_blank", &Game::is_blank),
                      InstanceMethod("is_lightbulb", &Game::is_lightbulb),
                      InstanceMethod("is_black", &Game::is_black),
                      InstanceMethod("get_black_number", &Game::get_black_number),
                      InstanceMethod("is_marked", &Game::is_marked),
                      InstanceMethod("is_lighted", &Game::is_lighted),
                      InstanceMethod("has_error", &Game::has_error),
                      InstanceMethod("nb_rows", &Game::nb_rows),
                      InstanceMethod("nb_cols", &Game::nb_cols),
                      InstanceMethod("is_wrapping", &Game::is_wrapping)

                      // end
                  });

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);
  exports.Set("Game", func);
  return exports;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return Game::Init(env, exports);
}

// https://github.com/nodejs/node-addon-api/blob/main/doc/node-gyp.md
NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)

// EOF