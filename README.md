<h1 style="text-align:center">Complexity and Recusivity - Exam</h1>

<div style="text-align:justify"></div>

<h2>Method</h2>

<div style="text-align:justify">
The algorithm explores the entirity of the tree of possibilities. Due to the fact that it needs to depend on a recursive structure, it will be a depth-first algorithm. Each node will define the current state of the search and as such will depend on the current look of the grid, the shape that we tested to make that grid and the shapes that are still to be tested.

<dl>

<dt><b>Node Creation</b></dt>
<dd style="text-align:justify">
For each node when it is first created, we first check if the piece fits (check if Null terminal) and if it does we update our current grid with the current piece. We then check if it is a positive terminal or negative terminal node. If it is none of the above then for each remaining shape (and all it's orientations) we create a node with the current node as the parent.
</dd>

<dt><b>Terminal Nodes</b></dt>
<dd style="text-align:justify">
<b>Positive Terminal - </b>All the pieces are on the board and we have one month, one number and one day.
<dd style="text-align:justify">
<b>Negative Terminal - </b>All the pieces are on the board but we don't have one month, one number and one day.
</dd>
<dd style="text-align:justify">
<b>Null Terminal - </b>The piece we are trying to fit on the board just doesn't fit. We can't go further with this node.
</dd>

</dl>

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