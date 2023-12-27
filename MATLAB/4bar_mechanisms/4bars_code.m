clc
clear all

l1 = 10;
l2 = 28.2;
l3 = 28.2;
l4 = 22.1;
l5 = 56.4;

% r=5;
th=[];

delta=5;
countT=1;

t_d=[];
theta=[];
v_theta2=[zeros];
v_theta3=[zeros];



% px = l1.*cos(theta1) + l5.*cos(t + pi);
% 
% hold on
% figure
% plot(t,px)
% grid
% xlim([0 8])
% ylim([5 30])
% xlabel('t')
% ylabel('20 + 5.*cos(t + pi)')
% title('Grafica 1')
% hold off
% 
% py = 10 + 5.*sin(t + pi);
% 
% hold on
% figure
% plot(t,py)
% grid
% xlim([0 8])
% ylim([0 20])
% xlabel('t')
% ylabel('10 + 5.*sin(t + pi)')
% title('Grafica 2')
% hold off
% 
% hold on
% figure
% plot(20 + 5.*cos(t + pi),10 + 5.*sin(t + pi), 'linewidth',2)
% grid
% xlim([10 35])
% ylim([0 20])
% xlabel('t')
% ylabel('[20 + 5.*cos(t + pi), 10 + 5.*sin(t + pi)]')
% title('Grafica de circunferencia')
% hold off

writerObj = VideoWriter('Trayectoria.avi');
writerObj.FrameRate = 20;
open(writerObj);
figure(6)
grid
axis(gca, 'equal'); 
hold on
hold off
title('Trayectoria ')
xlabel('Eje x')
ylabel('Eje y')

for sad=0:5
    pause(1.0);
end

% theta1 = 0:pi/72:2*pi;

for t=0:delta:720
    axis ([-35 30 -25 60]);
    th=t+180;
%     t_d=[l1+r*cosd(th) l2+r*sind(th)];
%     Px = t_d(1); 
%     Py = t_d(2);
    theta1 = t + 180;
    u = l4^2 + l3^2 + l1^2 - l2^2 - 2.*l4.*l1.*cosd(theta1);
    v = 2.*(l4.*l3 - l3.*l1.*cosd(theta1));
    w = -2.*l3.*l1.*sind(theta1);
%     r_1 = (u-v);
%     r_2 = (u+v);

    theta3 = 2*atand(((-2*w - sqrt(4*(w^2) - 4*(u - v)*(u + v)))) / (2*(u - v)));
    theta2 = atan2d(l3*sind(theta3) - l1*sind(theta1), l4 + l3*cosd(theta3) - l1*cosd(theta1));
       
    t_d=[l1.*cosd(theta1)+l5.*cosd(theta2) l1.*sind(theta1)+l5.*sind(theta2)];

    v_theta2(countT,1)=theta2;
    v_theta3(countT,1)=theta3;

%     Eslabon1 = line([0 l1*cosd(theta1)],[0 l1*sind(theta1)],'Color','r');
%     Eslabon2 = line([l1*cosd(theta1) l1*cosd(theta1)+l5*cosd(theta1+theta2)],[l1*sind(theta1) l1*sind(theta1)+l5*cosd(theta1+theta2)],'Color','g');
%     Eslabon2 = line([l1*cosd(theta1) 20],[l1*sind(theta1) 20],'Color','g');
%     Eslabon3 = line([l1*cosd(theta1)+l2*cosd(theta1+theta2) l4],[l1*sind(theta1)+l2*cosd(theta1+theta2) 0],'Color','b');
    traj1=[l1*cosd(theta1)+l5*cosd(theta2)-l4 l1*sind(theta1)+l5*sind(theta2)];
    traj= viscircles([traj1(1),traj1(2)],.05,'EdgeColor','b');
    
    Eslabon3 = line([0 l3*cosd(theta3)],[0 l3*sind(theta3)],'Color','r');%GRAFICA ESLABON1
    Eslabon2 = line([l3*cosd(theta3) -l4 + l1*cosd(theta1)],[l3*sind(theta3) l1*sind(theta1)],'Color','g');%GRAFICA ESLABON2
    Eslabon1 = line([l3*cosd(theta3) -l4 + l1*cosd(theta1) -l4 ],[l3*sind(theta3)  l1*sind(theta1) 0]);%GRAFICA ESLABON3
    
    Eslabon4 = line([l1*cosd(theta1)-l4 l1*cosd(theta1)+l5*cosd(theta2)-l4],[l1*sind(theta1) l1*sind(theta1)+l5*sind(theta2)],'Color','g');

    td_x(countT,1)=t_d(1);
    td_y(countT,1)=t_d(2);
     
    frame = getframe;
    writeVideo(writerObj,frame);
    pause(0.0001);
    delete(Eslabon1);
    delete(Eslabon2);
    delete(Eslabon3);
    delete(Eslabon4);
    countT=countT+1;
end