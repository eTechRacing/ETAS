clear all, close all, clc

load("B1654run35.mat");

%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
FZ_68=FZ(2055:2760,1);
RE_68=RE(2055:2760,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
FZ_90=FZ(1342:2047,1);
RE_90=RE(1342:2047,1);

%% Plotting
figure
plot([RE_68,RE_90],[FZ_68,FZ_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('RE (cm)')
ylabel('FZ (N)')