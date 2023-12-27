library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

ENTITY base_tiempo IS
  generic(
    X: integer:=100000; --constante del comparador
    Y: integer:=20000; --constante del comparador
    Z: integer:=10000; --constante del comparador
    N: integer:=32 -- numero de bits del contador
  
  );
  port(
    CLK : in STD_LOGIC; --reloj maestro
    RST : in STD_LOGIC; --reset maestro
    H : in STD_LOGIC; --señal de habilitacion de la base de timepo
    BT : out STD_LOGIC; --base de tiempo fisica
    duty_in : in STD_LOGIC_VECTOR (2 downto 0);
    frec_in : in STD_LOGIC_VECTOR (1 downto 0);
    R : out std_logic;
    PWM : out std_logic;
    PWM_N : out std_logic
    );
	
END ENTITY base_tiempo;

ARCHITECTURE Behavioral of base_tiempo is
signal Qp, Qn: std_logic_vector(N-1 downto 0) := (others=>'0'); --Qn es el tiempo futuro, Qp es tiempo presente
signal BdT : std_logic;                        --señal base de tiempo
signal BdTconH : std_logic_vector(1 downto 0); --señal base tiempo con habilitador
SIGNAL pulse : std_logic := '0';
SIGNAL pulse_n : std_logic := '0';
signal K : integer range 0 to 100000 := 0;
signal count : integer range 0 to 100000 := 0;
signal count1 : integer range 0 to 20000 := 0;
signal count2 : integer range 0 to 10000 := 0;
SIGNAL duty : std_logic_vector (2 downto 0) := "000";
SIGNAL frec : std_logic_vector (1 downto 0) := "00";

begin
  
  BT <= BdT and H;
  BdTconH <= BdT & H;   --el & es una concatenacion de BdT y H, por lo que BdTconH es un vector de 4 bits
  PWM <= pulse;  
  PWM_N <= pulse_n;
 
  Mux : process(BdTconH, Qp) is
  begin
    case BdTconH is
      when "01" => Qn <=Qp+1;
      when "11" => Qn <= (others=>'0');
      when others => Qn <= Qp;
    end case;
  end process Mux;

  Comparador : process (Qp,frec,K) is
  begin
    case frec is
      when "00" =>
        K <= X;
        if Qp = K then
          BdT <= '1';
        else
          BdT <= '0';
        end if;
      when "01" =>
        K <= Y;
        if Qp = K then
          BdT <= '1';
        else
          BdT <= '0';
        end if;
      when "10" =>
        K <= Z;
        if Qp = K then
          BdT <= '1';
        else
          BdT <= '0';
        end if;         
      when others => K <= 0; BdT <= '0';
    end case;
  end process Comparador;

  combinacional : process(CLK,RST,duty_in,frec_in) is  --registro
  begin
    if RST = '0' then
      duty <= duty_in;
      Qp <= (others => '0');
      R <= '1';
      pulse <= '0';
      pulse_n <= '0';
    elsif CLK'event and CLK = '1' then
      Qp <= Qn;
      R <= '0';
      frec <= frec_in;
      case frec is
        when "00" =>
          duty <= duty_in;
          case duty is
            when "000" =>
              if count = 99999 then
                count <= 0;
              elsif count >= 90000 then
                 count <= count + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count <= count + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "001" =>
              if count = 99999 then
                count <= 0;
              elsif count >= 65000 then
                 count <= count + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count <= count + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "010" =>
              if count = 99999 then
                count <= 0;
              elsif count >= 50000 then
                 count <= count + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count <= count + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "011" =>
              if count = 99999 then
                count <= 0;
              elsif count >= 35000 then
                 count <= count + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count <= count + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "100" =>
              if count = 99999 then
                count <= 0;
              elsif count >= 10000 then
                 count <= count + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count <= count + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if; 
            when others => count <= 0; pulse <= '0'; pulse_n <= '0';
          end case;--case duty 1k
          
        when "01" =>
          duty <= duty_in;
          case duty is
            when "000" =>
              if count1 = 19999 then
                count1 <= 0;
              elsif count1 >= 18000 then
                 count1 <= count1 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count1 <= count1 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "001" =>
              if count1 = 19999 then
                count1 <= 0;
              elsif count1 >= 13000 then
                 count1 <= count1 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count1 <= count1 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "010" =>
              if count1 = 19999 then
                count1 <= 0;
              elsif count1 >= 10000 then
                 count1 <= count1 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count1 <= count1 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "011" =>
              if count1 = 19999 then
                count1 <= 0;
              elsif count1 >= 7000 then
                 count1 <= count1 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count1 <= count1 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "100" =>
              if count1 = 19999 then
                count1 <= 0;
              elsif count1 >= 2000 then
                 count1 <= count1 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count1 <= count1 + 1;
                pulse <= '0';
                pulse_n <= '0';
              end if; 
            when others => count1 <= 0; pulse <= '0'; pulse_n <= '0'; 
          end case;--case duty 5k 
          
        when "10" =>
          duty <= duty_in;
          case duty is
            when "000" =>
              if count2 = 9999 then
                count2 <= 0;
              elsif count2 >= 9000 then
                 count2 <= count2 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count2 <= count2 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "001" =>
              if count2 = 9999 then
                count2 <= 0;
              elsif count2 >= 6500 then
                 count2 <= count2 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count2 <= count2 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
            when "010" =>
              if count2 = 9999 then
                count2 <= 0;
              elsif count2 >= 5000 then
                 count2 <= count2 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count2 <= count2 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "011" =>
              if count2 = 9999 then
                count2 <= 0;
              elsif count2 >= 3500 then
                 count2 <= count2 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count2 <= count2 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if;
             when "100" =>
              if count2 = 9999 then
                count2 <= 0;
              elsif count2 >= 1000 then
                 count2 <= count2 + 1;
                 pulse <= '1';
                 pulse_n <= '0';
              else
                count2 <= count2 + 1;
                pulse <= '0';
                pulse_n <= '1';
              end if; 
            when others => count2 <= 0; pulse <= '0'; pulse_n <= '0';
          end case;--case duty 10k          
          
        when others =>  pulse <= '0'; pulse_n <= '0'; count <= 0; count1 <= 0; count2 <= 0;
      end case; --case de frec 
    end if;
  end process combinacional;
    
END ARCHITECTURE Behavioral;