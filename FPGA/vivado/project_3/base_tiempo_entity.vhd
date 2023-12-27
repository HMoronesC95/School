library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

ENTITY base_tiempo IS
  generic(
    K: integer:=10416; --constante del comparador
    N: integer:=22 -- numero de bits del contador
  );
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    H : in STD_LOGIC; --señal de habilitacion de la base de timepo
    BT : out STD_LOGIC --base de tiempo fisica
    );
END ENTITY base_tiempo;

ARCHITECTURE Behavioral of base_tiempo is
signal Qp, Qn: std_logic_vector(N-1 downto 0) := (others=>'0'); --Qn es el tiempo futuro, Qp es tiempo presente
signal BdT : std_logic;                        --señal base de tiempo
signal BdTconH : std_logic_vector(1 downto 0); --señal base tiempo con habilitador

begin
  
  BT <= BdT and H;
  BdTconH <= BdT & H;   --el & es una concatenacion de BdT y H, por lo que BdTconH es un vector de 4 bits
  
  Mux : process(BdTconH, Qp) is
  begin
    case BdTconH is
      when "01" => Qn <=Qp+1;
      when "11" => Qn <= (others=>'0');
      when others => Qn <= Qp;
    end case;
  end process Mux;

  Comparador : process (Qp) is
  begin
    if Qp = K then
      BdT <= '1';
    else
      BdT <= '0';
    end if;
  end process Comparador;
  
  combinacional : process(CLK,RST) is 
  begin
    if RST = '0' then
      Qp <= (others => '0');
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
    end if;
  end process combinacional;
    
END ARCHITECTURE Behavioral;
