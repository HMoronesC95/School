library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

ENTITY PWM IS
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    --duty_in : in STD_LOGIC_VECTOR (17 downto 0);
    PWM_i : out std_logic;
    PWM_d : out std_logic
    );
	
END ENTITY PWM;

ARCHITECTURE Behavioral of PWM is
--SIGNAL duty : std_logic_vector (17 downto 0) := (others=>'0');
signal duty: integer range 0 to 200000 := 0;

begin
  
  combinacional : process(CLK,RST) is  --registro
  begin
    if RST = '0' then
      duty <= 0;
    elsif CLK'event and CLK = '1' then 
      if duty = 199999 then
        duty <= 0;    
      elsif duty >= 110000 then
        duty <= duty + 1;
        PWM_i <= '1';
        PWM_d <= '1';
      else
        duty <= duty + 1;
        PWM_i <= '0';
        PWM_d <= '0';         
      end if;   
    end if;
  end process combinacional;
    
END ARCHITECTURE Behavioral;