

tab = require "data"

x_init = 400
y_init = 0
function love.draw()
	love.graphics.print("p : zoom +",0,0)
	love.graphics.print("m : zoom -",0,15)
	love.graphics.print("left,up,right,down : move around",0,30)
	love.graphics.print("r : reload data",0,45)

	drawNode(tab,x_init,y_init)	
end

factor = 200;
zoom = 1;
function drawNode( node,x,y,depth)
	if node ~= nil then
		x = x or 0;
		y = y or 0;
		depth = depth or 1;
		love.graphics.print(node.id..','..node.height,x,y)
		
		love.graphics.setColor(127,127,127)
		if node.left ~= nil then
		love.graphics.line(x,y,x-factor*zoom/depth,y+factor*zoom/depth)
		end
		if node.right ~= nil then
		love.graphics.line(x,y,x+factor*zoom/depth,y+factor*zoom/depth)
		end
		love.graphics.setColor(255,255,255)
		drawNode(node.left,x-factor*zoom/depth,y+factor*zoom/depth,depth*2)
		
		drawNode(node.right,x +factor*zoom/depth,y+factor*zoom/depth,depth*2)
	end
end

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
		x_init = x_init - 50
	end
	if k == "right" then
		x_init = x_init + 50
	end
	if k == "up" then
		y_init = y_init - 50
	end
	if k == "down" then
		y_init = y_init + 50
	end
	if k == "r" then
		f = love.filesystem.load("data.lua")
		tab = f()
	end
end