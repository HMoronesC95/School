-- VHDL Entity SCRATCH_LIB.proyecto_3_bloques.symbol
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 14:34:21 13/07/2019
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ENTITY proyecto_3_bloques IS
   PORT( 
      CLK           : IN     STD_LOGIC;
      H             : IN     STD_LOGIC;
      RST           : IN     STD_LOGIC;
      rx_in         : IN     STD_LOGIC;
      sonar_echo    : IN     STD_LOGIC;
      sonar_echo_2  : IN     STD_LOGIC;
      Anodes        : OUT    std_logic_vector (3 DOWNTO 0);
      Busy_rx       : OUT    STD_LOGIC;
      PWM_d         : OUT    std_logic;
      PWM_i         : OUT    std_logic;
      Sensor1Data   : OUT    std_logic_vector (6 DOWNTO 0);
      Sensor2Data   : OUT    std_logic_vector (6 DOWNTO 0);
      m_d           : OUT    std_logic_vector (1 DOWNTO 0);
      m_i           : OUT    std_logic_vector (1 DOWNTO 0);
      segments      : OUT    std_logic_vector (6 DOWNTO 0);
      sonar_trig    : OUT    STD_LOGIC;
      sonar_trigger : OUT    STD_LOGIC
   );

-- Declarations

END proyecto_3_bloques ;

--
-- VHDL Architecture SCRATCH_LIB.proyecto_3_bloques.struct
--
-- Created:
--          by - HP.UNKNOWN (LAPTOP-VBR26E3B)
--          at - 14:34:21 13/07/2019
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE IEEE.std_logic_unsigned.all;
USE IEEE.std_logic_signed.all;
USE IEEE.NUMERIC_STD.all;

LIBRARY SCRATCH_LIB;

ARCHITECTURE struct OF proyecto_3_bloques IS

   -- Architecture declarations

   -- Internal signal declarations
   SIGNAL B          : STD_LOGIC;
   SIGNAL cent_dece  : std_logic_vector(3 DOWNTO 0);
   SIGNAL cent_unos  : std_logic_vector(3 DOWNTO 0);
   SIGNAL centi_dece : std_logic_vector(3 DOWNTO 0);
   SIGNAL centi_unos : std_logic_vector(3 DOWNTO 0);
   SIGNAL verif_in   : STD_LOGIC_VECTOR(7 DOWNTO 0);


   -- Component Declarations
   COMPONENT PWM_derecha
   PORT (
      CLK   : IN     STD_LOGIC;
      RST   : IN     STD_LOGIC;
      PWM_d : OUT    std_logic
   );
   END COMPONENT;
   COMPONENT PWM_izquierda
   PORT (
      CLK   : IN     STD_LOGIC;
      RST   : IN     STD_LOGIC;
      PWM_i : OUT    std_logic
   );
   END COMPONENT;
   COMPONENT ProcessSignal
   PORT (
      CLK             : IN     std_logic;
      Sensor1Decenas  : IN     std_logic_vector (3 DOWNTO 0);
      Sensor1Unidades : IN     std_logic_vector (3 DOWNTO 0);
      Sensor2Decenas  : IN     std_logic_vector (3 DOWNTO 0);
      Sensor2Unidades : IN     std_logic_vector (3 DOWNTO 0);
      Anodes          : OUT    std_logic_vector (3 DOWNTO 0);
      Sensor1Data     : OUT    std_logic_vector (6 DOWNTO 0);
      Sensor2Data     : OUT    std_logic_vector (6 DOWNTO 0);
      segments        : OUT    std_logic_vector (6 DOWNTO 0)
   );
   END COMPONENT;
   COMPONENT RX
   PORT (
      B       : IN     STD_LOGIC;
      CLK     : IN     STD_LOGIC;
      RST     : IN     STD_LOGIC;
      rx_in   : IN     STD_LOGIC;
      Busy_rx : OUT    STD_LOGIC;
      verif   : OUT    STD_LOGIC_VECTOR (7 DOWNTO 0)
   );
   END COMPONENT;
   COMPONENT base_tiempo
   GENERIC (
      K : integer := 10416;      --constante del comparador
      N : integer := 22          -- numero de bits del contador
   );
   PORT (
      CLK : IN     STD_LOGIC;
      H   : IN     STD_LOGIC;
      RST : IN     STD_LOGIC;
      BT  : OUT    STD_LOGIC
   );
   END COMPONENT;
   COMPONENT control_motor
   PORT (
      CLK      : IN     STD_LOGIC;
      RST      : IN     STD_LOGIC;
      verif_in : IN     STD_LOGIC_VECTOR (7 DOWNTO 0);
      m_d      : OUT    std_logic_vector (1 DOWNTO 0);
      m_i      : OUT    std_logic_vector (1 DOWNTO 0)
   );
   END COMPONENT;
   COMPONENT sonar
   PORT (
      clk        : IN     STD_LOGIC;
      sonar_echo : IN     STD_LOGIC;
      centi_dece : OUT    std_logic_vector (3 DOWNTO 0);
      centi_unos : OUT    std_logic_vector (3 DOWNTO 0);
      sonar_trig : OUT    STD_LOGIC
   );
   END COMPONENT;
   COMPONENT sonar2
   PORT (
      clk           : IN     STD_LOGIC;
      sonar_echo_2  : IN     STD_LOGIC;
      cent_dece     : OUT    std_logic_vector (3 DOWNTO 0);
      cent_unos     : OUT    std_logic_vector (3 DOWNTO 0);
      sonar_trigger : OUT    STD_LOGIC
   );
   END COMPONENT;

   -- Optional embedded configurations
   -- pragma synthesis_off
   FOR ALL : PWM_derecha USE ENTITY SCRATCH_LIB.PWM_derecha;
   FOR ALL : PWM_izquierda USE ENTITY SCRATCH_LIB.PWM_izquierda;
   FOR ALL : ProcessSignal USE ENTITY SCRATCH_LIB.ProcessSignal;
   FOR ALL : RX USE ENTITY SCRATCH_LIB.RX;
   FOR ALL : base_tiempo USE ENTITY SCRATCH_LIB.base_tiempo;
   FOR ALL : control_motor USE ENTITY SCRATCH_LIB.control_motor;
   FOR ALL : sonar USE ENTITY SCRATCH_LIB.sonar;
   FOR ALL : sonar2 USE ENTITY SCRATCH_LIB.sonar2;
   -- pragma synthesis_on


