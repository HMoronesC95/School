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
    set_point : out std_logic_vector (6 downto 0);
    direccion_i : in std_logic;
    direccion_d : in std_logic;
    paro_in : in std_logic;
    m_d : out std_logic_vector (1 downto 0);
    m_i : out std_logic_vector (1 downto 0)
  );
END ENTITY control_motor;

architecture control of control_motor is
signal Qp, Qn: std_logic_vector(1 downto 0) := (others=>'0');
signal x_p,x_n : std_logic_vector (6 downto 0) := "0000001";
begin
   
   set_point <= x_p;
   
   distancia : process (verif_in,x_p)
   begin
    case verif_in is
        when "00110001" => --5cm
            x_n <= "0000101";
        when "00110010" => --12cm
            x_n <= "0001100";
        when "00110011" => --20cm
            x_n <= "0010100";
        when "00110000" => --stop
            x_n <= "0000001";
        when others =>
            x_n <= x_p;
    end case;
   end process;
   
  
  Salida : process (verif_in,Qp,direccion_i,direccion_d,paro_in)
  begin
  case Qp is
    when "00" => --case del modo libre
      case verif_in is
        when "01000001" =>  --avance
          m_d <= "01";
          m_i <= "01";
          Qn <= "00";
        when "01000010" => --derecha
          m_d <= "01";
          m_i <= "10";
          Qn <= "00"; 
        when "01000011" => --retroceso
          m_d <= "10";
          m_i <= "10";
          Qn <= "00";
        when "01000100" => --izquierda
          m_d <= "10";
          m_i <= "01";
          Qn <= "00"; 
        when "01000000" => --default
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";
        when ("00110001" or "00110010" or "00110011") => --start 5, 12, 20cm
          m_d <= "00";
          m_i <= "00";
          Qn <= "01";
        when "00110000" => --stop, regresa al estado libre
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";   
        when others =>
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";
      end case; --fin del case de modo 
    when "01" => -- case de 5, 12, 20 cm
      case verif_in is
        when "01000001" =>  --avance
          m_d <= "01";
          m_i <= "01";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "01";
          end if;
        when "01000010" => --derecha
          m_d <= "01";
          m_i <= "10";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "01";
          end if;  
        when "01000011" => --retroceso
          m_d <= "10";
          m_i <= "10";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "01";
          end if;
        when "01000100" => --izquierda
          m_d <= "10";
          m_i <= "01";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "01";
          end if;   
        when "01000000" => --default
          if paro_in = '1' then
            m_d <= "00";
            m_i <= "00";
            Qn <= "10";
          elsif ((direccion_d = '1') and (direccion_i = '1'))  then 
            m_d <= "01";
            m_i <= "01";
            Qn <= "01";
          elsif ((direccion_d = '0') and (direccion_i = '0')) then 
            m_d <= "10";
            m_i <= "10";
            Qn <= "01";
          elsif ((direccion_d = '0') and (direccion_i = '1')) then 
            m_d <= "10";
            m_i <= "01";
            Qn <= "01";
          elsif ((direccion_d = '1') and (direccion_i = '0')) then 
            m_d <= "01";
            m_i <= "10";
            Qn <= "01";
          else 
            m_d <= "00";
            m_i <= "00";
            Qn <= "01";          
          end if;
        when ("00110001" or "00110010" or "00110011") => --start 5 ,12, 20 cm
          m_d <= "00";
          m_i <= "00";
          Qn <= "01";
        when "00110000" => --stop, regresa al estado libre
          m_d <= "00";
          m_i <= "00";
          Qn <= "00";       
        when others =>
          m_d <= "00";
          m_i <= "00";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "01";
          end if; 
      end case; --fin del case de verif
    when "10" => 
      case verif_in is
        when "00110000" => --stop, regresa al estado libre
          m_d <= "00";
          m_i <= "00";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "00";
          end if;
        when others =>
          m_d <= "00";
          m_i <= "00";
          if paro_in = '1' then
            Qn <= "10";
          else
            Qn <= "00";
          end if; 
      end case; --fin del case de verif
    when others => m_d <= "00"; m_i <= "00"; Qn <= "00";
  end case;--fin del case de estado   
  end process;
  
  
  combinacional : process(CLK,RST) is 
  begin
    if RST = '0' then
      Qp <= (others => '0');
      x_p <= "0000001";
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
      x_p <= x_n;
    end if;
  end process combinacional;

end architecture;