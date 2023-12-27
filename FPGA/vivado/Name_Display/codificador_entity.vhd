--
-- VHDL Entity SCRATCH_LIB.codificador.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 20:39:44 25/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ENTITY codificador IS

  port(
    CLK : in STD_LOGIC;
    multiplex : out STD_LOGIC_vector (3 downto 0)
    );  
  
END ENTITY codificador;

ARCHITECTURE Codif of codificador is
signal pulse : std_logic := '0';
signal count : integer range 0 to 1000000 := 0;
signal salida : STD_LOGIC_vector (3 downto 0) := "0000";
signal m : STD_LOGIC_vector (3 downto 0) := "1110";

begin
  
  pulse <= CLK;
  
  multiplex <= m;
  
  counter : process(CLK) is  --registro
  begin
    if CLK'event and CLK = '1' then
      if count = 999999 then
         count <= 0;
         if m = "1110" then
           m <= "1101";
         elsif m = "1101" then
           m <= "1011";
         elsif m = "1011" then
           m <= "0111";
         else
           m <= "1110";
        end if;
      else
        count <= count + 1;
      end if;
    end if;
  end process counter;
  
    
END ARCHITECTURE codif;
