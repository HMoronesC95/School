--
-- VHDL Entity SCRATCH_LIB.multiplexor.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 08:36:50 19/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ENTITY multiplexor IS
    port(
    sw : in std_logic_vector(3 downto 0);   --entrada de push
    s : in std_logic_vector(1 downto 0);   --entrada de selector
    f1 : out std_logic;
    LED : out std_logic_vector(3 downto 0)                    --salida led 
    );
     
END ENTITY multiplexor;

architecture combinacional of multiplexor is    --declaracion de arquitectura
signal func1, func2, func3 : std_logic;         --estas señales se pueden leer y escribir, no es ni input u output
--signal func : std_logic_vector(2 downto 0) : ="000" --se inicializa el vector en cero
--
begin                                           --dentro del begin es la descripcion de lo que se va a ejecutar
    
    func1 <= sw(3) and sw(2);
    func2 <=((not sw(1)) and sw(0)) or (sw(1) and (not sw(0)));
    func3 <= sw(0);
  
    --f1 <= (func(0) and (not s(1)) and (not s(0))) or (func(1) and....--funcion del multiplexor
    
    encender : process (sw)
    begin
        case sw is
            when "0000" => LED <= "0000";
            when "0001" => LED <= "0001";
            when "0010" => LED <= "0010";
            when "0011" => LED <= "0011";
            when "0100" => LED <= "0100";
            when "0101" => LED <= "0101";
            when "0110" => LED <= "0110";
            when "0111" => LED <= "0111";
            when "1000" => LED <= "1000";
            when "1001" => LED <= "1001";
            when "1010" => LED <= "1010";
            when "1011" => LED <= "1011";
            when "1100" => LED <= "1100";
            when "1101" => LED <= "1101";
            when "1110" => LED <= "1110";
            when "1111" => LED <= "1111";
            when others => LED <= "0000";
         end case;
     end process encender;
  
    comparacion : process (s, func1, func2, func3)
    begin
        case s is
            when "00" => f1 <= func1;      --cuando es un vector se pregunta con comillas dobles porque tiene varios valores
            when "01" => f1 <= func2;
            when "10" => f1 <= func3;
            when others => f1 <= '0';       --las comillas simples es cuando es uno o cero
        end case;
    
    end process comparacion;
  
  
end architecture combinacional;