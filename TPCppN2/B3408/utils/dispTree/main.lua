--[[ ============================
This is a binary tree visualization tool
written in LUA using the LÖVE2d framework.
It parses the "data.lua" file located in the
same folder and displays it on the screen.
The program allows zoom and pan in order to
see the tree properly.
=================================]]--

-- Load the data located in the data.lua file.
tab = require "data"

-- The position of the root of the tree.
x_init = 400
y_init = 0

-- love.draw is a function that is periodically called
-- by the LÖVE framework
function love.draw()
	-- Displays the controls in the top left corner. 
	love.graphics.print("p : zoom +",0,0)
	love.graphics.print("m : zoom -",0,15)
	love.graphics.print("left,up,right,down : move around",0,30)
	love.graphics.print("r : reload data",0,45)

	-- Draw the tree.
	drawNode(tab,x_init,y_init)	
end

-- The distance between the first 2 nodes
factor = 200;

-- The zoom level
zoom = 1;

-- Draw a node and its children.
-- node : the node to draw
-- x : the x position of the node on the screen
-- y : the y position of the node on the screen
-- depth : where we are un the subtree
function drawNode( node,x,y,depth)

	-- Don't draw the node if it doesn't exist 
	if node ~= nil then
		-- initialize the variables
		x = x or 0;
		y = y or 0;
		depth = depth or 1;

		-- Set the color to white
		love.graphics.setColor(255,255,255)

		-- Print this node id and height
		love.graphics.print(node.id..','..node.height,x,y)
		
		-- Set the color of the lines to be gray
		love.graphics.setColor(127,127,127)

		-- If there is a left child node, draw a line to it
		if node.left ~= nil then
		love.graphics.line(x,y,x-factor*zoom/depth,y+factor*zoom/depth)
		end
		-- Idem for the right
		if node.right ~= nil then
		love.graphics.line(x,y,x+factor*zoom/depth,y+factor*zoom/depth)
		end

		love.graphics.setColor(255,255,255)
		
		-- Draw the left node (even if it's nil)
		drawNode(node.left,x-factor*zoom/depth,y+factor*zoom/depth,depth*2)
		
		-- Idem for the right
		drawNode(node.right,x +factor*zoom/depth,y+factor*zoom/depth,depth*2)
	end
end

-- Handle the key presses
function love.keypressed( k )
	if k == 'p' then
	zoom =zoom * 2
	x_init = x_init * 2 - 400
	y_init = y_init * 2 - 300
	end
	if k == 'm' then
	zoom =zoom / 2
	x_init = x_init / 2 + 200
	y_init = y_init / 2 + 150
	end
	if k == "left" then
		x_init = x_init + 50
	end
	if k == "right" then
		x_init = x_init - 50
	end
	if k == "up" then
		y_init = y_init + 50
	end
	if k == "down" then
		y_init = y_init - 50
	end
	if k == "r" then
		f = love.filesystem.load("data.lua")
		tab = f()
	end
end