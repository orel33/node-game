#ifndef GAMEW_H
#define GAMEW_H

#include <napi.h>

typedef struct game_s *game;

class Game : public Napi::ObjectWrap<Game>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Game(const Napi::CallbackInfo &info); // constructor (default game)
  ~Game();                              // destructor

  // game game_new(square* squares);
  // game game_new_empty(void);
  // game game_copy(cgame g);
  // void game_delete(game g);
  // bool game_equal(cgame g1, cgame g2);

public:
  // void game_set_square(game g, uint i, uint j, square s);
  // square game_get_square(cgame g, uint i, uint j);
  // square game_get_state(cgame g, uint i, uint j);
  // square game_get_flags(cgame g, uint i, uint j);
  // bool game_is_blank(cgame g, uint i, uint j);
  // bool game_is_lightbulb(cgame g, uint i, uint j);
  // bool game_is_black(cgame g, uint i, uint j);
  // int game_get_black_number(cgame g, uint i, uint j);
  // bool game_is_marked(cgame g, uint i, uint j);
  // bool game_is_lighted(cgame g, uint i, uint j);

  // bool game_has_error(cgame g, uint i, uint j);
  // bool game_check_move(cgame g, uint i, uint j, square s);
  // void game_play_move(game g, uint i, uint j, square s);
  // void game_update_flags(game g);
  // bool game_is_over(cgame g);
  // void game_restart(game g);

  Napi::Value check_move(const Napi::CallbackInfo &info);
  void play_move(const Napi::CallbackInfo &info);
  // void update_flags(const Napi::CallbackInfo &info);
  Napi::Value is_over(const Napi::CallbackInfo &info);
  void restart(const Napi::CallbackInfo &info);
  // void set_square(const Napi::CallbackInfo &info);
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

  // ...

  // void game_print(cgame g);
  // game game_default(void);
  // game game_default_solution(void);
  // game game_new_ext(uint nb_rows, uint nb_cols, square* squares, bool wrapping);
  // game game_new_empty_ext(uint nb_rows, uint nb_cols, bool wrapping);
  // uint game_nb_rows(cgame g);
  // uint game_nb_cols(cgame g);
  // bool game_is_wrapping(cgame g);
  // void game_undo(game g);
  // void game_redo(game g);
  // game game_load(char* filename);
  // void game_save(cgame g, char* filename);
  // bool game_solve(game g);
  // uint game_nb_solutions(cgame g);

private:
  game g;
};

#endif
