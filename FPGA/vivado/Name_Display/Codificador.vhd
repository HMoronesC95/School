library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

Entity Codificador is 
	port (
	CLK: IN STD_LOGic;	
	RST : in STD_LOGIC;
	DISPLAYS: out std_logic_vector(1 downto 0);
	Pulso: in std_logic
	);
end Codificador;

architecture combinacional of Codificador is 
signal Qp,Qn:std_logic_vector(1 downto 0):=(others=>'0');	  
begin	   
	DISPLAYS<=Qp;
	cod: process (Qp, Pulso)
	begin
	case Qp is
		When "00"=>
			if Pulso='1' then 
				Qn<=Qp+1;
			else 
				Qn<=Qp;
			end if;	
		When "01"=>
			if Pulso='1' then 
				Qn<=Qp+1;
			else 
				Qn<=Qp;
			end if;	
		When "10"=>
			if Pulso='1' then 
				Qn<=Qp+1;
			else 
				Qn<=Qp;
			end if;	
		When "11"=>
			if Pulso='1' then 
				Qn<=(others=>'0');
			else 
				Qn<=Qp;
			end if;	
		When others =>Qn<=Qp;			
	end case;
	end process cod;		 
	
	combinacional : process(CLK,RST) is  --registro
	begin
		if RST = '0' then
		  Qp <= (others => '0');
		elsif CLK'event and CLK = '1' then
		  Qp <= Qn;
		end if;
	end process combinacional;
  
	
	
end architecture combinacional;