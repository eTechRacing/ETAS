clear all
close all
clc

% Dades:
data1= xlsread('Steering-Camber.xlsx');
data2= xlsread('Steering_Input_Data_Toe_0.0.xlsx');
RackDisp=data2(101:50:5301,2);%mm
steering=data2(101:50:5301,3);%deg
camber= data1(:, 5);%deg
mat= [steering, camber];

%{
Resultats Curve Fitter
Fit Name: Camber-Steering

Polynomial Curve Fit (poly3)
f(x) = p1*x^3 + p2*x^2 + p3*x + p4

Coefficients and 95% Confidence Bounds
       Value      Lower     Upper  
p1    0.0000     0.0000     0.0000
p2    0.0005     0.0005     0.0005
p3    0.0386     0.0386     0.0387
p4    -0.0007    -0.0016    0.0002

Goodness of Fit
             Value   
SSE         0.0009  
R-square    1.0000  
DFE         101.0000
Adj R-sq    1.0000  
RMSE        0.0030  
%}
