/**
 * @file test.js
 * @brief Test of Game Wrapper for Node.js
 * @author aurelien.esnard@u-bordeaux.fr
 * @copyright University of Bordeaux. All rights reserved, 2022.
 **/

var addon = require('bindings')('game');

/* ******************** Square Enum ******************** */

const S_BLANK = 0;
const S_LIGHTBULB = 1;
const S_MARK = 2;
const S_BLACK = 8;
const S_BLACK0 = S_BLACK + 0;
const S_BLACK1 = S_BLACK + 1;
const S_BLACK2 = S_BLACK + 2;
const S_BLACK3 = S_BLACK + 3;
const S_BLACK4 = S_BLACK + 4;
const S_BLACKU = S_BLACK + 5;
const F_LIGHTED = 16;
const F_ERROR = 32;

/* ******************** Print Square ******************** */

function get_square_as_char(g, i, j) {
    if (g.is_marked(i, j)) return "-";
    else if (g.is_lightbulb(i, j)) return "*";
    else if (g.is_black(i, j)) {
        var n = g.get_black_number(i, j);
        if(n == -1) return "w";
        else if(n == 0) return "0";
        else if(n == 1) return "1";
        else if(n == 2) return "2";
        else if(n == 3) return "3";
        else if(n == 4) return "4";
    }
    else if (g.is_blank(i, j) && g.is_lighted(i, j)) return ".";
    else if (g.is_blank(i, j)) return " ";
    return "?";
}

/* ******************** Print Game ******************** */

function print(g) {
    let nb_rows = g.nb_rows();
    let nb_cols = g.nb_cols();

    let sep = " ";
    for (let j = 0; j < nb_cols; j++) sep += "-";

    console.log(sep);
    for (let i = 0; i < nb_rows; i++) {
        let line = "|";
        for (let j = 0; j < nb_cols; j++) {
            x = get_square_as_char(g, i, j);
            line += x;
        }
        line += "|";
        console.log(line);
    }
    console.log(sep);

}

/* ******************** Main ******************** */

let squares = [
    S_BLANK, S_BLANK, S_BLACK1, S_BLANK, S_BLANK, S_BLANK, S_BLANK,  /* row 0 */
    S_BLANK, S_BLANK, S_BLACK2, S_BLANK, S_BLANK, S_BLANK, S_BLANK,  /* row 1 */
    S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLACKU, S_BLACK2, /* row 2 */
    S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLANK,   /* row 3 */
    S_BLACK1, S_BLACKU, S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLANK, /* row 4 */
    S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLACK2, S_BLANK, S_BLANK,  /* row 5 */
    S_BLANK, S_BLANK, S_BLANK, S_BLANK, S_BLACKU, S_BLANK, S_BLANK   /* row 6 */
];

var g = new addon.Game();  // create default game, if no arguments are provided
// var g = new addon.Game(7, 7, squares, false);

print(g);
// play solution moves
g.play_move(0, 0, S_LIGHTBULB);
g.play_move(1, 1, S_LIGHTBULB);
g.play_move(2, 2, S_LIGHTBULB);
g.play_move(0, 3, S_LIGHTBULB);
g.play_move(1, 6, S_LIGHTBULB);
g.play_move(3, 6, S_LIGHTBULB);
g.play_move(4, 4, S_LIGHTBULB);
g.play_move(5, 0, S_LIGHTBULB);
g.play_move(5, 5, S_LIGHTBULB);
g.play_move(6, 1, S_LIGHTBULB);
print(g);
console.log("game is over? " + g.is_over());
delete g;

// EOF