import CanvasInterface from "../Canvas/CanvasInterface";

export default class Shape {
    private _x: number
    private _y: number

    private _drawStrategy:  (canvas: CanvasInterface, x: number, y: number) => void
    private _color: string

    constructor(x: number, y: number, drawStrategy: (canvas: CanvasInterface, x: number, y: number) => void, color: string) {
        this._x = x
        this._y = y

        this._drawStrategy = drawStrategy
        this._color = color
    }

    set x(num: number) {
        this._x = num
    }

    set y(num: number) {
        this._y = num
    }

    draw(canvas: CanvasInterface): void {
        canvas.SetColor(this._color)
        this._drawStrategy(canvas, this._x, this._y)
    }
}