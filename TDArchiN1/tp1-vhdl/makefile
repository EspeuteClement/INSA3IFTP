FILES = testbench_addersub.vhdl fulladder.vhdl adder.vhdl clock.vhdl registre1bit.vhdl registrenbits.vhdl compteur.vhdl addersub.vhdl
TARGET = testbench_addersub
TARGET_NAME = testbench_addersub.out
VCD = testbench_addersub.vcd

ALL : $(TARGET_NAME) makefile
	out/$(TARGET_NAME) --stop-time=20ns --vcd=out/$(VCD)
	gtkwave out/$(VCD)

$(TARGET_NAME) : $(FILES)
	cd out && ghdl -e $(TARGET) && cd ..
	cd out && mv $(TARGET) $(TARGET_NAME) && cd ..

%.vhdl :
	cd out && ghdl -a ../$@ && cd ..

clean :
	rm *.out *.o *.cf *.vcd
