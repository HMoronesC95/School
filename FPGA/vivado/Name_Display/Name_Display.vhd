library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

Entity Name_Display is
	port (
	CLK : in std_logic;
	RST : in std_logic;
	H	: in std_logic;
	f : out std_logic_vector(6 downto 0)
	  );
end Name_Display;

Architecture completa of Name_Display is

Component base_tiempo is  
	GENERIc(
	K: integer:=3; --constante del comparador
    N: integer:=4 -- numero de bits del contador
  
  );
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    H : in STD_LOGIC; --señal de habilitacion de la base de timepo
    BT : out STD_LOGIC --base de tiempo fisica
    );
End component;

Component Codificador is 
	port (
	CLK: IN STD_LOGic;	
	RST : in STD_LOGIC;
	DISPLAYS: out std_logic_vector(1 downto 0);
	Pulso: in std_logic
	);
end Component;
Component Hola is
	port(		  
	
	x : in std_logic_vector(1 downto 0); --entradas para las funciones
	f : out std_logic_vector(6 downto 0) --Salida Led
	);	  
	
end component;

signal Y1:std_logic:='0';
SIGNal Y2:std_logic_vector(1 downto 0);

begin		 
	C_BDT 		: base_tiempo Generic map (49999,16) port map (CLK,RST,H,Y1);
	C_COD		: Codificador port map (CLK,RST,Y2,Y1);
	C_HOL		: Hola port map (Y2,f); 
	
	
end architecture completa;