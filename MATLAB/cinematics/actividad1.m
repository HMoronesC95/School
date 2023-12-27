clc
clear all

% DATOS PARA MTH ---------------------------------------
syms theta_1;
syms theta_2;
syms theta_3;
syms theta_4;
syms theta_5;
syms theta_6;

syms d_1;
syms d_2;
syms d_3;
syms d_4;
syms d_5;
syms d_6;

syms a_1;
syms a_2;
syms a_3;
syms a_4;
syms a_5;
syms a_6;

syms alpha_1;
syms alpha_2;
syms alpha_3;
syms alpha_4;
syms alpha_5;
syms alpha_6;

%Matrices de transformacion homogenea-----------------------

A1 = [cos(theta_1) -cos(alpha_1)*sin(theta_1) sin(alpha_1)*sin(theta_1) a_1*cos(theta_1);
      sin(theta_1) cos(alpha_1)*cos(theta_1) -sin(alpha_1)*cos(theta_1) a_1*sin(theta_1);
           0               sin(alpha_1)                 cos(alpha_1)              d_1       ;
           0                    0                            0                      1        ;]
A2 = [cos(theta_2) -cos(alpha_2)*sin(theta_2) sin(alpha_2)*sin(theta_2) a_2*cos(theta_2);
      sin(theta_2) cos(alpha_2)*cos(theta_2) -sin(alpha_2)*cos(theta_2) a_2*sin(theta_2);
           0               sin(alpha_2)                 cos(alpha_2)              d_2       ;
           0                    0                            0                      1        ;]
A3 = [cos(theta_3) -cos(alpha_3)*sin(theta_3) sin(alpha_3)*sin(theta_3) a_3*cos(theta_3);
      sin(theta_3) cos(alpha_3)*cos(theta_3) -sin(alpha_3)*cos(theta_3) a_2*sin(theta_3);
           0               sin(alpha_3)                 cos(alpha_3)              d_3       ;
           0                    0                            0                      1        ;]
A4 = [cos(theta_4) -cos(alpha_4)*sin(theta_4) sin(alpha_4)*sin(theta_4) a_4*cos(theta_4);
      sin(theta_4) cos(alpha_4)*cos(theta_4) -sin(alpha_4)*cos(theta_4) a_4*sin(theta_4);
           0               sin(alpha_4)                 cos(alpha_4)              d_4       ;
           0                    0                            0                      1        ;]
A5 = [cos(theta_5) -cos(alpha_5)*sin(theta_5) sin(alpha_5)*sin(theta_5) a_5*cos(theta_5);
      sin(theta_5) cos(alpha_5)*cos(theta_5) -sin(alpha_5)*cos(theta_5) a_5*sin(theta_5);
           0               sin(alpha_5)                 cos(alpha_5)              d_5       ;
           0                    0                            0                      1        ;]
A6 = [cos(theta_6) -cos(alpha_6)*sin(theta_6) sin(alpha_6)*sin(theta_6) a_6*cos(theta_6);
      sin(theta_6) cos(alpha_6)*cos(theta_6) -sin(alpha_6)*cos(theta_6) a_6*sin(theta_6);
           0               sin(alpha_6)                 cos(alpha_6)              d_6       ;
           0                    0                            0                      1        ;]
B1 = [cos(theta_1) -cos(alpha_1)*sin(theta_1) sin(alpha_1)*sin(theta_1)        0        ;
      sin(theta_1) cos(alpha_1)*cos(theta_1) -sin(alpha_1)*cos(theta_1)        0        ;
           0               sin(alpha_1)                 cos(alpha_1)              d_1       ;
           0                    0                            0                      1        ;]
B2 = [cos(theta_2) -cos(alpha_2)*sin(theta_2) sin(alpha_2)*sin(theta_2)        0        ;
      sin(theta_2) cos(alpha_2)*cos(theta_2) -sin(alpha_2)*cos(theta_2)        0        ;
           0               sin(alpha_2)                 cos(alpha_2)              d_2       ;
           0                    0                            0                      1        ;]
B3 = [cos(theta_3) -cos(alpha_3)*sin(theta_3) sin(alpha_3)*sin(theta_3)        0        ;
      sin(theta_3) cos(alpha_3)*cos(theta_3) -sin(alpha_3)*cos(theta_3)        0        ;
           0               sin(alpha_3)                 cos(alpha_3)              d_3       ;
           0                    0                            0                      1        ;]
