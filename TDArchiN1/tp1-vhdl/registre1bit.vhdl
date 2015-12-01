library ieee;
use ieee.std_logic_1164.all;
library work;


entity registre1bit is
   port ( clk, d, enable, reset : in  std_logic;
          q : out  std_logic );
end entity;

architecture behaviorial of registre1bit is
   -- Registre avec enable
   begin
   with_enable_process :process
   begin
     if rising_edge(clk) then
       if enable = '1' then
         q <= d;
       end if;
     end if;
     if reset = '1' then
       q <= '0';
     end if;
   end process;
 end;
