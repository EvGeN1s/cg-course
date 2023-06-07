import Canvas from "./Canvas/Canvas";
import Shape from "./Shape/Shape";
import {drawD, drawE, drawF} from "./Shape/LetterDrawFunctions";

function main() {
    const canvasElm: HTMLCanvasElement | null = <HTMLCanvasElement>document.getElementById('canvas')
    const canvasCtx: CanvasRenderingContext2D | null | undefined = canvasElm?.getContext('2d')
    if (canvasCtx == null) {
        console.error("Canvas context not found")
        return
    }
    const canvas = new Canvas(canvasCtx)

    const betweenWidth = 200

    const letterF = new Shape(50, 50, drawF, 'red')
    const letterE = new Shape(50 + betweenWidth, 50, drawE, 'blue')
    const letterD = new Shape(50 + betweenWidth * 2, 50, drawD, 'green')

    letterF.draw(canvas)
    letterE.draw(canvas)
    letterD.draw(canvas)
}



/*
const acceleration = -0.5
const startSpeed = 5

function jump(shape: Shape, speed: number): void {
    speed += acceleration
    if (speed == (-startSpeed)) {
        return
    }
}*/

main()