--
-- VHDL Entity SCRATCH_LIB.Distancias.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:40:01 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity Oneshot is
	port( 	 
	RST : in std_logic;
	CLK : in std_logic;
	entrada: in std_logic;	
	salida: out std_logic;
	Led:out std_logic
	);
end Oneshot;
			  
architecture combinacional of oneshot is 
signal Qn, Qp: std_logic_vector(1 downto 0):=(others=>'0');
begin				  
	machine:process(Qp,entrada) is
	begin
		
		case Qp is 
			--s0
			when "00"=>
			salida<='0';
			Led<='0';  
			if entrada='0' then
				Qn<="01";
			else 
				Qn <= Qp; 
			end if;
			 --s1
			when "01"=>
			salida<='0'; 
			Led<='0';  
			if entrada='1' then
				Qn<="10";
			else
			    Qn <= Qp; 
			end if;	
			  --s2
			when "10"=>
			salida<='1';  
			Led<='1';  
			if entrada='1' then
				Qn<="10" ;
			else
			    Qn <= "11"; 
			end if;	
			--s3
			when "11"=>
			salida<='0'; 
			Led<='0';  
			if entrada='0' then
				Qn<="11" ;
			else
			    Qn <= "00"; 
			end if;
			when others =>
			Qn <= "00"; --Ir a S0
			
			end case;
		
	end process machine; 
	
	secuencial : process (RST,CLK) is
	begin 
		if RST = '0' then
			Qp <= "00";  
		 elsif CLK'event and CLK ='1' then
			Qp <= Qn;
		end if;
	end process secuencial;
	
end architecture combinacional;

