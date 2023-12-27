----
---- VHDL Entity SCRATCH_LIB.selector_producto.arch_name
----
---- Created:
----          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
----          at - 13:15:29 26/06/2019
----
---- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
----
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

ENTITY selector_producto IS
  
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    P1 : IN STD_LOGIC;
   -- P2 : IN STD_LOGIC;
    LED : out STD_LOGIC
   -- Pselect : out std_logic_vector (1 downto 0) 
    );  
END ENTITY selector_producto;

ARCHITECTURE Combinacional of selector_producto is
  
--signal entrada : std_logic_vector(1 downto 0) := (others=>'0');
signal entrada_p1 : std_logic := '0';
signal pulse : std_logic := '0';
--signal entrada_p2 : std_logic;
signal estado : integer range 0 to 3 := 0;
signal estado_n : integer range 0 to 3 := 0;
--signal estado_p : integer range 0 to 3 := 0;
 

begin
  
  
  entrada_p1 <= P1;
  LED <= pulse;
--  entrada_p2 <= P2; 
  

  comparacion : process (entrada_p1,estado) is
  begin
    case estado is
      when  0 =>
       -- Pselect <= "00";
        if entrada_p1 = '1' then
          estado_n <= 1;
        else
          estado_n <= estado;
        end if;
      when 1 =>
      --  Pselect <= "00";
        if entrada_p1 = '1' then
          estado_n <= estado;
        else
          estado_n <= estado + 1;
        end if;
      when 2 =>
     --   Pselect <= "01";
        if entrada_p1 = '0' then
          estado_n <= estado;
         -- pulse <= '1';
        else
          estado_n <= 0;
         -- pulse <= '0';
        end if;       
      when others => estado_n <= 0;
    end case;
  end process;
 
  combinacional : process(CLK,RST) is  --registro
  begin
    if RST = '0' then
      estado <= 0;
    elsif CLK'event and CLK = '1' then
      estado <= estado_n;
    end if;
  end process combinacional; 
  
END ARCHITECTURE Combinacional;

--
-- VHDL Entity SCRATCH_LIB.led_blink.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 11:53:39 24/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
--LIBRARY ieee;
--USE ieee.std_logic_1164.all;
--USE ieee.std_logic_arith.all;
--USE ieee.std_logic_unsigned.all;

--ENTITY led_blink IS

--  port(
--    CLK : in STD_LOGIC; --reloj maestro
--    LED : out STD_LOGIC --base de tiempo fisica
--    );
--END ENTITY led_blink;

--ARCHITECTURE Parpadeo of led_blink is
--signal pulse : std_logic := '0';
--signal count : integer range 0 to 100000000 := 0;

--begin
--  counter : process(CLK) is  --registro
--  begin
--    if CLK'event and CLK = '1' then
--      if count = 99999999 then
--         count <= 0;
--         pulse <= not pulse;
--      else
--        count <= count + 1;
--      end if;
--    end if;
--  end process counter;
  
--  LED <= pulse;
    
--END ARCHITECTURE Parpadeo;