B4 = [cos(theta_4) -cos(alpha_4)*sin(theta_4) sin(alpha_4)*sin(theta_4)        0        ;
      sin(theta_4) cos(alpha_4)*cos(theta_4) -sin(alpha_4)*cos(theta_4)        0        ;
           0               sin(alpha_4)                 cos(alpha_4)              d_4       ;
           0                    0                            0                      1        ;]
B5 = [cos(theta_5) -cos(alpha_5)*sin(theta_5) sin(alpha_5)*sin(theta_5)        0        ;
      sin(theta_5) cos(alpha_5)*cos(theta_5) -sin(alpha_5)*cos(theta_5)        0        ;
           0               sin(alpha_5)                 cos(alpha_5)              d_5       ;
           0                    0                            0                      1        ;]
B6 = [cos(theta_6) -cos(alpha_6)*sin(theta_6) sin(alpha_6)*sin(theta_6)        0        ;
      sin(theta_6) cos(alpha_6)*cos(theta_6) -sin(alpha_6)*cos(theta_6)        0        ;
           0               sin(alpha_6)                 cos(alpha_6)              d_6       ;
           0                    0                            0                      1        ;]
%Calculo de matriz T------------------------------------------------------
T=A1*A2*B3
%M=simplify(T)
%Angulos de Euler convencion ZXZ--------------------------------
alpha_y=T(1,3)
alpha_x=-T(2,3)
alpha=atan2((T(1,3)),(-T(2,3)))
beta_y=T(1,3)*sin(alpha)-T(2,3)
beta_x=T(3,3)
beta=atan2((T(1,3)*sin(alpha)-T(2,3)),T(3,3))
gamma_y=-T(1,2)*cos(alpha)-T(2,2)*sin(alpha)
gamma_x=T(1,1)*cos(alpha)+T(2,1)*sin(alpha)
gamma=atan2((-T(1,2)*cos(alpha)-T(2,2)*sin(alpha)),(T(1,1)*cos(alpha)+T(2,1)*sin(alpha)))

% DATOS NUMERICOS----------------------------------------------------

theta_1=-(60)*(pi/180);
theta_2=-(90)*(pi/180);
theta_3=(30)*(pi/180);
theta_4=(25)*(pi/180);
theta_5=(45)*(pi/180);
theta_6=(13)*(pi/180);

d_1=350;
d_2=0;
d_3=0;
d_4=290;
d_5=0;
d_6=100;

a_1=150;
a_2=250;
a_3=75;
a_4=0;
a_5=0;
a_6=0;

alpha_1=(90)*(pi/180);
alpha_2=(0)*(pi/180);
alpha_3=(90)*(pi/180);
alpha_4=-(90)*(pi/180);
alpha_5=(90)*(pi/180);
alpha_6=(0)*(pi/180);

%Matrices de transformacion homogenea-----------------------

A1 = [cos(theta_1) -cos(alpha_1)*sin(theta_1) sin(alpha_1)*sin(theta_1) a_1*cos(theta_1);
      sin(theta_1) cos(alpha_1)*cos(theta_1) -sin(alpha_1)*cos(theta_1) a_1*sin(theta_1);
           0               sin(alpha_1)                 cos(alpha_1)              d_1       ;
           0                    0                            0                      1        ;]
A2 = [cos(theta_2) -cos(alpha_2)*sin(theta_2) sin(alpha_2)*sin(theta_2) a_2*cos(theta_2);
      sin(theta_2) cos(alpha_2)*cos(theta_2) -sin(alpha_2)*cos(theta_2) a_2*sin(theta_2);
           0               sin(alpha_2)                 cos(alpha_2)              d_2       ;
           0                    0                            0                      1        ;]
A3 = [cos(theta_3) -cos(alpha_3)*sin(theta_3) sin(alpha_3)*sin(theta_3) a_3*cos(theta_3);
      sin(theta_3) cos(alpha_3)*cos(theta_3) -sin(alpha_3)*cos(theta_3) a_3*sin(theta_3);
           0               sin(alpha_3)                 cos(alpha_3)              d_3       ;
           0                    0                            0                      1        ;]
A4 = [cos(theta_4) -cos(alpha_4)*sin(theta_4) sin(alpha_4)*sin(theta_4) a_4*cos(theta_4);
      sin(theta_4) cos(alpha_4)*cos(theta_4) -sin(alpha_4)*cos(theta_4) a_4*sin(theta_4);
           0               sin(alpha_4)                 cos(alpha_4)              d_4       ;
           0                    0                            0                      1        ;]
