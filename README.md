<h1>FDF</h1>

<h2>Project Overview</h2>
<p>The <code>FDF</code> project is about representing a landscape as a 3D object in which all surfaces are outlined in lines. This is a computer graphics project that uses the MiniLibX library.</p>

<h2>Purpose</h2>
<p>The purpose of this project is to create a wireframe model representation of a 3D landscape by linking various points in space with line segments. This project helps in understanding the basics of graphics programming, including how to place points in space, join them, and view the scene from different perspectives.</p>

<h2>What You Will Learn</h2>
<ul>
    <li>How to use the MiniLibX library for graphics programming.</li>
    <li>How to represent 3D objects in a 2D space using isometric projection.</li>
    <li>How to handle keyboard and mouse events in a graphical application.</li>
    <li>How to manage window and image creation in a graphical application.</li>
</ul>

<h2>Project Contents</h2>

<h3>Mandatory Part</h3>
<p>You must implement the following requirements:</p>
<ul>
    <li>Create a wireframe model representation of a 3D landscape using MiniLibX.</li>
    <li>Read the landscape data from a file with the extension <code>.fdf</code>.</li>
    <li>Display the image in a window, handling window events smoothly (e.g., changing focus, minimizing).</li>
    <li>Pressing ESC must close the window and quit the program cleanly.</li>
    <li>Clicking the window's close button must also close the window and quit the program cleanly.</li>
</ul>

<h4>Function Prototype</h4>
<p><code>int main(int argc, char **argv);</code></p>

<h4>Parameters</h4>
<ul>
    <li><code>argc</code>: The number of arguments passed to the program.</li>
    <li><code>argv</code>: The array of arguments passed to the program.</li>
</ul>

<h4>Return Value</h4>
<ul>
    <li>The function returns 0 on success, and a non-zero value on error.</li>
</ul>

<h4>External Functions</h4>
<p>You are allowed to use the following external functions:</p>
<ul>
    <li><code>open, close, read, write</code></li>
    <li><code>malloc, free, perror, strerror, exit</code></li>
    <li>All functions of the math library (with the <code>-lm</code> compiler option)</li>
    <li>All functions of the MiniLibX</li>
    <li><code>ft_printf</code> and any equivalent functions you coded</li>
</ul>

<h4>Description</h4>
<ul>
    <li>The coordinates of the landscape are stored in a <code>.fdf</code> file passed as a parameter to your program.</li>
    <li>Each number in the file represents a point in space with x, y, and z coordinates.</li>
    <li>The program must render the landscape in isometric projection.</li>
</ul>

<h3>Bonus Part</h3>
<p>The bonus part includes additional features:</p>
<ul>
    <li>Include one extra projection (such as parallel or conic).</li>
    <li>Implement zoom in and out functionality.</li>
    <li>Allow translation (moving) of the model.</li>
    <li>Allow rotation of the model.</li>
    <li>Add an additional bonus feature of your choice.</li>
</ul>
<p>The bonus part will only be assessed if the mandatory part is perfect.</p>

<h2>Usage</h2>
<p>To use the <code>fdf</code> program, compile it using the provided Makefile and run it with a valid <code>.fdf</code> file as an argument. The program will display the 3D landscape in a window.</p>

<h2>Conclusion</h2>
<p>The <code>FDF</code> project is an excellent opportunity to learn about graphics programming and 3D modeling. By completing this project, you will gain valuable skills in using graphical libraries, managing 3D coordinates, and creating interactive graphical applications.</p>
