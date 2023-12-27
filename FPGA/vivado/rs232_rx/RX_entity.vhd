--
-- VHDL Entity SCRATCH_LIB.RX.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 11:01:42 05/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
--
-- VHDL Entity SCRATCH_LIB.RX.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 11:01:42 05/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

ENTITY RX IS
	 port(
     CLK : in STD_LOGIC; --reloj maestro
     RST : in STD_LOGIC; --reset maestro	   
	 B : in STD_LOGIC;	
	 rx_in : in STD_LOGIC;
	 verif : out STD_LOGIC_VECTOR(7 downto 0);
     Busy_rx : out STD_LOGIC
	     ); 
END ENTITY RX;

architecture RX_arch of RX is
signal Qp, Qn: std_logic_vector (3 downto 0);

begin	

	Recibir : process (B,rx_in,Qp) is
	begin			
		case Qp is 
			when "0000" =>--estado de espera 
			  if rx_in = '1' then
				  Busy_rx <= '0';
				  Qn <= Qp;
				else
				  Qn <= "0001";
				  Busy_rx <= '0';
				end if; 
			when "0001" => -- estado de espera para que acabe el bit de start
			  if B = '0' then
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0010";
				  Busy_rx <= '1';
				end if; 			  
			when "0010" => --se recibe el primer dato
			  if B = '0' then
				  verif(0) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0011";
				  Busy_rx <= '1';
				  verif(0) <= rx_in;
				end if; 
			when "0011" =>   -- se recibe el segundo dato
			  if B = '0' then
				  verif(1) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0100";
				  Busy_rx <= '1';
				  verif(1) <= rx_in;
				end if; 
			when "0100" => -- se recibe el tercer dato
			  if B = '0' then
				  verif(2) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0101";
				  Busy_rx <= '1';
				  verif(2) <= rx_in;
				end if; 
			when "0101" => --cuarto dato
			  if B = '0' then
				  verif(3) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0110";
				  Busy_rx <= '1';
				  verif(3) <= rx_in;
				end if; 
			when "0110" => -- quinto dato
			  if B = '0' then
				  verif(4) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0111";
				  Busy_rx <= '1';
				  verif(4) <= rx_in;
				end if; 
			when "0111" =>--sexto dato
			  if B = '0' then
				  verif(5) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "1000";
				  Busy_rx <= '1';
				  verif(5) <= rx_in;
				end if; 
			when "1000" =>--septimo dato
			  if B = '0' then
				  verif(6) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "1001";
				  Busy_rx <= '1';
				  verif(6) <= rx_in;
				end if; 
			when "1001" => --recepcion del ultimo dato
			  if B = '0' then
				  verif(7) <= rx_in;
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "1010";	
				  Busy_rx <= '1';
				  --verif(7) <= rx_in;
				end if; 		
			when "1010" => 
			  if rx_in = '0' then
				  Busy_rx <= '1';
				  Qn <= Qp;
				else
				  Qn <= "0000";
				  Busy_rx <= '0';
				end if; 
			when others => verif <= (others => '0'); Qn <= "0000"; Busy_rx <= '0';
		end case;
	end process Recibir;	
				
  combinacional : process(CLK,RST) is  --registro
  begin
    if RST = '0' then
      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
    end if;
  end process combinacional;				
								
end architecture;

