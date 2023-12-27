--
-- VHDL Entity SCRATCH_LIB.maquina_estado_moore.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 20:34:48 26/06/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE IEEE.std_logic_unsigned.all;

ENTITY maquina_estado_moore IS

  port(
    RST : in std_logic;
    CLK : in std_logic;
    X : in std_logic; 
    R : out std_logic;
    Y1 : out std_logic; 
    Y : out std_logic
  );
  
END ENTITY maquina_estado_moore;

ARCHITECTURE maquina of maquina_estado_moore is
--  SIGNAL estado : std_logic_vector (1 downto 0) := "00";
--  signal Qp, Qn : std_logic_vector (1 downto 0) := "00";
TYPE Estado_FSM is (SA,SB,SC,SD,SE,SF);
signal Qp,Qn : Estado_FSM;
  
begin
  Combinacional : process (Qp, X)
  begin
    case Qp is
      when SA => Y <= '0';Y1 <= '0';
        if (X='0') then
          Qn <= SA;
        else
          Qn <= SB;
        end if;
      when SB => Y <= '0';Y1 <= '0';
        if (X = '1') then
          Qn <= SB;
        else
          Qn <= SC;
        end if;
      when SC => Y <= '1';Y1 <= '0';
        if (X = '0') then
          Qn <= SC;
        else 
          Qn <= SD;
        end if;
      when SD => Y <= '0';Y1 <= '0';
        if (X = '1') then
          Qn <= SD;
        else 
          Qn <= SE;
        end if;
      when SE => Y <= '1';Y1 <= '1';
        if (X = '0') then
          Qn <= SE;
        else 
          Qn <= SF;
        end if;
      when SF => Y <= '0';Y1 <= '0';
        if (X = '1') then
          Qn <= SF;
        else 
          Qn <= SA;
        end if;
   --   when others => Qn <= "00";
      end case;
    end process Combinacional;
    
  secuencial : process (RST,CLK)
  begin
    if (RST = '0') then
      Qp <= SA;  --iniciar en estado s0
      R <= '1';
    elsif (CLK'event and CLK = '1') then
      Qp <= Qn;
      R <= '0';
    end if;
  end process secuencial;
end architecture maquina;