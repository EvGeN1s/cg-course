"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Canvas = /** @class */ (function () {
    function Canvas(canvas) {
        this.canvas = canvas;
        this.color = 'black';
    }
    Canvas.prototype.DrawEllipse = function (x, y, xRadius, yRadius) {
        this.canvas.ellipse(x, y, xRadius, yRadius, 0, 0, 360);
    };
    Canvas.prototype.DrawRectangle = function (x, y, width, height) {
        this.canvas.fillRect(x, y, width, height);
    };
    Canvas.prototype.SetColor = function (color) {
        this.canvas.fillStyle = color;
    };
    return Canvas;
}());
exports.default = Canvas;
//# sourceMappingURL=Canvas.js.map