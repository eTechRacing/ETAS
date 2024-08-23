clear all
clc

g=9.81; %m/s^2

l = 1.535; %longitud cotxe
a = 0.8; %anterior car.a = 0.78; Distancia ruedas del a cg 
b = l-a; %Distancia ruedas tras a cg
Tf = 1.25; %Trackwidth front
Tr = 1.15; %Trackwidth rear
weight = 200+86; %Pes
Zrf=0.0963; %Roll center front
Zrr=0.12; %Roll center rear
H=0.1837;
Kf= 336.38; %roll stiffnes front maxima ajustabilidad +150 de lo que de el muelle
Kr= 313.41; %roll stiffnes rear maxima ajustabilidad +250 de lo que de el muelle
h= 0.280; %COG height
copx = 0.84; % centre de pressions
lambdaHy=1;
lambdaVy=1;
lambdauy=0.59; %scaling factor
lambdaKygamma=1;
lambdaCy=1;
lambdaEy=1;
lambdaKyalpha=1;
lambdaKygamma=1;
PF=0.75; %Front pressure Bar
PR=0.75; %Rrear pressure Bar
gammaF0=-1.5; %Front Camber deg en negatiu
gammaR0=-1; %Rear Camber deg en negatiu

%Propietats del neumàtic
PCY1 = 1.5000; %shape factor (Afilar cantonades i estirar i atxatar)
PDY1 = 2.4360; %estirar o aixafar gràfica
PDY2 = -0.3628;
PDY3 = 10;
PEY1 = -0.0286; %afilar cantonades
PEY2 = 0.0113;
PEY3 = -0.2863; %en negatiu s'afila la dreta i en postiu l'esquerra
PEY4 = 32.0364;
PEY5 = -4.6821e+03;
PKY1 = -35.2758;
PKY2 = 1.7514; %rotar sobre el centre antihorari
PKY3 = 1.0000; 
PKY4 = 2.0000; 
PKY5 = -1.6874; 
PKY6 = 3.5692;
PKY7 = 1.9296;
PHY1 = 0.0043; %Desplaçar lateralment
PHY2 = 0; %Desplaçar lateralment
PVY1 = -0.0216; %pujar i baixar la grafica sencera
PVY2 = 0; %pujar i baixar la grafica sencera
PVY3 = 0.6492; %pujar i baixar la grafica sencera
PVY4 = 2.1293;
PPY1 = 0.2239; 
PPY2 = 0.9444;
PPY3 = -0.9607;
PPY4 = -2;
PPY5 = 0.0000;
Fz0 = 1080;
P0=0.97;
%Turn slip
z0=1;
z1=1;
z2=1;
z3=1;
z4=1;

%Ecuacio MZ(SA) Regressio 
a0m =       2.107;
a1m =      -3.933;
b1m =       61.61;
a2m =     -0.4837;
b2m =       10.06;
a3m =      0.7475;
b3m =        7.31;
a4m =      0.4277;
b4m =      -0.423;
a5m =       1.124;
b5m =       3.801;
wm =      0.2417;

MZ=@(SA)  a0m + a1m*cos(SA*wm) + b1m*sin(SA*wm) + a2m*cos(2*SA*wm) + b2m*sin(2*SA*wm) + a3m*cos(3*SA*wm) + b3m*sin(3*SA*wm) + a4m*cos(4*SA*wm) + b4m*sin(4*SA*wm) + a5m*cos(5*SA*wm) + b5m*sin(5*SA*wm);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Imputs
V=50; %velocitat en X en km/h SENSOR
deltadg=-15:1:15; %Steering angles en graus SENSOR
SI=deltadg'.*pi/180; %Steering angle en rad
Betadg=-15:1:15; %Slip angle en graus SENSOR
VS=Betadg'.*pi/180; %Slip angle rad
sliplim=17*pi/180; %Limit slip angle
w=0:0.5:15; %rad/s SENSOR gyroz
ay=(-1.5:0.1:1.5)/9.81; %m/s SENSOR
Ay=ay*9.81; %in gs

%Izz=car.weight*(a^2+car.h^2); %Moment inercia
df=2.3*((V/3.6)^2) %Down Force
dfR=(df*copx)/l %dfR=df*copx/(1.53*2); Down Force front
dfF=df-dfR %dfF=df*(1.53-copx)/(1.53*2); Down Force rear
%Vy=(V./3.6)*tan(VS);
Wf=g*weight*b/l
Wr=g*weight*a/l


