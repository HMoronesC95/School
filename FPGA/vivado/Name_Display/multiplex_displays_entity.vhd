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
    an : out std_logic_vector(3 downto 0);
    seg : out std_logic_vector(6 downto 0);   --entrada de selector
    dp : out std_logic;
    LED : out STD_LOGIC --base de tiempo fisica
    );
  
END ENTITY multiplex_displays;

Architecture completa of multiplex_displays is

signal pulse : std_logic := '0';
signal count : integer range 0 to 100000000 := 0;
--signal count_displace : integer range 0 to 100000000 :=0;
--signal count_aux : STD_LOGIC_vector (3 downto 0) := "0000";
signal m : STD_LOGIC_vector (3 downto 0) := "0111";
signal trash : std_logic := '1';
signal H : std_logic_vector (6 downto 0) := "1001000";
signal O : std_logic_vector (6 downto 0) := "0000001";
signal L : std_logic_vector (6 downto 0) := "1110001";
signal A : std_logic_vector (6 downto 0) := "0001000";
signal X : std_logic_vector (6 downto 0) := "1111111";

begin		 

  an <= m;
  dp <= trash;
  multiplex : process(CLK,H,O,L,A) is  --registro
  begin
    if CLK'event and CLK = '1' then
      if count = 99999 then
         count <= 0;
         pulse <= not pulse;
         if m = "0111" then 
            seg <= H;    
           m <= "1110";
         elsif m = "1110" then
            seg <= O;
           m <= "1101";
         elsif m = "1101" then
           seg <= L;
           m <= "1011";
         else
           seg <= A;
           m <= "0111";
        end if;
      else
        count <= count + 1;
--        count_displace <= count_displace +1;
     end if;
     
--      if count_displace = 99999999 then
--         count_displace <= 0;
--         count_aux <= count_aux+1;
--      elsif count_aux = "1000" then
--         count_aux <= "0000";
--      else
--        count_displace <= 0;
--      end if;
    end if;
  end process multiplex;
  
--  display : process(count_aux,m,X,H,O,L,A) is  --registro
--  begin
--    case count_aux is
--        when "0000" =>
--             if m = "0111" then     
--                seg <= X;
--             elsif m = "1110" then
--                seg <= X;
--             elsif m = "1101" then
--                seg <= X;
--             else --m <= "0111";
--                seg <= X;      
--            end if; 
--        when "0001" =>
--             if m = "0111" then     
--                seg <= X;
--             elsif m = "1110" then
--                seg <= H;
--             elsif m = "1101" then
--                seg <= X;
--             else --m <= "0111";
--                seg <= X;      
--            end if;
--        when "0010" =>
--             if m = "0111" then     
--                seg <= X;
--             elsif m = "1110" then
--                seg <= O;
--             elsif m = "1101" then
--                seg <= H;
--             else --m <= "0111";
--                seg <= X;      
--            end if; 
--        when "0011" =>
--             if m = "0111" then     
--                seg <= X;
--             elsif m = "1110" then
--                seg <= L;
--             elsif m = "1101" then
--                seg <= O;
--             else --m <= "0111";
--                seg <= H;      
--            end if;
--        when "0100" =>
--             if m = "0111" then     
--                seg <= H;
--             elsif m = "1110" then
--                seg <= A;
--             elsif m = "1101" then
--                seg <= L;
--             else --m <= "0111";
--                seg <= O;      
--            end if; 
--        when "0101" =>
--             if m = "0111" then     
--                seg <= O;
--             elsif m = "1110" then
--                seg <= X;
--             elsif m = "1101" then
--                seg <= A;
--             else --m <= "0111";
--                seg <= L;      
--            end if;
--        when "0110" =>
--             if m = "0111" then     
--                seg <= L;
--             elsif m = "1110" then
--                seg <= X;
--             elsif m = "1101" then
--                seg <= X;
--             else --m <= "0111";
--                seg <= A;      
--            end if; 
--        when "0111" =>
--             if m = "0111" then     
--                seg <= A;
--             elsif m = "1110" then
--                seg <= X;
--             elsif m = "1101" then
--                seg <= X;
--             else --m <= "0111";
--                seg <= X;      
--            end if;             
--         when others => seg <= X;
--     end case;
--  end process display;
  
  LED <= pulse;

end architecture completa;
