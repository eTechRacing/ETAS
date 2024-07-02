clear all, close all, clc

load("B1654run21.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
FZ_68=FZ(2556:3833,1);
FY_68=FY(2556:3833,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
FZ_90=FZ(1278:2555,1);
FY_90=FY(1278:2555,1);

%% Plotting
figure
plot([FZ_68,FZ_90],[FY_68,FY_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('FZ (N)')
ylabel('FY (N)')