if length(SI)==length(VS);
    for i = 1:length(SI);
        
        alphaFL(i)=((tan(VS(i))*(V/3.6))+(w(i)*a))./((V/3.6)-w(i)*Tf/2)-SI(i); %slip angle front left en rad
        if alphaFL(i)>sliplim;
            alphaFL(i)=sliplim;
        elseif alphaFL(i)<-sliplim;
            alphaFL(i)=-sliplim;
        end
        
        alphaFR(i)=((tan(VS(i))*(V/3.6))+(w(i)*a))./((V/3.6)+w(i)*Tf/2)-SI(i); %slip angle front right en rad
        if alphaFR(i)>sliplim;
            alphaFR(i)=sliplim;
        elseif alphaFR(i)<-sliplim;
            alphaFR(i)=-sliplim;
        end
        
        alphaRL(i)=((tan(VS(i))*(V/3.6))-(w(i)*b))./((V/3.6)-w(i)*Tr/2); %slip angle rear left en rad           
        if alphaRL(i)>sliplim;
            alphaRL(i)=sliplim;
        elseif alphaRL(i)<-sliplim;
            alphaRL(i)=-sliplim;
        end
        
        alphaRR(i)=((tan(VS(i))*(V/3.6))-(w(i)*b))./((V/3.6)+w(i)*Tr/2); %slip angle rear right en rad
        if alphaRR(i)>sliplim;
            alphaRR(i)=sliplim;
        elseif alphaRR(i)<-sliplim;
            alphaRR(i)=-sliplim;
        end
        
        %Weight transfer
        WF(i)=Ay(i)*((g*weight/Tf)*((H*Kf/(Kf+Kr))+(b*Zrf/l))); %weight transfer front (La Ay es en g)
        WR(i)=Ay(i)*((g*weight/Tr)*((H*Kr/(Kf+Kr))+(a*Zrr/l))); %weight transfer rear (La Ay es en g)
        
        WFL(i)=WF(i);
        WFR(i)=-WF(i);
        WRL(i)=WR(i);
        WRR(i)=-WR(i);
        
        %Camber variation
        rollangle(i)=Ay(i)*weight*g*H/(Kr+Kf);
        gammaFL(i)=abs((gammaF0+0.55333*rollangle(i))*pi/180); %rollangle i camber en deg 
        gammaFR(i)=abs((gammaF0-0.55333*rollangle(i))*pi/180); %rollangle i camber en deg 
        gammaRL(i)=abs((gammaR0+0.55333*rollangle(i))*pi/180); %rollangle i camber en deg 
        gammaRR(i)=abs((gammaR0-0.55333*rollangle(i))*pi/180); %rollangle i camber en deg 
        
        
        %Front Left wheel
        FzFL(i) = (Wf/2)+(WFL(i))+dfF/2;
        dfzFL(i)=(FzFL(i)-Fz0)./Fz0;
        dpiFL=(PF-P0)/P0;
        Shy0FL(i)=(PHY1+PHY2*dfzFL(i))*lambdaHy;
        Svy0FL(i)=FzFL(i)*(PVY1+PVY2*dfzFL(i))*lambdaVy*lambdauy*z2;
        SvygammaFL(i)=FzFL(i)*(PVY3+PVY4*dfzFL(i))*gammaFL(i)*lambdaKygamma*lambdauy*z2;
        SvyFL(i)=Svy0FL(i)+SvygammaFL(i);
        Kygamma0FL(i)=(PKY6+PKY7*dfzFL(i))*FzFL(i)*lambdaKygamma*(1+PPY5*dpiFL);
        Kyalpha0FL(i)=PKY1*Fz0*(1+PPY1*dpiFL)*sin(PKY4*atan(FzFL(i)/((PKY2*Fz0*(1+PPY2*dpiFL)))))*lambdaKyalpha;
        KyalphaFL(i)=PKY1*Fz0*(1+PPY1*dpiFL)*sin(PKY4*atan(FzFL(i)/((PKY2+PKY5*gammaFL(i)^2)*Fz0*(1+PPY2*dpiFL))))*(1-PKY3*abs(gammaFL(i)))*lambdaKyalpha*z3;
        ShygammaFL(i)=((Kygamma0FL(i)*gammaFL(i)-SvygammaFL(i))/KyalphaFL(i))*z0+z4-1;
        ShyFL(i)=Shy0FL(i)+ShygammaFL(i);
        alphayFL(i)=-(alphaFL(i)+ShyFL(i));
        CyFL(i)=PCY1*lambdaCy;
        uyFL(i)=(PDY1+PDY2*dfzFL(i))*(1+PPY3*dpiFL+PPY4*dpiFL^2)*(1-PDY3*gammaFL(i)^2)*lambdauy;
        DyFL(i)=uyFL(i)*FzFL(i)*z2;
        EyFL(i)=(PEY1+PEY2*dfzFL(i))*(1+PEY5*gammaFL(i)^2-(PEY3+PEY4*gammaFL(i))*sign(alphayFL(i)))*lambdaEy;
        ByFL(i)=KyalphaFL(i)/(CyFL(i)*DyFL(i));
        FypFL(i)=DyFL(i)*sin(CyFL(i)*atan(ByFL(i)*alphayFL(i)-EyFL(i).*(ByFL(i)*alphayFL(i)-atan(ByFL(i)*alphayFL(i)))))+SvyFL(i);
        %MF61Y:
        Gxalpha=1; %combined slip weiht function
        Svyk=0; %combined slip braking included
        FyFL(i)=-Gxalpha*FypFL(i)+Svyk;
        
        
        %Front Right wheel
        FzFR(i) = (Wf/2)+(WFR(i))+dfF/2;
        dfzFR(i)=(FzFR(i)-Fz0)./Fz0;
        dpiFR=(PF-P0)/P0;
        Shy0FR(i)=(PHY1+PHY2*dfzFR(i))*lambdaHy;
        Svy0FR(i)=FzFR(i)*(PVY1+PVY2*dfzFR(i))*lambdaVy*lambdauy*z2;
        SvygammaFR(i)=FzFR(i)*(PVY3+PVY4*dfzFR(i))*gammaFR(i)*lambdaKygamma*lambdauy*z2;
        SvyFR(i)=Svy0FR(i)+SvygammaFR(i);
        Kygamma0FR(i)=(PKY6+PKY7*dfzFR(i))*FzFR(i)*lambdaKygamma*(1+PPY5*dpiFR);
        Kyalpha0FR(i)=PKY1*Fz0*(1+PPY1*dpiFR)*sin(PKY4*atan(FzFR(i)/((PKY2*Fz0*(1+PPY2*dpiFR)))))*lambdaKyalpha;
        KyalphaFR(i)=PKY1*Fz0*(1+PPY1*dpiFR)*sin(PKY4*atan(FzFR(i)/((PKY2+PKY5*gammaFR(i)^2)*Fz0*(1+PPY2*dpiFR))))*(1-PKY3*abs(gammaFR(i)))*lambdaKyalpha*z3;
        ShygammaFR(i)=((Kygamma0FR(i)*gammaFR(i)-SvygammaFR(i))/KyalphaFR(i))*z0+z4-1;
        ShyFR(i)=Shy0FR(i)+ShygammaFR(i);
        alphayFR(i)=alphaFR(i)+ShyFR(i);
        CyFR(i)=PCY1*lambdaCy;
        uyFR(i)=(PDY1+PDY2*dfzFR(i))*(1+PPY3*dpiFR+PPY4*dpiFR^2)*(1-PDY3*gammaFR(i)^2)*lambdauy;
        DyFR(i)=uyFR(i)*FzFR(i)*z2;
        EyFR(i)=(PEY1+PEY2*dfzFR(i))*(1+PEY5*gammaFR(i)^2-(PEY3+PEY4*gammaFR(i))*sign(alphayFR(i)))*lambdaEy;
        ByFR(i)=KyalphaFR(i)/(CyFR(i)*DyFR(i));
        FypFR(i)=DyFR(i)*sin(CyFR(i)*atan(ByFR(i)*alphayFR(i)-EyFR(i).*(ByFR(i)*alphayFR(i)-atan(ByFR(i)*alphayFR(i)))))+SvyFR(i);
        %MF61Y:
        Gxalpha=1;%conbined slip weiht function
        Svyk=0;%conbined slip braking included
        FyFR(i)=Gxalpha*FypFR(i)+Svyk;
        
        
        %Rear Left wheel
        FzRL(i) = (Wr/2)+WRL(i)+dfR/2;
        dfzRL(i)=(FzRL(i)-Fz0)./Fz0;
        dpiRL=(PR-P0)/P0;
        Shy0RL(i)=(PHY1+PHY2*dfzRL(i))*lambdaHy;
        Svy0RL(i)=FzRL(i)*(PVY1+PVY2*dfzRL(i))*lambdaVy*lambdauy*z2;
        SvygammaRL(i)=FzRL(i)*(PVY3+PVY4*dfzRL(i))*gammaRL(i)*lambdaKygamma*lambdauy*z2;
        SvyRL(i)=Svy0RL(i)+SvygammaRL(i);
        Kygamma0RL(i)=(PKY6+PKY7*dfzRL(i))*FzRL(i)*lambdaKygamma*(1+PPY5*dpiRL);
        Kyalpha0RL(i)=PKY1*Fz0*(1+PPY1*dpiRL)*sin(PKY4*atan(FzRL(i)/((PKY2*Fz0*(1+PPY2*dpiRL)))))*lambdaKyalpha;
        KyalphaRL(i)=PKY1*Fz0*(1+PPY1*dpiRL)*sin(PKY4*atan(FzRL(i)/((PKY2+PKY5*gammaRL(i)^2)*Fz0*(1+PPY2*dpiRL))))*(1-PKY3*abs(gammaRL(i)))*lambdaKyalpha*z3;
        ShygammaRL(i)=((Kygamma0RL(i)*gammaRL(i)-SvygammaRL(i))/KyalphaRL(i))*z0+z4-1;
        ShyRL(i)=Shy0RL(i)+ShygammaRL(i);
        alphayRL(i)=-(alphaRL(i)+ShyRL(i));
        CyRL(i)=PCY1*lambdaCy;
        uyRL(i)=(PDY1+PDY2*dfzRL(i))*(1+PPY3*dpiRL+PPY4*dpiRL^2)*(1-PDY3*gammaRL(i)^2)*lambdauy;
        DyRL(i)=uyRL(i)*FzRL(i)*z2;
        EyRL(i)=(PEY1+PEY2*dfzRL(i))*(1+PEY5*gammaRL(i)^2-(PEY3+PEY4*gammaRL(i))*sign(alphayRL(i)))*lambdaEy;
        ByRL(i)=KyalphaRL(i)/(CyRL(i)*DyRL(i));
        FypRL(i)=DyRL(i)*sin(CyRL(i)*atan(ByRL(i)*alphayRL(i)-EyRL(i).*(ByRL(i)*alphayRL(i)-atan(ByRL(i)*alphayRL(i)))))+SvyRL(i);
        %MF61Y:
        Gxalpha=1;%conbined slip weiht function
        Svyk=0;%conbined slip braking included
        FyRL(i)=-Gxalpha*FypRL(i)+Svyk;
        
        
        %Rear Right wheel
        FzRR(i) =(Wr/2)+(WRR(i))+dfR/2;
        dfzRR(i)=(FzRR(i)-Fz0)./Fz0;
        dpiRR=(PR-P0)/P0;
        Shy0RR(i)=(PHY1+PHY2*dfzRR(i))*lambdaHy;
        Svy0RR(i)=FzRR(i)*(PVY1+PVY2*dfzRR(i))*lambdaVy*lambdauy*z2;
        SvygammaRR(i)=FzRR(i)*(PVY3+PVY4*dfzRR(i))*gammaRR(i)*lambdaKygamma*lambdauy*z2;
        SvyRR(i)=Svy0RR(i)+SvygammaRR(i);
        Kygamma0RR(i)=(PKY6+PKY7*dfzRR(i))*FzRR(i)*lambdaKygamma*(1+PPY5*dpiRR);
        Kyalpha0RR(i)=PKY1*Fz0*(1+PPY1*dpiRR)*sin(PKY4*atan(FzRR(i)/((PKY2*Fz0*(1+PPY2*dpiRR)))))*lambdaKyalpha;
        KyalphaRR(i)=PKY1*Fz0*(1+PPY1*dpiRR)*sin(PKY4*atan(FzRR(i)/((PKY2+PKY5*gammaRR(i)^2)*Fz0*(1+PPY2*dpiRR))))*(1-PKY3*abs(gammaRR(i)))*lambdaKyalpha*z3;
        ShygammaRR(i)=((Kygamma0RR(i)*gammaRR(i)-SvygammaRR(i))/KyalphaRR(i))*z0+z4-1;
        ShyRR(i)=Shy0RR(i)+ShygammaRR(i);
        alphayRR(i)=alphaRR(i)+ShyRR(i);
        CyRR(i)=PCY1*lambdaCy;
        uyRR(i)=(PDY1+PDY2*dfzRR(i))*(1+PPY3*dpiRR+PPY4*dpiRR^2)*(1-PDY3*gammaRR(i)^2)*lambdauy;
        DyRR(i)=uyRR(i)*FzRR(i)*z2;
        EyRR(i)=(PEY1+PEY2*dfzRR(i))*(PEY5*gammaRR(i)^2-(PEY3+PEY4*gammaRR(i))*sign(alphayRR(i)))*lambdaEy;
        ByRR(i)=KyalphaRR(i)/(CyRR(i)*DyRR(i));
        FypRR(i)=DyRR(i)*sin(CyRR(i)*atan(ByRR(i)*alphayRR(i)-EyRR(i).*(ByRR(i)*alphayRR(i)-atan(ByRR(i)*alphayRR(i)))))+SvyRR(i);
        %MF61Y:
        Gxalpha=1;%conbined slip weiht function
        Svyk=0;%conbined slip braking included
        FyRR(i)=Gxalpha*FypRR(i)+Svyk;
        
        
        Izz(i)=(a/l)*(FzFL(i)+FzFR(i))*a^2+(b/l)*(FzRR(i)+FzRL(i))*b^2;
        %Ay(i)=(FyFL(i)*(cos(SI(i)))+FyFR(i)*(cos(SI(i)))+(FyRR(i)+FyRL(i)))/(weight*g); %Acceleracio lateral o centripeta en g
        %Ay(i)=(FyFL(i)*(cos(SI(i)-alphaFL(i)))+FyFR(i)*(cos(SI(i)-alphaFR(i)))+(FyRR(i)+FyRL(i)))/(weight*g); %Acceleracio lateral o centripeta
        YawMoment(i)=(FyFL(i).*cos(SI(i))+FyFR(i).*cos(SI(i)))*a-(FyRR(i)+FyRL(i))*b+MZ(alphaFL(i))+MZ(alphaFR(i))+MZ(alphaRL(i))+MZ(alphaRR(i));
        %YawMoment(i)=(FyFL(i).*cos(SI(i)-alphaFL(i))+FyFR(i).*cos(SI(i)-alphaFL(i)))*a-(FyRR(i)+FyRL(i))*b-MZ(alphaFL(i))-MZ(alphaFR(i))-MZ(alphaRL(i))-MZ(alphaRR(i));
        YawAccel(i)=YawMoment(i)./Izz(i)*180/pi;
        %w(i)=Ay(i)*g/(V/3.6);
        %R=Ay(i)./(w^2);
    end
else 
    fprintf('error: length(SI)!=length(VS)');
end
[M,N]=size(YawMoment);

%{
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
%}
% legendCell_VS = cellstr(num2str(VS', 'VS=%-d'));
% legendCell_SI = cellstr(num2str(SI', 'SI=%-d'));
% legend([legendCell_VS;legendCell_SI], 'NumColumns',2)
xlabel('Lateral accel [gs]')
ylabel('Yaw Moment [kg m]')
legendCell_VS = cellstr(num2str(VS*180/pi, 'VS=%-d'));
legendCell_SI = cellstr(num2str(SI*180/pi, 'SI=%-d'));
legend([legendCell_VS;legendCell_SI], 'NumColumns',2)

%{
figure
for i=1:N
    plot(Ay(:,i)/g,YawAccel(:,i))
    hold on
end
for i=1:M
    plot(Ay(i,:)/g,YawAccel(i,:))
    hold on
end
legendCell_VS = cellstr(num2str(VS', 'VS=%-d'));
legendCell_SI = cellstr(num2str(SI', 'SI=%-d'));
legend([legendCell_VS;legendCell_SI], 'NumColumns',2)
xlabel('Lateral accel [gs]')
ylabel('Yaw Accel [deg/s^2]')
%}