A5 = [cos(theta_5) -cos(alpha_5)*sin(theta_5) sin(alpha_5)*sin(theta_5) a_5*cos(theta_5);
      sin(theta_5) cos(alpha_5)*cos(theta_5) -sin(alpha_5)*cos(theta_5) a_5*sin(theta_5);
           0               sin(alpha_5)                 cos(alpha_5)              d_5       ;
           0                    0                            0                      1        ;]
A6 = [cos(theta_6) -cos(alpha_6)*sin(theta_6) sin(alpha_6)*sin(theta_6) a_6*cos(theta_6);
      sin(theta_6) cos(alpha_6)*cos(theta_6) -sin(alpha_6)*cos(theta_6) a_6*sin(theta_6);
           0               sin(alpha_6)                 cos(alpha_6)              d_6       ;
           0                    0                            0                      1        ;]
B1 = [cosd(theta_1) -cosd(alpha_1)*sind(theta_1) sind(alpha_1)*sind(theta_1)        0        ;
      sind(theta_1) cosd(alpha_1)*cosd(theta_1) -sind(alpha_1)*cosd(theta_1)        0        ;
           0               sind(alpha_1)                 cosd(alpha_1)              d_1       ;
           0                    0                            0                      1        ;]
B2 = [cosd(theta_2) -cosd(alpha_2)*sind(theta_2) sind(alpha_2)*sind(theta_2)        0        ;
      sind(theta_2) cosd(alpha_2)*cosd(theta_2) -sind(alpha_2)*cosd(theta_2)        0        ;
           0               sind(alpha_2)                 cosd(alpha_2)              d_2       ;
           0                    0                            0                      1        ;]
B3 = [cosd(theta_3) -cosd(alpha_3)*sind(theta_3) sind(alpha_3)*sind(theta_3)        0        ;
      sind(theta_3) cosd(alpha_3)*cosd(theta_3) -sind(alpha_3)*cosd(theta_3)        0        ;
           0               sind(alpha_3)                 cosd(alpha_3)              d_3       ;
           0                    0                            0                      1        ;]
B4 = [cosd(theta_4) -cosd(alpha_4)*sind(theta_4) sind(alpha_4)*sind(theta_4)        0        ;
      sind(theta_4) cosd(alpha_4)*cosd(theta_4) -sind(alpha_4)*cosd(theta_4)        0        ;
           0               sind(alpha_4)                 cosd(alpha_4)              d_4       ;
           0                    0                            0                      1        ;]
B5 = [cosd(theta_5) -cosd(alpha_5)*sind(theta_5) sind(alpha_5)*sind(theta_5)        0        ;
      sind(theta_5) cosd(alpha_5)*cosd(theta_5) -sind(alpha_5)*cosd(theta_5)        0        ;
           0               sind(alpha_5)                 cosd(alpha_5)              d_5       ;
           0                    0                            0                      1        ;]
B6 = [cosd(theta_6) -cosd(alpha_6)*sind(theta_6) sind(alpha_6)*sind(theta_6)        0        ;
      sind(theta_6) cosd(alpha_6)*cosd(theta_6) -sind(alpha_6)*cosd(theta_6)        0        ;
           0               sind(alpha_6)                 cosd(alpha_6)              d_6       ;
           0                    0                            0                      1        ;]

%Calculo de matriz T------------------------------------------------------
T=A1*A2*A3*A4*A5*A6
%Angulos de Euler convencion ZXZ--------------------------------
alpha_y=T(1,3)
alpha_x=-T(2,3)
alpha=atan2((T(1,3)),(-T(2,3)))*(180/pi)
beta_y=T(1,3)*sind(alpha)-T(2,3)
beta_x=T(3,3)
beta=atan2((T(1,3)*sind(alpha)-T(2,3)*cosd(alpha)),T(3,3))*(180/pi)
gamma_y=-T(1,2)*cosd(alpha)-T(2,2)*sind(alpha)
gamma_x=T(1,1)*cosd(alpha)+T(2,1)*sind(alpha)
gamma=atan2((-T(1,2)*cosd(alpha)-T(2,2)*sind(alpha)),(T(1,1)*cosd(alpha)+T(2,1)*sind(alpha)))*(180/pi)
