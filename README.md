# Fract-ol 42 🌀
<!-- Welcome to the **mathness**!   -->
The purpose of this project is to render beautiful, fully-interractional fractals of the Julia and Mandelbrot sets from scratch.

![zoom](assets/zoom.gif)
![jiter](assets/jiter.gif)

## WHAT IS A FRACTAL?
In mathematics, a fractal is a geometric shape containing detailed structure at arb...
basically crazy math shi creating crazy visual shi. Read some [wikipedia](https://en.wikipedia.org/wiki/Fractal) or something

![bl](assets/bl1.png)

## How to run?
### Clone repo and compile
```bash
git clone git@github.com:sneshev/fract-ol_42.git fractol
cd fractol
make
```
### Run different sets
``` 
./fractol mandelbrot
```
``` 
./fractol julia
```
``` 
./fractol julia c_real c_imag 
```
``` 
./fractol bship 
```
<p align="center"><i>ℹ️ Controls show up in the terminal on program start</i></p>

## Creating the project

Fract-ol is built **entirely in C**, using **MiniLibX** for graphics and event handling.  
It combines **math, logic, and visuals** — turning pure math formulas into interactive art.
- Low-level **graphics programming** and rendering
- **Complex number math** for Mandelbrot, Julia & Burning Ship sets
- Handling **floating-point precision** for deep, stable zooms
- **Keyboard/mouse events** -> real-time zoom, movement, iteration control, and color change
 
![bship](assets/bship.png)
![Mandelbrot2](assets/m2.png)
![univrs](assets/univrs.gif)
