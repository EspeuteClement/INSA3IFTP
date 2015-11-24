---------  A full adder ------------------

library ieee;
use ieee.std_logic_1164.all;
library work;


entity fulladder is
   port ( x, y, cin : in std_logic;
          cout, sum : out  std_logic );
end entity;


architecture rtl of fulladder is
begin
	cout <= (x and y) or (cin and (x xor y)) after 35 ps;
	sum <= y xor x xor cin after 30 ps;
end architecture;
