FILES = clock.vhdl
TARGET = clock_generator
TARGET_NAME = clock.out
VCD = clock.vcd

ALL : $(TARGET_NAME) makefile
	./$(TARGET_NAME) --stop-time=20ns --vcd=$(VCD)
	gtkwave $(VCD)

$(TARGET_NAME) : $(FILES)
	ghdl -e $(TARGET)
	mv $(TARGET) $(TARGET_NAME)

%.vhdl :
	ghdl -a $@

clean :
	rm *.out *.o *.cf *.vcd
