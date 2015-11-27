-- Generate a test for the OPT command :

_in = io.open("testOPT.in","w")
_out = io.open("testOPT.out","w")



if _in and _out then
	-- choose one time to be optimal, then fill the rest of the table with R traffic
	numberOfTrajectSensors = 5
	numberOfOtherSensors = 0

	startHour = 22
	endHour = 24

	numberOfMinutes = (endHour-startHour) * 60
	optimalStartTime = math.random(0,numberOfMinutes-1)
	for sensor=1,numberOfTrajectSensors do
		for minute=0,numberOfMinutes*2 do
			_in:write(	"ADD " ..
						sensor ..
						" 1984 1 " ..
						(math.floor((startHour + math.floor(minute / 60))/24)%7)+1 ..
						" " ..
						(math.floor(minute / 60) + startHour)%24 ..  -- HOURS
						" " ..
						minute%60 ..
						" " .. 
						(math.floor((startHour + math.floor(minute / 60))/24)%7)+1);
			if minute == optimalStartTime+sensor-1 then
				_in:write(" V")
			else
				_in:write(" R")
			end
			_in:write("\n")

			
		end
	end

	_in:write("OPT 1 " .. startHour .. " " .. endHour .. " " .. numberOfTrajectSensors)

	for i=1,numberOfTrajectSensors do
		_in:write( " " .. i)
	end

	_in:write("\nEXIT")

	-- Write the expected result
	_out:write((math.floor((startHour + math.floor(numberOfTrajectSensors / 60))/24)%7)+1 .. " " .. math.floor(optimalStartTime / 60) + startHour.. " " .. optimalStartTime%60 .. " " .. numberOfTrajectSensors )

end
