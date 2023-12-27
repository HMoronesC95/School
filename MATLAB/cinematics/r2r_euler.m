clc
clear all
%DATOS GEOMETRICOS Y TRAYECTORIA
% r=2;
count=1;
%VECTORES DE IMPRESION DE DATOS
T_deseada=[];
Tra_Euler=[];
Datos=[];
%VARIABLES PARA EULER
delta=0.1;
eulerx=[];
eulery=[];
eulerx(count,1)=20;
eulery(count,1)=0;
Td_x=[];
Td_y=[];
theta=[0,0];

teuler1=[];
teuler2=[];
teuler1(count,1)=0;
teuler2(count,1)=0;

incremento=delta;
for i = 0:incremento:15;
th=i;
T_d=[20 th]; % TRAYECTORIA DESEADA
Td_x(count,1)=T_d(1);%VECTOR DE X
Td_y(count,1)=T_d(2);%VECTOR DE Y
count=count+1;
% pause(0.001);
end
%%
%Euler
count=2;


% 
for i=0:delta:15
th=i;
t_prima=[0 th];%DERIVADA DE LA POSICION EN CADA PUNTO [X Y Z]
eulerx(count,1)= eulerx(count-1,1)+(delta*(t_prima(1)));%M.EULER PARA CADA PUNTO
eulery(count,1)= eulery(count-1,1)+(delta);%%M.EULER PARA CADA PUNTO
% teuler1(count,1)= teuler1(count-1,1)+(delta*(t_prima(1)));%M.EULER PARA CADA PUNTO
% teuler2(count,1)= teuler2(count-1,1)+(delta*(t_prima(2)));%%M.EULER PARA CADA PUNTO

count=count+1;
end
writerObj = VideoWriter('Trayectoria.avi');
writerObj.FrameRate = 1;
open(writerObj);
% IMPRESION DE TRAYECTORIAS
figure(1)
plot(Td_x,Td_y,'color','b','LineWidth',2);
title('Trajectoria deseada vs Euler')
% axis equal
axis tight
xlim([-10 40]);
ylim([-20 40]);
grid on
hold on
plot(eulerx,eulery,'color','g','LineWidth',2);
legend({'Tdeseada','TEuler'},'Location','southwest')
% t=0:pi/360:2*pi;
% plot(200+50*cos(t),100+50*sin(t),200,100,'o')
xlabel('Eje x')
ylabel('Eje y')
grid on
length(eulerx)
eulerx
length(eulery)
eulery
% 
% length(eulerx)
% teuler1
% length(eulery)
% teuler2

% figure(2)
% grid on
% hold on
% plot(0:.3:6.3,eulerx,'color','b','LineWidth',1);
% plot(0:.3:6.3,eulery,'color','g','LineWidth',1);
% legend({'Theta1','Theta2'},'Location','southwest')

% ESLABONES DE 1->2 ------------------------------------------------------
% VARIABLES INICIALES
% THETA
theta=[28.95,104.47];
%DISTANCIAS d
d1=0; d2= 0;
% d=[350,0,0,290,0,80];
%DISTANCIAS a
a1=20;a2=10;
% a=[150,250,75,0,0,0];
% ALPHA
alpha1=0;alpha2=0;
% alpha=[-90,0,-90,90,-90,0];


theta_vector=[];
dist_vector=[];
precision=1;
flag=0;
Alpha= 0;
Beta= 0;
Gamma= 0;

% 
% 
for k=1:1:length(eulerx)
    while flag==0
        for i=0:1:1
            dist_anterior=1000;

            for j=0:precision:360
                %Sistema coordenado 1 respecto al 0
                A01=[ cosd(theta(1)) -cosd(alpha1)*sind(theta(1)) sind(alpha1)*sind(theta(1)) a1*cosd(theta(1));
                sind(theta(1)) cosd(alpha1)*cosd(theta(1)) -sind(alpha1)*cosd(theta(1)) a1*sind(theta(1));
                0 sind(alpha1) cosd(alpha1) d1 ;
                0 0 0 1 ];
                %Sistema coordenado 2 respecto al 1
                A12=[ cosd(theta(2)) -cosd(alpha2)*sind(theta(2)) sind(alpha2)*sind(theta(2)) a2*cosd(theta(2));
                sind(theta(2)) cosd(alpha2)*cosd(theta(2)) -sind(alpha2)*cosd(theta(2)) a2*sind(theta(2));
                0 sind(alpha2) cosd(alpha2) d2 ;
                0 0 0 1 ];

                A02=A01*A12;
                T=A02;

                pos_final= [ T(1,4) T(2,4)];

                dist_nueva = sqrt((eulerx(k,1)-pos_final(1,1))^2+(eulery(k,1)-pos_final(1,2))^2);

                if abs(dist_nueva) < abs(dist_anterior)
                    dist_anterior=dist_nueva;
                    dist_vector(i+1)=dist_anterior;
                    theta_vector(i+1)=mod(theta(i+1),360);
                    % theta_vector(i+1)=theta(i+1);
                end

                if i==0
                    theta(i+1)=theta(i+1)+precision;
                elseif i==1
                    theta(i+1)=theta(i+1)+precision;
                end
            end
            theta(i+1)=theta_vector(i+1);
            % theta_vector
            % dist_vector
            % dist_anterior

        end

        if dist_anterior<1
        flag=1;
        end
    end
    dist_anterior
    flag=0;
    k
    var_articulares(1,k)=theta_vector(1);
    var_articulares(2,k)=theta_vector(2);
end

format short

var_articulares

for i=1:1:k
theta_vector(1)=var_articulares(1,i);
% theta_vector(2)=var_articulares(2,i);
Eslabon_1 = line([0 20*cosd(var_articulares(1,i))],[0 20*sind(var_articulares(1,i))],'Color','b');
Px=20*cosd(var_articulares(1,i));
Py=20*sind(var_articulares(1,i));
Eslabon_2 = line([Px eulerx(i,1)],[Py eulery(i,1)],'Color','r');
frame = getframe;
writeVideo(writerObj,frame);
delete(Eslabon_1);
delete(Eslabon_2);
% pause(0.01)
end
close(writerObj);