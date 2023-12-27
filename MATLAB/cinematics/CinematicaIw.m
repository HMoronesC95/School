%Cinemática directa e inversa

clc
clear all

%PASOS PARA CINEMATICA INVERSA
%Se considera una matriz conocida T
%Verificar cuantas articulaciones son 
%1 Parametros DH
%2 Sustituir en las MTH los datos conocidos (alpha,d,a)

%ANGULOS Y LONGITUDES DE PARAMETROS DENAVIT-HARTENBERG
%%
% Variables simbolicas

syms  th1 th2 %th3
 %syms  theta2 %theta3 theta4 %theta5 theta6 
syms  alp1 alp2 %alp3 %alpha3 alpha4 %alpha5 alpha6 
syms  a1 a2 %a3  %a4 %a5 a6 
syms  d1 d2 %d3 %d3 d4 %d5 d6

% syms theta1p theta2p %theta3p %theta4p
% syms d1p d2p %d3p d4p
 
 
%%

%%
%==========================================================================
%De matriz conocida
 %T= [0 0 1 255;0 -1 0 0 ;1 0 0 400;0 0 0 1]

 %%
 %=========================================================================
 %Datos conocidos 
 %theta1=; theta2=; theta3=; theta4=; theta5=; theta6=; 
%  theta1=(90)*(pi/180);
%  theta2=(0)*(pi/180);
%  %theta3=(0)*(pi/180);
%  %theta4=(-90)*(pi/180);
%  %theta3=(0)*(pi/180);
%  alpha1=(90)*(pi/180); %alpha2=(-90)*(pi/180); alpha3=(0)*(pi/180); alpha4=(90)*(pi/180); % alpha5=;  alpha6=; 
%  a1=0; a2=0; %a3=0; a4=2; %a5=; a6=; 
%  d1=0; d2=2; %d3=180; 
 %d3=3; d4=0; %d5=; d6=;
 
%%

%========================================================================================
%                                   SIMBOLICO
%========================================================================================

%MATRICES DE TRANSFORMACION HOMOGENEA
%
%%
% %Sistema coordenado 1 respecto al 0
% 
% A01=[ cos(theta1)  -cos(alpha1)*sin(theta1)  sin(alpha1)*sin(theta1)  a1*cos(theta1)
%      sin(theta1)  cos(alpha1)*cos(theta1)   -sin(alpha1)*cos(theta1)  a1*sin(theta1)  
%           0                 sin(alpha1)              cos(alpha1)                d1      
%           0                      0                         0                       1     ] 
% %%
% 
% %%
% %Sistema coordenado 2 respecto al 1  
% A12=[ cos(theta2)  -cos(alpha2)*sin(theta2)  sin(alpha2)*sin(theta2)  a2*cos(theta2)
%       sin(theta2)  cos(alpha2)*cos(theta2)   -sin(alpha2)*cos(theta2) a2*sin(theta2) 
%             0              sin(alpha2)               cos(alpha2)                d2      
%             0                     0                       0                        1     ]
% %%
% 
% %%
% %Sistema coordenado 3 respecto al 2 
% A23=[ cos(theta3)  -cos(alpha3)*sin(theta3)  sin(alpha3)*sin(theta3)  a3*cos(theta3)
%      sin(theta3)   cos(alpha3)*cos(theta3)  -sin(alpha3)*cos(theta3)  a3*sin(theta3)  
%          0                 sin(alpha3)              cos(alpha3)                 d3      
%          0                     0                           0                       1     ]
% %%
% 
% %%
% % %Sistema coordenado 4 respecto al 3
% A34=[ cos(theta4)  -cos(alpha4)*sin(theta4)  sin(alpha4)*sin(theta4)  a4*cos(theta4)
%       sin(theta4)   cos(alpha4)*cos(theta4) -sin(alpha4)*cos(theta4)  a4*sin(theta4)  
%             0              sin(alpha4)                cos(alpha4)               d4      
%             0                     0                   0                            1     ]
%%

%%
% %Sistema coordenado 5 respecto al 4
% A45=[ cos(theta5)  -cos(alpha5)*sin(theta5)  sin(alpha5)*sin(theta5)   a5*cos(theta5);
%       sin(theta5)  cos(alpha5)*cos(theta5)  -sin(alpha5)*cos(theta5)   a5*sin(theta5);  
%            0                 sin(alpha5)          cos(alpha5)                   d5       ;
%            0                     0                     0                           1      ]
%%

%%
% %Sistema coordenado 6 respecto al 5
% A56=[ cos(theta6)  -cos(alpha6)*sin(theta6)  sin(alpha6)*sin(theta6)  a6*cos(theta6);
%       sin(theta6)  cos(alpha6)*cos(theta6)  -sin(alpha6)*cos(theta6)  a6*sin(theta6);  
%             0                 sin(alpha6)          cos(alpha6)                  d6      ;
%             0                     0                       0                        1     ]
%%

%%

% %Sistema coordenado 1 respecto al 0

