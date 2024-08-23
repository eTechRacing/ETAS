clear all
clc

g=9.81; % m/s^2
m = 320; % vechicle mass in kg
W = m*g; % vehicle weight in N
h = 0.3; % cog height m
l = 1.53; % wheel base m
cogx= 0.8; % Front axle -> Mass center distance in m
R = 0.223969; %efective rolling radius
CAMdeg = 1; %inclination angle en graus
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
LCX=1; %Scale factor of Fx shape factor; valor inventat
LMUX=1; %Scale factor of Fx peak friction coefficient; valor inventat
LEX=1; %Scale factor of Fx curvature factor; valor inventat
LKXk=1; %Scale factor of slip stiffness; valor inventat 
LHX=1; %Scale factor of Fx horizontal shift; valor inventat
LXA=1; %Scale factor of alpha influence on Fx; valor inventat

%Data
slip = 0:0.01:1.0; %vehicle slip
VV = (0:5:90)/3.6; %Vehicle Velocity m/s
PI = 0.8; %pressio en bar
DPI = (PI-0.97)/0.97;




for i = 1:length(slip)
    for j = 1:length(VV)
        
        Acx(i,j) = 0; %Acceleracio inicial en m/s
        fzr(i,j) = W*cogx/l; % Rear axle load load
        fzf(i,j) = W-fzr(i,j); % Front axle load load

        for k=1:100

            V(i,j) = VV(j)*(slip(i)+1); % Wheel velocity m/s
            k(i,j) = (V(i,j)-VV(j))/VV(j); %slip(i)
            WTx(i,j) = (h/l)*m*Acx(i,j); %Longitudinal weight transfer N
            WTF(i,j) = -WTx(i,j); 
            WTR(i,j) = WTx(i,j);            
            FZf(i,j) = fzf(i,j) + WTF(i,j);% Front axle load + weight transfer
            FZr(i,j) = fzr(i,j) + WTR(i,j);% Rear axle load + weight transfer
            FZFL(i,j) = FZf(i,j)/2; % Front left wheel load
            FZFR(i,j) = FZf(i,j)/2; % Front right wheel load
            FZRL(i,j) = FZr(i,j)/2; % Rear left wheel load
            FZRR(i,j) = FZr(i,j)/2; % Rear right wheel load
            DFZFL(i,j) = (FZFL(i,j)-1080)/1080; %load diferential FL
            DFZFR(i,j) = (FZFR(i,j)-1080)/1080; %load diferential FR
            DFZRL(i,j) = (FZRL(i,j)-1080)/1080; %load diferential RL
            DFZRR(i,j) = (FZRR(i,j)-1080)/1080; %load diferential RR
            
            
            %FRONT LEFT

            %MF-Tyre 5.2, 6.0, 6.1
            s1=1;
            SHXFL(i,j)= (PHX1+PHX2*DFZFL(i,j))*LHX; 

            %Pure Slip
            kxFL(i,j) = k(i,j)+SHXFL(i,j);
            CXFL(i,j) = PCX1*LCX;
            UFL(i,j)  = (PDX1+PDX2*DFZFL(i,j))*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LMUX;
            DXFL(i,j) = UFL(i,j)*FZFL(i,j)*s1;
            ExFL(i,j) = (PEX1+PEX2*DFZFL(i,j)+PEX3*DFZFL(i,j)^2)*(1-PEX4*sign(kxFL(i,j)))*LEX;
            KXkFL(i,j) = FZFL(i,j)*(PKX1+PKX2*DFZFL(i,j))*exp(PKX3*DFZFL(i,j))*(1+PPX1*DPI+PPX2*DPI^2)*LKXk; 
            BXFL(i,j) = KXkFL(i,j)/(CXFL(i,j)*DXFL(i,j));
            %Combined slip
            %{
            SHalfaFL= RHX1
            alfaSFL= alfaF+SHalfaFL
            BXalfaFL= (RBX1+RBX3*CAM^2)*cos(arctan(RBX2*k))*LXA
            CXalfaFL= RCX1
            EXAFL= REX1+REX2*DFZ
            %}
            GxalfaFL=1;
            %{
            GxalfaFL= (cos(CXalfaFL*arctan(BXalfaFL*alfaSFL-EXAFL(BXalfaFL*alfaSFL-arctan(BXalfaFL*alfaSFL)))))/(cos(CXalfaFL*arctan(BXalfaFL*SHalfaFL-EXalfa(BXalfaFL-SHalfaFL-arctan(BXalfaFL*SHXalfaFL)))))
            when combined slip is not used: Gxa=1
            %}
            %Turn slip
            s1=1; 
            %{
            BXP1FL= PDXP1(1+PDXP2*DFZ)*cos(arctan(PDXP3*k))
            s1= cos(arctan(BXP1FL*R*PF))
            %when turn slip not used: s1=1
            %}
            
            FxFL(i,j)=(DXFL(i,j)*sin(CXFL(i,j)*atan(BXFL(i,j)*kxFL(i,j)-ExFL(i,j)*(BXFL(i,j)*kxFL(i,j)-atan(BXFL(i,j)*kxFL(i,j)))))+SVX)*GxalfaFL;
            
            
            %FRONT RIGHT
            
            %MF-Tyre 5.2, 6.0, 6.1
            s1=1;
            SHXFR(i,j)= (PHX1+PHX2*DFZFR(i,j))*LHX; 
            
            %Pure Slip
            kxFR(i,j) = k(i,j)+SHXFR(i,j);
            CXFR(i,j) = PCX1*LCX;
            UFR(i,j)  = (PDX1+PDX2*DFZFR(i,j))*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LMUX;
            DXFR(i,j) = UFR(i,j)*FZFR(i,j)*s1;
            ExFR(i,j) = (PEX1+PEX2*DFZFR(i,j)+PEX3*DFZFR(i,j)^2)*(1-PEX4*sign(kxFR(i,j)))*LEX;
            KXkFR(i,j) = FZFR(i,j)*(PKX1+PKX2*DFZFR(i,j))*exp(PKX3*DFZFR(i,j))*(1+PPX1*DPI+PPX2*DPI^2)*LKXk; 
            BXFR(i,j) = KXkFR(i,j)/(CXFR(i,j)*DXFR(i,j));
            %Combined slip
            %{
            SHalfaFR= RHX1
            alfaSFR= alfaF+SHalfaFR
            BXalfaFR= (RBX1+RBX3*CAM^2)*cos(arctan(RBX2*k))*LXA
            CXalfaFR= RCX1
            EXAFR= REX1+REX2*DFZ
            %}
            GxalfaFR=1;
            %{
            GxalfaFR= (cos(CXalfaFR*arctan(BXalfaFR*alfaSFR-EXAFR(BXalfaFR*alfaSFR-arctan(BXalfaFR*alfaSFR)))))/(cos(CXalfaFR*arctan(BXalfaFR*SHalfaFR-EXalfa(BXalfaFR-SHalfaFR-arctan(BXalfaFR*SHXalfaFR)))))
            when combined slip is not used: Gxa=1
            %}
            %Turn slip
            s1=1; 
            %{
            BXP1FR= PDXP1(1+PDXP2*DFZ)*cos(arctan(PDXP3*k))
            s1= cos(arctan(BXP1FR*R*PF))
            %when turn slip not used: s1=1
            %}
            
            FxFR(i,j)=(DXFR(i,j)*sin(CXFR(i,j)*atan(BXFR(i,j)*kxFR(i,j)-ExFR(i,j)*(BXFR(i,j)*kxFR(i,j)-atan(BXFR(i,j)*kxFR(i,j)))))+SVX)*GxalfaFR;
            
            
            %REAR LEFT
            
            %MF-Tyre 5.2, 6.0, 6.1
            s1=1;
            SHXRL(i,j)= (PHX1+PHX2*DFZRL(i,j))*LHX; 
            
            %Pure Slip
            kxRL(i,j) = k(i,j)+SHXRL(i,j);
            CXRL(i,j) = PCX1*LCX;
            URL(i,j)  = (PDX1+PDX2*DFZRL(i,j))*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LMUX;
            DXRL(i,j) = URL(i,j)*FZRL(i,j)*s1;
            ExRL(i,j) = (PEX1+PEX2*DFZRL(i,j)+PEX3*DFZRL(i,j)^2)*(1-PEX4*sign(kxRL(i,j)))*LEX;
            KXkRL(i,j) = FZRL(i,j)*(PKX1+PKX2*DFZRL(i,j))*exp(PKX3*DFZRL(i,j))*(1+PPX1*DPI+PPX2*DPI^2)*LKXk; 
            BXRL(i,j) = KXkRL(i,j)/(CXRL(i,j)*DXRL(i,j));
            %Combined slip
            %{
            SHalfaRL= RHX1
            alfaSRL= alfaF+SHalfaRL
            BXalfaRL= (RBX1+RBX3*CAM^2)*cos(arctan(RBX2*k))*LXA
            CXalfaRL= RCX1
            EXARL= REX1+REX2*DFZ
            %}
            GxalfaRL=1;
            %{
            GxalfaRL= (cos(CXalfaRL*arctan(BXalfaRL*alfaSRL-EXARL(BXalfaRL*alfaSRL-arctan(BXalfaRL*alfaSRL)))))/(cos(CXalfaRL*arctan(BXalfaRL*SHalfaRL-EXalfa(BXalfaRL-SHalfaRL-arctan(BXalfaRL*SHXalfaRL)))))
            when combined slip is not used: Gxa=1
            %}
            %Turn slip
            s1=1; 
            %{
            BXP1RL= PDXP1(1+PDXP2*DFZ)*cos(arctan(PDXP3*k))
            s1= cos(arctan(BXP1RL*R*PF))
            %when turn slip not used: s1=1
            %}
            
            FxRL(i,j)=(DXRL(i,j)*sin(CXRL(i,j)*atan(BXRL(i,j)*kxRL(i,j)-ExRL(i,j)*(BXRL(i,j)*kxRL(i,j)-atan(BXRL(i,j)*kxRL(i,j)))))+SVX)*GxalfaRL;
            
            
            %REAR RIGHT
            
            %MF-Tyre 5.2, 6.0, 6.1
            s1=1;
            SHXRR(i,j)= (PHX1+PHX2*DFZRR(i,j))*LHX; 
            
            %Pure Slip
            kxRR(i,j) = k(i,j)+SHXRR(i,j);
            CXRR(i,j) = PCX1*LCX;
            URR(i,j)  = (PDX1+PDX2*DFZRR(i,j))*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LMUX;
            DXRR(i,j) = URR(i,j)*FZRR(i,j)*s1;
            ExRR(i,j) = (PEX1+PEX2*DFZRR(i,j)+PEX3*DFZRR(i,j)^2)*(1-PEX4*sign(kxRR(i,j)))*LEX;
            KXkRR(i,j) = FZRR(i,j)*(PKX1+PKX2*DFZRR(i,j))*exp(PKX3*DFZRR(i,j))*(1+PPX1*DPI+PPX2*DPI^2)*LKXk; 
            BXRR(i,j) = KXkRR(i,j)/(CXRR(i,j)*DXRR(i,j));
            %Combined slip
            %{
            SHalfaRR= RHX1
            alfaSRR= alfaF+SHalfaRR
            BXalfaRR= (RBX1+RBX3*CAM^2)*cos(arctan(RBX2*k))*LXA
            CXalfaRR= RCX1
            EXARR= REX1+REX2*DFZ
            %}
            GxalfaRR=1;
            %{
            GxalfaRR= (cos(CXalfaRR*arctan(BXalfaRR*alfaSRR-EXARR(BXalfaRR*alfaSRR-arctan(BXalfaRR*alfaSRR)))))/(cos(CXalfaRR*arctan(BXalfaRR*SHalfaRR-EXalfa(BXalfaRR-SHalfaRR-arctan(BXalfaRR*SHXalfaRR)))))
            when combined slip is not used: Gxa=1
            %}
            %Turn slip
            s1=1; 
            %{
            BXP1RR= PDXP1(1+PDXP2*DFZ)*cos(arctan(PDXP3*k))
            s1= cos(arctan(BXP1RR*R*PF))
            %when turn slip not used: s1=1
            %}
            
            FxRR(i,j)=(DXRR(i,j)*sin(CXRR(i,j)*atan(BXRR(i,j)*kxRR(i,j)-ExRR(i,j)*(BXRR(i,j)*kxRR(i,j)-atan(BXRR(i,j)*kxRR(i,j)))))+SVX)*GxalfaRR;
            
            %Total
            Fx4(i,j)=FxFL(i,j)+FxFR(i,j)+FxRL(i,j)+FxRR(i,j); %Only 4WD
            Fx2(i,j)=FxRL(i,j)+FxRR(i,j); %2WD
            Acx(i,j)=Fx2(i,j)/m; %Longitudinal acceleration
            
        end
    
    VmaxAccel(i,j)=sqrt(2*75*Acx(i,j))*3.6; %Maximum acceleration velocity in 75 m;
    end
