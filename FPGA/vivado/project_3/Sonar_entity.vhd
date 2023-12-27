--
-- VHDL Entity SCRATCH_LIB.Sonar.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 14:02:58 13/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity sonar is
    Port ( clk        : in  STD_LOGIC;
           sonar_trig : out STD_LOGIC;
           sonar_echo : in  STD_LOGIC;
		   centi_unos : out std_logic_vector(3 downto 0);
		   centi_dece : out std_logic_vector(3 downto 0));
end sonar;

architecture Behavioral of sonar is
    signal count            : unsigned(16 downto 0) := (others => '0');
    signal centimeters      : unsigned(15 downto 0) := (others => '0');
    signal centimeters_ones : unsigned(3 downto 0)  := (others => '0');
    signal centimeters_tens : unsigned(3 downto 0)  := (others => '0');
    signal output_ones      : unsigned(3 downto 0)  := (others => '0');
    signal output_tens      : unsigned(3 downto 0)  := (others => '0');
    signal digit            : unsigned(3 downto 0)  := (others => '0');
    signal echo_last        : std_logic := '0';
    signal echo_synced      : std_logic := '0';
    signal echo_unsynced    : std_logic := '0';
    signal waiting          : std_logic := '0'; 
    signal seven_seg_count  : unsigned(15 downto 0) := (others => '0');
begin

unidades: process(output_ones)
    begin
        case output_ones is 
           when "0001" => centi_unos <= "0001";
           when "0010" => centi_unos <= "0010";
           when "0011" => centi_unos <= "0011";
           when "0100" => centi_unos <= "0100";
           when "0101" => centi_unos <= "0101";
           when "0110" => centi_unos <= "0110";
           when "0111" => centi_unos <= "0111";
           when "1000" => centi_unos <= "1000";
           when "1001" => centi_unos <= "1001";
           when "1010" => centi_unos <= "1010";
           when "1011" => centi_unos <= "1011";
           when "1100" => centi_unos <= "1100";
           when "1101" => centi_unos <= "1101";
           when "1110" => centi_unos <= "1110";
           when "1111" => centi_unos <= "1111";
           when others => centi_unos <= "0000";
        end case;
    end process;
    
	decenas: process(output_tens)
    begin
        case output_tens is 
           when "0001" => centi_dece <= "0001";
           when "0010" => centi_dece <= "0010";
           when "0011" => centi_dece <= "0011";
           when "0100" => centi_dece <= "0100";
           when "0101" => centi_dece <= "0101";
           when "0110" => centi_dece <= "0110";
           when "0111" => centi_dece <= "0111";
           when "1000" => centi_dece <= "1000";
           when "1001" => centi_dece <= "1001";
           when "1010" => centi_dece <= "1010";
           when "1011" => centi_dece <= "1011";
           when "1100" => centi_dece <= "1100";
           when "1101" => centi_dece <= "1101";
           when "1110" => centi_dece <= "1110";
           when "1111" => centi_dece <= "1111";
           when others => centi_dece <= "0000";
        end case;
    end process;	

process(clk)
    begin
        if rising_edge(clk) then
            if waiting = '0' then
                if count = 1000 then -- Assumes 100MHz
                   -- After 10us then go into waiting mode
                   sonar_trig <= '0';
                   waiting    <= '1';
                   count       <= (others => '0');
                else
                   sonar_trig <= '1';
                   count <= count+1;
                end if;
            elsif echo_last = '0' and echo_synced = '1' then
                -- Seen rising edge - start count
                count       <= (others => '0');
                centimeters <= (others => '0');
                centimeters_ones <= (others => '0');
                centimeters_tens <= (others => '0');
            elsif echo_last = '1' and echo_synced = '0' then
                -- Seen falling edge, so capture count
                output_ones <= centimeters_ones; 
                output_tens <= centimeters_tens; 
            elsif count = 2900*2 -1 then
                -- advance the counter
                if centimeters_ones = 9 then
                    centimeters_ones <= (others => '0');
                    centimeters_tens <= centimeters_tens + 1;
                else
                    centimeters_ones <= centimeters_ones + 1;
                end if;
                centimeters <= centimeters + 1;
                count <= (others => '0');
                if centimeters = 3448 then
                    -- time out - send another pulse
                    waiting <= '0';
                end if;
            else
                count <= count + 1;                
            end if;

            echo_last     <= echo_synced;
            echo_synced   <= echo_unsynced;
            echo_unsynced <= sonar_echo;
        end if;
        
    end process;
end Behavioral;

