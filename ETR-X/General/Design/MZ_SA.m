clear all, close all, clc

load("B1654run21.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
MZ_68=MZ(2556:3833,1);
SA_68=SA(2556:3833,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
MZ_90=MZ(1278:2555,1);
SA_90=SA(1278:2555,1);

%% Plotting
figure
plot([SA_68,SA_90],[MZ_68,MZ_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('SA (deg)')
ylabel('MZ (Nm)')


%% Curve fitter results
%curveFitter([SA_68,SA_90],[MZ_68,MZ_90]);
      
a0=   -418.7448;
a1=   710.5065;
b1=   -554.2156;
a2=   -421.4004;
b2=   703.0382;
a3=   159.3263;
b3=   -401.6587;
a4=   -31.9234;
b4=   124.6616;
w=    0.1019;

MZ=@(x) a0 + a1*cos(x*w) + b1*sin(x*w) + a2*cos(2*x*w) + b2*sin(2*x*w) + a3*cos(3*x*w) + b3*sin(3*x*w) + a4*cos(4*x*w) + b4*sin(4*x*w);





 