end

figure(1)
plot3(slip,Fx2,V)

figure(2)
plot(slip,Fx2)

figure(3)
plot(slip,Acx)

figure(4)
plot(slip,VmaxAccel)

figure(5)
plot(Acx,WTx)

figure(6)
plot(Acx,FZFL)

figure(7)
plot(Acx,FZFR)

figure(8)
plot(Acx,FZRL)

figure(9)
plot(Acx,FZRR)

%{
[,]=size(Fx);

%Plotting Yaw Moment versus Lateral Acceleration
figure
for i=1:N
    plot(Ay(:,i),YawMoment(:,i))
    hold on
end

for i=1:M
    plot(Ay(i,:),YawMoment(i,:))
    hold on
end
% legendCell_VS = cellstr(num2str(VS', 'VS=%-d'));
% legendCell_SI = cellstr(num2str(SI', 'SI=%-d'));
% legend([legendCell_VS;legendCell_SI], 'NumColumns',2)
xlabel('Lateral accel [gs]')
ylabel('Yaw Moment [kg m]')
legendCell_slip = cellstr(num2str(slip*180/pi, 'VS=%-d'));
legendCell_V = cellstr(num2str(V*180/pi, 'SI=%-d'));
legend([legendCell_VS;legendCell_SI], 'NumColumns',2)


%}


% Matrix algorithm test
%{
a1 = [1,2,3]
a2 = [9,8,7]
a3 = [7,2,9;6,1,8;3,7,7]
for k=1:length(a1)
    for g=1:length(a2)
        a4(k,g) = a1(k)*a2(g)
        a5(k,g) = 4
        a6(k,g) = a4(k,g).*a3(k,g)
    end
end
%}




