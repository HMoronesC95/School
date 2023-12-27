
clc
clear all
close all

%Rotación en Y 180°     
Ry=[ cosd(180)           0          sind(180)   0;
        0              1                0       0;
     -sind(180)           0         cosd(180)  0;
        0               0               0       1;];
      
%Rotación en Z -90   
Rz= [  cosd(-90)      -sind(-90)      0    0;
        sind(-90)       cosd(-90)      0   0;
          0             0              1   0;
          0             0              0   1;];
      
      
%Traslacion
Tr= [  1      0      0    2;
       0      1      0    -8;
       0      0      1    1;
       0      0      0    1];
 
%Operacion
M=Ry*Rz*Tr
   