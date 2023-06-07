import CanvasInterface from "./CanvasInterface";

export default class Canvas implements CanvasInterface {
    private color: string
    private canvas: CanvasRenderingContext2D

    constructor(canvas: CanvasRenderingContext2D) {
        this.canvas = canvas
        this.color = 'black'
        this.canvas.lineWidth = 10
    }

    DrawEllipse(x: number, y: number, xRadius: number, yRadius: number): void {
        this.canvas.ellipse(x, y, xRadius, yRadius, 0, 0, 360)
        this.canvas.stroke()
    }

    DrawRectangle(x: number, y: number, width: number, height: number): void {
        this.canvas.fillRect(x, y, width, height)
    }

    SetColor(color: string): void {
        this.canvas.fillStyle = color
        this.canvas.strokeStyle = color
    }
}