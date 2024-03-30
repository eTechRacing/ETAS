clear all, clc
load("B1654run21.mat");

IA=0.9; %Camber deg (absolute value)
P=0.75; %Pressure bar

PSI=P/0.0689475729; %Pressure in psi

%Srping rate for 12PSI interpoling inclination angles (cambers) (imperail units)
K12=((IA-2)/(0-2))*(635-578)+578

%Spring rate for 10PSI interpoling inclination angles (cambers) (imperail units)
K10=((IA-2)/(0-2))*(579-522)+522

%Spring rate interpoling pressures (imperail units)
K=((PSI-12)/(10-12))*(K10-K12)+K12

%Spring rate in International System
KIS=vpa(K*(0.45359237*9.81)*(0.0245^-1))

% Calsplan data 
data=xlsread("Spring Rate.xlsx");
KC=data(:,1)*(0.45359237*9.81)*(0.245^-1); % Spring rate from Calsplan. From "data" take all of the rows of the column 1 N/m
PC=data(:,2)*0.0689475729; % Pressure from Calsplan Excel bar
IAC=data(:,3); % Inclination angle Excel deg
W=data(:,4)*0.45359237*9.81; % Weight in Newtons

%{
for i=1:length(IAC) %Interpolació per inclination angle
    if i==1
        K(i)=((IA-2)/(0-2))*(635-578)+578
    elseif i>1 & IAC(i)==0 & IAC(i-1)~=0;
        K(i)=((IA-2)/(0-2))*(635-578)+578
    end
end
%}
