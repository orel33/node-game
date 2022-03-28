// Test Game

var addon = require('bindings')('game');

var g = new addon.Game();

console.log(g.get_square(0, 0));
console.log(g.check_move(0, 0, 1));
console.log(g.play_move(0, 0, 1));
console.log(g.get_square(0, 0));
console.log(g.restart());
console.log(g.get_square(0, 0));

// EOF