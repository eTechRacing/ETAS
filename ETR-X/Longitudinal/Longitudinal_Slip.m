clear all
clc

g=9.81;
m = 320; % vechicle mass in kg 
R = 22.3969*10^-2 ; %efective rolling radius
CAMdeg = 0.9; %inclination angle en graus
CAM = CAMdeg*pi/180; %Camber in radians

%Longitudinal Coefficients
PCX1= 1.5000;
PDX1=1.9513;
PDX2=-1.0000;
PPX1=-6.7004;
PPX2=-16.5293;
PPX3=-2.1873;
PPX4=-5.6683;
PDX3=15.0000;
PEX1=-7.8385e-13;
PEX2=-0.9950;
PEX3=-0.6000;
PEX4=0.9000;
PKX1=25.1313;
PKX2=-5.7390e-06;
PKX3=-0.6401;
PHX1=6.0893e-04;
PHX2=-0.0018;
%PDXP1=
%PDXP2=
%PDXP3=
%RHX1=
%REX1=
%REX2=
%RCX1=
%RBX1=
%RBX2=
%RBX3=
SVX=1;

%Scaling coefficients
LCX=1; %Fx shape factor; valor inventat
LUX=1; %valor inventat
LEX=1; %valor inventat
LKXk=1; %valor inventat
LHX=1; %valor inventat
LXalfa=1; %valor inventat

%Data
slip = 1.0:0.02:2.0;
VV = (0:5:90)/3.6; %Vehicle Velocity m/s
FZ = m*g/4; % signle wheel load 
DFZ = (FZ-1080)/1080; %diferencial de carrega
PI = 0.8; %pressio en bar
DPI = (PI-0.84)/0.84;

%MF-Tyre 5.2, 6.0, 6.1
s1=1;
SHX= (PHX1+PHX2*DFZ)*LHX*LUX*s1;

for i = 1:length(slip)
    for j = 1:length(VV)
        
        V(i,j)= VV(j)*slip(i); % Wheel velocity m/s
        Omega(i,j) = V(i,j)/R; %wheel rotational speed %valor inventat
        k(i,j) = (V(i,j)-VV(j))/VV(j); %longitudinal slip

        %Pure Slip
        kx(i,j) = k(i,j)+SHX;
        CX(i,j) = PCX1*LCX;
        U(i,j) = (PDX1+PDX2*DFZ)*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LUX;
        DX(i,j) = U(i,j)*FZ*s1;
        Ex(i,j) = (PEX1+PEX2*DFZ+PEX3*DFZ^2)*(1-PEX4*sign(kx(i,j)))*LEX;
        KXk(i,j) = FZ*(PKX1+PKX2*DFZ)*exp(PKX3*DFZ)*(1+PPX1*DPI+PPX2*DPI^2)*LKXk;
        BX(i,j) = KXk(i,j)/(CX(i,j)*DX(i,j));
        
        %Combined slip
        %{
        SHalfa= RHX1
        alfaS= alfaF+SHalfa
        BXalfa= (RBX1+RBX3*CAM^2)*cos(arctan(RBX2*k))*LXalfa
        CXalfa= RCX1
        EXA= REX1+REX2*DFZ
        %}
        Gxalfa=1;
        %{
        GXalfa= (cos(CXalfa*arctan(BXalfa*alfaS-EXA(BXalfa*alfaS-arctan(BXalfa*alfaS)))))/(cos(CXalfa*arctan(BXalfa*SHalfa-EXalfa(BXalfa-SHalfa-arctan(BXalfa*SHXalfa)))))
        when combined slip is not used: Gxa=1
        %}
        
        %Turn slip
        s1=1; 
        %{
        BXP1= PDXP1(1+PDXP2*DFZ)*cos(arctan(PDXP3*k))
        s1= cos(arctan(BXP1*R*PF))
        when turn slip not used: s1=1
        %}
        
        
        Fx(i,j)=(DX(i,j)*sin(CX(i,j)*atan(BX(i,j)*kx(i,j)-Ex(i,j)*(BX(i,j)*kx(i,j)-atan(BX(i,j)*kx(i,j)))))+SVX)*Gxalfa;
        
    end
end

figure(1)
plot(slip, Fx)




%Matrix algorithm test
%{
a1 = [1,2,3]
a2 = [9,8,7]
a3 = [7,2,9;6,1,8;3,7,7]
for k=1:length(a1)
    for g=1:length(a2)
        a4(k,g) = a1(k)*a2(g)
        a5(k,g) = 4
        a6(k,g) = a4(k,g)*a3(k,g)
    end
end
%}




