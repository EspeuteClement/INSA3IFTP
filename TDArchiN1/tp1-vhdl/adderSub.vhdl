---------  An n-bit adder ------------------

library ieee; 
use ieee.std_logic_1164.all;
library work;
entity addersub is
  generic (n: integer); -- generic means: architectural parameter
  port(x : in std_logic_vector(n-1 downto 0);
       y : in std_logic_vector(n-1 downto 0);
       cin : in std_logic;
       s : out std_logic_vector(n-1 downto 0);
       cout : out std_logic );
end entity;




architecture rtl of addersub is
  component adder is
   port ( xadd, yadd, cinadd : in std_logic_vector(n-1 downto 0);
          coutadd, sadd : out  std_logic_vector(n-1 downto 0) );
    end component;
-- YAY
-- the vector of internal carries. Note that it is n+1 bits
  signal  c : std_logic_vector (n downto 0);

begin
	if ( cin = 1 ) then
		yvar <= not y;
	else
		yvar <= y;
	end if;
	adderinstance:
		adder port map (
			xadd => x;
			yadd => y;
			cinadd => cin;
			coutadd => cout;
			sadd => sum;
		);
end architecture;
