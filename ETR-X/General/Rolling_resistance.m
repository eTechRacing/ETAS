clear all
close all
clc

load('B1654run35.mat');
% P=0.83 bar - DataInterval: 0:26306
% P=0.83 bar SA=0 deg - DataInterval: 0:9600
% P=0.83 bar SA=0 deg IA=0 deg - DataInterval: 0:4140
% P=0.83 bar SA=0 deg IA=0 FZ=850N - DataInterval: 1342:2047 
% P=0.83 bar SA=0 deg IA=0 FZ=650N - DataInterval: 2048:2769 
% P=0.83 bar SA=0 deg IA=2 deg - DataInterval: 4141:6883 
% P=0.83 bar SA=0 deg IA=2 FZ=850N - DataInterval: 4141:4814
% P=0.83 bar SA=0 deg IA=2 FZ=650N - DataInterval: 4815:5509


% P=0.69 bar - DataInterval: 26307:51479
% P=0.83 bar SA=0 deg - DataInterval: 26307:34668
% P=0.69 bar SA=0 deg IA=0 deg - DataInterval: 26307:29111
% P=0.69 bar SA=0 deg IA=0 FZ=850N - DataInterval: 26307:27011
% P=0.69 bar SA=0 deg IA=0 FZ=650N - DataInterval: 27012:27728
% P=0.69 bar SA=0 deg IA=2 deg - DataInterval: 29112:31892
% P=0.69 bar SA=0 deg IA=2 FZ=850N - DataInterval: 29112:29816
% P=0.69 bar SA=0 deg IA=2 FZ=650N - DataInterval: 29817:30483


%Actual car setup
%IA=0.9; %Camber deg (absolute value)
%P=0.75; %Pressure bar

PSI=P/0.0689475729; %Pressure in psi

%Srping rate for 12PSI interpoling inclination angles (cambers) (imperail units)
K12=((IA-2)/(0-2))*(635-578)+578;

figure(1)
plot(FZ(27012:27728),FX(27012:27728))
figure(2)
plot(FX(27012:27728))
figure(3)
plot(SR(27012:27728),FX(27012:27728))







