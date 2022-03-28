#ifndef GAMEW_H
#define GAMEW_H

#include <napi.h>

typedef struct game_s *game;

class Game : public Napi::ObjectWrap<Game>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Game(const Napi::CallbackInfo &info); // constructor (default game)
  virtual ~Game();                      // destructor

  /* game play */
  void play_move(const Napi::CallbackInfo &info);
  Napi::Value check_move(const Napi::CallbackInfo &info);
  Napi::Value is_over(const Napi::CallbackInfo &info);
  void restart(const Napi::CallbackInfo &info);
  Napi::Value solve(const Napi::CallbackInfo &info);
  void undo(const Napi::CallbackInfo &info);
  void redo(const Napi::CallbackInfo &info);

  /* game accessors */
  Napi::Value get_square(const Napi::CallbackInfo &info);
  Napi::Value get_state(const Napi::CallbackInfo &info);
  Napi::Value get_flags(const Napi::CallbackInfo &info);
  Napi::Value is_blank(const Napi::CallbackInfo &info);
  Napi::Value is_lightbulb(const Napi::CallbackInfo &info);
  Napi::Value is_black(const Napi::CallbackInfo &info);
  Napi::Value get_black_number(const Napi::CallbackInfo &info);
  Napi::Value is_marked(const Napi::CallbackInfo &info);
  Napi::Value is_lighted(const Napi::CallbackInfo &info);
  Napi::Value has_error(const Napi::CallbackInfo &info);
  Napi::Value nb_rows(const Napi::CallbackInfo &info);
  Napi::Value nb_cols(const Napi::CallbackInfo &info);
  Napi::Value is_wrapping(const Napi::CallbackInfo &info);


private:
  game g;
};

#endif
