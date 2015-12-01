---------  An n-bit adder ------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
entity compteur is
  generic (n: integer); -- generic means: architectural parameter
  port ( clk, reset : in std_logic;
         q : out std_logic_vector(n-1 downto 0));
end entity;


architecture rtl of compteur is
  component registrenbits is
    generic (n: integer);
    port ( clk, enable, reset : in std_logic;
           d : in std_logic_vector(n-1 downto 0);
           q : out std_logic_vector(n-1 downto 0));
  end component;

  component adder is
    generic (n: integer);
    port(x : in std_logic_vector(n-1 downto 0);
         y : in std_logic_vector(n-1 downto 0);
         cin : in std_logic;
         s : out std_logic_vector(n-1 downto 0);
         cout : out std_logic );
  end component;

  signal one : std_logic_vector(n-1 downto 0);
  signal AdderOutToRegisterIn, RegisterOutToAdderIn : std_logic_vector(n-1 downto 0);

  begin
    one <= (n-1 downto 1 => '0') & '1';

    registrenbitsinstance:
      registrenbits
        generic map(n => n)
        port map (
        d => AdderOutToRegisterIn,
        q => RegisterOutToAdderIn,
        clk => clk,
        enable => '1',
        reset => reset
        );

    adderinstance:
      adder
        generic map(n => n)
        port map (
        x => RegisterOutToAdderIn,
        y => one,
        s => AdderOutToRegisterIn,
        cin => '0'
        );

      -- Output
      q <= RegisterOutToAdderIn;

end architecture;
