clear all, close all, clc

load("B1654run35.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
FZ_68=FZ(2055:2760,1);
RE_68=RE(2055:2760,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
FZ_90=FZ(1342:2047,1);
RE_90=RE(1342:2047,1);

%% Curvefitter
%curveFitter([-877.65, -836.9], [19.61, 26.408])
p1=    0.1668;
p2=    166.0214;
f1=@(x) p1*x + p2;
%curveFitter([-627.75,-661.89],[26.731,19.732])
p3=    0.2050;
p4=    155.4253; 
f2=@(x) p3*x + p4;

%% Plotting
figure
plot([FZ_68,FZ_90],[RE_68,RE_90])
hold on
fplot(f1)
fplot(f2)
xlim([-1000,-500])
ylim([19 27])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('FZ (N)')
ylabel('RE (cm)')
hold off



