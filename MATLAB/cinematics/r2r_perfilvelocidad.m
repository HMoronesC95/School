% implementacion perfil cicloidal
% RMSE
dif_cuadrada=[];
sigmax=0;
sigmay=0;
rmsex=[];
rmsey=[];
index=[];
%
%Euler con rmse--------
counte=2;
count=1;
delta=0.1;

th=0;
r=50;

eulerx=[];
eulery=[];
eulerx(count,1)=27;
eulery(count,1)=7;
Td_x=[];
Td_y=[];

for i = 0:delta:2*pi
th=i;
T_d=[27 7+th]; % TRAYECTORIA DESEADA

Td_x(count,1)=T_d(1);%VECTOR DE X
Td_y(count,1)=T_d(2);%VECTOR DE Y

%Euler

if i<=pi
t_prima=[0 ((2*r*(i^2))/(2*pi))];
elseif i>pi
t_prima=[0 (-(2*r*(i^2))/(2*pi)+2*r*i+2*r*(1+(3*pi)/2))];
% pi
end
eulerx(counte,1)= eulerx(counte-1,1)+(delta*(t_prima(1)));%M.EULER PARA CADA PUNTO
eulery(counte,1)= eulery(counte-1,1)+(delta*(t_prima(2)));%%M.EULER PARA CADA PUNTO
counte=counte+1;

% para x
dif_cuadrada(count,1)=(Td_x(count)-eulerx(count,1))^2;
sigmax=sigmax+dif_cuadrada(count,1);
rmsex(count,1)=sqrt(sigmax/count);
% para y
dif_cuadrada(count,2)=(Td_y(count)-eulery(count,1))^2;
sigmay=sigmay+dif_cuadrada(count,1);
rmsey(count,1)=sqrt(sigmay/count);

index(count,1)=count;
count=count+1;
end

rmse=[index rmsex rmsey]

% %IMPRESION DE eslabones

figure(1)
plot(Td_x,Td_y,'color','b','LineWidth',2);
title('Trajectoria deseada vs Euler')
% axis equal
axis tight
grid on
hold on
plot(eulerx,eulery,'color','g','LineWidth',2);
legend({'Tdeseada','TPerfilV'},'Location','southwest')

% t=0:pi/360:2*pi;
% plot(200+r*cosd(th),100+r*sind(th),'o');
xlabel('Eje x')
ylabel('Eje y')
grid on