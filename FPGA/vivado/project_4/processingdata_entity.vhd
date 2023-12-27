--
-- VHDL Entity SCRATCH_LIB.processingdata.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 19:46:19 13/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; 

Entity ProcessingData is
	port(
		CLK		   	: in std_logic;
		RST			: in std_logic;
		Sensor1Data	: in std_logic_vector(6 downto 0);
		Sensor2Data	: in std_logic_vector(6 downto 0);
		Informacion	: in std_logic_vector(6 downto 0);
		PWMmotor1	: out std_logic_vector(16 downto 0); --100,000 máximo
		PWMmotor2	: out std_logic_vector(16 downto 0); --100,000 máximo
		Direccion  	: out std_logic;
		Paro	   	: out std_logic
	);
end processingData;

architecture processing of ProcessingData is

signal Qp,Qn: std_logic_vector(2 downto 0):=(others=>'0');
signal DataIntegerS1, DataIntegerS2, DataControl : integer range 0 to 100:=0;
Signal DataOutS1,DataOutS2 : INTEGER range 0 to 160000;
signal cuenta: integer range 0 to 1000000:=0;

	begin 
		contador : process(CLK,Qp) is  --registro
  		begin
    		if CLK'event and CLK = '1' then	
			
			cuenta<=cuenta+1;
				if cuenta=999999 then	
					
					cuenta	<=	0;
					DataIntegerS1	<=	to_integer(signed(	Sensor1Data	));
					DataIntegerS2	<=	to_integer(signed(	Sensor2Data	));
					DataControl		<=	to_integer(unsigned(	Informacion	));
					
					Case Qp is
						
						when "000" =>
							if (DataControl = 5) then	
								Qn<="001";
							elsif (DataControl = 12) then
							
							elsif (DataControl = 20) then	
							
							else 
								Qn	<=	Qp;
						  	end if;
						when "001" =>
						
							if DataControl=1 then
								Qn	<=	"000";
							else
								Qn	<=	Qp;
							end if;
							
							if DataIntegerS1>5 then
								Direccion	<=	'1';
								Paro		<=	'0';
								PWMmotor1	<=	std_logic_vector(to_unsigned(1000*(DataIntegerS1-5)+45000,	PWMmotor1'length	));
							elsif DataIntegerS1<5 then 
								Direccion	<=	'0';
								Paro		<=	'0';
								PWMmotor1	<=	std_logic_vector(to_unsigned(1000*(5-	DataIntegerS1	)+45000	,	PWMmotor1'length	));
							elsif DataIntegerS1=5 then
								Direccion	<='0';
								Paro		<='1';
								PWMmotor1	<=	std_logic_vector	(to_unsigned(45000	,	PWMmotor1'length	));
							end if;
							
							if DataIntegerS2>5 then
								Direccion	<=	'1';
								Paro		<=	'0';
								PWMmotor2	<=	std_logic_vector(to_unsigned(1000*(DataIntegerS2-5)+45000,	PWMmotor2'length	));
							elsif DataIntegerS2<5 then 
								Direccion	<=	'0';
								Paro		<=	'0';
								PWMmotor2	<=	std_logic_vector(to_unsigned(1000*(5-	DataIntegerS2	)+45000	,	PWMmotor2'length	));
							elsif DataIntegerS2=5 then
								Direccion	<='0';
								Paro		<='1';
								PWMmotor2	<=	std_logic_vector	(to_unsigned(45000	,	PWMmotor2'length	));
							end if;
							
						when others=>
								Qn<=(others=>'0');
					end case;
				end if;
			end if;
			
		end process;
		
		actualizacion: process (CLK,RST) is
		begin		
    if RST = '0' then
      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
    end if;
		end process;		

end architecture;
