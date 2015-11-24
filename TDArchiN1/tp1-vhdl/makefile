ALL :
	ghdl -a fulladder.vhdl
	ghdl -a testbench_fulladder.vhdl
	ghdl -e testbench_fulladder
	./testbench_fulladder --stop-time=20ns --vcd=testbench_fulladder.vcd
	gtkwave testbench_fulladder.vcd
