FILES = testbench_compteur.vhdl fulladder.vhdl adder.vhdl clock.vhdl registre1bit.vhdl registrenbits.vhdl compteur.vhdl
TARGET = testbench_compteur
TARGET_NAME = testbench_compteur.out
VCD = testbench_compteur.vcd

ALL : $(TARGET_NAME) makefile
	./$(TARGET_NAME) --stop-time=60ns --vcd=$(VCD)
	gtkwave $(VCD)

$(TARGET_NAME) : $(FILES)
	ghdl -e $(TARGET)
	mv $(TARGET) $(TARGET_NAME)

%.vhdl :
	ghdl -a $@

clean :
	rm *.out *.o *.cf *.vcd
