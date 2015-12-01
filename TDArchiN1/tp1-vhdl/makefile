FILES = testbench_compteur.vhdl fulladder.vhdl adder.vhdl clock.vhdl registre1bit.vhdl registrenbits.vhdl compteur.vhdl
TARGET = testbench_compteur
TARGET_NAME = testbench_compteur.out
VCD = testbench_compteur.vcd

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
