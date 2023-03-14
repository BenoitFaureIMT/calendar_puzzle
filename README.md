<h1 style="text-align:center">Complexity and Recusivity - Exam</h1>

<div style="text-align:justify"></div>

<h2>Method</h2>

<div style="text-align:justify">
The algorithm explores the entirity of the tree of possibilities. Due to the fact that it needs to depend on a recursive structure, it will be a depth-first algorithm. Each node will define the current state of the search and as such will depend on the current look of the grid, the shape that we tested to make that grid and the shapes that are still to be tested.
<br><br>

Question: Do we want to return the date + path to it or just the date?

<dl>

<dt><b>Grid Creation</b></dt>
<dd style="text-align:justify">
Grid created from file (...). Each point in the grid will be represented by a number, the number are defined as followed:
</dd>
<dd><b>0 - </b>Occupied position, here there is a piece or it is not a part of the grid (as grid is not perfectly square)</dd>
<dd><b>1 - </b>Month position</dd>
<dd><b>2 - </b>Number position</dd>
<dd><b>3 - </b>Day position</dd>

So I fucked up... I made the grid with bools pretty much...

<dt><b>Node Creation</b></dt>
<dd style="text-align:justify">
For each node when it is first created, we first check if the piece fits (check if Null terminal) and if it does we update our current grid with the current piece. We then check if it is a positive terminal or negative terminal node. If it is none of the above then for each remaining shape (and all it's orientations) we create a node with the current node as the parent.
</dd>

<dt><b>Node Routine</b></dt>
<dd style="text-align:justify">
Once a node is created and we have checked it is not terminal. We loop over each square that is left and create a node with it (start routine on it). We take the output of this routine, if it is null then proceed to next node, if it isn't it contains the list of traces of the all solutions we happened upon, we add the trace to the list of traces and continue searching. Once we have looped through every shape we return the list of traces.
<br><br>
Question: When do we add ourselves to the trace? Also do we add ourselves only once at the top of the list of traces (in an attempt to reduce memory usage -> burden on the stack | with this replace node lists by a node tree in recursive function, then have a function to create lists from trees) or just make the lists of traces directly?<br>
Probable answer: Why even make a trace... just return positive terminal nodes and make trace in post process.
</dd>

<dt><b>Terminal Nodes/Grids</b></dt>
<dd style="text-align:justify">
<b>(1) Positive Terminal - </b>All the pieces are on the board and we have one month, one number and one day.
</dd>
<dd style="text-align:justify">
<b>(2) Negative Terminal - </b>All the pieces are on the board but we don't have one month, one number and one day.
</dd>
<dd style="text-align:justify">
<b>(3) Null Terminal - </b>The piece we are trying to fit on the board just doesn't fit. We can't go further with this node.
</dd>
<dd style="text-align:justify">
<b>(0) Not Terminal</b>
</dd>

<dt><b>Shapes</b></dt>
<dd style="text-align:justify">
Shapes can be rotated for 4 dif rotations + mirrored and rotated again.
Shapes will be stored in lists of shapes of the same rotations, and these lists will be stored in lists of lists.
</dd>

</dl>

</div>

<h2>Data Structures</h2>

<dl>

<dt><b>Grid -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">int</b> w - width of grid</dd>
<dd><b style="color:#5DADE2">int</b> h - height of grid</dd>
<dd><b style="color:#5DADE2">int*</b> data[] - data points of the grid</dd>

<dt><b>Node -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">grid*</b> grid</dd>
<dd><b style="color:#5DADE2">int</b> shape_ref - <i>position of shape referenced by the node in the shape array</i></dd>
<dd><b style="color:#5DADE2">IntList*</b> shapes_left - <i>positions of shapes that are left to be explored (only the first of the sets of 4 is referenced)</i></dd>
<dd><b style="color:#5DADE2">Node*</b> parent</dd>

<dt><b>NodeList -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">Node*</b> node</dd>
<dd><b style="color:#5DADE2">NodeList*</b> next</dd>

<dt><b>NodeList_List -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">NodeList*</b> nodelist</dd>
<dd><b style="color:#5DADE2">NodeList_List*</b> next</dd>

<dt><b>IntList -</b> Struct containing:</dt>
<dd><b style="color:#5DADE2">int</b> value</dd>
<dd><b style="color:#5DADE2">IntList*</b> next</dd>

</dl>