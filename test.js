/**
 * @file test.js
 * @brief Test of Game Wrapper for Node.js
 * @author aurelien.esnard@u-bordeaux.fr
 * @copyright University of Bordeaux. All rights reserved, 2022.
 **/

var addon = require('bindings')('game');

// basic tests
// console.log(g.get_square(0, 0));
// console.log(g.check_move(0, 0, 1));
// console.log(g.play_move(0, 0, 1));
// console.log(g.get_square(0, 0));
// console.log(g.restart());
// console.log(g.get_square(0, 0));

/* ******************** Print Game ******************** */

function print(g) {
    let nb_rows = g.nb_rows();
    let nb_cols = g.nb_cols();

    for (let i = 0; i < nb_rows; i++) {
        let line = "";
        for (let j = 0; j < nb_cols; j++) {
            x = g.get_square_str(i, j);
            line += x + " ";
        }
        console.log(line);
    }

}

/* ******************** Main ******************** */

var g = new addon.Game();
g.play_move(0, 0, 1);
print(g);
delete g;

// EOF