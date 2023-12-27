--
-- VHDL Entity SCRATCH_LIB.Contadorpasos.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:39:35 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;
use IEEE.STD_LOGIC_ARITH.all;


entity Contadorpasos is		

	port(
		 CLK: in std_logic;
		 Npasostotal : in STD_LOGIC;--	Reloj maestro
		 RST : in STD_LOGIC;--	Reset maestro
		 H:	in STD_LOGIC;	--	Se�al de habilitaci?n de la base de tiempo 
		 Senal:out std_logic_vector(1 downto 0);
		 Elec:in std_logic_vector(2 downto 0);
		 SalidaHomer:out std_logic;
		 Senal2:out std_logic:='0'
		 --Paro:in std_logic
	     );
end Contadorpasos;
architecture Behavioral of Contadorpasos is
signal ContBTp1,ContBTn1: std_logic_vector(8 downto 0):=(others => '0');	--	Estado presente y siguiente del contador
signal BdTconH3: std_logic_vector(1 downto 0);	
signal Qp, Qn : std_logic:='0';
begin				

	BdTconH3 <=  Npasostotal & H;
	
	--_____________________________________________________________Contar base de tiempo
	combinacionalBT: process(Npasostotal, RST) is		--	Registro
	begin		   
		if RST = '0' then
			ContBTp1 <= (others=>'0'); 
		elsif Npasostotal'event and Npasostotal= '1' then
			ContBTp1 <= ContBTn1;

		end if;
	end process combinacionalBT;
	
	MuxBT: process(Qn,Qp,BdTconH3, ContBTp1,Elec) is
	begin			
		case BdTconH3 is
			when "01" => 
				ContBTn1 <= ContBTp1 +1;
				Qn<='0';
				salidaHomer<=Qp;
			when "11" => ContBTn1 <= (others=>'0');
			when others => ContBTn1 <= ContBTp1;
		end case;
		Case Elec is
			When"100" =>
		 if ContBTp1= "010100000" then  --10100000
		  	 salidaHomer<=Qp;
			 Qn<='1';
			 ContBTn1 <= "000000000"; 
		 end if; 
		 -----
		 When"010" => 
		 if ContBTp1= "011110000" then  --10100000
		  ContBTn1 <= "000000000"; 
		 end if; 
		 -------
		    When"001" => 
		 if ContBTp1= "101000000" then  --10100000
		  ContBTn1 <= "000000000"; 
		 end if; 
		 when others => ContBTn1 <="000000000";
		end case;
	end process MuxBT;			
	
	---------------------------------------------------------
	
	Combinacional:Process(CLK)is
	begin
		if CLK'event and CLK='1' then
				Qp<=Qn;
		end if;
	end process Combinacional;
	
	--_____________________________________________________Termina contar base de tiempo	   
	
	
	MotorPasos: process( ContBTp1,Elec) is
	begin		  
		
		
	
	   Case Elec is
		When "100"=>
		if ContBTp1 < "01010000"	  then
			Senal<= "00"; 
			Senal2<='0';
			
		elsif ContBTp1="010100000" then
			Senal<= "01";
			Senal2<='0'	; 
			
			else
			Senal<= "11";
			Senal2<='1';
		end if;	   
	-------5cm	
		when "010"=>
		if ContBTp1 < "001111000"	  then
			Senal<= "00"; 
				Senal2<='0';
			
		elsif ContBTp1="011110000" then
			Senal<= "01";
				Senal2<='0';
	
			else
			Senal<= "11"; 
			Senal2<='1';
			
		end if;
		------------7cm
		 when "001"=>
		if ContBTp1 < "010100000"	  then
			Senal<= "00"; 
			Senal2<='0';
			
		elsif ContBTp1="101000000" then
			Senal<= "01";
			Senal2<='0';
	
			else
			Senal<= "11"; 
			Senal2<='1';
			
		end if;
		when others=>	Senal<= "01";
		Senal2<='0'	;
		end case;
	end process MotorPasos;	
	
	
	end Behavioral;
