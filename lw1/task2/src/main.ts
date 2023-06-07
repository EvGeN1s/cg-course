const pathToColor = new Map<number, string>([
    [0, "red"],
    [1, "orange"],
    [2, "yellow"],
    [3, "green"],
    [4, "magenta"],
    [5, "blue"],
    [6, "purple"]
])

function drawEllipse(canvas: CanvasRenderingContext2D, x: number, y: number, xRadius: number, yRadius: number, angle: number, color: string): void {
    canvas.fillStyle = color
    canvas.beginPath()
    canvas.ellipse(x, y, xRadius, yRadius, angle, 0, 360)
    canvas.closePath()
    canvas.fill()
}

function drawPath(canvas: CanvasRenderingContext2D, x: number, y: number, angle: number, color: string): void {
    drawEllipse(canvas, x, y, 50, 100, angle, color)
}

function drawPaths(canvas: CanvasRenderingContext2D, x: number, y: number, pathsCount: number, radius: number): void {
    let angleMove: number = Math.PI * 2 / pathsCount
    let figureAngle: number = 0
    let radiusAngle: number = Math.PI / 2
    for (let i = 0; i < pathsCount; i++) {
        let color = pathToColor.get(i) ?? "black"

        let xMove: number = Math.cos(radiusAngle) * radius
        let yMove: number = Math.sin(radiusAngle) * radius
        drawPath(canvas, x + xMove, y - yMove, figureAngle, color)
        figureAngle -= angleMove
        radiusAngle += angleMove
    }
}

function drawFlower(canvas: CanvasRenderingContext2D, x: number, y: number): void {
    const pathsCount: number = 7
    const radius: number = 120

    canvas.fillStyle = "green"
    canvas.fillRect(x -20, y, 40, 450)
    drawEllipse(canvas, x - 45,y + 400, 45, 90, Math.PI * 3 / 4, canvas.fillStyle)
    drawEllipse(canvas, x + 35,y + 400, 30, 70, Math.PI / 4, canvas.fillStyle)

    drawPaths(canvas, x, y, pathsCount, radius)
    drawEllipse(canvas, x, y, 50, 50, 0, "white")
}

function main() {
    const canvasElm: HTMLCanvasElement | null = <HTMLCanvasElement>document.getElementById('canvas')
    const canvasCtx: CanvasRenderingContext2D | null | undefined = canvasElm?.getContext('2d')
    if (canvasCtx == null) {
        console.error("Canvas context not found")
        return
    }
    drawFlower(canvasCtx, 400, 350)
}

main()