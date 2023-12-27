--
-- VHDL Entity SCRATCH_LIB.multiplex_displays.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 20:31:22 25/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ENTITY cont_0_99 IS
  
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC;
    control_in : in std_logic;
    manual_in : in std_logic;
    x_in : in std_logic;
    U_out : out std_logic_vector(3 downto 0);
    D_out : out std_logic_vector(3 downto 0)
 
    );
  
END ENTITY cont_0_99;

Architecture comp of cont_0_99 is

signal count : integer range 0 to 100000000 := 0;

signal u_p, u_n : std_logic_vector (3 downto 0) := "0000";
signal d_p, d_n : std_logic_vector (3 downto 0) := "0000";
signal Qp, Qn : std_logic_vector (1 downto 0) := "00";
signal control, manual, x: std_logic := '0';
--signal cont_u : integer range 0 to 9 := 0;

begin		 
  
  U_out <= u_p;
  D_out <= d_p;
  control <= control_in;
  manual <= manual_in;
  x <= x_in;
  
  
--  cuenta_manual : process (u_p,d_p,control,manual,x) is
--  begin
  
--  end process;
  
  counter : process(CLK,RST,u_p,d_p,control,manual,x) is  --registro
  begin
    if RST = '0' then
      count <= 0;
      u_n <= "0000";
      d_n <= "0000";
    elsif CLK'event and CLK = '1' then
      case manual is
        when '0' => --cuando esta en carrera libre
          case control is
            when '0' =>     --ascendente
              if count = 20000000 then
                 count <= 0;
                 if u_n < "1001" then
                    u_n <= u_p + 1;
                 elsif d_n = "1010" then
                    d_n <= "0000";
                 else 
                    u_n <= "0000";
                    d_n <= d_p + 1;
                 end if;
              else
                count <= count + 1;
                u_p <= u_n;
                d_p <= d_n;
              end if;
            when '1' =>  -- descendente
              if count = 20000000 then
                 count <= 0;
                 if u_n > "0000" then
                    u_n <= u_p - 1;
                 elsif d_n = "0000" then
                    d_n <= "1010";
                 else
                    u_n <= "1001";
                    d_n <= d_p - 1;
                 end if;
              else
                count <= count + 1;
                u_p <= u_n;
                d_p <= d_n;
              end if;
            when others => u_n <= u_p; d_n <= d_p;        
          end case; --fin del case control
          
        when '1' => --cuando se activa manual
          case control is
            when '0' => -- ascendente
              case Qp is
                when "00" =>     
                  if x = '0' then
                    Qn <= Qp;
                    u_n <= u_p;
                    d_n <= d_p;
                  else 
                    Qn <= "01";
                    u_n <= u_p;
                    d_n <= d_p;
                  end if;
                when "01" =>
                  if x = '1' then
                    Qn <= Qp;
                    u_p <= u_n;
                    d_p <= d_n;
                  else
                    Qn <= "10";              
                  end if;
                when "10" =>
                   if x = '0' then  
                     if u_p < "1001" then
                        u_n <= u_p + 1;
                        Qn <= "00"; 
                     elsif d_p = "1001" then
                        d_n <= "0000";
                        u_n <= "0000";
                        Qn <= "00";
                     else 
                        u_n <= "0000";
                        d_n <= d_p + 1;
                        Qn <= "00";
                     end if;
                    else
                        Qn <= "01";
                  end if;
                when others => u_p <= u_n; d_p <= d_n;
                --u_p <= u_n; d_p <= d_n;
              end case; --fin del case de estado 
              Qp <= Qn; u_p <= u_n; d_p <= d_n;
            when '1' => -- descendente
              case Qp is
                when "00" =>     
                  if x = '0' then
                    Qn <= Qp;
                    u_n <= u_p;
                    d_n <= d_p;
                  else 
                    Qn <= "01";
                    u_n <= u_p;
                    d_n <= d_p;
                  end if;
                when "01" =>
                  if x = '1' then
                    Qn <= Qp;
                    u_p <= u_n;
                    d_p <= d_n;
                  else
                    Qn <= "10";              
                  end if;
                when "10" =>
                   if x = '0' then  
                     if u_p > "0000" then
                        u_n <= u_p - 1;
                        Qn <= "00"; 
                     elsif d_p = "0000" then
                        d_n <= "1001";
                        u_n <= "1001";
                        Qn <= "00";
                     else 
                        u_n <= "1001";
                        d_n <= d_p - 1;
                        Qn <= "00";
                     end if;
                    else
                        Qn <= "01";
                  end if;
                when others => u_p <= u_n; d_p <= d_n;
                --u_p <= u_n; d_p <= d_n;
              end case; --fin del case de estado 
              Qp <= Qn; u_p <= u_n; d_p <= d_n;
            when others => Qp <= "00";       
          end case;--fin del case control 
        when others => control <= '0';
      end case;  -- fin del case manual
    end if; -- fin del evento de CLK = '1'
  end process counter;

end architecture comp;
