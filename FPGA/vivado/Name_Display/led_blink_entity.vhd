--
-- VHDL Entity SCRATCH_LIB.led_blink.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 11:53:39 24/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ENTITY led_blink IS

  port(
    CLK : in STD_LOGIC; --reloj maestro
    x : in std_logic;
    time : out STD_LOGIC --base de tiempo fisica
    );
END ENTITY led_blink;

ARCHITECTURE Parpadeo of led_blink is
signal pulse : std_logic := '0';
signal count : integer range 0 to 100000000 := 0;

begin
  counter : process(CLK) is  --registro
  begin
    if CLK'event and CLK = '1' then
      if count = 1 then
         count <= 0;
         pulse <= not pulse;
      else
        count <= count + 1;
      end if;
    end if;
  end process counter;
  
  time <= pulse;
    
END ARCHITECTURE Parpadeo;

