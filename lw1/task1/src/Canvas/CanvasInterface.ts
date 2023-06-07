export default interface CanvasInterface {
    DrawRectangle(x: number, y: number, width: number, height: number): void
    DrawEllipse(x: number, y: number, xRadius: number, yRadius: number): void

    SetColor(color: string): void
}