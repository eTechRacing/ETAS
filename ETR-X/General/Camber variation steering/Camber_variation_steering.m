clear all
close all
clc

% Dades:
data1= xlsread('Steering-Camber.xlsx');
data2= xlsread('Steering_Input_Data_Toe_0.0.xlsx');
RackDisp=data2(101:50:5301,2);%mm
steering=data2(101:50:5301,3).*pi/180;%rad
camber= data1(:, 5).*pi/180;%rad
mat= [steering, camber];
C=@(S) 0.0057*S^3+0.0278*S^2+0.0386*S;

fplot(C,[-pi*8/45,pi*8/45])
xlabel('Steering angle (radians)')
ylabel('Camber variation (radians)')
%{
Resultats
Fit Name: untitled fit 1

Polynomial Curve Fit (poly3)
f(x) = p1*x^3 + p2*x^2 + p3*x + p4

Coefficients and 95% Confidence Bounds
       Value      Lower     Upper  
p1    0.0057     0.0053     0.0060
p2    0.0278     0.0277     0.0279
p3    0.0386     0.0386     0.0387
p4    -0.0000    -0.0000    0.0000

Goodness of Fit
             Value   
SSE         0.0000  
R-square    1.0000  
DFE         101.0000
Adj R-sq    1.0000  
RMSE        0.0001  
%}
