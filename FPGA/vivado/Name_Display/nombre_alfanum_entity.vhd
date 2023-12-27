--
-- VHDL Entity SCRATCH_LIB.nombre_alfanum.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 12:27:57 24/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ENTITY nombre_alfanum IS
  
    port(
 --   sw : in std_logic_vector(1 downto 0) := sw_entrada;   --entrada de push
    
    an : out std_logic_vector(3 downto 0);
    seg : out std_logic_vector(6 downto 0);   --entrada de selector
    codif_in : in std_logic_vector(3 downto 0)
    );
     
END ENTITY nombre_alfanum;

architecture Display of nombre_alfanum is    --declaracion de arquitectura

signal sw_entrada : std_logic_vector (3 downto 0) := "0000"; 


begin                                           --dentro del begin es la descripcion de lo que se va a ejecutar

 --sw <= sw_entrada;
  sw_entrada <= codif_in;
  an <= sw_entrada;
 
     hola : process (sw_entrada)
    begin
        case sw_entrada is
            when "1110" => seg <= "0001000";      --cuando es un vector se pregunta con comillas dobles porque tiene varios valores           
            when "1101" => seg <= "1110001"; 
            when "1011" => seg <= "0000001";    
            when others => seg <= "1001000";       --las comillas simples es cuando es uno o cero
        end case;    
    end process hola;
 
end architecture Display;

