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

ENTITY multiplex_displays IS
  
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC;
    an : out std_logic_vector(3 downto 0);
    dp : out STD_LOGIC;
    U_in : STD_LOGIC_vector (3 downto 0);
    D_in : STD_LOGIC_vector (3 downto 0);
    seg : out std_logic_vector(6 downto 0)   
    );
  
END ENTITY multiplex_displays;

Architecture completa of multiplex_displays is

signal count : integer range 0 to 100000000 := 0;
signal m : STD_LOGIC_vector (3 downto 0) := "1110";
signal cero : STD_LOGIC_vector (6 downto 0) := "0000001";
signal uno : STD_LOGIC_vector (6 downto 0) := "1001111";
signal dos : STD_LOGIC_vector (6 downto 0) := "0010010";
signal tres : STD_LOGIC_vector (6 downto 0) := "0000110";
signal cuatro : STD_LOGIC_vector (6 downto 0) := "1001100";
signal cinco : STD_LOGIC_vector (6 downto 0) := "0100100";
signal seis : STD_LOGIC_vector (6 downto 0) := "0100000";
signal siete : STD_LOGIC_vector (6 downto 0) := "0001111";
signal ocho : STD_LOGIC_vector (6 downto 0) := "0000000";
signal nueve : STD_LOGIC_vector (6 downto 0) := "0000100";

signal   U : STD_LOGIC_vector (3 downto 0) := "0000";
signal   D : STD_LOGIC_vector (3 downto 0) := "0000";

--signal Qp, Qn: std_logic_vector (3 downto 0) :="0000";
signal BT : std_logic :='0';

begin		 

  an <= m;
  dp <= '1';

  
  counter : process(CLK,RST,U,D,U_in,D_in) is  --registro
  begin
  U <= U_in;
  D <= D_in;
    if RST = '0' then
      count <= 0;
      m <= "1111";
      U <= "0000";
      D <= "0000";
--      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
 --     Qp <= Qn;
      if count = 100000 then
         count <= 0;
         if m = "1110" then
           m <= "1101";
            case D is
              when "0000" => seg <= cero;
              when "0001" => seg <= uno;
              when "0010" => seg <= dos;
              when "0011" => seg <= tres;
              when "0100" => seg <= cuatro;
              when "0101" => seg <= cinco;
              when "0110" => seg <= seis;
              when "0111" => seg <= siete;
              when "1000" => seg <= ocho;
              when "1001" => seg <= nueve;           
              when others => seg <=cero;
            end case;
         elsif m = "1101" then
           m <= "1110";
             case U is
              when "0000" => seg <= cero;
              when "0001" => seg <= uno;
              when "0010" => seg <= dos;
              when "0011" => seg <= tres;
              when "0100" => seg <= cuatro;
              when "0101" => seg <= cinco;
              when "0110" => seg <= seis;
              when "0111" => seg <= siete;
              when "1000" => seg <= ocho;
              when "1001" => seg <= nueve;           
              when others => seg <=cero;
            end case;
         else
           m <= "1110";
           seg <= cero;
        end if;
      else
        count <= count + 1;
      end if;
    end if;
  end process counter;

end architecture completa;
