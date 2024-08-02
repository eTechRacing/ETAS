clear all, close all, clc

load("B1654run21.mat");

%% SA vs FY for different FZ
% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
SA_68=SA(2556:3833,1);
FY_68=FY(2556:3833,1);

% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
SA_90=SA(1278:2555,1);
FY_90=FY(1278:2555,1);

% PLotting
figure
plot([SA_68,SA_90],[FY_68,FY_90])
legend('IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg')
xlabel('SA (deg)')
ylabel('FY (N)')
title('SA vs FY')

%% SA vs FY for different pressures
% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.6895 bar (10 psi)
SA_10=SA(21735:23012,1);
FY_10=FY(21735:23012,1);

% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
SA_12=SA(1278:2555,1);
FY_12=FY(1278:2555,1);

% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.9653 bar (14 psi)
SA_14=SA(42186:43463,1);
FY_14=FY(42186:43463,1);

%Plotting
figure
plot([SA_10,SA_12, SA_14],[FY_10,FY_12, FY_14])
legend('IA=0deg, P=0.6895 bar','IA=0deg, P=0.8274 bar','IA=0deg, P=0.9653 bar')
xlabel('SA (deg)')
ylabel('FY (N)')
title('SA vs FY')