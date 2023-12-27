--
-- VHDL Entity SCRATCH_LIB.PWM_derecha.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 13:51:29 13/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

ENTITY PWM_derecha IS
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    duty_in : in STD_LOGIC_VECTOR (16 downto 0);
    PWM_d : out std_logic
    );
END ENTITY PWM_derecha;

ARCHITECTURE Behavioral of PWM_derecha is
SIGNAL duty : std_logic_vector (16 downto 0) := (others=>'0');
signal duty_d,contador: integer range 0 to 100000 := 0;

begin

  combinacional : process(CLK,RST,duty,duty_in) is  --registro
  begin
    duty <= duty_in;
    duty_d <= to_integer(unsigned(duty));
    if RST = '0' then
      duty_d <= 0;
      PWM_d <= '0';
    elsif CLK'event and CLK = '1' then 
      if contador >= 99999 then
        contador <= 0;
        PWM_d <= '0';    
      elsif contador >= duty_d then
        contador <= contador + 1;
        PWM_d <= '0';
      else
        contador <= contador + 1;
        PWM_d <= '1';         
      end if;   
    end if;
  end process combinacional;
    
END ARCHITECTURE Behavioral;



