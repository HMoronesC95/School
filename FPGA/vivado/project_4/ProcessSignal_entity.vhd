--
-- VHDL Entity SCRATCH_LIB.ProcessSignal.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 14:03:45 13/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; 
--use IEEE.Std_Logic_Arith.ALL;
--use IEEE.NUMERIC_STD.UNSIGNED;
entity ProcessSignal is
	port(
	CLK				: in std_logic;
	Sensor1Decenas	: in std_logic_vector (3 downto 0);
	Sensor1Data		: out std_logic_vector (6 downto 0);
	Sensor2Data		: out std_logic_vector (6 downto 0);
	Sensor1Unidades	: in std_logic_vector (3 downto 0);
	Sensor2Decenas	: in std_logic_vector (3 downto 0);
	Sensor2Unidades	: in std_logic_vector (3 downto 0);
	Anodes			: out std_logic_vector(3 downto 0);
	segments		: out std_logic_vector(6 downto 0)
	);
end ProcessSignal;

architecture ex of ProcessSignal is

signal digit : std_logic_vector(3 downto 0)  := (others => '0');

signal count,contador : integer range 0 to 1000000 := 0;
signal m : STD_LOGIC_vector (3 downto 0) := "0111";
signal Sensor2DataUnidades,Sensor2DataDecenas,DecenasSumaSensor2,UnidadesSumaSensor2:integer range 0 to 1000 :=0;
signal Sensor1DataUnidades,Sensor1DataDecenas,decenasSumaSensor1,unidadesSumaSensor1:integer range 0 to 1000 :=0;
signal ResultadoDecenasSensor2,ResultadoUnidadesSensor2,ResultadoDecenasSensor1,ResultadoUnidadesSensor1:integer range 0 to 15 :=0;
signal DecenasSensor2,UnidadesSensor2,DecenasSensor1,UnidadesSensor1: std_logic_vector (3 downto 0) := "0000";  
signal TotalSensor2,TotalSensor1: integer range 0 to 100:= 0;
signal TotalSensor2VectorSalida,TotalSensor1VectorSalida: std_logic_vector (6 downto 0):="0000000";

begin

decode: process(digit)
    begin
        case digit is 
           when "0001" => segments <= "1111001";
           when "0010" => segments <= "0100100";
           when "0011" => segments <= "0110000";
           when "0100" => segments <= "0011001";
           when "0101" => segments <= "0010010";
           when "0110" => segments <= "0000010";
           when "0111" => segments <= "1111000";
           when "1000" => segments <= "0000000";
           when "1001" => segments <= "0010000";
           --when "1010" => segments <= "0001000";
           --when "1011" => segments <= "0000011";
--           when "1100" => segments <= "1000110";
--           when "1101" => segments <= "0100001";
--           when "1110" => segments <= "0000110";
--           when "1111" => segments <= "0001110";
           when others => segments <= "1000000";
        end case;
    end process;
 
Anodes	<=	m;
	
counter : process(CLK) is  --registro
  begin
    if CLK'event and CLK = '1' then
    
	Sensor2DataDecenas	<=	to_integer(unsigned(Sensor2Decenas));	
	Sensor2DataUnidades	<=	to_integer(unsigned(Sensor2Unidades));
	Sensor1DataDecenas	<= 	to_integer(unsigned(Sensor1Decenas));
	Sensor1DataUnidades <=	to_integer(unsigned(Sensor1Unidades));
	
	UnidadesSumaSensor2	<=	Sensor2DataUnidades	+	UnidadesSumaSensor2;
	DecenasSumaSensor2	<=	Sensor2DataDecenas	+	DecenasSumaSensor2;	
	UnidadesSumaSensor1	<=	Sensor1DataUnidades	+	UnidadesSumaSensor1;
	DecenasSumaSensor1	<=	Sensor1DataDecenas	+	DecenasSumaSensor1;
	contador	<=	contador+1;	
		
		if contador=100 then
			
			ResultadodecenasSensor2		<=	DecenasSumaSensor2	/	99;
			ResultadounidadesSensor2	<=	UnidadesSumaSensor2	/	99;
			
			ResultadodecenasSensor1		<=	DecenasSumaSensor1	/	99;
			ResultadounidadesSensor1	<=	UnidadesSumaSensor1	/	99;
		
		elsif contador=101 then 
			
			UnidadesSumaSensor2	<=	0;
			DecenasSumaSensor2	<=	0;
			
			UnidadesSumaSensor1	<=	0;
			DecenasSumaSensor1	<=	0;
			
			contador	<=	0;
			
			TotalSensor2	<=	ResultadodecenasSensor2*10+ResultadoUnidadesSensor2;
			TotalSensor1	<=	ResultadodecenasSensor1*10+ResultadoUnidadesSensor1;
			
		end if;
		
		TotalSensor2VectorSalida	<=	std_logic_vector(to_unsigned(	TotalSensor2	,	TotalSensor2VectorSalida'length));	
		TotalSensor1VectorSalida	<=	std_logic_vector(to_unsigned(	TotalSensor1	,	TotalSensor1VectorSalida'length));
		
		Sensor1Data<=TotalSensor1VectorSalida;
		Sensor2Data<=TotalSensor2VectorSalida;
		
		decenasSensor2	<=	std_logic_vector(to_unsigned(	ResultadodecenasSensor2		,	decenasSensor2'length	));
		unidadesSensor2	<=	std_logic_vector(to_unsigned(	ResultadounidadesSensor2	,	unidadesSensor2'length	));
		
		decenasSensor1	<=	std_logic_vector(to_unsigned(	ResultadodecenasSensor1		,	decenasSensor1'length	));
		unidadesSensor1	<=	std_logic_vector(to_unsigned(	ResultadounidadesSensor1	,	unidadesSensor1'length	));
		
		if count = 10000 then
	         count <= 0;         
	         if m = "0111" then
	           digit <= unidadessensor1	;
	           m <= "1110";
	         elsif m = "1110" then
	           digit <= decenassensor1	;
	           m <= "1101";
	         elsif m = "1101" then
	           digit <= unidadesSensor2	;
	           m <= "1011";
	         else
	           digit <= decenasSensor2	;
	           m <= "0111";
	        end if;
	      else
	        count <= count + 1;
	      end if;
	   end if;
  end process counter;	
	
	
	
end architecture;



