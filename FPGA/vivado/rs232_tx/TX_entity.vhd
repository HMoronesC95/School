--
-- VHDL Entity SCRATCH_LIB.TX.arch_name
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 19:36:58 04/07/2019
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

ENTITY TX IS
	 port(
     CLK : in STD_LOGIC; --reloj maestro
     RST : in STD_LOGIC; --reset maestro	 
		 B : in STD_LOGIC;
		 send : in STD_LOGIC;
		 Data : in STD_LOGIC_VECTOR(7 downto 0);
		 tx_out : out STD_LOGIC;
		 Busy_tx : out STD_LOGIC	--	?ocupado o desocupado?
	     );
END ENTITY TX;

architecture TX_arch of TX is
signal Qp, Qn: std_logic_vector (3 downto 0);
begin					
	Enviar: process (Qp,Data,B,send) is
	begin			
		case Qp is	 
		    when "0000" => 
			  if send = '0' then
			    Qn <= Qp;
			    Busy_tx <= '0';
				  tx_out <= '1';
				else
				  Qn <= "0001";
				  Busy_tx <= '0';
				  tx_out <= '1';
				end if;	
		    when "0001" =>
			  if send = '1' then
			    Qn <= Qp;
			    Busy_tx <= '0';
				  tx_out <= '1';
				else
				  Qn <= "0010";
				  Busy_tx <= '0';
				  tx_out <= '1';
				end if;		    		    	     
			when "0010" =>  --se manda 1 hasta que llegue un pulso de la base de tiempo
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '0';
				  tx_out <= '1';
				else
				  Qn <= "0011";
				  Busy_tx <= '0';
				  tx_out <= '1';
				end if;
			when "0011" =>  --se manda el bit de start
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= '0';
				else
				  Qn <= "0100";
				  Busy_tx <= '1';
				  tx_out <= '0';
				end if;
			when "0100" =>  --se manda el bit menos significativo bit 0
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(0);
				else
				  Qn <= "0101";
				  Busy_tx <= '1';
				  tx_out <= Data(0);
				end if;
			when "0101" =>  -- bit 1
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(1);
				else
				  Qn <= "0110";
				  Busy_tx <= '1';
				  tx_out <= Data(1);
				end if;
			when "0110" =>
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(2);
				else
				  Qn <= "0111";
				  Busy_tx <= '1';
				  tx_out <= Data(2);
				end if;
			when "0111" =>
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(3);
				else
				  Qn <= "1000";
				  Busy_tx <= '1';
				  tx_out <= Data(3);
				end if;
			when "1000" =>
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(4);
				else
				  Qn <= "1001";
				  Busy_tx <= '1';
				  tx_out <= Data(4);
				end if;
			when "1001" =>
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(5);
				else
				  Qn <= "1010";
				  Busy_tx <= '1';
				  tx_out <= Data(5);
				end if;
			when "1010" =>
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(6);
				else
				  Qn <= "1011";
				  Busy_tx <= '1';
				  tx_out <= Data(6);
				end if;
			when "1011" => --se manda el ultimo bit
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '1';
				  tx_out <= Data(7);
				else
				  Qn <= "1100";
				  Busy_tx <= '1';
				  tx_out <= Data(7);
				end if;		
			when "1100" => -- se manda el bit de stop
			  if B = '0' then
			    Qn <= Qp;
			    Busy_tx <= '0';
				  tx_out <= '1';
				else
				  Qn <= "0000";
				  Busy_tx <= '0';
				  tx_out <= '1';
				end if;
			when others => tx_out <= '1'; Busy_tx <= '0'; Qn <= "0000";
		
		end case;
	end process Enviar;	
	
  combinacional : process(CLK,RST) is  --registro
  begin
    if RST = '0' then
      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
    end if;
  end process combinacional;	
				
end architecture;