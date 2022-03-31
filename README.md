# Game Wrapper for Node.js

Ce projet illustre comment construire une version web de notre jeu, en
s'appuyant sur la bibliothèque *game* native écrite en langage C. Pour ce faire,
nous utilisons la technologie *Node.js* et le langage *JavaScript*, en important
notre bibliothèque *game* sous forme d'un module *addon* natif.

Voici les principaux fichiers :

* [package.json](package.json) : npm description of this module
* [binding.gyp](binding.gyp) : used by node-gyp to compile the C code
* [gamew.hh](gamew.hh) + [gamew.cc](gamew.cc) : the C++ wrapper code of game library
* [game/](game/) : the C game library, provided as static x64 linux binary
* [test.js](test.js) : test code

*à compléter...*

## Documentation (à trier)

Javascript :

* Langage : <https://javascript.info/>
* Langage JavaScript : <https://developer.mozilla.org/fr/docs/Web/JavaScript>
* Javascript Web: <https://www.w3schools.com/js/>
* Learn Node.js: <https://nodejs.dev/learn>

N-API & node-addon-api :

* <https://github.com/nodejs/node-addon-api>
* Exemples : <https://github.com/nodejs/node-addon-examples>
* API : <https://github.com/nodejs/node-addon-api#api>

Tutoriels :

* first project : <https://nodejs.github.io/node-addon-examples/getting-started/first/>
* <https://github.com/a7ul/blog-addons-example>
* <https://medium.com/jspoint/a-simple-guide-to-load-c-c-code-into-node-js-javascript-applications-3fcccf54fd32>
* <https://koistya.medium.com/how-to-call-c-c-code-from-node-js-86a773033892>
* <https://www.adaltas.com/fr/2018/12/12/les-modules-natifs-node-js-n-api/>
* <https://nodejs.medium.com/building-modern-native-add-ons-for-node-js-in-2020-cd3992c68e0>
* <https://medium.com/ai-innovation/a-guide-for-javascript-developers-to-build-c-add-ons-with-node-addon-api-28c84a0c0cb1>
* <https://askcodez.com/comment-puis-je-utiliser-une-bibliotheque-c-de-node-js.html>

Divers :

* <https://gyp.gsrc.io/docs/UserDocumentation.md>
* <https://github.com/nodejs/node-addon-api/blob/main/doc/node-gyp.md>
* <https://github.com/nodejs/node-gyp>
* Swig : <http://www.swig.org/Doc3.0/Javascript.html> [deprecated ?]
* <https://nodejs.org/api/n-api.html#node-api>
* <https://nodejs.org/api/n-api.html>



---
aurelien.esnard@u-bordeaux.fr