A01=[ cos(th1)  -cos(alp1)*sin(th1)  sin(alp1)*sin(th1)   a1*cos(th1)
      sin(th1)  cos(alp1)*cos(th1)   -sin(alp1)*cos(th1)  a1*sin(th1)  
          0         sin(alp1)              cos(alp1)          d1      
          0              0                     0               1     ] 
%%

%%
%Sistema coordenado 2 respecto al 1  
A12=[ cos(th2)  -cos(alp2)*sin(th2)  sin(alp2)*sin(th2)   a2*cos(th2)
      sin(th2)  cos(alp2)*cos(th2)   -sin(alp2)*cos(th2)  a2*sin(th2)  
          0         sin(alp2)              cos(alp2)          d2      
          0              0                     0               1     ]
%%
%%
% %Sistema coordenado 3 respecto al 2  
% A23=[ cos(th3)  -cos(alp3)*sin(th3)  sin(alp3)*sin(th3)   a3*cos(th3)
%       sin(th3)  cos(alp3)*cos(th3)   -sin(alp3)*cos(th3)  a3*sin(th3)  
%           0         sin(alp3)              cos(alp3)          d3      
%           0              0                     0               1     ]
%%


A01S=A01
A02S=A01*A12
%A03S=A01*A12*A23

% d1=65; d2=0; d3=83;
th1=60; th2=0;
d1=0;d2=0;
alp1=pi/2; alp2=pi/2; %alp3=0;
a1=3; a2=4; %a3=0;

% %Sistema coordenado 1 respecto al 0

A01=[ cos(th1)  -cos(alp1)*sin(th1)  sin(alp1)*sin(th1)   a1*cos(th1)
      sin(th1)  cos(alp1)*cos(th1)   -sin(alp1)*cos(th1)  a1*sin(th1)  
          0         sin(alp1)              cos(alp1)          d1      
          0              0                     0               1     ] 
%%

%%
%Sistema coordenado 2 respecto al 1  
A12=[ cos(th2)  -cos(alp2)*sin(th2)  sin(alp2)*sin(th2)   a2*cos(th2)
      sin(th2)  cos(alp2)*cos(th2)   -sin(alp2)*cos(th2)  a2*sin(th2)  
          0         sin(alp2)              cos(alp2)          d2      
          0              0                     0               1     ]
%%
%%
%Sistema coordenado 3 respecto al 2  
% A23=[ cos(th3)  -cos(alp3)*sin(th3)  sin(alp3)*sin(th3)   a3*cos(th3)
%       sin(th3)  cos(alp3)*cos(th3)   -sin(alp3)*cos(th3)  a3*sin(th3)  
%           0         sin(alp3)              cos(alp3)          d3      
%           0              0                     0               1     ]
%%


A01N=A01
A02N=A01*A12
% A03N=A01*A12*A23
simplify(A02N)

% A01S=A01
% A02S=A01*A12
% A03S=A01*A12*A23
% A04S=A01*A12*A23*A34
%A05S=A01*A12*A23*A34*A45;
%A06S=A01*A12*A23*A34*A45*A56;
% T=simplify(A04S)
% T=A04S
jacobian(T,[theta1p d2p theta3p theta4p])
jacobian(T(:,1),theta1p)
jacobian(T(:,2),d2p)
jacobian(T(:,3),theta3p)
jacobian(T(:,4),theta4p)
T=vpa(T,2)
%T=round(A04S,2)
%%

%%

%POSICION SIMBOLICA
%PA01S=A01S(1:4,4)
%PA02S=A02S(1:4,4)
%PA03S=A03S(1:4,4)
PA04S=A04S(1:4,4)
%PA05S=A05S(1:4,4)
%PA06S=A06S(1:4,4)

%ROTACION SIMBOLICA
%RA01S=A01S(1:3,1:3)
%RA02S=A02S(1:3,1:3)
%RA03S=A03S(1:3,1:3)
RA04S=A04S(1:3,1:3)
%RA05S=A05S(1:3,1:3)
%RA06S=A06S(1:3,1:3)

%TRANSPUESTA SIMBOLICA
% TRA01S= transpose(RA01S)
% TRA02S= transpose(RA02S)
% TRA03S= transpose(RA03S)
% TRA04S= transpose(RA04S)
% TRA05S= transpose(RA05S)
% TRA06S= transpose(RA06S)

%Matrices inversas 
% A01I=inv(PA01S)
% simplify(A01I)
% 
% A12I=inv(A12)
% simplify(A12I)
% 
% %Matrices auxiliares
% 
% A2=A12*A23
% 
% aux2=A12I*A01I
% simplify(aux2)
% 
% A23



%=========================================================================================
%TERMINA SIMBOLICO
%=========================================================================================
%%
%%
%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
%                                NUMERICO
%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
%%

%%Variables numericas

%THETA
%2 art
% theta1=0;theta2=0;
%3 art
%  theta1=45;theta2=0;theta3=30;
%4 art
%  theta1=-90;theta2=90;theta3=0;theta4=45;
%5 art
%theta1=0;theta2=0;theta3=-90;theta4=0;theta5=-90;
%6 art
%theta1=115;theta2=-120;theta3=15;theta4=45;theta5=30;theta6=-45;

