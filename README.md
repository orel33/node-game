# Demo Web

Ce code illustre comment construire une version web de notre jeu, en s'appuyant
sur la bibliothèque *game* écrite en langage C. Pour ce faire, nous utilisons la
technologie *node.js* et le langage *JavaScript*, en important notre
bibliothèque *game* sous forme d'un module *gamew* pour *node.js*.

## Description

...

## Documentation sur node-addon-api

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

Divers :

* <https://gyp.gsrc.io/docs/UserDocumentation.md>
* <https://github.com/nodejs/node-addon-api/blob/main/doc/node-gyp.md>
* <https://github.com/nodejs/node-gyp>
* Swig : <http://www.swig.org/Doc3.0/Javascript.html>

## Compilation

En une ligne :

```bash
npm install
```

Sinon, pour compiler à la main les fichiers source, il faut faire `node-gyp
configure build` ou pour compiler en mode *verbose* :

```bash
node-gyp configure
cd build 
make V=1
```

On peu ensuite lancer le test : `node test.js`.
