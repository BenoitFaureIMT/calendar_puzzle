<h1 style="text-align:center">Complexity and Recusivity - Exam</h1>

<div style="text-align:justify"></div>

<h2>Method</h2>

<div style="text-align:justify">
The algorithm explores the entirity of the tree of possibilities. Due to the fact that it needs to depend on a recursive structure, it will be a depth-first algorithm. Each node will define the current state of the search and as such will depend on the current look of the grid, the shape that we tested to make that grid and the shapes that are still to be tested.


</div>

<h2>Data Structures</h2>

<dl>

<dt><b>Grid -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">int</b> w - width of grid</dd>
<dd><b style="color:#5DADE2">int</b> h - height of grid</dd>
<dd><b style="color:#5DADE2">int</b> data[] - data points of the grid</dd>

<dt><b>Node -</b> Struct containing:</dt>


<dt><b>NodeList -</b> Struct containing:</dt>

<dt><b>NodeList_List -</b> Struct containing:</dt>

</dl>