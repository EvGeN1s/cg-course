"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var Canvas_1 = __importDefault(require("./Canvas/Canvas"));
function main() {
    var canvasElm = document.getElementById('Canvas');
    var canvasCtx = canvasElm === null || canvasElm === void 0 ? void 0 : canvasElm.getContext('2d');
    if (canvasCtx == null) {
        console.error("Canvas context not found");
        return;
    }
    var canvas = new Canvas_1.default(canvasCtx);
}
main();
//# sourceMappingURL=main.js.map