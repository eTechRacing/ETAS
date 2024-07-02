clear all, close all, clc

load("B1654run35.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
SR_68=SR(2055:2760,1);
TSTC_68=TSTC(2055:2760,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
SR_90=SR(1342:2047,1);
TSTC_90=TSTC(1342:2047,1);

%% Plotting
figure
plot([TSTC_68,TSTC_90],[SR_68,SR_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('TSTC (Celsius)')
ylabel('SR')