%ALPHA
%2 art
% alpha1=0;alpha2=0;
%3 art
%alpha1=0;alpha2=90;alpha3=0;
%4 art
%  alpha1=0;alpha2=90;alpha3=0;alpha4=0;
%5 art 
%alpha1=0;alpha2=0;alpha3=0;alpha4=0;alpha5=0;
%6 art
%alpha1=-90;alpha2=0;alpha3=-90;alpha4=90;alpha5=-90;alpha6=0;

%DISTANCIAS A
%2 art
% a1=0;a2=0;
%3 art
% a1=20;a2=10;a3=5;
%4 art
%  a1=0;a2=0;a3=0;a4=0;
%5 art
% a1=0;a2=0;a3=0;a4=0;a5=0;
%6 art
% a1=150;a2=250;a3=75;a4=0;a5=0;a6=0;

%DISTANCIAS D
%2 art
% d1= 0; d2= 0.2;
%3 art
% d1= 0; d2= 0; d3= 0; 
%4 art
%  d1= 150; d2= 250; d3=180; d4= 75; 
%5 art
% d1= 0; d2= 0.2; d3= 0.5; d4= 0; d5= 0;
%6 art
% d1=350; d2= 0; d3= 0; d4=290; d5= 0; d6= 80;
 
%%

%%
% % %Sistema coordenado 1 respecto al 0
%  A01=[ cosd(theta1)  -cosd(alpha1)*sind(theta1)  sind(alpha1)*sind(theta1)  a1*cosd(theta1);
%      sind(theta1)  cosd(alpha1)*cosd(theta1)   -sind(alpha1)*cosd(theta1)  a1*sind(theta1);  
%           0                 sind(alpha1)              cosd(alpha1)                d1      ;
%           0                      0                         0                       1     ];
%%

%%
%Sistema coordenado 2 respecto al 1  
% A12=[ cosd(theta2)  -cosd(alpha2)*sind(theta2)  sind(alpha2)*sind(theta2)  a2*cosd(theta2);
%       sind(theta2)  cosd(alpha2)*cosd(theta2)   -sind(alpha2)*cosd(theta2) a2*sind(theta2);  
%             0              sind(alpha2)               cosd(alpha2)                d2      ;
%             0                     0                       0                        1     ];
%%

%%
%Sistema coordenado 3 respecto al 2 
% A23=[ cosd(theta3)  -cosd(alpha3)*sind(theta3)  sind(alpha3)*sind(theta3)  a3*cosd(theta3);
%      sind(theta3)   cosd(alpha3)*cosd(theta3)  -sind(alpha3)*cosd(theta3)  a3*sind(theta3);  
%          0                 sind(alpha3)              cosd(alpha3)                 d3      ;
%          0                     0                           0                       1     ];
%%     

%%
% Sistema coordenado 4 respecto al 3
% A34=[ cosd(theta4)  -cosd(alpha4)*sind(theta4)  sind(alpha4)*sind(theta4)  a4*cosd(theta4);
%       sind(theta4)   cosd(alpha4)*cosd(theta4) -sind(alpha4)*cosd(theta4)  a4*sind(theta4);  
%             0              sind(alpha4)                cosd(alpha4)               d4      ;
%             0                     0                   0                            1     ]
% %%

% %%
% %Sistema coordenado 5 respecto al 4
% A45=[ cosd(theta5)  -cosd(alpha5)*sind(theta5)  sind(alpha5)*sind(theta5)   a5*cosd(theta5);
%       sind(theta5)  cosd(alpha5)*cosd(theta5)  -sind(alpha5)*cosd(theta5)   a5*sind(theta5);  
%            0                 sind(alpha5)          cosd(alpha5)                   d5       ;
%            0                     0                     0                           1      ];
% %%
%  
% %%            
% %Sistema coordenado 6 respecto al 5
% A56=[ cosd(theta6)  -cosd(alpha6)*sind(theta6)  sind(alpha6)*sind(theta6)  a6*cosd(theta6);
%       sind(theta6)  cosd(alpha6)*cosd(theta6)  -sind(alpha6)*cosd(theta6)  a6*sind(theta6);  
%             0                 sind(alpha6)          cosd(alpha6)                  d6      ;
%             0                     0                       0                        1     ];
%%  

% A01=A01
% A02=A01*A12
% A03=A01*A12*A23
% A04=A01*A12*A23*A34;
% A05=A01*A12*A23*A34*A45;
% A06=A01*A12*A23*A34*A45*A56;
% T=A04
%%

%%
% ANGULOS EULER            
% Raux= [ t11 t12 t13;
%         t21 t22 t23;
%         t31 t32 t33];

 t=A04S;
% 
 Alpha= atan2d(t(1,3),-t(2,3))
 Beta= atan2d((t(1,3)*sind(Alpha)- t(2,3)*cosd(Alpha)),t(3,3))
 Gamma= atan2d(((-t(1,2)*cosd(Alpha))-(t(2,2)*sind(Alpha))),((t(1,1)*cosd(Alpha))+ (t(2,1)*sind(Alpha))))
% 
% 
% X= [ t(1,4);
%      t(2,4);
%      t(3,4);
%      Alpha;
%      Beta;
%      Gamma]
 
%%