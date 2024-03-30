clear all, clc
load("B1654run21.mat");

IA=0.9; %Camber deg (absolute value)
P=0.75; %Pressure bar

data=xlsread("Spring Rate.xlsx")
KC=data(:,1)*(0.45359237*9.81)*(0.245^-1); % Spring rate from Calsplan. From "data" take all of the rows of the column 1 N/m
PC=data(:,2)*0.0689475729; % Pressure from Calsplan Excel bar
IAC=data(:,3); % Inclination angle Excel deg
W=data(:,4)*0.45359237*9.81; % Weight in Newtons

%Per 12PSI
K=((IA-2)/(0-2))*(635-578)+578

%{
for i=1:length(IAC) %Interpolació per inclination angle
    if i==1
        K(i)=((IA-2)/(0-2))*(635-578)+578
    elseif i>1 & IAC(i)==0 & IAC(i-1)~=0;
        K(i)=((IA-2)/(0-2))*(635-578)+578
    end
end
%}
