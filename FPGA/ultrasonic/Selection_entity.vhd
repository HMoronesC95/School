--
-- VHDL Entity SCRATCH_LIB.Seleccion.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:42:21 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity Seleccion is
	port( 	 
	RST : in std_logic;	
	RST2 : in std_logic;
	CLK : in std_logic;
	entradas: in std_logic_vector(2 downto 0);
	salida: out std_logic_vector(2 downto 0);
	S : in std_logic;
	entradaHomer: in std_logic;
	fr : out std_logic_vector(21 downto 0)
	
	);
end Seleccion;		
architecture combinacional of Seleccion is 
signal Qn, Qp: std_logic_vector(3 downto 0):=(others=>'0');
begin
	machine:process(Qp,entradas) is
	begin
		
		case Qp is 	 
			
			--s0
			when "0000"=>
			salida<="000";
			if entradas="001" then
				Qn<="0001";
			elsif entradas="010" then
				Qn<="0100";	  
				elsif entradas="100" then
				Qn<="1000";
			else 
				Qn <= Qp;  
			end if;
		--------------------3cm	
			 --s1
			when "0001"=>
			salida<="000";
			if entradas="000" then
				Qn<="0010";
			else
			    Qn <= Qp; 
			end if;	
			  --s2
			when "0010"=>
			salida<="100";
			if entradas="001" then
				Qn<="0010" ;
			else
			    Qn <= Qp; 
			end if;	 
	   ------------------------------------------5cm
	  
		   --s1
			when "0100"=>
			salida<="000";
			if entradas="000" then
				Qn<="0101";
			else
			    Qn <= Qp; 
			end if;	
			  --s2
			when "0101"=>
			salida<="010";
			if entradas="010" then
				Qn<="0111" ;
			else
			    Qn <= Qp; 
			end if;	 
			  --s3
			when "0111"=>
			salida<="010";
			if entradas="000" then
				Qn<="0101" ;
			else
			    Qn <=Qp; 
				
			end if;	 
		
		 -----------------7cm--------------
		
		
					   --s1
			when "1000"=>
			salida<="000";
			if entradas="000" then
				Qn<="1001";
			else
			    Qn <= Qp; 
			end if;	
			  --s2
			when "1001"=>
			salida<="001";
			if entradas="100" then
				Qn<="1011" ;
			else
			    Qn <= Qp; 
			end if;	 
			  --s3
			when "1011"=>
			salida<="001";
			if entradas="000" then
				Qn<="1001" ;
			else
			    Qn <=Qp; 
				
			end if;	
		
		
		
		
		
		
		
		
		
		
		
		
			when others =>
			Qn <= "0000"; --Ir a S0 
			salida<="000";
			end case;
		
	end process machine; 
	
	FR1: process(S)is
	begin
			if S='0' then
			fr<="0001111010000100011111"; 
			else
			fr<="1001100010010110011111";
			end if;
	end process FR1;
	
	secuencial : process (entradaHomer,RST,CLK,RST2) is
	begin 
		if RST = '0' then
			Qp <= "0000";
		elsif entradaHomer='1' then
			Qp <= "0000";
		ELSif RST2 = '0' then
			Qp <= "0000";  
		 elsif CLK'event and CLK ='1' then
			Qp <= Qn;
		end if;
	end process secuencial;
	
end architecture combinacional;
			 

