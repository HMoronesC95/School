--
-- VHDL Entity SCRATCH_LIB.Base5.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:47:04 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;  

entity timeralto is
	generic (
	K: integer:= 249999999; --Constante del Comparador
	N: integer:= 28 --Número de Bits
	);
	port (
	CLK : in std_logic; --Reloj Maestro
	RST : in std_logic; --Reset Maestro
	--H : in std_logic; --Señal de Habilitación de la Base de Tiempo
	--BT1 : out std_logic;  --Base de Tiempo
	pulso : out std_logic_vector(1 downto 0)
	);
end timeralto;	

architecture Behavioral of timeralto is
signal Qp, Qn : std_logic_vector(N-1 downto 0):=(others => '0');  --Es
signal BdT , st, cd , alto : std_logic; 
signal BdTconH : std_logic_vector(1 downto 0);

begin 	

	BdTconH <= BdT & st;  
	cd <= BdT;
	alto <= BdT;
	
	Mux: process(BdTconH, Qp) is
	begin
		case BdTconH is
			when "01" => Qn <= Qp + 1;
			when "11" => Qn <= (others => '0');
			when others => Qn <= Qp;
		end case;
	end process Mux;
	
	Comparador: process(Qp) is 
	begin 
		if Qp = K then 
			BdT <= '1';
		else
			BdT <= '0';
		end if;
	end process Comparador;
	
	combinacional: process(CLK, RST) is  --Registro
	begin
		if RST ='0' then
			Qp <= (others => '0');
		elsif CLK'event and CLK = '1' then 
			Qp <= Qn;
		end if;
	end process combinacional; 
	
	act : process (cd) is
	begin 
		case cd is	 
			
			when '0' =>	--S0
				st <= '1';
			
			when '1' =>	--S1  
				st <= '0';
			
			when others =>
			st <= '0';
		end case;
	end process act;	
	
	salida : process (alto) is
	begin 
		case alto is 
			
			when '0' => 
			pulso <= "00";
			when '1' =>
			pulso <= "11";
			when others =>
			pulso <= "00";
		
		end case;
			
	end process salida;	
		
end Behavioral;

