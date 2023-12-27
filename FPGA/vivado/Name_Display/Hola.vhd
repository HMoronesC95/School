						library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

entity Hola is
	port(		  
	
	x : in std_logic_vector(1 downto 0); --entradas para las funciones
	f : out std_logic_vector(6 downto 0) --Salida Led
	);	  
	
end Hola;


architecture combinacional of Hola is	

signal func0, func1, func2, func3, func4, func5, func6: std_logic;
--signal func : std_logic_vector(2 down to 0):="000";

begin 
	
	func0 <= x(0);	
	func1 <= (not x(1)) or x(0);
	func2 <= (not x(1)) or x(0); 
	func3 <= ((not x(1)) and x(0)) or (x(1) and (not x(0)));
	func4 <= '1';
	func5 <= '1'; 
	func6 <= ((not x(1)) and (not x(0))) or (x(1) and x(0));
	
	comparacion: process (func0, func1, func2, func3, func4, func5, func6)	 --Lista de sensibilidad (se?ales que t? analizas)
	begin
			
		f(6) <= not func0;
		f(5) <= not func1;
		f(4) <= not func2;	 
		f(3) <= not func3;
		f(2) <= not func4;
		f(1) <= not func5;
		f(0) <= not func6;
			
	end process comparacion;
	
end architecture combinacional;