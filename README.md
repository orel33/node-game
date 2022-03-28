# Game Wrapper for Node.js

Ce code illustre comment construire une version web de notre jeu, en s'appuyant
sur la bibliothèque *game* écrite en langage C. Pour ce faire, nous utilisons la
technologie *Node.js* et le langage *JavaScript*, en important notre
bibliothèque *game* sous forme d'un module *addon*.

Voici les principaux fichiers :

* [package.json](package.json)
* [binding.gyp](binding.gyp)
* [gamew.hh](gamew.hh)
* [gamew.cc](gamew.cc)
* [test.js](test.js)
* ...

## Installation

Voici comment effectuer l'installation de *Node.js* en tant qu'admin sous Linux / Debian :

```bash
sudo apt install nodejs
sudo npm install -g node-gyp
```

On peut vérifier le numéro de version des principaux logiciels installés comme
ceci. Par exemple sur Ubuntu 22 :

```bash
$ node -v                       # v12.22.9
$ node-gyp -v                   # v9.0.0
$ node -p process.versions.v8   # 7.8.279.23-node.56
```

**Nota Bene** : Au CREMI, *Node.js* est déjà installé en version 10 et
*node-gyp* en version 6.1, et le moteur d'exécution *v8* est installé en version
6.8.

## Compilation

Pour tout compiler en une seule ligne :

```bash
npm install
```

Sinon, pour compiler à la main les fichiers source, il faut faire :

```bash
node-gyp configure
node-gyp build
```

ou pour compiler en mode *verbose* :

```bash
node-gyp configure
cd build
make V=1
```

On peu ensuite lancer le programme `test.js` :

```bash
node test.js
```

## Documentation (à trier)

Javascript :

* Langage : <https://javascript.info/>
* Javascript Web: <https://www.w3schools.com/js/>
* Learn Node.js: <https://nodejs.dev/learn>

N-API & node-addon-api :

* <https://github.com/nodejs/node-addon-api>
* Exemples : <https://github.com/nodejs/node-addon-examples>
* API : <https://github.com/nodejs/node-addon-api#api>

Tutoriels :

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
* Swig : <http://www.swig.org/Doc3.0/Javascript.html>
* <https://nodejs.org/api/n-api.html#node-api>
* <https://nodejs.org/api/n-api.html>

