clear all, close all, clc
open_system('vdynblksskidpad');
mdlWks = get_param('vdynblksskidpad','ModelWorkspace');
TrackPoints = evalin(mdlWks,'TrackPoints');
figure;
plot(TrackPoints(:,2),TrackPoints(:,1),'ro-');
hold on;
arrowLen = 1.5;
quiver(TrackPoints(:,2),TrackPoints(:,1), ...
    arrowLen*sin(TrackPoints(:,3)),arrowLen*cos(TrackPoints(:,3)), ...
    'b','LineWidth',1,'MaxHeadSize',arrowLen);
box on;
grid on;
xlabel('Y [m]');
ylabel('X [m]');
axis equal;
legend('Waypoints','Path Direction');