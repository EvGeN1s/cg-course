import CanvasInterface from "../Canvas/CanvasInterface";

export function drawF(canvas: CanvasInterface, x: number, y: number): void {
    canvas.DrawEllipse(x + 50, y + 30, 50, 30)
    canvas.DrawRectangle(x + 40, y, 20, 100)
}

export function drawE(canvas: CanvasInterface, x: number, y: number): void {
    canvas.DrawRectangle(x, y, 25, 100)
    canvas.DrawRectangle(x + 25, y, 50, 20)
    canvas.DrawRectangle(x + 25, y + 40, 50, 20)
    canvas.DrawRectangle(x + 25, y + 80, 50, 20)
}

export function drawD(canvas: CanvasInterface, x: number, y: number): void {
    canvas.DrawRectangle(x + 10, y, 70, 20)
    canvas.DrawRectangle(x + 10, y + 20, 20, 40)
    canvas.DrawRectangle(x + 60, y + 20, 20, 40)
    canvas.DrawRectangle(x, y + 60, 90, 20)
    canvas.DrawRectangle(x, y + 80, 20, 20)
    canvas.DrawRectangle(x + 70 , y + 80, 20, 20)
}