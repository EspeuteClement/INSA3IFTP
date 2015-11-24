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
	cout <= (x or y) and not (x or cin);
	sum <= (cin xor x) and  (cin xor y) ;
end architecture;
