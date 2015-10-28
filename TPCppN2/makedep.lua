-- MAKEDEP.LUA
-- BY ESPEUTE CLEMENT

-- Configuration variables :
SRC_FOLDER = "src/"
DEP_FOLDER = "dep/"
OBJ_FOLDER = "build/"
DEP_FILENAME = "Deps.dep"

-- Create .dep file
file = io.open(DEP_FOLDER..DEP_FILENAME,"w")
file:write("#File generated with makedep.lua\n")

function aWrite(a,file)
	file:write(SRC_FOLDER..a.." ")
end


for _,v in ipairs(arg) do
	string.gsub(v,"(.-).cpp",function(a) fileName = a end)
	
	-- Write 'obj/exemple.o : '
	file:write(OBJ_FOLDER..fileName..".o".." : ")

	-- Write 'src/exemple.cpp src.exemple.h'
	file:write(SRC_FOLDER..fileName..".cpp "..SRC_FOLDER..fileName..".h ")

	-- Extract and write all the files included in the file
	for line in io.lines(SRC_FOLDER..fileName..".cpp") do
		string.gsub(line,"#include \"(.-)\"", function(a) aWrite(a,file) end);
	end

	for line in io.lines(SRC_FOLDER..fileName..".h") do
		string.gsub(line,"#include \"(.-)\"", function(a) aWrite(a,file) end);
	end

	file:write("\n\n")

end