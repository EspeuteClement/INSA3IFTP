FILE = adder

ALL :
	ghdl -a $(FILE).vhdl
	ghdl -a testbench_$(FILE).vhdl
	ghdl -e testbench_$(FILE)
	./testbench_$(FILE) --stop-time=20ns --vcd=testbench_$(FILE).vcd
	gtkwave testbench_$(FILE).vcd
