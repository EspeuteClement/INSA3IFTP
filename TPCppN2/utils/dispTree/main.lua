tab = require "data"

x_init = 400
y_init = 0
function love.draw()
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
		
		if node.left ~= nil then
		love.graphics.line(x,y,x-factor*zoom/depth,y+factor*zoom/depth)
		end
		if node.right ~= nil then
		love.graphics.line(x,y,x+factor*zoom/depth,y+factor*zoom/depth)
		end
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
end