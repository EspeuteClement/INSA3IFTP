--- A good syntax for a mux
library ieee;
use ieee.std_logic_1164.all;
library work;

entity ual is
   port ( arg1, arg2 : in std_logic_vector(7 downto 0);
          codeop : in std_logic_vector(3 downto 0);

          R : out std_logic_vector(7 downto 0);
          c, z, n : out std_logic;
end entity;

architecture arch of ual is
begin
    case codeop is
      when '0010' => arg1 and arg2 <= R;
      when '0011' => arg1 or arg2 <= R;
      when '0100' => arg1 xor arg2 <= R;
      when '0101' => srl arg1 <= R;
    end case;
 end architecture;
