-- Generate a test for the OPT command :

_in = io.open("divers.3.in","w")
_out = io.open("divers.3.out","w")

if _in and _out then
	-- choose one time to be optimal, then fill the rest of the table with R traffic
	numberOfTrajectSensors = 5
	numberOfOtherSensors = 0

	startHour = 12
	endHour = 14

	numberOfMinutes = (endHour-startHour) * 60
	optimalStartTime = 119
	for sensor=1,numberOfTrajectSensors do
		for minute=0,numberOfMinutes*2 do
			_in:write(	"ADD " ..
						sensor ..
						" 1984 1 1 " ..
						math.floor(minute / 60) + startHour ..  -- HOURS
						" " ..
						minute%60 ..
						" 1 ");
			if minute == optimalStartTime+sensor-1 then
				_in:write("V")
			else
				_in:write("R")
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
	_out:write("1 " .. math.floor(optimalStartTime / 60) + startHour.. " " .. optimalStartTime%60 .. " " .. numberOfTrajectSensors )

end
