--
-- VHDL Entity SCRATCH_LIB.maquina_expendedora.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 19:01:23 26/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

ENTITY maquina_expendedora IS
  port(
    RST : in std_logic;
    CLK : in std_logic;
    U : in std_logic;     --moneda de 1
    D : in std_logic;     --moneda de 2
    C : out std_logic;
    R : out std_logic;
    P : out std_logic
  );
END ENTITY maquina_expendedora;

ARCHITECTURE FSM of maquina_expendedora is
signal Qn, Qp : std_logic_vector (2 downto 0);
begin
  combinacional : process (Qp, U, D)
    begin
      case Qp is
      when "000" =>
        --estado incial s0
        C <= '0';
        P <= '0';
        if (U = '1') then
          Qn <= "001";    --ir al estado s1
        elsif (D = '1') then
          Qn <= "010";   --ir al estado s2
        else 
          Qn <= Qp; --esperar moneda
        end if;
      when "001" =>   --estado s1 con 1 acumulado
        C <= '0';
        P <= '0';
        if (U = '1') then
            Qn <= Qp;
        else 
            Qn <= "010";    --ir al estado s2
        end if;
        if (D = '1') then
          Qn <= "011";   --ir al estado s3
        else 
          Qn <= Qp; --esperar moneda
        end if;
      when "010" =>   --estado s2 con 2 acumulados
        C <= '0';
        P <= '0';
        if (U = '1') then
            Qn <= "011";    --ir al estado s3
        elsif (D = '1') then
          Qn <= "100";   --ir al estado s4
        else 
          Qn <= Qp; --esperar moneda
        end if; 
      when "011" =>   --estado s3 para dar producto
        C <= '0';
        P <= '1';
        if(U = '1') then
            Qn <= Qp;
        else
            Qn <= "000";  --regresar a s0
        end if;
      when "100" =>   --estado s4 para dar producto y cambio
        C <= '1';
        P <= '1';
        Qn <= "000";  --regresar a s0
      when others => --estado irrelevantes
        C <= '0';
        P <= '0';
        Qn <= "000";  --regresar a s0      
    end case;
  end process combinacional;
  
  secuencial : process (RST,CLK)
  begin
    if (RST = '0') then
      Qp <= "000";  --iniciar en estado s0
      R <= '1';
    elsif (CLK'event and CLK = '1') then
      Qp <= Qn;
      R <= '0';
    end if;
  end process secuencial;
end FSM;
