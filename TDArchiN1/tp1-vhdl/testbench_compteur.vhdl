---------  A test bench for the <Compteur> -----------------
library ieee;
use ieee.std_logic_1164.all;
library work;

 -- the black box has no input and no output.
entity testbench_compteur is
end entity;

architecture behaviorial of testbench_compteur is
  -- We need to declare the sub-components used.
  component compteur is
    generic (n: integer); -- generic means: architectural parameter
    port ( clk, reset : in std_logic;
           q : out std_logic_vector(n-1 downto 0));
  end component;

  component clock is
    port ( clk : out  std_logic );
  end component;

  -- Think of signals as wires inside the architecture.
  -- We give them a name. std_logic is the standard logic type.
  signal testq : std_logic_vector(7 downto 0);
  signal testreset, testclock : std_logic;

begin
  --  Instantiate the Clock (Clk)
  myclock: clock
    port map (
      clk   => testclock
    );

  --  Instantiate the Unit Under Test (UUT)
  uut: compteur
    generic map ( n => 8 )  -- at some point the size of the architecture must
                            -- be fixed
    port map (
      q     => testq,
      reset => testreset,
      clk   => testclock
    );

  -- A process is an infinite loop
   test_process :process
   begin
     testreset <= '1';
     wait for 2 ns;
     testreset <= '0';
     wait for 10 ns;
     wait;
   end process;

end;
