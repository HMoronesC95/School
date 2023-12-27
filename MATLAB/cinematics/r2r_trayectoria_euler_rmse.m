
%DATOS GEOMETRICOS Y TRAYECTORIA

count=1;
%VECTORES DE IMPRESION DE DATOS
T_deseada=[];
Tra_Euler=[];
Datos=[];
%VARIABLES PARA EULER
delta=1;
eulerx=[];
eulery=[];
eulerx(count,1)=20;
eulery(count,1)=0;
Td_x=[];
Td_y=[];

teuler1=[];
teuler2=[];
teuler1(count,1)=28.95;
teuler2(count,1)=104.47;
incremento=delta;
for i = 0:incremento:20;
th=i;
T_d=[20 th]; % TRAYECTORIA DESEADA
Td_x(count,1)=T_d(1);%VECTOR DE X
Td_y(count,1)=T_d(2);%VECTOR DE Y
count=count+1;
pause(0.001);
end
%%
%Euler
count=1;

%RMSE
dif_cuadrada=[];
sigmax=0;
sigmay=0;
rmsex=[];
rmsey=[];
index=[];
%
counte=2;
e_propuesto=2;

for i=0:delta:20
th=i;
t_prima=[0 th];%DERIVADA DE LA POSICION EN CADA PUNTO [X Y Z]
eulerx(counte,1)= 20;%M.EULER PARA CADA PUNTO
eulery(counte,1)= eulery(counte-1,1)+(delta);%%M.EULER PARA CADA PUNTO
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

%///////////////////////////////////////////////////////////////
% IMPRESION DE TRAYECTORIAS
figure(1)
plot(Td_x,Td_y,'color','b','LineWidth',1);
title('Trajectoria deseada vs Euler')
% axis equal
axis tight
xlim([0 40]);
ylim([0 30]);
grid on
hold on
plot(eulerx,eulery,'color','g','LineWidth',2);
legend({'Tdeseada','TEuler'},'Location','southwest')
t=0:pi/360:2*pi;
plot(200+50*cos(t),100+50*sin(t),200,100,'o')
xlabel('Eje x')
ylabel('Eje y')
grid on
length(eulerx)
eulerx
length(eulery)
eulery




