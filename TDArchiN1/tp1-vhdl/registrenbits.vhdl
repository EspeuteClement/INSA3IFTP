---------  An n-bit adder ------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
entity registrenbits is
  generic (n: integer); -- generic means: architectural parameter
  port ( clk, enable, reset : in std_logic;
         d : in std_logic_vector(n-1 downto 0);
         q : out std_logic_vector(n-1 downto 0));
end entity;


architecture rtl of registrenbits is
  component registre1bit is
    port ( clk, d, enable, reset : in  std_logic;
           q : out  std_logic );
  end component;


  begin
      addloop: -- this is a label, mandatory on "for ... generate" loops
      for i in 0 to n-1 generate
        begin
          registre1bitinstance:
            registre1bit port map (
            d => d(i),
            q => q(i),
            clk => clk,
            enable => enable,
            reset => reset
            );
   end generate;
end architecture;
