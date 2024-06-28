clear all, close all, clc

load("B1654run21.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
NFY_68=NFY(2556:3833,1);
TSTC_68=TSTC(2556:3833,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
NFY_90=NFY(1278:2555,1);
TSTC_90=TSTC(1278:2555,1);

%% Plotting
figure
plot([TSTC_68,TSTC_90],[NFY_68,NFY_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('TSTC (Celsius)')
ylabel('FY/FZ (N)')