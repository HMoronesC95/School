--
-- VHDL Entity SCRATCH_LIB.Pasos.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:40:24 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;
use IEEE.STD_LOGIC_ARITH.all;


entity Pasos is		

	 port(
		 BdT : in STD_LOGIC;--	Reloj maestro
		 RST : in STD_LOGIC;--	Reset maestro
		 H:	in STD_LOGIC;	--	Se�al de habilitaci?n de la base de tiempo 
		 Motor : out STD_LOGIC_VECTOR(3 downto 0);
		 CM3:in std_logic_vector(2 downto 0);
		 NPaso:out std_logic;
		 Suma :in std_logic_vector(1 downto 0);
		 Senal22: in std_logic_vector(1 downto 0)
--		 Entradas:in std_logic_vector(2 downto 0)

	     );
end Pasos;
architecture Behavioral of Pasos is
signal ContBTp,ContBTn: std_logic_vector(1 downto 0):=(others => '0');	--	Estado presente y siguiente del contador
signal BdTconH2: std_logic_vector(1 downto 0);

begin				

	BdTconH2 <=  BdT & H;
	
	--_____________________________________________________________Contar base de tiempo
	combinacionalBT: process(BdT, RST) is		--	Registro
	begin		   
		if RST = '0' then
			ContBTp <= (others=>'0');
		elsif BdT'event and BdT = '1' then
			ContBTp <= ContBTn;
		end if;
	end process combinacionalBT;
	
	MuxBT: process(BdTconH2, ContBTp) is
	begin			
		case BdTconH2 is
			when "01" => ContBTn <= ContBTp +1;
			when "11" => ContBTn <= (others=>'0');
			when others => ContBTn <= ContBTp;
		end case;
	end process MuxBT;			
	
	--_____________________________________________________Termina contar base de tiempo 
	
	--_____________________________________________________Motor a pasos
	
	MotorPasos: process( ContBTp,CM3,Suma,Senal22) is
	begin 
		
		Case CM3 is
		When "100"=> 
					Case Suma is
					when "00"=>
					case ContBTp is
						when "00" => Motor <= "0001";
						Npaso<='0';
						when "01" => Motor <= "0010";
						when "10" => Motor <= "0100";
						when "11" => Motor <= "1000"; 
						Npaso<='1';
					when others => Motor <= "0000";
					end case;
					
					When "11"=>
					Case Senal22 is
						When "11"=>
						case ContBTp is
						when "00" => Motor <= "1000";
						Npaso<='0';
						when "01" => Motor <= "0100";
						when "10" => Motor <= "0010";
						when "11" => Motor <= "0001"; 
						Npaso<='1';
						when others => Motor <= "0000";
						end case;
						when "01"=>Motor <= "0000";
						when others => Motor <= "0000";
						end case;
					 when others => Motor <= "0000";
					 end case ;
		
					 ----------------5cm
					 	When "010"=> 
					Case Suma is
					when "00"=>
					case ContBTp is
						when "00" => Motor <= "0001";
						Npaso<='0';
						when "01" => Motor <= "0010";
						when "10" => Motor <= "0100";
						when "11" => Motor <= "1000"; 
						Npaso<='1';
					when others => Motor <= "0000";
					end case;
					
					When "11"=>
					Case Senal22 is
						When "11"=>
						case ContBTp is
						when "00" => Motor <= "1000";
						Npaso<='0';
						when "01" => Motor <= "0100";
						when "10" => Motor <= "0010";
						when "11" => Motor <= "0001"; 
						Npaso<='1';
						when others => Motor <= "0000";
						end case;
						when "01"=>Motor <= "0000";
						when others => Motor <= "0000";
						end case;
					 when others => Motor <= "0000";
					 end case ;
		
		
				   ------------------7cm
				   	  When "001"=> 
					Case Suma is
					when "00"=>
					case ContBTp is
						when "00" => Motor <= "0001";
						Npaso<='0';
						when "01" => Motor <= "0010";
						when "10" => Motor <= "0100";
						when "11" => Motor <= "1000"; 
						Npaso<='1';
					when others => Motor <= "0000";
					end case;
					
					When "11"=>
					Case Senal22 is
						When "11"=>
						case ContBTp is
						when "00" => Motor <= "1000";
						Npaso<='0';
						when "01" => Motor <= "0100";
						when "10" => Motor <= "0010";
						when "11" => Motor <= "0001"; 
						Npaso<='1';
						when others => Motor <= "0000";
						end case;  
						
						--when "01"=>Motor <= "0000";
						when others => Motor <= "0000";
						end case;
					 when others => Motor <= "0000";
					 end case ;
		
		
		
		


		
		
	
		
		
	
	
	
	when others => Motor <= "0000";
	end case;	
	end process MotorPasos;
	
	--_____________________________________________________Termina Motor a pasos
	
	
end Behavioral;

