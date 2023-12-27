--
-- VHDL Entity SCRATCH_LIB.Base.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 16:38:05 03/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
library IEEE;
use IEEE.STd_logic_1164.ALL;
use IEEE.STd_logic_UNSIGNED.ALL;
use IEEE.STd_logic_ARITH.ALL;

entity Base is
	generic(  
	--K: integer:=499999;--constante del comparador
	N:integer:=22 --numero de bist del contador
	);
	port
	(
	CLK:in std_logic;--reloj maestro
	RST: in std_logic;--reset maesstro
	H:in std_logic;--señal de habilitacion de la base de tiempo
	BT:out std_logic;--base de tiempo
	Frecuencia: in STD_LOGIC_VECTOR (N-1 downto 0)
	) ;
end Base;

architecture Behavioral of Base is
signal Qp,Qn: std_logic_vector(N-1 downto 0):=(others=>'0');
signal BdT:std_logic;--señal base de tiempo
signal BdTconH:std_logic_vector(1 downto 0);--señal base de tiempo con habilitador

begin
	BT<=BdT;
	BdTconH<=BdT & H;
	Mux:Process(BdTconH,Qp)is
	begin
		case BdTconH is
			when "01" =>Qn<=Qp+1;
			when "11" =>Qn<=(others=>'0');
			when others=>Qn<=Qp;
		end case;
	end process Mux;
	Comparador:Process(Qp)is
	begin
		if Qp=Frecuencia then
			BdT<='1';
		else
			BdT<='0';
		end if;
		end process Comparador;
		
Combinacional:Process(CLK,RST)is
begin
	if RST='0' then
		Qp<=(others=>'0');
	elsif CLK'event and CLK='1' then
		Qp<=Qn;
	end if;
	end process Combinacional;
	end Behavioral;

