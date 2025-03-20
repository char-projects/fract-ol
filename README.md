<div align="center">
	<h1>🌌 fract-ol</h1>
	<p><b>The <code>fract-ol</code> project from the 42 School is one of the three graphical projects of the cursus. It teaches you about manipulating a low-level graphic library, advanced math, and more.</b></p>
</div>
<div align="center">
   <img src="https://github.com/user-attachments/assets/d08b787a-87a7-4966-8f46-f5e09b702015" height="300">
</div>

## 📌 Features

<li>Multiple fractals: Mandelbrot, Julia, BurningShip</li>
<li>Increase and decrease max iteration for shape calculation</li>
<li>Zoom and unzoom</li>
<li>Move around with the arrow keys or W, A, S, D</li>
<li>Different color patterns</li>


## 🛠 Installation

Clone the repository, cd into it, then run:
```
make
```
This will generate the fractol executable.

## 🚀 Usage

Run the program with one of the available fractals:
```
./fractol mandelbrot
```
```
./fractol julia
```
```
./fractol burningship
```
For the Julia set, you can specify custom parameters:

./fractol julia <real_part> <imaginary_part>

Example:

./fractol julia -0.8 0.156

## 🎮 Controls

| Action                | Key               |
|----------------------|-------------------|
| Move Up              | `W` / `↑`         |
| Move Down            | `S` / `↓`         |
| Move Left            | `A` / `←`         |
| Move Right           | `D` / `→`         |
| Zoom In              | Scroll Up / `+`   |
| Zoom Out             | Scroll Down / `-` |
| Increase Iterations  | `I`               |
| Decrease Iterations  | `K`               |
| Change Color Scheme  | `C`               |
| Reset View           | `R`               |
| Quit                 | `ESC`             |