BEGIN

   -- Instance port mappings.
   U_3 : PWM_derecha
      PORT MAP (
         CLK   => CLK,
         RST   => RST,
         PWM_d => PWM_d
      );
   U_4 : PWM_izquierda
      PORT MAP (
         CLK   => CLK,
         RST   => RST,
         PWM_i => PWM_i
      );
   U_8 : ProcessSignal
      PORT MAP (
         CLK             => CLK,
         Sensor1Decenas  => centi_dece,
         Sensor1Data     => Sensor1Data,
         Sensor2Data     => Sensor2Data,
         Sensor1Unidades => centi_unos,
         Sensor2Decenas  => cent_dece,
         Sensor2Unidades => cent_unos,
         Anodes          => Anodes,
         segments        => segments
      );
   U_5 : RX
      PORT MAP (
         CLK     => CLK,
         RST     => RST,
         B       => B,
         rx_in   => rx_in,
         verif   => verif_in,
         Busy_rx => Busy_rx
      );
   U_0 : base_tiempo
      GENERIC MAP (
         K => 10416,         --constante del comparador
         N => 22             -- numero de bits del contador
      )
      PORT MAP (
         CLK => CLK,
         RST => RST,
         H   => H,
         BT  => B
      );
   U_2 : control_motor
      PORT MAP (
         verif_in => verif_in,
         CLK      => CLK,
         RST      => RST,
         m_d      => m_d,
         m_i      => m_i
      );
   U_6 : sonar
      PORT MAP (
         clk        => CLK,
         sonar_trig => sonar_trig,
         sonar_echo => sonar_echo,
         centi_unos => centi_unos,
         centi_dece => centi_dece
      );
   U_7 : sonar2
      PORT MAP (
         clk           => CLK,
         sonar_trigger => sonar_trigger,
         cent_unos     => cent_unos,
         cent_dece     => cent_dece,
         sonar_echo_2  => sonar_echo_2
      );

END struct;
