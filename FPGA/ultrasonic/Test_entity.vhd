--
-- VHDL Entity SCRATCH_LIB.Prueba_entity.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:41:11 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;
use IEEE.STD_LOGIC_ARITH.all;


entity Prueba_entity is		
	 port(
		 CLK : in STD_LOGIC;--	Reloj maestro
		 RST : in STD_LOGIC;--	Reset maestro
		  H:	in STD_LOGIC;
		 entrada:in std_logic;
		 entradas: in std_logic_vector(2 downto 0);	
		 --salida: out std_logic_vector(2 downto 0) ;
		  Motor : out STD_LOGIC_VECTOR(3 downto 0);
		 Led:out std_logic;
		 S : in std_logic
		
		 
	     );
end Prueba_entity;	  

architecture Complete of Prueba_entity is
Component Oneshot is
	port( 	 
	RST : in std_logic;
	CLK : in std_logic;
	entrada: in std_logic;	
	salida: out std_logic;
	Led:out std_logic
	);
end component; 

Component Seleccion is
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
end Component;
component Pasos is		

	 port(
		 BdT : in STD_LOGIC;--	Reloj maestro
		 RST : in STD_LOGIC;--	Reset maestro
		 H:	in STD_LOGIC;	--	Se�al de habilitaci?n de la base de tiempo 
		 Motor : out STD_LOGIC_VECTOR(3 downto 0);	
		 --NPaso:out std_logic;
		 CM3:in std_logic_vector(2 downto 0);
		  NPaso:out std_logic;
		 Suma :in std_logic_vector(1 downto 0);
		 Senal22: in std_logic_vector(1 downto 0)
	     );
end component;
Component Base is
	generic(  
	--K: integer:=499999;--constante del comparador
	N:integer:=19 --numero de bist del contador
	);
	port
	(
	CLK:in std_logic;--reloj maestro
	RST: in std_logic;--reset maesstro
	H:in std_logic;--se�al de habilitacion de la base de tiempo
	BT:out std_logic;--base de tiempo
	Frecuencia: in STD_LOGIC_VECTOR (N-1 downto 0)
	) ;
end Component;
Component Contadorpasos is		

	port(
		 CLK:in std_logic;
		 Npasostotal : in STD_LOGIC;--	Reloj maestro
		 RST : in STD_LOGIC;--	Reset maestro
		 H:	in STD_LOGIC;	--	Se�al de habilitaci?n de la base de tiempo 
		 Senal:out std_logic_vector(1 downto 0);
		 Elec:in std_logic_vector(2 downto 0);
		 SalidaHomer:out std_logic;
		 Senal2:out std_logic
		 --Paro:in std_logic
	     );
end component; 
Component timeralto is
	generic (
	K: integer:= 249999999; --Constante del Comparador
	N: integer:= 28 --N�mero de Bits
	);
	port (
	CLK : in std_logic; --Reloj Maestro
	RST : in std_logic; --Reset Maestro
	--H : in std_logic; --Se�al de Habilitaci�n de la Base de Tiempo
	--BT1 : out std_logic;  --Base de Tiempo
	pulso : out std_logic_vector(1 downto 0)
	);
end component;	

signal Y0:std_logic;
Signal Y1:std_logic_vector(2 downto 0);
Signal BT:std_logic;
Signal Fr:std_logic_vector(21 downto 0);
Signal Npaso:std_logic;
Signal SumaPasos:std_logic_vector(1 downto 0);	
Signal Pul: std_logic_vector(1 downto 0);
signal Pul2: std_logic;
signal Homer_crack_ruso:std_logic;
begin
			
	
	One:  Oneshot port map(RST,CLK,entrada,Y0,Led);
	Sel:  Seleccion port map(RST,Y0,CLK,entradas,Y1,S,Homer_crack_ruso,Fr);
	Bas:  Base Generic map(22) port map(CLK,RST,H,BT,Fr);
	Pas:  Pasos port map(BT,RST,H,Motor,Y1,Npaso,SumaPasos,Pul);
	Cont: Contadorpasos port map(CLK,Npaso,RST,H,SumaPasos,Y1,Homer_crack_ruso,Pul2);
	reg:  timeralto port map(CLK,Pul2,Pul);
	
	
end Complete;	

