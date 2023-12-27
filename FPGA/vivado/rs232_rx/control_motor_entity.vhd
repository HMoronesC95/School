--
-- VHDL Entity SCRATCH_LIB.control_motor.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 15:52:45 09/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

ENTITY control_motor IS
  port(
    verif_in : in STD_LOGIC_VECTOR(7 downto 0);
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    m_d : out std_logic_vector (1 downto 0);
    m_i : out std_logic_vector (1 downto 0);
    led : out std_logic_vector (1 downto 0)
  );
END ENTITY control_motor;

architecture control of control_motor is
signal Qp, Qn: std_logic_vector(1 downto 0) := (others=>'0');
begin
  
  Salida : process (verif_in,Qp)
  begin
  case Qp is
    when "00" => --case del modo libre
      case verif_in is
        when "01000001" =>  --avance
          m_d <= "01";
          m_i <= "01";
          Qn <= Qp;
          led <= "00";
        when "01000010" => --derecha
          m_d <= "01";
          m_i <= "10";
          Qn <= Qp;
          led <= "00";  
        when "01000011" => --retroceso
          m_d <= "10";
          m_i <= "10";
          Qn <= Qp;
          led <= "00";
        when "01000100" => --izquierda
          m_d <= "10";
          m_i <= "01";
          Qn <= Qp;
          led <= "00";   
        when "01000000" => --default
          m_d <= "00";
          m_i <= "00";
          Qn <= Qp;
          led <= "00";
        when "00110001" => --start 5 cm
          m_d <= "00";
          m_i <= "00";
          Qn <= "01";
          led <= "00"; 
        when "00110000" => --stop, regresa al estado libre
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";
          led <= "00";        
        when others =>
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";
          led <= "00";
      end case; --fin del case de modo 
    when "01" => -- case de 5 cm
      case verif_in is
        when "01000001" =>  --avance
          m_d <= "01";
          m_i <= "01";
          Qn <= Qp;
          led <= "01";
        when "01000010" => --derecha
          m_d <= "01";
          m_i <= "10";
          Qn <= Qp;
          led <= "01";  
        when "01000011" => --retroceso
          m_d <= "10";
          m_i <= "10";
          Qn <= Qp;
          led <= "01";
        when "01000100" => --izquierda
          m_d <= "10";
          m_i <= "01";
          Qn <= Qp; 
          led <= "01";  
        when "01000000" => --default
          m_d <= "01";
          m_i <= "01";
          Qn <= Qp;
          led <= "01";
        when "00110001" => --start 5 cm
          m_d <= "01";
          m_i <= "01";
          Qn <= Qp;
          led <= "01";
        when "00110000" => --stop, regresa al estado libre
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";
          led <= "01";          
        when others =>
          m_d <= "00";
          m_i <= "00";
          Qn <= Qp;
          led <= "01";
      end case; --fin del case de modo
    when others => m_d <= "00"; m_i <= "00"; Qn <= "00";
  end case;--fin del case de estado
  end process;
  
  
  combinacional : process(CLK,RST) is 
  begin
    if RST = '0' then
      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
    end if;
  end process combinacional;

end architecture;

