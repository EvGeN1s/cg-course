"use strict";
exports.__esModule = true;
exports.hello = void 0;
var world = 'world';
function hello(word) {
    if (word === void 0) { word = world; }
    return "Hello ".concat(world, "! ");
}
exports.hello = hello;
